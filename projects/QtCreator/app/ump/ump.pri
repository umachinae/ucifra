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
#   File: ump.pri
#
# Author: $author$
#   Date: 1/28/2022
#
# generic QtCreator project .pri file for framework ucifra executable ump
########################################################################

########################################################################
# ump

# ump TARGET
#
ump_TARGET = ump

# ump INCLUDEPATH
#
ump_INCLUDEPATH += \
$${ucifra_INCLUDEPATH} \

# ump DEFINES
#
ump_DEFINES += \
$${ucifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# ump OBJECTIVE_HEADERS
#
#ump_OBJECTIVE_HEADERS += \
#$${UCIFRA_SRC}/xos/app/console/ump/main.hh \

# ump OBJECTIVE_SOURCES
#
#ump_OBJECTIVE_SOURCES += \
#$${UCIFRA_SRC}/xos/app/console/ump/main.mm \

########################################################################
# ump HEADERS
#
ump_HEADERS += \
$${UCIFRA_SRC}/xos/app/console/ump/main_opt.hpp \
$${UCIFRA_SRC}/xos/app/console/ump/main.hpp \

# ump SOURCES
#
ump_SOURCES += \
$${UCIFRA_SRC}/xos/app/console/ump/main_opt.cpp \
$${UCIFRA_SRC}/xos/app/console/ump/main.cpp \

########################################################################
# ump FRAMEWORKS
#
ump_FRAMEWORKS += \
$${ucifra_FRAMEWORKS} \

# ump LIBS
#
ump_LIBS += \
$${ucifra_mp_LIBS} \

########################################################################
# NO Qt
QT -= gui core

