########################################################################
# Copyright (c) 1988-2022 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: libucifra.pri
#
# Author: $author$
#   Date: 1/26/2022
#
# generic QtCreator project .pri file for framework ucifra static library libucifra
########################################################################

########################################################################
# libucifra
XOS_LIB_UCIFRA_VERSION_BUILD_DATE = 1/26/2022 #$$system(~/bin/utility/tdate)

# libucifra TARGET
#
libucifra_TARGET = ucifra
libucifra_TEMPLATE = lib
libucifra_CONFIG += staticlib

# libucifra INCLUDEPATH
#
libucifra_INCLUDEPATH += \
$${ucifra_INCLUDEPATH} \

# libucifra DEFINES
#
libucifra_DEFINES += \
$${ucifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_UCIFRA_VERSION_BUILD_DATE=$${XOS_LIB_UCIFRA_VERSION_BUILD_DATE} \

########################################################################
# libucifra OBJECTIVE_HEADERS
#
#libucifra_OBJECTIVE_HEADERS += \
#$${UCIFRA_SRC}/xos/lib/ucifra/version.hh \

# libucifra OBJECTIVE_SOURCES
#
#libucifra_OBJECTIVE_SOURCES += \
#$${UCIFRA_SRC}/xos/lib/ucifra/version.mm \

########################################################################
# libucifra HEADERS
#
libucifra_HEADERS += \
$${CIFRA_SRC}/xos/crypto/base.hpp \
$${CIFRA_SRC}/xos/crypto/hash.hpp \
$${CIFRA_SRC}/xos/crypto/random.hpp \
$${CIFRA_SRC}/xos/crypto/cipher.hpp \
\
$${UCIFRA_SRC}/xos/lib/ucifra/version.hpp \

# libucifra SOURCES
#
libucifra_SOURCES += \
$${CIFRA_SRC}/xos/crypto/base.cpp \
$${CIFRA_SRC}/xos/crypto/hash.cpp \
$${CIFRA_SRC}/xos/crypto/random.cpp \
$${CIFRA_SRC}/xos/crypto/cipher.cpp \
\
$${UCIFRA_SRC}/xos/lib/ucifra/version.cpp \

########################################################################

