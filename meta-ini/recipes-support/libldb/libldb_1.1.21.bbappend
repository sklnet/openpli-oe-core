FILESEXTRAPATHS_append := "${THISDIR}/files:"

SRC_URI_append_xpeedlx = " \
    file://ldb_old_kernel_fix.patch;patch=1 \
    "

