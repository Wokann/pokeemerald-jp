.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified



thumb_func_start sub_0829B7CC
sub_0829B7CC: @ 0x0829B7CC
	adds r3, r0, #0
	movs r1, #0
	ldr r2, _0829B7D4
	b _0829B7E0
	.align 2, 0
_0829B7D4: .4byte 0x03001AB0
_0829B7D8:
	adds r2, #8
	adds r1, #1
	cmp r1, #0x13
	bgt _0829B7E6
_0829B7E0:
	ldr r0, [r2]
	cmp r0, r3
	bne _0829B7D8
_0829B7E6:
	adds r0, r1, #0
	bx lr
	.align 2, 0
	thumb_func_end sub_0829B7CC

thumb_func_start sub_0829B7EC
sub_0829B7EC: @ 0x0829B7EC
	adds r2, r0, #0
	ldr r0, _0829B800
	ldr r1, [r0]
	ldr r0, [r1, #4]
	movs r3, #0xe
	ldrsh r0, [r0, r3]
	cmp r2, r0
	bne _0829B808
	ldr r0, _0829B804
	b _0829B82E
	.align 2, 0
_0829B800: .4byte 0x0203CF1C
_0829B804: .4byte 0x03001AA4
_0829B808:
	ldr r0, [r1, #8]
	movs r3, #0xe
	ldrsh r0, [r0, r3]
	cmp r2, r0
	bne _0829B81C
	ldr r0, _0829B818
	b _0829B82E
	.align 2, 0
_0829B818: .4byte 0x03001AA8
_0829B81C:
	ldr r0, [r1, #0xc]
	movs r1, #0xe
	ldrsh r0, [r0, r1]
	cmp r2, r0
	beq _0829B82C
	adds r0, r2, #0
	subs r0, #0x20
	b _0829B830
_0829B82C:
	ldr r0, _0829B834
_0829B82E:
	ldr r0, [r0]
_0829B830:
	bx lr
	.align 2, 0
_0829B834: .4byte 0x03001AAC
	thumb_func_end sub_0829B7EC

thumb_func_start initialise_monitor_handles
initialise_monitor_handles: @ 0x0829B838
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r4, _0829B894
	str r4, [sp]
	movs r3, #3
	str r3, [sp, #8]
	movs r0, #0
	str r0, [sp, #4]
	movs r5, #1
	adds r0, r5, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	ldr r5, _0829B898
	str r2, [r5]
	str r4, [sp]
	str r3, [sp, #8]
	movs r0, #4
	str r0, [sp, #4]
	ldr r3, _0829B89C
	movs r4, #1
	adds r0, r4, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	ldr r0, _0829B8A0
	str r2, [r0]
	str r2, [r3]
	ldr r2, _0829B8A4
	adds r1, r2, #0
	subs r4, #2
	adds r0, r2, #0
	adds r0, #0x98
_0829B87A:
	str r4, [r0]
	subs r0, #8
	cmp r0, r1
	bge _0829B87A
	movs r0, #0
	ldr r1, [r5]
	str r1, [r2]
	str r0, [r2, #4]
	ldr r1, [r3]
	str r1, [r2, #8]
	str r0, [r2, #0xc]
	add sp, #0xc
	pop {r4, r5, pc}
	.align 2, 0
_0829B894: .4byte 0x0890F34C
_0829B898: .4byte 0x03001AA4
_0829B89C: .4byte 0x03001AA8
_0829B8A0: .4byte 0x03001AAC
_0829B8A4: .4byte 0x03001AB0
	thumb_func_end initialise_monitor_handles

thumb_func_start sub_0829B8A8
sub_0829B8A8: @ 0x0829B8A8
	push {r4, lr}
	movs r3, #0x13
	movs r4, #0
	adds r0, r3, #0
	adds r1, r4, #0
	svc #0xab
	adds r2, r0, #0
	adds r0, r2, #0
	pop {r4, pc}
	.align 2, 0
	thumb_func_end sub_0829B8A8

thumb_func_start sub_0829B8BC
sub_0829B8BC: @ 0x0829B8BC
	push {r4, r5, lr}
	adds r5, r0, #0
	bl __errno
	adds r4, r0, #0
	bl sub_0829B8A8
	str r0, [r4]
	adds r0, r5, #0
	pop {r4, r5, pc}
	thumb_func_end sub_0829B8BC

thumb_func_start sub_0829B8D0
sub_0829B8D0: @ 0x0829B8D0
	push {lr}
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0829B8E0
	adds r0, r1, #0
	b _0829B8E6
_0829B8E0:
	adds r0, r1, #0
	bl sub_0829B8BC
_0829B8E6:
	pop {pc}
	thumb_func_end sub_0829B8D0

thumb_func_start _swiread
_swiread: @ 0x0829B8E8
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r1, #0
	adds r5, r2, #0
	bl sub_0829B7EC
	str r0, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r3, #6
	adds r0, r3, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	adds r0, r2, #0
	add sp, #0xc
	pop {r4, r5, pc}
	.align 2, 0
	thumb_func_end _swiread

thumb_func_start _read
_read: @ 0x0829B90C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	bl sub_0829B7EC
	bl sub_0829B7CC
	adds r6, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl _swiread
	cmp r0, #0
	bge _0829B936
	movs r0, #1
	rsbs r0, r0, #0
	bl sub_0829B8BC
	b _0829B94C
_0829B936:
	subs r2, r7, r0
	cmp r6, #0x14
	beq _0829B94A
	ldr r0, _0829B950
	lsls r1, r6, #3
	adds r0, #4
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
_0829B94A:
	adds r0, r2, #0
_0829B94C:
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0829B950: .4byte 0x03001AB0
	thumb_func_end _read

thumb_func_start _swilseek
_swilseek: @ 0x0829B954
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r5, r1, #0
	adds r4, r2, #0
	bl sub_0829B7EC
	adds r7, r0, #0
	bl sub_0829B7CC
	adds r6, r0, #0
	cmp r4, #1
	bne _0829B98A
	cmp r6, #0x14
	bne _0829B97C
	movs r0, #1
	rsbs r0, r0, #0
	b _0829B9CC
_0829B97C:
	ldr r0, _0829B9D4
	lsls r1, r6, #3
	adds r0, #4
	adds r1, r1, r0
	ldr r0, [r1]
	adds r5, r5, r0
	movs r4, #0
_0829B98A:
	cmp r4, #2
	bne _0829B99C
	str r7, [sp]
	movs r3, #0xc
	adds r0, r3, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	adds r5, r5, r2
_0829B99C:
	mov r0, r8
	bl sub_0829B7EC
	str r0, [sp]
	str r5, [sp, #4]
	movs r3, #0xa
	adds r0, r3, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	cmp r6, #0x14
	beq _0829B9C2
	cmp r2, #0
	bne _0829B9C2
	ldr r0, _0829B9D4
	lsls r1, r6, #3
	adds r0, #4
	adds r1, r1, r0
	str r5, [r1]
_0829B9C2:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, #0
	bne _0829B9CC
	adds r0, r5, #0
_0829B9CC:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0829B9D4: .4byte 0x03001AB0
	thumb_func_end _swilseek

thumb_func_start _lseek
_lseek: @ 0x0829B9D8
	push {lr}
	bl _swilseek
	bl sub_0829B8D0
	pop {pc}
	thumb_func_end _lseek

thumb_func_start _swiwrite
_swiwrite: @ 0x0829B9E4
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r1, #0
	adds r5, r2, #0
	bl sub_0829B7EC
	str r0, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	movs r3, #5
	adds r0, r3, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	adds r0, r2, #0
	add sp, #0xc
	pop {r4, r5, pc}
	.align 2, 0
	thumb_func_end _swiwrite

thumb_func_start _write
_write: @ 0x0829BA08
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	bl sub_0829B7EC
	bl sub_0829B7CC
	adds r7, r0, #0
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl _swiwrite
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _0829BA30
	cmp r0, r6
	bne _0829BA38
_0829BA30:
	adds r0, r1, #0
	bl sub_0829B8BC
	b _0829BA4E
_0829BA38:
	subs r2, r6, r0
	cmp r7, #0x14
	beq _0829BA4C
	ldr r0, _0829BA50
	lsls r1, r7, #3
	adds r0, #4
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
_0829BA4C:
	adds r0, r2, #0
_0829BA4E:
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0829BA50: .4byte 0x03001AB0
	thumb_func_end _write

thumb_func_start _swiopen
_swiopen: @ 0x0829BA54
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	adds r4, r1, #0
	movs r5, #0
	movs r6, #1
	rsbs r6, r6, #0
	adds r0, r6, #0
	bl sub_0829B7CC
	mov r8, r0
	cmp r0, #0x14
	bne _0829BA76
	adds r0, r6, #0
	b _0829BAEA
_0829BA76:
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq _0829BA80
	movs r5, #2
_0829BA80:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r4
	cmp r0, #0
	beq _0829BA8E
	movs r0, #4
	orrs r5, r0
_0829BA8E:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r4
	cmp r0, #0
	beq _0829BA9C
	movs r0, #4
	orrs r5, r0
_0829BA9C:
	movs r1, #8
	ands r4, r1
	cmp r4, #0
	beq _0829BAAC
	movs r0, #5
	rsbs r0, r0, #0
	ands r5, r0
	orrs r5, r1
_0829BAAC:
	str r7, [sp]
	adds r0, r7, #0
	bl strlen
	str r0, [sp, #8]
	str r5, [sp, #4]
	movs r2, #1
	adds r0, r2, #0
	mov r1, sp
	svc #0xab
	adds r3, r0, #0
	cmp r3, #0
	blt _0829BAE4
	ldr r0, _0829BAE0
	mov r1, r8
	lsls r2, r1, #3
	adds r1, r2, r0
	str r3, [r1]
	adds r0, #4
	adds r2, r2, r0
	movs r0, #0
	str r0, [r2]
	adds r0, r3, #0
	adds r0, #0x20
	b _0829BAEA
	.align 2, 0
_0829BAE0: .4byte 0x03001AB0
_0829BAE4:
	adds r0, r3, #0
	bl sub_0829B8BC
_0829BAEA:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
	thumb_func_end _swiopen

thumb_func_start _open
_open: @ 0x0829BAF4
	push {r1, r2, r3}
	push {lr}
	ldr r1, [sp, #4]
	bl _swiopen
	bl sub_0829B8D0
	pop {r3}
	add sp, #0xc
	bx r3
	thumb_func_end _open

thumb_func_start _swiclose
_swiclose: @ 0x0829BB08
	push {lr}
	sub sp, #4
	bl sub_0829B7EC
	str r0, [sp]
	bl sub_0829B7CC
	adds r1, r0, #0
	cmp r1, #0x14
	beq _0829BB28
	ldr r0, _0829BB38
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
_0829BB28:
	movs r3, #2
	adds r0, r3, #0
	mov r1, sp
	svc #0xab
	adds r2, r0, #0
	adds r0, r2, #0
	add sp, #4
	pop {pc}
	.align 2, 0
_0829BB38: .4byte 0x03001AB0
	thumb_func_end _swiclose

thumb_func_start _close
_close: @ 0x0829BB3C
	push {lr}
	bl _swiclose
	bl sub_0829B8D0
	pop {pc}
	thumb_func_end _close

thumb_func_start _exit
_exit: @ 0x0829BB48
	mov ip, r3
	mov r3, r8
	push {r3}
	mov r3, ip
	movs r2, #0x18
	ldr r3, _0829BB64
	adds r0, r2, #0
	adds r1, r3, #0
	svc #0xab
	mov r8, r0
	pop {r3}
	mov r8, r3
	bx lr
	.align 2, 0
_0829BB64: .4byte 0x00020026
	thumb_func_end _exit

thumb_func_start _kill
_kill: @ 0x0829BB68
	mov ip, r3
	mov r3, r8
	push {r3}
	mov r3, ip
	movs r2, #0x18
	ldr r3, _0829BB84
	adds r0, r2, #0
	adds r1, r3, #0
	svc #0xab
	mov r8, r0
	pop {r3}
	mov r8, r3
	bx lr
	.align 2, 0
_0829BB84: .4byte 0x00020026
	thumb_func_end _kill

thumb_func_start _getpid
_getpid: @ 0x0829BB88
	movs r0, #1
	bx lr
	thumb_func_end _getpid

thumb_func_start _sbrk
_sbrk: @ 0x0829BB8C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, _0829BBBC
	ldr r0, [r4]
	cmp r0, #0
	bne _0829BB9C
	ldr r0, _0829BBC0
	str r0, [r4]
_0829BB9C:
	ldr r5, [r4]
	adds r0, r5, r6
	cmp r0, sp
	bls _0829BBB2
	ldr r1, _0829BBC4
	movs r0, #1
	movs r2, #0x20
	bl _write
	bl abort
_0829BBB2:
	ldr r0, [r4]
	adds r0, r0, r6
	str r0, [r4]
	adds r0, r5, #0
	pop {r4, r5, r6, pc}
	.align 2, 0
_0829BBBC: .4byte 0x03001AA0
_0829BBC0: .4byte 0x088BA568
_0829BBC4: .4byte 0x0890F350
	thumb_func_end _sbrk

thumb_func_start _fstat
_fstat: @ 0x0829BBC8
	movs r0, #0x80
	lsls r0, r0, #6
	str r0, [r1, #4]
	movs r0, #0
	bx lr
	.align 2, 0
	thumb_func_end _fstat

thumb_func_start _unlink
_unlink: @ 0x0829BBD4
	movs r0, #1
	rsbs r0, r0, #0
	bx lr
	.align 2, 0
	thumb_func_end _unlink

thumb_func_start _raise
_raise: @ 0x0829BBDC
	bx lr
	.align 2, 0
	thumb_func_end _raise

thumb_func_start _gettimeofday
_gettimeofday: @ 0x0829BBE0
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	cmp r2, #0
	beq _0829BBFE
	movs r4, #0x11
	movs r5, #0
	adds r0, r4, #0
	adds r1, r5, #0
	svc #0xab
	adds r5, r0, #0
	adds r4, r5, #0
	str r4, [r2]
	movs r0, #0
	str r0, [r2, #4]
_0829BBFE:
	cmp r3, #0
	beq _0829BC08
	movs r0, #0
	str r0, [r3]
	str r0, [r3, #4]
_0829BC08:
	movs r0, #0
	pop {r4, r5, pc}
	thumb_func_end _gettimeofday

thumb_func_start _times
_times: @ 0x0829BC0C
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r4, #0x10
	movs r5, #0
	adds r0, r4, #0
	adds r1, r5, #0
	svc #0xab
	adds r3, r0, #0
	cmp r2, #0
	beq _0829BC2A
	str r3, [r2]
	movs r0, #0
	str r0, [r2, #4]
	str r0, [r2, #8]
	str r0, [r2, #0xc]
_0829BC2A:
	adds r0, r3, #0
	pop {r4, r5, pc}
	.align 2, 0
	thumb_func_end _times

thumb_func_start _write_r
_write_r: @ 0x0829BC30
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r4, _0829BC5C
	movs r3, #0
	str r3, [r4]
	bl _write
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0829BC56
	ldr r0, [r4]
	cmp r0, #0
	beq _0829BC56
	str r0, [r5]
_0829BC56:
	adds r0, r1, #0
	pop {r4, r5, pc}
	.align 2, 0
_0829BC5C: .4byte 0x0300764C
	thumb_func_end _write_r

thumb_func_start _calloc_r
_calloc_r: @ 0x0829BC60
	push {r4, lr}
	muls r1, r2, r1
	bl _malloc_r
	adds r4, r0, #0
	cmp r4, #0
	bne _0829BC72
	movs r0, #0
	b _0829BCB6
_0829BC72:
	adds r0, r4, #0
	subs r0, #8
	ldr r0, [r0, #4]
	movs r1, #4
	rsbs r1, r1, #0
	ands r0, r1
	subs r2, r0, #4
	cmp r2, #0x24
	bhi _0829BCAC
	adds r1, r4, #0
	cmp r2, #0x13
	bls _0829BCA2
	movs r0, #0
	stm r1!, {r0}
	str r0, [r4, #4]
	adds r1, #4
	cmp r2, #0x1b
	bls _0829BCA2
	stm r1!, {r0}
	stm r1!, {r0}
	cmp r2, #0x23
	bls _0829BCA2
	stm r1!, {r0}
	stm r1!, {r0}
_0829BCA2:
	movs r0, #0
	stm r1!, {r0}
	stm r1!, {r0}
	str r0, [r1]
	b _0829BCB4
_0829BCAC:
	adds r0, r4, #0
	movs r1, #0
	bl memset
_0829BCB4:
	adds r0, r4, #0
_0829BCB6:
	pop {r4, pc}
	thumb_func_end _calloc_r

thumb_func_start _close_r
_close_r: @ 0x0829BCB8
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	ldr r4, _0829BCE0
	movs r1, #0
	str r1, [r4]
	bl _close
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0829BCDA
	ldr r0, [r4]
	cmp r0, #0
	beq _0829BCDA
	str r0, [r5]
_0829BCDA:
	adds r0, r1, #0
	pop {r4, r5, pc}
	.align 2, 0
_0829BCE0: .4byte 0x0300764C
	thumb_func_end _close_r

thumb_func_start __errno
__errno: @ 0x0829BCE4
	ldr r0, _0829BCEC
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0829BCEC: .4byte 0x0203CF1C
	thumb_func_end __errno

thumb_func_start _fstat_r
_fstat_r: @ 0x0829BCF0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	adds r1, r2, #0
	ldr r4, _0829BD18
	movs r2, #0
	str r2, [r4]
	bl _fstat
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0829BD14
	ldr r0, [r4]
	cmp r0, #0
	beq _0829BD14
	str r0, [r5]
_0829BD14:
	adds r0, r1, #0
	pop {r4, r5, pc}
	.align 2, 0
_0829BD18: .4byte 0x0300764C
	thumb_func_end _fstat_r

thumb_func_start abort
abort: @ 0x0829BD1C
	mov ip, r3
	mov r3, r8
	push {r3}
	mov r3, ip
	movs r2, #0x18
	ldr r3, _0829BD38
	adds r0, r2, #0
	adds r1, r3, #0
	svc #0xab
	mov r8, r0
	pop {r3}
	mov r8, r3
	bx lr
	.align 2, 0
_0829BD38: .4byte 0x00020022
	thumb_func_end abort

thumb_func_start isatty
isatty: @ 0x0829BD3C
	movs r0, #1
	bx lr
	thumb_func_end isatty

thumb_func_start alarm
alarm: @ 0x0829BD40
	bx lr
	.align 2, 0
	thumb_func_end alarm

thumb_func_start _lseek_r
_lseek_r: @ 0x0829BD44
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r4, _0829BD70
	movs r3, #0
	str r3, [r4]
	bl _lseek
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0829BD6A
	ldr r0, [r4]
	cmp r0, #0
	beq _0829BD6A
	str r0, [r5]
_0829BD6A:
	adds r0, r1, #0
	pop {r4, r5, pc}
	.align 2, 0
_0829BD70: .4byte 0x0300764C
	thumb_func_end _lseek_r

thumb_func_start _read_r
_read_r: @ 0x0829BD74
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r4, _0829BDA0
	movs r3, #0
	str r3, [r4]
	bl _read
	adds r1, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0829BD9A
	ldr r0, [r4]
	cmp r0, #0
	beq _0829BD9A
	str r0, [r5]
_0829BD9A:
	adds r0, r1, #0
	pop {r4, r5, pc}
	.align 2, 0
_0829BDA0: .4byte 0x0300764C

