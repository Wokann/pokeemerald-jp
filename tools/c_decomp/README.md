# C decompilation

Functions that are byte-identical to the US decompilation after
normalizing pointers and bl targets (see tools/compare_functions.py) can
be ported from pokeemerald's C source.  Each conversion is verified
against the JP ROM and then wired into the build so `make` itself proves
byte-identity.

## Pipeline

1. **Verify** the C against the JP ROM:
   `python3 tools/c_decomp/verify_all.py` compiles every function in
   `src/` with the pret agbcc toolchain and byte-compares it with the
   ROM (masking link-time data: Thumb bl immediates and absolute-address
   literal pool words).  Addresses come from the asm label comment or,
   for functions already moved to C, from funcmap_jp.txt.
2. **Wire the module into the build** (per converted module):
   - split the asm file so the converted functions occupy one
     contiguous ROM-ordered range (`asm/xxx.s` keeps the functions
     before it, `asm/xxx_rest.s` keeps the ones after), or delete the
     asm file once every function is converted;
   - add the module to `C_SRCS` in the Makefile (compiled with
     `-ffunction-sections`, each function becomes `.text.<name>`);
   - update ld_script_jp.txt: replace/extend the asm object entries
     with `build/src/xxx.o(.text.*)` at the exact ROM position;
   - `make` must produce a byte-identical ROM (`make compare`).
3. **Commit** only after `make compare` passes.

The pokeemerald include tree (include/) is ported wholesale, so C files
use the real headers (`#include "global.h"`, `"sprite.h"`, ...).  The
compile step runs `cpp -P -nostdinc -undef -iquote include
-I ../pokeemerald/tools/agbcc/include ...` (agbcc's own libc headers,
not glibc) before agbcc.

Converted C sources live in `src/` following pokeemerald's module layout
(e.g. src/recorded_battle.c, src/battle_anim_mons.c), so the two trees
can be diffed directly.  Function order inside each C file must match
the JP ROM order (which can differ from pokeemerald's order).

## Converted so far

117 functions across 48 src/ modules (matching pokeemerald layout):
src/main.c (2), src/util.c (1), src/battle_anim_mons.c (4),
src/field_specials.c (1), src/menu.c (3), src/mirage_tower.c (1),
src/overworld.c (1), src/sound.c (1), src/recorded_battle.c (10),
src/field_message_box.c (1), src/party_menu.c (1), src/link.c (1),
src/battle_setup.c (1), src/event_object_movement.c (2), src/script.c (2),
src/mystery_gift_menu.c (1), src/text_window.c (1), src/trainer_hill.c (1),
src/field_weather.c (1), src/string_util.c (11), src/main_menu.c (1),
src/tileset_anims.c (1), src/decompress.c (1), src/item.c (1),
src/pokemon.c (1), src/record_mixing.c (1), src/coord_event_weather.c (7),
src/contest_painting.c (1), src/intro.c (1),
src/pokemon_storage_system.c (1), src/easy_chat.c (1),
src/frontier_util.c (1), src/cable_club.c (1), src/wild_encounter.c (1),
src/event_data.c (4), src/start_menu.c (1), src/bike.c (1),
src/battle_transition.c (1), src/sprite.c (1), src/berry.c (1),
src/link_rfu_3.c (1), src/item_menu_icons.c (1), src/malloc.c (3),
src/field_door.c (1), src/load_save.c (6), src/hof_pc.c (4),
src/tv.c (5), src/battle_tower.c (2).

All verified byte-identical with `python3 tools/c_decomp/verify_all.py`.

Wired into the build (compiled from C, linked into the ROM):
src/load_save.c (16, full module -- asm/load_save.s and
asm/load_save_rest.s were removed), src/decompress.c (21, full module --
asm/decompress.s removed), src/util.c (11, full module -- asm/util.s
removed), src/text_window.c (11, full module -- asm/text_window.s
removed), src/random.c (4, full module -- asm/random.s removed),
src/heal_location.c (3, full module -- asm/heal_location.s removed),
src/landmark.c (2, full module -- asm/landmark.s removed),
src/trig.c (4, full module -- asm/trig.s removed),
src/dynamic_placeholder_text_util.c (4, full module -- asm/
dynamic_placeholder_text_util.s removed), src/hof_pc.c (4, asm/hof_pc.s
removed).
