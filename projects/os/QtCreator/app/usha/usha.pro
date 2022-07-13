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
#   File: usha.pro
#
# Author: $author$
#   Date: 4/1/2022
#
# os specific QtCreator project .pro file for framework ucifra executable usha
########################################################################
#
# Debug: ucifra/build/os/QtCreator/Debug/bin/usha
# Release: ucifra/build/os/QtCreator/Release/bin/usha
# Profile: ucifra/build/os/QtCreator/Profile/bin/usha
#
include(../../../../../build/QtCreator/ucifra.pri)
include(../../../../QtCreator/ucifra.pri)
include(../../ucifra.pri)
include(../../../../QtCreator/app/usha/usha.pri)

TARGET = $${usha_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${usha_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${usha_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${usha_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${usha_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${usha_HEADERS} \
$${usha_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${usha_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${usha_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${usha_LIBS} \
$${FRAMEWORKS} \

########################################################################

