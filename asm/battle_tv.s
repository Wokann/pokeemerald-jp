.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start BattleTv_SetDataBasedOnString
BattleTv_SetDataBasedOnString: @ 0x0817C808
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r0, _0817C88C
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0817C834
	ldr r0, [sp]
	cmp r0, #0x1b
	beq _0817C834
	cmp r0, #0xdd
	beq _0817C834
	bl _0817DF52
_0817C834:
	ldr r0, _0817C890
	ldr r0, [r0]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r7, r0, r1
	ldr r5, _0817C894
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _0817C898
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _0817C89C
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r0, _0817C8A0
	ldr r0, [r0]
	ldrb r0, [r0, #7]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
	cmp r4, #0
	bne _0817C8AC
	ldr r2, _0817C8A4
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _0817C8A8
	b _0817C8BC
	.align 2, 0
_0817C88C: .4byte 0x02022C90
_0817C890: .4byte 0x02024140
_0817C894: .4byte 0x02023EAF
_0817C898: .4byte 0x02023EB0
_0817C89C: .4byte 0x02023EB2
_0817C8A0: .4byte 0x0203A874
_0817C8A4: .4byte 0x02023D12
_0817C8A8: .4byte 0x02024190
_0817C8AC:
	ldr r2, _0817C8D8
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _0817C8DC
_0817C8BC:
	adds r1, r1, r0
	str r1, [sp, #8]
	cmp r6, #0
	bne _0817C8E8
	ldr r0, _0817C8E0
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _0817C8E4
	b _0817C8F8
	.align 2, 0
_0817C8D8: .4byte 0x02023D12
_0817C8DC: .4byte 0x020243E8
_0817C8E0: .4byte 0x02023EB0
_0817C8E4: .4byte 0x02024190
_0817C8E8:
	ldr r0, _0817C938
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _0817C93C
_0817C8F8:
	adds r1, r1, r0
	str r1, [sp, #0xc]
	ldr r0, _0817C940
	ldrb r0, [r0]
	ldr r1, _0817C944
	ldr r1, [r1]
	ldrh r1, [r1]
	bl GetBattlerMoveSlotId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	cmp r0, #3
	bls _0817C948
	ldr r0, [sp]
	bl IsNotSpecialBattleString
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0817C948
	ldr r2, [sp]
	cmp r2, #0xc
	bls _0817C948
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r7, r0
	adds r0, #0x57
	ldrb r1, [r0]
	movs r2, #0x1e
	bl _0817DF4E
	.align 2, 0
_0817C938: .4byte 0x02023EB0
_0817C93C: .4byte 0x020243E8
_0817C940: .4byte 0x02023EAF
_0817C944: .4byte 0x0203A874
_0817C948:
	ldr r0, _0817C988
	ldrb r0, [r0]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x19
	mov r8, r0
	ldr r0, _0817C98C
	ldrb r0, [r0]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x19
	ldr r0, _0817C990
	ldrb r0, [r0]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x19
	ldr r1, [sp]
	subs r1, #2
	movs r0, #0xb0
	lsls r0, r0, #1
	cmp r1, r0
	bls _0817C97E
	bl _0817DF52
_0817C97E:
	lsls r0, r1, #2
	ldr r1, _0817C994
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0817C988: .4byte 0x02023EAF
_0817C98C: .4byte 0x02023EB0
_0817C990: .4byte 0x02023EB2
_0817C994: .4byte 0x0817C998
_0817C998: @ jump table
	.4byte _0817DC26 @ case 0
	.4byte _0817DF52 @ case 1
	.4byte _0817DF52 @ case 2
	.4byte _0817DF52 @ case 3
	.4byte _0817DF52 @ case 4
	.4byte _0817DF52 @ case 5
	.4byte _0817DF52 @ case 6
	.4byte _0817DF52 @ case 7
	.4byte _0817DF52 @ case 8
	.4byte _0817DF52 @ case 9
	.4byte _0817DF52 @ case 10
	.4byte _0817DF52 @ case 11
	.4byte _0817DF52 @ case 12
	.4byte _0817DF52 @ case 13
	.4byte _0817DF52 @ case 14
	.4byte _0817DF52 @ case 15
	.4byte _0817DF52 @ case 16
	.4byte _0817DF52 @ case 17
	.4byte _0817DF52 @ case 18
	.4byte _0817DF52 @ case 19
	.4byte _0817DF52 @ case 20
	.4byte _0817DF52 @ case 21
	.4byte _0817DF52 @ case 22
	.4byte _0817DF52 @ case 23
	.4byte _0817DF52 @ case 24
	.4byte _0817CF1C @ case 25
	.4byte _0817DC20 @ case 26
	.4byte _0817DC2C @ case 27
	.4byte _0817DF52 @ case 28
	.4byte _0817DF52 @ case 29
	.4byte _0817DF52 @ case 30
	.4byte _0817DF52 @ case 31
	.4byte _0817DF52 @ case 32
	.4byte _0817D914 @ case 33
	.4byte _0817DF52 @ case 34
	.4byte _0817DF52 @ case 35
	.4byte _0817DF52 @ case 36
	.4byte _0817DF52 @ case 37
	.4byte _0817D684 @ case 38
	.4byte _0817DF52 @ case 39
	.4byte _0817D750 @ case 40
	.4byte _0817DF52 @ case 41
	.4byte _0817D6E4 @ case 42
	.4byte _0817DF52 @ case 43
	.4byte _0817D5B0 @ case 44
	.4byte _0817DF52 @ case 45
	.4byte _0817D618 @ case 46
	.4byte _0817D9D0 @ case 47
	.4byte _0817DF52 @ case 48
	.4byte _0817DA3C @ case 49
	.4byte _0817DF52 @ case 50
	.4byte _0817DF52 @ case 51
	.4byte _0817DF52 @ case 52
	.4byte _0817D86E @ case 53
	.4byte _0817DF52 @ case 54
	.4byte _0817D8D0 @ case 55
	.4byte _0817DF52 @ case 56
	.4byte _0817DF52 @ case 57
	.4byte _0817DF52 @ case 58
	.4byte _0817DF52 @ case 59
	.4byte _0817DF52 @ case 60
	.4byte _0817DF52 @ case 61
	.4byte _0817DF52 @ case 62
	.4byte _0817DF52 @ case 63
	.4byte _0817DF52 @ case 64
	.4byte _0817DA80 @ case 65
	.4byte _0817DF52 @ case 66
	.4byte _0817D7F8 @ case 67
	.4byte _0817DF52 @ case 68
	.4byte _0817D840 @ case 69
	.4byte _0817DF52 @ case 70
	.4byte _0817DF52 @ case 71
	.4byte _0817DEEC @ case 72
	.4byte _0817DF52 @ case 73
	.4byte _0817DF52 @ case 74
	.4byte _0817DCBC @ case 75
	.4byte _0817DC74 @ case 76
	.4byte _0817DD88 @ case 77
	.4byte _0817DDD0 @ case 78
	.4byte _0817DDFA @ case 79
	.4byte _0817DF52 @ case 80
	.4byte _0817DF52 @ case 81
	.4byte _0817DF52 @ case 82
	.4byte _0817DF52 @ case 83
	.4byte _0817DF52 @ case 84
	.4byte _0817DF52 @ case 85
	.4byte _0817DF52 @ case 86
	.4byte _0817DF52 @ case 87
	.4byte _0817D50A @ case 88
	.4byte _0817D50A @ case 89
	.4byte _0817D50A @ case 90
	.4byte _0817D50A @ case 91
	.4byte _0817D544 @ case 92
	.4byte _0817DF52 @ case 93
	.4byte _0817DF3A @ case 94
	.4byte _0817DE1C @ case 95
	.4byte _0817DE68 @ case 96
	.4byte _0817DF52 @ case 97
	.4byte _0817DF3A @ case 98
	.4byte _0817DF52 @ case 99
	.4byte _0817DF52 @ case 100
	.4byte _0817DF52 @ case 101
	.4byte _0817D3E8 @ case 102
	.4byte _0817DF52 @ case 103
	.4byte _0817D430 @ case 104
	.4byte _0817D978 @ case 105
	.4byte _0817DF52 @ case 106
	.4byte _0817DF52 @ case 107
	.4byte _0817DF52 @ case 108
	.4byte _0817DF52 @ case 109
	.4byte _0817DF52 @ case 110
	.4byte _0817DF52 @ case 111
	.4byte _0817DF52 @ case 112
	.4byte _0817DF52 @ case 113
	.4byte _0817DF52 @ case 114
	.4byte _0817DF52 @ case 115
	.4byte _0817DF52 @ case 116
	.4byte _0817DF52 @ case 117
	.4byte _0817DF52 @ case 118
	.4byte _0817DF52 @ case 119
	.4byte _0817DF52 @ case 120
	.4byte _0817DF52 @ case 121
	.4byte _0817DF52 @ case 122
	.4byte _0817D252 @ case 123
	.4byte _0817DF52 @ case 124
	.4byte _0817DF52 @ case 125
	.4byte _0817DF52 @ case 126
	.4byte _0817DF52 @ case 127
	.4byte _0817DF52 @ case 128
	.4byte _0817DF52 @ case 129
	.4byte _0817DF52 @ case 130
	.4byte _0817DF52 @ case 131
	.4byte _0817DF52 @ case 132
	.4byte _0817DF52 @ case 133
	.4byte _0817DF52 @ case 134
	.4byte _0817DF52 @ case 135
	.4byte _0817DF52 @ case 136
	.4byte _0817D142 @ case 137
	.4byte _0817D190 @ case 138
	.4byte _0817DF52 @ case 139
	.4byte _0817DF52 @ case 140
	.4byte _0817DF52 @ case 141
	.4byte _0817D47A @ case 142
	.4byte _0817D4B4 @ case 143
	.4byte _0817D344 @ case 144
	.4byte _0817D38C @ case 145
	.4byte _0817DB0E @ case 146
	.4byte _0817DB44 @ case 147
	.4byte _0817DF52 @ case 148
	.4byte _0817D064 @ case 149
	.4byte _0817DF52 @ case 150
	.4byte _0817DF52 @ case 151
	.4byte _0817DF52 @ case 152
	.4byte _0817DF52 @ case 153
	.4byte _0817DF52 @ case 154
	.4byte _0817DF52 @ case 155
	.4byte _0817DF52 @ case 156
	.4byte _0817DB88 @ case 157
	.4byte _0817DF52 @ case 158
	.4byte _0817CF88 @ case 159
	.4byte _0817DF52 @ case 160
	.4byte _0817DF52 @ case 161
	.4byte _0817DF52 @ case 162
	.4byte _0817DF52 @ case 163
	.4byte _0817DF52 @ case 164
	.4byte _0817DF52 @ case 165
	.4byte _0817DF52 @ case 166
	.4byte _0817DF52 @ case 167
	.4byte _0817DF52 @ case 168
	.4byte _0817DF52 @ case 169
	.4byte _0817DF52 @ case 170
	.4byte _0817DF52 @ case 171
	.4byte _0817DF52 @ case 172
	.4byte _0817DF52 @ case 173
	.4byte _0817DF52 @ case 174
	.4byte _0817DF52 @ case 175
	.4byte _0817D08C @ case 176
	.4byte _0817D1C0 @ case 177
	.4byte _0817D200 @ case 178
	.4byte _0817D21E @ case 179
	.4byte _0817DF52 @ case 180
	.4byte _0817DF52 @ case 181
	.4byte _0817DF52 @ case 182
	.4byte _0817DF52 @ case 183
	.4byte _0817DF52 @ case 184
	.4byte _0817D0C2 @ case 185
	.4byte _0817D10C @ case 186
	.4byte _0817DF52 @ case 187
	.4byte _0817DF52 @ case 188
	.4byte _0817DF52 @ case 189
	.4byte _0817DF52 @ case 190
	.4byte _0817DF52 @ case 191
	.4byte _0817DF52 @ case 192
	.4byte _0817DF52 @ case 193
	.4byte _0817DF52 @ case 194
	.4byte _0817DF52 @ case 195
	.4byte _0817DF52 @ case 196
	.4byte _0817DF52 @ case 197
	.4byte _0817DF52 @ case 198
	.4byte _0817DF52 @ case 199
	.4byte _0817DF52 @ case 200
	.4byte _0817DF52 @ case 201
	.4byte _0817DF52 @ case 202
	.4byte _0817DF52 @ case 203
	.4byte _0817DF52 @ case 204
	.4byte _0817DF52 @ case 205
	.4byte _0817DF52 @ case 206
	.4byte _0817DF52 @ case 207
	.4byte _0817DF52 @ case 208
	.4byte _0817DF52 @ case 209
	.4byte _0817DF52 @ case 210
	.4byte _0817D26C @ case 211
	.4byte _0817D29E @ case 212
	.4byte _0817D2EC @ case 213
	.4byte _0817D308 @ case 214
	.4byte _0817D264 @ case 215
	.4byte _0817DF52 @ case 216
	.4byte _0817DF52 @ case 217
	.4byte _0817DF52 @ case 218
	.4byte _0817CF44 @ case 219
	.4byte _0817CF80 @ case 220
	.4byte _0817DF52 @ case 221
	.4byte _0817DF52 @ case 222
	.4byte _0817DF52 @ case 223
	.4byte _0817DF52 @ case 224
	.4byte _0817DF52 @ case 225
	.4byte _0817DF52 @ case 226
	.4byte _0817DF52 @ case 227
	.4byte _0817DACC @ case 228
	.4byte _0817DF52 @ case 229
	.4byte _0817DF52 @ case 230
	.4byte _0817DF52 @ case 231
	.4byte _0817DF52 @ case 232
	.4byte _0817DF52 @ case 233
	.4byte _0817DF52 @ case 234
	.4byte _0817DF52 @ case 235
	.4byte _0817DF52 @ case 236
	.4byte _0817DF52 @ case 237
	.4byte _0817DF52 @ case 238
	.4byte _0817DF52 @ case 239
	.4byte _0817DF52 @ case 240
	.4byte _0817DF52 @ case 241
	.4byte _0817DF52 @ case 242
	.4byte _0817DF52 @ case 243
	.4byte _0817DF52 @ case 244
	.4byte _0817DF52 @ case 245
	.4byte _0817DF52 @ case 246
	.4byte _0817DF52 @ case 247
	.4byte _0817DF52 @ case 248
	.4byte _0817DF52 @ case 249
	.4byte _0817DF52 @ case 250
	.4byte _0817DF52 @ case 251
	.4byte _0817D018 @ case 252
	.4byte _0817DF52 @ case 253
	.4byte _0817DF52 @ case 254
	.4byte _0817DF52 @ case 255
	.4byte _0817DF52 @ case 256
	.4byte _0817DF52 @ case 257
	.4byte _0817DF52 @ case 258
	.4byte _0817DF52 @ case 259
	.4byte _0817DF52 @ case 260
	.4byte _0817DF52 @ case 261
	.4byte _0817DF52 @ case 262
	.4byte _0817DF52 @ case 263
	.4byte _0817DF52 @ case 264
	.4byte _0817DF52 @ case 265
	.4byte _0817DF52 @ case 266
	.4byte _0817DF52 @ case 267
	.4byte _0817DF52 @ case 268
	.4byte _0817DF52 @ case 269
	.4byte _0817DF52 @ case 270
	.4byte _0817DF52 @ case 271
	.4byte _0817DF52 @ case 272
	.4byte _0817DF52 @ case 273
	.4byte _0817DF52 @ case 274
	.4byte _0817DF52 @ case 275
	.4byte _0817DF52 @ case 276
	.4byte _0817DF52 @ case 277
	.4byte _0817DF52 @ case 278
	.4byte _0817DF52 @ case 279
	.4byte _0817DF52 @ case 280
	.4byte _0817DF52 @ case 281
	.4byte _0817DF52 @ case 282
	.4byte _0817DF52 @ case 283
	.4byte _0817DF52 @ case 284
	.4byte _0817DF52 @ case 285
	.4byte _0817DF52 @ case 286
	.4byte _0817DF52 @ case 287
	.4byte _0817DF52 @ case 288
	.4byte _0817DF52 @ case 289
	.4byte _0817DF52 @ case 290
	.4byte _0817DF52 @ case 291
	.4byte _0817DF52 @ case 292
	.4byte _0817DF52 @ case 293
	.4byte _0817DF52 @ case 294
	.4byte _0817DF52 @ case 295
	.4byte _0817DF52 @ case 296
	.4byte _0817DF52 @ case 297
	.4byte _0817DF52 @ case 298
	.4byte _0817DF52 @ case 299
	.4byte _0817DF52 @ case 300
	.4byte _0817DF52 @ case 301
	.4byte _0817DF52 @ case 302
	.4byte _0817DF52 @ case 303
	.4byte _0817DF52 @ case 304
	.4byte _0817DF52 @ case 305
	.4byte _0817DF52 @ case 306
	.4byte _0817DF52 @ case 307
	.4byte _0817DF52 @ case 308
	.4byte _0817DF52 @ case 309
	.4byte _0817DF52 @ case 310
	.4byte _0817DF52 @ case 311
	.4byte _0817DF52 @ case 312
	.4byte _0817DBE4 @ case 313
	.4byte _0817DBA8 @ case 314
	.4byte _0817DF52 @ case 315
	.4byte _0817DF52 @ case 316
	.4byte _0817DF52 @ case 317
	.4byte _0817DF52 @ case 318
	.4byte _0817DF52 @ case 319
	.4byte _0817DF52 @ case 320
	.4byte _0817DF52 @ case 321
	.4byte _0817DF52 @ case 322
	.4byte _0817DF52 @ case 323
	.4byte _0817DF52 @ case 324
	.4byte _0817DF52 @ case 325
	.4byte _0817D50A @ case 326
	.4byte _0817DF52 @ case 327
	.4byte _0817DF52 @ case 328
	.4byte _0817DF52 @ case 329
	.4byte _0817DF52 @ case 330
	.4byte _0817DF52 @ case 331
	.4byte _0817DF52 @ case 332
	.4byte _0817CFD0 @ case 333
	.4byte _0817DF52 @ case 334
	.4byte _0817DF52 @ case 335
	.4byte _0817DF52 @ case 336
	.4byte _0817DF52 @ case 337
	.4byte _0817DF52 @ case 338
	.4byte _0817DF52 @ case 339
	.4byte _0817DF52 @ case 340
	.4byte _0817DF52 @ case 341
	.4byte _0817DF52 @ case 342
	.4byte _0817DF52 @ case 343
	.4byte _0817DF52 @ case 344
	.4byte _0817DF52 @ case 345
	.4byte _0817DF52 @ case 346
	.4byte _0817DF52 @ case 347
	.4byte _0817DF52 @ case 348
	.4byte _0817DD04 @ case 349
	.4byte _0817DC74 @ case 350
	.4byte _0817DCBC @ case 351
	.4byte _0817DE92 @ case 352
_0817CF1C:
	movs r0, #1
	mov r1, sl
	movs r2, #2
	movs r3, #0
	bl AddMovePoints
	ldr r0, _0817CF40
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0817CF38
	bl _0817DF52
_0817CF38:
	bl TrySetBattleSeminarShow
	bl _0817DF52
	.align 2, 0
_0817CF40: .4byte 0x02022C90
_0817CF44:
	movs r0, #1
	mov r1, sl
	movs r2, #1
	movs r3, #0
	bl AddMovePoints
	ldr r0, _0817CF7C
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0817CF60
	bl _0817DF52
_0817CF60:
	ldr r0, [sp, #0xc]
	movs r1, #0x39
	movs r2, #0
	bl GetMonData3
	cmp r0, #0
	bne _0817CF72
	bl _0817DF52
_0817CF72:
	bl TrySetBattleSeminarShow
	bl _0817DF52
	.align 2, 0
_0817CF7C: .4byte 0x02022C90
_0817CF80:
	movs r0, #1
	mov r1, sl
	movs r2, #0
	b _0817D33A
_0817CF88:
	lsls r3, r4, #1
	adds r3, r3, r4
	lsls r3, r3, #2
	adds r3, r7, r3
	ldr r1, _0817CFC4
	ldr r0, _0817CFC8
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #0xf
	ldr r1, [r3, #0x50]
	ldr r2, _0817CFCC
	ands r1, r2
	orrs r1, r0
	str r1, [r3, #0x50]
	adds r3, #0x55
	movs r0, #3
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3]
	movs r0, #0xd
	rsbs r0, r0, #0
	bl _0817DAB8
	.align 2, 0
_0817CFC4: .4byte 0x02023D12
_0817CFC8: .4byte 0x02023EAF
_0817CFCC: .4byte 0xFFFC7FFF
_0817CFD0:
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #2
	adds r2, r7, r2
	ldr r1, _0817D010
	ldr r0, _0817D014
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r4, r2, #0
	adds r4, #0x52
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #2
	ldrb r3, [r4]
	movs r0, #0x1d
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r2, #0x55
	movs r0, #3
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #4
	ldrb r3, [r2]
	movs r0, #0x31
	rsbs r0, r0, #0
	bl _0817DE56
	.align 2, 0
_0817D010: .4byte 0x02023D12
_0817D014: .4byte 0x02023EAF
_0817D018:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r5, r7, r0
	ldr r1, _0817D05C
	ldr r0, _0817D060
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r3, r5, #0
	adds r3, #0x52
	lsls r1, r1, #5
	ldrb r2, [r3]
	movs r0, #0x1f
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	adds r4, r5, #0
	adds r4, #0x55
	mov r0, sl
	lsls r2, r0, #6
	ldrb r1, [r4]
	movs r0, #0x3f
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	adds r2, r5, #0
	adds r2, #0x58
	ldrb r0, [r2]
	movs r1, #0x40
	bl _0817DE58
	.align 2, 0
_0817D05C: .4byte 0x02023D12
_0817D060: .4byte 0x02023EAF
_0817D064:
	ldr r1, _0817D088
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817D070
	bl _0817DF52
_0817D070:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r7, r0
	adds r0, #0x57
	ldrb r2, [r0]
	movs r1, #0x1f
	rsbs r1, r1, #0
	ands r1, r2
	movs r2, #0x14
	bl _0817DF4E
	.align 2, 0
_0817D088: .4byte 0x02022C10
_0817D08C:
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r3, r7, r0
	adds r0, r3, #0
	adds r0, #0x53
	ldrb r0, [r0]
	lsls r0, r0, #0x1d
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817D0A6
	bl _0817DF52
_0817D0A6:
	adds r2, r6, #0
	subs r1, r0, #1
	lsls r1, r1, #2
	adds r0, r3, #0
	adds r0, #0x56
	ldrb r3, [r0]
	lsls r3, r3, #0x1e
	lsrs r3, r3, #0x1e
	adds r3, r3, r1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r0, #2
	bl sub_0817D9BC
_0817D0C2:
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #2
	adds r2, r7, r2
	ldr r1, _0817D104
	ldr r0, _0817D108
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r4, r2, #0
	adds r4, #0x53
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #3
	ldrb r3, [r4]
	movs r0, #0x39
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r2, #0x56
	movs r0, #3
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #2
	ldrb r3, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	bl _0817DE56
	.align 2, 0
_0817D104: .4byte 0x02023D12
_0817D108: .4byte 0x02023EAF
_0817D10C:
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r3, r7, r0
	adds r0, r3, #0
	adds r0, #0x53
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817D126
	bl _0817DF52
_0817D126:
	adds r2, r6, #0
	subs r1, r0, #1
	lsls r1, r1, #2
	adds r0, r3, #0
	adds r0, #0x56
	ldrb r3, [r0]
	lsls r3, r3, #0x1c
	lsrs r3, r3, #0x1e
	adds r3, r3, r1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r0, #2
	bl sub_0817DA6E
_0817D142:
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #2
	adds r2, r7, r2
	ldr r1, _0817D184
	ldr r0, _0817D188
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r2, #0x56
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #4
	ldrb r3, [r2]
	movs r0, #0x71
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	movs r0, #3
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #7
	ldrh r3, [r2]
	ldr r0, _0817D18C
	ands r0, r3
	orrs r0, r1
	strh r0, [r2]
	bl _0817DF52
	.align 2, 0
_0817D184: .4byte 0x02023D12
_0817D188: .4byte 0x02023EAF
_0817D18C: .4byte 0xFFFFFE7F
_0817D190:
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r7, r0
	adds r0, #0x56
	ldrb r0, [r0]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817D1A8
	bl _0817DF52
_0817D1A8:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r7, r0
	adds r0, #0x57
	ldrb r2, [r0]
	movs r1, #0x1f
	rsbs r1, r1, #0
	ands r1, r2
	movs r2, #0x16
	bl _0817DF4E
_0817D1C0:
	mov r2, r8
	lsls r3, r2, #3
	lsls r0, r4, #4
	adds r3, r3, r0
	adds r3, r7, r3
	ldr r1, _0817D1F8
	ldr r0, _0817D1FC
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r3, #0x35
	movs r0, #7
	ands r1, r0
	ldrb r2, [r3]
	movs r0, #8
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	movs r2, #3
	mov r1, sl
	ands r1, r2
	lsls r1, r1, #3
	movs r2, #0x19
	rsbs r2, r2, #0
	bl _0817DAB8
	.align 2, 0
_0817D1F8: .4byte 0x02023D12
_0817D1FC: .4byte 0x02023EAF
_0817D200:
	mov r1, r8
	lsls r0, r1, #3
	lsls r1, r4, #4
	adds r0, r0, r1
	adds r0, r7, r0
	adds r0, #0x35
	ldrb r1, [r0]
	lsls r0, r1, #0x1d
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817D21A
	bl _0817DF52
_0817D21A:
	adds r2, r4, #0
	b _0817D238
_0817D21E:
	lsls r0, r5, #3
	lsls r1, r6, #4
	adds r0, r0, r1
	adds r0, r7, r0
	adds r0, #0x35
	ldrb r1, [r0]
	lsls r0, r1, #0x1d
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817D236
	bl _0817DF52
_0817D236:
	adds r2, r6, #0
_0817D238:
	subs r0, #1
	lsls r0, r0, #2
	lsls r3, r1, #0x1b
	lsrs r3, r3, #0x1e
	adds r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r0, #2
	movs r1, #6
	bl AddMovePoints
	bl _0817DF52
_0817D252:
	ldr r0, _0817D260
	ldr r0, [r0]
	adds r0, #0xb3
	movs r1, #1
	bl _0817DF50
	.align 2, 0
_0817D260: .4byte 0x02024140
_0817D264:
	movs r0, #0x12
	mov r1, sl
	movs r2, #0
	b _0817D33A
_0817D26C:
	ldr r0, _0817D28C
	ldrb r2, [r0, #2]
	cmp r2, #0
	bne _0817D278
	bl _0817DF52
_0817D278:
	ldr r1, _0817D290
	ldrh r0, [r1]
	cmp r0, #0xd1
	bne _0817D294
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0x17
	b _0817D338
	.align 2, 0
_0817D28C: .4byte 0x02022C0C
_0817D290: .4byte 0x02022C1E
_0817D294:
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0x16
	b _0817D338
_0817D29E:
	ldr r0, _0817D2C8
	ldrb r2, [r0, #2]
	cmp r2, #0
	bne _0817D2AA
	bl _0817DF52
_0817D2AA:
	ldr r0, _0817D2CC
	ldr r1, _0817D2D0
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0817D2E2
	ldr r1, _0817D2D4
	ldrh r0, [r1]
	cmp r0, #0xd1
	bne _0817D2D8
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0x17
	b _0817D338
	.align 2, 0
_0817D2C8: .4byte 0x02022C0C
_0817D2CC: .4byte 0x02023EAF
_0817D2D0: .4byte 0x02023EB0
_0817D2D4: .4byte 0x02022C1E
_0817D2D8:
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0x16
	b _0817D338
_0817D2E2:
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0x1b
	b _0817D338
_0817D2EC:
	ldr r0, _0817D304
	ldrb r2, [r0, #2]
	cmp r2, #0
	bne _0817D2F8
	bl _0817DF52
_0817D2F8:
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0x18
	b _0817D338
	.align 2, 0
_0817D304: .4byte 0x02022C0C
_0817D308:
	ldr r0, _0817D328
	ldrb r2, [r0, #2]
	cmp r2, #0
	bne _0817D314
	bl _0817DF52
_0817D314:
	ldr r1, _0817D32C
	ldrh r0, [r1]
	cmp r0, #0xd3
	bne _0817D330
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0x1a
	b _0817D338
	.align 2, 0
_0817D328: .4byte 0x02022C0C
_0817D32C: .4byte 0x02022C1E
_0817D330:
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0x19
_0817D338:
	mov r1, sl
_0817D33A:
	movs r3, #0
	bl AddMovePoints
	bl _0817DF52
_0817D344:
	lsls r2, r5, #3
	lsls r0, r6, #4
	adds r2, r2, r0
	adds r2, r7, r2
	ldr r1, _0817D384
	ldr r0, _0817D388
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r4, r2, #0
	adds r4, #0x30
	movs r0, #7
	ands r1, r0
	ldrb r3, [r4]
	movs r0, #8
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r2, #0x32
	movs r0, #3
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #2
	ldrb r3, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	bl _0817DE56
	.align 2, 0
_0817D384: .4byte 0x02023D12
_0817D388: .4byte 0x02023EAF
_0817D38C:
	ldr r0, [sp, #8]
	movs r1, #0x39
	movs r2, #0
	bl GetMonData3
	cmp r0, #0
	bne _0817D39E
	bl _0817DF52
_0817D39E:
	mov r2, r8
	lsls r0, r2, #3
	lsls r1, r4, #4
	adds r0, r0, r1
	adds r1, r7, r0
	adds r0, r1, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #0x1d
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817D3BA
	bl _0817DF52
_0817D3BA:
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r3, [r0]
	lsls r3, r3, #0x1c
	lsrs r3, r3, #0x1e
	movs r0, #8
	movs r1, #0
	bl AddMovePoints
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r7, r1
	adds r1, #0x57
	ldrb r2, [r1]
	movs r0, #0x1f
	rsbs r0, r0, #0
	ands r0, r2
	movs r2, #2
	b _0817D59E
_0817D3E8:
	lsls r2, r5, #3
	lsls r0, r6, #4
	adds r2, r2, r0
	adds r2, r7, r2
	ldr r1, _0817D428
	ldr r0, _0817D42C
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r4, r2, #0
	adds r4, #0x30
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #3
	ldrb r3, [r4]
	movs r0, #0x39
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r2, #0x32
	movs r0, #3
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #4
	ldrb r3, [r2]
	movs r0, #0x31
	rsbs r0, r0, #0
	bl _0817DE56
	.align 2, 0
_0817D428: .4byte 0x02023D12
_0817D42C: .4byte 0x02023EAF
_0817D430:
	mov r1, r8
	lsls r0, r1, #3
	lsls r1, r4, #4
	adds r0, r0, r1
	adds r1, r7, r0
	adds r0, r1, #0
	adds r0, #0x30
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817D44C
	bl _0817DF52
_0817D44C:
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r3, [r0]
	lsls r3, r3, #0x1a
	lsrs r3, r3, #0x1e
	movs r0, #8
	movs r1, #1
	bl AddMovePoints
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r7, r1
	adds r1, #0x57
	ldrb r2, [r1]
	movs r0, #0x1f
	rsbs r0, r0, #0
	ands r0, r2
	movs r2, #4
	b _0817D59E
_0817D47A:
	lsls r2, r5, #3
	lsls r0, r6, #4
	adds r2, r2, r0
	adds r2, r7, r2
	ldr r1, _0817D4A8
	ldr r0, _0817D4AC
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #6
	ldrh r3, [r2, #0x30]
	ldr r0, _0817D4B0
	ands r0, r3
	orrs r0, r1
	strh r0, [r2, #0x30]
	adds r2, #0x32
	bl _0817DDB6
	.align 2, 0
_0817D4A8: .4byte 0x02023D12
_0817D4AC: .4byte 0x02023EAF
_0817D4B0: .4byte 0xFFFFFE3F
_0817D4B4:
	ldr r0, [sp, #8]
	movs r1, #0x39
	movs r2, #0
	bl GetMonData3
	cmp r0, #0
	bne _0817D4C6
	bl _0817DF52
_0817D4C6:
	mov r1, r8
	lsls r0, r1, #3
	lsls r1, r4, #4
	adds r0, r0, r1
	adds r1, r7, r0
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x17
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817D4DE
	bl _0817DF52
_0817D4DE:
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r1, #0
	adds r0, #0x32
	ldrb r3, [r0]
	lsrs r3, r3, #6
	movs r0, #8
	movs r1, #5
	bl AddMovePoints
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r7, r1
	adds r1, #0x57
	ldrb r2, [r1]
	movs r0, #0x1f
	rsbs r0, r0, #0
	ands r0, r2
	movs r2, #0xa
	b _0817D59E
_0817D50A:
	lsls r2, r5, #3
	lsls r0, r6, #4
	adds r2, r2, r0
	adds r2, r7, r2
	ldr r1, _0817D53C
	ldr r0, _0817D540
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r4, r2, #0
	adds r4, #0x31
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #1
	ldrb r3, [r4]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r2, #0x33
	bl _0817DE4A
	.align 2, 0
_0817D53C: .4byte 0x02023D12
_0817D540: .4byte 0x02023EAF
_0817D544:
	ldr r0, [sp, #8]
	movs r1, #0x39
	movs r2, #0
	bl GetMonData3
	cmp r0, #0
	bne _0817D556
	bl _0817DF52
_0817D556:
	mov r1, r8
	lsls r0, r1, #3
	lsls r1, r4, #4
	adds r0, r0, r1
	adds r1, r7, r0
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817D572
	bl _0817DF52
_0817D572:
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r1, #0
	adds r0, #0x33
	ldrb r3, [r0]
	lsls r3, r3, #0x1e
	lsrs r3, r3, #0x1e
	movs r0, #8
	movs r1, #6
	bl AddMovePoints
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r7, r1
	adds r1, #0x57
	ldrb r2, [r1]
	movs r0, #0x1f
	rsbs r0, r0, #0
	ands r0, r2
	movs r2, #0xc
_0817D59E:
	orrs r0, r2
	mov r2, r8
	lsls r3, r2, #5
	movs r2, #0x1f
	ands r0, r2
	orrs r0, r3
	strb r0, [r1]
	bl _0817DF52
_0817D5B0:
	ldr r5, _0817D608
	ldr r6, _0817D60C
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	lsls r2, r2, #2
	mov r0, sb
	lsls r4, r0, #1
	add r4, sb
	lsls r4, r4, #3
	adds r2, r2, r4
	adds r2, r7, r2
	ldr r0, _0817D610
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	adds r1, #1
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #6
	ldrh r3, [r2]
	ldr r0, _0817D614
	ands r0, r3
	orrs r0, r1
	strh r0, [r2]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, r7, r1
	mov r2, sl
	lsls r3, r2, #6
	ldrb r2, [r1, #2]
	movs r0, #0x3f
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, #2]
	bl _0817DF52
	.align 2, 0
_0817D608: .4byte 0x02023D12
_0817D60C: .4byte 0x02023EB2
_0817D610: .4byte 0x02023EAF
_0817D614: .4byte 0xFFFFFE3F
_0817D618:
	ldr r0, [sp, #8]
	movs r1, #0x39
	movs r2, #0
	bl GetMonData3
	cmp r0, #0
	bne _0817D62A
	bl _0817DF52
_0817D62A:
	ldr r6, _0817D67C
	ldr r5, _0817D680
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	lsls r0, r0, #2
	lsls r1, r4, #1
	adds r4, r1, r4
	lsls r1, r4, #3
	adds r0, r0, r1
	adds r1, r7, r0
	ldrh r0, [r1]
	lsls r0, r0, #0x17
	lsrs r0, r0, #0x1d
	cmp r0, #0
	beq _0817D65E
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r1, #2]
	lsrs r3, r3, #6
	movs r0, #8
	movs r1, #4
	bl AddMovePoints
_0817D65E:
	lsls r3, r4, #2
	adds r3, r7, r3
	adds r3, #0x57
	ldrb r0, [r3]
	movs r1, #0x1f
	rsbs r1, r1, #0
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	strb r1, [r3]
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r6
	b _0817D7E0
	.align 2, 0
_0817D67C: .4byte 0x02023D12
_0817D680: .4byte 0x02023EAF
_0817D684:
	ldr r5, _0817D6D8
	ldr r6, _0817D6DC
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	lsls r2, r2, #2
	mov r0, sb
	lsls r4, r0, #1
	add r4, sb
	lsls r4, r4, #3
	adds r2, r2, r4
	adds r2, r7, r2
	ldr r0, _0817D6E0
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	adds r1, #1
	movs r0, #7
	ands r1, r0
	ldrb r3, [r2]
	movs r0, #8
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, r7, r1
	movs r0, #3
	mov r2, sl
	ands r2, r0
	lsls r2, r2, #2
	ldrb r3, [r1, #2]
	movs r0, #0xd
	rsbs r0, r0, #0
	b _0817D738
	.align 2, 0
_0817D6D8: .4byte 0x02023D12
_0817D6DC: .4byte 0x02023EB2
_0817D6E0: .4byte 0x02023EAF
_0817D6E4:
	ldr r5, _0817D744
	ldr r6, _0817D748
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	lsls r2, r2, #2
	mov r1, sb
	lsls r4, r1, #1
	add r4, sb
	lsls r4, r4, #3
	adds r2, r2, r4
	adds r2, r7, r2
	ldr r0, _0817D74C
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	adds r1, #1
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #3
	ldrb r3, [r2]
	movs r0, #0x39
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, r7, r1
	movs r0, #3
	mov r2, sl
	ands r2, r0
	lsls r2, r2, #4
	ldrb r3, [r1, #2]
	movs r0, #0x31
	rsbs r0, r0, #0
_0817D738:
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, #2]
	bl _0817DF52
	.align 2, 0
_0817D744: .4byte 0x02023D12
_0817D748: .4byte 0x02023EB2
_0817D74C: .4byte 0x02023EAF
_0817D750:
	ldr r0, [sp, #8]
	movs r1, #0x39
	movs r2, #0
	bl GetMonData3
	cmp r0, #0
	bne _0817D762
	bl _0817DF52
_0817D762:
	ldr r2, _0817D7F0
	mov r8, r2
	ldr r6, _0817D7F4
	ldrb r0, [r6]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	lsls r0, r0, #2
	lsls r1, r4, #1
	adds r5, r1, r4
	lsls r4, r5, #3
	adds r0, r0, r4
	adds r1, r7, r0
	ldrb r0, [r1]
	lsls r0, r0, #0x1d
	lsrs r0, r0, #0x1d
	cmp r0, #0
	beq _0817D79A
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r1, #2]
	lsls r3, r3, #0x1c
	lsrs r3, r3, #0x1e
	movs r0, #8
	movs r1, #2
	bl AddMovePoints
_0817D79A:
	ldrb r0, [r6]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r1, r7, r0
	ldrb r0, [r1]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1d
	cmp r0, #0
	beq _0817D7C6
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r1, #2]
	lsls r3, r3, #0x1a
	lsrs r3, r3, #0x1e
	movs r0, #8
	movs r1, #3
	bl AddMovePoints
_0817D7C6:
	lsls r3, r5, #2
	adds r3, r7, r3
	adds r3, #0x57
	ldrb r0, [r3]
	movs r1, #0x1f
	rsbs r1, r1, #0
	ands r1, r0
	movs r0, #6
	orrs r1, r0
	strb r1, [r3]
	ldrb r0, [r6]
	lsls r0, r0, #1
	add r0, r8
_0817D7E0:
	ldrh r0, [r0]
	lsls r0, r0, #5
	movs r2, #0x1f
	ands r1, r2
	orrs r1, r0
	strb r1, [r3]
	b _0817DF52
	.align 2, 0
_0817D7F0: .4byte 0x02023D12
_0817D7F4: .4byte 0x02023EAF
_0817D7F8:
	lsls r2, r5, #3
	lsls r0, r6, #4
	adds r2, r2, r0
	adds r2, r7, r2
	ldr r1, _0817D838
	ldr r0, _0817D83C
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r4, r2, #0
	adds r4, #0x31
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #4
	ldrb r3, [r4]
	movs r0, #0x71
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r2, #0x33
	movs r0, #3
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #2
	ldrb r3, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	b _0817DE56
	.align 2, 0
_0817D838: .4byte 0x02023D12
_0817D83C: .4byte 0x02023EAF
_0817D840:
	mov r1, r8
	lsls r0, r1, #3
	lsls r1, r4, #4
	adds r0, r0, r1
	adds r1, r7, r0
	adds r0, r1, #0
	adds r0, #0x31
	ldrb r0, [r0]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817D85A
	b _0817DF52
_0817D85A:
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r1, #0
	adds r0, #0x33
	ldrb r3, [r0]
	lsls r3, r3, #0x1c
	lsrs r3, r3, #0x1e
	movs r0, #9
	b _0817DF32
_0817D86E:
	ldr r5, _0817D8C4
	ldr r6, _0817D8C8
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	lsls r2, r2, #2
	mov r0, sb
	lsls r4, r0, #1
	add r4, sb
	lsls r4, r4, #3
	adds r2, r2, r4
	adds r2, r7, r2
	ldr r0, _0817D8CC
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	adds r1, #1
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #1
	ldrb r3, [r2, #1]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #1]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, r7, r1
	movs r0, #3
	mov r2, sl
	ands r2, r0
	ldrb r3, [r1, #3]
	movs r0, #4
	rsbs r0, r0, #0
	b _0817DA22
	.align 2, 0
_0817D8C4: .4byte 0x02023D12
_0817D8C8: .4byte 0x02023EB2
_0817D8CC: .4byte 0x02023EAF
_0817D8D0:
	ldr r1, _0817D90C
	ldr r0, _0817D910
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r1, r1, #2
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r7, r1
	ldrb r0, [r1, #1]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817D8F4
	b _0817DF52
_0817D8F4:
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r1, #3]
	lsls r3, r3, #0x1e
	lsrs r3, r3, #0x1e
	movs r0, #9
	movs r1, #2
	bl AddMovePoints
	b _0817DF52
	.align 2, 0
_0817D90C: .4byte 0x02023D12
_0817D910: .4byte 0x02023EAF
_0817D914:
	ldr r5, _0817D96C
	ldr r6, _0817D970
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	lsls r2, r2, #2
	mov r1, sb
	lsls r4, r1, #1
	add r4, sb
	lsls r4, r4, #3
	adds r2, r2, r4
	adds r2, r7, r2
	ldr r0, _0817D974
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	adds r1, #1
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #4
	ldrb r3, [r2, #1]
	movs r0, #0x71
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #1]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, r7, r1
	movs r0, #3
	mov r2, sl
	ands r2, r0
	lsls r2, r2, #2
	ldrb r3, [r1, #3]
	movs r0, #0xd
	rsbs r0, r0, #0
	b _0817DA22
	.align 2, 0
_0817D96C: .4byte 0x02023D12
_0817D970: .4byte 0x02023EB2
_0817D974: .4byte 0x02023EAF
_0817D978:
	ldr r1, _0817D9C4
	ldr r0, _0817D9C8
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r1, r1, #2
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r7, r1
	ldrb r0, [r1, #1]
	lsls r0, r0, #0x19
	lsrs r2, r0, #0x1d
	cmp r2, #0
	bne _0817D99C
	b _0817DF52
_0817D99C:
	ldr r0, _0817D9CC
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0xad
	bne _0817D9A8
	b _0817DF52
_0817D9A8:
	cmp r0, #0xd6
	bne _0817D9AE
	b _0817DF52
_0817D9AE:
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r1, #3]
	lsls r3, r3, #0x1c
	lsrs r3, r3, #0x1e
	movs r0, #9
	thumb_func_end BattleTv_SetDataBasedOnString

	thumb_func_start sub_0817D9BC
sub_0817D9BC: @ 0x0817D9BC
	movs r1, #3
	bl AddMovePoints
	b _0817DF52
	.align 2, 0
_0817D9C4: .4byte 0x02023D12
_0817D9C8: .4byte 0x02023EAF
_0817D9CC: .4byte 0x0203A874
_0817D9D0:
	ldr r5, _0817DA2C
	ldr r6, _0817DA30
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r3, [r0]
	lsls r3, r3, #2
	mov r2, sb
	lsls r4, r2, #1
	add r4, sb
	lsls r4, r4, #3
	adds r3, r3, r4
	adds r3, r7, r3
	ldr r0, _0817DA34
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #0xf
	ldr r1, [r3]
	ldr r2, _0817DA38
	ands r1, r2
	orrs r1, r0
	str r1, [r3]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, r7, r1
	movs r0, #3
	mov r2, sl
	ands r2, r0
	lsls r2, r2, #4
	ldrb r3, [r1, #3]
	movs r0, #0x31
	rsbs r0, r0, #0
_0817DA22:
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, #3]
	b _0817DF52
	.align 2, 0
_0817DA2C: .4byte 0x02023D12
_0817DA30: .4byte 0x02023EB2
_0817DA34: .4byte 0x02023EAF
_0817DA38: .4byte 0xFFFC7FFF
_0817DA3C:
	ldr r1, _0817DA78
	ldr r0, _0817DA7C
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r1, r1, #2
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r7, r1
	ldr r0, [r1]
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817DA60
	b _0817DF52
_0817DA60:
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r1, #3]
	lsls r3, r3, #0x1a
	lsrs r3, r3, #0x1e
	movs r0, #9
sub_0817DA6E: @ 0x0817DA6E
	movs r1, #4
	bl AddMovePoints
	b _0817DF52
	.align 2, 0
_0817DA78: .4byte 0x02023D12
_0817DA7C: .4byte 0x02023EAF
_0817DA80:
	lsls r3, r3, #3
	mov r1, sb
	lsls r0, r1, #4
	adds r3, r3, r0
	adds r3, r7, r3
	ldr r1, _0817DAC0
	ldr r0, _0817DAC4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #0xf
	ldr r1, [r3, #0x30]
	ldr r2, _0817DAC8
	ands r1, r2
	orrs r1, r0
	str r1, [r3, #0x30]
	adds r3, #0x33
	movs r0, #3
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #4
	ldrb r2, [r3]
	movs r0, #0x31
	rsbs r0, r0, #0
_0817DAB8:
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	b _0817DF52
	.align 2, 0
_0817DAC0: .4byte 0x02023D12
_0817DAC4: .4byte 0x02023EAF
_0817DAC8: .4byte 0xFFFC7FFF
_0817DACC:
	mov r2, r8
	lsls r0, r2, #3
	lsls r1, r4, #4
	adds r0, r0, r1
	adds r3, r7, r0
	ldr r0, [r3, #0x30]
	lsls r0, r0, #0xe
	lsrs r0, r0, #0x1d
	cmp r0, #0
	beq _0817DAF8
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r3, #0
	adds r0, #0x33
	ldrb r3, [r0]
	lsls r3, r3, #0x1a
	lsrs r3, r3, #0x1e
	movs r0, #9
	movs r1, #1
	bl AddMovePoints
_0817DAF8:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r7, r0
	adds r0, #0x57
	ldrb r2, [r0]
	movs r1, #0x1f
	rsbs r1, r1, #0
	ands r1, r2
	movs r2, #0x18
	b _0817DF4E
_0817DB0E:
	lsls r2, r6, #1
	adds r2, r2, r6
	lsls r2, r2, #2
	adds r2, r7, r2
	ldr r1, _0817DB3C
	ldr r0, _0817DB40
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r4, r2, #0
	adds r4, #0x50
	movs r0, #7
	ands r1, r0
	ldrb r3, [r4]
	movs r0, #8
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r2, #0x54
	b _0817DE4A
	.align 2, 0
_0817DB3C: .4byte 0x02023D12
_0817DB40: .4byte 0x02023EAF
_0817DB44:
	ldr r1, [sp, #4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r4, r7, r0
	adds r0, r4, #0
	adds r0, #0x50
	ldrb r0, [r0]
	lsls r0, r0, #0x1d
	lsrs r2, r0, #0x1d
	cmp r2, #0
	bne _0817DB5E
	b _0817DF52
_0817DB5E:
	movs r0, #1
	eors r1, r0
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	adds r0, #0x54
	ldrb r3, [r0]
	lsls r3, r3, #0x1e
	lsrs r3, r3, #0x1e
	movs r0, #0xa
	bl AddMovePoints
	adds r2, r4, #0
	adds r2, #0x57
	ldrb r1, [r2]
	movs r0, #0x1f
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0xe
	b _0817DE58
_0817DB88:
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r7, r1
	adds r3, r1, #0
	adds r3, #0x50
	ldrb r2, [r3]
	movs r0, #8
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r3]
	adds r1, #0x54
	ldrb r2, [r1]
	movs r0, #4
	rsbs r0, r0, #0
	b _0817DE16
_0817DBA8:
	mov r0, r8
	lsls r2, r0, #3
	lsls r0, r4, #4
	adds r2, r2, r0
	adds r2, r7, r2
	ldr r1, _0817DBDC
	ldr r0, _0817DBE0
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r4, r2, #0
	adds r4, #0x34
	movs r0, #7
	ands r1, r0
	ldrb r3, [r4]
	movs r0, #8
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r2, #0x33
	mov r1, sl
	lsls r3, r1, #6
	b _0817DDBA
	.align 2, 0
_0817DBDC: .4byte 0x02023D12
_0817DBE0: .4byte 0x02023EAF
_0817DBE4:
	mov r0, r8
	lsls r2, r0, #3
	lsls r0, r4, #4
	adds r2, r2, r0
	adds r2, r7, r2
	ldr r1, _0817DC18
	ldr r0, _0817DC1C
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r2, #0x34
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #3
	ldrb r3, [r2]
	movs r0, #0x39
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	mov r1, sl
	lsls r3, r1, #6
	movs r1, #0x3f
	b _0817DDBE
	.align 2, 0
_0817DC18: .4byte 0x02023D12
_0817DC1C: .4byte 0x02023EAF
_0817DC20:
	movs r0, #0
	bl AddPointsOnFainting
_0817DC26:
	mov r2, r8
	lsls r0, r2, #3
	b _0817DC34
_0817DC2C:
	movs r0, #1
	bl AddPointsOnFainting
	lsls r0, r5, #3
_0817DC34:
	lsls r1, r4, #4
	adds r0, r0, r1
	adds r1, r7, r0
	adds r4, r1, #0
	adds r4, #0x34
	ldrb r5, [r4]
	lsls r0, r5, #0x1d
	cmp r0, #0
	beq _0817DC5A
	movs r0, #8
	rsbs r0, r0, #0
	ands r0, r5
	strb r0, [r4]
	adds r2, r1, #0
	adds r2, #0x33
	ldrb r1, [r2]
	movs r0, #0x3f
	ands r0, r1
	strb r0, [r2]
_0817DC5A:
	ldrb r1, [r4]
	lsls r0, r1, #0x1a
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817DC66
	b _0817DF52
_0817DC66:
	movs r0, #0x39
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x3f
	ands r0, r1
	strb r0, [r4]
	b _0817DF52
_0817DC74:
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #2
	adds r2, r7, r2
	ldr r1, _0817DCB4
	ldr r0, _0817DCB8
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r4, r2, #0
	adds r4, #0x50
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #3
	ldrb r3, [r4]
	movs r0, #0x39
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r2, #0x54
	movs r0, #3
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #2
	ldrb r3, [r2]
	movs r0, #0xd
	rsbs r0, r0, #0
	b _0817DE56
	.align 2, 0
_0817DCB4: .4byte 0x02023D12
_0817DCB8: .4byte 0x02023EAF
_0817DCBC:
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #2
	adds r2, r7, r2
	ldr r1, _0817DCF8
	ldr r0, _0817DCFC
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r4, r2, #0
	adds r4, #0x50
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #6
	ldrh r3, [r4]
	ldr r0, _0817DD00
	ands r0, r3
	orrs r0, r1
	strh r0, [r4]
	adds r2, #0x54
	movs r0, #3
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #4
	ldrb r3, [r2]
	movs r0, #0x31
	rsbs r0, r0, #0
	b _0817DE56
	.align 2, 0
_0817DCF8: .4byte 0x02023D12
_0817DCFC: .4byte 0x02023EAF
_0817DD00: .4byte 0xFFFFFE3F
_0817DD04:
	ldr r1, _0817DD80
	ldrh r0, [r1]
	cmp r0, #0x73
	bne _0817DD2E
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r7, r1
	adds r3, r1, #0
	adds r3, #0x50
	ldrb r2, [r3]
	movs r0, #0x39
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r3]
	adds r1, #0x54
	ldrb r2, [r1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
_0817DD2E:
	ldr r2, _0817DD80
	ldrh r0, [r2]
	cmp r0, #0x71
	bne _0817DD56
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r7, r1
	adds r3, r1, #0
	adds r3, #0x50
	ldrh r2, [r3]
	ldr r0, _0817DD84
	ands r0, r2
	strh r0, [r3]
	adds r1, #0x54
	ldrb r2, [r1]
	movs r0, #0x31
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
_0817DD56:
	ldr r1, _0817DD80
	ldrh r0, [r1]
	cmp r0, #0x36
	beq _0817DD60
	b _0817DF52
_0817DD60:
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r7, r1
	adds r4, r1, #0
	adds r4, #0x51
	ldrb r2, [r4]
	movs r0, #0x71
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r4]
	adds r1, #0x55
	ldrb r2, [r1]
	movs r0, #4
	rsbs r0, r0, #0
	b _0817DE16
	.align 2, 0
_0817DD80: .4byte 0x02022C0E
_0817DD84: .4byte 0xFFFFFE3F
_0817DD88:
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #2
	adds r2, r7, r2
	ldr r1, _0817DDC8
	ldr r0, _0817DDCC
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r4, r2, #0
	adds r4, #0x51
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #1
	ldrb r3, [r4]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r2, #0x54
_0817DDB6:
	mov r0, sl
	lsls r3, r0, #6
_0817DDBA:
	ldrb r1, [r2]
	movs r0, #0x3f
_0817DDBE:
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
	b _0817DF52
	.align 2, 0
_0817DDC8: .4byte 0x02023D12
_0817DDCC: .4byte 0x02023EAF
_0817DDD0:
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r0, r1, #0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817DDE8
	b _0817DF52
_0817DDE8:
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r1, #0
	adds r0, #0x54
	ldrb r3, [r0]
	lsrs r3, r3, #6
	movs r0, #0xf
	b _0817DF32
_0817DDFA:
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r7, r1
	adds r4, r1, #0
	adds r4, #0x51
	ldrb r2, [r4]
	movs r0, #0xf
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r4]
	adds r1, #0x54
	ldrb r2, [r1]
	movs r0, #0x3f
_0817DE16:
	ands r0, r2
	strb r0, [r1]
	b _0817DF52
_0817DE1C:
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #2
	adds r2, r7, r2
	ldr r1, _0817DE60
	ldr r0, _0817DE64
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, #1
	adds r4, r2, #0
	adds r4, #0x51
	movs r0, #7
	ands r1, r0
	lsls r1, r1, #4
	ldrb r3, [r4]
	movs r0, #0x71
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	adds r2, #0x55
_0817DE4A:
	movs r0, #3
	mov r1, sl
	ands r1, r0
	ldrb r3, [r2]
	movs r0, #4
	rsbs r0, r0, #0
_0817DE56:
	ands r0, r3
_0817DE58:
	orrs r0, r1
	strb r0, [r2]
	b _0817DF52
	.align 2, 0
_0817DE60: .4byte 0x02023D12
_0817DE64: .4byte 0x02023EAF
_0817DE68:
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r0, r1, #0
	adds r0, #0x51
	ldrb r0, [r0]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x1d
	cmp r0, #0
	beq _0817DF52
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r1, #0
	adds r0, #0x55
	ldrb r3, [r0]
	lsls r3, r3, #0x1e
	lsrs r3, r3, #0x1e
	movs r0, #0x10
	b _0817DF32
_0817DE92:
	lsls r1, r6, #1
	adds r1, r1, r6
	lsls r1, r1, #2
	adds r1, r7, r1
	adds r3, r1, #0
	adds r3, #0x50
	ldrb r2, [r3]
	movs r0, #0x39
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r3]
	adds r1, #0x54
	ldrb r2, [r1]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldrh r2, [r3]
	ldr r0, _0817DEE0
	ands r0, r2
	strh r0, [r3]
	ldrb r2, [r1]
	movs r0, #0x31
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldr r1, _0817DEE4
	ldr r0, _0817DEE8
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r0, #0x11
	movs r1, #0
	mov r3, sl
	bl AddMovePoints
	b _0817DF52
	.align 2, 0
_0817DEE0: .4byte 0xFFFFFE3F
_0817DEE4: .4byte 0x02023D12
_0817DEE8: .4byte 0x02023EAF
_0817DEEC:
	lsls r0, r4, #4
	adds r4, r7, r0
	adds r0, r4, #0
	adds r0, #0x35
	ldrb r0, [r0]
	lsrs r0, r0, #5
	cmp r0, #0
	beq _0817DF14
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	adds r0, #0x36
	ldrb r3, [r0]
	lsls r3, r3, #0x1e
	lsrs r3, r3, #0x1e
	movs r0, #0x15
	movs r1, #0
	bl AddMovePoints
_0817DF14:
	adds r0, r4, #0
	adds r0, #0x3d
	ldrb r0, [r0]
	lsrs r0, r0, #5
	cmp r0, #0
	beq _0817DF52
	subs r2, r0, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r3, [r0]
	lsls r3, r3, #0x1e
	lsrs r3, r3, #0x1e
	movs r0, #0x15
_0817DF32:
	movs r1, #0
	bl AddMovePoints
	b _0817DF52
_0817DF3A:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r7, r0
	adds r0, #0x57
	ldrb r2, [r0]
	movs r1, #0x1f
	rsbs r1, r1, #0
	ands r1, r2
	movs r2, #0x1c
_0817DF4E:
	orrs r1, r2
_0817DF50:
	strb r1, [r0]
_0817DF52:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0817D9BC
