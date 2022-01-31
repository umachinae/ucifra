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
#   File: libump.pri
#
# Author: $author$
#   Date: 1/28/2022
#
# generic QtCreator project .pri file for framework ucifra static library libump
########################################################################

########################################################################
# libump
XOS_LIB_UMP_VERSION_BUILD_DATE = $$system(~/bin/utility/tdate)

# libump TARGET
#
libump_TARGET = ump
libump_TEMPLATE = lib
libump_CONFIG += staticlib

# libump INCLUDEPATH
#
libump_INCLUDEPATH += \
$${ucifra_INCLUDEPATH} \

# libump DEFINES
#
libump_DEFINES += \
$${ucifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_UMP_VERSION_BUILD_DATE=$${XOS_LIB_UMP_VERSION_BUILD_DATE} \

########################################################################
# libump OBJECTIVE_HEADERS
#
#libump_OBJECTIVE_HEADERS += \
#$${UCIFRA_SRC}/xos/lib/ump/version.hh \

# libump OBJECTIVE_SOURCES
#
#libump_OBJECTIVE_SOURCES += \
#$${UCIFRA_SRC}/xos/lib/ump/version.mm \

########################################################################
# libump HEADERS
#
libump_HEADERS += \
$${UCIFRA_SRC}/xos/lib/ump/version.hpp \

# libump SOURCES
#
libump_SOURCES += \
$${UMP_SRC}/extract-double.c \
$${UMP_SRC}/insert-double.c \
$${UMP_SRC}/memory.c \
$${UMP_SRC}/mp_bpl.c \
$${UMP_SRC}/mp_clz_tab.c \
$${UMP_SRC}/mp_set_fns.c \
$${UMP_SRC}/stack-alloc.c \
\
$${UCIFRA_SRC}/xos/lib/ump/version.cpp \

#$${UMP_SRC}/version.c -- included by $${UCIFRA_SRC}/xos/lib/ump/version.cpp

########################################################################

