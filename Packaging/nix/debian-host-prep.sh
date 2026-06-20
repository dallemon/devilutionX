#!/usr/bin/env bash
set -euo pipefail
set -x

PACKAGES=(
  build-essential
  cmake
  gettext
  git
  g++
  libbenchmark-dev
  libbz2-dev
  libfmt-dev
  libgmock-dev
  libgtest-dev
  libpng-dev
  libsdl2-dev
  libsdl2-image-dev
  libsodium-dev
  libspeechd-dev
  pkg-config
  poedit
  rpm
  smpq
)

if (( $# < 1 )) || [[ "$1" != --no-gcc ]]; then
  PACKAGES+=(g++)
fi

sudo apt-get update
sudo apt-get install -y "${PACKAGES[@]}"

