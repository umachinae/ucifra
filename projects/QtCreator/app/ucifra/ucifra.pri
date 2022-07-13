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
#   File: ucifra.pri
#
# Author: $author$
#   Date: 5/9/2022
#
# generic QtCreator project .pri file for framework ucifra executable ucifra
########################################################################

########################################################################
# ucifra

# ucifra_exe TARGET
#
ucifra_exe_TARGET = ucifra

# ucifra_exe INCLUDEPATH
#
ucifra_exe_INCLUDEPATH += \
$${ucifra_INCLUDEPATH} \

# ucifra_exe DEFINES
#
ucifra_exe_DEFINES += \
$${ucifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# ucifra_exe OBJECTIVE_HEADERS
#
#ucifra_exe_OBJECTIVE_HEADERS += \
#$${UCIFRA_SRC}/xos/app/console/ucifra/main.hh \

# ucifra_exe OBJECTIVE_SOURCES
#
#ucifra_exe_OBJECTIVE_SOURCES += \
#$${UCIFRA_SRC}/xos/app/console/ucifra/main.mm \

########################################################################
# ucifra_exe HEADERS
#
ucifra_exe_HEADERS += \
$${UCIFRA_SRC}/xos/app/console/ucifra/version/main_opt.hpp \
$${UCIFRA_SRC}/xos/app/console/ucifra/version/main.hpp \

# ucifra_exe SOURCES
#
ucifra_exe_SOURCES += \
$${UCIFRA_SRC}/xos/app/console/ucifra/version/main_opt.cpp \
$${UCIFRA_SRC}/xos/app/console/ucifra/version/main.cpp \

########################################################################
# ucifra_exe FRAMEWORKS
#
ucifra_exe_FRAMEWORKS += \
$${ucifra_FRAMEWORKS} \

# ucifra_exe LIBS
#
ucifra_exe_LIBS += \
$${ucifra_LIBS} \

########################################################################
# NO Qt
QT -= gui core

