# Decompilation workflow

This document is the standard procedure for converting `asm/` to `src/` in
this repository.  The goal is a JP project whose architecture, variable
names, compile rules, and directory layout mirror
[pokeemerald](https://github.com/pret/pokeemerald) as closely as possible,
so that shared code can be reused and compared directly.

Follow this procedure for every conversion batch.  The verification step
at the end is mandatory and uses the same build the players use.

## 1. Build environment

Set up once per machine (see [INSTALL.md](INSTALL.md)):

	sh setup.sh

If the environment is already prepared, skip setup and use the toolchain
directly:

	make -j$(nproc)
	make compare

The authoritative tools for verification are:

* `make all` - builds the ROM from sources
* `make compare` - `sha1sum -c rom_jp.sha1`, must print `OK`

These two are the *only* acceptance test.  Do not rely on checking a
single object or a single ROM range instead of the full build.

## 2. Picking a target

Work in link order.  `ld_script_jp.txt` lists every object in ROM address
order; find the first `asm/*.o(.text)` entry whose functions have not been
converted yet.  `asm/crt0.o` stays in asm (it is the ROM header plus ARM
bootstrap code, exactly like pokeemerald's `src/crt0.s`).

Progress is tracked by:

	python3 tools/decomp_progress.py

Each converted batch must include the updated progress percentage in the
commit message.

## 3. Converting asm to C

For each function in the target asm file:

1. Disassemble/read the JP asm and identify the function's role.
2. Find the corresponding function in pokeemerald (`src/`).  Compare
   behavior, not just bytes: same call graph, same data flow, same
   control structure qualifies as "the same function" even if register
   allocation or a few instructions differ.
3. Copy/adapt the US C code into a JP `src/` file.  Prefer keeping the US
   variable names; rename only where the JP logic actually differs.
4. If the function is JP-only (no US counterpart), write it as JP-specific
   code and keep its JP name.

### Special cases

* **libc/newlib functions** (`asm/libc_rest_*.s`, `asm/libc_mid_0.s`):
  copy the source straight from `tools/agbcc-src/libc/` (e.g.
  `libc/string/memcpy.c`) into `src/libc/`.  These compile byte-exact
  with the `build/src/libc/%.o` rule.  Do **not** link the official
  `libc.a` where a source copy can be compiled instead.
* **Flash / RTC / library-style calls** (`agb_flash*`, `siirtc`): they
  came from official libraries and match pokeemerald's split sources
  almost byte-for-byte; port them early.
* **Naked functions / inline asm**: keep the `__attribute__((naked))`
  body as inline asm inside the C file; the section must land at the same
  address, so keep it in the same `src/` object that ld_script references.

## 4. Wiring the new source into the build

The Makefile compiles `src/*.c` and `src/*/*.c` automatically
(`C_SRCS := $(filter-out $(UNPORTED_SRCS),$(wildcard ...))`).  There are
therefore exactly three edit points per conversion:

1. **`ld_script_jp.txt`**: replace the asm object reference with the C
   object.  When the converted functions occupy a contiguous range, use
   the whole object:

	   asm/link_mid_0.o(.text);

   becomes:

	   src/link.o(.text.ProcessRecvCmds);

   (or list several `.text.<function>` sections if the asm file sits
   between other objects).  Then remove the asm file from
   `$(ASFILE)`/ld_script.  Paths in ld_script are relative to `build/`
   (the linker runs with `cd build`), so asm objects are written as
   `asm/<file>.o` and C objects as `src/<file>.o` - no `build/` prefix.
2. **`UNPORTED_SRCS` in the Makefile**: if a US `src/` file is copied for
   reference but its functions are not all converted yet, list it here so
   the wildcard does not compile it (that would duplicate symbols with
   the asm objects).  Once fully converted, remove it from the list.
3. **Remove the converted functions from the asm file**: delete them from
   `asm/<file>.s`, or delete the whole `.s` file when empty, and drop its
   `asm/<file>.o(.text)` line from `ld_script_jp.txt`.

Keep converted `.c` files in the same relative path as pokeemerald
(`src/field_player_avatar.c`, `src/libc/memcpy.c`, ...) so diffs against
US are trivial.

## 5. Verification (mandatory)

Always verify with the full player build, never with a partial check:

	make -j$(nproc)
	make compare

`make compare` must print `pokeemerald_jp.gba: OK`.  If it fails:

* use `tools/diff_rom_range.sh <addr> <length>` only to *locate* the
  diverging bytes;
* inspect the JP asm for the function and adjust the C (types, casts,
  loop shape, static vs inline, section names);
* fix, rebuild, re-run `make compare`.

Only commit once `make compare` passes.

## 6. Committing

* Commit in small, self-contained batches (one module or one logical
  group of functions).
* Message format:

	  c: convert <module> <what> to C

	  - <per-function notes: JP differences, casts, kept-in-asm notes>
	  - SHA1 verified byte-exact (make compare)

	  decomp progress: N/12612 = P% (asm -> C)

* Sign with all three authors:

	  Co-authored-by: DeepSeek <deepseek-ai@users.noreply.github.com>
	  Co-authored-by: Codex <codex@users.noreply.github.com>

* Push only to `origin` (Wokann/pokeemerald-jp).  Never push to the
  `pret` upstream.

## 7. Naming and matching rules

* Symbol names should follow pokeemerald's current names when the
  functions correspond (update `funcmap_*.txt` accordingly).
* When a JP function cannot be matched to US by address, match by mask
  bytes / behavior / surrounding call graph, and keep the JP name until
  a US equivalent is confirmed.
* `pokeemerald.sym` generation: use the map and check the actual source
  for anything the symbol table cannot express.
* Pure binary data extracted from the ROM must not be committed; only
  commit once it is split into real decompiled parts (`.bpp`, palettes,
  structs, etc.).
