FILESEXTRAPATHS_append := "${THISDIR}/files:"

SRC_URI_append_sh4 = " \
    file://tdb_old_kernel_fix.patch;patch=1 \
    "

