# C decompilation

Functions that are byte-identical to the US decompilation after
normalizing pointers and bl targets (see tools/compare_functions.py) can
be ported from pokeemerald's C source.  The compiled output is inlined
into the assembly at the same ROM address, keeping the layout fixed.

## Pipeline

Compile a C function with the pret agbcc toolchain (from
~/pokeemerald/tools/agbcc):

    agbcc -mthumb-interwork -O2 -fhex-asm -o out.s file.c

then inline the generated .text into the corresponding asm file (in the
repo's unified-syntax style: `movs` instead of `mov`, keep
thumb_func_start/end and the local literal pool).  Global data referenced
by the C must be defined at its JP address with ABSOLUTE() in
sym_ewram_jp.txt / sym_iwram_jp.txt so the literal resolves correctly.

## Converted so far

* `trainer_hill_vblank.c` - ClearTrainerHillVBlankCounter (0x080008E8,
  12 bytes), verified byte-identical.
