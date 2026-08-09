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

`tools/c_decomp/convert_c.py <function> <file.c>` automates this: it
reads the JP function address from the asm label, compiles with agbcc,
compares the code bytes (masking the trailing literal), and prints the
generated snippet.  With `-f <function> <file.c>` the file may contain
several functions (the named one is extracted via arm-none-eabi-nm -S).
Only functions where it reports MATCH are integrated.

The pokeemerald include tree (include/) is ported wholesale, so C files
use the real headers (`#include "global.h"`, `"sprite.h"`, ...).  The
compile step runs `cpp -P -I include` first (the `-P` strips linemarkers
that agbcc's own preprocessor rejects), then pipes to agbcc.

Converted C sources live in `src/` following pokeemerald's module layout
(e.g. src/recorded_battle.c, src/battle_anim_mons.c), so the two trees
can be diffed directly.

## Converted so far

52 functions across 23 src/ modules (matching pokeemerald layout):
src/main.c (2), src/util.c (1), src/battle_anim_mons.c (4),
src/field_specials.c (1), src/menu.c (3), src/mirage_tower.c (1),
src/overworld.c (1), src/sound.c (1), src/recorded_battle.c (10),
src/field_message_box.c (1), src/party_menu.c (1), src/link.c (1),
src/battle_setup.c (1), src/event_object_movement.c (2), src/script.c (2),
src/mystery_gift_menu.c (1), src/text_window.c (1), src/trainer_hill.c (1),
src/field_weather.c (1), src/string_util.c (11), src/main_menu.c (1),
src/tileset_anims.c (1), src/decompress.c (1).
All verified byte-identical with tools/c_decomp/convert_c.py -f.
