SRC_URI_sh4 = "${GITHUB_URI}/sklnet/openpli-enigma2.git;branch=${ENIGMA2_BRANCH}"

DEPENDS += " \
    ${@base_contains("MACHINE_FEATURES", "eplayer3", "libeplayer3" , "", d)} \
"

RDEPENDS_${PN} += " \
    ${@base_contains("MACHINE_FEATURES", "eplayer3", "libeplayer3" , "", d)} \
"

EXTRA_OECONF += " \
    ${@base_contains("MACHINE_FEATURES", "eplayer3", "--with-libeplayer3=yes" , "", d)} \
"

EXTRA_OECONF += " \
    ${@base_contains("MACHINE_TUNE", "sh4", "--enable-sh" , "", d)} \
"

