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
#   File: uecc.pro
#
# Author: $author$
#   Date: 7/6/2022
#
# os specific QtCreator project .pro file for framework ucifra executable uecc
########################################################################
#
# Debug: ucifra/build/os/QtCreator/Debug/bin/uecc
# Release: ucifra/build/os/QtCreator/Release/bin/uecc
# Profile: ucifra/build/os/QtCreator/Profile/bin/uecc
#
include(../../../../../build/QtCreator/ucifra.pri)
include(../../../../QtCreator/ucifra.pri)
include(../../ucifra.pri)
include(../../../../QtCreator/app/uecc/uecc.pri)

TARGET = $${uecc_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${uecc_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${uecc_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${uecc_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${uecc_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${uecc_HEADERS} \
$${uecc_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${uecc_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${uecc_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${uecc_LIBS} \
$${FRAMEWORKS} \

########################################################################

