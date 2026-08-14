.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start CreateInGameTradePokemon
CreateInGameTradePokemon: @ 0x0807E448
	push {lr}
	ldr r0, _0807E45C
	ldrb r0, [r0]
	ldr r1, _0807E460
	ldrb r1, [r1]
	bl _CreateInGameTradePokemon
	pop {r0}
	bx r0
	.align 2, 0
_0807E45C: .4byte 0x02037282
_0807E460: .4byte 0x02037280
	thumb_func_end CreateInGameTradePokemon

	thumb_func_start sub_0807E464
sub_0807E464: @ 0x0807E464
	push {r4, r5, r6, lr}
	bl sub_0807B600
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #1
	bne _0807E4CE
	ldr r5, _0807E4F0
	ldr r0, [r5]
	adds r0, #0x8e
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0807E4F4
	adds r0, r0, r4
	bl DestroySprite
	ldr r0, [r5]
	adds r0, #0x8f
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl FreeSpriteOamMatrix
	ldr r0, _0807E4F8
	ldrb r4, [r0]
	ldrb r0, [r0, #1]
	movs r1, #6
	bl __umodsi3
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_0807AF08
	bl sub_08076C68
	cmp r0, #0
	bne _0807E4C8
	ldr r0, [r5]
	adds r2, r0, #0
	adds r2, #0x74
	ldr r1, _0807E4FC
	strh r1, [r2]
	adds r0, #0x93
	strb r6, [r0]
_0807E4C8:
	ldr r0, _0807E500
	bl SetMainCallback2
_0807E4CE:
	bl sub_0807AFF0
	bl sub_0807DF14
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807E4F0: .4byte 0x02031F40
_0807E4F4: .4byte 0x020205AC
_0807E4F8: .4byte 0x02031F38
_0807E4FC: .4byte 0x0000ABCD
_0807E500: .4byte 0x0807E505
	thumb_func_end sub_0807E464

	thumb_func_start sub_0807E504
sub_0807E504: @ 0x0807E504
	push {r4, lr}
	bl sub_0807A738
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_08076C68
	cmp r0, #0
	beq _0807E524
	ldr r0, _0807E520
	bl SetMainCallback2
	b _0807E564
	.align 2, 0
_0807E520: .4byte 0x0807DE4D
_0807E524:
	bl sub_0807DF14
	cmp r4, #0
	bne _0807E564
	ldr r4, _0807E57C
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0x72
	ldrh r1, [r0]
	ldr r0, _0807E580
	cmp r1, r0
	bne _0807E564
	adds r1, r2, #0
	adds r1, #0x74
	ldr r0, _0807E584
	strh r0, [r1]
	bl bitmask_all_link_players_but_self
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, [r4]
	adds r1, #0x74
	movs r2, #0x14
	bl SendBlock
	ldr r0, [r4]
	adds r0, #0x72
	movs r1, #2
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, #0x73
	strb r1, [r0]
_0807E564:
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807E57C: .4byte 0x02031F40
_0807E580: .4byte 0x00000101
_0807E584: .4byte 0x0000DCBA
	thumb_func_end sub_0807E504

	thumb_func_start sub_0807E588
sub_0807E588: @ 0x0807E588
	push {r4, lr}
	sub sp, #4
	ldr r1, _0807E5A8
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0x65
	bls _0807E59E
	b _0807EA72
_0807E59E:
	lsls r0, r0, #2
	ldr r1, _0807E5AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807E5A8: .4byte 0x03002360
_0807E5AC: .4byte 0x0807E5B0
_0807E5B0: @ jump table
	.4byte _0807E748 @ case 0
	.4byte _0807E764 @ case 1
	.4byte _0807E7D0 @ case 2
	.4byte _0807EA72 @ case 3
	.4byte _0807E8B0 @ case 4
	.4byte _0807E974 @ case 5
	.4byte _0807E99C @ case 6
	.4byte _0807E9B6 @ case 7
	.4byte _0807E9DC @ case 8
	.4byte _0807EA28 @ case 9
	.4byte _0807EA72 @ case 10
	.4byte _0807EA72 @ case 11
	.4byte _0807EA72 @ case 12
	.4byte _0807EA72 @ case 13
	.4byte _0807EA72 @ case 14
	.4byte _0807EA72 @ case 15
	.4byte _0807EA72 @ case 16
	.4byte _0807EA72 @ case 17
	.4byte _0807EA72 @ case 18
	.4byte _0807EA72 @ case 19
	.4byte _0807EA72 @ case 20
	.4byte _0807EA72 @ case 21
	.4byte _0807EA72 @ case 22
	.4byte _0807EA72 @ case 23
	.4byte _0807EA72 @ case 24
	.4byte _0807EA72 @ case 25
	.4byte _0807EA72 @ case 26
	.4byte _0807EA72 @ case 27
	.4byte _0807EA72 @ case 28
	.4byte _0807EA72 @ case 29
	.4byte _0807EA72 @ case 30
	.4byte _0807EA72 @ case 31
	.4byte _0807EA72 @ case 32
	.4byte _0807EA72 @ case 33
	.4byte _0807EA72 @ case 34
	.4byte _0807EA72 @ case 35
	.4byte _0807EA72 @ case 36
	.4byte _0807EA72 @ case 37
	.4byte _0807EA72 @ case 38
	.4byte _0807EA72 @ case 39
	.4byte _0807E8D4 @ case 40
	.4byte _0807E924 @ case 41
	.4byte _0807E952 @ case 42
	.4byte _0807EA72 @ case 43
	.4byte _0807EA72 @ case 44
	.4byte _0807EA72 @ case 45
	.4byte _0807EA72 @ case 46
	.4byte _0807EA72 @ case 47
	.4byte _0807EA72 @ case 48
	.4byte _0807EA72 @ case 49
	.4byte _0807E7F8 @ case 50
	.4byte _0807E854 @ case 51
	.4byte _0807E870 @ case 52
	.4byte _0807EA72 @ case 53
	.4byte _0807EA72 @ case 54
	.4byte _0807EA72 @ case 55
	.4byte _0807EA72 @ case 56
	.4byte _0807EA72 @ case 57
	.4byte _0807EA72 @ case 58
	.4byte _0807EA72 @ case 59
	.4byte _0807EA72 @ case 60
	.4byte _0807EA72 @ case 61
	.4byte _0807EA72 @ case 62
	.4byte _0807EA72 @ case 63
	.4byte _0807EA72 @ case 64
	.4byte _0807EA72 @ case 65
	.4byte _0807EA72 @ case 66
	.4byte _0807EA72 @ case 67
	.4byte _0807EA72 @ case 68
	.4byte _0807EA72 @ case 69
	.4byte _0807EA72 @ case 70
	.4byte _0807EA72 @ case 71
	.4byte _0807EA72 @ case 72
	.4byte _0807EA72 @ case 73
	.4byte _0807EA72 @ case 74
	.4byte _0807EA72 @ case 75
	.4byte _0807EA72 @ case 76
	.4byte _0807EA72 @ case 77
	.4byte _0807EA72 @ case 78
	.4byte _0807EA72 @ case 79
	.4byte _0807EA72 @ case 80
	.4byte _0807EA72 @ case 81
	.4byte _0807EA72 @ case 82
	.4byte _0807EA72 @ case 83
	.4byte _0807EA72 @ case 84
	.4byte _0807EA72 @ case 85
	.4byte _0807EA72 @ case 86
	.4byte _0807EA72 @ case 87
	.4byte _0807EA72 @ case 88
	.4byte _0807EA72 @ case 89
	.4byte _0807EA72 @ case 90
	.4byte _0807EA72 @ case 91
	.4byte _0807EA72 @ case 92
	.4byte _0807EA72 @ case 93
	.4byte _0807EA72 @ case 94
	.4byte _0807EA72 @ case 95
	.4byte _0807EA72 @ case 96
	.4byte _0807EA72 @ case 97
	.4byte _0807EA72 @ case 98
	.4byte _0807EA72 @ case 99
	.4byte _0807E77C @ case 100
	.4byte _0807E7B4 @ case 101
_0807E748:
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r4, _0807E75C
	ldr r1, _0807E760
	b _0807E7DE
	.align 2, 0
_0807E75C: .4byte 0x02021C7C
_0807E760: .4byte 0x08595430
_0807E764:
	movs r0, #0
	bl sub_08076C90
	ldr r0, _0807E778
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r2, #0
	movs r1, #0x64
	b _0807E8C0
	.align 2, 0
_0807E778: .4byte 0x03002360
_0807E77C:
	ldr r0, _0807E7AC
	ldr r3, [r0]
	ldr r0, [r3, #0x64]
	adds r0, #1
	str r0, [r3, #0x64]
	cmp r0, #0xb4
	bls _0807E798
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r2, r1
	movs r2, #0
	movs r1, #0x65
	strb r1, [r0]
	str r2, [r3, #0x64]
_0807E798:
	bl _IsLinkTaskFinished
	cmp r0, #0
	bne _0807E7A2
	b _0807EA72
_0807E7A2:
	ldr r0, _0807E7B0
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	b _0807E7C6
	.align 2, 0
_0807E7AC: .4byte 0x02031F40
_0807E7B0: .4byte 0x03002360
_0807E7B4:
	bl _IsLinkTaskFinished
	cmp r0, #0
	bne _0807E7BE
	b _0807EA72
_0807E7BE:
	ldr r0, _0807E7CC
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
_0807E7C6:
	movs r1, #2
	strb r1, [r0]
	b _0807EA72
	.align 2, 0
_0807E7CC: .4byte 0x03002360
_0807E7D0:
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	movs r0, #0x32
	strb r0, [r1]
	ldr r4, _0807E7F0
	ldr r1, _0807E7F4
_0807E7DE:
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	b _0807EA72
	.align 2, 0
_0807E7F0: .4byte 0x02021C7C
_0807E7F4: .4byte 0x08277071
_0807E7F8:
	bl InUnionRoom
	cmp r0, #0
	bne _0807E806
	movs r0, #0x15
	bl IncrementGameStat
_0807E806:
	ldr r0, _0807E848
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807E82E
	ldr r4, _0807E84C
	bl GetMultiplayerId
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r4, #4
	adds r1, r1, r4
	ldr r1, [r1]
	movs r0, #2
	bl MysteryGift_TryIncrementStat
_0807E82E:
	bl SetContinueGameWarpStatusToDynamicWarp
	bl sub_081532BC
	ldr r1, _0807E850
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	b _0807E8C2
	.align 2, 0
_0807E848: .4byte 0x0300319C
_0807E84C: .4byte 0x020226A0
_0807E850: .4byte 0x03002360
_0807E854:
	ldr r0, _0807E86C
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #5
	beq _0807E864
	b _0807EA72
_0807E864:
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	b _0807EA1C
	.align 2, 0
_0807E86C: .4byte 0x02031F40
_0807E870:
	bl sub_081532E8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0807E894
	bl ClearContinueGameWarpStatus
	ldr r0, _0807E890
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	b _0807EA72
	.align 2, 0
_0807E890: .4byte 0x03002360
_0807E894:
	ldr r0, _0807E8A8
	ldr r0, [r0]
	str r1, [r0, #0x64]
	ldr r0, _0807E8AC
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #0x33
	strb r1, [r0]
	b _0807EA72
	.align 2, 0
_0807E8A8: .4byte 0x02031F40
_0807E8AC: .4byte 0x03002360
_0807E8B0:
	bl sub_0815331C
	ldr r0, _0807E8CC
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r2, #0
	movs r1, #0x28
_0807E8C0:
	strb r1, [r0]
_0807E8C2:
	ldr r0, _0807E8D0
	ldr r0, [r0]
	str r2, [r0, #0x64]
	b _0807EA72
	.align 2, 0
_0807E8CC: .4byte 0x03002360
_0807E8D0: .4byte 0x02031F40
_0807E8D4:
	ldr r4, _0807E908
	ldr r1, [r4]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x32
	bhi _0807E8E4
	b _0807EA72
_0807E8E4:
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807E90C
	bl Random
	ldr r4, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x1e
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r4, #0x64]
	b _0807E912
	.align 2, 0
_0807E908: .4byte 0x02031F40
_0807E90C:
	ldr r1, [r4]
	movs r0, #0
	str r0, [r1, #0x64]
_0807E912:
	ldr r0, _0807E920
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #0x29
	strb r1, [r0]
	b _0807EA72
	.align 2, 0
_0807E920: .4byte 0x03002360
_0807E924:
	ldr r0, _0807E944
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	cmp r0, #0
	bne _0807E94C
	movs r0, #1
	bl sub_08076C90
	ldr r0, _0807E948
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #0x2a
	strb r1, [r0]
	b _0807EA72
	.align 2, 0
_0807E944: .4byte 0x02031F40
_0807E948: .4byte 0x03002360
_0807E94C:
	subs r0, #1
	str r0, [r1, #0x64]
	b _0807EA72
_0807E952:
	bl _IsLinkTaskFinished
	cmp r0, #0
	bne _0807E95C
	b _0807EA72
_0807E95C:
	bl sub_08153344
	ldr r0, _0807E970
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #5
	strb r1, [r0]
	b _0807EA72
	.align 2, 0
_0807E970: .4byte 0x03002360
_0807E974:
	ldr r0, _0807E998
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x3c
	bls _0807EA72
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #2
	bl sub_08076C90
	b _0807EA72
	.align 2, 0
_0807E998: .4byte 0x02031F40
_0807E99C:
	bl _IsLinkTaskFinished
	cmp r0, #0
	beq _0807EA72
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	b _0807EA14
_0807E9B6:
	ldr r0, _0807E9D4
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0807EA72
	movs r0, #3
	bl FadeOutBGMTemporarily
	ldr r1, _0807E9D8
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r1, r0
	b _0807EA1C
	.align 2, 0
_0807E9D4: .4byte 0x02037C74
_0807E9D8: .4byte 0x03002360
_0807E9DC:
	bl IsBGMStopped
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0807EA72
	ldr r0, _0807EA04
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807EA10
	ldr r0, _0807EA08
	ldr r1, [r0, #8]
	ldr r0, _0807EA0C
	cmp r1, r0
	bne _0807EA10
	movs r0, #3
	bl sub_08076C90
	b _0807EA14
	.align 2, 0
_0807EA04: .4byte 0x0300319C
_0807EA08: .4byte 0x03002360
_0807EA0C: .4byte 0x08076DB5
_0807EA10:
	bl SetCloseLinkCallback
_0807EA14:
	ldr r1, _0807EA24
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r1, r2
_0807EA1C:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0807EA72
	.align 2, 0
_0807EA24: .4byte 0x03002360
_0807EA28:
	ldr r0, _0807EA50
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807EA60
	ldr r1, [r2, #8]
	ldr r0, _0807EA54
	cmp r1, r0
	bne _0807EA60
	bl _IsLinkTaskFinished
	cmp r0, #0
	beq _0807EA72
	ldr r0, _0807EA58
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0807EA5C
	bl SetMainCallback2
	b _0807EA72
	.align 2, 0
_0807EA50: .4byte 0x0300319C
_0807EA54: .4byte 0x08076DB5
_0807EA58: .4byte 0x030027A0
_0807EA5C: .4byte 0x0807EAA1
_0807EA60:
	ldr r0, _0807EA94
	ldrb r1, [r0]
	cmp r1, #0
	bne _0807EA72
	ldr r0, _0807EA98
	strb r1, [r0]
	ldr r0, _0807EA9C
	bl SetMainCallback2
_0807EA72:
	bl HasLinkErrorOccurred
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807EA80
	bl RunTasks
_0807EA80:
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807EA94: .4byte 0x030031C4
_0807EA98: .4byte 0x030027A0
_0807EA9C: .4byte 0x0807EAA1
	thumb_func_end sub_0807E588

	thumb_func_start c2_080543C4
c2_080543C4: @ 0x0807EAA0
	push {r4, r5, lr}
	ldr r0, _0807EB0C
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0807EAF6
	bl FreeAllWindowBuffers
	movs r0, #3
	bl GetBgTilemapBuffer
	bl Free
	movs r0, #1
	bl GetBgTilemapBuffer
	bl Free
	movs r0, #0
	bl GetBgTilemapBuffer
	bl Free
	bl FreeMonSpritesGfx
	ldr r4, _0807EB10
	ldr r0, [r4]
	bl Free
	str r5, [r4]
	ldr r0, _0807EB14
	ldrb r0, [r0]
	cmp r0, #0
	beq _0807EAEE
	bl DestroyWirelessStatusIndicatorSprite
_0807EAEE:
	ldr r0, _0807EB18
	ldr r0, [r0, #8]
	bl SetMainCallback2
_0807EAF6:
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807EB0C: .4byte 0x02037C74
_0807EB10: .4byte 0x02031F40
_0807EB14: .4byte 0x0300319C
_0807EB18: .4byte 0x03002360
	thumb_func_end c2_080543C4

	thumb_func_start DoInGameTradeScene
DoInGameTradeScene: @ 0x0807EB1C
	push {lr}
	sub sp, #4
	bl LockPlayerFieldControls
	ldr r0, _0807EB44
	movs r1, #0xa
	bl CreateTask
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0807EB44: .4byte 0x0807EB49
	thumb_func_end DoInGameTradeScene

	thumb_func_start sub_0807EB48
sub_0807EB48: @ 0x0807EB48
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _0807EB74
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0807EB6C
	ldr r0, _0807EB78
	bl SetMainCallback2
	ldr r1, _0807EB7C
	ldr r0, _0807EB80
	str r0, [r1]
	adds r0, r4, #0
	bl DestroyTask
_0807EB6C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807EB74: .4byte 0x02037C74
_0807EB78: .4byte 0x0807ACC9
_0807EB7C: .4byte 0x03005B0C
_0807EB80: .4byte 0x080AEA65
	thumb_func_end sub_0807EB48

	thumb_func_start sub_0807EB84
sub_0807EB84: @ 0x0807EB84
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #0
_0807EB8A:
	ldr r0, _0807EBC8
	ldrb r0, [r0, #1]
	movs r1, #6
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x64
	muls r0, r1, r0
	ldr r1, _0807EBCC
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x43
	bl GetMonData3
	adds r0, r5, r0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xb
	bls _0807EB8A
	cmp r5, #0
	beq _0807EBC2
	ldr r0, _0807EBD0
	bl FlagSet
_0807EBC2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807EBC8: .4byte 0x02031F38
_0807EBCC: .4byte 0x020243E8
_0807EBD0: .4byte 0x0000089B
	thumb_func_end sub_0807EB84

	thumb_func_start sub_0807EBD4
sub_0807EBD4: @ 0x0807EBD4
	push {lr}
	bl sub_0807ABCC
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0807EBD4

	thumb_func_start sub_0807EBE0
sub_0807EBE0: @ 0x0807EBE0
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	movs r1, #0xff
	bl FillWindowPixelBuffer
	ldr r2, _0807EC44
	ldr r0, [r2]
	adds r0, #0xf6
	movs r3, #0
	movs r1, #0xf
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0xf7
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0xf8
	movs r1, #6
	strb r1, [r0]
	str r3, [sp]
	str r3, [sp, #4]
	ldr r0, [r2]
	adds r0, #0xf6
	str r0, [sp, #8]
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	str r4, [sp, #0xc]
	str r6, [sp, #0x10]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0
	movs r3, #2
	bl AddTextPrinterParameterized4
	adds r0, r5, #0
	movs r1, #3
	bl CopyWindowToVram
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807EC44: .4byte 0x02031F40
	thumb_func_end sub_0807EBE0

	thumb_func_start c3_08054588
c3_08054588: @ 0x0807EC48
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, _0807EC80
	adds r4, r0, r1
	ldr r1, _0807EC84
	movs r2, #0
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r2, r1, #0
	movs r3, #4
	ldrsh r0, [r4, r3]
	cmp r0, #0
	bne _0807EC8C
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq _0807EC94
	lsls r0, r1, #1
	ldr r1, _0807EC88
	adds r0, r0, r1
	b _0807EC96
	.align 2, 0
_0807EC80: .4byte 0x03005B68
_0807EC84: .4byte 0x0830D310
_0807EC88: .4byte 0x0830BCE4
_0807EC8C:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	bne _0807ECA4
_0807EC94:
	ldr r0, _0807ECA0
_0807EC96:
	movs r1, #0x30
	movs r2, #0x20
	bl LoadPalette
	b _0807ECB2
	.align 2, 0
_0807ECA0: .4byte 0x0830C0E4
_0807ECA4:
	lsls r0, r2, #1
	ldr r1, _0807ED08
	adds r0, r0, r1
	movs r1, #0x30
	movs r2, #0x20
	bl LoadPalette
_0807ECB2:
	ldr r0, _0807ED0C
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _0807ECD0
	movs r3, #2
	ldrsh r0, [r4, r3]
	cmp r0, #0
	bne _0807ECD0
	movs r0, #0xc3
	bl PlaySE
_0807ECD0:
	movs r0, #2
	ldrsh r2, [r4, r0]
	ldr r1, _0807ED0C
	movs r3, #0
	ldrsh r0, [r4, r3]
	lsls r0, r0, #1
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r2, r0
	bne _0807ED10
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	movs r0, #0
	strh r0, [r4, #2]
	movs r2, #0
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _0807ED16
	adds r0, r5, #0
	bl DestroyTask
	b _0807ED16
	.align 2, 0
_0807ED08: .4byte 0x0830BEE4
_0807ED0C: .4byte 0x0830D310
_0807ED10:
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
_0807ED16:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end c3_08054588

	thumb_func_start c3_0805465C
c3_0805465C: @ 0x0807ED1C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r0, #0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	ldr r1, _0807EDCC
	adds r5, r0, r1
	movs r0, #0
	ldrsh r4, [r5, r0]
	cmp r4, #0
	bne _0807ED6E
	ldr r2, _0807EDD0
	ldr r0, [r2]
	adds r3, r0, #0
	adds r3, #0xfd
	movs r1, #0x78
	strb r1, [r3]
	adds r0, #0xfb
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0xfc
	strb r4, [r0]
	ldr r0, [r2]
	adds r0, #0xfe
	movs r1, #0xa0
	strb r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	movs r0, #0
	bl SetGpuRegBits
	movs r0, #0x4a
	movs r1, #0x10
	bl SetGpuReg
	movs r0, #0x48
	movs r1, #0x13
	bl SetGpuReg
_0807ED6E:
	ldr r4, _0807EDD0
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0xfd
	ldrb r1, [r1]
	adds r0, #0xfb
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	movs r0, #0x40
	bl SetGpuReg
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0xfe
	ldrb r1, [r1]
	adds r0, #0xfc
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	movs r0, #0x44
	bl SetGpuReg
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	ldr r1, [r4]
	adds r1, #0xfb
	ldrb r0, [r1]
	subs r0, #5
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, #0xfd
	ldrb r0, [r1]
	adds r0, #5
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0xfb
	ldrb r0, [r0]
	cmp r0, #0x4f
	bhi _0807EDC6
	adds r0, r6, #0
	bl DestroyTask
_0807EDC6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807EDCC: .4byte 0x03005B68
_0807EDD0: .4byte 0x02031F40
	thumb_func_end c3_0805465C

	thumb_func_start sub_0807EDD4
sub_0807EDD4: @ 0x0807EDD4
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r0, #0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	ldr r1, _0807EE78
	adds r5, r0, r1
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _0807EE10
	ldr r2, _0807EE7C
	ldr r0, [r2]
	adds r0, #0xfb
	movs r1, #0x50
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0xfd
	movs r1, #0xa0
	strb r1, [r0]
	movs r0, #0x4a
	movs r1, #0x10
	bl SetGpuReg
	movs r0, #0x48
	movs r1, #0x13
	bl SetGpuReg
_0807EE10:
	ldr r4, _0807EE7C
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0xfd
	ldrb r1, [r1]
	adds r0, #0xfb
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	movs r0, #0x40
	bl SetGpuReg
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0xfe
	ldrb r1, [r1]
	adds r0, #0xfc
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r1, r0
	movs r0, #0x44
	bl SetGpuReg
	ldr r0, [r4]
	adds r0, #0xfb
	ldrb r0, [r0]
	cmp r0, #0x78
	beq _0807EE84
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	ldr r1, [r4]
	adds r1, #0xfb
	ldrb r0, [r1]
	adds r0, #5
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, #0xfd
	ldrb r0, [r1]
	subs r0, #5
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, #0xfb
	ldrb r0, [r0]
	cmp r0, #0x73
	bls _0807EE94
	ldr r2, _0807EE80
	movs r0, #8
	movs r1, #0
	bl BlendPalettes
	b _0807EE94
	.align 2, 0
_0807EE78: .4byte 0x03005B68
_0807EE7C: .4byte 0x02031F40
_0807EE80: .4byte 0x0000FFFF
_0807EE84:
	movs r1, #0x80
	lsls r1, r1, #6
	movs r0, #0
	bl ClearGpuRegBits
	adds r0, r6, #0
	bl DestroyTask
_0807EE94:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0807EDD4

	thumb_func_start sub_0807EE9C
sub_0807EE9C: @ 0x0807EE9C
	push {r4, r5, lr}
	sub sp, #4
	ldr r1, _0807EEBC
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0xc
	bls _0807EEB2
	b _0807F144
_0807EEB2:
	lsls r0, r0, #2
	ldr r1, _0807EEC0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807EEBC: .4byte 0x03002360
_0807EEC0: .4byte 0x0807EEC4
_0807EEC4: @ jump table
	.4byte _0807EEF8 @ case 0
	.4byte _0807EF20 @ case 1
	.4byte _0807EF38 @ case 2
	.4byte _0807EF88 @ case 3
	.4byte _0807EFA8 @ case 4
	.4byte _0807EFE4 @ case 5
	.4byte _0807F008 @ case 6
	.4byte _0807F058 @ case 7
	.4byte _0807F086 @ case 8
	.4byte _0807F0A4 @ case 9
	.4byte _0807F0CC @ case 10
	.4byte _0807F0FC @ case 11
	.4byte _0807F130 @ case 12
_0807EEF8:
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	ldr r4, _0807EF18
	ldr r1, _0807EF1C
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	b _0807F144
	.align 2, 0
_0807EF18: .4byte 0x02021C7C
_0807EF1C: .4byte 0x08595430
_0807EF20:
	movs r0, #0
	bl sub_08076C90
	ldr r0, _0807EF34
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r2, #0
	movs r1, #2
	b _0807EFF4
	.align 2, 0
_0807EF34: .4byte 0x03002360
_0807EF38:
	bl _IsLinkTaskFinished
	cmp r0, #0
	bne _0807EF42
	b _0807F144
_0807EF42:
	ldr r0, _0807EF78
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r5, #0
	movs r1, #3
	strb r1, [r0]
	ldr r4, _0807EF7C
	ldr r1, _0807EF80
	adds r0, r4, #0
	bl StringExpandPlaceholders
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl sub_0807EBE0
	movs r0, #0x15
	bl IncrementGameStat
	bl sub_081532BC
	ldr r0, _0807EF84
	ldr r0, [r0]
	str r5, [r0, #0x64]
	b _0807F144
	.align 2, 0
_0807EF78: .4byte 0x03002360
_0807EF7C: .4byte 0x02021C7C
_0807EF80: .4byte 0x08277071
_0807EF84: .4byte 0x02031F40
_0807EF88:
	ldr r0, _0807EFA4
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #5
	beq _0807EF98
	b _0807F144
_0807EF98:
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	movs r0, #4
	strb r0, [r1]
	b _0807F144
	.align 2, 0
_0807EFA4: .4byte 0x02031F40
_0807EFA8:
	bl sub_081532E8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0807EFC8
	ldr r0, _0807EFC4
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807EFC4: .4byte 0x03002360
_0807EFC8:
	ldr r0, _0807EFDC
	ldr r0, [r0]
	str r1, [r0, #0x64]
	ldr r0, _0807EFE0
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #3
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807EFDC: .4byte 0x02031F40
_0807EFE0: .4byte 0x03002360
_0807EFE4:
	bl sub_0815331C
	ldr r0, _0807F000
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r2, #0
	movs r1, #6
_0807EFF4:
	strb r1, [r0]
	ldr r0, _0807F004
	ldr r0, [r0]
	str r2, [r0, #0x64]
	b _0807F144
	.align 2, 0
_0807F000: .4byte 0x03002360
_0807F004: .4byte 0x02031F40
_0807F008:
	ldr r4, _0807F03C
	ldr r1, [r4]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0xa
	bhi _0807F018
	b _0807F144
_0807F018:
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807F040
	bl Random
	ldr r4, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x1e
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r4, #0x64]
	b _0807F046
	.align 2, 0
_0807F03C: .4byte 0x02031F40
_0807F040:
	ldr r1, [r4]
	movs r0, #0
	str r0, [r1, #0x64]
_0807F046:
	ldr r0, _0807F054
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #7
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807F054: .4byte 0x03002360
_0807F058:
	ldr r0, _0807F078
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	cmp r0, #0
	bne _0807F080
	movs r0, #1
	bl sub_08076C90
	ldr r0, _0807F07C
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #8
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807F078: .4byte 0x02031F40
_0807F07C: .4byte 0x03002360
_0807F080:
	subs r0, #1
	str r0, [r1, #0x64]
	b _0807F144
_0807F086:
	bl _IsLinkTaskFinished
	cmp r0, #0
	beq _0807F144
	bl sub_08153344
	ldr r0, _0807F0A0
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #9
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807F0A0: .4byte 0x03002360
_0807F0A4:
	ldr r0, _0807F0C8
	ldr r1, [r0]
	ldr r0, [r1, #0x64]
	adds r0, #1
	str r0, [r1, #0x64]
	cmp r0, #0x3c
	bls _0807F144
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #2
	bl sub_08076C90
	b _0807F144
	.align 2, 0
_0807F0C8: .4byte 0x02031F40
_0807F0CC:
	bl _IsLinkTaskFinished
	cmp r0, #0
	beq _0807F144
	movs r0, #3
	bl FadeOutBGMTemporarily
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r0, _0807F0F8
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #0xb
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807F0F8: .4byte 0x03002360
_0807F0FC:
	ldr r0, _0807F128
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0807F144
	bl IsBGMStopped
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0807F144
	movs r0, #3
	bl sub_08076C90
	ldr r0, _0807F12C
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #0xc
	strb r1, [r0]
	b _0807F144
	.align 2, 0
_0807F128: .4byte 0x02037C74
_0807F12C: .4byte 0x03002360
_0807F130:
	bl _IsLinkTaskFinished
	cmp r0, #0
	beq _0807F144
	ldr r0, _0807F168
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0807F16C
	bl SetMainCallback2
_0807F144:
	bl HasLinkErrorOccurred
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0807F152
	bl RunTasks
_0807F152:
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807F168: .4byte 0x030027A0
_0807F16C: .4byte 0x0807EAA1
	thumb_func_end sub_0807EE9C
