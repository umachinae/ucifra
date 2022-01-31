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
#   File: umpn.pri
#
# Author: $author$
#   Date: 1/29/2022
#
# generic QtCreator project .pri file for framework ucifra executable umpn
########################################################################

########################################################################
# umpn

# umpn TARGET
#
umpn_TARGET = umpn

# umpn INCLUDEPATH
#
umpn_INCLUDEPATH += \
$${ucifra_INCLUDEPATH} \

# umpn DEFINES
#
umpn_DEFINES += \
$${ucifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# umpn OBJECTIVE_HEADERS
#
#umpn_OBJECTIVE_HEADERS += \
#$${UCIFRA_SRC}/xos/app/console/umpn/main.hh \

# umpn OBJECTIVE_SOURCES
#
#umpn_OBJECTIVE_SOURCES += \
#$${UCIFRA_SRC}/xos/app/console/umpn/main.mm \

########################################################################
# umpn HEADERS
#
umpn_HEADERS += \
$${UCIFRA_SRC}/xos/app/console/umpn/main_opt.hpp \
$${UCIFRA_SRC}/xos/app/console/umpn/main.hpp \

# umpn SOURCES
#
umpn_SOURCES += \
$${UCIFRA_SRC}/xos/app/console/umpn/main_opt.cpp \
$${UCIFRA_SRC}/xos/app/console/umpn/main.cpp \

########################################################################
# umpn FRAMEWORKS
#
umpn_FRAMEWORKS += \
$${ucifra_FRAMEWORKS} \

# umpn LIBS
#
umpn_LIBS += \
$${ucifra_mp_LIBS} \

########################################################################
# NO Qt
QT -= gui core

