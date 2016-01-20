FILESEXTRAPATHS_append := "${THISDIR}/files"

SRC_URI_append_sh4 = " \
    file://tuxtxtlib_sh4_fix.patch;patch=1 \
    "

