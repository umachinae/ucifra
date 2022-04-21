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
#   File: ursa.pri
#
# Author: $author$
#   Date: 4/14/2022
#
# generic QtCreator project .pri file for framework ucifra executable ursa
########################################################################

########################################################################
# ursa

# ursa TARGET
#
ursa_TARGET = ursa

# ursa INCLUDEPATH
#
ursa_INCLUDEPATH += \
$${ucifra_INCLUDEPATH} \

# ursa DEFINES
#
ursa_DEFINES += \
$${ucifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# ursa OBJECTIVE_HEADERS
#
#ursa_OBJECTIVE_HEADERS += \
#$${UCIFRA_SRC}/xos/app/console/ursa/main.hh \

# ursa OBJECTIVE_SOURCES
#
#ursa_OBJECTIVE_SOURCES += \
#$${UCIFRA_SRC}/xos/app/console/ursa/main.mm \

########################################################################
# ursa HEADERS
#
ursa_HEADERS += \
$${UCIFRA_SRC}/xos/base/array.hpp \
$${UCIFRA_SRC}/xos/base/arrays.hpp \
\
$${UCIFRA_SRC}/xos/io/array/reader.hpp \
$${UCIFRA_SRC}/xos/io/told.hpp \
$${UCIFRA_SRC}/xos/io/delegated/reader.hpp \
$${UCIFRA_SRC}/xos/io/hex/reader.hpp \
$${UCIFRA_SRC}/xos/io/hex/read_to_array.hpp \
$${UCIFRA_SRC}/xos/io/hex/read_to_arrays.hpp \
\
$${UCIFRA_SRC}/xos/crypto/output.hpp \
\
$${UCIFRA_SRC}/xos/crypto/rsa/key/implement.hpp \
$${UCIFRA_SRC}/xos/crypto/rsa/key/extend.hpp \
\
$${UCIFRA_SRC}/xos/crypto/rsa/public_key/implement.hpp \
$${UCIFRA_SRC}/xos/crypto/rsa/public_key/extend.hpp \
\
$${UCIFRA_SRC}/xos/crypto/rsa/private_key/implement.hpp \
$${UCIFRA_SRC}/xos/crypto/rsa/private_key/extend.hpp \
\
$${UCIFRA_SRC}/xos/crypto/rsa/bn/key.hpp \
$${UCIFRA_SRC}/xos/crypto/rsa/bn/public_key.hpp \
$${UCIFRA_SRC}/xos/crypto/rsa/bn/private_key.hpp \
\
$${UCIFRA_SRC}/xos/crypto/rsa/mp/key.hpp \
$${UCIFRA_SRC}/xos/crypto/rsa/mp/public_key.hpp \
$${UCIFRA_SRC}/xos/crypto/rsa/mp/private_key.hpp \
\
$${UCIFRA_SRC}/xos/crypto/rsa/keys.hpp \
\
$${UCIFRA_SRC}/xos/app/console/ucifra/main_opt.hpp \
$${UCIFRA_SRC}/xos/app/console/ucifra/main.hpp \
\
$${UCIFRA_SRC}/xos/app/console/crypto/base/main_opt.hpp \
$${UCIFRA_SRC}/xos/app/console/crypto/base/main.hpp \
\
$${UCIFRA_SRC}/xos/app/console/crypto/rsa/main_opt.hpp \
$${UCIFRA_SRC}/xos/app/console/crypto/rsa/main.hpp \

# ursa SOURCES
#
ursa_SOURCES += \
$${UCIFRA_SRC}/xos/base/array.cpp \
$${UCIFRA_SRC}/xos/base/arrays.cpp \
\
$${UCIFRA_SRC}/xos/io/told.cpp \
$${UCIFRA_SRC}/xos/io/hex/reader.cpp \
$${UCIFRA_SRC}/xos/io/hex/read_to_array.cpp \
$${UCIFRA_SRC}/xos/io/hex/read_to_arrays.cpp \
\
$${UCIFRA_SRC}/xos/crypto/output.cpp \
\
$${UCIFRA_SRC}/xos/crypto/rsa/mp/key.cpp \
$${UCIFRA_SRC}/xos/crypto/rsa/mp/public_key.cpp \
$${UCIFRA_SRC}/xos/crypto/rsa/mp/private_key.cpp \
\
$${UCIFRA_SRC}/xos/crypto/rsa/keys.cpp \
\
$${UCIFRA_SRC}/xos/app/console/crypto/rsa/main_opt.cpp \
$${UCIFRA_SRC}/xos/app/console/crypto/rsa/main.cpp \

########################################################################
# ursa FRAMEWORKS
#
ursa_FRAMEWORKS += \
$${ucifra_rsa_FRAMEWORKS} \

# ursa LIBS
#
ursa_LIBS += \
$${ucifra_rsa_LIBS} \

########################################################################
# NO Qt
QT -= gui core

