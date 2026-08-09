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
generated snippet.  Only functions where it reports MATCH are integrated.

The pokeemerald include tree (include/) is ported wholesale, so C files
use the real headers (`#include "global.h"`, `"sprite.h"`, ...).  The
compile step runs `cpp -P -I include` first (the `-P` strips linemarkers
that agbcc's own preprocessor rejects), then pipes to agbcc.

## Converted so far

* `trainer_hill_vblank.c` - ClearTrainerHillVBlankCounter (0x080008E8,
  12 bytes), verified byte-identical.
* `store_word_in_two_halfwords.c` - StoreWordInTwoHalfwords (0x0806F100,
  8 bytes), no globals.
* `store_pointer_in_vars.c` - StorePointerInVars (0x080A7910, 8 bytes),
  no globals; JP uses a signed `asrs` shift.
* `get_battle_outcome.c` - GetBattleOutcome (0x08138BF0, 12 bytes),
  gBattleOutcome mapped to ABSOLUTE(0x02023FDE).
* `store_sprite_callback_in_data6.c` - StoreSpriteCallbackInData6
  (0x080A5B9C, 8 bytes); minimal struct Sprite with data[8] at 0x2E.
* `set_callback_to_stored_in_data6.c` - SetCallbackToStoredInData6
  (0x080A5BA4, 14 bytes).
* `free_all_overworld_window_buffers.c` - FreeAllOverworldWindowBuffers
  (0x08196DE8, 10 bytes); tail-call via bl, resolved at link time.
* `clear_mirage_tower_pulse_blend.c` - ClearMirageTowerPulseBlend
  (0x081BE348, 12 bytes); static pointer mapped to ABSOLUTE(0x0203CBE4).
* `cb2_overworld_basic.c` - CB2_OverworldBasic (0x080856E8, 10 bytes);
  JP version calls SafariZoneRetirePrompt (differs from US).
* `get_current_map_music.c` - GetCurrentMapMusic (0x080A27CC, 8 bytes);
  JP reads a u16 from IWRAM (gCurrentMapMusic = ABSOLUTE(0x03000F48)),
  differs from US SaveBlock-based version.
* `get_ai_scripts_in_recorded_battle.c` - GetAiScriptsInRecordedBattle
  (0x08186190, 8 bytes); sAI_Scripts at ABSOLUTE(0x0203C488).
* `get_battle_scene_in_recorded_battle.c` -
  GetBattleSceneInRecordedBattle (0x08185D1C, 8 bytes); sBattleScene at
  ABSOLUTE(0x0203C483).
* `destroy_sprite_and_free_resources_.c` -
  DestroySpriteAndFreeResources_ (0x080A7ED8, 10 bytes); tail call.
* `get_field_message_box_mode.c` - GetFieldMessageBoxMode
  (0x08097CB8, 8 bytes); sFieldMessageBoxMode at ABSOLUTE(0x0203725C).
* `get_cursor_selection_mon_id.c` - GetCursorSelectionMonId
  (0x081B1024, 8 bytes); gPartyMenu.slotId (real party_menu.h struct).
* `has_link_error_occurred.c` - HasLinkErrorOccurred (0x0800AE18,
  8 bytes); gLinkErrorOccurred at ABSOLUTE(0x0300310C) (IWRAM).
* `get_start_menu_window_id.c` / `get_map_name_popup_window_id.c` -
  window-id getters (0x0819780C / 0x0819787C); EWRAM statics at
  0x0203CA58 / 0x0203CA59.
