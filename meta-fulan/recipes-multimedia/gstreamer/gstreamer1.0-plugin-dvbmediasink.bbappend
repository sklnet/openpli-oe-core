FILESEXTRAPATHS_append := "${THISDIR}/files"

SRC_URI = "git://github.com/christophecvr/gstreamer1.0-plugin-multibox-dvbmediasink.git;protocol=git"

SRC_URI_append_sh4 = " \
    file://0001-dvbmediasink_sh4_fix.patch;patch=1 \
"

