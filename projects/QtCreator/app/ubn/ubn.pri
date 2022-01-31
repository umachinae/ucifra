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
#   File: ubn.pri
#
# Author: $author$
#   Date: 1/28/2022
#
# generic QtCreator project .pri file for framework ucifra executable ubn
########################################################################

########################################################################
# ubn

# ubn TARGET
#
ubn_TARGET = ubn

# ubn INCLUDEPATH
#
ubn_INCLUDEPATH += \
$${ucifra_INCLUDEPATH} \

# ubn DEFINES
#
ubn_DEFINES += \
$${ucifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# ubn OBJECTIVE_HEADERS
#
#ubn_OBJECTIVE_HEADERS += \
#$${UCIFRA_SRC}/xos/app/console/ubn/main.hh \

# ubn OBJECTIVE_SOURCES
#
#ubn_OBJECTIVE_SOURCES += \
#$${UCIFRA_SRC}/xos/app/console/ubn/main.mm \

########################################################################
# ubn HEADERS
#
ubn_HEADERS += \
$${UCIFRA_SRC}/xos/app/console/ubn/main_opt.hpp \
$${UCIFRA_SRC}/xos/app/console/ubn/main.hpp \

# ubn SOURCES
#
ubn_SOURCES += \
$${UCIFRA_SRC}/xos/app/console/ubn/main_opt.cpp \
$${UCIFRA_SRC}/xos/app/console/ubn/main.cpp \

########################################################################
# ubn FRAMEWORKS
#
ubn_FRAMEWORKS += \
$${ucifra_FRAMEWORKS} \

# ubn LIBS
#
ubn_LIBS += \
$${ucifra_bn_LIBS} \

########################################################################
# NO Qt
QT -= gui core

