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
///   File: public_key.hpp
///
/// Author: $author$
///   Date: 7/6/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_ECC_CURVE25519_MSOTOODEH_PUBLIC_KEY_HPP
#define XOS_CRYPTO_ECC_CURVE25519_MSOTOODEH_PUBLIC_KEY_HPP

#include "xos/crypto/ecc/curve25519/public_key.hpp"
#include "thirdparty/msotoodeh/curve25519/curve25519_mehdi.hxx"

namespace xos {
namespace crypto {
namespace ecc {
namespace curve25519 {
namespace msotoodeh {

/// class public_keyt
template 
<class TPublicKey = curve25519::public_key, class TExtends = TPublicKey, class TImplements = typename TExtends::implements>

class exported public_keyt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef public_keyt derives; 
    
    /// constructors / destructor
    public_keyt(const byte_t* elements, size_t length): extends(elements, length) {
    }
    public_keyt(const private_key& from_private, const base_point& from_base) {
        construct(from_private, from_base);
    }
    public_keyt(const public_keyt& copy): extends(copy) {
    }
    public_keyt() {
    }
    virtual ~public_keyt() {
    }
private:
    void construct(const private_key& from_private, const base_point& from_base) {
        if (!(generate(from_private, from_base))) {
            LOGGER_IS_LOGGED_ERROR("...failed on generate(from_private, from_base) throw exception(exception_failed)...");
            throw exception(exception_failed);
        }
    }

public:
    /// generate
    using extends::generate;
    virtual bool generate(key& to, const private_key& from_private, const key& from_public) const {
        byte_t& p = to[0];
        const byte_t& s = from_private[0];
        const byte_t& b = from_public[0];
        int err = 0;
        LOGGER_IS_LOGGED_DEBUG("curve25519_mehdi(&p, &s, &b)...")
        if (!(err = curve25519_mehdi(&p, &b, &s))) {
            LOGGER_IS_LOGGED_DEBUG("...curve25519_mehdi(&p, &s, &b)")
            return true;
        }
        return false;
    }

}; /// class public_keyt
typedef public_keyt<> public_key;

} /// namespace msotoodeh
} /// namespace curve25519
} /// namespace ecc
} /// namespace crypto
} /// namespace xos

#endif /// ndef XOS_CRYPTO_ECC_CURVE25519_MSOTOODEH_PUBLIC_KEY_HPP
