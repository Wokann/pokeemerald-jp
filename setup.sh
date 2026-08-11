#!/bin/sh
# One-shot build environment setup for pokeemerald-jp.
#
#   sh setup.sh
#
# Prepares: host tools (build_tools.sh), arm-none-eabi binutils links,
# and a locally built agbcc (cloned to tools/agbcc-src, installed to
# tools/agbcc).  Requires a Japanese Emerald ROM named baserom_jp.gba in
# the project root.
set -e

ROOT=$(pwd)

echo "==> 1/5  Checking system tools"
MISSING=""
for t in gcc g++ make git cpp arm-none-eabi-as arm-none-eabi-ar arm-none-eabi-ld arm-none-eabi-objcopy; do
    if ! command -v "$t" >/dev/null 2>&1; then
        MISSING="$MISSING $t"
    fi
done
if [ -n "$MISSING" ]; then
    echo "Missing tools:$MISSING"
    echo
    echo "Debian/Ubuntu (including WSL):"
    echo "  sudo apt install gcc g++ make git libpng-dev gcc-arm-none-eabi"
    echo
    echo "macOS (Homebrew):"
    echo "  brew install gcc make git libpng arm-none-eabi-gcc"
    echo
    echo "Install the missing tools, then run: sh setup.sh"
    exit 1
fi
echo "    all required tools found"

echo "==> 2/5  Checking baserom_jp.gba"
if [ ! -f baserom_jp.gba ]; then
    echo "baserom_jp.gba not found. Place the Japanese Emerald ROM in the"
    echo "project root named baserom_jp.gba, then re-run: sh setup.sh"
    exit 1
fi
if ! printf 'd7cf8f156ba9c455d164e1ea780a6bf1945465c2  baserom_jp.gba\n' | sha1sum -c - >/dev/null 2>&1; then
    echo "baserom_jp.gba has the wrong SHA1 (expected"
    echo "d7cf8f156ba9c455d164e1ea780a6bf1945465c2)."
    exit 1
fi
echo "    baserom_jp.gba OK"

echo "==> 3/5  Building host tools"
sh build_tools.sh

echo "==> 4/5  Linking arm-none-eabi binutils"
mkdir -p tools/binutils/bin
for t in as ar ld objcopy nm objdump; do
    if [ ! -e "tools/binutils/bin/arm-none-eabi-$t" ] && command -v "arm-none-eabi-$t" >/dev/null 2>&1; then
        ln -sf "$(command -v arm-none-eabi-$t)" "tools/binutils/bin/arm-none-eabi-$t"
    fi
done
echo "    binutils linked"

echo "==> 5/5  Building and installing agbcc"
if [ ! -x tools/agbcc/bin/agbcc ]; then
    if [ ! -d tools/agbcc-src ]; then
        git clone https://github.com/pret/agbcc tools/agbcc-src
    fi
    cd tools/agbcc-src
    ./build.sh
    ./install.sh "$ROOT"
    cd "$ROOT"
    echo "    agbcc installed to tools/agbcc"
else
    echo "    agbcc already present"
fi

echo
echo "Environment ready. Build and verify with:"
echo "  make -j\$(nproc)"
echo "  make compare"
