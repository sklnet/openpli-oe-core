FILESEXTRAPATHS_prepend := "${THISDIR}/${P}:"

SRC_URI_append_sh4= " \
    file://udev-builtin-input_id.patch \
"
