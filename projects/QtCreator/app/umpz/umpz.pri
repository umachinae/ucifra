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
#   File: umpz.pri
#
# Author: $author$
#   Date: 1/29/2022
#
# generic QtCreator project .pri file for framework ucifra executable umpz
########################################################################

########################################################################
# umpz

# umpz TARGET
#
umpz_TARGET = umpz

# umpz INCLUDEPATH
#
umpz_INCLUDEPATH += \
$${ucifra_INCLUDEPATH} \

# umpz DEFINES
#
umpz_DEFINES += \
$${ucifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# umpz OBJECTIVE_HEADERS
#
#umpz_OBJECTIVE_HEADERS += \
#$${UCIFRA_SRC}/xos/app/console/umpz/main.hh \

# umpz OBJECTIVE_SOURCES
#
#umpz_OBJECTIVE_SOURCES += \
#$${UCIFRA_SRC}/xos/app/console/umpz/main.mm \

########################################################################
# umpz HEADERS
#
umpz_HEADERS += \
$${UCIFRA_SRC}/xos/app/console/umpz/main_opt.hpp \
$${UCIFRA_SRC}/xos/app/console/umpz/main.hpp \

# umpz SOURCES
#
umpz_SOURCES += \
$${UCIFRA_SRC}/xos/app/console/umpz/main_opt.cpp \
$${UCIFRA_SRC}/xos/app/console/umpz/main.cpp \

########################################################################
# umpz FRAMEWORKS
#
umpz_FRAMEWORKS += \
$${ucifra_FRAMEWORKS} \

# umpz LIBS
#
umpz_LIBS += \
$${ucifra_mp_LIBS} \

########################################################################
# NO Qt
QT -= gui core

