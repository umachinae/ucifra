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
#   File: libump.pro
#
# Author: $author$
#   Date: 1/28/2022
#
# os specific QtCreator project .pro file for framework ucifra static library libump
########################################################################
#
# Debug: ucifra/build/os/QtCreator/Debug/lib/libump
# Release: ucifra/build/os/QtCreator/Release/lib/libump
# Profile: ucifra/build/os/QtCreator/Profile/lib/libump
#
include(../../../../../build/QtCreator/ucifra.pri)
include(../../../../QtCreator/ucifra.pri)
include(../../ucifra.pri)
include(../../../../QtCreator/lib/libump/libump.pri)

TARGET = $${libump_TARGET}
TEMPLATE = $${libump_TEMPLATE}
CONFIG += $${libump_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libump_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libump_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libump_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libump_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libump_HEADERS} \
$${libump_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libump_SOURCES} \

########################################################################

