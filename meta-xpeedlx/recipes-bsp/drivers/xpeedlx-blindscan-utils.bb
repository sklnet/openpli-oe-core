SUMMARY = "Utilities for transponder & dvb-s blindscan"
SECTION = "base"
PRIORITY = "optional"
RDEPENDS_${PN} = "ncurses"

PACKAGE_ARCH = "${MACHINE_ARCH}"

LICENSE = "CLOSED"
require conf/license/license-close.inc

PACKAGES = "xpeedlx-blindscan-dvbs-utils xpeedlx-blindscan-dvbs-utils-dbg xpeedlx-blindscan-dvbc-utils xpeedlx-blindscan-dvbc-utils-dbg"

PROVIDES += "virtual/blindscan-dvbs virtual/blindscan-dvbc"
RPROVIDES_xpeedlx-blindscan-dvbs-utils += "virtual/blindscan-dvbs"
RPROVIDES_xpeedlx-blindscan-dvbc-utils += "virtual/blindscan-dvbc"

SRC_URI = "file://tda1002x file://ini_blindscan"

PV = "2.1"
PR = "r3"

S = "${WORKDIR}/"

FILES_xpeedlx-blindscan-dvbs-utils = "${bindir}/*_blindscan"
FILES_xpeedlx-blindscan-dvbc-utils = "${bindir}/tda1002x"
FILES_xpeedlx-blindscan-dvbs-utils-dbg = "${bindir}/.debug/*_blindscan"
FILES_xpeedlx-blindscan-dvbc-utils-dbg = "${bindir}/.debug/tda1002x"

do_install() {
    install -d ${D}/${bindir}/
    install -m 0755 "${S}/tda1002x" "${D}/${bindir}"
    install -m 0755 "${S}/ini_blindscan" "${D}/${bindir}"
}
