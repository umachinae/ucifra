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
///   Date: 2/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPT_HPP

#include "xos/app/console/crypto/hash/base/main.hpp"

#include "xos/crypto/hash/md5.hpp"
#include "xos/crypto/hash/sha1.hpp"
#include "xos/crypto/hash/sha256.hpp"
#include "xos/crypto/hash/sha512.hpp"

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPT "md5"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTUSE "md5 algorithm"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTVAL_S "d"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPT "sha1"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTUSE "sha1 algorithm"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTVAL_S "1"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTVAL_C '1'
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPT "sha256"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTUSE "sha256 algorithm"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTVAL_S "2"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTVAL_C '2'
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPT "sha512"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTUSE "sha512 algorithm"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTVAL_S "5"
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTVAL_C '5'
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTION \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTION \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTION \
    XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTION \

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_ARGS \
    XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_ARGS

#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_ARGV \
    XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_ARGV

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace hash {

/// class main_optt
template 
<class TExtends = xos::app::console::crypto::hash::base::main, 
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

    /// ...hash_algorithm
    xos::crypto::hash::algorithm* (derives::*hash_algorithm_)() const;
    virtual xos::crypto::hash::algorithm* hash_algorithm() const {
        if ((this->hash_algorithm_)) {
            return (this->*hash_algorithm_)();
        }
        return default_hash_algorithm();
    }
    virtual xos::crypto::hash::algorithm* default_hash_algorithm() const {
        return sha256_hash_algorithm();
    }
    virtual xos::crypto::hash::algorithm* md5_hash_algorithm() const {
        return 0;
    }
    virtual xos::crypto::hash::algorithm* sha1_hash_algorithm() const {
        return 0;
    }
    virtual xos::crypto::hash::algorithm* sha256_hash_algorithm() const {
        return 0;
    }
    virtual xos::crypto::hash::algorithm* sha512_hash_algorithm() const {
        return 0;
    }

    /// on_..._option
    virtual int on_d_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        hash_algorithm_ = &derives::md5_hash_algorithm;
        err = this->set_plain_run(argc, argv, env);
        return err;
    }
    virtual const char_t* on_d_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTARG;
        return chars;
    }
    virtual int on_1_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        hash_algorithm_ = &derives::sha1_hash_algorithm;
        err = this->set_plain_run(argc, argv, env);
        return err;
    }
    virtual const char_t* on_1_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTARG;
        return chars;
    }
    virtual int on_2_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        hash_algorithm_ = &derives::sha256_hash_algorithm;
        err = this->set_plain_run(argc, argv, env);
        return err;
    }
    virtual const char_t* on_2_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTARG;
        return chars;
    }
    virtual int on_5_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        hash_algorithm_ = &derives::sha512_hash_algorithm;
        err = this->set_plain_run(argc, argv, env);
        return err;
    }
    virtual const char_t* on_5_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTVAL_C:
            err = this->on_5_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTVAL_C:
            err = this->on_2_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTVAL_C:
            err = this->on_1_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTVAL_C:
            err = this->on_d_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_5_OPTVAL_C:
            chars = this->on_5_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_2_OPTVAL_C:
            chars = this->on_2_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_1_OPTVAL_C:
            chars = this->on_1_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_D_OPTVAL_C:
            chars = this->on_d_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace hash
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_OPT_HPP
