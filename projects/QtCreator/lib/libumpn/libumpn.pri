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
#   File: libumpn.pri
#
# Author: $author$
#   Date: 1/28/2022
#
# generic QtCreator project .pri file for framework ucifra static library libumpn
########################################################################

########################################################################
# libumpn
XOS_LIB_UMPN_VERSION_BUILD_DATE = 1/28/2022 #$$system(~/bin/utility/tdate)

# libumpn TARGET
#
libumpn_TARGET = umpn
libumpn_TEMPLATE = lib
libumpn_CONFIG += staticlib

# libumpn INCLUDEPATH
#
libumpn_INCLUDEPATH += \
$${ucifra_INCLUDEPATH} \

# libumpn DEFINES
#
libumpn_DEFINES += \
$${ucifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_UMPN_VERSION_BUILD_DATE=$${XOS_LIB_UMPN_VERSION_BUILD_DATE} \

########################################################################
# libumpn OBJECTIVE_HEADERS
#
#libumpn_OBJECTIVE_HEADERS += \
#$${UCIFRA_SRC}/xos/lib/umpn/version.hh \

# libumpn OBJECTIVE_SOURCES
#
#libumpn_OBJECTIVE_SOURCES += \
#$${UCIFRA_SRC}/xos/lib/umpn/version.mm \

########################################################################
# libumpn HEADERS
#
libumpn_HEADERS += \
$${UCIFRA_SRC}/xos/lib/umpn/version.hpp \

# libumpn SOURCES
#
libumpn_SOURCES += \
$${UMP_SRC}/mpn/generic/add_n.c \
$${UMP_SRC}/mpn/generic/addmul_1.c \
$${UMP_SRC}/mpn/generic/bdivmod.c \
$${UMP_SRC}/mpn/generic/cmp.c \
$${UMP_SRC}/mpn/generic/divmod_1.c \
$${UMP_SRC}/mpn/generic/divrem.c \
$${UMP_SRC}/mpn/generic/divrem_1.c \
$${UMP_SRC}/mpn/generic/dump.c \
$${UMP_SRC}/mpn/generic/gcd.c \
$${UMP_SRC}/mpn/generic/gcd_1.c \
$${UMP_SRC}/mpn/generic/gcdext.c \
$${UMP_SRC}/mpn/generic/get_str.c \
$${UMP_SRC}/mpn/generic/hamdist.c \
$${UMP_SRC}/mpn/generic/inlines.c \
$${UMP_SRC}/mpn/generic/lshift.c \
$${UMP_SRC}/mpn/generic/mod_1.c \
$${UMP_SRC}/mpn/mp_bases.c \
$${UMP_SRC}/mpn/generic/mul.c \
$${UMP_SRC}/mpn/generic/mul_1.c \
$${UMP_SRC}/mpn/generic/mul_n.c \
$${UMP_SRC}/mpn/generic/perfsqr.c \
$${UMP_SRC}/mpn/generic/popcount.c \
$${UMP_SRC}/mpn/generic/pre_mod_1.c \
$${UMP_SRC}/mpn/generic/random2.c \
$${UMP_SRC}/mpn/generic/rshift.c \
$${UMP_SRC}/mpn/generic/scan0.c \
$${UMP_SRC}/mpn/generic/scan1.c \
$${UMP_SRC}/mpn/generic/set_str.c \
$${UMP_SRC}/mpn/generic/sqrtrem.c \
$${UMP_SRC}/mpn/generic/sub_n.c \
$${UMP_SRC}/mpn/generic/submul_1.c \
$${UMP_SRC}/mpn/generic/udiv_w_sdiv.c \
\
$${UCIFRA_SRC}/xos/lib/umpn/version.cpp \

########################################################################

