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
#   File: libubn.pri
#
# Author: $author$
#   Date: 1/28/2022
#
# generic QtCreator project .pri file for framework ucifra static library libubn
########################################################################

########################################################################
# libubn
XOS_LIB_UBN_VERSION_BUILD_DATE = 1/28/2022 #$$system(~/bin/utility/tdate)

# libubn TARGET
#
libubn_TARGET = ubn
libubn_TEMPLATE = lib
libubn_CONFIG += staticlib

# libubn INCLUDEPATH
#
libubn_INCLUDEPATH += \
$${ucifra_INCLUDEPATH} \

# libubn DEFINES
#
libubn_DEFINES += \
$${ucifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_UBN_VERSION_BUILD_DATE=$${XOS_LIB_UBN_VERSION_BUILD_DATE} \

########################################################################
# libubn OBJECTIVE_HEADERS
#
#libubn_OBJECTIVE_HEADERS += \
#$${UCIFRA_SRC}/xos/lib/ubn/version.hh \

# libubn OBJECTIVE_SOURCES
#
#libubn_OBJECTIVE_SOURCES += \
#$${UCIFRA_SRC}/xos/lib/ubn/version.mm \

########################################################################
# libubn HEADERS
#
libubn_HEADERS += \
$${UBN_SRC}/bn_lsb.h \
$${UBN_SRC}/bn_msb.h \
\
$${UCIFRA_SRC}/xos/lib/ubn/version.hpp \

# libubn SOURCES
#
libubn_SOURCES += \
$${UBN_SRC}/bn_lsb.c \
$${UBN_SRC}/bn_msb.c \
\
$${UBN_SRC}/bn_add.c \
$${UBN_SRC}/bn_blind.c \
$${UBN_SRC}/bn_div.c \
$${UBN_SRC}/bn_exp.c \
$${UBN_SRC}/bn_gcd.c \
$${UBN_SRC}/bn_lib.c \
$${UBN_SRC}/bn_mod.c \
$${UBN_SRC}/bn_mont.c \
$${UBN_SRC}/bn_mpi.c \
$${UBN_SRC}/bn_mul.c \
$${UBN_SRC}/bn_mulw.c \
$${UBN_SRC}/bn_prime.c \
$${UBN_SRC}/bn_randm.c \
$${UBN_SRC}/bn_recp.c \
$${UBN_SRC}/bn_shift.c \
$${UBN_SRC}/bn_sqr.c \
$${UBN_SRC}/bn_sub.c \
$${UBN_SRC}/bn_word.c \
\
$${UCIFRA_SRC}/xos/lib/ubn/version.cpp \

########################################################################

