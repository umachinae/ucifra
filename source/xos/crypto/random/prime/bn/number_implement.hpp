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
///   File: number_implement.hpp
///
/// Author: $author$
///   Date: 4/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RANDOM_PRIME_BN_NUMBER_IMPLEMENT_HPP
#define XOS_CRYPTO_RANDOM_PRIME_BN_NUMBER_IMPLEMENT_HPP

#include "xos/crypto/random/prime/bn/license.hpp"
#include "xos/crypto/base.hpp"
#include "xos/base/created.hpp"
#include "xos/base/attached.hpp"
#include "bn_msb.h"

namespace xos {
namespace crypto {
namespace random {
namespace prime {
namespace bn {

typedef BIGNUM BIGPRIME;
typedef BIGNUM* BIGINT;

/// class number_implementt
template <class TImplements = xos::crypto::implement>
class exported number_implementt: virtual public TImplements {
public:
    typedef TImplements Implements, implements;
    typedef number_implementt Derives, derives; 
    
    /// constructors / destructor
    virtual ~number_implementt() {
    }

    /// BN...free
    virtual bool BN_CTX_free(BN_CTX*& a) {
        if ((a)) {
            ::BN_CTX_free(a);
            a = 0;
            return true;
        }
        return false;
    }
    virtual bool BN_free(BIGNUM*& a) {
        if ((a)) {
            ::BN_free(a);
            a = 0;
            return true;
        }
        return false;
    }
}; /// class number_implementt
typedef number_implementt<> number_implement;

} /// namespace bn
} /// namespace prime
} /// namespace random
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RANDOM_PRIME_BN_NUMBER_IMPLEMENT_HPP
