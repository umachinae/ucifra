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
#   File: usea.pro
#
# Author: $author$
#   Date: 2/21/2022
#
# os specific QtCreator project .pro file for framework ucifra executable usea
########################################################################
#
# Debug: ucifra/build/os/QtCreator/Debug/bin/usea
# Release: ucifra/build/os/QtCreator/Release/bin/usea
# Profile: ucifra/build/os/QtCreator/Profile/bin/usea
#
include(../../../../../build/QtCreator/ucifra.pri)
include(../../../../QtCreator/ucifra.pri)
include(../../ucifra.pri)
include(../../../../QtCreator/app/usea/usea.pri)

TARGET = $${usea_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${usea_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${usea_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${usea_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${usea_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${usea_HEADERS} \
$${usea_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${usea_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${usea_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${usea_LIBS} \
$${FRAMEWORKS} \

########################################################################

