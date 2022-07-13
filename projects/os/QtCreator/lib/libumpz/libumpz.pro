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
#   File: libumpz.pro
#
# Author: $author$
#   Date: 3/31/2022
#
# os specific QtCreator project .pro file for framework ucifra static library libumpz
########################################################################
#
# Debug: ucifra/build/os/QtCreator/Debug/lib/libumpz
# Release: ucifra/build/os/QtCreator/Release/lib/libumpz
# Profile: ucifra/build/os/QtCreator/Profile/lib/libumpz
#
include(../../../../../build/QtCreator/ucifra.pri)
include(../../../../QtCreator/ucifra.pri)
include(../../ucifra.pri)
include(../../../../QtCreator/lib/libumpz/libumpz.pri)

TARGET = $${libumpz_TARGET}
TEMPLATE = $${libumpz_TEMPLATE}
CONFIG += $${libumpz_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libumpz_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libumpz_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libumpz_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libumpz_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libumpz_HEADERS} \
$${libumpz_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libumpz_SOURCES} \

########################################################################

