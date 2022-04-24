///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 4/14/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_HPP

#include "xos/app/console/crypto/rsa/main_opt.hpp"

#include "xos/app/console/crypto/rsa/public_key.hpp"
#include "xos/app/console/crypto/rsa/private_key.hpp"

#include "xos/crypto/rsa/bn/public_key.hpp"
#include "xos/crypto/rsa/bn/private_key.hpp"

#include "xos/crypto/rsa/mp/public_key.hpp"
#include "xos/crypto/rsa/mp/private_key.hpp"

#include "xos/crypto/pseudo/random/number/generator.hpp"
#include "xos/crypto/random/number/reader.hpp"
#include "xos/crypto/random/prime/reader.hpp"

#include "xos/crypto/random/prime/bn/number.hpp"
#include "xos/crypto/random/prime/bn/reader.hpp"
#include "xos/crypto/random/prime/bn/miller_rabin.hpp"
#include "xos/crypto/random/prime/bn/generator.hpp"
#include "xos/crypto/rsa/bn/key_generator.hpp"

#define XOS_APP_CONSOLE_RSA_MODULUS_BITS 2048
#define XOS_APP_CONSOLE_RSA_EXPONENT_BITS 24
#define XOS_APP_CONSOLE_RSA_EXPONENT_VALUE 0x010001

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace rsa {

/// class maint
template 
<class TExtends = xos::app::console::crypto::rsa::main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint()
    : run_(0),
      exponent_value_(XOS_APP_CONSOLE_RSA_EXPONENT_VALUE), 
      exponent_bits_(XOS_APP_CONSOLE_RSA_EXPONENT_BITS),
      modulus_bits_(XOS_APP_CONSOLE_RSA_MODULUS_BITS) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    typedef typename extends::byte_array_t byte_array_t;
    typedef typename extends::crypto_array_t crypto_array_t;

    class exported bn_reader_observer_t
    : virtual public xos::crypto::random::prime::bn::reader::observer {
    friend class maint;
    public:
        bn_reader_observer_t(maint& main): main_(main), output_(0) {}
        virtual ~bn_reader_observer_t() {}
        virtual ssize_t on_read(BIGNUM* n, size_t bytes) {
            bool output = true;
            if ((output)) {
                main_.err(".");
                ++output_;
            }
            return bytes;
        }
        virtual size_t clear_output() {
            size_t output = output_;
            output_ = 0;
            if ((output)) {
                main_.errln();
            }
            return output;
        }
    protected:
        maint& main_;
        size_t output_;
    }; /// class bn_reader_observer_t
    
protected:
    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    /// ...bn_generate_key_pair_run
    virtual int bn_generate_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t expbits = this->exponent_bits(), expbytes = ((expbits + 7) >> 3),
               modbits = this->modulus_bits(), modbytes = ((modbits + 7) >> 3),
               pbits = (modbits >> 1), pbytes = (modbytes >> 1);
        crypto_array_t exponent_array(exponent_value_, expbytes);
        byte_t* exponent = 0; size_t exponent_length = 0;
        
        if ((exponent = exponent_array.has_elements(exponent_length)) && (expbytes == exponent_length)) {
            xos::crypto::pseudo::random::number::generator random;
            xos::crypto::rsa::bn::public_key pub(modbytes, expbytes);
            xos::crypto::rsa::bn::private_key prv(pbytes);
            bn_reader_observer_t observer(*this);
            xos::crypto::rsa::bn::key_generator generator(&observer);
            
            observer.clear_output();
            if ((generator.generate(prv, pub, modbytes, exponent, expbytes, random))) {
                
                observer.clear_output();
                if (!(err = output_generated_key_pair_run(pub, prv, argc, argv, env))) {
                }
            }
        }
        return err;
    }

    /// ...output_generated_key_pair_run
    virtual int output_generated_key_pair_run
    (const xos::crypto::rsa::public_key::extend& pub, 
     const xos::crypto::rsa::private_key::extend& prv, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t expbytes = pub.expbytes(), 
               modbytes = pub.modbytes(), 
               pbytes = prv.pbytes();
        byte_array_t array(modbytes);
        byte_t *bytes = 0; size_t length = 0;
        
        if ((bytes = array.has_elements(length)) && (modbytes <= length)) {

            if (expbytes == (length = pub.get_exponent_msb(bytes, modbytes))) {
                this->output_hex_verbage_sized("exponent", bytes, length);

                if (modbytes == (length = pub.get_modulus_msb(bytes, modbytes))) {
                    this->output_hex_verbage_sized("modulus", bytes, length);
                    
                    if (pbytes == (length = prv.get_p_msb(bytes, pbytes))) {
                        this->output_hex_verbage_sized("p", bytes, length);
                        
                        if (pbytes == (length = prv.get_q_msb(bytes, pbytes))) {
                            this->output_hex_verbage_sized("q", bytes, length);
                            
                            if (pbytes == (length = prv.get_dmp1_msb(bytes, pbytes))) {
                                this->output_hex_verbage_sized("dmp1", bytes, length);
                                
                                if (pbytes == (length = prv.get_dmq1_msb(bytes, pbytes))) {
                                    this->output_hex_verbage_sized("dmq1", bytes, length);
                                    
                                    if (pbytes == (length = prv.get_iqmp_msb(bytes, pbytes))) {
                                        this->output_hex_verbage_sized("iqmp", bytes, length);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return err;
    }

    /// ...pseudo_random_number_run
    virtual int default_pseudo_random_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0;
        const byte_t *modulus = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length)
            && (modulus_length >= modbytes_min) && (modulus_length <= modbytes_max)) {
            size_t length = 0, sizeof_random = 0;
            byte_t *random = 0;
            
            if ((random = &this->rsa_decipher(sizeof_random)) && (sizeof_random >= (length = (modulus_length / 2)))) {
                xos::crypto::pseudo::random::number::generator generator;
                
                if (length == (sizeof_random = generator.generate(random, length))) {
                    this->output_hex_verbage_sized("pseudo_random_number", random, sizeof_random);
                }
            }
        }
        return err;
    }
    virtual int bn_generate_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0;
        const byte_t *modulus = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length)
            && (modulus_length >= modbytes_min) && (modulus_length <= modbytes_max)) {
            size_t length = 0, sizeof_random = 0;
            byte_t *random = 0;
            
            if ((random = &this->rsa_decipher(sizeof_random)) && (sizeof_random >= (length = (modulus_length / 2)))) {
                xos::crypto::pseudo::random::number::generator random_reader;
                xos::crypto::random::prime::bn::number number;

                if ((number.is_created())) {
                    bn_reader_observer_t reader_observer(*this);
                    xos::crypto::random::prime::bn::generator generator(&reader_observer);

                    if ((generator.create())) {
                        
                        if (length == (sizeof_random = generator.generate(number, length, random_reader))) {
                            
                            if (length == (sizeof_random = number.to_msb(random, length))) {
                                this->output_hex_verbage_sized("pseudo_random_prime", random, sizeof_random);
                            }
                        }
                        generator.destroy();
                    }
                }
            }
        }
        return err;
    }
    virtual int bn_miller_rabin_pseudo_random_prime_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0;
        const byte_t *modulus = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length)
            && (modulus_length >= modbytes_min) && (modulus_length <= modbytes_max)) {
            size_t length = 0, sizeof_random = 0;
            byte_t *random = 0;
            
            if ((random = &this->rsa_decipher(sizeof_random)) && (sizeof_random >= (length = (modulus_length / 2)))) {
                xos::crypto::pseudo::random::number::generator generator;
                xos::crypto::random::prime::bn::number number;

                if ((number.is_created())) {
                    bn_reader_observer_t reader_observer(*this);
                    xos::crypto::random::prime::bn::miller_rabin miller_rabin(&reader_observer);

                    if ((miller_rabin.create())) {
                        xos::crypto::random::prime::bn::reader reader;
                        bool is_probably_prime = false;
                        
                        do {
                            if (length == (sizeof_random = reader.read_msb(number, length, generator))) {
                                if ((is_probably_prime = miller_rabin.probably_prime(number, length, generator))) {
                                    if (length == (sizeof_random = number.to_msb(random, length))) {
                                        this->output_hex_verbage_sized("pseudo_random_prime", random, sizeof_random);
                                    }
                                }
                            }
                        } while (!is_probably_prime);
                        miller_rabin.destroy();
                    }
                }
            }
        }
        return err;
    }

    ///
    /// ...rsa_public_...crypt_run
    /// ...
    virtual int bn_rsa_public_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            xos::crypto::rsa::bn::public_key pub(modulus, modulus_length,exponent, exponent_length);

            err = rsa_public_encrypt_run(pub, argc, argv, env);
        }
        return err;
    }
    virtual int gmp_rsa_public_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            xos::crypto::rsa::mp::public_key pub(modulus, modulus_length,exponent, exponent_length);

            err = rsa_public_encrypt_run(pub, argc, argv, env);
        }
        return err;
    }
    template <typename rsa_public_key_t>
    int rsa_public_encrypt_run(rsa_public_key_t& pub, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t size = 0, modbytes = pub.modbytes();

        if ((modbytes >= modbytes_min) && (modbytes <= modbytes_max)) {
            size_t sizeof_plain = 0, plain_length = 0;
            const byte_t *plain_bytes = 0;
            byte_t *plain = &this->rsa_plain(sizeof_plain);

            if ((plain_bytes = this->get_rsa_plain(plain_length)) && (plain_length)) {
                size_t sizeof_cipher = 0;
                byte_t *cipher = &this->rsa_cipher(sizeof_cipher);

                if ((modbytes > plain_length)) {
                    size_t length = length = (modbytes - plain_length);
                    ::memcpy(plain, plain_bytes, plain_length);
                    ::memset(plain + plain_length, 0, length);
                } else {
                    ::memcpy(plain, plain_bytes, modbytes);
                }
                if (modbytes == (size = pub(cipher, sizeof_cipher, plain, modbytes))) {
                    this->output_hex_verbage_sized("cipher", cipher, size);
                }
            }
        }
        return err;
    }
    template <typename rsa_public_key_t>
    int rsa_public_decrypt_run(rsa_public_key_t& pub, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t size = 0, modbytes = pub.modbytes();

        if ((modbytes >= modbytes_min) && (modbytes <= modbytes_max)) {
            size_t sizeof_cipher = 0, cipher_length = 0;
            const byte_t *cipher_bytes = 0;
            byte_t *cipher = &this->rsa_cipher(sizeof_cipher);

            if ((cipher_bytes = this->get_rsa_cipher(cipher_length)) && (cipher_length)) {
                size_t sizeof_decipher = 0;
                byte_t *decipher = &this->rsa_decipher(sizeof_decipher);

                if ((modbytes > cipher_length)) {
                    size_t length = length = (modbytes - cipher_length);
                    ::memcpy(cipher, cipher_bytes, cipher_length);
                    ::memset(cipher + cipher_length, 0, length);
                } else {
                    ::memcpy(cipher, cipher_bytes, modbytes);
                }
                if (modbytes == (size = pub(decipher, sizeof_decipher, cipher, modbytes))) {
                    this->output_hex_verbage_sized("plain", decipher, size);
                }
            }
        }
        return err;
    }
    /// ...
    /// ...rsa_public_...crypt_run
    /// 

    ///
    /// ...rsa_private_...crypt_run
    /// ...
    virtual int bn_rsa_private_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t p_length = 0;
        const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;

        if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {
            xos::crypto::rsa::bn::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);

            err = rsa_private_encrypt_run(prv, argc, argv, env);
        }
        return err;
    }
    virtual int gmp_rsa_private_encrypt_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t p_length = 0;
        const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;

        if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {
            xos::crypto::rsa::mp::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);

            err = rsa_private_encrypt_run(prv, argc, argv, env);
        }
        return err;
    }
    template <typename rsa_private_key_t>
    int rsa_private_encrypt_run(rsa_private_key_t& prv, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t size = 0, modbytes = prv.modbytes();

        if ((modbytes >= modbytes_min) && (modbytes <= modbytes_max)) {
            size_t sizeof_plain = 0, plain_length = 0;
            const byte_t *plain_bytes = 0;
            byte_t *plain = &this->rsa_plain(sizeof_plain);

            if ((plain_bytes = this->get_rsa_plain(plain_length)) && (plain_length)) {
                size_t sizeof_cipher = 0;
                byte_t *cipher = &this->rsa_cipher(sizeof_cipher);

                if ((modbytes > plain_length)) {
                    size_t length = length = (modbytes - plain_length);
                    ::memcpy(plain, plain_bytes, plain_length);
                    ::memset(plain + plain_length, 0, length);
                } else {
                    ::memcpy(plain, plain_bytes, modbytes);
                }
                if (modbytes == (size = prv(cipher, sizeof_cipher, plain, modbytes))) {
                    this->output_hex_verbage_sized("cipher", cipher, size);
                }
            }
        }
        return err;
    }
    template <typename rsa_private_key_t>
    int rsa_private_decrypt_run(rsa_private_key_t& prv, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t size = 0, modbytes = prv.modbytes();

        if ((modbytes >= modbytes_min) && (modbytes <= modbytes_max)) {
            size_t sizeof_cipher = 0, cipher_length = 0;
            const byte_t *cipher_bytes = 0;
            byte_t *cipher = &this->rsa_cipher(sizeof_cipher);

            if ((cipher_bytes = this->get_rsa_cipher(cipher_length)) && (cipher_length)) {
                size_t sizeof_decipher = 0;
                byte_t *decipher = &this->rsa_decipher(sizeof_decipher);

                if ((modbytes > cipher_length)) {
                    size_t length = length = (modbytes - cipher_length);
                    ::memcpy(cipher, cipher_bytes, cipher_length);
                    ::memset(cipher + cipher_length, 0, length);
                } else {
                    ::memcpy(cipher, cipher_bytes, modbytes);
                }
                if (modbytes == (size = prv(decipher, sizeof_decipher, cipher, modbytes))) {
                    this->output_hex_verbage_sized("plain", decipher, size);
                }
            }
        }
        return err;
    }
    /// ...
    /// ...rsa_private_...crypt_run
    /// 

    /// ...rsa_public_cipher_run
    ///
    /// ...test_key_pair_run
    /// ...
    /// bn_test_key_pair_run
    virtual int bn_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            size_t p_length = 0;
            const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
            
            xos::crypto::rsa::bn::public_key pub(modulus, modulus_length,exponent, exponent_length);
            if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {

                xos::crypto::rsa::bn::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);
                err = test_key_pair_run(pub, prv, argc, argv, env);
            }
        }
        return err;
    }
    /// ...gmp_test_key_pair_run
    virtual int gmp_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            size_t p_length = 0;
            const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
            
            xos::crypto::rsa::mp::public_key pub(modulus, modulus_length,exponent, exponent_length);
            if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {

                xos::crypto::rsa::mp::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);
                err = test_key_pair_run(pub, prv, argc, argv, env);
            }
        }
        return err;
    }
    /// test_key_pair_run
    template <typename rsa_public_key_t, typename rsa_private_key_t>
    int test_key_pair_run(rsa_public_key_t& pub, rsa_private_key_t& prv, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t size = 0, modbytes = pub.modbytes();

        if ((modbytes >= modbytes_min) && (modbytes <= modbytes_max)) {
            size_t sizeof_plain = 0;
            byte_t *plain = &this->rsa_plain(sizeof_plain);
            
            if ((size = this->random(plain, modbytes))) {
                size_t sizeof_cipher = 0;
                byte_t *cipher = &this->rsa_cipher(sizeof_cipher);

                this->out("plain = ");
                this->outx(plain, modbytes);
                this->outln();
                this->outln();

                if (modbytes == (size = pub(cipher, sizeof_cipher, plain, modbytes))) {
                    size_t sizeof_decipher = 0;
                    byte_t *decipher = &this->rsa_decipher(sizeof_decipher);
    
                    this->out("cipher = ");
                    this->outx(cipher, size);
                    this->outln();
                    this->outln();

                    if (modbytes == (size = prv(decipher, sizeof_decipher, cipher, size))) {
                        this->out("decipher = ");
                        this->outx(decipher, size);
                        this->outln();
                        this->outln();

                        this->out("public <--> private ");
                        if (!(::memcmp(plain, decipher, size))) {
                            this->outln("success");
                        } else {
                            this->outln("failure");
                        }
                        this->outln();
                    } else {
                    }
                } else {
                }
                if (modbytes == (size = prv(cipher, sizeof_cipher, plain, modbytes))) {
                    size_t sizeof_decipher = 0;
                    byte_t *decipher = &this->rsa_decipher(sizeof_decipher);
    
                    this->out("cipher = ");
                    this->outx(cipher, size);
                    this->outln();
                    this->outln();

                    if (modbytes == (size = pub(decipher, sizeof_decipher, cipher, size))) {
                        this->out("decipher = ");
                        this->outx(decipher, size);
                        this->outln();
                        this->outln();

                        this->out("private <--> public ");
                        if (!(::memcmp(plain, decipher, size))) {
                            this->outln("success");
                        } else {
                            this->outln("failure");
                        }
                        this->outln();
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    /// ...
    /// ...test_key_pair_run
    /// 

    ///
    /// ...output_get_..._run
    /// ...
    virtual int default_output_get_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        if ((bytes = get_rsa_plain(length)) && (length)) {
            this->output_hex_verbage_sized("plain", bytes, length);
        }
        return err;
    }
    virtual int default_output_get_rsa_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        if ((bytes = get_rsa_cipher(length)) && (length)) {
            this->output_hex_verbage_sized("cipher", bytes, length);
        }
        return err;
    }
    virtual int bn_output_get_rsa_public_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            xos::crypto::rsa::bn::public_key pub(modulus, modulus_length,exponent, exponent_length);

            err = rsa_public_encrypt_run(pub, argc, argv, env);
        }
        return err;
    }
    virtual int gmp_output_get_rsa_public_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            xos::crypto::rsa::mp::public_key pub(modulus, modulus_length,exponent, exponent_length);

            err = rsa_public_encrypt_run(pub, argc, argv, env);
        }
        return err;
    }
    virtual int bn_output_get_rsa_private_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t p_length = 0;
        const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;

        if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {
            xos::crypto::rsa::bn::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);

            err = rsa_private_decrypt_run(prv, argc, argv, env);
        }
        return err;
    }
    virtual int gmp_output_get_rsa_private_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t p_length = 0;
        const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;

        if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length)) && (p_length)) {
            xos::crypto::rsa::mp::private_key prv(p, q, dmp1, dmq1, iqmp, p_length);

            err = rsa_private_decrypt_run(prv, argc, argv, env);
        }
        return err;
    }
    virtual int default_output_get_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        if ((bytes = get_exponent(length)) && (length)) {
            this->output_hex_verbage_sized("public_exponent", bytes, length);
            if ((bytes = get_modulus(length)) && (length)) {
                this->output_hex_verbage_sized("public_modulus", bytes, length);
            }
        }
        return err;
    }
    virtual int default_output_get_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        const byte_t *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
        if ((bytes = get_p(q, dmp1, dmq1, iqmp, length)) && (length)) {
            this->output_hex_verbage_sized("private_p", bytes, length);
            this->output_hex_verbage_sized("private_q", q, length);
            this->output_hex_verbage_sized("private_dmp1", dmp1, length);
            this->output_hex_verbage_sized("private_dmq1", dmq1, length);
            this->output_hex_verbage_sized("private_iqmp", iqmp, length);
        }
        return err;
    }
    virtual int default_output_get_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = default_output_get_public_key_run(argc, argv, env))) {
            if (!(err = default_output_get_private_key_run(argc, argv, env))) {
            }
        }
        return err;
    }
    /// ...
    /// ...output_get_..._run
    /// 

    ///
    /// ...output_test_..._run
    /// ...
    virtual int default_output_test_rsa_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modbytes = 0;
        const byte_t *modulus = 0;

        if ((modulus = this->get_modulus(modbytes)) && (modbytes)
            && (modbytes >= modbytes_min) && (modbytes <= modbytes_max)) {
            size_t size = 0, sizeof_plain = 0;
            byte_t *plain = &this->rsa_plain(sizeof_plain);
            
            if (modbytes == (size = this->random(plain, modbytes))) {
                this->output_hex_verbage_sized("plain", plain, size);
            }
        }
        return err;
    }
    virtual int bn_output_test_rsa_public_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            xos::crypto::rsa::bn::public_key pub(modulus, modulus_length,exponent, exponent_length);

            err = output_test_rsa_public_cipher_run(pub, argc, argv, env);
        }
        return err;
    }
    virtual int gmp_output_test_rsa_public_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t modulus_length = 0, exponent_length = 0;
        const byte_t *modulus = 0, *exponent = 0;

        if ((modulus = this->get_modulus(modulus_length)) && (modulus_length) 
            && (exponent = this->get_exponent(exponent_length)) && (exponent_length)) {
            xos::crypto::rsa::mp::public_key pub(modulus, modulus_length,exponent, exponent_length);

            err = output_test_rsa_public_cipher_run(pub, argc, argv, env);
        }
        return err;
    }
    /// output_test_rsa_public_cipher_run
    template <typename rsa_public_key_t>
    int output_test_rsa_public_cipher_run(rsa_public_key_t& pub, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t size = 0, modbytes = pub.modbytes();

        if ((modbytes >= modbytes_min) && (modbytes <= modbytes_max)) {
            size_t sizeof_plain = 0;
            byte_t *plain = &this->rsa_plain(sizeof_plain);

            if ((size = this->random(plain, modbytes))) {
                size_t sizeof_cipher = 0;
                byte_t *cipher = &this->rsa_cipher(sizeof_cipher);

                if (modbytes == (size = pub(cipher, sizeof_cipher, plain, modbytes))) {
                    this->output_hex_verbage_sized("cipher", cipher, size);
                }
            }
        }
        return err;
    }
    virtual int default_output_test_public_exponent_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->output_hex_verbage_sized
        ("public_exponent",::xos::app::console::crypto::rsa::rsa_public_exponent, 
         sizeof(::xos::app::console::crypto::rsa::rsa_public_exponent));
        return err;
    }
    virtual int default_output_test_public_modulus_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->output_hex_verbage_sized
        ("public_modulus",::xos::app::console::crypto::rsa::rsa_public_modulus, 
         sizeof(::xos::app::console::crypto::rsa::rsa_public_modulus));
        return err;
    }
    virtual int default_output_test_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = default_output_test_public_exponent_run(argc, argv, env))) {
            if (!(err = default_output_test_public_modulus_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int default_output_test_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->output_hex_verbage_sized
        ("private_p", ::xos::app::console::crypto::rsa::rsa_private_p, 
         sizeof(::xos::app::console::crypto::rsa::rsa_private_p));
        this->output_hex_verbage_sized
        ("private_q", ::xos::app::console::crypto::rsa::rsa_private_q, 
         sizeof(::xos::app::console::crypto::rsa::rsa_private_q));
        this->output_hex_verbage_sized
        ("private_dmp1", ::xos::app::console::crypto::rsa::rsa_private_dmp1, 
         sizeof(::xos::app::console::crypto::rsa::rsa_private_dmp1));
        this->output_hex_verbage_sized
        ("private_dmq1", ::xos::app::console::crypto::rsa::rsa_private_dmq1, 
         sizeof(::xos::app::console::crypto::rsa::rsa_private_dmq1));
        this->output_hex_verbage_sized
        ("private_iqmp", ::xos::app::console::crypto::rsa::rsa_private_iqmp, 
         sizeof(::xos::app::console::crypto::rsa::rsa_private_iqmp));
        return err;
    }
    virtual int default_output_test_key_pair_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = default_output_test_public_key_run(argc, argv, env))) {
            if (!(err = default_output_test_private_key_run(argc, argv, env))) {
            }
        }
        return err;
    }
    /// ...
    /// ...output_test_..._run
    /// 

    /// on_set...literal
    virtual int on_set_rsa_plain_literal(const char_t* chars, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((chars) && (chars[0])) {
            string_t literal(chars);
            if (!(err = this->on_set_rsa_plain_hex_literal(rsa_plain_array_, literal))) {
                if (!(err = this->set_get_literal_rsa_plain(argc, argv, env))) {
                    if (!(err = this->set_output_get_rsa_plain_run(argc, argv, env))) {
                    }
                }
            }
        }
        return err;
    }
    virtual int on_set_rsa_cipher_literal(const char_t* chars, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((chars) && (chars[0])) {
            string_t literal(chars);
            if (!(err = this->on_set_rsa_cipher_hex_literal(rsa_cipher_array_, literal))) {
                if (!(err = this->set_get_literal_rsa_cipher(argc, argv, env))) {
                    if (!(err = this->set_output_get_rsa_cipher_run(argc, argv, env))) {
                    }
                }
            }
        }
        return err;
    }
    virtual int on_set_public_key_literal(const char_t* chars, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((chars) && (chars[0])) {
            string_t literal(chars);
            if (!(err = this->on_set_public_key_hex_literals(exponent_, modulus_, literal))) {
                if (!(err = this->set_get_literal_exponent(argc, argv, env))) {
                    if (!(err = this->set_get_literal_modulus(argc, argv, env))) {
                    }
                }
            }
        }
        return err;
    }
    virtual int on_set_private_key_literal(const char_t* chars, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((chars) && (chars[0])) {
            string_t literal(chars);
            if (!(err = this->on_set_private_key_hex_literals(p_, q_, dmp1_, dmq1_, iqmp_, literal))) {
                if (!(err = this->set_get_literal_p(argc, argv, env))) {
                }
            }
        }
        return err;
    }
    virtual int on_set_key_pair_literal(const char_t* chars, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((chars) && (chars[0])) {
            string_t literal(chars);
            if (!(err = this->on_set_key_pair_hex_literals
                (exponent_, modulus_, p_, q_, dmp1_, dmq1_, iqmp_, literal))) {
                if (!(err = this->set_get_literal_exponent(argc, argv, env))) {
                    if (!(err = this->set_get_literal_modulus(argc, argv, env))) {
                        if (!(err = this->set_get_literal_p(argc, argv, env))) {
                        }
                    }
                }
            }
        }
        return err;
    }

    /// random
    virtual size_t random(unsigned char *buff, size_t len) const {
        static unsigned randnum = 0;
        static unsigned avail = 0;
        size_t i=0;
        
        for (i=0; i<len;) {
            if (avail<1) {
                randnum=(unsigned)rand();
                avail=sizeof(randnum);
            }
            if ((buff[i]=(char)(randnum&255))!=0) {
                i++;
            }
            if ((randnum>>=8)<1) {
                avail=0;
            } else {
                avail--;
            }
        }
        return i;
    }

    /// size_of
    virtual size_t size_of(const unsigned char *buff, size_t len) const {
        for (size_t i=0; len>0; i++, --len) {
            if (buff[i]) {
                return len;
            }
        }
        return 0;
    }

    /// ...get_exponent
    const byte_t* (derives::*get_exponent_)(size_t &length);
    virtual const byte_t* get_exponent(size_t &length) {
        const byte_t* bytes = 0;
        if (get_exponent_) {
            bytes = (this->*get_exponent_)(length);
        } else {
            bytes = get_test_exponent(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_exponent(size_t &length) {
        const byte_t* bytes = 0;
        length = sizeof(::xos::app::console::crypto::rsa::rsa_public_exponent);
        bytes = ::xos::app::console::crypto::rsa::rsa_public_exponent;
        return bytes;
    }
    virtual const byte_t* get_literal_exponent(size_t &length) {
        const byte_t* bytes = 0;
        length = exponent_.length();
        bytes = exponent_.elements();
        return bytes;
    }
    virtual int set_get_test_exponent(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_exponent_ = &derives::get_literal_exponent;
        return err;
    }
    virtual int set_get_literal_exponent(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_exponent_ = &derives::get_literal_exponent;
        return err;
    }

    /// ...get_modulus
    const byte_t* (derives::*get_modulus_)(size_t &length);
    virtual const byte_t* get_modulus(size_t &length) {
        const byte_t* bytes = 0;
        if (get_modulus_) {
            bytes = (this->*get_modulus_)(length);
        } else {
            bytes = get_test_modulus(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_modulus(size_t &length) {
        const byte_t* bytes = 0;
        length = sizeof(::xos::app::console::crypto::rsa::rsa_public_modulus);
        bytes = ::xos::app::console::crypto::rsa::rsa_public_modulus;
        return bytes;
    }
    virtual const byte_t* get_literal_modulus(size_t &length) {
        const byte_t* bytes = 0;
        length = modulus_.length();
        bytes = modulus_.elements();
        return bytes;;
    }
    virtual int set_get_test_modulus(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_modulus_ = &derives::get_test_modulus;
        return err;
    }
    virtual int set_get_literal_modulus(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_modulus_ = &derives::get_literal_modulus;
        return err;
    }

    /// ...get_p
    const byte_t* (derives::*get_p_)
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length);
    virtual const byte_t* get_p
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length) {
        const byte_t* bytes = 0;
        if (get_p_) {
            bytes = (this->*get_p_)(q, dmp1, dmq1, iqmp, length);
        } else {
            bytes = get_test_p(q, dmp1, dmq1, iqmp, length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_p
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length) {
        const byte_t* bytes = 0;
        length = sizeof(::xos::app::console::crypto::rsa::rsa_private_p);
        bytes = ::xos::app::console::crypto::rsa::rsa_private_p;
        q = ::xos::app::console::crypto::rsa::rsa_private_q;
        dmp1 = ::xos::app::console::crypto::rsa::rsa_private_dmp1;
        dmq1 = ::xos::app::console::crypto::rsa::rsa_private_dmq1;
        iqmp = ::xos::app::console::crypto::rsa::rsa_private_iqmp;
        return bytes;
    }
    virtual const byte_t* get_literal_p
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length) {
        const byte_t* bytes = 0;
        length = p_.length();
        bytes = p_.elements();
        q = q_.elements();
        dmp1 = dmp1_.elements();
        dmq1 = dmq1_.elements();
        iqmp = iqmp_.elements();
        return bytes;;
    }
    virtual int set_get_test_p(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_p_ = &derives::get_test_p;
        return err;
    }
    virtual int set_get_literal_p(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_p_ = &derives::get_literal_p;
        return err;
    }

    /// ...get_rsa...
    const byte_t* (derives::*get_rsa_plain_)(size_t &length);
    virtual const byte_t* get_rsa_plain(size_t &length) {
        const byte_t* bytes = 0;
        if (get_rsa_plain_) {
            bytes = (this->*get_rsa_plain_)(length);
        } else {
            bytes = get_test_rsa_plain(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_rsa_plain(size_t &length) {
        const byte_t *bytes = 0, *modulus = 0;
        size_t modbytes = 0;

        if ((modulus = this->get_modulus(modbytes)) && (modbytes)
            && (modbytes >= modbytes_min) && (modbytes <= modbytes_max)) {
            size_t size = 0, sizeof_plain = 0;
            byte_t *plain = &this->rsa_decipher(sizeof_plain);
            
            if (modbytes == (size = this->random(plain, modbytes))) {
                length = size;
                bytes = plain;
            }
        }
        return bytes;
    }
    virtual const byte_t* get_literal_rsa_plain(size_t &length) {
        const byte_t* bytes = 0;
        length = rsa_plain_array_.length();
        bytes = rsa_plain_array_.elements();
        return bytes;
    }
    virtual int set_get_test_rsa_plain(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_rsa_plain_ = &derives::get_test_rsa_plain;
        return err;
    }
    virtual int set_get_literal_rsa_plain(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_rsa_plain_ = &derives::get_literal_rsa_plain;
        return err;
    }
    const byte_t* (derives::*get_rsa_cipher_)(size_t &length);
    virtual const byte_t* get_rsa_cipher(size_t &length) {
        const byte_t* bytes = 0;
        if (get_rsa_cipher_) {
            bytes = (this->*get_rsa_cipher_)(length);
        } else {
            bytes = get_test_rsa_cipher(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_rsa_cipher(size_t &length) {
        const byte_t *bytes = 0, *modulus = 0;
        size_t modbytes = 0;

        if ((modulus = this->get_modulus(modbytes)) && (modbytes)
            && (modbytes >= modbytes_min) && (modbytes <= modbytes_max)) {
            size_t size = 0, sizeof_cipher = 0;
            byte_t *cipher = &this->rsa_plain(sizeof_cipher);
            
            if (modbytes == (size = this->random(cipher, modbytes))) {
                length = size;
                bytes = cipher;
            }
        }
        return bytes;;
    }
    virtual const byte_t* get_literal_rsa_cipher(size_t &length) {
        const byte_t* bytes = 0;
        length = rsa_cipher_array_.length();
        bytes = rsa_cipher_array_.elements();
        return bytes;;
    }
    virtual int set_get_test_rsa_cipher(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_rsa_cipher_ = &derives::get_test_rsa_cipher;
        return err;
    }
    virtual int set_get_literal_rsa_cipher(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_rsa_cipher_ = &derives::get_literal_rsa_cipher;
        return err;
    }
    
    /// ...rsa...
    virtual byte_t& rsa_plain(size_t& size) const {
        size = sizeof(rsa_plain_);
        return (byte_t&)(rsa_plain_[0]);
    }
    virtual byte_t& rsa_cipher(size_t& size) const {
        size = sizeof(rsa_cipher_);
        return (byte_t&)(rsa_cipher_[0]);
    }
    virtual byte_t& rsa_decipher(size_t& size) const {
        size = sizeof(rsa_decipher_);
        return (byte_t&)(rsa_decipher_[0]);
    }

    /// ...exponent...
    virtual uint32_t& set_exponent_value(const uint32_t& to) {
        exponent_value_ = to;
        return exponent_value_;
    }
    virtual uint32_t& exponent_value() const {
        return (uint32_t&)exponent_value_;
    }
    virtual size_t& set_exponent_bits(const size_t& to) {
        exponent_bits_ = to;
        return exponent_bits_;
    }
    virtual size_t& exponent_bits() const {
        return (size_t&)exponent_bits_;
    }

    /// ...modulus...
    virtual size_t& set_modulus_bits(const size_t& to) {
        modulus_bits_ = to;
        return modulus_bits_;
    }
    virtual size_t& modulus_bits() const {
        return (size_t&)modulus_bits_;
    }

protected:
    enum {
        modbytes_min = 512/8,
        modbytes_max = 4096/8
    };
    uint32_t exponent_value_;
    size_t exponent_bits_, modulus_bits_;
    byte_array_t exponent_, modulus_, p_, q_, dmp1_, dmq1_, iqmp_, rsa_plain_array_, rsa_cipher_array_;
    byte_t rsa_plain_[modbytes_max], rsa_cipher_[modbytes_max], rsa_decipher_[modbytes_max];
}; /// class maint
typedef maint<> main;

} /// namespace rsa
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_RSA_MAIN_HPP
