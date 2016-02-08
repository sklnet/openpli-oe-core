FILESEXTRAPATHS_append := "${THISDIR}/files:"

SRC_URI_append_xpeedlx = " \
    file://samba_old_kernel_fix.patch;patch=1 \
    "

