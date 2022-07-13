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
#   File: ucifra.pri
#
# Author: $author$
#   Date: 3/31/2022
#
# os specific QtCreator project .pri file for framework ucifra
########################################################################
# Repository Depends: vmachinae
# Depends: ubn;ump;urostra;unadir;ufila;ucrono

UNAME = $$system(uname)

contains(UNAME,Darwin) {
UCIFRA_OS = macosx
} else {
contains(UNAME,Linux) {
UCIFRA_OS = linux
} else {
UCIFRA_OS = windows
} # contains(UNAME,Linux)
} # contains(UNAME,Darwin)

contains(BUILD_OS,UCIFRA_OS) {
UCIFRA_BUILD = $${UCIFRA_OS}
} else {
UCIFRA_BUILD = $${BUILD_OS}
} # contains(BUILD_OS,UCIFRA_OS)

contains(BUILD_CPP_VERSION,10) {
CONFIG += c++0x
} else {
contains(BUILD_CPP_VERSION,98|03|11|14|17) {
CONFIG += c++$${BUILD_CPP_VERSION}
} else {
} # contains(BUILD_CPP_VERSION,98|03|11|14|17)
} # contains(BUILD_CPP_VERSION,10)

contains(UCIFRA_OS,macosx) {
} else {
contains(UCIFRA_OS,linux) {
QMAKE_CXXFLAGS += -fpermissive
} else {
contains(UCIFRA_OS,windows) {
} else {
} # contains(UCIFRA_OS,windows)
} # contains(UCIFRA_OS,linux)
} # contains(UCIFRA_OS,macosx)

########################################################################
# ubn
UBN_THIRDPARTY_PKG_MAKE_BLD = $${UBN_THIRDPARTY_PKG}/build/$${UCIFRA_BUILD}/$${BUILD_CONFIG}
UBN_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${UBN_THIRDPARTY_PRJ}/build/$${UCIFRA_BUILD}/$${BUILD_CONFIG}
UBN_THIRDPARTY_PKG_BLD = $${UBN_THIRDPARTY_PKG}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UBN_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${UBN_THIRDPARTY_PRJ}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UBN_PKG_BLD = $${OTHER_BLD}/$${UBN_PKG}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UBN_PRJ_BLD = $${OTHER_BLD}/$${UBN_PRJ}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
#UBN_LIB = $${UBN_THIRDPARTY_PKG_MAKE_BLD}/lib
#UBN_LIB = $${UBN_THIRDPARTY_PRJ_MAKE_BLD}/lib
#UBN_LIB = $${UBN_THIRDPARTY_PKG_BLD}/lib
#UBN_LIB = $${UBN_THIRDPARTY_PRJ_BLD}/lib
#UBN_LIB = $${UBN_PKG_BLD}/lib
#UBN_LIB = $${UBN_PRJ_BLD}/lib
#UBN_LIB = $${UCIFRA_LIB}
UBN_LIB = $${UCIFRA_LIB}
UBN_LIB_NAME = u$${UBN_NAME}

# ubn LIBS
#
ubn_LIBS += \
-L$${UBN_LIB}/lib$${UBN_LIB_NAME} \
-l$${UBN_LIB_NAME} \


########################################################################
# ump
UMP_THIRDPARTY_PKG_MAKE_BLD = $${UMP_THIRDPARTY_PKG}/build/$${UCIFRA_BUILD}/$${BUILD_CONFIG}
UMP_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${UMP_THIRDPARTY_PRJ}/build/$${UCIFRA_BUILD}/$${BUILD_CONFIG}
UMP_THIRDPARTY_PKG_BLD = $${UMP_THIRDPARTY_PKG}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UMP_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${UMP_THIRDPARTY_PRJ}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UMP_PKG_BLD = $${OTHER_BLD}/$${UMP_PKG}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UMP_PRJ_BLD = $${OTHER_BLD}/$${UMP_PRJ}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
#UMP_LIB = $${UMP_THIRDPARTY_PKG_MAKE_BLD}/lib
#UMP_LIB = $${UMP_THIRDPARTY_PRJ_MAKE_BLD}/lib
#UMP_LIB = $${UMP_THIRDPARTY_PKG_BLD}/lib
#UMP_LIB = $${UMP_THIRDPARTY_PRJ_BLD}/lib
#UMP_LIB = $${UMP_PKG_BLD}/lib
#UMP_LIB = $${UMP_PRJ_BLD}/lib
#UMP_LIB = $${UCIFRA_LIB}
UMP_LIB = $${UCIFRA_LIB}
UMP_LIB_NAME = u$${UMP_NAME}

# ump LIBS
#
ump_LIBS += \
-L$${UMP_LIB}/lib$${UMP_LIB_NAME}z \
-l$${UMP_LIB_NAME}z \
-L$${UMP_LIB}/lib$${UMP_LIB_NAME}n \
-l$${UMP_LIB_NAME}n \
-L$${UMP_LIB}/lib$${UMP_LIB_NAME} \
-l$${UMP_LIB_NAME} \


########################################################################
# urostra
UROSTRA_THIRDPARTY_PKG_MAKE_BLD = $${UROSTRA_THIRDPARTY_PKG}/build/$${UCIFRA_BUILD}/$${BUILD_CONFIG}
UROSTRA_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${UROSTRA_THIRDPARTY_PRJ}/build/$${UCIFRA_BUILD}/$${BUILD_CONFIG}
UROSTRA_THIRDPARTY_PKG_BLD = $${UROSTRA_THIRDPARTY_PKG}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UROSTRA_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${UROSTRA_THIRDPARTY_PRJ}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UROSTRA_PKG_BLD = $${OTHER_BLD}/$${UROSTRA_PKG}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UROSTRA_PRJ_BLD = $${OTHER_BLD}/$${UROSTRA_PRJ}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
#UROSTRA_LIB = $${UROSTRA_THIRDPARTY_PKG_MAKE_BLD}/lib
#UROSTRA_LIB = $${UROSTRA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#UROSTRA_LIB = $${UROSTRA_THIRDPARTY_PKG_BLD}/lib
#UROSTRA_LIB = $${UROSTRA_THIRDPARTY_PRJ_BLD}/lib
UROSTRA_LIB = $${UROSTRA_PKG_BLD}/lib
#UROSTRA_LIB = $${UROSTRA_PRJ_BLD}/lib
#UROSTRA_LIB = $${UCIFRA_LIB}
UROSTRA_LIB_NAME = $${UROSTRA_NAME}

# urostra LIBS
#
urostra_LIBS += \
-L$${UROSTRA_LIB}/lib$${UROSTRA_LIB_NAME} \
-l$${UROSTRA_LIB_NAME} \


########################################################################
# unadir
UNADIR_THIRDPARTY_PKG_MAKE_BLD = $${UNADIR_THIRDPARTY_PKG}/build/$${UCIFRA_BUILD}/$${BUILD_CONFIG}
UNADIR_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${UNADIR_THIRDPARTY_PRJ}/build/$${UCIFRA_BUILD}/$${BUILD_CONFIG}
UNADIR_THIRDPARTY_PKG_BLD = $${UNADIR_THIRDPARTY_PKG}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UNADIR_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${UNADIR_THIRDPARTY_PRJ}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UNADIR_PKG_BLD = $${OTHER_BLD}/$${UNADIR_PKG}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UNADIR_PRJ_BLD = $${OTHER_BLD}/$${UNADIR_PRJ}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
#UNADIR_LIB = $${UNADIR_THIRDPARTY_PKG_MAKE_BLD}/lib
#UNADIR_LIB = $${UNADIR_THIRDPARTY_PRJ_MAKE_BLD}/lib
#UNADIR_LIB = $${UNADIR_THIRDPARTY_PKG_BLD}/lib
#UNADIR_LIB = $${UNADIR_THIRDPARTY_PRJ_BLD}/lib
UNADIR_LIB = $${UNADIR_PKG_BLD}/lib
#UNADIR_LIB = $${UNADIR_PRJ_BLD}/lib
#UNADIR_LIB = $${UCIFRA_LIB}
UNADIR_LIB_NAME = $${UNADIR_NAME}

# unadir LIBS
#
unadir_LIBS += \
-L$${UNADIR_LIB}/lib$${UNADIR_LIB_NAME} \
-l$${UNADIR_LIB_NAME} \


########################################################################
# ufila
UFILA_THIRDPARTY_PKG_MAKE_BLD = $${UFILA_THIRDPARTY_PKG}/build/$${UCIFRA_BUILD}/$${BUILD_CONFIG}
UFILA_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${UFILA_THIRDPARTY_PRJ}/build/$${UCIFRA_BUILD}/$${BUILD_CONFIG}
UFILA_THIRDPARTY_PKG_BLD = $${UFILA_THIRDPARTY_PKG}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UFILA_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${UFILA_THIRDPARTY_PRJ}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UFILA_PKG_BLD = $${OTHER_BLD}/$${UFILA_PKG}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UFILA_PRJ_BLD = $${OTHER_BLD}/$${UFILA_PRJ}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
#UFILA_LIB = $${UFILA_THIRDPARTY_PKG_MAKE_BLD}/lib
#UFILA_LIB = $${UFILA_THIRDPARTY_PRJ_MAKE_BLD}/lib
#UFILA_LIB = $${UFILA_THIRDPARTY_PKG_BLD}/lib
#UFILA_LIB = $${UFILA_THIRDPARTY_PRJ_BLD}/lib
UFILA_LIB = $${UFILA_PKG_BLD}/lib
#UFILA_LIB = $${UFILA_PRJ_BLD}/lib
#UFILA_LIB = $${UCIFRA_LIB}
UFILA_LIB_NAME = $${UFILA_NAME}

# ufila LIBS
#
ufila_LIBS += \
-L$${UFILA_LIB}/lib$${UFILA_LIB_NAME} \
-l$${UFILA_LIB_NAME} \


########################################################################
# ucrono
UCRONO_THIRDPARTY_PKG_MAKE_BLD = $${UCRONO_THIRDPARTY_PKG}/build/$${UCIFRA_BUILD}/$${BUILD_CONFIG}
UCRONO_THIRDPARTY_PRJ_MAKE_BLD = $${OTHER_BLD}/$${UCRONO_THIRDPARTY_PRJ}/build/$${UCIFRA_BUILD}/$${BUILD_CONFIG}
UCRONO_THIRDPARTY_PKG_BLD = $${UCRONO_THIRDPARTY_PKG}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UCRONO_THIRDPARTY_PRJ_BLD = $${OTHER_BLD}/$${UCRONO_THIRDPARTY_PRJ}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UCRONO_PKG_BLD = $${OTHER_BLD}/$${UCRONO_PKG}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
UCRONO_PRJ_BLD = $${OTHER_BLD}/$${UCRONO_PRJ}/build/$${UCIFRA_BUILD}/QtCreator/$${BUILD_CONFIG}
#UCRONO_LIB = $${UCRONO_THIRDPARTY_PKG_MAKE_BLD}/lib
#UCRONO_LIB = $${UCRONO_THIRDPARTY_PRJ_MAKE_BLD}/lib
#UCRONO_LIB = $${UCRONO_THIRDPARTY_PKG_BLD}/lib
#UCRONO_LIB = $${UCRONO_THIRDPARTY_PRJ_BLD}/lib
UCRONO_LIB = $${UCRONO_PKG_BLD}/lib
#UCRONO_LIB = $${UCRONO_PRJ_BLD}/lib
#UCRONO_LIB = $${UCIFRA_LIB}
UCRONO_LIB_NAME = $${UCRONO_NAME}

# ucrono LIBS
#
ucrono_LIBS += \
-L$${UCRONO_LIB}/lib$${UCRONO_LIB_NAME} \
-l$${UCRONO_LIB_NAME} \

########################################################################
# ucifra

# ucifra INCLUDEPATH
#
ucifra_INCLUDEPATH += \

# ucifra DEFINES
#
ucifra_DEFINES += \

# ucifra os LIBS
#
contains(UCIFRA_OS,macosx|linux) {
ucifra_os_LIBS += \
-lpthread \
-ldl
} else {
} # contains(UCIFRA_OS,macosx|linux)

contains(UCIFRA_OS,linux) {
ucifra_os_LIBS += \
-lrt
} else {
} # contains(UCIFRA_OS,linux)

# ucifra base LIBS
#
ucifra_base_LIBS += \
$${ucrono_LIBS} \
$${ufila_LIBS} \
$${unadir_LIBS} \
$${urostra_LIBS} \

# ucifra bnmp LIBS
#
ucifra_bnmp_LIBS += \
$${ump_LIBS} \
$${ubn_LIBS} \

# ucifra rsa LIBS
#
ucifra_rsa_LIBS += \
$${ucifra_base_LIBS} \
$${ucifra_bnmp_LIBS} \
$${build_ucifra_LIBS} \
$${ucifra_os_LIBS} \

# ucifra LIBS
#
ucifra_LIBS += \
$${ucifra_base_LIBS} \
$${build_ucifra_LIBS} \
$${ucifra_os_LIBS} \
