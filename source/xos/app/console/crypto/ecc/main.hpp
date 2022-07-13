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
///   Date: 7/6/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_ECC_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_ECC_MAIN_HPP

#include "xos/app/console/crypto/ecc/main_opt.hpp"

#include "xos/crypto/random/generator.hpp"
#include "xos/crypto/random/pseudo/generator.hpp"

#include "xos/crypto/ecc/curve25519/key.hpp"
#include "xos/crypto/ecc/curve25519/base_point.hpp"
#include "xos/crypto/ecc/curve25519/private_key.hpp"
#include "xos/crypto/ecc/curve25519/public_key.hpp"
#include "xos/crypto/ecc/curve25519/shared_secret.hpp"
#include "xos/crypto/ecc/curve25519/msotoodeh/public_key.hpp"
#include "xos/crypto/ecc/curve25519/google/donna/public_key.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace ecc {

/// class maint
template 
<class TExtends = xos::app::console::crypto::ecc::main_opt, 
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
      pseudo_random_seed_(0), 
      pseudo_random_generator_(pseudo_random_seed_) {
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

    typedef typename extends::output_hex_verbage_sized_t output_hex_verbage_sized_t;

    typedef unsigned pseudo_random_seed_t;
    typedef xos::crypto::random::generator random_generator_t;
    typedef xos::crypto::random::pseudo::generator pseudo_random_generator_t;
    
    typedef xos::crypto::ecc::curve25519::base_point curve25519_base_point_t;
    typedef xos::crypto::ecc::curve25519::private_key curve25519_private_key_t;
    typedef xos::crypto::ecc::curve25519::public_key curve25519_public_key_t;
    typedef xos::crypto::ecc::curve25519::shared_secret curve25519_shared_secret_t;
    typedef xos::crypto::ecc::curve25519::msotoodeh::public_key mehdi_curve25519_public_key_t;
    typedef xos::crypto::ecc::curve25519::google::donna::public_key donna_curve25519_public_key_t;

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

    /// ...test_get_ecc_25519_key_pairs_run
    virtual int test_get_ecc_25519_key_pairs_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_array_t &public_key1 = this->public_key1(), &private_key1 = this->private_key1(), 
                           &public_key2 = this->public_key2(), &private_key2 = this->private_key2();
        const byte_t *public_key1_bytes = 0, *private_key1_bytes = 0,
                     *public_key2_bytes = 0, *private_key2_bytes = 0;
        size_t key_length = 0, length = 0;

        if ((public_key1_bytes = public_key1.elements(length)) && (key_length = length)) {
            if ((private_key1_bytes = private_key1.elements(length)) && (key_length == length)) {
                if ((public_key2_bytes = public_key2.elements(length)) && (key_length == length)) {
                    if ((private_key2_bytes = private_key2.elements(length)) && (key_length == length)) {
                        err = test_ecc_25519_key_exchange_run
                        (public_key1, private_key1, public_key2, private_key2, argc, argv, env);
                    }
                }
            }
        }
        return err;
    }

    /// ...output_ecc_25519_key_pairs...run...
    virtual int default_output_ecc_25519_key_pairs_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_array_t &public_key1 = this->public_key1(), &private_key1 = this->private_key1(), 
                           &public_key2 = this->public_key2(), &private_key2 = this->private_key2();
        const byte_t *public_key1_bytes = 0, *private_key1_bytes = 0,
                     *public_key2_bytes = 0, *private_key2_bytes = 0;
        size_t key_length = 0, length = 0;

        if ((public_key1_bytes = public_key1.elements(length)) && (key_length = length)) {
            if ((private_key1_bytes = private_key1.elements(length)) && (key_length == length)) {
                if ((public_key2_bytes = public_key2.elements(length)) && (key_length == length)) {
                    if ((private_key2_bytes = private_key2.elements(length)) && (key_length == length)) {
                        bool const_0x_output = this->const_0x_output();
                        output_hex_verbage_sized_t output_hex_verbage_sized = 0;

                        if ((const_0x_output)) {
                            output_hex_verbage_sized = this->set_output_const_0x_verbage_sized();
                        }
                        this->output_hex_verbage_sized("public_key1", public_key1_bytes, length);
                        this->output_hex_verbage_sized("private_key1", private_key1_bytes, length);
                        this->output_hex_verbage_sized("public_key2", public_key2_bytes, length);
                        this->output_hex_verbage_sized("private_key2", private_key2_bytes, length);
                        if ((const_0x_output)) {
                            this->unset_output_0x_verbage_sized(output_hex_verbage_sized);
                        }
                    }
                }
            }
        }
        return err;
    }

    /// ...generate_ecc_25519_key_pairs...run...
    virtual int generate_ecc_25519_key_pairs_mehdi_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        random_generator_t& r = this->random_generator();
        curve25519_base_point_t bp;
        curve25519_private_key_t private_key1(r), private_key2(r);
        mehdi_curve25519_public_key_t public_key1(private_key1, bp), public_key2(private_key2, bp);
        err = output_ecc_25519_key_pairs_run(public_key1, private_key1, public_key2, private_key2, argc, argv, env);
        return err;
    }
    virtual int generate_ecc_25519_key_pairs_donna_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        random_generator_t& r = this->random_generator();
        curve25519_base_point_t bp;
        curve25519_private_key_t private_key1(r), private_key2(r);
        donna_curve25519_public_key_t public_key1(private_key1, bp), public_key2(private_key2, bp);
        err = output_ecc_25519_key_pairs_run(public_key1, private_key1, public_key2, private_key2, argc, argv, env);
        return err;
    }
    /// output_ecc_25519_key_pairs_run
    virtual int output_ecc_25519_key_pairs_run
    (const curve25519_public_key_t& public_key1, const curve25519_private_key_t& private_key1, 
     const curve25519_public_key_t& public_key2,const curve25519_private_key_t& private_key2, 
     int argc, char_t** argv, char_t** env) {
        int err = 0;

        set_public_key1(public_key1.elements(), public_key1.size());
        set_private_key1(private_key1.elements(), private_key1.size());

        set_public_key2(public_key2.elements(), public_key2.size());
        set_private_key2(private_key2.elements(), private_key2.size());
        return err;
    }
    
    /// ...test_generated_ecc_25519_key_pairs...run...
    virtual int test_generated_ecc_25519_key_pairs_mehdi_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        random_generator_t& r = this->random_generator();
        curve25519_base_point_t bp;
        curve25519_private_key_t private_key1(r), private_key2(r);
        mehdi_curve25519_public_key_t public_key1(private_key1, bp), public_key2(private_key2, bp);
        err = test_ecc_25519_key_exchange_run(r, public_key1, private_key1, public_key2, private_key2, argc, argv, env);
        return err;
    }
    virtual int test_generated_ecc_25519_key_pairs_donna_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        random_generator_t& r = this->random_generator();
        curve25519_base_point_t bp;
        curve25519_private_key_t private_key1(r), private_key2(r);
        donna_curve25519_public_key_t public_key1(private_key1, bp), public_key2(private_key2, bp);
        err = test_ecc_25519_key_exchange_run(r, public_key1, private_key1, public_key2, private_key2, argc, argv, env);
        return err;
    }

    /// test_ecc_25519_key_exchange_run
    int (derives::*test_ecc_25519_key_exchange_run_)
    (const byte_array_t& public_key1, const byte_array_t& private_key1, 
     const byte_array_t& public_key2,const byte_array_t& private_key2, 
     int argc, char_t** argv, char_t** env);
    virtual int test_ecc_25519_key_exchange_run
    (const byte_array_t& public_key1, const byte_array_t& private_key1, 
     const byte_array_t& public_key2,const byte_array_t& private_key2, 
     int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((test_ecc_25519_key_exchange_run_)) {
            err = (this->*test_ecc_25519_key_exchange_run_)
            (public_key1, private_key1, public_key2, private_key2, argc, argv, env);
        } else {
            err = test_ecc_25519_key_exchange_mehdi_run
            (public_key1, private_key1, public_key2, private_key2, argc, argv, env);
        }
        return err;
    }
    virtual int test_ecc_25519_key_exchange_mehdi_run
    (const byte_array_t& public_key1, const byte_array_t& private_key1, 
     const byte_array_t& public_key2,const byte_array_t& private_key2, 
     int argc, char_t** argv, char_t** env) {
        int err = 0;
        random_generator_t& r = this->random_generator();
        mehdi_curve25519_public_key_t curve25519_public_key1(public_key1.elements(), public_key1.length()), 
                                curve25519_public_key2(public_key2.elements(), public_key2.length());
        curve25519_private_key_t curve25519_private_key1(private_key1.elements(), private_key1.length()), 
                                 curve25519_private_key2(private_key2.elements(), private_key2.length());
        err = test_ecc_25519_key_exchange_run
        (r, curve25519_public_key1, curve25519_private_key1, 
         curve25519_public_key2, curve25519_private_key2, argc, argv, env);
        return err;
    }
    virtual int set_test_ecc_25519_key_pairs_mehdi_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        test_ecc_25519_key_exchange_run_ = &derives::test_ecc_25519_key_exchange_mehdi_run;
        return err;
    }
    virtual int test_ecc_25519_key_exchange_donna_run
    (const byte_array_t& public_key1, const byte_array_t& private_key1, 
     const byte_array_t& public_key2,const byte_array_t& private_key2, 
     int argc, char_t** argv, char_t** env) {
        int err = 0;
        random_generator_t& r = this->random_generator();
        donna_curve25519_public_key_t curve25519_public_key1(public_key1.elements(), public_key1.length()), 
                                curve25519_public_key2(public_key2.elements(), public_key2.length());
        curve25519_private_key_t curve25519_private_key1(private_key1.elements(), private_key1.length()), 
                                 curve25519_private_key2(private_key2.elements(), private_key2.length());
        err = test_ecc_25519_key_exchange_run
        (r, curve25519_public_key1, curve25519_private_key1, 
         curve25519_public_key2, curve25519_private_key2, argc, argv, env);
        return err;
    }
    virtual int set_test_ecc_25519_key_pairs_donna_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        test_ecc_25519_key_exchange_run_ = &derives::test_ecc_25519_key_exchange_donna_run;
        return err;
    }
    virtual int test_ecc_25519_key_exchange_run
    (random_generator_t& r,
     const curve25519_public_key_t& public_key1, const curve25519_private_key_t& private_key1, 
     const curve25519_public_key_t& public_key2,const curve25519_private_key_t& private_key2, 
     int argc, char_t** argv, char_t** env) {
        int err = 0;
        curve25519_shared_secret_t s(private_key1, public_key2), s2(private_key2, public_key1);

        this->outln();
        this->out("private-key1: 0x"); this->outxln(private_key1.elements(), private_key1.size());
        this->out(" public-key1: 0x"); this->outxln(public_key1.elements(), public_key1.size());
        this->out("     secret1: 0x"); this->outxln(s.elements(), s.size());
        this->outln();

        this->out("private-key2: 0x"); this->outxln(private_key2.elements(), private_key2.size());
        this->out(" public-key2: 0x"); this->outxln(public_key2.elements(), public_key2.size());
        this->out("     secret2: 0x"); this->outxln(s2.elements(), s2.size());
        this->outln();

        if (!(bytes_t::compare(s.elements(), s2.elements(), s.length()))) {
            this->outln("     success: secret1 == secret2");
        } else {
            this->outln("      failed: secret1 != secret2");
            return 1;
        }
        this->outln();
        return err;
    }

    /// ...pseudo_random...
    virtual pseudo_random_seed_t& pseudo_random_seed() const {
        return (pseudo_random_seed_t&)pseudo_random_seed_;
    }
    virtual pseudo_random_generator_t& pseudo_random_generator() const {
        return (pseudo_random_generator_t&)pseudo_random_generator_;
    }
    virtual random_generator_t& random_generator() const {
        return pseudo_random_generator();
    }

    /// ...option...
    virtual int on_set_key_pairs_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            byte_array_t &public_key1 = this->public_key1(), &private_key1 = this->private_key1(),
                         &public_key2 = this->public_key2(), &private_key2 = this->private_key2();
            string_t literal(optarg);
            
            if (!(this->on_set_key_pairs_hex_literals
                 (public_key1, private_key1, public_key2, private_key2, literal))) {
            }
        }
        return err;
    }

    /// ...key1...
    virtual byte_array_t& set_public_key1(const byte_t* to, size_t length) {
        if ((to) && (length)) {
            public_key1_.assign(to, length);
        }
        return (byte_array_t&)public_key1_;
    }
    virtual byte_array_t& public_key1() const {
        return (byte_array_t&)public_key1_;
    }
    virtual byte_array_t& set_private_key1(const byte_t* to, size_t length) {
        if ((to) && (length)) {
            private_key1_.assign(to, length);
        }
        return (byte_array_t&)private_key1_;
    }
    virtual byte_array_t& private_key1() const {
        return (byte_array_t&)private_key1_;
    }
    /// ...key2...
    virtual byte_array_t& set_public_key2(const byte_t* to, size_t length) {
        if ((to) && (length)) {
            public_key2_.assign(to, length);
        }
        return (byte_array_t&)public_key2_;
    }
    virtual byte_array_t& public_key2() const {
        return (byte_array_t&)public_key2_;
    }
    virtual byte_array_t& set_private_key2(const byte_t* to, size_t length) {
        if ((to) && (length)) {
            private_key2_.assign(to, length);
        }
        return (byte_array_t&)private_key2_;
    }
    virtual byte_array_t& private_key2() const {
        return (byte_array_t&)private_key2_;
    }

protected:
    pseudo_random_seed_t pseudo_random_seed_;
    pseudo_random_generator_t pseudo_random_generator_;
    byte_array_t public_key1_, private_key1_, public_key2_, private_key2_;
}; /// class maint
typedef maint<> main;

} /// namespace ecc
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_ECC_MAIN_HPP
