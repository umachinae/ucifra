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
#   File: umpn.pro
#
# Author: $author$
#   Date: 1/29/2022
#
# os specific QtCreator project .pro file for framework ucifra executable umpn
########################################################################
#
# Debug: ucifra/build/os/QtCreator/Debug/bin/umpn
# Release: ucifra/build/os/QtCreator/Release/bin/umpn
# Profile: ucifra/build/os/QtCreator/Profile/bin/umpn
#
include(../../../../../build/QtCreator/ucifra.pri)
include(../../../../QtCreator/ucifra.pri)
include(../../ucifra.pri)
include(../../../../QtCreator/app/umpn/umpn.pri)

TARGET = $${umpn_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${umpn_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${umpn_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${umpn_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${umpn_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${umpn_HEADERS} \
$${umpn_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${umpn_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${umpn_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${umpn_LIBS} \
$${FRAMEWORKS} \

########################################################################

