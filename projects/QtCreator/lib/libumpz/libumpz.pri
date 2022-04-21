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
#   File: libumpz.pri
#
# Author: $author$
#   Date: 1/28/2022
#
# generic QtCreator project .pri file for framework ucifra static library libumpz
########################################################################

########################################################################
# libumpz
XOS_LIB_UMPZ_VERSION_BUILD_DATE = 1/28/2022 #$$system(~/bin/utility/tdate)

# libumpz TARGET
#
libumpz_TARGET = umpz
libumpz_TEMPLATE = lib
libumpz_CONFIG += staticlib

# libumpz INCLUDEPATH
#
libumpz_INCLUDEPATH += \
$${ucifra_INCLUDEPATH} \

# libumpz DEFINES
#
libumpz_DEFINES += \
$${ucifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_UMPZ_VERSION_BUILD_DATE=$${XOS_LIB_UMPZ_VERSION_BUILD_DATE} \

########################################################################
# libumpz OBJECTIVE_HEADERS
#
#libumpz_OBJECTIVE_HEADERS += \
#$${UCIFRA_SRC}/xos/lib/umpz/version.hh \

# libumpz OBJECTIVE_SOURCES
#
#libumpz_OBJECTIVE_SOURCES += \
#$${UCIFRA_SRC}/xos/lib/umpz/version.mm \

########################################################################
# libumpz HEADERS
#
libumpz_HEADERS += \
$${UCIFRA_SRC}/xos/lib/umpz/version.hpp \

# libumpz SOURCES
#
libumpz_SOURCES += \
$${UMP_SRC}/mpz/abs.c \
$${UMP_SRC}/mpz/add.c \
$${UMP_SRC}/mpz/add_ui.c \
$${UMP_SRC}/mpz/and.c \
$${UMP_SRC}/mpz/array_init.c \
$${UMP_SRC}/mpz/cdiv_q.c \
$${UMP_SRC}/mpz/cdiv_q_ui.c \
$${UMP_SRC}/mpz/cdiv_qr.c \
$${UMP_SRC}/mpz/cdiv_qr_ui.c \
$${UMP_SRC}/mpz/cdiv_r.c \
$${UMP_SRC}/mpz/cdiv_r_ui.c \
$${UMP_SRC}/mpz/cdiv_ui.c \
$${UMP_SRC}/mpz/clear.c \
$${UMP_SRC}/mpz/clrbit.c \
$${UMP_SRC}/mpz/cmp.c \
$${UMP_SRC}/mpz/cmp_si.c \
$${UMP_SRC}/mpz/cmp_ui.c \
$${UMP_SRC}/mpz/com.c \
$${UMP_SRC}/mpz/divexact.c \
$${UMP_SRC}/mpz/fac_ui.c \
$${UMP_SRC}/mpz/fdiv_q.c \
$${UMP_SRC}/mpz/fdiv_q_2exp.c \
$${UMP_SRC}/mpz/fdiv_q_ui.c \
$${UMP_SRC}/mpz/fdiv_qr.c \
$${UMP_SRC}/mpz/fdiv_qr_ui.c \
$${UMP_SRC}/mpz/fdiv_r.c \
$${UMP_SRC}/mpz/fdiv_r_2exp.c \
$${UMP_SRC}/mpz/fdiv_r_ui.c \
$${UMP_SRC}/mpz/fdiv_ui.c \
$${UMP_SRC}/mpz/gcd.c \
$${UMP_SRC}/mpz/gcd_ui.c \
$${UMP_SRC}/mpz/gcdext.c \
$${UMP_SRC}/mpz/get_d.c \
$${UMP_SRC}/mpz/get_si.c \
$${UMP_SRC}/mpz/get_str.c \
$${UMP_SRC}/mpz/get_ui.c \
$${UMP_SRC}/mpz/getbit.c \
$${UMP_SRC}/mpz/getlimbn.c \
$${UMP_SRC}/mpz/hamdist.c \
$${UMP_SRC}/mpz/init.c \
$${UMP_SRC}/mpz/inp_raw.c \
$${UMP_SRC}/mpz/inp_str.c \
$${UMP_SRC}/mpz/invert.c \
$${UMP_SRC}/mpz/ior.c \
$${UMP_SRC}/mpz/iset.c \
$${UMP_SRC}/mpz/iset_d.c \
$${UMP_SRC}/mpz/iset_si.c \
$${UMP_SRC}/mpz/iset_str.c \
$${UMP_SRC}/mpz/iset_ui.c \
$${UMP_SRC}/mpz/jacobi.c \
$${UMP_SRC}/mpz/legendre.c \
$${UMP_SRC}/mpz/mod.c \
$${UMP_SRC}/mpz/mod_inverse.c \
$${UMP_SRC}/mpz_lsb.c \
$${UMP_SRC}/mpz_msb.c \
$${UMP_SRC}/mpz/mul.c \
$${UMP_SRC}/mpz/mul_2exp.c \
$${UMP_SRC}/mpz/mul_ui.c \
$${UMP_SRC}/mpz/neg.c \
$${UMP_SRC}/mpz/out_raw.c \
$${UMP_SRC}/mpz/out_str.c \
$${UMP_SRC}/mpz/perfsqr.c \
$${UMP_SRC}/mpz/popcount.c \
$${UMP_SRC}/mpz/pow_ui.c \
$${UMP_SRC}/mpz/powm.c \
$${UMP_SRC}/mpz/powm_ui.c \
$${UMP_SRC}/mpz/pprime_p.c \
$${UMP_SRC}/mpz/random.c \
$${UMP_SRC}/mpz/random2.c \
$${UMP_SRC}/mpz/realloc.c \
$${UMP_SRC}/mpz/scan0.c \
$${UMP_SRC}/mpz/scan1.c \
$${UMP_SRC}/mpz/set.c \
$${UMP_SRC}/mpz/set_d.c \
$${UMP_SRC}/mpz/set_f.c \
$${UMP_SRC}/mpz/set_q.c \
$${UMP_SRC}/mpz/set_si.c \
$${UMP_SRC}/mpz/set_str.c \
$${UMP_SRC}/mpz/set_ui.c \
$${UMP_SRC}/mpz/setbit.c \
$${UMP_SRC}/mpz/size.c \
$${UMP_SRC}/mpz/sizeinbase.c \
$${UMP_SRC}/mpz/sqrt.c \
$${UMP_SRC}/mpz/sqrtrem.c \
$${UMP_SRC}/mpz/sub.c \
$${UMP_SRC}/mpz/sub_ui.c \
$${UMP_SRC}/mpz/tdiv_q.c \
$${UMP_SRC}/mpz/tdiv_q_2exp.c \
$${UMP_SRC}/mpz/tdiv_q_ui.c \
$${UMP_SRC}/mpz/tdiv_qr.c \
$${UMP_SRC}/mpz/tdiv_qr_ui.c \
$${UMP_SRC}/mpz/tdiv_r.c \
$${UMP_SRC}/mpz/tdiv_r_2exp.c \
$${UMP_SRC}/mpz/tdiv_r_ui.c \
$${UMP_SRC}/mpz/ui_pow_ui.c \
\
$${UCIFRA_SRC}/xos/lib/umpz/version.cpp \

########################################################################

