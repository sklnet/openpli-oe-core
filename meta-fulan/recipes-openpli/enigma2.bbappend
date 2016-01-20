SRC_URI_sh4 = "${GITHUB_URI}/sklnet/openpli-enigma2.git;branch=${ENIGMA2_BRANCH}"

EXTRA_OECONF_append_sh4 = " \
    --enable-sh=yes \
"

