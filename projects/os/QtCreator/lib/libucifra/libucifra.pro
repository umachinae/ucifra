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
#   File: libucifra.pro
#
# Author: $author$
#   Date: 1/26/2022
#
# os specific QtCreator project .pro file for framework ucifra static library libucifra
########################################################################
#
# Debug: ucifra/build/os/QtCreator/Debug/lib/libucifra
# Release: ucifra/build/os/QtCreator/Release/lib/libucifra
# Profile: ucifra/build/os/QtCreator/Profile/lib/libucifra
#
include(../../../../../build/QtCreator/ucifra.pri)
include(../../../../QtCreator/ucifra.pri)
include(../../ucifra.pri)
include(../../../../QtCreator/lib/libucifra/libucifra.pri)

TARGET = $${libucifra_TARGET}
TEMPLATE = $${libucifra_TEMPLATE}
CONFIG += $${libucifra_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libucifra_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libucifra_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libucifra_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libucifra_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libucifra_HEADERS} \
$${libucifra_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libucifra_SOURCES} \

########################################################################

