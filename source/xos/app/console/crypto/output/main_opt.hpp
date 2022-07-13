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
///   Date: 7/7/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_OPT_HPP

#include "xos/app/console/crypto/base/main.hpp"
#include "xos/io/hex/read_to_arrays.hpp"
#include "xos/io/hex/read_to_array.hpp"
#include "xos/io/crt/file/reader.hpp"
#include "xos/base/array.hpp"
#include "xos/crypto/array.hpp"

#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPT "verbose"
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTUSE "verbose output"
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTVAL_S "v"
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTVAL_C 'v'
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPT "quiet"
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTUSE "quiet output"
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTVAL_S "q"
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTVAL_C 'q'
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPT, \
    XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_0X_HEX_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTVAL_S \
    XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_0X_HEX_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_HEX_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_HEX_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_TEXT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTION \
    XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTION \
    XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_UCIFRA_MAIN_LOGGING_OPTIONS_CHARS

#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_UCIFRA_MAIN_LOGGING_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_ARGS 0
#define XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace output {

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

    /// constructor / destructor
    main_optt()
    : run_(0), 
      const_0x_output_(false), verbose_output_(false) {
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

    typedef xos::byte_array byte_array_t;
    typedef xos::crypto::array crypto_array_t;

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

    ///
    /// output_const_0x_verbage...
    /// ...
    virtual int output_const_0x_verbage_sized(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_const_0x_verbage_sized(verbage, bytes, length);
        }
        return err;
    }
    virtual int output_const_0x_verbage_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        err = output_0x_verbage_sized
        ("const byte_t ", " = {", "};", verbage, out, len);
        return err;
    }
    virtual int output_0x_verbage_sized
    (const char_t* before, const char_t* between, const char_t* after, 
     const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            if ((before) && (before[0])) {
                this->out(before);
            }
            if ((verbage) && (verbage[0])) {
                unsigned_to_string size(len);
                this->out(verbage);
                this->out("[");
                this->out(size);
                this->out("]");
            }
            if ((between) && (between[0])) {
                this->outln(between);
            }
            this->output_0x(out, len);
            if ((after) && (after[0])) {
                this->outln(after);
            } else {
                if ((verbage) && (verbage[0])) {
                    this->outln();
                }
            }
        }
        return err;
    }
    /// ...
    /// output_const_0x_verbage...
    /// 

    /// 
    /// output_hex_verbage...
    /// ...
    virtual int output_hex_verbage_sized(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_hex_verbage_sized(verbage, bytes, length);
        }
        return err;
    }
    typedef int (derives::*output_hex_verbage_sized_t)(const char_t* verbage, const void* out, size_t len);
    output_hex_verbage_sized_t output_hex_verbage_sized_;
    virtual int output_hex_verbage_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if (output_hex_verbage_sized_) {
            err = (this->*output_hex_verbage_sized_)(verbage, out, len);
        } else {
            err = default_output_hex_verbage_sized(verbage, out, len);
        }
        return err;
    }
    virtual int default_output_hex_verbage_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose();
            if ((verbose) && (verbage) && (verbage[0])) {
                unsigned_to_string size(len);
                this->out(verbage);
                this->out("[");
                this->out(size);
                this->outln("]:\\");
            }
            this->output_hex(out, len);
            if ((verbose) && (verbage) && (verbage[0])) {
                this->outln();
            }
        }
        return err;
    }
    virtual output_hex_verbage_sized_t set_output_const_0x_verbage_sized() {
        output_hex_verbage_sized_t output_hex_verbage_sized = output_hex_verbage_sized_;
        output_hex_verbage_sized_ = &derives::output_const_0x_verbage_sized;
        return output_hex_verbage_sized;
    }
    virtual output_hex_verbage_sized_t unset_output_0x_verbage_sized(output_hex_verbage_sized_t to) {
        output_hex_verbage_sized_t output_hex_verbage_sized = output_hex_verbage_sized_;
        output_hex_verbage_sized_ = to;
        return output_hex_verbage_sized;
    }
    virtual int output_hex_verbage(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_hex_verbage(verbage, bytes, length);
        }
        return err;
    }
    virtual int output_hex_verbage(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose();
            if ((verbose) && (verbage) && (verbage[0])) {
                this->out(verbage);
                this->outln(":\\");
            }
            this->output_hex(out, len);
            if ((verbose) && (verbage) && (verbage[0])) {
                this->outln();
            }
        }
        return err;
    }
    /// ...
    /// output_hex_verbage...
    /// 

    /// 
    /// output_hex_verbose...
    /// ...
    virtual int output_hex_verbose_sized(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_hex_verbose_sized(verbage, bytes, length);
        }
        return err;
    }
    typedef int (derives::*output_hex_verbose_sized_t)(const char_t* verbage, const void* out, size_t len);
    output_hex_verbose_sized_t output_hex_verbose_sized_;
    virtual int output_hex_verbose_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if (output_hex_verbose_sized_) {
            err = (this->*output_hex_verbose_sized_)(verbage, out, len);
        } else {
            err = default_output_hex_verbose_sized(verbage, out, len);
        }
        return err;
    }
    virtual int default_output_hex_verbose_sized(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose();
            if ((verbose) && (verbage) && (verbage[0])) {
                unsigned_to_string size(len);
                this->out(verbage);
                this->out("[");
                this->out(size);
                this->outln("]:\\");
                this->output_hex(out, len);
                this->outln();
            }
        }
        return err;
    }
    virtual int output_hex_verbose(const char_t* verbage, const byte_array_t& array) {
        int err = 0;
        size_t length = 0;
        const byte_t* bytes = 0; 
        if ((bytes = array.has_elements(length))) {
            err = output_hex_verbose(verbage, bytes, length);
        }
        return err;
    }
    virtual int output_hex_verbose(const char_t* verbage, const void* out, size_t len) {
        int err = 0;
        if ((out) && (len)) {
            bool verbose = this->verbose();
            if ((verbose) && (verbage) && (verbage[0])) {
                this->out(verbage);
                this->outln(":\\");
                this->output_hex(out, len);
                this->outln();
            }
        }
        return err;
    }
    /// ...
    /// output_hex_verbose...
    /// 

    ///
    /// ...on_set_hex_literals
    /// ...
    int (derives::*on_set_hex_literals_)(xos::io::hex::read_to_byte_arrays &to_arrays, string_t &literal);
    virtual int on_set_hex_literals(xos::io::hex::read_to_byte_arrays &to_arrays, string_t &literal) {
        int err = 0;
        if (on_set_hex_literals_) {
            err = (this->*on_set_hex_literals_)(to_arrays, literal);
        } else {
            err = default_on_set_hex_literals(to_arrays, literal);
        }
        return err;
    }
    virtual int default_on_set_hex_literals(xos::io::hex::read_to_byte_arrays &to_arrays, string_t &literal) {
        int err = 0;
        err = on_set_hex_file_literals(to_arrays, literal);
        return err;
    }
    virtual int on_set_hex_file_literals(xos::io::hex::read_to_byte_arrays &to_arrays, string_t &literal) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;

        if ((chars = literal.has_chars(length))) {
            xos::io::crt::file::char_reader file;

            this->errlln("file.open(\"", chars, "\")...", null);
            if ((file.open(chars))) {
                ssize_t count = 0;
                xos::io::hex::reader hex(to_arrays, file);
    
                if (0 >= (count = hex.read())) {
                    err = on_failed_set_hex_literals(to_arrays, literal);
                }
                this->errlln("...file.close(\"", chars, "\")...", null);
                file.close();
            }
        }
        return err;
    }
    virtual int on_failed_set_hex_literals(xos::io::hex::read_to_byte_arrays &to_arrays, string_t &literal) {
        int err = 0;
        size_t length = 0;
        xos::io::hex::read_to_byte_arrays::arrays_t &arrays = to_arrays.arrays();
        xos::io::hex::read_to_byte_arrays::array_pointer_t* array_pointers = 0;

        if ((array_pointers = arrays.elements(length))) {
            xos::io::hex::read_to_byte_arrays::array_pointer_t array_pointer = 0;

            for (array_pointer = *array_pointers; length; --length, ++array_pointers) {
                if ((array_pointer)) {
                    array_pointer->set_length(0);
                }
            }
        }
        return err;
    }
    /// ...
    /// ...on_set_hex_literals
    /// 

    /// random...
    virtual size_t random_plain(unsigned char *buff, size_t len) const {
        size_t size = 0;

        if ((buff) && (len)) {
            if (len == (size = random(buff, len))) {
                buff[0] &= 0x7F;
            }
        }
        return size;
    }
    virtual size_t random(unsigned char *buff, size_t len) const {
        static unsigned randnum = 0;
        static unsigned avail = 0;
        size_t size = 0;
        
        if ((buff) && (len)) {
            for (size = 0; size < len;) {
                if (avail < 1) {
                    randnum = (unsigned)rand();
                    avail = sizeof(randnum);
                }
                if (0 != (buff[size] = ((char)(randnum & 0xFF)))) {
                    ++size;
                }
                if ((randnum >>= 8) < 1) {
                    avail = 0;
                } else {
                    --avail;
                }
            }
        }
        return size;
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

    /// ...option...
    virtual int on_set_Ox_hex_option
    (int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_const_0x_output();
        return err;
    }
    virtual int on_verbose_output_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_verbose_output();
        return err;
    }
    virtual const char_t* verbose_output_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTARG;
        return chars;
    }
    virtual int on_quiet_output_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        set_quiet_output();
        return err;
    }
    virtual const char_t* quiet_output_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTUSE;
        optarg = XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTVAL_C:
            err = this->on_verbose_output_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTVAL_C:
            err = this->on_quiet_output_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_VERBOSE_OUTPUT_OPTVAL_C:
            chars = this->verbose_output_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_QUIET_OUTPUT_OPTVAL_C:
            chars = this->quiet_output_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// ...const_0x_output
    virtual bool set_const_0x_output(const bool to = true) {
        const_0x_output_ = to;
        return const_0x_output_;
    }
    virtual bool const_0x_output() const {
        return const_0x_output_;
    }

    /// ...verbose...
    virtual bool set_verbose_output(const bool to = true) {
        verbose_output_ = to;
        return verbose_output_;
    }
    virtual bool verbose_output() const {
        return verbose_output_;
    }
    virtual bool set_verbose(const bool to = true) {
        return set_verbose_output(to);
    }
    virtual bool verbose() const {
        return verbose_output();
    }

    /// ...quiet...
    virtual bool set_quiet_output(const bool to = true) {
        return !set_verbose_output(!to);
    }
    virtual bool quiet_output() const {
        return !verbose_output();
    }
    virtual bool set_quiet(const bool to = true) {
        return set_quiet_output(to);
    }
    virtual bool quiet() const {
        return quiet_output();
    }

protected:
    bool const_0x_output_, verbose_output_;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace output
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_OUTPUT_MAIN_OPT_HPP
