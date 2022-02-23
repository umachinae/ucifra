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
#   File: usha.pri
#
# Author: $author$
#   Date: 2/23/2022
#
# generic QtCreator project .pri file for framework ucifra executable usha
########################################################################

########################################################################
# usha

# usha TARGET
#
usha_TARGET = usha

# usha INCLUDEPATH
#
usha_INCLUDEPATH += \
$${ucifra_INCLUDEPATH} \

# usha DEFINES
#
usha_DEFINES += \
$${ucifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# usha OBJECTIVE_HEADERS
#
#usha_OBJECTIVE_HEADERS += \
#$${UCIFRA_SRC}/xos/app/console/crypto/hash/base/main.hh \

# usha OBJECTIVE_SOURCES
#
#usha_OBJECTIVE_SOURCES += \
#$${UCIFRA_SRC}/xos/app/console/crypto/hash/base/main.mm \

########################################################################
# usha HEADERS
#
usha_HEADERS += \
$${UCIFRA_SRC}/xos/app/console/crypto/base/main_opt.hpp \
$${UCIFRA_SRC}/xos/app/console/crypto/base/main.hpp \
\
$${UCIFRA_SRC}/xos/app/console/crypto/hash/base/main_opt.hpp \
$${UCIFRA_SRC}/xos/app/console/crypto/hash/base/main.hpp \
\
$${UCIFRA_SRC}/xos/app/console/crypto/hash/main_opt.hpp \
$${UCIFRA_SRC}/xos/app/console/crypto/hash/main.hpp \

# usha SOURCES
#
usha_SOURCES += \
$${UCIFRA_SRC}/xos/app/console/crypto/hash/main_opt.cpp \
$${UCIFRA_SRC}/xos/app/console/crypto/hash/main.cpp \

########################################################################
# usha FRAMEWORKS
#
usha_FRAMEWORKS += \
$${ucifra_FRAMEWORKS} \

# usha LIBS
#
usha_LIBS += \
$${ucifra_LIBS} \

########################################################################
# NO Qt
QT -= gui core

