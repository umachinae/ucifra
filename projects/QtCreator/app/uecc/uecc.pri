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
#   File: uecc.pri
#
# Author: $author$
#   Date: 7/6/2022
#
# generic QtCreator project .pri file for framework ucifra executable uecc
########################################################################

########################################################################
# uecc

# uecc TARGET
#
uecc_TARGET = uecc

# uecc INCLUDEPATH
#
uecc_INCLUDEPATH += \
$${ucifra_INCLUDEPATH} \

# uecc DEFINES
#
uecc_DEFINES += \
$${ucifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# uecc OBJECTIVE_HEADERS
#
#uecc_OBJECTIVE_HEADERS += \
#$${UCIFRA_SRC}/xos/app/console/crypto/ecc/main.hh \

# uecc OBJECTIVE_SOURCES
#
#uecc_OBJECTIVE_SOURCES += \
#$${UCIFRA_SRC}/xos/app/console/crypto/ecc/main.mm \

########################################################################
# uecc HEADERS
#
uecc_HEADERS += \
$${UNADIR_SRC}/xos/base/array.hpp \
\
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/array.hpp \
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/key.hpp \
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/base_point.hpp \
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/private_key.hpp \
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/public_key.hpp \
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/shared_secret.hpp \
\
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/msotoodeh/public_key.hpp \
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/google/donna/public_key.hpp \
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/public_keys.hpp \
\
$${UCIFRA_SRC}/xos/app/console/crypto/output/main_opt.hpp \
$${UCIFRA_SRC}/xos/app/console/crypto/output/main.hpp \
\
$${UCIFRA_SRC}/xos/app/console/crypto/ecc/main_opt.hpp \
$${UCIFRA_SRC}/xos/app/console/crypto/ecc/main.hpp \

# uecc SOURCES
#
uecc_SOURCES += \
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/array.cpp \
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/key.cpp \
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/base_point.cpp \
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/private_key.cpp \
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/shared_secret.cpp \
$${UCIFRA_SRC}/xos/crypto/ecc/curve25519/public_keys.cpp \
\
$${UCIFRA_SRC}/xos/app/console/crypto/ecc/main_opt.cpp \
$${UCIFRA_SRC}/xos/app/console/crypto/ecc/main.cpp \

########################################################################
# uecc FRAMEWORKS
#
uecc_FRAMEWORKS += \
$${ucifra_FRAMEWORKS} \

# uecc LIBS
#
uecc_LIBS += \
$${ucifra_LIBS} \

########################################################################
# NO Qt
QT -= gui core

