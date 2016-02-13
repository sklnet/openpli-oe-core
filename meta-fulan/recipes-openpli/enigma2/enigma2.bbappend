SRC_URI_sh4 = "${GITHUB_URI}/sklnet/openpli-enigma2.git;branch=${ENIGMA2_BRANCH}"

DEPENDS += " \
    ${@base_contains("MACHINE_FEATURES", "eplayer3", "libeplayer3" , "", d)} \
"

RDEPENDS_${PN} += " \
    ${@base_contains("MACHINE_FEATURES", "eplayer3", "libeplayer3" , "", d)} \
"

EXTRA_OECONF += " \
    ${@base_contains("TARGET_ARCH", "sh4", "--with-stmfb=yes " , "", d)} \
    ${@base_contains("MACHINE_FEATURES", "eplayer3", "--enable-libeplayer3=yes" , "", d)} \
"

