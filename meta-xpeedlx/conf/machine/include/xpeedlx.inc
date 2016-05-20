# We know about rtc
include conf/machine/include/build-extras.inc

BRAND_OEM = "ini"

GST_VERSION = "1.0"

MTD_KERNEL = "mtd2"
MTD_ROOTFS = "mtd0"

KERNEL_FILE = "kernel.bin"
ROOTFS_FILE = "rootfs.bin"

DVBPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS = "\
	xpeedlx-dvb-modules-${MACHINE} \
	"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS = "\
    kernel-module-cdfs \
    "

MACHINE_EXTRA_RRECOMMENDS = " \
    ${@base_contains("GST_VERSION", "1.0", "gstreamer1.0-plugin-dvbmediasink", "gst-plugin-dvbmediasink", d)} \
    "

include conf/machine/include/autoload-filesystems.inc

TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

GLIBC_EXTRA_OECONF = "--with-tls"
DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts"

PREFERRED_VERSION_nfs-utils ?= "1.2.8"

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "xpeedlx-blindscan-utils"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "xpeedlx-blindscan-utils"

KERNEL_IMAGETYPE = "vmlinux"
KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_CONSOLE = "ttyS0,115200n8"

IMAGE_FSTYPES ?= "ubi"

IMAGE_CMD_ubi_prepend = " \
    rm -rf ${IMAGE_ROOTFS}/boot/*; \
    rm -rf ${IMAGE_ROOTFS}/tmp/*; \
    "

IMAGE_CMD_ubi_append = "\
    mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
    cp ${DEPLOY_DIR_IMAGE}/${BOOTLOGO_FILENAME} ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${BOOTLOGO_FILENAME}; \
    ${@base_contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/cfe.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
    ${@base_contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/splash.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
    ${@base_contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/imageversion.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
    ${@base_contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/kernel.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
    ${@base_contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/rootfs.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
    ${@base_contains("MACHINE_FEATURES", "extrasplash", "cp ${DEPLOY_DIR_IMAGE}/finished.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
    mv ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.ubi ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${ROOTFS_FILE}; \
    gzip -f -9c ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
    echo ${IMAGE_VER_STRING} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
    cd ${DEPLOY_DIR_IMAGE}; \
    zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.ubi; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.ubifs; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.manifest; \
    rm -f ${DEPLOY_DIR_IMAGE}/.ubifs; \
    rm -f ${DEPLOY_DIR_IMAGE}/.manifest; \
    rm -rf ${IMAGEDIR}; \
    "

MACHINE_FEATURES += "3dtv alsa hdmicec switchoff wifi bootsplash omb feature1 feature2"

BOOTLOGO_FILENAME = "splash.bin"

require conf/machine/include/tune-mips32.inc

# add support for extra feeds
PACKAGE_ARCHS += " ${MACHINEBUILD}"
