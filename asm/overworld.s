.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start CB2_ReturnToFieldContinueScriptPlayMapMusic
CB2_ReturnToFieldContinueScriptPlayMapMusic: @ 0x08085B34
	push {lr}
	bl FieldClearVBlankHBlankCallbacks
	ldr r1, _08085B48
	ldr r0, _08085B4C
	str r0, [r1]
	bl CB2_ReturnToField
	pop {r0}
	bx r0
	.align 2, 0
_08085B48: .4byte 0x03005B0C
_08085B4C: .4byte 0x080AEA65
	thumb_func_end CB2_ReturnToFieldContinueScriptPlayMapMusic

	thumb_func_start CB2_ReturnToFieldFadeFromBlack
CB2_ReturnToFieldFadeFromBlack: @ 0x08085B50
	push {lr}
	bl FieldClearVBlankHBlankCallbacks
	ldr r1, _08085B64
	ldr r0, _08085B68
	str r0, [r1]
	bl CB2_ReturnToField
	pop {r0}
	bx r0
	.align 2, 0
_08085B64: .4byte 0x03005B0C
_08085B68: .4byte 0x080AECC5
	thumb_func_end CB2_ReturnToFieldFadeFromBlack

	thumb_func_start sub_08085B6C
sub_08085B6C: @ 0x08085B6C
	push {lr}
	ldr r0, _08085B94
	ldrb r1, [r0, #0x1a]
	movs r0, #0xf8
	ands r0, r1
	cmp r0, #8
	bne _08085B8A
	bl SecretBaseMapPopupEnabled
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08085B8A
	bl ShowMapNamePopup
_08085B8A:
	bl FieldCB_WarpExitFadeFromBlack
	pop {r0}
	bx r0
	.align 2, 0
_08085B94: .4byte 0x02036FB8
	thumb_func_end sub_08085B6C

	thumb_func_start CB2_ContinueSavedGame
CB2_ContinueSavedGame: @ 0x08085B98
	push {r4, lr}
	bl FieldClearVBlankHBlankCallbacks
	bl StopMapMusic
	bl CB2_OverworldBasic
	ldr r0, _08085BD0
	ldrh r0, [r0]
	cmp r0, #0xff
	bne _08085BB2
	bl sub_081A36A0
_08085BB2:
	bl LoadSaveblockMapHeader
	bl GetCurrentTrainerHillMapId
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _08085BD4
	ldrh r1, [r0, #0x12]
	ldr r0, _08085BD8
	cmp r1, r0
	bne _08085BDC
	bl LoadBattlePyramidFloorEventObjectScripts
	b _08085BEE
	.align 2, 0
_08085BD0: .4byte 0x03005F50
_08085BD4: .4byte 0x02036FB8
_08085BD8: .4byte 0x00000169
_08085BDC:
	cmp r4, #0
	beq _08085BEA
	cmp r4, #6
	beq _08085BEA
	bl sub_081D5840
	b _08085BEE
_08085BEA:
	bl LoadSaveblockEventObjScripts
_08085BEE:
	bl UnfreezeObjectEvents
	bl DoTimeBasedEvents
	bl sub_08084110
	ldr r0, _08085C0C
	ldrh r1, [r0, #0x12]
	ldr r0, _08085C10
	cmp r1, r0
	bne _08085C14
	movs r0, #1
	bl InitBattlePyramidMap
	b _08085C22
	.align 2, 0
_08085C0C: .4byte 0x02036FB8
_08085C10: .4byte 0x00000169
_08085C14:
	cmp r4, #0
	beq _08085C1E
	bl InitTrainerHillMap
	b _08085C22
_08085C1E:
	bl InitMapFromSavedGame
_08085C22:
	bl PlayTimeCounter_Start
	bl ScriptContext1_Init
	bl UnlockPlayerFieldControls
	bl InitMatchCallCounters
	bl UseContinueGameWarp
	cmp r0, #1
	bne _08085C58
	bl ClearContinueGameWarpStatus2
	bl SetWarpDestinationToContinueGameWarp
	bl WarpIntoMap
	bl sub_080EE664
	ldr r0, _08085C54
	bl SetMainCallback2
	b _08085C6C
	.align 2, 0
_08085C54: .4byte 0x08085935
_08085C58:
	bl sub_080EE664
	ldr r0, _08085C74
	ldr r1, _08085C78
	str r1, [r0]
	ldr r0, _08085C7C
	bl SetMainCallback1
	bl CB2_ReturnToField
_08085C6C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08085C74: .4byte 0x03005B0C
_08085C78: .4byte 0x08085B6D
_08085C7C: .4byte 0x0808576D
	thumb_func_end CB2_ContinueSavedGame

	thumb_func_start FieldClearVBlankHBlankCallbacks
FieldClearVBlankHBlankCallbacks: @ 0x08085C80
	push {r4, lr}
	bl warp0_in_pokecenter
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08085C92
	bl CloseLink
_08085C92:
	ldr r0, _08085CA8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08085CAC
	movs r0, #0xc5
	bl EnableInterrupts
	movs r0, #2
	bl DisableInterrupts
	b _08085CC6
	.align 2, 0
_08085CA8: .4byte 0x0300319C
_08085CAC:
	ldr r4, _08085CD8
	ldrh r3, [r4]
	strh r0, [r4]
	ldr r2, _08085CDC
	ldrh r1, [r2]
	ldr r0, _08085CE0
	ands r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
	strh r3, [r4]
_08085CC6:
	movs r0, #0
	bl SetVBlankCallback
	movs r0, #0
	bl SetHBlankCallback
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08085CD8: .4byte 0x04000208
_08085CDC: .4byte 0x04000200
_08085CE0: .4byte 0x0000FFFD
	thumb_func_end FieldClearVBlankHBlankCallbacks

	thumb_func_start SetFieldVBlankCallback
SetFieldVBlankCallback: @ 0x08085CE4
	push {lr}
	ldr r0, _08085CF0
	bl SetVBlankCallback
	pop {r0}
	bx r0
	.align 2, 0
_08085CF0: .4byte 0x08085CF5
	thumb_func_end SetFieldVBlankCallback

	thumb_func_start VBlankCB_Field
VBlankCB_Field: @ 0x08085CF4
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl ScanlineEffect_InitHBlankDmaTransfer
	bl FieldUpdateBgTilemapScroll
	bl TransferPlttBuffer
	bl TransferTilesetAnimsBuffer
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end VBlankCB_Field

	thumb_func_start InitCurrentFlashLevelScanlineEffect
InitCurrentFlashLevelScanlineEffect: @ 0x08085D14
	push {lr}
	bl InBattlePyramid_
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08085D38
	bl WriteBattlePyramidViewScanlineEffectBuffer
	ldr r2, _08085D34
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r2, [r2, #8]
	bl ScanlineEffect_SetParams
	b _08085D54
	.align 2, 0
_08085D34: .4byte 0x0830FD08
_08085D38:
	bl GetFlashLevel
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08085D54
	bl WriteFlashScanlineEffectBuffer
	ldr r2, _08085D58
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r2, [r2, #8]
	bl ScanlineEffect_SetParams
_08085D54:
	pop {r0}
	bx r0
	.align 2, 0
_08085D58: .4byte 0x0830FD08
	thumb_func_end InitCurrentFlashLevelScanlineEffect

	thumb_func_start map_loading_iteration_3
map_loading_iteration_3: @ 0x08085D5C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0xd
	bls _08085D68
	b _08085E76
_08085D68:
	lsls r0, r0, #2
	ldr r1, _08085D74
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08085D74: .4byte 0x08085D78
_08085D78: @ jump table
	.4byte _08085DB0 @ case 0
	.4byte _08085DC6 @ case 1
	.4byte _08085DCE @ case 2
	.4byte _08085DD6 @ case 3
	.4byte _08085DE8 @ case 4
	.4byte _08085DF6 @ case 5
	.4byte _08085DFC @ case 6
	.4byte _08085E0C @ case 7
	.4byte _08085E1C @ case 8
	.4byte _08085E38 @ case 9
	.4byte _08085E3E @ case 10
	.4byte _08085E44 @ case 11
	.4byte _08085E60 @ case 12
	.4byte _08085E72 @ case 13
_08085DB0:
	bl InitOverworldBgs
	bl ScriptContext1_Init
	bl UnlockPlayerFieldControls
	bl sub_0808612C
	bl sub_0808613C
	b _08085E6A
_08085DC6:
	movs r0, #1
	bl mli0_load_map
	b _08085E6A
_08085DCE:
	movs r0, #1
	bl sub_080862EC
	b _08085E6A
_08085DD6:
	bl sub_08086448
	bl sub_08086340
	bl sub_08086478
	bl SetCameraToTrackGuestPlayer
	b _08085E6A
_08085DE8:
	bl InitCurrentFlashLevelScanlineEffect
	bl InitOverworldGraphicsRegisters
	bl sub_08196DF4
	b _08085E6A
_08085DF6:
	bl ResetFieldCamera
	b _08085E6A
_08085DFC:
	ldr r0, _08085E08
	ldr r0, [r0]
	bl copy_map_tileset1_to_vram
	b _08085E6A
	.align 2, 0
_08085E08: .4byte 0x02036FB8
_08085E0C:
	ldr r0, _08085E18
	ldr r0, [r0]
	bl copy_map_tileset2_to_vram
	b _08085E6A
	.align 2, 0
_08085E18: .4byte 0x02036FB8
_08085E1C:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08085E76
	ldr r0, _08085E34
	ldr r0, [r0]
	bl apply_map_tileset1_tileset2_palette
	b _08085E6A
	.align 2, 0
_08085E34: .4byte 0x02036FB8
_08085E38:
	bl DrawWholeMapView
	b _08085E6A
_08085E3E:
	bl InitTilesetAnimations
	b _08085E6A
_08085E44:
	ldr r0, _08085E5C
	ldrb r0, [r0]
	cmp r0, #0
	beq _08085E6A
	bl LoadWirelessStatusIndicatorSpriteGfx
	movs r0, #0
	movs r1, #0
	bl CreateWirelessStatusIndicatorSprite
	b _08085E6A
	.align 2, 0
_08085E5C: .4byte 0x0300319C
_08085E60:
	bl map_post_load_hook_exec
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08085E76
_08085E6A:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _08085E76
_08085E72:
	movs r0, #1
	b _08085E78
_08085E76:
	movs r0, #0
_08085E78:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end map_loading_iteration_3

	thumb_func_start load_map_stuff
load_map_stuff: @ 0x08085E80
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldrb r0, [r4]
	cmp r0, #0xd
	bls _08085E8E
	b _08085F92
_08085E8E:
	lsls r0, r0, #2
	ldr r1, _08085E98
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08085E98: .4byte 0x08085E9C
_08085E9C: @ jump table
	.4byte _08085ED4 @ case 0
	.4byte _08085EE0 @ case 1
	.4byte _08085EEA @ case 2
	.4byte _08085EF2 @ case 3
	.4byte _08085EFC @ case 4
	.4byte _08085F0A @ case 5
	.4byte _08085F10 @ case 6
	.4byte _08085F20 @ case 7
	.4byte _08085F30 @ case 8
	.4byte _08085F4C @ case 9
	.4byte _08085F52 @ case 10
	.4byte _08085F58 @ case 11
	.4byte _08085F7C @ case 12
	.4byte _08085F8E @ case 13
_08085ED4:
	bl FieldClearVBlankHBlankCallbacks
	adds r0, r5, #0
	bl mli0_load_map
	b _08085F86
_08085EE0:
	bl sub_0808612C
	bl sub_0808613C
	b _08085F86
_08085EEA:
	adds r0, r5, #0
	bl sub_080862EC
	b _08085F86
_08085EF2:
	bl mli4_mapscripts_and_other
	bl sub_080863E4
	b _08085F86
_08085EFC:
	bl InitCurrentFlashLevelScanlineEffect
	bl InitOverworldGraphicsRegisters
	bl sub_08196DF4
	b _08085F86
_08085F0A:
	bl ResetFieldCamera
	b _08085F86
_08085F10:
	ldr r0, _08085F1C
	ldr r0, [r0]
	bl copy_map_tileset1_to_vram
	b _08085F86
	.align 2, 0
_08085F1C: .4byte 0x02036FB8
_08085F20:
	ldr r0, _08085F2C
	ldr r0, [r0]
	bl copy_map_tileset2_to_vram
	b _08085F86
	.align 2, 0
_08085F2C: .4byte 0x02036FB8
_08085F30:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08085F92
	ldr r0, _08085F48
	ldr r0, [r0]
	bl apply_map_tileset1_tileset2_palette
	b _08085F86
	.align 2, 0
_08085F48: .4byte 0x02036FB8
_08085F4C:
	bl DrawWholeMapView
	b _08085F86
_08085F52:
	bl InitTilesetAnimations
	b _08085F86
_08085F58:
	ldr r0, _08085F78
	ldrb r1, [r0, #0x1a]
	movs r0, #0xf8
	ands r0, r1
	cmp r0, #8
	bne _08085F86
	bl SecretBaseMapPopupEnabled
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08085F86
	bl ShowMapNamePopup
	b _08085F86
	.align 2, 0
_08085F78: .4byte 0x02036FB8
_08085F7C:
	bl map_post_load_hook_exec
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08085F92
_08085F86:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _08085F92
_08085F8E:
	movs r0, #1
	b _08085F94
_08085F92:
	movs r0, #0
_08085F94:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end load_map_stuff

	thumb_func_start sub_08085F9C
sub_08085F9C: @ 0x08085F9C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #1
	beq _08085FD2
	cmp r0, #1
	bgt _08085FB0
	cmp r0, #0
	beq _08085FBA
	b _08085FF2
_08085FB0:
	cmp r0, #2
	beq _08085FDC
	cmp r0, #3
	beq _08085FEE
	b _08085FF2
_08085FBA:
	bl sub_0808612C
	bl sub_0808613C
	movs r0, #0
	bl sub_080862EC
	bl sub_080863CC
	bl sub_080863E4
	b _08085FE6
_08085FD2:
	bl sub_080861C4
	bl sub_081D5E60
	b _08085FE6
_08085FDC:
	bl map_post_load_hook_exec
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08085FF2
_08085FE6:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _08085FF2
_08085FEE:
	movs r0, #1
	b _08085FF4
_08085FF2:
	movs r0, #0
_08085FF4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08085F9C

	thumb_func_start map_loading_iteration_2_link
map_loading_iteration_2_link: @ 0x08085FFC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0xd
	bls _08086008
	b _0808610C
_08086008:
	lsls r0, r0, #2
	ldr r1, _08086014
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08086014: .4byte 0x08086018
_08086018: @ jump table
	.4byte _08086050 @ case 0
	.4byte _0808605E @ case 1
	.4byte _08086066 @ case 2
	.4byte _08086074 @ case 3
	.4byte _08086082 @ case 4
	.4byte _08086088 @ case 5
	.4byte _08086098 @ case 6
	.4byte _080860A8 @ case 7
	.4byte _080860C4 @ case 8
	.4byte _080860CA @ case 9
	.4byte _080860F6 @ case 10
	.4byte _080860D0 @ case 11
	.4byte _080860EC @ case 12
	.4byte _080860FE @ case 13
_08086050:
	bl FieldClearVBlankHBlankCallbacks
	bl sub_0808612C
	bl sub_0808613C
	b _080860F6
_0808605E:
	movs r0, #1
	bl sub_080862EC
	b _080860F6
_08086066:
	bl CreateLinkPlayerSprites
	bl sub_080863CC
	bl SetCameraToTrackGuestPlayer_2
	b _080860F6
_08086074:
	bl InitCurrentFlashLevelScanlineEffect
	bl InitOverworldGraphicsRegisters
	bl sub_08196DF4
	b _080860F6
_08086082:
	bl ResetFieldCamera
	b _080860F6
_08086088:
	ldr r0, _08086094
	ldr r0, [r0]
	bl copy_map_tileset1_to_vram
	b _080860F6
	.align 2, 0
_08086094: .4byte 0x02036FB8
_08086098:
	ldr r0, _080860A4
	ldr r0, [r0]
	bl copy_map_tileset2_to_vram
	b _080860F6
	.align 2, 0
_080860A4: .4byte 0x02036FB8
_080860A8:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0808610C
	ldr r0, _080860C0
	ldr r0, [r0]
	bl apply_map_tileset1_tileset2_palette
	b _080860F6
	.align 2, 0
_080860C0: .4byte 0x02036FB8
_080860C4:
	bl DrawWholeMapView
	b _080860F6
_080860CA:
	bl InitTilesetAnimations
	b _080860F6
_080860D0:
	ldr r0, _080860E8
	ldrb r0, [r0]
	cmp r0, #0
	beq _080860F6
	bl LoadWirelessStatusIndicatorSpriteGfx
	movs r0, #0
	movs r1, #0
	bl CreateWirelessStatusIndicatorSprite
	b _080860F6
	.align 2, 0
_080860E8: .4byte 0x0300319C
_080860EC:
	bl map_post_load_hook_exec
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808610C
_080860F6:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0808610C
_080860FE:
	bl SetFieldVBlankCallback
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	movs r0, #1
	b _0808610E
_0808610C:
	movs r0, #0
_0808610E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end map_loading_iteration_2_link

	thumb_func_start do_load_map_stuff_loop
do_load_map_stuff_loop: @ 0x08086114
	push {r4, lr}
	adds r4, r0, #0
_08086118:
	adds r0, r4, #0
	movs r1, #0
	bl load_map_stuff
	cmp r0, #0
	beq _08086118
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end do_load_map_stuff_loop

	thumb_func_start sub_0808612C
sub_0808612C: @ 0x0808612C
	push {lr}
	bl ClearMirageTowerPulseBlend
	bl MoveSaveBlocks_ResetHeap
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0808612C

	thumb_func_start sub_0808613C
sub_0808613C: @ 0x0808613C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	movs r0, #0
	movs r1, #0
	bl SetGpuReg
	bl ScanlineEffect_Stop
	ldr r2, _080861B4
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080861B8
	mov r0, sp
	str r0, [r1]
	str r2, [r1, #4]
	ldr r0, _080861BC
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r2, #0xc0
	lsls r2, r2, #0x13
	movs r3, #0xc0
	lsls r3, r3, #9
	mov r4, sp
	movs r6, #0
	movs r5, #0x80
	lsls r5, r5, #5
	ldr r7, _080861C0
	movs r0, #0x81
	lsls r0, r0, #0x18
	mov ip, r0
_0808617A:
	strh r6, [r4]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, #4]
	str r7, [r1, #8]
	ldr r0, [r1, #8]
	adds r2, r2, r5
	subs r3, r3, r5
	cmp r3, r5
	bhi _0808617A
	strh r6, [r4]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, #4]
	lsrs r0, r3, #1
	mov r2, ip
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0
	movs r1, #0x80
	bl ResetOamRange
	bl LoadOam
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080861B4: .4byte 0x05000002
_080861B8: .4byte 0x040000D4
_080861BC: .4byte 0x810001FF
_080861C0: .4byte 0x81000800
	thumb_func_end sub_0808613C

	thumb_func_start sub_080861C4
sub_080861C4: @ 0x080861C4
	push {lr}
	bl InitCurrentFlashLevelScanlineEffect
	bl InitOverworldGraphicsRegisters
	bl sub_08196DF4
	bl mapdata_load_assets_to_gpu_and_full_redraw
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080861C4

	thumb_func_start InitOverworldGraphicsRegisters
InitOverworldGraphicsRegisters: @ 0x080861DC
	push {r4, lr}
	bl ClearScheduledBgCopiesToVram
	bl ResetTempTileDataBuffers
	movs r0, #0x4c
	movs r1, #0
	bl SetGpuReg
	ldr r1, _080862D4
	movs r0, #0x48
	bl SetGpuReg
	ldr r1, _080862D8
	movs r0, #0x4a
	bl SetGpuReg
	movs r0, #0x40
	movs r1, #0xff
	bl SetGpuReg
	movs r0, #0x44
	movs r1, #0xff
	bl SetGpuReg
	ldr r4, _080862DC
	movs r0, #0x42
	adds r1, r4, #0
	bl SetGpuReg
	movs r0, #0x46
	adds r1, r4, #0
	bl SetGpuReg
	ldr r0, _080862E0
	ldrh r1, [r0, #2]
	ldrh r2, [r0, #4]
	orrs r1, r2
	ldrh r0, [r0, #6]
	orrs r1, r0
	movs r2, #0x82
	lsls r2, r2, #5
	adds r0, r2, #0
	orrs r1, r0
	movs r0, #0x50
	bl SetGpuReg
	ldr r1, _080862E4
	movs r0, #0x52
	bl SetGpuReg
	bl InitOverworldBgs
	movs r0, #1
	bl ScheduleBgCopyTilemapToVram
	movs r0, #2
	bl ScheduleBgCopyTilemapToVram
	movs r0, #3
	bl ScheduleBgCopyTilemapToVram
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	ldr r1, _080862E8
	movs r0, #0
	bl SetGpuReg
	movs r0, #0
	bl ShowBg
	movs r0, #1
	bl ShowBg
	movs r0, #2
	bl ShowBg
	movs r0, #3
	bl ShowBg
	bl InitFieldMessageBox
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080862D4: .4byte 0x00001F1F
_080862D8: .4byte 0x00000101
_080862DC: .4byte 0x0000FFFF
_080862E0: .4byte 0x082BF42C
_080862E4: .4byte 0x0000070D
_080862E8: .4byte 0x00007060
	thumb_func_end InitOverworldGraphicsRegisters

	thumb_func_start sub_080862EC
sub_080862EC: @ 0x080862EC
	push {r4, lr}
	adds r4, r0, #0
	bl ResetTasks
	bl ResetSpriteData
	bl ResetPaletteFade
	bl ScanlineEffect_Clear
	bl ResetAllPicSprites
	bl ResetCameraUpdateInfo
	bl InstallCameraPanAheadCallback
	cmp r4, #0
	bne _08086318
	movs r0, #0
	bl InitEventObjectPalettes
	b _0808631E
_08086318:
	movs r0, #1
	bl InitEventObjectPalettes
_0808631E:
	bl FieldEffectActiveListClear
	bl StartWeather
	bl ResumePausedWeather
	cmp r4, #0
	bne _08086332
	bl SetUpFieldTasks
_08086332:
	bl RunOnResumeMapScript
	bl TryStartMirageTowerPulseBlendEffect
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_080862EC

	thumb_func_start sub_08086340
sub_08086340: @ 0x08086340
	push {lr}
	ldr r0, _08086360
	movs r1, #0
	strh r1, [r0]
	ldr r0, _08086364
	strh r1, [r0]
	bl ResetEventObjects
	movs r0, #0
	movs r1, #0
	bl TrySpawnObjectEvents
	bl TryRunOnWarpIntoMapScript
	pop {r0}
	bx r0
	.align 2, 0
_08086360: .4byte 0x03005B4C
_08086364: .4byte 0x03005B48
	thumb_func_end sub_08086340

	thumb_func_start mli4_mapscripts_and_other
mli4_mapscripts_and_other: @ 0x08086368
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _080863C0
	movs r1, #0
	strh r1, [r0]
	ldr r0, _080863C4
	strh r1, [r0]
	bl ResetEventObjects
	mov r4, sp
	adds r4, #2
	mov r0, sp
	adds r1, r4, #0
	bl GetCameraFocusCoords
	bl GetInitialPlayerAvatarState
	adds r5, r0, #0
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldrb r2, [r5, #1]
	ldr r3, _080863C8
	ldr r3, [r3]
	ldrb r3, [r3, #8]
	bl InitPlayerAvatar
	ldrb r0, [r5]
	bl SetPlayerAvatarTransitionFlags
	bl ResetInitialPlayerAvatarState
	movs r0, #0
	movs r1, #0
	bl TrySpawnObjectEvents
	bl TryRunOnWarpIntoMapScript
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080863C0: .4byte 0x03005B4C
_080863C4: .4byte 0x03005B48
_080863C8: .4byte 0x03005AF0
	thumb_func_end mli4_mapscripts_and_other

	thumb_func_start sub_080863CC
sub_080863CC: @ 0x080863CC
	push {lr}
	movs r0, #0
	movs r1, #0
	bl sub_0808DADC
	bl RotatingGate_InitPuzzleAndGraphics
	bl RunOnReturnToFieldMapScript
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080863CC

	thumb_func_start sub_080863E4
sub_080863E4: @ 0x080863E4
	push {lr}
	ldr r2, _08086408
	ldr r3, _0808640C
	ldrb r1, [r3, #5]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0, #1]
	movs r2, #0x80
	orrs r1, r2
	strb r1, [r0, #1]
	ldrb r0, [r3, #4]
	bl InitCameraUpdateCallback
	pop {r0}
	bx r0
	.align 2, 0
_08086408: .4byte 0x02036FF0
_0808640C: .4byte 0x02037230
	thumb_func_end sub_080863E4

	thumb_func_start SetCameraToTrackGuestPlayer
SetCameraToTrackGuestPlayer: @ 0x08086410
	push {lr}
	ldr r0, _08086428
	ldrb r0, [r0]
	bl GetSpriteForLinkedPlayer
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl InitCameraUpdateCallback
	pop {r0}
	bx r0
	.align 2, 0
_08086428: .4byte 0x03005B14
	thumb_func_end SetCameraToTrackGuestPlayer

	thumb_func_start SetCameraToTrackGuestPlayer_2
SetCameraToTrackGuestPlayer_2: @ 0x0808642C
	push {lr}
	ldr r0, _08086444
	ldrb r0, [r0]
	bl GetSpriteForLinkedPlayer
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl InitCameraUpdateCallback
	pop {r0}
	bx r0
	.align 2, 0
_08086444: .4byte 0x03005B14
	thumb_func_end SetCameraToTrackGuestPlayer_2

	thumb_func_start sub_08086448
sub_08086448: @ 0x08086448
	push {r4, lr}
	sub sp, #4
	mov r4, sp
	adds r4, #2
	mov r0, sp
	adds r1, r4, #0
	bl GetCameraFocusCoords
	mov r2, sp
	ldr r0, _08086474
	ldrb r1, [r0]
	ldrh r0, [r2]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4]
	bl sub_080884A0
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086474: .4byte 0x03005B14
	thumb_func_end sub_08086448

	thumb_func_start sub_08086478
sub_08086478: @ 0x08086478
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r4, sp
	adds r4, #2
	mov r0, sp
	adds r1, r4, #0
	bl GetCameraFocusCoords
	mov r3, sp
	mov r2, sp
	ldr r0, _080864F4
	ldrb r1, [r0]
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r3]
	movs r6, #0
	ldr r0, _080864F8
	mov r8, r4
	ldrb r0, [r0]
	cmp r6, r0
	bhs _080864E2
	ldr r7, _080864FC
_080864A8:
	lsls r5, r6, #0x18
	lsrs r5, r5, #0x18
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r6, r1
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	mov r0, r8
	movs r3, #0
	ldrsh r2, [r0, r3]
	lsls r4, r6, #3
	subs r4, r4, r6
	lsls r4, r4, #2
	adds r4, r4, r7
	ldrb r3, [r4, #0x13]
	adds r0, r5, #0
	bl SpawnLinkPlayerEventObject
	ldrb r1, [r4]
	adds r0, r5, #0
	bl CreateLinkPlayerSprite
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _080864F8
	ldrb r0, [r0]
	cmp r6, r0
	blo _080864A8
_080864E2:
	bl ClearAllPlayerKeys
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080864F4: .4byte 0x03005B14
_080864F8: .4byte 0x03005B18
_080864FC: .4byte 0x020226A0
	thumb_func_end sub_08086478

	thumb_func_start CreateLinkPlayerSprites
CreateLinkPlayerSprites: @ 0x08086500
	push {r4, r5, lr}
	movs r4, #0
	ldr r0, _08086534
	ldrb r0, [r0]
	cmp r4, r0
	bhs _0808652E
	ldr r5, _08086538
_0808650E:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r4, #3
	subs r1, r1, r4
	lsls r1, r1, #2
	adds r1, r1, r5
	ldrb r1, [r1]
	bl CreateLinkPlayerSprite
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _08086534
	ldrb r0, [r0]
	cmp r4, r0
	blo _0808650E
_0808652E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08086534: .4byte 0x03005B18
_08086538: .4byte 0x020226A0
	thumb_func_end CreateLinkPlayerSprites

	thumb_func_start CB1_UpdateLinkState
CB1_UpdateLinkState: @ 0x0808653C
	push {r4, lr}
	ldr r0, _08086580
	ldrb r0, [r0]
	cmp r0, #0
	beq _08086556
	bl IsRfuRecvQueueEmpty
	cmp r0, #0
	beq _08086556
	bl IsSendingKeysToLink
	cmp r0, #0
	bne _08086578
_08086556:
	ldr r0, _08086584
	ldrb r4, [r0]
	ldr r0, _08086588
	adds r1, r4, #0
	bl UpdateAllLinkPlayers
	ldr r0, _0808658C
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl UpdateHeldKeyCode
	bl ClearAllPlayerKeys
_08086578:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086580: .4byte 0x0300319C
_08086584: .4byte 0x03005B14
_08086588: .4byte 0x030030C0
_0808658C: .4byte 0x03000E14
	thumb_func_end CB1_UpdateLinkState

	thumb_func_start ResetAllMultiplayerState
ResetAllMultiplayerState: @ 0x08086590
	push {lr}
	bl ResetAllTradingStates
	ldr r0, _080865A0
	bl SetKeyInterceptCallback
	pop {r0}
	bx r0
	.align 2, 0
_080865A0: .4byte 0x08086A15
	thumb_func_end ResetAllMultiplayerState

	thumb_func_start ClearAllPlayerKeys
ClearAllPlayerKeys: @ 0x080865A4
	@ From src/overworld.c
	push {lr}
	ldr r0, _080865B0
	bl ResetPlayerHeldKeys
	pop {r0}
	bx r0
	.align 2, 0
_080865B0: .4byte gLinkPartnersHeldKeys
	thumb_func_end ClearAllPlayerKeys

	thumb_func_start SetKeyInterceptCallback
SetKeyInterceptCallback: @ 0x080865B4
	ldr r2, _080865C0
	movs r1, #0
	strb r1, [r2]
	ldr r1, _080865C4
	str r0, [r1]
	bx lr
	.align 2, 0
_080865C0: .4byte 0x03000E19
_080865C4: .4byte 0x03000E14
	thumb_func_end SetKeyInterceptCallback

	thumb_func_start CheckRfuKeepAliveTimer
CheckRfuKeepAliveTimer: @ 0x080865C8
	push {lr}
	ldr r0, _080865EC
	ldrb r0, [r0]
	cmp r0, #0
	beq _080865E6
	ldr r1, _080865F0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3c
	bls _080865E6
	bl LinkRfu_FatalError
_080865E6:
	pop {r0}
	bx r0
	.align 2, 0
_080865EC: .4byte 0x0300319C
_080865F0: .4byte 0x03000E19
	thumb_func_end CheckRfuKeepAliveTimer

	thumb_func_start ResetAllTradingStates
ResetAllTradingStates: @ 0x080865F4
	push {lr}
	ldr r1, _08086608
	movs r2, #0x80
	adds r0, r1, #3
_080865FC:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _080865FC
	pop {r0}
	bx r0
	.align 2, 0
_08086608: .4byte 0x03000E10
	thumb_func_end ResetAllTradingStates

	thumb_func_start AreAllPlayersInTradingState
AreAllPlayersInTradingState: @ 0x0808660C
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, _0808662C
	ldrb r2, [r0]
	movs r1, #0
	cmp r1, r2
	bge _0808663A
	ldr r4, _08086630
_0808661E:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, r3
	beq _08086634
	movs r0, #0
	b _0808663C
	.align 2, 0
_0808662C: .4byte 0x03005B18
_08086630: .4byte 0x03000E10
_08086634:
	adds r1, #1
	cmp r1, r2
	blt _0808661E
_0808663A:
	movs r0, #1
_0808663C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end AreAllPlayersInTradingState

	thumb_func_start IsAnyPlayerInTradingState
IsAnyPlayerInTradingState: @ 0x08086644
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, _08086664
	ldrb r2, [r0]
	movs r1, #0
	cmp r1, r2
	bge _08086672
	ldr r4, _08086668
_08086656:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, r3
	bne _0808666C
	movs r0, #1
	b _08086674
	.align 2, 0
_08086664: .4byte 0x03005B18
_08086668: .4byte 0x03000E10
_0808666C:
	adds r1, #1
	cmp r1, r2
	blt _08086656
_08086672:
	movs r0, #0
_08086674:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end IsAnyPlayerInTradingState

	thumb_func_start HandleLinkPlayerKeyInput
HandleLinkPlayerKeyInput: @ 0x0808667C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r6, r2, #0
	mov sb, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	ldr r0, _080866CC
	adds r5, r7, r0
	ldrb r0, [r5]
	cmp r0, #0x80
	beq _0808669C
	b _08086816
_0808669C:
	adds r0, r6, #0
	bl TryGetTileEventScript
	adds r4, r0, #0
	cmp r4, #0
	beq _080866D4
	bl GetDirectionForEventScript
	mov r1, sb
	strh r0, [r1]
	movs r0, #0x81
	strb r0, [r5]
	ldrb r0, [r6, #1]
	cmp r0, #0
	bne _080866BC
	b _0808688A
_080866BC:
	ldr r0, _080866D0
	bl SetKeyInterceptCallback
	adds r0, r4, #0
	bl InitMenuBasedScript
	b _0808688A
	.align 2, 0
_080866CC: .4byte 0x03000E10
_080866D0: .4byte 0x08086A5D
_080866D4:
	movs r0, #0x83
	bl IsAnyPlayerInTradingState
	cmp r0, #1
	bne _080866FC
	movs r0, #0x81
	strb r0, [r5]
	ldrb r0, [r6, #1]
	cmp r0, #0
	bne _080866EA
	b _0808688A
_080866EA:
	ldr r0, _080866F8
	bl SetKeyInterceptCallback
	bl sub_08086EE8
	b _0808688A
	.align 2, 0
_080866F8: .4byte 0x08086A5D
_080866FC:
	mov r0, r8
	subs r0, #0x12
	cmp r0, #0xa
	bls _08086706
	b _08086816
_08086706:
	lsls r0, r0, #2
	ldr r1, _08086710
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08086710: .4byte 0x08086714
_08086714: @ jump table
	.4byte _0808676C @ case 0
	.4byte _08086816 @ case 1
	.4byte _08086816 @ case 2
	.4byte _08086816 @ case 3
	.4byte _08086816 @ case 4
	.4byte _08086816 @ case 5
	.4byte _08086740 @ case 6
	.4byte _08086798 @ case 7
	.4byte _08086816 @ case 8
	.4byte _080867C8 @ case 9
	.4byte _080867F4 @ case 10
_08086740:
	adds r0, r6, #0
	bl sub_08086CBC
	cmp r0, #0
	beq _08086816
	ldr r0, _08086764
	adds r0, r7, r0
	movs r1, #0x81
	strb r1, [r0]
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _08086816
	ldr r0, _08086768
	bl SetKeyInterceptCallback
	bl InitLinkRoomStartMenuScript
	b _08086816
	.align 2, 0
_08086764: .4byte 0x03000E10
_08086768: .4byte 0x08086A5D
_0808676C:
	adds r0, r6, #0
	bl PlayerIsAtSouthExit
	cmp r0, #1
	bne _08086816
	ldr r0, _08086790
	adds r0, r7, r0
	movs r1, #0x81
	strb r1, [r0]
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _08086816
	ldr r0, _08086794
	bl SetKeyInterceptCallback
	bl CreateConfirmLeaveTradeRoomPrompt
	b _08086816
	.align 2, 0
_08086790: .4byte 0x03000E10
_08086794: .4byte 0x08086A5D
_08086798:
	adds r0, r6, #0
	bl TryInteractWithPlayer
	adds r4, r0, #0
	cmp r4, #0
	beq _08086816
	ldr r0, _080867C0
	adds r0, r7, r0
	movs r1, #0x81
	strb r1, [r0]
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _08086816
	ldr r0, _080867C4
	bl SetKeyInterceptCallback
	adds r0, r4, #0
	bl sub_08086ECC
	b _08086816
	.align 2, 0
_080867C0: .4byte 0x03000E10
_080867C4: .4byte 0x08086A5D
_080867C8:
	adds r0, r6, #0
	bl sub_08086CA4
	cmp r0, #0
	beq _08086816
	ldr r0, _080867EC
	adds r0, r7, r0
	movs r1, #0x81
	strb r1, [r0]
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _08086816
	ldr r0, _080867F0
	bl SetKeyInterceptCallback
	bl sub_08086E74
	b _08086816
	.align 2, 0
_080867EC: .4byte 0x03000E10
_080867F0: .4byte 0x08086A81
_080867F4:
	adds r0, r6, #0
	bl sub_08086CA4
	cmp r0, #0
	beq _08086816
	ldr r0, _08086828
	adds r0, r7, r0
	movs r1, #0x81
	strb r1, [r0]
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _08086816
	ldr r0, _0808682C
	bl SetKeyInterceptCallback
	bl sub_08086E74
_08086816:
	mov r0, r8
	cmp r0, #0x17
	beq _0808683C
	cmp r0, #0x17
	bgt _08086830
	cmp r0, #0x16
	beq _0808684C
	b _0808688A
	.align 2, 0
_08086828: .4byte 0x03000E10
_0808682C: .4byte 0x08086AA5
_08086830:
	mov r1, r8
	cmp r1, #0x1a
	beq _0808685C
	cmp r1, #0x1d
	beq _0808687C
	b _0808688A
_0808683C:
	ldr r0, _08086848
	adds r0, r7, r0
	movs r1, #0x83
	strb r1, [r0]
	b _0808688A
	.align 2, 0
_08086848: .4byte 0x03000E10
_0808684C:
	ldr r0, _08086858
	adds r0, r7, r0
	movs r1, #0x82
	strb r1, [r0]
	b _0808688A
	.align 2, 0
_08086858: .4byte 0x03000E10
_0808685C:
	ldr r0, _08086874
	adds r0, r7, r0
	movs r1, #0x80
	strb r1, [r0]
	ldrb r0, [r6, #1]
	cmp r0, #0
	beq _0808688A
	ldr r0, _08086878
	bl SetKeyInterceptCallback
	b _0808688A
	.align 2, 0
_08086874: .4byte 0x03000E10
_08086878: .4byte 0x08086A15
_0808687C:
	ldr r0, _08086898
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0x82
	bne _0808688A
	movs r0, #0x81
	strb r0, [r1]
_0808688A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08086898: .4byte 0x03000E10
	thumb_func_end HandleLinkPlayerKeyInput

	thumb_func_start UpdateAllLinkPlayers
UpdateAllLinkPlayers: @ 0x0808689C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	mov r8, r1
	movs r6, #0
	add r5, sp, #0x10
	mov sb, r5
	adds r7, r0, #0
_080868B0:
	ldrb r4, [r7]
	movs r0, #0
	strh r0, [r5]
	adds r0, r6, #0
	mov r1, r8
	mov r2, sp
	bl LoadTradeRoomPlayer
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sp
	adds r3, r5, #0
	bl HandleLinkPlayerKeyInput
	ldr r0, _08086900
	adds r0, r6, r0
	ldrb r0, [r0]
	cmp r0, #0x80
	bne _080868E0
	adds r0, r4, #0
	bl GetDirectionForDpadKey
	mov r1, sb
	strh r0, [r1]
_080868E0:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r5]
	bl SetPlayerFacingDirection
	adds r7, #2
	adds r6, #1
	cmp r6, #3
	ble _080868B0
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08086900: .4byte 0x03000E10
	thumb_func_end UpdateAllLinkPlayers

	thumb_func_start UpdateHeldKeyCode
UpdateHeldKeyCode: @ 0x08086904
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r1, _0808691C
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	cmp r0, #0xc
	bhi _08086924
	ldr r0, _08086920
	strh r4, [r0]
	b _0808692A
	.align 2, 0
_0808691C: .4byte 0xFFEF0000
_08086920: .4byte 0x03005B08
_08086924:
	ldr r1, _08086968
	movs r0, #0x11
	strh r0, [r1]
_0808692A:
	ldr r0, _0808696C
	ldrb r0, [r0]
	cmp r0, #0
	beq _08086960
	bl GetLinkSendQueueLength
	cmp r0, #1
	bls _08086960
	bl IsUpdateLinkStateCBActive
	cmp r0, #1
	bne _08086960
	bl IsSendingKeysToLink
	cmp r0, #1
	bne _08086960
	cmp r4, #0x11
	blt _08086960
	cmp r4, #0x15
	ble _0808695A
	cmp r4, #0x19
	bgt _08086960
	cmp r4, #0x18
	blt _08086960
_0808695A:
	ldr r1, _08086968
	movs r0, #0
	strh r0, [r1]
_08086960:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086968: .4byte 0x03005B08
_0808696C: .4byte 0x0300319C
	thumb_func_end UpdateHeldKeyCode

	thumb_func_start KeyInterCB_ReadButtons
KeyInterCB_ReadButtons: @ 0x08086970
	push {lr}
	ldr r2, _08086984
	ldrh r1, [r2, #0x2c]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08086988
	movs r0, #0x13
	b _080869C8
	.align 2, 0
_08086984: .4byte 0x03002360
_08086988:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08086994
	movs r0, #0x12
	b _080869C8
_08086994:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080869A0
	movs r0, #0x14
	b _080869C8
_080869A0:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080869AC
	movs r0, #0x15
	b _080869C8
_080869AC:
	ldrh r1, [r2, #0x2e]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080869BA
	movs r0, #0x18
	b _080869C8
_080869BA:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080869C6
	movs r0, #0x11
	b _080869C8
_080869C6:
	movs r0, #0x19
_080869C8:
	pop {r1}
	bx r1
	thumb_func_end KeyInterCB_ReadButtons

	thumb_func_start GetDirectionForDpadKey
GetDirectionForDpadKey: @ 0x080869CC
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	cmp r0, #0x13
	beq _080869F2
	cmp r0, #0x13
	bgt _080869E2
	cmp r0, #0x12
	beq _080869F6
	b _080869FA
_080869E2:
	cmp r1, #0x14
	beq _080869EE
	cmp r1, #0x15
	bne _080869FA
	movs r0, #4
	b _080869FC
_080869EE:
	movs r0, #3
	b _080869FC
_080869F2:
	movs r0, #1
	b _080869FC
_080869F6:
	movs r0, #2
	b _080869FC
_080869FA:
	movs r0, #0
_080869FC:
	pop {r1}
	bx r1
	thumb_func_end GetDirectionForDpadKey

	thumb_func_start ResetPlayerHeldKeys
ResetPlayerHeldKeys: @ 0x08086A00
	push {lr}
	movs r2, #0x11
	adds r1, r0, #6
_08086A06:
	strh r2, [r1]
	subs r1, #2
	cmp r1, r0
	bge _08086A06
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end ResetPlayerHeldKeys

	thumb_func_start KeyInterCB_SelfIdle
KeyInterCB_SelfIdle: @ 0x08086A14
	push {r4, lr}
	adds r4, r0, #0
	bl ArePlayerFieldControlsLocked
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08086A28
	movs r0, #0x11
	b _08086A4A
_08086A28:
	bl GetLinkRecvQueueLength
	cmp r0, #4
	bls _08086A34
	movs r0, #0x1b
	b _08086A4A
_08086A34:
	bl GetLinkSendQueueLength
	cmp r0, #4
	bls _08086A40
	movs r0, #0x1c
	b _08086A4A
_08086A40:
	adds r0, r4, #0
	bl KeyInterCB_ReadButtons
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_08086A4A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end KeyInterCB_SelfIdle

	thumb_func_start sub_08086A50
sub_08086A50: @ 0x08086A50
	push {lr}
	bl CheckRfuKeepAliveTimer
	movs r0, #0x11
	pop {r1}
	bx r1
	thumb_func_end sub_08086A50

	thumb_func_start KeyInterCB_DeferToEventScript
KeyInterCB_DeferToEventScript: @ 0x08086A5C
	push {r4, lr}
	bl ArePlayerFieldControlsLocked
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r4, #0x11
	cmp r0, #1
	beq _08086A74
	movs r4, #0x1a
	ldr r0, _08086A7C
	bl SetKeyInterceptCallback
_08086A74:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08086A7C: .4byte 0x08086A51
	thumb_func_end KeyInterCB_DeferToEventScript

	thumb_func_start KeyInterCB_DeferToRecvQueue
KeyInterCB_DeferToRecvQueue: @ 0x08086A80
	push {r4, lr}
	bl GetLinkRecvQueueLength
	movs r4, #0x11
	cmp r0, #2
	bhi _08086A98
	movs r4, #0x1a
	bl UnlockPlayerFieldControls
	ldr r0, _08086AA0
	bl SetKeyInterceptCallback
_08086A98:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08086AA0: .4byte 0x08086A51
	thumb_func_end KeyInterCB_DeferToRecvQueue

	thumb_func_start KeyInterCB_DeferToSendQueue
KeyInterCB_DeferToSendQueue: @ 0x08086AA4
	push {r4, lr}
	bl GetLinkSendQueueLength
	movs r4, #0x11
	cmp r0, #2
	bhi _08086ABC
	movs r4, #0x1a
	bl UnlockPlayerFieldControls
	ldr r0, _08086AC4
	bl SetKeyInterceptCallback
_08086ABC:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08086AC4: .4byte 0x08086A51
	thumb_func_end KeyInterCB_DeferToSendQueue

	thumb_func_start KeyInterCB_DoNothingAndKeepAlive
KeyInterCB_DoNothingAndKeepAlive: @ 0x08086AC8
	push {lr}
	bl CheckRfuKeepAliveTimer
	movs r0, #0x11
	pop {r1}
	bx r1
	thumb_func_end KeyInterCB_DoNothingAndKeepAlive

	thumb_func_start sub_08086AD4
sub_08086AD4: @ 0x08086AD4
	push {lr}
	ldr r1, _08086AF8
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x82
	bne _08086B04
	ldr r0, _08086AFC
	ldrh r1, [r0, #0x2e]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08086B08
	ldr r0, _08086B00
	bl SetKeyInterceptCallback
	movs r0, #0x1d
	b _08086B0A
	.align 2, 0
_08086AF8: .4byte 0x03000E10
_08086AFC: .4byte 0x03002360
_08086B00: .4byte 0x08086AC9
_08086B04:
	bl CheckRfuKeepAliveTimer
_08086B08:
	movs r0, #0x11
_08086B0A:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08086AD4

	thumb_func_start sub_08086B10
sub_08086B10: @ 0x08086B10
	push {lr}
	ldr r0, _08086B20
	bl SetKeyInterceptCallback
	movs r0, #0x16
	pop {r1}
	bx r1
	.align 2, 0
_08086B20: .4byte 0x08086AD5
	thumb_func_end sub_08086B10

	thumb_func_start KeyInterCB_SendNothing_2
KeyInterCB_SendNothing_2: @ 0x08086B24
	movs r0, #0x11
	bx lr
	thumb_func_end KeyInterCB_SendNothing_2

	thumb_func_start KeyInterCB_WaitForPlayersToExit
KeyInterCB_WaitForPlayersToExit: @ 0x08086B28
	push {lr}
	ldr r1, _08086B54
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x83
	beq _08086B38
	bl CheckRfuKeepAliveTimer
_08086B38:
	movs r0, #0x83
	bl AreAllPlayersInTradingState
	cmp r0, #1
	bne _08086B4E
	ldr r0, _08086B58
	bl ScriptContext_SetupScript
	ldr r0, _08086B5C
	bl SetKeyInterceptCallback
_08086B4E:
	movs r0, #0x11
	pop {r1}
	bx r1
	.align 2, 0
_08086B54: .4byte 0x03000E10
_08086B58: .4byte 0x082471F2
_08086B5C: .4byte 0x08086B25
	thumb_func_end KeyInterCB_WaitForPlayersToExit

	thumb_func_start KeyInterCB_SendExitRoomKey
KeyInterCB_SendExitRoomKey: @ 0x08086B60
	push {lr}
	ldr r0, _08086B70
	bl SetKeyInterceptCallback
	movs r0, #0x17
	pop {r1}
	bx r1
	.align 2, 0
_08086B70: .4byte 0x08086B29
	thumb_func_end KeyInterCB_SendExitRoomKey

	thumb_func_start KeyInterCB_SendNothing
KeyInterCB_SendNothing: @ 0x08086B74
	movs r0, #0x11
	bx lr
	thumb_func_end KeyInterCB_SendNothing

	thumb_func_start sub_08086B78
sub_08086B78: @ 0x08086B78
	push {lr}
	movs r0, #0x83
	bl IsAnyPlayerInTradingState
	cmp r0, #1
	beq _08086BB4
	ldr r0, _08086BB8
	ldr r2, [r0]
	ldr r1, _08086BBC
	adds r3, r0, #0
	cmp r2, r1
	bne _08086B9E
	ldr r1, _08086BC0
	ldr r0, _08086BC4
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x82
	bne _08086BD6
_08086B9E:
	ldr r1, [r3]
	ldr r0, _08086BC8
	cmp r1, r0
	bne _08086BCC
	ldr r1, _08086BC0
	ldr r0, _08086BC4
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x81
	bne _08086BCC
_08086BB4:
	movs r0, #2
	b _08086BDC
	.align 2, 0
_08086BB8: .4byte 0x03000E14
_08086BBC: .4byte 0x08086AD5
_08086BC0: .4byte 0x03000E10
_08086BC4: .4byte 0x03005B14
_08086BC8: .4byte 0x08086AC9
_08086BCC:
	movs r0, #0x82
	bl AreAllPlayersInTradingState
	cmp r0, #0
	bne _08086BDA
_08086BD6:
	movs r0, #0
	b _08086BDC
_08086BDA:
	movs r0, #1
_08086BDC:
	pop {r1}
	bx r1
	thumb_func_end sub_08086B78

	thumb_func_start sub_08086BE0
sub_08086BE0: @ 0x08086BE0
	push {lr}
	movs r0, #0x83
	bl IsAnyPlayerInTradingState
	pop {r1}
	bx r1
	thumb_func_end sub_08086BE0

	thumb_func_start sub_08086BEC
sub_08086BEC: @ 0x08086BEC
	push {lr}
	ldr r0, _08086BFC
	bl SetKeyInterceptCallback
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08086BFC: .4byte 0x08086B11
	thumb_func_end sub_08086BEC

	thumb_func_start sub_08086C00
sub_08086C00: @ 0x08086C00
	push {lr}
	ldr r0, _08086C10
	bl SetKeyInterceptCallback
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08086C10: .4byte 0x08086A5D
	thumb_func_end sub_08086C00

	thumb_func_start QueueExitLinkRoomKey
QueueExitLinkRoomKey: @ 0x08086C14
	push {lr}
	ldr r0, _08086C24
	bl SetKeyInterceptCallback
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08086C24: .4byte 0x08086B61
	thumb_func_end QueueExitLinkRoomKey

	thumb_func_start sub_08086C28
sub_08086C28: @ 0x08086C28
	push {lr}
	ldr r0, _08086C38
	bl SetKeyInterceptCallback
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08086C38: .4byte 0x08086B75
	thumb_func_end sub_08086C28

	thumb_func_start LoadTradeRoomPlayer
LoadTradeRoomPlayer: @ 0x08086C3C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r2, #0
	strb r4, [r6]
	movs r0, #0
	cmp r4, r1
	bne _08086C4E
	movs r0, #1
_08086C4E:
	strb r0, [r6, #1]
	ldr r1, _08086CA0
	lsls r0, r4, #2
	adds r0, r0, r1
	ldrb r0, [r0, #3]
	strb r0, [r6, #2]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	bl GetLinkPlayerFacingDirection
	strb r0, [r6, #3]
	mov r5, sp
	adds r5, #2
	adds r0, r4, #0
	mov r1, sp
	adds r2, r5, #0
	bl GetLinkPlayerCoords
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r6, #4]
	ldrh r0, [r5]
	strh r0, [r6, #6]
	adds r0, r4, #0
	bl GetLinkPlayerElevation
	strb r0, [r6, #8]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0
	ldrsh r1, [r5, r2]
	bl MapGridGetMetatileBehaviorAt
	strh r0, [r6, #0xc]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08086CA0: .4byte 0x02031FA8
	thumb_func_end LoadTradeRoomPlayer

	thumb_func_start sub_08086CA4
sub_08086CA4: @ 0x08086CA4
	push {lr}
	ldrb r0, [r0, #2]
	cmp r0, #2
	beq _08086CB0
	cmp r0, #0
	bne _08086CB4
_08086CB0:
	movs r0, #1
	b _08086CB6
_08086CB4:
	movs r0, #0
_08086CB6:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08086CA4

	thumb_func_start sub_08086CBC
sub_08086CBC: @ 0x08086CBC
	push {lr}
	ldrb r0, [r0, #2]
	cmp r0, #2
	beq _08086CC8
	cmp r0, #0
	bne _08086CCC
_08086CC8:
	movs r0, #1
	b _08086CCE
_08086CCC:
	movs r0, #0
_08086CCE:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08086CBC

	thumb_func_start TryGetTileEventScript
TryGetTileEventScript: @ 0x08086CD4
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #2]
	cmp r0, #2
	bne _08086CE6
	adds r0, r1, #4
	bl GetCoordEventScriptAtMapPosition
	b _08086CE8
_08086CE6:
	movs r0, #0
_08086CE8:
	pop {r1}
	bx r1
	thumb_func_end TryGetTileEventScript

	thumb_func_start PlayerIsAtSouthExit
PlayerIsAtSouthExit: @ 0x08086CEC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #2
	beq _08086CFA
	cmp r0, #0
	bne _08086D10
_08086CFA:
	ldrb r0, [r4, #0xc]
	bl MetatileBehavior_IsSouthArrowWarp
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08086D10
	ldrb r0, [r4, #3]
	cmp r0, #1
	bne _08086D10
	movs r0, #1
	b _08086D12
_08086D10:
	movs r0, #0
_08086D12:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end PlayerIsAtSouthExit

	thumb_func_start TryInteractWithPlayer
TryInteractWithPlayer: @ 0x08086D18
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _08086D2C
	cmp r0, #2
	beq _08086D2C
	movs r0, #0
	b _08086DDA
_08086D2C:
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r3, _08086D9C
	ldrb r0, [r4, #3]
	lsls r0, r0, #3
	adds r0, r0, r3
	ldr r0, [r0]
	mov r1, sp
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08086DA0
	ldr r2, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	asrs r1, r2, #0x10
	ldrb r0, [r4, #3]
	lsls r0, r0, #3
	adds r3, #4
	adds r0, r0, r3
	ldr r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _08086DA4
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldr r2, _08086DA8
	ldr r0, [sp, #4]
	ands r0, r2
	str r0, [sp, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	asrs r1, r1, #0x10
	bl GetLinkPlayerIdAt
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r2, r1, #0
	cmp r1, #4
	beq _08086DD0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08086D98
	ldr r0, _08086DAC
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, #0x80
	beq _08086DB4
_08086D98:
	ldr r0, _08086DB0
	b _08086DDA
	.align 2, 0
_08086D9C: .4byte 0x0830FCB0
_08086DA0: .4byte 0xFFFF0000
_08086DA4: .4byte 0x0000FFFF
_08086DA8: .4byte 0xFFFFFF00
_08086DAC: .4byte 0x03000E10
_08086DB0: .4byte 0x0824717B
_08086DB4:
	adds r0, r2, #0
	bl GetLinkTrainerCardColor
	cmp r0, #0
	bne _08086DC8
	ldr r0, _08086DC4
	b _08086DDA
	.align 2, 0
_08086DC4: .4byte 0x0824715D
_08086DC8:
	ldr r0, _08086DCC
	b _08086DDA
	.align 2, 0
_08086DCC: .4byte 0x0824716C
_08086DD0:
	ldrb r1, [r4, #0xc]
	ldrb r2, [r4, #3]
	mov r0, sp
	bl GetInteractedLinkPlayerScript
_08086DDA:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end TryInteractWithPlayer

	thumb_func_start GetDirectionForEventScript
GetDirectionForEventScript: @ 0x08086DE4
	push {lr}
	adds r1, r0, #0
	ldr r0, _08086E30
	cmp r1, r0
	beq _08086E2A
	ldr r0, _08086E34
	cmp r1, r0
	beq _08086E6C
	ldr r0, _08086E38
	cmp r1, r0
	beq _08086E2A
	ldr r0, _08086E3C
	cmp r1, r0
	beq _08086E6C
	ldr r0, _08086E40
	cmp r1, r0
	beq _08086E2A
	ldr r0, _08086E44
	cmp r1, r0
	beq _08086E6C
	ldr r0, _08086E48
	cmp r1, r0
	beq _08086E2A
	ldr r0, _08086E4C
	cmp r1, r0
	beq _08086E6C
	ldr r0, _08086E50
	cmp r1, r0
	beq _08086E2A
	ldr r0, _08086E54
	cmp r1, r0
	beq _08086E6C
	ldr r0, _08086E58
	cmp r1, r0
	bne _08086E5C
_08086E2A:
	movs r0, #0xa
	b _08086E6E
	.align 2, 0
_08086E30: .4byte 0x08247067
_08086E34: .4byte 0x08247082
_08086E38: .4byte 0x0824709D
_08086E3C: .4byte 0x082470B8
_08086E40: .4byte 0x082470FC
_08086E44: .4byte 0x08247111
_08086E48: .4byte 0x08247126
_08086E4C: .4byte 0x0824713B
_08086E50: .4byte 0x08247053
_08086E54: .4byte 0x0824705D
_08086E58: .4byte 0x082470D4
_08086E5C:
	ldr r0, _08086E68
	cmp r1, r0
	beq _08086E6C
	movs r0, #0
	b _08086E6E
	.align 2, 0
_08086E68: .4byte 0x082470DE
_08086E6C:
	movs r0, #9
_08086E6E:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetDirectionForEventScript

	thumb_func_start sub_08086E74
sub_08086E74: @ 0x08086E74
	push {lr}
	bl LockPlayerFieldControls
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08086E74

	thumb_func_start InitLinkRoomStartMenuScript
InitLinkRoomStartMenuScript: @ 0x08086E80
	push {lr}
	movs r0, #6
	bl PlaySE
	bl ShowStartMenu
	bl LockPlayerFieldControls
	pop {r0}
	bx r0
	thumb_func_end InitLinkRoomStartMenuScript

	thumb_func_start InitMenuBasedScript
InitMenuBasedScript: @ 0x08086E94
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #5
	bl PlaySE
	adds r0, r4, #0
	bl ScriptContext_SetupScript
	bl LockPlayerFieldControls
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end InitMenuBasedScript

	thumb_func_start CreateConfirmLeaveTradeRoomPrompt
CreateConfirmLeaveTradeRoomPrompt: @ 0x08086EB0
	push {lr}
	movs r0, #6
	bl PlaySE
	ldr r0, _08086EC8
	bl ScriptContext_SetupScript
	bl LockPlayerFieldControls
	pop {r0}
	bx r0
	.align 2, 0
_08086EC8: .4byte 0x082471CE
	thumb_func_end CreateConfirmLeaveTradeRoomPrompt

	thumb_func_start sub_08086ECC
sub_08086ECC: @ 0x08086ECC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #5
	bl PlaySE
	adds r0, r4, #0
	bl ScriptContext_SetupScript
	bl LockPlayerFieldControls
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08086ECC

	thumb_func_start sub_08086EE8
sub_08086EE8: @ 0x08086EE8
	push {lr}
	ldr r0, _08086EF8
	bl ScriptContext_SetupScript
	bl LockPlayerFieldControls
	pop {r0}
	bx r0
	.align 2, 0
_08086EF8: .4byte 0x082471E8
	thumb_func_end sub_08086EE8

	thumb_func_start sub_08086EFC
sub_08086EFC: @ 0x08086EFC
	push {lr}
	bl IsUpdateLinkStateCBActive
	cmp r0, #0
	bne _08086F0A
	movs r0, #0
	b _08086F24
_08086F0A:
	bl GetLinkRecvQueueLength
	cmp r0, #2
	bls _08086F1C
	ldr r1, _08086F18
	movs r0, #1
	b _08086F20
	.align 2, 0
_08086F18: .4byte 0x03000E18
_08086F1C:
	ldr r1, _08086F28
	movs r0, #0
_08086F20:
	strb r0, [r1]
	ldrb r0, [r1]
_08086F24:
	pop {r1}
	bx r1
	.align 2, 0
_08086F28: .4byte 0x03000E18
	thumb_func_end sub_08086EFC

	thumb_func_start Overworld_RecvKeysFromLinkIsRunning
Overworld_RecvKeysFromLinkIsRunning: @ 0x08086F2C
	push {lr}
	bl GetLinkRecvQueueLength
	cmp r0, #1
	bls _08086F90
	bl IsUpdateLinkStateCBActive
	cmp r0, #1
	bne _08086F90
	bl IsSendingKeysToLink
	cmp r0, #1
	bne _08086F90
	ldr r0, _08086F7C
	ldr r1, [r0]
	ldr r0, _08086F80
	cmp r1, r0
	beq _08086F78
	ldr r0, _08086F84
	cmp r1, r0
	bne _08086F90
	ldr r0, _08086F88
	ldrb r2, [r0]
	movs r1, #0
	strb r1, [r0]
	cmp r2, #1
	beq _08086F78
	ldr r2, _08086F8C
	ldrb r1, [r2, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08086F90
	ldrb r1, [r2, #0xa]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08086F90
_08086F78:
	movs r0, #1
	b _08086F92
	.align 2, 0
_08086F7C: .4byte 0x03000E14
_08086F80: .4byte 0x08086A81
_08086F84: .4byte 0x08086A5D
_08086F88: .4byte 0x03000E18
_08086F8C: .4byte 0x02037C74
_08086F90:
	movs r0, #0
_08086F92:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end Overworld_RecvKeysFromLinkIsRunning

	thumb_func_start Overworld_SendKeysToLinkIsRunning
Overworld_SendKeysToLinkIsRunning: @ 0x08086F98
	push {lr}
	bl GetLinkSendQueueLength
	cmp r0, #1
	bls _08086FBC
	bl IsUpdateLinkStateCBActive
	cmp r0, #1
	bne _08086FBC
	bl IsSendingKeysToLink
	cmp r0, #1
	bne _08086FBC
	ldr r0, _08086FC0
	ldr r1, [r0]
	ldr r0, _08086FC4
	cmp r1, r0
	beq _08086FC8
_08086FBC:
	movs r0, #0
	b _08086FCA
	.align 2, 0
_08086FC0: .4byte 0x03000E14
_08086FC4: .4byte 0x08086AA5
_08086FC8:
	movs r0, #1
_08086FCA:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end Overworld_SendKeysToLinkIsRunning

	thumb_func_start IsSendingKeysOverCable
IsSendingKeysOverCable: @ 0x08086FD0
	push {lr}
	ldr r0, _08086FE8
	ldrb r0, [r0]
	cmp r0, #0
	bne _08086FEC
	bl IsSendingKeysToLink
	cmp r0, #0
	beq _08086FEC
	movs r0, #1
	b _08086FEE
	.align 2, 0
_08086FE8: .4byte 0x0300319C
_08086FEC:
	movs r0, #0
_08086FEE:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end IsSendingKeysOverCable

	thumb_func_start GetLinkSendQueueLength
GetLinkSendQueueLength: @ 0x08086FF4
	push {lr}
	ldr r0, _08087008
	ldrb r0, [r0]
	cmp r0, #0
	bne _08087014
	ldr r0, _0808700C
	ldr r1, _08087010
	adds r0, r0, r1
	ldrb r0, [r0]
	b _0808701C
	.align 2, 0
_08087008: .4byte 0x0300319C
_0808700C: .4byte 0x03003210
_08087010: .4byte 0x00000339
_08087014:
	ldr r0, _08087020
	ldr r1, _08087024
	adds r0, r0, r1
	ldrb r0, [r0]
_0808701C:
	pop {r1}
	bx r1
	.align 2, 0
_08087020: .4byte 0x030050A0
_08087024: .4byte 0x000008D2
	thumb_func_end GetLinkSendQueueLength

	thumb_func_start ZeroLinkPlayerObjectEvent
ZeroLinkPlayerObjectEvent: @ 0x08087028
	@ From src/overworld.c (ZeroLinkPlayerObjectEvent)
	movs r1, #0
	str r1, [r0]
	bx lr
	.align 2, 0
	thumb_func_end ZeroLinkPlayerObjectEvent

	thumb_func_start ClearLinkPlayerEventObjects
ClearLinkPlayerEventObjects: @ 0x08087030
	push {lr}
	ldr r0, _08087040
	movs r1, #0
	movs r2, #0x10
	bl memset
	pop {r0}
	bx r0
	.align 2, 0
_08087040: .4byte 0x02031FA8
	thumb_func_end ClearLinkPlayerEventObjects

	thumb_func_start ZeroEventObject
ZeroEventObject: @ 0x08087044
	push {lr}
	movs r1, #0
	movs r2, #0x24
	bl memset
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end ZeroEventObject

	thumb_func_start SpawnLinkPlayerEventObject
SpawnLinkPlayerEventObject: @ 0x08087054
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r1
	mov sl, r2
	mov r8, r3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	mov r0, sb
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r1, sl
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	mov r2, r8
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	bl GetFirstInactiveEventObjectId
	adds r6, r0, #0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r4, r7, #2
	ldr r0, _080870F8
	adds r4, r4, r0
	lsls r5, r6, #3
	adds r5, r5, r6
	lsls r5, r5, #2
	ldr r0, _080870FC
	adds r5, r5, r0
	adds r0, r4, #0
	bl ZeroLinkPlayerObjectEvent
	adds r0, r5, #0
	bl ZeroEventObject
	movs r2, #0
	movs r1, #1
	movs r0, #1
	strb r0, [r4]
	strb r7, [r4, #1]
	strb r6, [r4, #2]
	strb r2, [r4, #3]
	ldrb r0, [r5]
	orrs r0, r1
	mov r2, r8
	ands r2, r1
	lsls r2, r2, #1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	movs r0, #2
	strb r0, [r5, #0x19]
	movs r0, #0x40
	strb r0, [r5, #4]
	mov r0, sb
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov sb, r0
	mov r1, sl
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	mov sl, r1
	adds r0, r5, #0
	mov r1, sb
	mov r2, sl
	bl InitLinkPlayerEventObjectPos
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080870F8: .4byte 0x02031FA8
_080870FC: .4byte 0x02036FF0
	thumb_func_end SpawnLinkPlayerEventObject

	thumb_func_start InitLinkPlayerEventObjectPos
InitLinkPlayerEventObjectPos: @ 0x08087100
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	adds r1, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	strh r0, [r4, #0x10]
	strh r1, [r4, #0x12]
	strh r0, [r4, #0x14]
	strh r1, [r4, #0x16]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r2, r4, #0
	adds r2, #0xc
	adds r3, r4, #0
	adds r3, #0xe
	bl SetSpritePosToMapCoords
	ldrh r0, [r4, #0xc]
	adds r0, #8
	strh r0, [r4, #0xc]
	adds r0, r4, #0
	bl EventObjectUpdateZCoord
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end InitLinkPlayerEventObjectPos

	thumb_func_start sub_08087140
sub_08087140: @ 0x08087140
	push {lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	ldr r1, _08087168
	lsrs r0, r0, #0x16
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _08087162
	ldrb r0, [r1, #2]
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0808716C
	adds r1, r1, r0
	strb r2, [r1, #0x19]
_08087162:
	pop {r0}
	bx r0
	.align 2, 0
_08087168: .4byte 0x02031FA8
_0808716C: .4byte 0x02036FF0
	thumb_func_end sub_08087140

	thumb_func_start sub_08087170
sub_08087170: @ 0x08087170
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	ldr r1, _080871B0
	adds r5, r0, r1
	ldrb r1, [r5, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080871B4
	adds r4, r0, r1
	ldrb r0, [r4, #4]
	cmp r0, #0x40
	beq _0808719C
	adds r1, r0, #0
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080871B8
	adds r0, r0, r1
	bl DestroySprite
_0808719C:
	movs r0, #0
	strb r0, [r5]
	ldrb r1, [r4]
	subs r0, #2
	ands r0, r1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080871B0: .4byte 0x02031FA8
_080871B4: .4byte 0x02036FF0
_080871B8: .4byte 0x020205AC
	thumb_func_end sub_08087170

	thumb_func_start GetSpriteForLinkedPlayer
GetSpriteForLinkedPlayer: @ 0x080871BC
	lsls r0, r0, #0x18
	ldr r1, _080871D4
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080871D8
	adds r0, r0, r1
	ldrb r0, [r0, #4]
	bx lr
	.align 2, 0
_080871D4: .4byte 0x02031FA8
_080871D8: .4byte 0x02036FF0
	thumb_func_end GetSpriteForLinkedPlayer

	thumb_func_start GetLinkPlayerCoords
GetLinkPlayerCoords: @ 0x080871DC
	lsls r0, r0, #0x18
	ldr r3, _080871FC
	lsrs r0, r0, #0x16
	adds r0, r0, r3
	ldrb r3, [r0, #2]
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r0, r0, #2
	ldr r3, _08087200
	adds r0, r0, r3
	ldrh r3, [r0, #0x10]
	strh r3, [r1]
	ldrh r0, [r0, #0x12]
	strh r0, [r2]
	bx lr
	.align 2, 0
_080871FC: .4byte 0x02031FA8
_08087200: .4byte 0x02036FF0
	thumb_func_end GetLinkPlayerCoords

	thumb_func_start GetLinkPlayerFacingDirection
GetLinkPlayerFacingDirection: @ 0x08087204
	lsls r0, r0, #0x18
	ldr r1, _0808721C
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087220
	adds r0, r0, r1
	ldrb r0, [r0, #0x19]
	bx lr
	.align 2, 0
_0808721C: .4byte 0x02031FA8
_08087220: .4byte 0x02036FF0
	thumb_func_end GetLinkPlayerFacingDirection

	thumb_func_start GetLinkPlayerElevation
GetLinkPlayerElevation: @ 0x08087224
	lsls r0, r0, #0x18
	ldr r1, _08087240
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087244
	adds r0, r0, r1
	ldrb r0, [r0, #0xb]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	bx lr
	.align 2, 0
_08087240: .4byte 0x02031FA8
_08087244: .4byte 0x02036FF0
	thumb_func_end GetLinkPlayerElevation

	thumb_func_start sub_08087248
sub_08087248: @ 0x08087248
	lsls r0, r0, #0x18
	ldr r1, _08087268
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r1, [r0, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0808726C
	adds r0, r0, r1
	adds r0, #0x21
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x10
	subs r0, r0, r1
	bx lr
	.align 2, 0
_08087268: .4byte 0x02031FA8
_0808726C: .4byte 0x02036FF0
	thumb_func_end sub_08087248

	thumb_func_start GetLinkPlayerIdAt
GetLinkPlayerIdAt: @ 0x08087270
	push {r4, r5, r6, lr}
	movs r2, #0
	ldr r5, _080872B4
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	lsls r1, r1, #0x10
	asrs r3, r1, #0x10
_0808727E:
	lsls r0, r2, #2
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, #0
	beq _080872BC
	ldrb r0, [r1, #3]
	cmp r0, #0
	beq _08087292
	cmp r0, #2
	bne _080872BC
_08087292:
	ldrb r1, [r1, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080872B8
	adds r1, r0, r1
	movs r6, #0x10
	ldrsh r0, [r1, r6]
	cmp r0, r4
	bne _080872BC
	movs r6, #0x12
	ldrsh r0, [r1, r6]
	cmp r0, r3
	bne _080872BC
	adds r0, r2, #0
	b _080872C8
	.align 2, 0
_080872B4: .4byte 0x02031FA8
_080872B8: .4byte 0x02036FF0
_080872BC:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _0808727E
	movs r0, #4
_080872C8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetLinkPlayerIdAt

	thumb_func_start SetPlayerFacingDirection
SetPlayerFacingDirection: @ 0x080872D0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	adds r2, r3, #0
	lsrs r0, r0, #0x16
	ldr r1, _08087300
	adds r5, r0, r1
	ldrb r1, [r5, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087304
	adds r6, r0, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _0808732C
	cmp r3, #0xa
	bls _08087308
	ldrb r0, [r6]
	movs r1, #4
	orrs r0, r1
	strb r0, [r6]
	b _0808732C
	.align 2, 0
_08087300: .4byte 0x02031FA8
_08087304: .4byte 0x02036FF0
_08087308:
	ldr r4, _08087334
	ldr r1, _08087338
	ldrb r0, [r5, #3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r0, r4
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r2
_0808732C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08087334: .4byte 0x0830FD4C
_08087338: .4byte 0x0830FD14
	thumb_func_end SetPlayerFacingDirection

	thumb_func_start MovementEventModeCB_Normal
MovementEventModeCB_Normal: @ 0x0808733C
	push {r4, lr}
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r4, _08087358
	lsls r3, r2, #2
	adds r3, r3, r4
	ldr r3, [r3]
	bl _call_via_r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08087358: .4byte 0x0830FD20
	thumb_func_end MovementEventModeCB_Normal

	thumb_func_start MovementEventModeCB_Ignored
MovementEventModeCB_Ignored: @ 0x0808735C
	movs r0, #1
	bx lr
	thumb_func_end MovementEventModeCB_Ignored

	thumb_func_start MovementEventModeCB_Normal_2
MovementEventModeCB_Normal_2: @ 0x08087360
	push {r4, lr}
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r4, _0808737C
	lsls r3, r2, #2
	adds r3, r3, r4
	ldr r3, [r3]
	bl _call_via_r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0808737C: .4byte 0x0830FD20
	thumb_func_end MovementEventModeCB_Normal_2

	thumb_func_start FacingHandler_DoNothing
FacingHandler_DoNothing: @ 0x08087380
	movs r0, #0
	bx lr
	thumb_func_end FacingHandler_DoNothing

	thumb_func_start FacingHandler_DpadMovement
FacingHandler_DpadMovement: @ 0x08087384
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r5, #0x19]
	bl FlipVerticalAndClearForced
	strb r0, [r5, #0x19]
	ldrb r1, [r5, #0x19]
	mov r6, sp
	adds r6, #2
	adds r0, r5, #0
	mov r2, sp
	adds r3, r6, #0
	bl EventObjectMoveDestCoords
	ldrb r0, [r4, #2]
	ldrb r1, [r5, #0x19]
	mov r2, sp
	movs r3, #0
	ldrsh r2, [r2, r3]
	movs r4, #0
	ldrsh r3, [r6, r4]
	bl LinkPlayerDetectCollision
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080873E2
	adds r1, r5, #0
	adds r1, #0x21
	movs r0, #0x10
	strb r0, [r1]
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0
	ldrsh r2, [r6, r3]
	adds r0, r5, #0
	bl ShiftEventObjectCoords
	adds r0, r5, #0
	bl EventObjectUpdateZCoord
	movs r0, #1
	b _080873E4
_080873E2:
	movs r0, #0
_080873E4:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end FacingHandler_DpadMovement

	thumb_func_start FacingHandler_ForcedFacingChange
FacingHandler_ForcedFacingChange: @ 0x080873EC
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4, #0x19]
	bl FlipVerticalAndClearForced
	strb r0, [r4, #0x19]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end FacingHandler_ForcedFacingChange

	thumb_func_start MovementStatusHandler_EnterFreeMode
MovementStatusHandler_EnterFreeMode: @ 0x08087404
	@ From src/overworld.c
	movs r1, #0
	strb r1, [r0, #3]
	bx lr
	.align 2, 0
	thumb_func_end MovementStatusHandler_EnterFreeMode

	thumb_func_start MovementStatusHandler_TryAdvanceScript
MovementStatusHandler_TryAdvanceScript: @ 0x0808740C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x21
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	movs r0, #1
	strb r0, [r6, #3]
	ldrb r0, [r4, #0x19]
	adds r1, #0xc
	adds r2, r4, #0
	adds r2, #0xe
	bl MoveCoords
	ldrb r0, [r5]
	cmp r0, #0
	bne _0808743C
	adds r0, r4, #0
	bl ShiftStillEventObjectCoords
	movs r0, #2
	strb r0, [r6, #3]
_0808743C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end MovementStatusHandler_TryAdvanceScript

	thumb_func_start FlipVerticalAndClearForced
FlipVerticalAndClearForced: @ 0x08087444
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	subs r0, #1
	cmp r0, #9
	bhi _0808749C
	lsls r0, r0, #2
	ldr r1, _08087460
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08087460: .4byte 0x08087464
_08087464: @ jump table
	.4byte _0808748C @ case 0
	.4byte _08087490 @ case 1
	.4byte _08087494 @ case 2
	.4byte _08087498 @ case 3
	.4byte _0808749C @ case 4
	.4byte _0808749C @ case 5
	.4byte _0808748C @ case 6
	.4byte _08087490 @ case 7
	.4byte _08087494 @ case 8
	.4byte _08087498 @ case 9
_0808748C:
	movs r0, #2
	b _0808749E
_08087490:
	movs r0, #1
	b _0808749E
_08087494:
	movs r0, #3
	b _0808749E
_08087498:
	movs r0, #4
	b _0808749E
_0808749C:
	adds r0, r2, #0
_0808749E:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end FlipVerticalAndClearForced

	thumb_func_start LinkPlayerDetectCollision
LinkPlayerDetectCollision: @ 0x080874A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov ip, r2
	lsls r3, r3, #0x10
	movs r4, #0
	ldr r0, _08087508
	mov sb, r0
	lsrs r2, r3, #0x10
	mov sl, r2
	asrs r6, r3, #0x10
_080874C8:
	mov r7, ip
	lsls r3, r7, #0x10
	mov r0, sl
	lsls r5, r0, #0x10
	cmp r4, r8
	beq _0808750C
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	mov r2, sb
	adds r1, r0, r2
	movs r7, #0x10
	ldrsh r0, [r1, r7]
	asrs r2, r3, #0x10
	cmp r0, r2
	bne _080874F0
	movs r7, #0x12
	ldrsh r0, [r1, r7]
	cmp r0, r6
	beq _08087502
_080874F0:
	movs r7, #0x14
	ldrsh r0, [r1, r7]
	cmp r0, r2
	bne _0808750C
	movs r0, #0x16
	ldrsh r1, [r1, r0]
	asrs r0, r5, #0x10
	cmp r1, r0
	bne _0808750C
_08087502:
	movs r0, #1
	b _08087522
	.align 2, 0
_08087508: .4byte 0x02036FF0
_0808750C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xf
	bls _080874C8
	asrs r0, r3, #0x10
	asrs r1, r5, #0x10
	bl MapGridGetCollisionAt
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08087522:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end LinkPlayerDetectCollision

	thumb_func_start CreateLinkPlayerSprite
CreateLinkPlayerSprite: @ 0x08087530
	push {r4, r5, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	lsls r2, r5, #2
	ldr r0, _08087564
	adds r2, r2, r0
	ldrb r1, [r2, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087568
	adds r4, r0, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080875DE
	subs r0, r3, #1
	cmp r0, #4
	bhi _080875BA
	lsls r0, r0, #2
	ldr r1, _0808756C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08087564: .4byte 0x02031FA8
_08087568: .4byte 0x02036FF0
_0808756C: .4byte 0x08087570
_08087570: @ jump table
	.4byte _08087590 @ case 0
	.4byte _08087590 @ case 1
	.4byte _0808759C @ case 2
	.4byte _08087584 @ case 3
	.4byte _08087584 @ case 4
_08087584:
	ldrb r0, [r4]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1f
	bl sub_0808B6D0
	b _080875A8
_08087590:
	ldrb r0, [r4]
	lsls r0, r0, #0x1e
	lsrs r0, r0, #0x1f
	bl GetFRLGAvatarGraphicsIdByGender
	b _080875A8
_0808759C:
	ldrb r1, [r4]
	lsls r1, r1, #0x1e
	lsrs r1, r1, #0x1f
	movs r0, #0
	bl GetPlayerAvatarGraphicsIdByStateIdAndGender
_080875A8:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080875E8
	movs r2, #0
	str r2, [sp]
	movs r3, #0
	bl AddPseudoEventObject
	strb r0, [r4, #4]
_080875BA:
	ldrb r1, [r4, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080875EC
	adds r0, r0, r1
	adds r3, r0, #0
	adds r3, #0x3e
	ldrb r1, [r3]
	movs r2, #2
	orrs r1, r2
	strb r1, [r3]
	strh r5, [r0, #0x2e]
	ldrb r1, [r4]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4]
_080875DE:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080875E8: .4byte 0x080875F1
_080875EC: .4byte 0x020205AC
	thumb_func_end CreateLinkPlayerSprite

	thumb_func_start SpriteCB_LinkPlayer
SpriteCB_LinkPlayer: @ 0x080875F0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x2e
	ldrsh r4, [r5, r0]
	lsls r4, r4, #2
	ldr r0, _08087654
	adds r4, r4, r0
	ldrb r1, [r4, #2]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08087658
	adds r6, r0, r1
	ldrh r0, [r6, #0xc]
	strh r0, [r5, #0x20]
	ldrh r0, [r6, #0xe]
	strh r0, [r5, #0x22]
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #4
	adds r1, r5, #0
	movs r2, #1
	bl SetObjectSubpriorityByElevation
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #4
	bl ElevationToPriority
	movs r1, #3
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r5, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r5, #5]
	ldrb r0, [r4, #3]
	cmp r0, #0
	bne _0808765C
	ldrb r0, [r6, #0x19]
	bl GetJumpInPlaceMovementAction
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl StartSpriteAnim
	b _0808766E
	.align 2, 0
_08087654: .4byte 0x02031FA8
_08087658: .4byte 0x02036FF0
_0808765C:
	ldrb r0, [r6, #0x19]
	bl GetJumpInPlaceTurnAroundMovementAction
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl StartSpriteAnimIfDifferent
_0808766E:
	adds r0, r5, #0
	movs r1, #0
	bl UpdateObjectEventSpriteInvisibility
	ldrb r0, [r6]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _080876A0
	ldrh r0, [r5, #0x3c]
	movs r1, #4
	ands r1, r0
	lsls r1, r1, #0x10
	adds r3, r5, #0
	adds r3, #0x3e
	lsrs r1, r1, #0x12
	lsls r1, r1, #2
	ldrb r2, [r3]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r5, #0x3c]
	adds r0, #1
	strh r0, [r5, #0x3c]
_080876A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end SpriteCB_LinkPlayer



