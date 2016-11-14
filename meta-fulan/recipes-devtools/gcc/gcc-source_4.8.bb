require gcc-${PV}.inc
require gcc-source.inc

SRC_URI_append = " \
    file://fix-build-with-gcc-6.patch \
"

SRC_URI_append_sh4 = " \
    file://gcc-4.8.4-stm-150128.patch \
"

