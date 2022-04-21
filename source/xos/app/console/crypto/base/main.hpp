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
///   Date: 2/21/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_HPP

#include "xos/app/console/crypto/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::crypto::base::main_opt, 
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
    typedef typename extends::string_reader_t string_reader_t;
    typedef typename extends::char_reader_t char_reader_t;

    /// constructor / destructor
    maint()
    : run_(0), 
      input_x_(0), output_x_(0), output_x_ln_(true), 
      output_hex_(0), output_hex_x_(0) {
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

    /// ...input_x
    ssize_t (derives::*input_x_)(void* block, size_t length, char_reader_t& reader);
    virtual ssize_t input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((this->input_x_)) {
            count = (this->*input_x_)(block, length, reader);
        } else {
            count = lower_input_x(block, length, reader);
        }
        return count;
    }
    virtual ssize_t base64_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((block) && (length)) {
            count = reader.read64(block, length);
        }
        return count;
    }
    virtual ssize_t upper_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((block) && (length)) {
           count = reader.readx(block, length);
        }
        return count;
    }
    virtual ssize_t lower_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((block) && (length)) {
            count = reader.readx(block, length);
        }
        return count;
    }
    virtual ssize_t before_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t after_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t all_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if (0 <= (count = before_input_x(block, length, reader))) {
            ssize_t count2 = 0;
            count = input_x(block, length, reader);
            if (0 > (count2 = after_input_x(block, length, reader))) {
                if (0 <= (count)) count = count2;
            }
        }
        return count;
    }

    /// ...output_x
    int (derives::*output_x_)(const void* block, size_t length);
    virtual int output_x(const void* block, size_t length) {
        int err = 0;
        if ((this->output_x_)) {
            err = (this->*output_x_)(block, length);
        } else {
            err = lower_output_x(block, length);
        }
        return err;
    }
    virtual int base64_output_x(const void* block, size_t length) {
        int err = 0;
        if ((block) && (length)) {
            if (output_x_ln()) {
                this->out64ln(block, length);
            } else {
                this->out64(block, length);
            }
        }
        return err;
    }
    virtual int upper_output_x(const void* block, size_t length) {
        int err = 0;
        if ((block) && (length)) {
            if (output_x_ln()) {
                this->outXln(block, length);
            } else {
                this->outX(block, length);
            }
        }
        return err;
    }
    virtual int lower_output_x(const void* block, size_t length) {
        int err = 0;
        if ((block) && (length)) {
            if (output_x_ln()) {
                this->outxln(block, length);
            } else {
                this->outx(block, length);
            }
        }
        return err;
    }
    virtual int text_output_x(const void* block, size_t length) {
        int err = 0;
        const char_t* chars = 0;
        if ((chars = ((const char_t*)block)) && (length)) {
            if (output_x_ln()) {
                this->outln(chars, length);
            } else {
                this->out(chars, length);
            }
        }
        return err;
    }
    virtual int before_output_x(const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int after_output_x(const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int all_output_x(const void* block, size_t length) {
        int err = 0;
        if (!(err = before_output_x(block, length))) {
            int err2 = 0;
            err = output_x(block, length);
            if ((err2 = after_output_x(block, length))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_base64_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_x_ = &derives::base64_input_x;
        output_x_ = &derives::base64_output_x;
        return err;
    }
    virtual int set_upper_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_x_ = &derives::upper_input_x;
        output_x_ = &derives::upper_output_x;
        return err;
    }
    virtual int set_lower_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_x_ = &derives::lower_input_x;
        output_x_ = &derives::lower_output_x;
        return err;
    }
    virtual int set_text_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_x_ = &derives::text_output_x;
        return err;
    }

    /// ...output_x
    virtual int output_x(const char_t* chars, const void* block, size_t length) {
        int err = 0;
        if ((chars)) {
            this->outln(chars, length);
        } else {
            err = this->all_output_x(block, length);
        }
        return err;
    }
    virtual int before_output_x(const char_t* chars, const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int after_output_x(const char_t* chars, const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int all_output_x(const char_t* chars, const void* block, size_t length) {
        int err = 0;
        if (!(err = before_output_x(chars, block, length))) {
            int err2 = 0;
            err = output_x(chars, block, length);
            if ((err2 = after_output_x(chars, block, length))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...output_hex
    int (derives::*output_hex_)(const void* out, size_t len);
    virtual int output_hex(const void* out, size_t len) {
        int err = 0;
        if (output_hex_) {
            err = (this->*output_hex_)(out, len);
        } else {
            err = default_output_hex(out, len);
        }
        return err;
    }
    virtual int default_output_hex(const void* out, size_t len) {
        int err = 0;
        const byte_t *bytes = 0;

        if ((bytes = ((const byte_t*)out)) && (len)) {
            size_t cols = 32, col = 0;
            char_t nextln = '\\';

            for (col = 0; len; --len, ++bytes, ++col) {
                if (cols <= (col)) {
                    this->outln(&nextln, 1);
                    col = 0;
                }
                this->output_hex_x(bytes, 1);
            }
            this->outln();
        }
        return err;
    }
    int (derives::*output_hex_x_)(const void* out, size_t len);
    virtual int output_hex_x(const void* out, size_t len) {
        int err = 0;
        if (output_hex_x_) {
            err = (this->*output_hex_x_)(out, len);
        } else {
            err = lower_output_hex_x(out, len);
        }
        return err;
    }
    virtual int lower_output_hex_x(const void* out, size_t len) {
        int err = 0;
        const byte_t *bytes = 0;

        if ((bytes = ((const byte_t*)out)) && (len)) {
            this->outx(bytes, len);
        }
        return err;
    }
    virtual int upper_output_hex_x(const void* out, size_t len) {
        int err = 0;
        const byte_t *bytes = 0;

        if ((bytes = ((const byte_t*)out)) && (len)) {
            this->outX(bytes, len);
        }
        return err;
    }
    virtual int set_lower_output_hex_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_hex_x_ = &derives::lower_output_hex_x;
        return err;
    }
    virtual int set_upper_output_hex_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_hex_x_ = &derives::upper_output_hex_x;
        return err;
    }

    /// on...option
    virtual int on_set_plain_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_plain_text(optarg);
            this->on_plain_text_set(optarg);
            this->set_plain_run(argc, argv, env);
        }
        return err;
    }
    virtual int on_set_cipher_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_cipher_text(optarg);
            this->on_cipher_text_set(optarg);
            this->set_cipher_run(argc, argv, env);
        }
        return err;
    }
    virtual int on_base64_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_base64_output_x(argc, argv, env))) {
        }
        return err;
    }
    virtual int on_upper_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_upper_output_x(argc, argv, env))) {
            if (!(err = this->set_upper_output_hex_x(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int on_lower_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_lower_output_x(argc, argv, env))) {
            if (!(err = this->set_lower_output_hex_x(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int on_text_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_text_output_x(argc, argv, env))) {
        }
        return err;
    }
    virtual int on_no_line_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_output_x_ln(false);
        return err;
    }
    virtual int on_line_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_output_x_ln(true);
        return err;
    }

    /// ...output_x_ln
    bool output_x_ln_;
    virtual bool set_output_x_ln(bool to = true) {
        output_x_ln_ = to;
        return output_x_ln_;
    }
    virtual bool output_x_ln() const {
        return output_x_ln_;
    }

    /// ...plain... / ...cipher...
    virtual const char_t* set_plain_text(const char_t* to) {
        plain_text_.assign(to);
        return plain_text_.chars();
    }
    virtual const char_t* plain_text(size_t& length) const {
        return plain_text_.has_chars(length);
    }
    virtual const string_t& plain_text_string() const {
        return plain_text_;
    }
    virtual const char_t* set_cipher_text(const char_t* to) {
        cipher_text_.assign(to);
        return cipher_text_.chars();
    }
    virtual const char_t* cipher_text(size_t& length) const {
        return cipher_text_.has_chars(length);
    }
    virtual const string_t& cipher_text_string() const {
        return cipher_text_;
    }

protected:
    string_t plain_text_, cipher_text_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_HPP
