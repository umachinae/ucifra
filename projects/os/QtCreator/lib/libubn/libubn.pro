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
#   File: libubn.pro
#
# Author: $author$
#   Date: 3/31/2022
#
# os specific QtCreator project .pro file for framework ucifra static library libubn
########################################################################
#
# Debug: ucifra/build/os/QtCreator/Debug/lib/libubn
# Release: ucifra/build/os/QtCreator/Release/lib/libubn
# Profile: ucifra/build/os/QtCreator/Profile/lib/libubn
#
include(../../../../../build/QtCreator/ucifra.pri)
include(../../../../QtCreator/ucifra.pri)
include(../../ucifra.pri)
include(../../../../QtCreator/lib/libubn/libubn.pri)

TARGET = $${libubn_TARGET}
TEMPLATE = $${libubn_TEMPLATE}
CONFIG += $${libubn_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libubn_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libubn_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libubn_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libubn_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libubn_HEADERS} \
$${libubn_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libubn_SOURCES} \

########################################################################

