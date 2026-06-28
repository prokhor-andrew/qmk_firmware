#!/usr/bin/env bash
# Prerequisites: qmk CLI must be installed — brew install qmk/qmk/qmk
set -euo pipefail

ZSA_FORK="https://github.com/zsa/qmk_firmware.git"
QMK_HOME="${QMK_HOME:-$HOME/Projects/firmware}"

if [[ ! -d "$QMK_HOME" ]]; then
  echo "Cloning ZSA QMK fork to $QMK_HOME ..."
  git clone --depth 1 --recurse-submodules "$ZSA_FORK" "$QMK_HOME"
fi

QMK_HOME="$QMK_HOME" qmk compile -kb zsa/moonlander/revb -km zsa_moonlander_the-layout_source
