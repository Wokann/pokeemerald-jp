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

   When the C module calls functions that the JP splitter named
   differently, rename the JP asm labels to pokeemerald's names (judged
   by functionality + call-site logic, not by name or address) instead
   of adding `ABSOLUTE()` aliases in the linker script: a Thumb `bl` to
   an `ABSOLUTE()` symbol makes the linker emit ARM interworking veneers
   (`.text.__stub`), which shifts the layout and breaks `make compare`.
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
dynamic_placeholder_text_util.s removed), src/gym_leader_rematch.c (3,
full module -- asm/gym_leader_rematch.s removed), src/birch_pc.c (3,
full module -- asm/birch_pc.s removed), src/fldeff_strength.c (4, full
module -- asm/fldeff_strength.s removed), src/fldeff_teleport.c (4, full
module -- asm/fldeff_teleport.s removed), src/hof_pc.c (4, asm/hof_pc.s
removed), src/fldeff_rocksmash.c (10, asm/fldeff_rocksmash.s trimmed to the
remaining 4 EscapeRope helper functions), src/fldeff_dig.c (4, full module --
asm/fldeff_rocksmash.s removed), src/fldeff_sweetscent.c (6, full module --
asm/fldeff_sweetscent.s removed), src/fldeff_softboiled.c (8, full module --
asm/fldeff_softboiled.s removed), src/fldeff_flash.c (20, full module --
asm/fldeff_flash.s removed), src/fldeff_cut.c (17, full module --
asm/fldeff_cut.s removed), src/fldeff_escalator.c (6, full module --
asm/fldeff_escalator.s removed).

The rocksmash conversion also aligned the JP asm names of the called
helpers with pokeemerald (EventObject* -> ObjectEvent*, PlayerGetZCoord
-> PlayerGetElevation, GetEventObjectIdByXYZ -> GetObjectEventIdByPosition,
MovementAction_AcroEndWheelieFaceLeft_Step0 ->
ObjectEventClearHeldMovementIfFinished, ScriptContext1_SetupScript ->
ScriptContext_SetupScript, ScriptContext2_Enable/Disable ->
LockPlayerFieldControls/UnlockPlayerFieldControls, EnableBothScriptContexts
-> ScriptContext_Enable).  funcmap_jp.txt and sym_ewram_jp.txt were updated
accordingly (gPlayerFacingPosition 0x0203A80C, gSpecialVar_LastTalked
0x02037292).

src/fldeff_dig.c (SetUpFieldMove_Dig, FieldCallback_Dig, FldEff_UseDig,
StartDigFieldEffect) completes the module; the JP splitter had swapped the
Overworld_ResetStateAfterFly / Overworld_ResetStateAfterDigEscRope labels
(0x0808406C is the dig/escape-rope reset, 0x08083FE8 the fly reset, judged
by call-site logic in item_use.s and field_effect.s), and
CanUseEscapeRopeOnCurrMap / task08_080A1C44 were renamed to pokeemerald's
CanUseDigOrEscapeRopeOnCurMap / Task_UseDigEscapeRopeOnField.

src/fldeff_sweetscent.c (SetUpFieldMove_SweetScent, FieldCallback_SweetScent,
FldEff_SweetScent, StartSweetScentFieldEffect, TrySweetScentEncounter,
FailSweetScentEncounter) is the sixteenth wired module.  Renamed
GetPlayerAvatarObjectId -> GetPlayerAvatarSpriteId (0x0808B640 returns
gPlayerAvatar.spriteId) and sub_080ABCE0 -> SetWeatherPalStateIdle; the
splitter's "SetWeatherScreenFadeOut" at 0x080AAB88 was actually an empty
do-nothing (renamed sub_080AAB88) while the real SetWeatherScreenFadeOut is
0x080ABCCC.  Added gPaletteDecompressionBuffer (0x02037C88) and
EventScript_FailSweetScent (0x08256A14) symbols.

src/fldeff_softboiled.c (SetUpFieldMove_SoftBoiled, ChooseMonForSoftboiled,
Task_TryUseSoftboiledOnPartyMon, Task_SoftboiledRestoreHealth,
Task_DisplayHPRestoredMessage, Task_FinishSoftboiled,
Task_ChooseNewMonForSoftboiled, CantUseSoftboiledOnMon) is the seventeenth
wired module.  Renamed the JP party-menu helper labels to pokeemerald
(sub_081B1040 -> Task_HandleChooseMonInput, display_pokemon_menu_message ->
DisplayPartyMenuStdMessage, sub_081B182C -> DisplayPartyMenuMessage,
sub_081B1BE8 -> PartyMenuModifyHP, sub_081B0C9C -> AnimatePartySlot,
sub_081B18A4 -> IsPartyMenuTextPrinterActive,
schedule_bg_copy_tilemap_to_vram -> ScheduleBgCopyTilemapToVram) and
GetMonData -> GetMonData3 (2-arg form kept as GetMonData2 alias, as in
pokeemerald).  Added gStringVar4 (0x02021C7C), gText_PkmnHPRestoredByVar2
(0x085C9E8F) and gText_CantBeUsedOnPkmn (0x085C9B07) symbols.

src/fldeff_flash.c (SetUpFieldMove_Flash, FieldCallback_Flash,
FldEff_UseFlash, CB2_ChangeMapMain, VBC_ChangeMapVBlank, CB2_DoChangeMap,
TryDoMapTransition, GetMapPairFadeToType, GetMapPairFadeFromType, the
DoExitCaveTransition/Task_ExitCaveTransition1-5 and
DoEnterCaveTransition/Task_EnterCaveTransition1-4 cave-transition tasks) is
the eighteenth wired module.  The JP splitter's hm2_flash / c2_change_map /
sub_* labels were renamed to the pokeemerald names; the module's data
(sTransitionTypes 0x08592214, the three cave-transition palettes
0x0859229C/BC/DC, tilemap 0x085922FC and tiles 0x085924DC) stays in the ROM
data region and is referenced via ABSOLUTE symbols, with EventScript_UseFlash
(0x08257EE2) added.  Two bogus funcmap_jp entries (0x080E82DC and 0x081347FC
mislabeled as CB2_ChangeMapMain / VBC_ChangeMapVBlank) were corrected.

src/fldeff_cut.c (SetUpFieldMove_Cut, FieldCallback_CutGrass/CutTree,
FldEff_UseCutOnGrass/OnTree, StartCutGrass/CutTreeFieldEffect, FldEff_CutGrass,
SetCutGrassMetatile, GetLongGrassCaseAt, SetCutGrassMetatiles,
HandleLongGrassOnHyper, CutGrassSpriteCallback1/2/End,
FixLongGrassMetatilesWindowTop/Bottom) is the nineteenth wired module.  The
module's IWRAM vars (sCutSquareSide/sTileCountFromPlayer_X/Y 0x03001100-02,
sHyperCutTiles 0x03001108), EWRAM pointer (sCutGrassSpriteArrayPtr
0x02039A70) and rodata (sHyperCutStruct 0x08557164, sSpriteTemplate_CutGrass
0x085571C8, EventScript_UseCut 0x08256612,
FarawayIsland_Interior_EventScript_HideMewWhenGrassCut 0x0823B5A9) stay in
the ROM data region and are referenced via symbols.  Renamed the JP labels
MapGridGetZCoordAt -> MapGridGetElevationAt, MapGridIsImpassableAt ->
MapGridGetCollisionAt, sub_0808E0CC -> AllowObjectAtPosTriggerGroundEffects,
ScriptUnfreezeEventObjects -> ScriptUnfreezeObjectEvents, and swapped the
mislabeled MetatileBehavior_IsLongGrass / _Duplicate pair (0x08089480 is the
Duplicate check used by fldeff_cut; 0x08088DC0 is the generic one).
verify_all's linker-addend fallback was extended to mid-function literal
pools (sHyperCutStruct+2 style relocations).

src/fldeff_escalator.c (SetEscalatorMetatile, Task_DrawEscalator,
CreateEscalatorTask, StartEscalator, StopEscalator, IsEscalatorMoving) is the
twentieth wired module.  The seven sEscalatorMetatiles_* tables
(0x08562A3E-0x08562A62) and sEscalatorAnim_TaskId (0x02039C2C) stay in the
ROM data region; the JP sub_080E0AA4/ABC/AD0 labels were renamed to
StartEscalator/StopEscalator/IsEscalatorMoving.
