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
asm/fldeff_escalator.s removed), src/field_poison.c (7, asm/field_poison.s
split; the remaining 13 functions belong to pokeemerald's
src/pokemon_size_record.c and are still in asm), src/pokemon_size_record.c
(12) + src/give_gift_ribbon_to_party.c (1) complete the region --
asm/field_poison.s removed, src/field_door.c (23, full module --
asm/field_door.s removed), src/rotating_gate.c (21, full module --
asm/rotating_gate.s removed), src/field_message_box.c (17, full module --
asm/field_message_box.s removed), src/field_tasks.c (28, full module --
asm/field_tasks.s removed), src/field_camera.c (8) + src/field_camera_rest.c
(12) partial -- the 8 middle functions (RedrawMapSlicesForCameraUpdate,
RedrawMapSliceN/S/E/W, CurrentMapDrawMetatileAt, DrawDoorMetatileAt,
DrawMetatileAt) are JP variants with inline offset math and stay in
asm/field_camera_rest.s, src/berry_powder.c (14, full module --
asm/berry_powder.s removed), src/field_region_map.c (6, full module --
asm/field_region_map.s removed).

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

src/field_poison.c (IsMonValidSpecies, AllMonsFainted, FaintFromFieldPoison,
MonFaintedFromPoison, Task_TryFieldPoisonWhiteOut, TryFieldPoisonWhiteOut,
DoPoisonFieldEffect) is the twenty-first wired module (partial: the JP
field_poison.s region also holds pokemon_size_record.c's functions, which
stay in asm for now).  Renamed StringGetEnd10 -> StringGet_Nickname
(0x0800885C), pokemon_ailments_get_primary -> GetAilmentFromStatus
(0x081B1CE4), InBattlePyramid -> CurrentBattlePyramidLocation (0x081A9BB8),
sub_081D52F0 -> InTrainerHillChallenge (0x081D52F0), ScriptContext1_Stop ->
ScriptContext_Stop, and updated data/specials.inc (ExecuteWhiteOut ->
TryFieldPoisonWhiteOut).  Added gText_PkmnFainted_FldPsn (0x085CC30F).

src/pokemon_size_record.c (GetMonSizeHash, TranslateBigMonSizeTableIndex,
GetMonSize, FormatMonSizeRecord, CompareMonSize, GetMonSizeRecordInfo,
InitSeedotSizeRecord, GetSeedotSizeRecordInfo, CompareSeedotSize,
InitLotadSizeRecord, GetLotadSizeRecordInfo, CompareLotadSize) and
src/give_gift_ribbon_to_party.c (GiveGiftRibbonToParty) finish the JP
field_poison region.  JP variants handled: FormatMonSizeRecord copies the
2-byte decimal point to a local before appending; species names use 6-byte
rows (gSpeciesNamesJP 0x082EA31C) and GetMonSize uses HoennToNationalOrder.
Added sBigMonSizeTable (0x085694D0), gText_DecimalPoint (0x08569550),
gText_Marco (0x085CC31B) and sGiftRibbonsMonDataIds (0x08569552); specials.inc
updated (sub_080FA300/31C/358/374 -> GetSeedotSizeRecordInfo/CompareSeedotSize/
GetLotadSizeRecordInfo/CompareLotadSize).

src/field_door.c (CopyDoorTilesToVram, BuildDoorTiles,
DrawCurrentDoorAnimFrame, DrawClosedDoorTiles, DrawDoor, AnimateDoorFrame,
Task_AnimateDoor, GetLastDoorFrame, GetDoorGraphics,
StartDoorAnimationTask, DrawClosedDoor, DrawOpenedDoor,
StartDoorOpenAnimation, StartDoorCloseAnimation, GetDoorSoundType,
Debug_FieldAnimateDoorOpen, FieldSetDoorOpened, FieldSetDoorClosed,
FieldAnimateDoorClose, FieldAnimateDoorOpen, FieldIsDoorAnimationRunning,
GetDoorSoundEffect, ShouldUseMultiCorridorDoor) is the twenty-third wired
module.  The door-animation data (the huge tiles/palette arrays) stays in
the ROM data region; only the four top-level tables are referenced:
sDoorOpenAnimFrames (0x0846F3AC), sDoorCloseAnimFrames (0x0846F3C0),
sBigDoorOpenAnimFrames (0x0846F3D4) and sDoorAnimGraphicsTable
(0x0846F594).  JP variant: DoorAnimFrame.offset is u16 (US uses s16).
The JP splitter's door_build_blockdef / cur_mapdata_get_door_x2_at /
unref_sub_808A83C / sub_0808A2C8 labels were renamed to BuildDoorTiles /
GetDoorSoundType / Debug_FieldAnimateDoorOpen / ShouldUseMultiCorridorDoor.

src/rotating_gate.c (GetCurrentMapRotatingGatePuzzleType,
RotatingGate_ResetAllGateOrientations, _GetGateOrientation,
_SetGateOrientation, _RotateInDirection, _LoadPuzzleConfig,
_CreateGatesWithinViewport, _CreateGate, SpriteCallback_RotatingGate,
_HideGatesOutsideViewport, LoadRotatingGatePics,
_DestroyGatesOutsideViewport, _CanRotate, _HasArm,
_TriggerRotationAnimation, _GetRotationInfo, _InitPuzzle,
RotatingGatePuzzleCameraUpdate, _InitPuzzleAndGraphics,
CheckForRotatingGatePuzzleCollision[WithoutAnimation]) is the
twenty-fourth wired module.  All puzzle-config/graphics/sprite-template/
rotation-info/arm tables stay in the ROM data region (0x0856A494-0x0856DC5C)
and the three EWRAM vars (sRotatingGate_GateSpriteIds 0x02039D04,
_PuzzleConfig 0x02039D10, _PuzzleCount 0x02039D14) are in sym_ewram.
ARRAY_COUNT needed sized externs (8/11) to avoid folding to 0; the JP
Regular/Large sprite-template addresses are swapped vs the US declaration
order.  Renamed sub_08092960 -> GetMapCoordsFromSpritePos and added
gSpriteCoordOffsetX/Y (0x02021B38/3A).

src/field_message_box.c (InitFieldMessageBox, Task_DrawFieldMessage,
CreateTask/DestroyTask_DrawFieldMessage, ShowFieldMessage,
Task_HidePokenavMessageWhenDone, ShowPokenavFieldMessage,
ShowFieldAutoScrollMessage, ForceShowFieldAutoScrollMessage,
ShowFieldMessageFromBuffer, ExpandStringAndStartDrawFieldMessage,
StartDrawFieldMessage, HideFieldMessageBox, GetFieldMessageBoxMode,
IsFieldMessageBoxHidden, ReplaceFieldMessageWithFrame, StopFieldMessage) is
the twenty-fifth wired module.  Only data needed: sFieldMessageBoxMode
(0x0203725C) and gTextFlags (0x030030B4).  The JP splitter had swapped
DrawDialogueFrame (0x08196FB8) / ClearDialogWindowAndFrame (0x08197028) and
DrawStdWindowFrame (0x08196FF0) / ClearStdWindowAndFrame (0x08197060);
sub_08196F98 -> LoadMessageBoxAndBorderGfx.  Renames applied across asm
callers (C files keep the pokeemerald names).

src/field_tasks.c (Task_RunPerStepCallback, RunTimeBasedEvents,
Task_RunTimeBasedEvents, SetUpFieldTasks, ActivatePerStepCallback,
ResetFieldTasksArgs, DummyPerStepCallback,
GetPacifidlogBridgeMetatileOffsets, TrySetPacifidlogBridgeMetatiles,
TrySetLogBridgeHalfSubmerged/FullySubmerged/Floating,
ShouldRaise/ShouldSinkPacifidlogLogs, PacifidlogBridgePerStepCallback,
TryLower/TryRaiseFortreeBridge, FortreeBridgePerStepCallback,
CoordInIcePuzzleRegion, MarkIcePuzzleCoordVisited,
IsIcePuzzleCoordVisited, SetSootopolisGymCrackedIceMetatiles,
SootopolisGymIcePerStepCallback, AshGrassPerStepCallback,
SetCrackedFloorHoleMetatile, CrackedFloorPerStepCallback,
SetMuddySlopeMetatile, Task_MuddySlope) is the twenty-sixth wired module.
The six data tables (sPerStepCallbacks 0x084E898C, the three bridge-offset
tables 0x084E89AC/CC/EC, sSootopolisGymIceRowVars 0x084E8A0C,
sMuddySlopeMetatiles 0x084E8A40) stay in the ROM data region; ARRAY_COUNT
needed sized externs (8/4).  Renamed ScriptContext2_IsEnabled ->
ArePlayerFieldControlsLocked and the four misspelled
MetatileBehavior_IsPacifilog* labels to the pokeemerald Pacifidlog names;
added gCamera (0x02036FD4).  verify_all now covers every src function
(381/381); its linker-addend fallback was fixed to pad the JP side before
the word-by-word comparison.

src/field_camera.c (ResetCameraOffset, AddCameraTileOffset,
AddCameraPixelOffset, ResetFieldCamera, FieldUpdateBgTilemapScroll,
GetCameraOffsetWithPan, DrawWholeMapView, DrawWholeMapViewInternal) and
src/field_camera_rest.c (DrawMetatile, MapPosToBgTilemapOffset,
CameraUpdateCallback, ResetCameraUpdateInfo, InitCameraUpdateCallback,
CameraUpdate, MoveCameraAndRedrawMap, SetCameraPanningCallback,
SetCameraPanning, InstallCameraPanAheadCallback, UpdateCameraPanning,
CameraPanningCB_PanAhead) are the twenty-seventh wired module (partial).
The middle 8 functions are JP variants (inline tilemap offset math, no
RequestBgCopy, different metatile decompression path in DrawMetatileAt)
and stay in asm/field_camera_rest.s; MapPosToBgTilemapOffset/DrawMetatile
were made global so the asm can call them.  JP variants: ResetCameraOffset
clears tile offsets first and leaves copyBGToVRAM set; AddCameraTileOffset
mods each offset right after adding; AddCameraPixelOffset has no modulo.
Renamed UpdateEventObjectsForCameraUpdate -> UpdateObjectEventsForCameraUpdate,
ResetBerryTreeSparkleFlags -> SetBerryTreesSeen, move_tilemap_camera_to_upper_left_corner
-> ResetFieldCamera and sub_0808956C -> GetCameraOffsetWithPan.  Added the
camera IWRAM vars (sFieldCameraOffset 0x03000E20, pans/flags 0x03000E28-30,
gOverworldTilemapBuffer_Bg1/2/3 0x03005B00/AFC/B04, gFieldCamera 0x03005B30,
gTotalCameraPixelOffsetX/Y 0x03005B4C/48) and gUnusedBikeCameraAheadPanback
(0x02036FE8).

src/berry_powder.c (DecryptBerryPowder, SetBerryPowder,
ApplyNewEncryptionKeyToBerryPowder, HasEnoughBerryPowder_/HasEnoughBerryPowder,
GiveBerryPowder, TakeBerryPowder_/TakeBerryPowder, GetBerryPowder,
PrintBerryPowderAmount, DrawPlayerPowderAmount, PrintPlayerBerryPowderAmount,
DisplayBerryPowderVendorMenu, RemoveBerryPowderVendorMenu) is the
twenty-eighth wired module.  Only data needed: sBerryPowderVendorWindowId
(0x02022948) and gText_Powder (0x085CCCEE); the UNUSED bg/window templates
stay in the ROM data region.  JP variants: amount printed with FONT_SMALL at
(16,12), the "Powder" label at y=0, and the vendor window template uses
height 3 / baseBlock 0x20.

src/field_region_map.c (FieldInitRegionMap, MCB2_InitRegionMapRegisters,
VBCB/MCB2_FieldUpdateRegionMap, FieldUpdateRegionMap,
PrintRegionMapSecName) is the twenty-ninth wired module.  Only data needed:
sFieldRegionMapHandler (0x0203B99C), sFieldRegionMapBgTemplates
(0x085C6124), sFieldRegionMapWindowTemplates (0x085C612C) and gText_Hoenn
(0x085C611C).  JP variants: window-border tile 0x23 instead of 0x27, the
title/name text printed at y=2 (and the title at x=0 without the centered
offset), and no FillWindowPixelBuffer before the section name.  Renamed
clear_scheduled_bg_copies_to_vram / do_scheduled_bg_tilemap_copies_to_vram
and sub_081230B8 to the pokeemerald names.
