.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_0802B010
sub_0802B010: @ 0x0802B010
	push {r4, lr}
	ldr r4, _0802B024
	ldr r0, [r4]
	ldrh r0, [r0, #8]
	cmp r0, #0
	beq _0802B028
	cmp r0, #1
	beq _0802B046
	b _0802B052
	.align 2, 0
_0802B024: .4byte 0x020229B0
_0802B028:
	bl sub_0802BDDC
	movs r0, #0
	bl sub_0802AB08
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x72
	ldrh r0, [r0]
	adds r2, r1, #0
	adds r2, #0x4a
	strh r0, [r2]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
_0802B046:
	bl sub_0802C400
	cmp r0, #0
	beq _0802B052
	movs r0, #0
	b _0802B054
_0802B052:
	movs r0, #1
_0802B054:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802B010

	thumb_func_start sub_0802B05C
sub_0802B05C: @ 0x0802B05C
	push {lr}
	bl sub_0802B5C0
	cmp r0, #0
	bne _0802B084
	ldr r0, _0802B080
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	adds r2, r1, #0
	adds r2, #0x72
	strh r0, [r2]
	adds r1, #0x4c
	movs r0, #1
	strb r0, [r1]
	b _0802B09E
	.align 2, 0
_0802B080: .4byte 0x020229B0
_0802B084:
	bl sub_0802C22C
	cmp r0, #0
	beq _0802B090
	movs r0, #1
	b _0802B0A0
_0802B090:
	bl sub_0802BDAC
	ldr r0, _0802B0A4
	ldr r0, [r0]
	adds r0, #0x4c
	movs r1, #3
	strb r1, [r0]
_0802B09E:
	movs r0, #0
_0802B0A0:
	pop {r1}
	bx r1
	.align 2, 0
_0802B0A4: .4byte 0x020229B0
	thumb_func_end sub_0802B05C

	thumb_func_start sub_0802B0A8
sub_0802B0A8: @ 0x0802B0A8
	push {lr}
	bl sub_0802B5C0
	cmp r0, #0
	beq _0802B0C2
	bl sub_0802C22C
	cmp r0, #0
	beq _0802B0BE
	movs r0, #1
	b _0802B0C4
_0802B0BE:
	bl sub_0802BDAC
_0802B0C2:
	movs r0, #0
_0802B0C4:
	pop {r1}
	bx r1
	thumb_func_end sub_0802B0A8

	thumb_func_start sub_0802B0C8
sub_0802B0C8: @ 0x0802B0C8
	push {r4, lr}
	ldr r4, _0802B0E0
	ldr r0, [r4]
	ldrh r0, [r0, #8]
	cmp r0, #1
	beq _0802B100
	cmp r0, #1
	bgt _0802B0E4
	cmp r0, #0
	beq _0802B0EA
	b _0802B15C
	.align 2, 0
_0802B0E0: .4byte 0x020229B0
_0802B0E4:
	cmp r0, #2
	beq _0802B154
	b _0802B15C
_0802B0EA:
	bl sub_0802C22C
	bl sub_0802C2D0
	cmp r0, #0
	beq _0802B15C
	ldr r1, [r4]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _0802B15C
_0802B100:
	bl sub_0802B658
	cmp r0, #0
	bne _0802B15C
	bl sub_0802C4B0
	cmp r0, #0
	beq _0802B122
	bl sub_0802C4D4
	ldr r1, [r4]
	adds r2, r1, #0
	adds r2, #0x72
	strh r0, [r2]
	adds r1, #0x4c
	movs r0, #7
	b _0802B148
_0802B122:
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x74
	ldrh r0, [r0]
	cmp r0, #0xc7
	bls _0802B13C
	ldrh r0, [r1, #0xe]
	adds r2, r1, #0
	adds r2, #0x72
	strh r0, [r2]
	adds r1, #0x4c
	movs r0, #8
	b _0802B148
_0802B13C:
	ldrh r0, [r1, #0xe]
	adds r2, r1, #0
	adds r2, #0x72
	strh r0, [r2]
	adds r1, #0x4c
	movs r0, #4
_0802B148:
	strb r0, [r1]
	ldr r0, _0802B158
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
_0802B154:
	movs r0, #0
	b _0802B15E
	.align 2, 0
_0802B158: .4byte 0x020229B0
_0802B15C:
	movs r0, #1
_0802B15E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802B0C8

	thumb_func_start sub_0802B164
sub_0802B164: @ 0x0802B164
	push {r4, lr}
	ldr r4, _0802B17C
	ldr r0, [r4]
	ldrh r0, [r0, #8]
	cmp r0, #1
	beq _0802B1A4
	cmp r0, #1
	bgt _0802B180
	cmp r0, #0
	beq _0802B186
	b _0802B1B8
	.align 2, 0
_0802B17C: .4byte 0x020229B0
_0802B180:
	cmp r0, #2
	beq _0802B1B4
	b _0802B1B8
_0802B186:
	bl sub_0802C22C
	cmp r0, #0
	bne _0802B192
	bl sub_0802BDAC
_0802B192:
	bl sub_0802C2D0
	cmp r0, #0
	beq _0802B1B8
	ldr r1, [r4]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _0802B1B8
_0802B1A4:
	bl sub_0802B658
	cmp r0, #0
	bne _0802B1B8
	ldr r1, [r4]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
_0802B1B4:
	movs r0, #0
	b _0802B1BA
_0802B1B8:
	movs r0, #1
_0802B1BA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802B164

	thumb_func_start sub_0802B1C0
sub_0802B1C0: @ 0x0802B1C0
	push {r4, lr}
	ldr r4, _0802B1D8
	ldr r0, [r4]
	ldrh r1, [r0, #8]
	cmp r1, #1
	beq _0802B1F4
	cmp r1, #1
	bgt _0802B1DC
	cmp r1, #0
	beq _0802B1E6
	b _0802B254
	.align 2, 0
_0802B1D8: .4byte 0x020229B0
_0802B1DC:
	cmp r1, #2
	beq _0802B220
	cmp r1, #3
	beq _0802B24A
	b _0802B254
_0802B1E6:
	movs r0, #4
	bl sub_0802AB08
	ldr r1, [r4]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
_0802B1F4:
	bl sub_0802B878
	cmp r0, #0
	bne _0802B254
	ldr r4, _0802B21C
	ldr r2, [r4]
	ldr r0, [r2, #0x78]
	adds r1, r2, #0
	adds r1, #0x74
	ldrh r1, [r1]
	adds r2, #0x72
	ldrh r2, [r2]
	bl sub_0802E04C
	ldr r1, [r4]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _0802B254
	.align 2, 0
_0802B21C: .4byte 0x020229B0
_0802B220:
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802B254
	bl sub_0802C344
	cmp r0, #0
	beq _0802B238
	ldr r0, [r4]
	adds r0, #0x4c
	movs r1, #5
	b _0802B23E
_0802B238:
	ldr r0, [r4]
	adds r0, #0x4c
	movs r1, #6
_0802B23E:
	strb r1, [r0]
	ldr r0, _0802B250
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
_0802B24A:
	movs r0, #0
	b _0802B256
	.align 2, 0
_0802B250: .4byte 0x020229B0
_0802B254:
	movs r0, #1
_0802B256:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802B1C0

	thumb_func_start sub_0802B25C
sub_0802B25C: @ 0x0802B25C
	push {r4, lr}
	ldr r4, _0802B270
	ldr r0, [r4]
	ldrh r0, [r0, #8]
	cmp r0, #0
	beq _0802B274
	cmp r0, #1
	beq _0802B282
	b _0802B2B4
	.align 2, 0
_0802B270: .4byte 0x020229B0
_0802B274:
	movs r0, #0
	bl sub_0802AB08
	ldr r1, [r4]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
_0802B282:
	bl sub_0802B878
	cmp r0, #0
	bne _0802B2B4
	ldr r4, _0802B2B0
	ldr r2, [r4]
	ldr r0, [r2, #0x78]
	adds r1, r2, #0
	adds r1, #0x74
	ldrh r1, [r1]
	adds r2, #0x72
	ldrh r2, [r2]
	bl sub_0802E04C
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0x45
	ldrb r1, [r1]
	adds r0, #0x42
	strh r1, [r0]
	movs r0, #0
	b _0802B2B6
	.align 2, 0
_0802B2B0: .4byte 0x020229B0
_0802B2B4:
	movs r0, #1
_0802B2B6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802B25C

	thumb_func_start sub_0802B2BC
sub_0802B2BC: @ 0x0802B2BC
	push {r4, lr}
	ldr r4, _0802B2D0
	ldr r1, [r4]
	ldrh r0, [r1, #8]
	cmp r0, #0
	beq _0802B2D4
	cmp r0, #1
	beq _0802B2E6
	b _0802B312
	.align 2, 0
_0802B2D0: .4byte 0x020229B0
_0802B2D4:
	bl sub_0802BA24
	cmp r0, #0
	bne _0802B312
	ldr r1, [r4]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _0802B312
_0802B2E6:
	adds r0, r1, #0
	adds r0, #0x49
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802B312
	adds r0, r1, #0
	bl sub_0802A788
	bl Random
	ldr r1, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r1, #0x24]
	adds r3, r1, #0
	adds r3, #0x72
	movs r2, #0
	strh r0, [r3]
	adds r1, #0x4c
	strb r2, [r1]
	movs r0, #0
	b _0802B314
_0802B312:
	movs r0, #1
_0802B314:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802B2BC

	thumb_func_start sub_0802B31C
sub_0802B31C: @ 0x0802B31C
	push {r4, lr}
	ldr r4, _0802B330
	ldr r0, [r4]
	ldrh r0, [r0, #8]
	cmp r0, #0
	beq _0802B334
	cmp r0, #1
	beq _0802B34A
	b _0802B34E
	.align 2, 0
_0802B330: .4byte 0x020229B0
_0802B334:
	bl sub_0802BA24
	cmp r0, #0
	bne _0802B34E
	ldr r0, [r4]
	bl sub_0802A788
	ldr r1, [r4]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
_0802B34A:
	movs r0, #0
	b _0802B350
_0802B34E:
	movs r0, #1
_0802B350:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802B31C

	thumb_func_start sub_0802B358
sub_0802B358: @ 0x0802B358
	push {r4, lr}
	ldr r4, _0802B370
	ldr r1, [r4]
	ldrh r0, [r1, #8]
	cmp r0, #1
	beq _0802B380
	cmp r0, #1
	bgt _0802B374
	cmp r0, #0
	beq _0802B37A
	b _0802B3A4
	.align 2, 0
_0802B370: .4byte 0x020229B0
_0802B374:
	cmp r0, #2
	beq _0802B390
	b _0802B3A4
_0802B37A:
	movs r0, #1
	strh r0, [r1, #8]
	b _0802B3A4
_0802B380:
	movs r0, #0
	bl sub_0802AB08
	ldr r1, [r4]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _0802B3A4
_0802B390:
	bl sub_0802B954
	cmp r0, #0
	bne _0802B3A4
	ldr r0, [r4]
	ldr r0, [r0]
	bl SetMainCallback2
	bl sub_0802A73C
_0802B3A4:
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802B358

	thumb_func_start sub_0802B3AC
sub_0802B3AC: @ 0x0802B3AC
	push {r4, lr}
	ldr r4, _0802B3C0
	ldr r0, [r4]
	ldrh r0, [r0, #8]
	cmp r0, #0
	beq _0802B3C4
	cmp r0, #1
	beq _0802B3D4
	b _0802B3F0
	.align 2, 0
_0802B3C0: .4byte 0x020229B0
_0802B3C4:
	movs r0, #4
	bl sub_0802AB08
	ldr r1, [r4]
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _0802B3F0
_0802B3D4:
	bl sub_0802B74C
	cmp r0, #0
	bne _0802B3F0
	ldr r0, [r4]
	ldrh r1, [r0, #0xe]
	adds r2, r0, #0
	adds r2, #0x72
	strh r1, [r2]
	adds r0, #0x4c
	movs r1, #8
	strb r1, [r0]
	movs r0, #0
	b _0802B3F2
_0802B3F0:
	movs r0, #1
_0802B3F2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802B3AC

	thumb_func_start sub_0802B3F8
sub_0802B3F8: @ 0x0802B3F8
	push {lr}
	movs r0, #0
	bl sub_0802AB08
	bl sub_0802B74C
	cmp r0, #0
	beq _0802B40C
	movs r0, #1
	b _0802B40E
_0802B40C:
	movs r0, #0
_0802B40E:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802B3F8

	thumb_func_start sub_0802B414
sub_0802B414: @ 0x0802B414
	push {r4, lr}
	ldr r1, _0802B42C
	ldr r0, [r1]
	ldrh r0, [r0, #8]
	adds r4, r1, #0
	cmp r0, #4
	bhi _0802B4CC
	lsls r0, r0, #2
	ldr r1, _0802B430
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802B42C: .4byte 0x020229B0
_0802B430: .4byte 0x0802B434
_0802B434: @ jump table
	.4byte _0802B448 @ case 0
	.4byte _0802B464 @ case 1
	.4byte _0802B474 @ case 2
	.4byte _0802B48C @ case 3
	.4byte _0802B4B0 @ case 4
_0802B448:
	ldr r2, [r4]
	ldr r0, [r2, #0x78]
	adds r1, r2, #0
	adds r1, #0x74
	ldrh r1, [r1]
	adds r2, #0x72
	ldrh r2, [r2]
	bl sub_0802E04C
	movs r0, #5
	bl sub_0802CDBC
	ldr r1, [r4]
	b _0802B4A0
_0802B464:
	bl sub_0802CDE4
	cmp r0, #0
	bne _0802B4CC
	movs r0, #0
	bl sub_0802AB08
	b _0802B49C
_0802B474:
	bl sub_0802C400
	cmp r0, #0
	beq _0802B4CC
	ldr r0, _0802B488
	movs r1, #6
	bl CreateTask
	b _0802B49C
	.align 2, 0
_0802B488: .4byte 0x081535C5
_0802B48C:
	ldr r0, _0802B4A8
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802B4CC
	bl sub_0802D704
_0802B49C:
	ldr r0, _0802B4AC
	ldr r1, [r0]
_0802B4A0:
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _0802B4CC
	.align 2, 0
_0802B4A8: .4byte 0x081535C5
_0802B4AC: .4byte 0x020229B0
_0802B4B0:
	bl sub_0802D734
	cmp r0, #0
	bne _0802B4CC
	ldr r0, _0802B4C8
	ldr r0, [r0]
	adds r0, #0x4c
	movs r1, #4
	strb r1, [r0]
	movs r0, #0
	b _0802B4CE
	.align 2, 0
_0802B4C8: .4byte 0x020229B0
_0802B4CC:
	movs r0, #1
_0802B4CE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802B414

	thumb_func_start sub_0802B4D4
sub_0802B4D4: @ 0x0802B4D4
	push {r4, r5, lr}
	ldr r1, _0802B4EC
	ldr r0, [r1]
	ldrh r0, [r0, #0xa]
	adds r4, r1, #0
	cmp r0, #7
	bhi _0802B5B8
	lsls r0, r0, #2
	ldr r1, _0802B4F0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802B4EC: .4byte 0x020229B0
_0802B4F0: .4byte 0x0802B4F4
_0802B4F4: @ jump table
	.4byte _0802B514 @ case 0
	.4byte _0802B520 @ case 1
	.4byte _0802B540 @ case 2
	.4byte _0802B55A @ case 3
	.4byte _0802B56C @ case 4
	.4byte _0802B574 @ case 5
	.4byte _0802B594 @ case 6
	.4byte _0802B5AE @ case 7
_0802B514:
	movs r0, #2
	bl sub_0802CDBC
	bl sub_0802DAD8
	b _0802B584
_0802B520:
	bl sub_0802CDE4
	adds r5, r0, #0
	cmp r5, #0
	bne _0802B5B8
	ldr r4, _0802B53C
	ldr r0, [r4]
	ldrb r0, [r0, #6]
	bl sub_0802DAEC
	ldr r1, [r4]
	strh r5, [r1, #0x3c]
	b _0802B588
	.align 2, 0
_0802B53C: .4byte 0x020229B0
_0802B540:
	ldr r1, [r4]
	ldrh r0, [r1, #0x3c]
	adds r0, #1
	strh r0, [r1, #0x3c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x78
	bls _0802B5B8
	movs r0, #3
	bl sub_0802CDBC
	ldr r1, [r4]
	b _0802B588
_0802B55A:
	bl sub_0802CDE4
	cmp r0, #1
	beq _0802B5B8
	bl sub_0802DB00
	cmp r0, #1
	beq _0802B5B8
	b _0802B584
_0802B56C:
	movs r0, #9
	bl sub_0802CDBC
	b _0802B584
_0802B574:
	bl sub_0802CDE4
	cmp r0, #0
	bne _0802B5B8
	bl sub_0802BF54
	bl sub_0802D458
_0802B584:
	ldr r0, _0802B590
	ldr r1, [r0]
_0802B588:
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	b _0802B5B8
	.align 2, 0
_0802B590: .4byte 0x020229B0
_0802B594:
	bl sub_0802D47C
	cmp r0, #0
	bne _0802B5B8
	bl sub_0802BF64
	bl sub_0802BB94
	ldr r0, _0802B5B4
	ldr r1, [r0]
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
_0802B5AE:
	movs r0, #0
	b _0802B5BA
	.align 2, 0
_0802B5B4: .4byte 0x020229B0
_0802B5B8:
	movs r0, #1
_0802B5BA:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_0802B4D4

	thumb_func_start sub_0802B5C0
sub_0802B5C0: @ 0x0802B5C0
	push {r4, r5, lr}
	bl sub_0802BBD8
	ldr r5, _0802B5D8
	ldr r1, [r5]
	ldrh r4, [r1, #0x36]
	cmp r4, #0
	beq _0802B5DC
	movs r0, #0
	strh r0, [r1, #0x36]
	b _0802B650
	.align 2, 0
_0802B5D8: .4byte 0x020229B0
_0802B5DC:
	ldrh r0, [r1, #0xa]
	cmp r0, #1
	beq _0802B608
	cmp r0, #1
	bgt _0802B5EC
	cmp r0, #0
	beq _0802B5F6
	b _0802B64E
_0802B5EC:
	cmp r0, #2
	beq _0802B62C
	cmp r0, #3
	beq _0802B640
	b _0802B64E
_0802B5F6:
	movs r0, #0
	bl sub_0802BE24
	cmp r0, #0
	beq _0802B64E
	ldr r1, [r5]
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
_0802B608:
	ldr r0, _0802B624
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0802B64E
	bl sub_0802BE58
	movs r0, #3
	bl sub_0802AB08
	ldr r0, _0802B628
	ldr r1, [r0]
	b _0802B638
	.align 2, 0
_0802B624: .4byte 0x03002360
_0802B628: .4byte 0x020229B0
_0802B62C:
	movs r0, #1
	bl sub_0802BE24
	cmp r0, #1
	bne _0802B64E
	ldr r1, [r5]
_0802B638:
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	b _0802B64E
_0802B640:
	movs r0, #0
	bl sub_0802BE24
	cmp r0, #1
	bne _0802B64E
	ldr r0, [r5]
	strh r4, [r0, #0xa]
_0802B64E:
	movs r0, #1
_0802B650:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802B5C0

	thumb_func_start sub_0802B658
sub_0802B658: @ 0x0802B658
	push {r4, r5, r6, lr}
	ldr r1, _0802B670
	ldr r0, [r1]
	ldrh r0, [r0, #0xa]
	adds r5, r1, #0
	cmp r0, #4
	bhi _0802B744
	lsls r0, r0, #2
	ldr r1, _0802B674
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802B670: .4byte 0x020229B0
_0802B674: .4byte 0x0802B678
_0802B678: @ jump table
	.4byte _0802B68C @ case 0
	.4byte _0802B6B0 @ case 1
	.4byte _0802B6F4 @ case 2
	.4byte _0802B718 @ case 3
	.4byte _0802B73A @ case 4
_0802B68C:
	movs r4, #0
	ldr r0, [r5]
	ldrb r0, [r0, #5]
	cmp r4, r0
	bge _0802B6AC
	adds r6, r5, #0
_0802B698:
	adds r0, r4, #0
	bl sub_0802DAB0
	cmp r0, #1
	beq _0802B744
	adds r4, #1
	ldr r0, [r6]
	ldrb r0, [r0, #5]
	cmp r4, r0
	blt _0802B698
_0802B6AC:
	ldr r1, [r5]
	b _0802B710
_0802B6B0:
	movs r4, #0
	ldr r0, [r5]
	ldrb r0, [r0, #5]
	cmp r4, r0
	bge _0802B6E0
	adds r6, r5, #0
	movs r5, #0
_0802B6BE:
	ldr r0, [r6]
	adds r0, r0, r5
	ldr r1, _0802B6EC
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _0802B6D4
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_0802DA98
_0802B6D4:
	adds r5, #0x24
	adds r4, #1
	ldr r0, [r6]
	ldrb r0, [r0, #5]
	cmp r4, r0
	blt _0802B6BE
_0802B6E0:
	movs r0, #1
	bl sub_0802CDBC
	ldr r0, _0802B6F0
	ldr r1, [r0]
	b _0802B70C
	.align 2, 0
_0802B6EC: .4byte 0x000082F4
_0802B6F0: .4byte 0x020229B0
_0802B6F4:
	ldr r1, [r5]
	ldrh r0, [r1, #0x3c]
	adds r0, #1
	strh r0, [r1, #0x3c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x64
	bls _0802B744
	movs r0, #3
	bl sub_0802CDBC
	ldr r1, [r5]
_0802B70C:
	movs r0, #0
	strh r0, [r1, #0x3c]
_0802B710:
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	b _0802B744
_0802B718:
	bl sub_0802CDE4
	adds r5, r0, #0
	cmp r5, #0
	bne _0802B744
	bl sub_0802DAC4
	ldr r4, _0802B740
	ldr r0, [r4]
	adds r0, #0x71
	strb r5, [r0]
	bl sub_0802BE08
	ldr r1, [r4]
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
_0802B73A:
	movs r0, #0
	b _0802B746
	.align 2, 0
_0802B740: .4byte 0x020229B0
_0802B744:
	movs r0, #1
_0802B746:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_0802B658

	thumb_func_start sub_0802B74C
sub_0802B74C: @ 0x0802B74C
	push {r4, lr}
	ldr r1, _0802B768
	ldr r0, [r1]
	ldrh r0, [r0, #0xa]
	adds r4, r1, #0
	cmp r0, #6
	bls _0802B75C
	b _0802B870
_0802B75C:
	lsls r0, r0, #2
	ldr r1, _0802B76C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802B768: .4byte 0x020229B0
_0802B76C: .4byte 0x0802B770
_0802B770: @ jump table
	.4byte _0802B78C @ case 0
	.4byte _0802B7AC @ case 1
	.4byte _0802B7C4 @ case 2
	.4byte _0802B7F4 @ case 3
	.4byte _0802B7AC @ case 4
	.4byte _0802B7C4 @ case 5
	.4byte _0802B864 @ case 6
_0802B78C:
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0x72
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x3e
	adds r2, #0x40
	bl sub_0802C4FC
	ldr r1, [r4]
	ldrh r0, [r1, #0x3e]
	adds r1, #0x40
	ldrh r1, [r1]
	bl sub_0802D4DC
	b _0802B7E4
_0802B7AC:
	bl sub_0802D664
	adds r2, r0, #0
	cmp r2, #0
	bne _0802B870
	ldr r0, _0802B7C0
	ldr r1, [r0]
	strh r2, [r1, #0x3c]
	b _0802B7E6
	.align 2, 0
_0802B7C0: .4byte 0x020229B0
_0802B7C4:
	ldr r1, [r4]
	ldrh r0, [r1, #0x3c]
	adds r2, r0, #1
	strh r2, [r1, #0x3c]
	ldr r0, _0802B7F0
	ldrh r1, [r0, #0x2e]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _0802B7E0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb4
	bls _0802B870
_0802B7E0:
	bl sub_0802D704
_0802B7E4:
	ldr r1, [r4]
_0802B7E6:
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	b _0802B870
	.align 2, 0
_0802B7F0: .4byte 0x03002360
_0802B7F4:
	bl sub_0802D734
	cmp r0, #0
	bne _0802B870
	ldr r4, _0802B840
	ldr r1, [r4]
	ldrh r0, [r1, #0x3e]
	adds r1, #0x40
	ldrh r1, [r1]
	bl sub_0802C574
	ldr r1, [r4]
	adds r2, r1, #0
	adds r2, #0x40
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0802B84C
	ldrh r0, [r1, #0x3e]
	ldrh r1, [r2]
	bl AddBagItem
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802B84C
	ldr r0, [r4]
	ldrh r0, [r0, #0x3e]
	movs r1, #1
	bl CheckBagHasSpace
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802B844
	ldr r0, [r4]
	ldrh r0, [r0, #0x3e]
	bl sub_0802D574
	b _0802B856
	.align 2, 0
_0802B840: .4byte 0x020229B0
_0802B844:
	ldr r1, [r4]
	movs r0, #6
	strh r0, [r1, #0xa]
	b _0802B870
_0802B84C:
	ldr r4, _0802B860
	ldr r0, [r4]
	ldrh r0, [r0, #0x3e]
	bl sub_0802D5EC
_0802B856:
	ldr r1, [r4]
	movs r0, #4
	strh r0, [r1, #0xa]
	b _0802B870
	.align 2, 0
_0802B860: .4byte 0x020229B0
_0802B864:
	bl sub_0802D734
	cmp r0, #0
	bne _0802B870
	movs r0, #0
	b _0802B872
_0802B870:
	movs r0, #1
_0802B872:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802B74C

	thumb_func_start sub_0802B878
sub_0802B878: @ 0x0802B878
	push {r4, lr}
	ldr r0, _0802B890
	ldr r0, [r0]
	ldrh r0, [r0, #0xa]
	cmp r0, #6
	bhi _0802B94C
	lsls r0, r0, #2
	ldr r1, _0802B894
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802B890: .4byte 0x020229B0
_0802B894: .4byte 0x0802B898
_0802B898: @ jump table
	.4byte _0802B8B4 @ case 0
	.4byte _0802B8B8 @ case 1
	.4byte _0802B8C2 @ case 2
	.4byte _0802B910 @ case 3
	.4byte _0802B91A @ case 4
	.4byte _0802B930 @ case 5
	.4byte _0802B942 @ case 6
_0802B8B4:
	movs r0, #4
	b _0802B91C
_0802B8B8:
	bl sub_0802CDE4
	cmp r0, #0
	bne _0802B94C
	b _0802B920
_0802B8C2:
	bl sub_0802D77C
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #0
	beq _0802B8F8
	cmp r1, #0
	bgt _0802B8DC
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0802B8E0
	b _0802B94C
_0802B8DC:
	cmp r1, #1
	bne _0802B94C
_0802B8E0:
	ldr r4, _0802B8F4
	ldr r0, [r4]
	adds r0, #0x45
	movs r1, #1
	strb r1, [r0]
	movs r0, #6
	bl sub_0802CDBC
	ldr r1, [r4]
	b _0802B924
	.align 2, 0
_0802B8F4: .4byte 0x020229B0
_0802B8F8:
	ldr r4, _0802B90C
	ldr r0, [r4]
	adds r0, #0x45
	movs r1, #2
	strb r1, [r0]
	movs r0, #6
	bl sub_0802CDBC
	ldr r1, [r4]
	b _0802B924
	.align 2, 0
_0802B90C: .4byte 0x020229B0
_0802B910:
	bl sub_0802CDE4
	cmp r0, #0
	bne _0802B94C
	b _0802B920
_0802B91A:
	movs r0, #8
_0802B91C:
	bl sub_0802CDBC
_0802B920:
	ldr r0, _0802B92C
	ldr r1, [r0]
_0802B924:
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	b _0802B94C
	.align 2, 0
_0802B92C: .4byte 0x020229B0
_0802B930:
	bl sub_0802CDE4
	cmp r0, #0
	bne _0802B94C
	ldr r0, _0802B948
	ldr r1, [r0]
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
_0802B942:
	movs r0, #0
	b _0802B94E
	.align 2, 0
_0802B948: .4byte 0x020229B0
_0802B94C:
	movs r0, #1
_0802B94E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802B878

	thumb_func_start sub_0802B954
sub_0802B954: @ 0x0802B954
	push {r4, lr}
	sub sp, #4
	ldr r1, _0802B970
	ldr r0, [r1]
	ldrh r0, [r0, #0xa]
	adds r4, r1, #0
	cmp r0, #5
	bhi _0802BA18
	lsls r0, r0, #2
	ldr r1, _0802B974
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802B970: .4byte 0x020229B0
_0802B974: .4byte 0x0802B978
_0802B978: @ jump table
	.4byte _0802B990 @ case 0
	.4byte _0802B996 @ case 1
	.4byte _0802B9A6 @ case 2
	.4byte _0802B9BC @ case 3
	.4byte _0802B9E2 @ case 4
	.4byte _0802BA08 @ case 5
_0802B990:
	bl sub_0802D704
	b _0802B9F2
_0802B996:
	bl sub_0802D734
	cmp r0, #0
	bne _0802BA18
	movs r0, #7
	bl sub_0802CDBC
	b _0802B9F2
_0802B9A6:
	bl sub_0802CDE4
	adds r2, r0, #0
	cmp r2, #0
	bne _0802BA18
	ldr r0, _0802B9B8
	ldr r1, [r0]
	strh r2, [r1, #0x3c]
	b _0802B9F6
	.align 2, 0
_0802B9B8: .4byte 0x020229B0
_0802B9BC:
	ldr r1, [r4]
	ldrh r0, [r1, #0x3c]
	adds r0, #1
	strh r0, [r1, #0x3c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x78
	bls _0802BA18
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r1, #0
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r1, [r4]
	b _0802B9F6
_0802B9E2:
	ldr r0, _0802BA00
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0802BA18
	bl SetCloseLinkCallback
_0802B9F2:
	ldr r0, _0802BA04
	ldr r1, [r0]
_0802B9F6:
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	b _0802BA18
	.align 2, 0
_0802BA00: .4byte 0x02037C74
_0802BA04: .4byte 0x020229B0
_0802BA08:
	ldr r0, _0802BA14
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802BA18
	movs r0, #0
	b _0802BA1A
	.align 2, 0
_0802BA14: .4byte 0x030031C4
_0802BA18:
	movs r0, #1
_0802BA1A:
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802B954

	thumb_func_start sub_0802BA24
sub_0802BA24: @ 0x0802BA24
	push {r4, lr}
	ldr r4, _0802BA3C
	ldr r0, [r4]
	ldrh r0, [r0, #0xa]
	cmp r0, #1
	beq _0802BA5A
	cmp r0, #1
	bgt _0802BA40
	cmp r0, #0
	beq _0802BA46
	b _0802BA6E
	.align 2, 0
_0802BA3C: .4byte 0x020229B0
_0802BA40:
	cmp r0, #2
	beq _0802BA6A
	b _0802BA6E
_0802BA46:
	bl sub_0802D704
	movs r0, #0
	bl sub_0802DA5C
	ldr r1, [r4]
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	b _0802BA6E
_0802BA5A:
	bl sub_0802D734
	cmp r0, #0
	bne _0802BA6E
	ldr r1, [r4]
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
_0802BA6A:
	movs r0, #0
	b _0802BA70
_0802BA6E:
	movs r0, #1
_0802BA70:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802BA24

	thumb_func_start sub_0802BA78
sub_0802BA78: @ 0x0802BA78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsls r0, r0, #2
	add r0, sl
	lsls r0, r0, #3
	ldr r1, _0802BAAC
	adds r6, r0, r1
	mov r0, sl
	movs r1, #0xe
	bl GetWordTaskArg
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _0802BABC
	cmp r0, #1
	beq _0802BAD0
	b _0802BB3C
	.align 2, 0
_0802BAAC: .4byte 0x03005B68
_0802BAB0:
	bl sub_0802A814
	mov r0, sl
	bl DestroyTask
	b _0802BB3C
_0802BABC:
	movs r1, #0
	adds r0, r6, #0
	adds r0, #8
_0802BAC2:
	strh r1, [r0, #4]
	subs r0, #2
	cmp r0, r6
	bge _0802BAC2
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
_0802BAD0:
	mov r3, r8
	ldrb r1, [r3, #6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0802BB4C
	adds r0, r0, r4
	add r0, r8
	bl sub_0802DDA4
	movs r2, #0
	adds r5, r6, #4
	mov sb, r2
	movs r7, #0x83
	lsls r7, r7, #8
	add r7, r8
	add r4, r8
_0802BAF2:
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _0802BB2C
	adds r0, r2, #0
	adds r1, r4, #0
	str r2, [sp]
	bl sub_0802DDC8
	ldr r2, [sp]
	cmp r0, #0
	beq _0802BB2C
	ldr r1, _0802BB50
	add r1, sb
	adds r0, r7, #0
	bl StringCopy
	movs r0, #1
	strh r0, [r5]
	ldrh r0, [r6, #2]
	adds r0, #1
	strh r0, [r6, #2]
	movs r3, #2
	ldrsh r0, [r6, r3]
	ldr r2, [sp]
	mov r1, r8
	ldrb r1, [r1, #5]
	cmp r0, r1
	beq _0802BAB0
_0802BB2C:
	adds r5, #2
	movs r3, #0x1c
	add sb, r3
	adds r7, #0x24
	adds r4, #0xc
	adds r2, #1
	cmp r2, #4
	ble _0802BAF2
_0802BB3C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802BB4C: .4byte 0x000082A8
_0802BB50: .4byte 0x020226A8
	thumb_func_end sub_0802BA78

	thumb_func_start sub_0802BB54
sub_0802BB54: @ 0x0802BB54
	push {lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0802BB70
	ldr r2, [r1]
	movs r1, #0xe
	bl SetWordTaskArg
	pop {r0}
	bx r0
	.align 2, 0
_0802BB70: .4byte 0x020229B0
	thumb_func_end sub_0802BB54

	thumb_func_start sub_0802BB74
sub_0802BB74: @ 0x0802BB74
	ldr r0, _0802BB90
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x4a
	movs r1, #0
	strh r1, [r0]
	movs r0, #6
	str r0, [r2, #0x14]
	strh r1, [r2, #0x34]
	str r1, [r2, #0x1c]
	strh r1, [r2, #0x36]
	str r1, [r2, #0x10]
	bx lr
	.align 2, 0
_0802BB90: .4byte 0x020229B0
	thumb_func_end sub_0802BB74

	thumb_func_start sub_0802BB94
sub_0802BB94: @ 0x0802BB94
	push {r4, lr}
	ldr r3, _0802BBD0
	ldr r0, [r3]
	adds r1, r0, #0
	adds r1, #0x4a
	movs r4, #0
	movs r2, #0
	strh r2, [r1]
	ldr r1, _0802BBD4
	strh r1, [r0, #0x34]
	movs r1, #7
	str r1, [r0, #0x14]
	strh r2, [r0, #0x36]
	str r2, [r0, #0x10]
	adds r0, #0x51
	strb r4, [r0]
	ldr r0, [r3]
	adds r0, #0x50
	strb r4, [r0]
	ldr r0, [r3]
	str r2, [r0, #0x20]
	adds r1, r0, #0
	adds r1, #0x4e
	strh r2, [r1]
	str r2, [r0, #0x6c]
	bl sub_0802BC70
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802BBD0: .4byte 0x020229B0
_0802BBD4: .4byte 0x000006FF
	thumb_func_end sub_0802BB94

	thumb_func_start sub_0802BBD8
sub_0802BBD8: @ 0x0802BBD8
	push {r4, lr}
	ldr r4, _0802BC30
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x46
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BC28
	adds r1, #0x4a
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bl sub_0802BC3C
	ldr r3, [r4]
	ldrh r1, [r3, #0x34]
	adds r2, r1, r0
	strh r2, [r3, #0x34]
	lsls r1, r2, #0x10
	ldr r0, _0802BC34
	cmp r1, r0
	bls _0802BC0A
	ldr r1, _0802BC38
	adds r0, r2, r1
	strh r0, [r3, #0x34]
_0802BC0A:
	ldr r1, [r4]
	ldr r2, [r1, #0x14]
	str r2, [r1, #0x18]
	ldrh r0, [r1, #0x34]
	lsrs r0, r0, #8
	str r0, [r1, #0x14]
	cmp r0, #6
	bls _0802BC28
	cmp r2, #6
	bhi _0802BC28
	ldrh r0, [r1, #0x36]
	adds r0, #1
	strh r0, [r1, #0x36]
	bl sub_0802BC70
_0802BC28:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802BC30: .4byte 0x020229B0
_0802BC34: .4byte 0x09FE0000
_0802BC38: .4byte 0xFFFFF601
	thumb_func_end sub_0802BBD8

	thumb_func_start sub_0802BC3C
sub_0802BC3C: @ 0x0802BC3C
	push {lr}
	ldr r0, _0802BC4C
	ldr r2, [r0]
	ldr r0, [r2, #0x10]
	cmp r0, #0
	beq _0802BC50
	movs r0, #0
	b _0802BC66
	.align 2, 0
_0802BC4C: .4byte 0x020229B0
_0802BC50:
	ldr r3, [r2, #0x1c]
	ldrh r1, [r2, #0x34]
	ldr r0, _0802BC6C
	cmp r1, r0
	bhi _0802BC64
	ldr r0, [r2, #0x20]
	adds r0, #0x50
	str r0, [r2, #0x20]
	lsrs r0, r0, #8
	adds r3, r3, r0
_0802BC64:
	adds r0, r3, #0
_0802BC66:
	pop {r1}
	bx r1
	.align 2, 0
_0802BC6C: .4byte 0x000005FF
	thumb_func_end sub_0802BC3C

	thumb_func_start sub_0802BC70
sub_0802BC70: @ 0x0802BC70
	push {r4, lr}
	ldr r4, _0802BCA0
	ldr r3, [r4]
	movs r0, #0
	str r0, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x4e
	ldrh r0, [r1]
	cmp r0, #0
	beq _0802BCB4
	subs r0, #1
	strh r0, [r1]
	ldr r0, [r3, #0x6c]
	cmp r0, #0
	beq _0802BD7E
	bl sub_0802BD8C
	movs r1, #3
	ands r1, r0
	cmp r1, #0
	beq _0802BCA4
	ldr r1, [r4]
	b _0802BD7A
	.align 2, 0
_0802BCA0: .4byte 0x020229B0
_0802BCA4:
	ldr r1, [r4]
	ldr r0, [r1, #0x28]
	cmp r0, #0x36
	bls _0802BCB0
	movs r0, #0x1e
	b _0802BD7C
_0802BCB0:
	movs r0, #0x52
	b _0802BD7C
_0802BCB4:
	adds r2, r3, #0
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0802BD08
	ldr r0, _0802BD00
	ldrb r1, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	adds r0, r3, #0
	adds r0, #0x51
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [r3, #0x28]
	bl sub_0802BD8C
	ldr r2, [r4]
	ldr r3, _0802BD04
	movs r1, #3
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r0, [r1]
	adds r0, #2
	adds r1, r2, #0
	adds r1, #0x4e
	strh r0, [r1]
	adds r2, #0x50
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	b _0802BD76
	.align 2, 0
_0802BD00: .4byte 0x082CEEC8
_0802BD04: .4byte 0x082CEED8
_0802BD08:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _0802BD24
	adds r1, r3, #0
	adds r1, #0x51
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0802BD20
	adds r0, #1
	strb r0, [r1]
	b _0802BD24
_0802BD20:
	movs r0, #1
	str r0, [r3, #0x6c]
_0802BD24:
	ldr r2, _0802BD84
	ldr r4, _0802BD88
	ldr r0, [r4]
	mov ip, r0
	mov r3, ip
	adds r3, #0x50
	ldrb r0, [r3]
	movs r1, #0xf
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	mov r0, ip
	adds r0, #0x51
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, ip
	str r0, [r1, #0x28]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0802BD76
	bl sub_0802BD8C
	movs r1, #3
	ands r1, r0
	cmp r1, #0
	bne _0802BD6E
	ldr r1, [r4]
	ldr r0, [r1, #0x28]
	subs r0, #5
	str r0, [r1, #0x28]
_0802BD6E:
	ldr r0, [r4]
	adds r0, #0x50
	movs r1, #0
	strb r1, [r0]
_0802BD76:
	ldr r0, _0802BD88
	ldr r1, [r0]
_0802BD7A:
	ldr r0, [r1, #0x28]
_0802BD7C:
	str r0, [r1, #0x1c]
_0802BD7E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802BD84: .4byte 0x082CEEC8
_0802BD88: .4byte 0x020229B0
	thumb_func_end sub_0802BC70

	thumb_func_start sub_0802BD8C
sub_0802BD8C: @ 0x0802BD8C
	ldr r0, _0802BDA0
	ldr r2, [r0]
	ldr r1, [r2, #0x24]
	ldr r0, _0802BDA4
	muls r0, r1, r0
	ldr r1, _0802BDA8
	adds r0, r0, r1
	str r0, [r2, #0x24]
	lsrs r0, r0, #0x10
	bx lr
	.align 2, 0
_0802BDA0: .4byte 0x020229B0
_0802BDA4: .4byte 0x41C64E6D
_0802BDA8: .4byte 0x00006073
	thumb_func_end sub_0802BD8C

	thumb_func_start sub_0802BDAC
sub_0802BDAC: @ 0x0802BDAC
	push {lr}
	ldr r0, _0802BDC8
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x10]
	movs r0, #6
	str r0, [r1, #0x14]
	ldr r0, _0802BDCC
	strh r0, [r1, #0x34]
	bl sub_0802BF64
	pop {r0}
	bx r0
	.align 2, 0
_0802BDC8: .4byte 0x020229B0
_0802BDCC: .4byte 0x000005FF
	thumb_func_end sub_0802BDAC

	thumb_func_start sub_0802BDD0
sub_0802BDD0: @ 0x0802BDD0
	ldr r0, _0802BDD8
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	bx lr
	.align 2, 0
_0802BDD8: .4byte 0x020229B0
	thumb_func_end sub_0802BDD0
