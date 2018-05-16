require gstreamer1.0-libav.inc
include gstreamer1.0-common.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=b234ee4d69f5fce4486a80fdaf4a4263 \
                    file://COPYING.LIB;md5=6762ed442b3822387a51c92d928ead0d \
                    file://ext/libav/gstav.h;beginline=1;endline=18;md5=a752c35267d8276fd9ca3db6994fca9c \
                    file://gst-libs/ext/libav/COPYING.GPLv2;md5=b234ee4d69f5fce4486a80fdaf4a4263 \
                    file://gst-libs/ext/libav/COPYING.GPLv3;md5=d32239bcb673463ab874e80d47fae504 \
                    file://gst-libs/ext/libav/COPYING.LGPLv2.1;md5=bd7a443320af8c812e4c18d1b79df004 \
                    file://gst-libs/ext/libav/COPYING.LGPLv3;md5=e6a600fd5e1d9cbde2d983680233ad02"

# To build using the system libav/ffmpeg, append "libav" to PACKAGECONFIG
# and remove the ffmpeg sources from SRC_URI below. However, first note the
# warnings in gstreamer1.0-libav.inc
SRC_URI = " \
	git://anongit.freedesktop.org/gstreamer/gst-libav;branch=${GST_BRANCH};name=base \
	git://github.com/FFmpeg/FFmpeg.git;destsuffix=git/gst-libs/ext/libav;branch=release/3.4;name=ffmpeg \
	file://0001-Disable-yasm-for-libav-when-disable-yasm.patch \
	file://workaround-to-build-gst-libav-for-i586-with-gcc.patch \
	file://mips64_cpu_detection.patch \
	file://0001-configure-check-for-armv7ve-variant.patch \
"

