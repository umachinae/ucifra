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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 2/21/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPT_HPP

#include "xos/app/console/crypto/base/main.hpp"

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPT "encrypt"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG "[string]"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTUSE "encrypt plain text"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_S "e::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_C 'e'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPT "decrypt"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG "[string]"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTUSE "decrypt cipher text"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_S "d::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPT "key"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTARG "[string]"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTUSE "encryption key"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTVAL_S "k::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTVAL_C 'k'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPT "iv"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTARG "[string]"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTUSE "initialization vector"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTVAL_S "i::"
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTVAL_C 'i'
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTION \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTION \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTION \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTION \

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGS \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_ARGS

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGV \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_ARGV

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::crypto::base::main, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_reader_t string_reader_t;
    typedef typename extends::char_reader_t char_reader_t;

    /// constructor / destructor
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

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

    /// ...encipher_run
    virtual int encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_encipher_run(argc, argv, env))) {
            int err2 = 0;
            err = encipher_run(argc, argv, env);
            if ((err2 = after_encipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_encipher_run;
        return err;
    }

    /// ...decipher_run
    virtual int decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_decipher_run(argc, argv, env))) {
            int err2 = 0;
            err = decipher_run(argc, argv, env);
            if ((err2 = after_decipher_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_decipher_run;
        return err;
    }

    /// ...get_key_run
    virtual int get_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* cipher_key = 0;
        size_t sizeof_cipher_key = 0;

        if ((cipher_key = this->cipher_key(sizeof_cipher_key))) {
            this->output_x(cipher_key, sizeof_cipher_key);
        }
        return err;
    }
    virtual int before_get_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_get_key_run(argc, argv, env))) {
            int err2 = 0;
            err = get_key_run(argc, argv, env);
            if ((err2 = after_get_key_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_get_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_get_key_run;
        return err;
    }

    /// ...get_iv_run
    virtual int get_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* cipher_iv = 0;
        size_t sizeof_cipher_iv = 0;

        if ((cipher_iv = this->cipher_iv(sizeof_cipher_iv))) {
            this->output_x(cipher_iv, sizeof_cipher_iv);
        }
        return err;
    }
    virtual int before_get_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_get_iv_run(argc, argv, env))) {
            int err2 = 0;
            err = get_iv_run(argc, argv, env);
            if ((err2 = after_get_iv_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_get_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_get_iv_run;
        return err;
    }

    /// ...cipher_key... / ...cipher_iv...
    virtual byte_t* cipher_key_data(size_t& sizeof_cipher_key) const {
        sizeof_cipher_key= 0;
        return 0;
    }
    virtual const byte_t* cipher_key(size_t& sizeof_cipher_key) const {
        sizeof_cipher_key= 0;
        return 0;
    }
    virtual byte_t* cipher_iv_data(size_t& sizeof_cipher_iv) const {
        sizeof_cipher_iv = 0;
        return 0;
    }
    virtual const byte_t* cipher_iv(size_t& sizeof_cipher_iv) const {
        sizeof_cipher_iv = 0;
        return 0;
    }
    
    /// ...option...
    virtual int on_encrypt_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            this->set_encipher_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* encrypt_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTARG;
        return chars;
    }
    virtual int on_decrypt_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            this->set_decipher_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* decrypt_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTARG;
        return chars;
    }
    virtual int on_set_key_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_get_key_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_get_key_run(argc, argv, env);
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_key_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = this->on_set_key_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            err = this->on_get_key_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* key_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTARG;
        return chars;
    }
    virtual int on_set_iv_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_get_iv_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_get_iv_run(argc, argv, env);
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_iv_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = this->on_set_iv_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            err = this->on_get_iv_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* iv_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTARG;
        return chars;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_C:
            err = this->on_encrypt_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_C:
            err = this->on_decrypt_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTVAL_C:
            err = this->on_key_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTVAL_C:
            err = this->on_iv_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ENCRYPT_OPTVAL_C:
            chars = this->encrypt_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_DECRYPT_OPTVAL_C:
            chars = this->decrypt_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_KEY_OPTVAL_C:
            chars = this->key_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_IV_OPTVAL_C:
            chars = this->iv_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base
} /// namespace cipher
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_OPT_HPP
