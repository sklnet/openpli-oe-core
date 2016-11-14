SRC_URI_sh4 = "${GITHUB_URI}/sklnet/openpli-enigma2.git;branch=${ENIGMA2_BRANCH}"

EXTRA_OECONF += " \
    ${@bb.utils.contains("MACHINE_TUNE", "sh4", "--enable-sh" , "", d)} \
"

