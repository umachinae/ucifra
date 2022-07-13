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
#   File: ucifra.pro
#
# Author: $author$
#   Date: 3/31/2022
#
# os specific QtCreator project .pro file for framework ucifra executable ucifra
########################################################################
#
# Debug: ucifra/build/os/QtCreator/Debug/bin/ucifra
# Release: ucifra/build/os/QtCreator/Release/bin/ucifra
# Profile: ucifra/build/os/QtCreator/Profile/bin/ucifra
#
include(../../../../../build/QtCreator/ucifra.pri)
include(../../../../QtCreator/ucifra.pri)
include(../../ucifra.pri)
include(../../../../QtCreator/app/ucifra/ucifra.pri)

TARGET = $${ucifra_exe_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${ucifra_exe_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${ucifra_exe_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${ucifra_exe_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${ucifra_exe_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${ucifra_exe_HEADERS} \
$${ucifra_exe_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${ucifra_exe_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${ucifra_exe_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${ucifra_exe_LIBS} \
$${FRAMEWORKS} \

########################################################################

