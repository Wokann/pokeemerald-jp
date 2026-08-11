# Installing the build environment

This project builds a byte-exact copy of the **Japanese** PokÃ©mon Emerald
ROM.  You need the original Japanese Emerald ROM itself (it is copyrighted
and therefore not shipped with the repository).

## Prerequisites

* Linux (native or [WSL2][wsl2]), macOS (with Xcode Command Line Tools), or
  a Unix-like environment
* `gcc`, `g++`, `make`, `git`, `cpp`
* `libpng-dev` (Debian/Ubuntu) or `libpng` (macOS Homebrew)
* an `arm-none-eabi` binutils toolchain (`gcc-arm-none-eabi` on
  Debian/Ubuntu, `arm-none-eabi-gcc` on macOS)

Debian/Ubuntu (including WSL):

	sudo apt install gcc g++ make git libpng-dev gcc-arm-none-eabi

macOS:

	brew install gcc make git libpng arm-none-eabi-gcc

[wsl2]: https://docs.microsoft.com/windows/wsl/wsl2-install

## One-shot setup

Place the Japanese Emerald ROM in the project root as `baserom_jp.gba`,
then run:

	sh setup.sh

`setup.sh` verifies the ROM checksum
(`d7cf8f156ba9c455d164e1ea780a6bf1945465c2`), builds the host tools
(`tools/gbagfx`, `tools/preproc`, `tools/gbafix`, etc.), links the system
`arm-none-eabi` binutils into `tools/binutils/bin`, clones
[pret/agbcc](https://github.com/pret/agbcc) to `tools/agbcc-src`, builds it,
and installs it to `tools/agbcc`.

If cloning agbcc fails (e.g. GitHub is unreachable), place an existing agbcc
checkout at `tools/agbcc-src` manually and re-run `sh setup.sh`.

## Building and verifying

	make -j$(nproc)

To check that the output is byte-identical to the original ROM:

	make compare

This runs `sha1sum -c rom_jp.sha1` against `pokeemerald_jp.gba`; it must
print `OK`.  `make compare` (and `make`) are the authoritative build-and-
verify flow and should be used to validate **every** change, not just a
rebuilt object or a single ROM range.

## Skipping already-installed parts

On an already-prepared checkout you only need the ROM and the system
toolchain.  Skip `setup.sh` entirely and build directly:

	make -j$(nproc)
	make compare

`setup.sh` itself is idempotent: steps it can skip are

* step 3 (`build_tools.sh`) - re-running it is harmless; each tool's
  `make` is incremental
* step 4 (binutils links) - skips links that already exist
* step 5 (agbcc) - skips building/cloning if `tools/agbcc/bin/agbcc`
  already exists

## Cleaning

	make clean

removes `build/`, the generated ROM, ELF, and map file.  It does not remove
`tools/agbcc`, `tools/agbcc-src`, or `tools/binutils`, so the environment
stays ready for the next build.

## Notes

* The ROM regions that are still raw data are `.incbin`'d directly from
  `baserom_jp.gba` at absolute offsets; there is no separate extraction
  step.
* The multiboot programs `data/mb_ereader.gba` and
  `data/mb_berry_fix.gba` are committed, following pokeemerald's layout.
* If you are here to contribute decompilation work, read
  [DECOMPILING.md](DECOMPILING.md) for the asm-to-C workflow and the
  standard verification procedure.
