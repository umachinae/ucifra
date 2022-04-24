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
///   File: number_extend.hpp
///
/// Author: $author$
///   Date: 4/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_CRYPTO_RANDOM_PRIME_BN_NUMBER_EXTEND_HPP
#define XOS_CRYPTO_RANDOM_PRIME_BN_NUMBER_EXTEND_HPP

#include "xos/crypto/random/prime/bn/license.hpp"
#include "xos/crypto/random/prime/bn/number_implement.hpp"

namespace xos {
namespace crypto {
namespace random {
namespace prime {
namespace bn {

/// class number_extendt
template 
<class TExtends = xos::crypto::extend, 
 class TImplements = xos::crypto::random::prime::bn::number_implement>

class exported number_extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef number_extendt Derives, derives; 
    
    /// constructors / destructor
    number_extendt(const number_extendt& copy) {
    }
    number_extendt() {
    }
    virtual ~number_extendt() {
    }

}; /// class number_extendt
typedef number_extendt<> number_extend;

} /// namespace bn
} /// namespace prime
} /// namespace random
} /// namespace crypto
} /// namespace xos

#endif /// XOS_CRYPTO_RANDOM_PRIME_BN_NUMBER_EXTEND_HPP
