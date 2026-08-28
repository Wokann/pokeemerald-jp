#include "constants/battle.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/sound.h"
#include "constants/moves.h"
	.include "asm/macros.inc"
	.include "asm/macros/battle_anim_script.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

@ This JP-located owner mirrors pokeemerald battle_anim_scripts.s.
@ Unconverted ranges remain visible here as per-label baserom spans.
@ This JP-located table is consumed by the battle animation script engine.
	.align 2
gMovesWithQuietBGM::
	.2byte MOVE_SING, MOVE_PERISH_SONG, MOVE_GRASS_WHISTLE, 0xFFFF

@ These JP-located dispatch tables remain in battle_anim_scripts.o to preserve script_data ROM order.
gBattleAnims_Moves:: @ 0x82772F8
	.4byte Move_NONE                             @ MOVE_NONE
	.4byte Move_POUND                            @ MOVE_POUND
	.4byte gUnknown_828063A                  @ 002
	.4byte Move_DOUBLE_SLAP                    @ MOVE_DOUBLE_SLAP
	.4byte gUnknown_827884F                  @ 004
	.4byte gUnknown_82786D9                  @ 005
	.4byte gUnknown_8279E41                  @ 006
	.4byte gUnknown_8281204                  @ 007
	.4byte gUnknown_827DC85                  @ 008
	.4byte gUnknown_827E01B                  @ 009
	.4byte gUnknown_827E2CB                  @ 010
	.4byte gUnknown_8279D6D                  @ 011
	.4byte gUnknown_8279DB5                  @ 012
	.4byte gUnknown_8281F08                  @ 013
	.4byte gUnknown_8279030                  @ 014
	.4byte gUnknown_8278D16                  @ 015
	.4byte gUnknown_827FF98                  @ 016
	.4byte gUnknown_827FFE9                  @ 017
	.4byte gUnknown_827A375                  @ 018
	.4byte gUnknown_828056D                  @ 019
	.4byte gUnknown_828164F                  @ 020
	.4byte gUnknown_8279495                  @ 021
	.4byte gUnknown_827951D                  @ 022
	.4byte gUnknown_8278CB6                  @ 023
	.4byte gUnknown_82807E8                  @ 024
	.4byte gUnknown_82787B3                  @ 025
	.4byte gUnknown_82806F5                  @ 026
	.4byte gUnknown_827ABC6                  @ 027
	.4byte gUnknown_827E873                  @ 028
	.4byte gUnknown_827AC49                  @ 029
	.4byte gUnknown_827ACA6                  @ 030
	.4byte gUnknown_827AD13                  @ 031
	.4byte gUnknown_827AD90                  @ 032
	.4byte Move_TACKLE                         @ MOVE_TACKLE
	.4byte Move_BODY_SLAM                      @ MOVE_BODY_SLAM
	.4byte gUnknown_8281689                  @ 035
	.4byte gUnknown_8278276                  @ 036
	.4byte gUnknown_827AF0D                  @ 037
	.4byte gUnknown_8278306                  @ 038
	.4byte gUnknown_8278CFD                  @ 039
	.4byte gUnknown_8278419                  @ 040
	.4byte gUnknown_827846E                  @ 041
	.4byte gUnknown_82780EC                  @ 042
	.4byte gUnknown_8281317                  @ 043
	.4byte gUnknown_827EAE1                  @ 044
	.4byte gUnknown_827E4A8                  @ 045
	.4byte gUnknown_827E411                  @ 046
	.4byte gUnknown_827AF8C                  @ 047
	.4byte Move_SUPERSONIC                     @ MOVE_SUPERSONIC
	.4byte gUnknown_82788C7                  @ 049
	.4byte gUnknown_8281FEE                  @ 050
	.4byte gUnknown_827FC59                  @ 051
	.4byte gUnknown_8278665                  @ 052
	.4byte gUnknown_8280365                  @ 053
	.4byte gUnknown_8281170                  @ 054
	.4byte gUnknown_82801CA                  @ 055
	.4byte gUnknown_827F33F                  @ 056
	.4byte gUnknown_8280351                  @ 057
	.4byte gUnknown_827EC4C                  @ 058
	.4byte gUnknown_827F0B9                  @ 059
	.4byte gUnknown_828169F                  @ 060
	.4byte gUnknown_827A6FF                  @ 061
	.4byte gUnknown_827ED90                  @ 062
	.4byte gUnknown_82832F7                  @ 063
	.4byte gUnknown_8280086                  @ 064
	.4byte gUnknown_8279554                  @ 065
	.4byte gUnknown_8280BEB                  @ 066
	.4byte gUnknown_827B060                  @ 067
	.4byte gUnknown_82809A9                  @ 068
	.4byte gUnknown_8285087                  @ 069
	.4byte Move_STRENGTH                       @ MOVE_STRENGTH
	.4byte gUnknown_827F526                  @ 071
	.4byte gUnknown_827F63E                  @ 072
	.4byte gUnknown_827860F                  @ 073
	.4byte gUnknown_827A33F                  @ 074
	.4byte gUnknown_8280EDB                  @ 075
	.4byte gUnknown_827EE64                  @ 076
	.4byte Move_POISON_POWDER                  @ MOVE_POISON_POWDER
	.4byte Move_STUN_SPORE                     @ MOVE_STUN_SPORE
	.4byte Move_SLEEP_POWDER                   @ MOVE_SLEEP_POWDER
	.4byte gUnknown_8280DA3                  @ 080
	.4byte gUnknown_8281D95                  @ 081
	.4byte gUnknown_827E9B9                  @ 082
	.4byte gUnknown_8279222                  @ 083
	.4byte gUnknown_8278928                  @ 084
	.4byte gUnknown_8278996                  @ 085
	.4byte gUnknown_8278B4C                  @ 086
	.4byte gUnknown_827DEC1                  @ 087
	.4byte gUnknown_827A4EB                  @ 088
	.4byte gUnknown_827B0BD                  @ 089
	.4byte gUnknown_827B10A                  @ 090
	.4byte gUnknown_827B22D                  @ 091
	.4byte gUnknown_827FA82                  @ 092
	.4byte gUnknown_827DDB0                  @ 093
	.4byte gUnknown_827DE11                  @ 094
	.4byte gUnknown_8281739                  @ 095
	.4byte gUnknown_827B349                  @ 096
	.4byte gUnknown_827B366                  @ 097
	.4byte gUnknown_827B3B0                  @ 098
	.4byte gUnknown_827B408                  @ 099
	.4byte gUnknown_827B47E                  @ 100
	.4byte gUnknown_8281B0A                  @ 101
	.4byte gUnknown_82820C6                  @ 102
	.4byte Move_SCREECH                        @ MOVE_SCREECH
	.4byte gUnknown_827B497                  @ 104
	.4byte gUnknown_828201C                  @ 105
	.4byte gUnknown_827DA50                  @ 106
	.4byte gUnknown_827B4DE                  @ 107
	.4byte gUnknown_827A89C                  @ 108
	.4byte gUnknown_827A41D                  @ 109
	.4byte gUnknown_827ED83                  @ 110
	.4byte gUnknown_8279908                  @ 111
	.4byte gUnknown_827E67E                  @ 112
	.4byte gUnknown_827E579                  @ 113
	.4byte gUnknown_82811D1                  @ 114
	.4byte gUnknown_827E62B                  @ 115
	.4byte gUnknown_8281C56                  @ 116
	.4byte gUnknown_8281C96                  @ 117
	.4byte gUnknown_827B4F1                  @ 118
	.4byte Move_MIRROR_MOVE                      @ MOVE_MIRROR_MOVE
	.4byte gUnknown_82793A5                  @ 120
	.4byte gUnknown_8281B52                  @ 121
	.4byte gUnknown_8281C2F                  @ 122
	.4byte gUnknown_827E771                  @ 123
	.4byte gUnknown_827FAF1                  @ 124
	.4byte gUnknown_827FDA7                  @ 125
	.4byte gUnknown_82784E1                  @ 126
	.4byte gUnknown_82795AD                  @ 127
	.4byte gUnknown_827EBEF                  @ 128
	.4byte Move_SWIFT                          @ MOVE_SWIFT
	.4byte gUnknown_827B51B                  @ 130
	.4byte gUnknown_8278F7D                  @ 131
	.4byte gUnknown_8282111                  @ 132
	.4byte gUnknown_827B5E1                  @ 133
	.4byte gUnknown_827B605                  @ 134
	.4byte gUnknown_8282239                  @ 135
	.4byte gUnknown_8280752                  @ 136
	.4byte gUnknown_827B656                  @ 137
	.4byte gUnknown_828136E                  @ 138
	.4byte gUnknown_8281571                  @ 139
	.4byte gUnknown_827B6BF                  @ 140
	.4byte gUnknown_827F9D6                  @ 141
	.4byte gUnknown_82825BC                  @ 142
	.4byte gUnknown_827B707                  @ 143
	.4byte gUnknown_8283161                  @ 144
	.4byte gUnknown_827E69B                  @ 145
	.4byte gUnknown_82790E8                  @ 146
	.4byte gUnknown_8280D3E                  @ 147
	.4byte gUnknown_827B89F                  @ 148
	.4byte gUnknown_8281799                  @ 149
	.4byte gUnknown_827B8AC                  @ 150
	.4byte gUnknown_827B8C1                  @ 151
	.4byte gUnknown_8280257                  @ 152
	.4byte gUnknown_8279801                  @ 153
	.4byte gUnknown_8282603                  @ 154
	.4byte gUnknown_827FD53                  @ 155
	.4byte gUnknown_827DD70                  @ 156
	.4byte gUnknown_827A577                  @ 157
	.4byte gUnknown_8282AB5                  @ 158
	.4byte gUnknown_827B8DA                  @ 159
	.4byte gUnknown_827A995                  @ 160
	.4byte gUnknown_8282B1C                  @ 161
	.4byte gUnknown_827B8E6                  @ 162
	.4byte gUnknown_827B967                  @ 163
	.4byte gUnknown_8283D8E                  @ 164
	.4byte gUnknown_827B9A1                  @ 165
	.4byte gUnknown_827BA07                  @ 166
	.4byte gUnknown_828081A                  @ 167
	.4byte gUnknown_827A6B8                  @ 168
	.4byte gUnknown_8281E67                  @ 169
	.4byte gUnknown_827DB4D                  @ 170
	.4byte gUnknown_827BA2F                  @ 171
	.4byte Move_FLAME_WHEEL                   @ MOVE_FLAME_WHEEL
	.4byte gUnknown_827E4E9                  @ 173
	.4byte gUnknown_8282179                  @ 174
	.4byte gUnknown_827BA85                  @ 175
	.4byte gUnknown_827AAAA                  @ 176
	.4byte gUnknown_82800AD                  @ 177
	.4byte gUnknown_8280CE4                  @ 178
	.4byte gUnknown_8278E31                  @ 179
	.4byte gUnknown_827BAC2                  @ 180
	.4byte gUnknown_827F245                  @ 181
	.4byte gUnknown_8279941                  @ 182
	.4byte gUnknown_827BAF1                  @ 183
	.4byte gUnknown_82824F0                  @ 184
	.4byte gUnknown_827E7EC                  @ 185
	.4byte gUnknown_8282553                  @ 186
	.4byte gUnknown_827DA65                  @ 187
	.4byte gUnknown_827FB33                  @ 188
	.4byte gUnknown_827E91B                  @ 189
	.4byte gUnknown_828110A                  @ 190
	.4byte gUnknown_827FE54                  @ 191
	.4byte gUnknown_828181F                  @ 192
	.4byte gUnknown_827BB79                  @ 193
	.4byte gUnknown_827BBB8                  @ 194
	.4byte gUnknown_8282891                  @ 195
	.4byte gUnknown_827A7DC                  @ 196
	.4byte gUnknown_827995E                  @ 197
	.4byte gUnknown_827FE09                  @ 198
	.4byte gUnknown_827A470                  @ 199
	.4byte gUnknown_8279E94                  @ 200
	.4byte gUnknown_8280402                  @ 201
	.4byte gUnknown_827F7CE                  @ 202
	.4byte gUnknown_827BC13                  @ 203
	.4byte gUnknown_827BCA7                  @ 204
	.4byte gUnknown_827BCEA                  @ 205
	.4byte gUnknown_827BD2B                  @ 206
	.4byte gUnknown_827BDB2                  @ 207
	.4byte gUnknown_827BDFA                  @ 208
	.4byte gUnknown_827A02F                  @ 209
	.4byte gUnknown_82792D6                  @ 210
	.4byte gUnknown_8281904                  @ 211
	.4byte gUnknown_827A4A6                  @ 212
	.4byte gUnknown_827A246                  @ 213
	.4byte gUnknown_82829FA                  @ 214
	.4byte gUnknown_82822BB                  @ 215
	.4byte gUnknown_8284055                  @ 216
	.4byte gUnknown_8282718                  @ 217
	.4byte gUnknown_82799BC                  @ 218
	.4byte gUnknown_8279C83                  @ 219
	.4byte gUnknown_8279CC5                  @ 220
	.4byte gUnknown_827E0E4                  @ 221
	.4byte gUnknown_827BE3C                  @ 222
	.4byte gUnknown_82808E1                  @ 223
	.4byte gUnknown_827FEAB                  @ 224
	.4byte gUnknown_827E2FD                  @ 225
	.4byte gUnknown_828286F                  @ 226
	.4byte gUnknown_8282D4E                  @ 227
	.4byte gUnknown_8278F0C                  @ 228
	.4byte gUnknown_827BECD                  @ 229
	.4byte gUnknown_828320D                  @ 230
	.4byte gUnknown_82819B3                  @ 231
	.4byte gUnknown_8281A77                  @ 232
	.4byte gUnknown_8280A78                  @ 233
	.4byte gUnknown_8283179                  @ 234
	.4byte gUnknown_827FA58                  @ 235
	.4byte gUnknown_827BF3A                  @ 236
	.4byte gUnknown_8278D48                  @ 237
	.4byte gUnknown_828068C                  @ 238
	.4byte gUnknown_82855AB                  @ 239
	.4byte gUnknown_827EA96                  @ 240
	.4byte gUnknown_8280C8E                  @ 241
	.4byte gUnknown_827EB3F                  @ 242
	.4byte gUnknown_827E605                  @ 243
	.4byte gUnknown_8279076                  @ 244
	.4byte gUnknown_827BFCA                  @ 245
	.4byte gUnknown_8280FE2                  @ 246
	.4byte gUnknown_8281BEC                  @ 247
	.4byte gUnknown_827DE74                  @ 248
	.4byte gUnknown_8280AF3                  @ 249
	.4byte gUnknown_828048A                  @ 250
	.4byte gUnknown_8278BBB                  @ 251
	.4byte gUnknown_82824B5                  @ 252
	.4byte gUnknown_827C088                  @ 253
	.4byte gUnknown_8282EBB                  @ 254
	.4byte gUnknown_8282F72                  @ 255
	.4byte gUnknown_82830B5                  @ 256
	.4byte gUnknown_827C152                  @ 257
	.4byte gUnknown_827C202                  @ 258
	.4byte gUnknown_827C23A                  @ 259
	.4byte gUnknown_8283439                  @ 260
	.4byte gUnknown_8282C90                  @ 261
	.4byte gUnknown_827C27E                  @ 262
	.4byte gUnknown_827C2C2                  @ 263
	.4byte gUnknown_8283F8E                  @ 264
	.4byte gUnknown_827C2E2                  @ 265
	.4byte gUnknown_827C33D                  @ 266
	.4byte gUnknown_8280FE2                  @ 267
	.4byte gUnknown_827C35C                  @ 268
	.4byte gUnknown_827C3F7                  @ 269
	.4byte gUnknown_827C44B                  @ 270
	.4byte gUnknown_8282DF5                  @ 271
	.4byte gUnknown_8283535                  @ 272
	.4byte gUnknown_8282E73                  @ 273
	.4byte gUnknown_827C4BE                  @ 274
	.4byte gUnknown_8282667                  @ 275
	.4byte gUnknown_827C52F                  @ 276
	.4byte gUnknown_82851E4                  @ 277
	.4byte gUnknown_827C5EA                  @ 278
	.4byte gUnknown_8283CB8                  @ 279
	.4byte gUnknown_827C61E                  @ 280
	.4byte gUnknown_827C7DF                  @ 281
	.4byte gUnknown_828536A                  @ 282
	.4byte gUnknown_827C822                  @ 283
	.4byte gUnknown_827C897                  @ 284
	.4byte gUnknown_827C964                  @ 285
	.4byte gUnknown_827C9AF                  @ 286
	.4byte gUnknown_8283592                  @ 287
	.4byte gUnknown_827C9F2                  @ 288
	.4byte gUnknown_8284AAA                  @ 289
	.4byte gUnknown_8285557                  @ 290
	.4byte gUnknown_8284AC4                  @ 291
	.4byte gUnknown_82837EE                  @ 292
	.4byte gUnknown_827CA1A                  @ 293
	.4byte gUnknown_827CA60                  @ 294
	.4byte gUnknown_827CAA3                  @ 295
	.4byte gUnknown_827CBBA                  @ 296
	.4byte gUnknown_827CC49                  @ 297
	.4byte gUnknown_827CD19                  @ 298
	.4byte gUnknown_82835D5                  @ 299
	.4byte gUnknown_827CD84                  @ 300
	.4byte gUnknown_828582B                  @ 301
	.4byte gUnknown_827CEBB                  @ 302
	.4byte gUnknown_827D06B                  @ 303
	.4byte gUnknown_828365D                  @ 304
	.4byte gUnknown_8283D4F                  @ 305
	.4byte gUnknown_827D083                  @ 306
	.4byte gUnknown_8284569                  @ 307
	.4byte gUnknown_8284F0D                  @ 308
	.4byte gUnknown_8283C31                  @ 309
	.4byte gUnknown_828503F                  @ 310
	.4byte gUnknown_82859FA                  @ 311
	.4byte gUnknown_827D0F2                  @ 312
	.4byte gUnknown_827D254                  @ 313
	.4byte gUnknown_827D2E4                  @ 314
	.4byte gUnknown_8284C1B                  @ 315
	.4byte gUnknown_827D346                  @ 316
	.4byte gUnknown_82847AB                  @ 317
	.4byte gUnknown_8284892                  @ 318
	.4byte gUnknown_8283F3E                  @ 319
	.4byte gUnknown_827D390                  @ 320
	.4byte gUnknown_827D483                  @ 321
	.4byte gUnknown_82844E4                  @ 322
	.4byte gUnknown_827D4EF                  @ 323
	.4byte gUnknown_827F43E                  @ 324
	.4byte gUnknown_827D51D                  @ 325
	.4byte gUnknown_827D578                  @ 326
	.4byte gUnknown_828545E                  @ 327
	.4byte gUnknown_82836F1                  @ 328
	.4byte gUnknown_82837C9                  @ 329
	.4byte gUnknown_8283883                  @ 330
	.4byte gUnknown_8283895                  @ 331
	.4byte gUnknown_827D5E0                  @ 332
	.4byte gUnknown_82781B1                  @ 333
	.4byte gUnknown_827D64A                  @ 334
	.4byte gUnknown_827D674                  @ 335
	.4byte gUnknown_827D683                  @ 336
	.4byte gUnknown_828392B                  @ 337
	.4byte gUnknown_8283D9A                  @ 338
	.4byte gUnknown_827D6A5                  @ 339
	.4byte gUnknown_82805D7                  @ 340
	.4byte gUnknown_8283B94                  @ 341
	.4byte gUnknown_8281A11                  @ 342
	.4byte gUnknown_827D6C3                  @ 343
	.4byte gUnknown_827D720                  @ 344
	.4byte gUnknown_828570A                  @ 345
	.4byte gUnknown_827D818                  @ 346
	.4byte gUnknown_827D83E                  @ 347
	.4byte gUnknown_827D8BC                  @ 348
	.4byte gUnknown_827D93F                  @ 349
	.4byte gUnknown_8284B7E                  @ 350
	.4byte gUnknown_827D9AE                  @ 351
	.4byte gUnknown_8285201                  @ 352
	.4byte gUnknown_82853FA                  @ 353
	.4byte gUnknown_82852F6                  @ 354
	.4byte gUnknown_8285C76                  @ 355

gBattleAnims_StatusConditions:: @ 0x8277888
	.4byte gUnknown_82862E1                  @ 000
	.4byte gUnknown_828630C                  @ 001
	.4byte gUnknown_8286315                  @ 002
	.4byte gUnknown_8286345                  @ 003
	.4byte gUnknown_828637A                  @ 004
	.4byte gUnknown_82863A6                  @ 005
	.4byte gUnknown_82863C0                  @ 006
	.4byte gUnknown_82863DB                  @ 007
	.4byte gUnknown_8286400                  @ 008

gBattleAnims_General:: @ 0x82778AC
	.4byte gUnknown_8286425                  @ 000
	.4byte gUnknown_828645B                  @ 001
	.4byte gUnknown_8286464                  @ 002
	.4byte gUnknown_82864A1                  @ 003
	.4byte gUnknown_82864A9                  @ 004
	.4byte gUnknown_82864F1                  @ 005
	.4byte gUnknown_82864FC                  @ 006
	.4byte gUnknown_828668F                  @ 007
	.4byte gUnknown_8286703                  @ 008
	.4byte gUnknown_82867DF                  @ 009
	.4byte gUnknown_828682C                  @ 010
	.4byte gUnknown_8286875                  @ 011
	.4byte gUnknown_828687A                  @ 012
	.4byte gUnknown_828687F                  @ 013
	.4byte gUnknown_8286884                  @ 014
	.4byte gUnknown_8286892                  @ 015
	.4byte gUnknown_82868C3                  @ 016
	.4byte gUnknown_82868E8                  @ 017
	.4byte gUnknown_8286946                  @ 018
	.4byte gUnknown_82869A5                  @ 019
	.4byte gUnknown_8286A6A                  @ 020
	.4byte gUnknown_8286AAA                  @ 021
	.4byte gUnknown_8286AED                  @ 022

gBattleAnims_Special:: @ 0x8277908
	.4byte 0x08286B6A, 0x08286B8B, 0x08286B9C, 0x08286BAD, 0x08286C01, 0x08286C1A, 0x08286C24
Move_NONE:
Move_MIRROR_MOVE:
Move_POUND:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_M_DOUBLE_SLAP, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_DOUBLE_SLAP: @ 0x08277955
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	choosetwoturnanim DoubleSlapLeft, DoubleSlapRight
DoubleSlapContinue:
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_M_DOUBLE_SLAP, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
DoubleSlapLeft:
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=-8, y=0, relative_to=ANIM_TARGET, animation=2
	goto DoubleSlapContinue
DoubleSlapRight:
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=8, y=0, relative_to=ANIM_TARGET, animation=2
	goto DoubleSlapContinue

Move_POISON_POWDER: @ 0x082779A8
	loadspritegfx ANIM_TAG_POISON_POWDER
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	loopsewithpan SE_M_POISON_POWDER, SOUND_PAN_TARGET, 10, 6
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=-30, y=-22, duration=117, y_velocity=80/256, wave_amplitude=5, wave_speed=1
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=10, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=-25, y=-22, duration=117, y_velocity=112/256, wave_amplitude=5, wave_speed=3
	delay 15
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=-5, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=5, y=-22, duration=117, y_velocity=96/256, wave_amplitude=5, wave_speed=1
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=0, y=-22, duration=117, y_velocity=69/256, wave_amplitude=-5, wave_speed=1
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=-15, y=-22, duration=117, y_velocity=112/256, wave_amplitude=5, wave_speed=2
	delay 30
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=-15, y=-22, duration=117, y_velocity=112/256, wave_amplitude=5, wave_speed=2
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=15, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=-10, y=-22, duration=117, y_velocity=96/256, wave_amplitude=7, wave_speed=2
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=-5, y=-22, duration=117, y_velocity=90/256, wave_amplitude=-8, wave_speed=0
	delay 20
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=-10, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=0, y=-22, duration=117, y_velocity=89/256, wave_amplitude=5, wave_speed=2
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=20, y=-22, duration=117, y_velocity=112/256, wave_amplitude=-8, wave_speed=2
	create_poison_powder_particle_sprite ANIM_TARGET, 2, x=5, y=-22, duration=117, y_velocity=80/256, wave_amplitude=5, wave_speed=1
	waitforvisualfinish
	end

Move_STUN_SPORE: @ 0x08277AD9
	loadspritegfx ANIM_TAG_STUN_SPORE
	loopsewithpan SE_M_POISON_POWDER, SOUND_PAN_TARGET, 10, 6
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=-30, y=-22, duration=117, y_velocity=80/256, wave_amplitude=5, wave_speed=1
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=10, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=-25, y=-22, duration=117, y_velocity=112/256, wave_amplitude=5, wave_speed=3
	delay 15
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=-5, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=5, y=-22, duration=117, y_velocity=96/256, wave_amplitude=5, wave_speed=1
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=0, y=-22, duration=117, y_velocity=69/256, wave_amplitude=-5, wave_speed=1
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=-15, y=-22, duration=117, y_velocity=112/256, wave_amplitude=5, wave_speed=2
	delay 30
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=-15, y=-22, duration=117, y_velocity=112/256, wave_amplitude=5, wave_speed=2
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=15, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=-10, y=-22, duration=117, y_velocity=96/256, wave_amplitude=7, wave_speed=2
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=-5, y=-22, duration=117, y_velocity=90/256, wave_amplitude=-8, wave_speed=0
	delay 20
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=-10, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=0, y=-22, duration=117, y_velocity=89/256, wave_amplitude=5, wave_speed=2
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=20, y=-22, duration=117, y_velocity=112/256, wave_amplitude=-8, wave_speed=2
	create_stun_spore_particle_sprite ANIM_TARGET, 2, x=5, y=-22, duration=117, y_velocity=80/256, wave_amplitude=5, wave_speed=1
	waitforvisualfinish
	end

Move_SLEEP_POWDER: @ 0x08277C07
	loadspritegfx ANIM_TAG_SLEEP_POWDER
	loopsewithpan SE_M_POISON_POWDER, SOUND_PAN_TARGET, 10, 6
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=-30, y=-22, duration=117, y_velocity=80/256, wave_amplitude=5, wave_speed=1
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=10, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=-25, y=-22, duration=117, y_velocity=112/256, wave_amplitude=5, wave_speed=3
	delay 15
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=-5, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=5, y=-22, duration=117, y_velocity=96/256, wave_amplitude=5, wave_speed=1
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=0, y=-22, duration=117, y_velocity=69/256, wave_amplitude=-5, wave_speed=1
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=-15, y=-22, duration=117, y_velocity=112/256, wave_amplitude=5, wave_speed=2
	delay 30
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=-15, y=-22, duration=117, y_velocity=112/256, wave_amplitude=5, wave_speed=2
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=15, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=-10, y=-22, duration=117, y_velocity=96/256, wave_amplitude=7, wave_speed=2
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=-5, y=-22, duration=117, y_velocity=90/256, wave_amplitude=-8, wave_speed=0
	delay 20
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=-10, y=-22, duration=117, y_velocity=80/256, wave_amplitude=-5, wave_speed=1
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=0, y=-22, duration=117, y_velocity=89/256, wave_amplitude=5, wave_speed=2
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=20, y=-22, duration=117, y_velocity=112/256, wave_amplitude=-8, wave_speed=2
	create_sleep_powder_particle_sprite ANIM_TARGET, 2, x=5, y=-22, duration=117, y_velocity=80/256, wave_amplitude=5, wave_speed=1
	waitforvisualfinish
	end

Move_SWIFT: @ 0x08277D35
	loadspritegfx ANIM_TAG_YELLOW_STAR
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_M_SWIFT, SOUND_PAN_ATTACKER
	create_swift_star_sprite ANIM_TARGET, 3, initial_x=20, initial_y=-10, target_x=20, target_y=0, duration=22, wave_amplitude=20, target_both=TRUE
	delay 5
	playsewithpan SE_M_SWIFT, SOUND_PAN_ATTACKER
	create_swift_star_sprite ANIM_TARGET, 3, initial_x=20, initial_y=-10, target_x=20, target_y=5, duration=22, wave_amplitude=-18, target_both=TRUE
	delay 5
	playsewithpan SE_M_SWIFT, SOUND_PAN_ATTACKER
	create_swift_star_sprite ANIM_TARGET, 3, initial_x=20, initial_y=-10, target_x=20, target_y=-10, duration=22, wave_amplitude=15, target_both=TRUE
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 18, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 2, 0, 18, 1
	delay 5
	playsewithpan SE_M_SWIFT, SOUND_PAN_ATTACKER
	create_swift_star_sprite ANIM_TARGET, 3, initial_x=20, initial_y=-10, target_x=20, target_y=0, duration=22, wave_amplitude=-20, target_both=TRUE
	delay 5
	playsewithpan SE_M_SWIFT, SOUND_PAN_ATTACKER
	create_swift_star_sprite ANIM_TARGET, 3, initial_x=20, initial_y=-10, target_x=20, target_y=0, duration=22, wave_amplitude=12, target_both=TRUE
	delay 5
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_STRENGTH: @ 0x08277DEE
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_M_TAKE_DOWN, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ShakeAndSinkMon, 5, ANIM_ATTACKER, 2, 0, 96, 30
	waitforvisualfinish
	delay 10
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 4
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_TARGET, 18, 6, 2, 4
	delay 4
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=16, y=12, relative_to=ANIM_TARGET, animation=1
	delay 4
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=-16, y=-12, relative_to=ANIM_TARGET, animation=1
	delay 4
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=3, y=4, relative_to=ANIM_TARGET, animation=1
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_TACKLE: @ 0x08277E82
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 4
	delay 6
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_BODY_SLAM: @ 0x08277EC0
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_M_TAKE_DOWN, SOUND_PAN_ATTACKER
	createsprite gVerticalDipSpriteTemplate, ANIM_ATTACKER, 2, 6, 1, ANIM_ATTACKER
	waitforvisualfinish
	delay 11
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 26, 0, 0, 5
	delay 6
	create_basic_hitsplat_sprite ANIM_ATTACKER, 4, x=-10, y=0, relative_to=ANIM_TARGET, animation=0
	loopsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET, 10, 2
	delay 1
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -28, 0, 0, 3
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 12, 1
	waitforvisualfinish
	delay 10
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 6
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 6
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SUPERSONIC: @ 0x08277F4D
	loadspritegfx ANIM_TAG_GOLD_RING
	monbg ANIM_ATK_PARTNER
	splitbgprio_foes ANIM_ATTACKER
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 2, 0, 8, 1
	call SupersonicRing
	call SupersonicRing
	call SupersonicRing
	call SupersonicRing
	call SupersonicRing
	call SupersonicRing
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end
SupersonicRing:
	playsewithpan SE_M_SUPERSONIC, SOUND_PAN_ATTACKER
	createsprite gSupersonicRingSpriteTemplate, ANIM_TARGET, 2, 16, 0, 0, 0, 30, 0
	delay 2
	return

Move_SCREECH: @ 0x08277FA5
	loadspritegfx ANIM_TAG_PURPLE_RING
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 3, 0, 2, 1
	call ScreechRing
	call ScreechRing
	delay 16
	createvisualtask AnimTask_SwayMon, 5, 0, 6, 2048, 2, ANIM_TARGET
	waitforvisualfinish
	end
ScreechRing:
	playsewithpan SE_M_SCREECH, SOUND_PAN_ATTACKER
	createsprite gScreechRingSpriteTemplate, ANIM_TARGET, 2, 16, 0, 0, 0, 30, 0
	delay 2
	return

Move_FLAME_WHEEL: @ 0x08277FF2
	loadspritegfx ANIM_TAG_SMALL_EMBER
	monbg ANIM_DEF_PARTNER
	splitbgprio_foes ANIM_TARGET
	createsprite gFireSpiralOutwardSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 56, 0
	playsewithpan SE_M_FLAME_WHEEL, SOUND_PAN_ATTACKER
	delay 2
	createsprite gFireSpiralOutwardSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 56, 4
	playsewithpan SE_M_FLAME_WHEEL, SOUND_PAN_ATTACKER
	delay 2
	createsprite gFireSpiralOutwardSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 56, 8
	playsewithpan SE_M_FLAME_WHEEL, SOUND_PAN_ATTACKER
	delay 2
	createsprite gFireSpiralOutwardSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 56, 12
	playsewithpan SE_M_FLAME_WHEEL, SOUND_PAN_ATTACKER
	delay 2
	createsprite gFireSpiralOutwardSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 56, 16
	playsewithpan SE_M_FLAME_WHEEL, SOUND_PAN_ATTACKER
	delay 2
	createsprite gFireSpiralOutwardSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 56, 20
	playsewithpan SE_M_FLAME_WHEEL, SOUND_PAN_ATTACKER
	delay 2
	createsprite gFireSpiralOutwardSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 56, 24
	playsewithpan SE_M_FLAME_WHEEL, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 24, 0, 0, 6
	delay 4
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 8, 1
	createvisualtask AnimTask_BlendMonInAndOut, 3, ANIM_TARGET, RGB_RED, 12, 1, 1
	playsewithpan SE_M_FLAME_WHEEL2, SOUND_PAN_TARGET
	call FireSpreadEffect
	delay 7
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 9
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

FlameWheel1: @ Unused
	createsprite gFireSpiralOutwardSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 50
	delay 4
	return

gUnknown_82780EC: @ 0x082780EC
	.incbin "baserom_jp.gba", 0x2780ec, 0xc5

gUnknown_82781B1: @ 0x082781B1
	.incbin "baserom_jp.gba", 0x2781b1, 0xc5

gUnknown_8278276: @ 0x08278276
	.incbin "baserom_jp.gba", 0x278276, 0x90

gUnknown_8278306: @ 0x08278306
	.incbin "baserom_jp.gba", 0x278306, 0x113

gUnknown_8278419: @ 0x08278419
	.incbin "baserom_jp.gba", 0x278419, 0x55

gUnknown_827846E: @ 0x0827846E
	.incbin "baserom_jp.gba", 0x27846e, 0x73

gUnknown_82784E1: @ 0x082784E1
	.incbin "baserom_jp.gba", 0x2784e1, 0x12e

gUnknown_827860F: @ 0x0827860F
	.incbin "baserom_jp.gba", 0x27860f, 0x56

gUnknown_8278665: @ 0x08278665
	.incbin "baserom_jp.gba", 0x278665, 0x74

gUnknown_82786D9: @ 0x082786D9
	.incbin "baserom_jp.gba", 0x2786d9, 0xda

gUnknown_82787B3: @ 0x082787B3
	.incbin "baserom_jp.gba", 0x2787b3, 0x9c

gUnknown_827884F: @ 0x0827884F
	.incbin "baserom_jp.gba", 0x27884f, 0x78

gUnknown_82788C7: @ 0x082788C7
	.incbin "baserom_jp.gba", 0x2788c7, 0x61

gUnknown_8278928: @ 0x08278928
	.incbin "baserom_jp.gba", 0x278928, 0x6e

gUnknown_8278996: @ 0x08278996
	.incbin "baserom_jp.gba", 0x278996, 0x1b6

gUnknown_8278B4C: @ 0x08278B4C
	.incbin "baserom_jp.gba", 0x278b4c, 0x6f

gUnknown_8278BBB: @ 0x08278BBB
	.incbin "baserom_jp.gba", 0x278bbb, 0xfb

gUnknown_8278CB6: @ 0x08278CB6
	.incbin "baserom_jp.gba", 0x278cb6, 0x47

gUnknown_8278CFD: @ 0x08278CFD
	.incbin "baserom_jp.gba", 0x278cfd, 0x19

gUnknown_8278D16: @ 0x08278D16
	.incbin "baserom_jp.gba", 0x278d16, 0x32

gUnknown_8278D48: @ 0x08278D48
	.incbin "baserom_jp.gba", 0x278d48, 0xe9

gUnknown_8278E31: @ 0x08278E31
	.incbin "baserom_jp.gba", 0x278e31, 0xdb

gUnknown_8278F0C: @ 0x08278F0C
	.incbin "baserom_jp.gba", 0x278f0c, 0x71

gUnknown_8278F7D: @ 0x08278F7D
	.incbin "baserom_jp.gba", 0x278f7d, 0xb3

gUnknown_8279030: @ 0x08279030
	.incbin "baserom_jp.gba", 0x279030, 0x46

gUnknown_8279076: @ 0x08279076
	.incbin "baserom_jp.gba", 0x279076, 0x72

gUnknown_82790E8: @ 0x082790E8
	.incbin "baserom_jp.gba", 0x2790e8, 0x13a

gUnknown_8279222: @ 0x08279222
	.incbin "baserom_jp.gba", 0x279222, 0xb4

gUnknown_82792D6: @ 0x082792D6
	.incbin "baserom_jp.gba", 0x2792d6, 0xcf

gUnknown_82793A5: @ 0x082793A5
	.incbin "baserom_jp.gba", 0x2793a5, 0xf0

gUnknown_8279495: @ 0x08279495
	.incbin "baserom_jp.gba", 0x279495, 0x88

gUnknown_827951D: @ 0x0827951D
	.incbin "baserom_jp.gba", 0x27951d, 0x37

gUnknown_8279554: @ 0x08279554
	.incbin "baserom_jp.gba", 0x279554, 0x59

gUnknown_82795AD: @ 0x082795AD
	.incbin "baserom_jp.gba", 0x2795ad, 0x254

gUnknown_8279801: @ 0x08279801
	.incbin "baserom_jp.gba", 0x279801, 0x107

gUnknown_8279908: @ 0x08279908
	.incbin "baserom_jp.gba", 0x279908, 0x39

gUnknown_8279941: @ 0x08279941
	.incbin "baserom_jp.gba", 0x279941, 0x1d

gUnknown_827995E: @ 0x0827995E
	.incbin "baserom_jp.gba", 0x27995e, 0x5e

gUnknown_82799BC: @ 0x082799BC
	.incbin "baserom_jp.gba", 0x2799bc, 0x2c7

gUnknown_8279C83: @ 0x08279C83
	.incbin "baserom_jp.gba", 0x279c83, 0x42

gUnknown_8279CC5: @ 0x08279CC5
	.incbin "baserom_jp.gba", 0x279cc5, 0xa8

gUnknown_8279D6D: @ 0x08279D6D
	.incbin "baserom_jp.gba", 0x279d6d, 0x48

gUnknown_8279DB5: @ 0x08279DB5
	.incbin "baserom_jp.gba", 0x279db5, 0x8c

gUnknown_8279E41: @ 0x08279E41
	.incbin "baserom_jp.gba", 0x279e41, 0x53

gUnknown_8279E94: @ 0x08279E94
	.incbin "baserom_jp.gba", 0x279e94, 0x19b

gUnknown_827A02F: @ 0x0827A02F
	.incbin "baserom_jp.gba", 0x27a02f, 0x217

gUnknown_827A246: @ 0x0827A246
	.incbin "baserom_jp.gba", 0x27a246, 0xf9

gUnknown_827A33F: @ 0x0827A33F
	.incbin "baserom_jp.gba", 0x27a33f, 0x36

gUnknown_827A375: @ 0x0827A375
	.incbin "baserom_jp.gba", 0x27a375, 0xa8

gUnknown_827A41D: @ 0x0827A41D
	.incbin "baserom_jp.gba", 0x27a41d, 0x53

gUnknown_827A470: @ 0x0827A470
	.incbin "baserom_jp.gba", 0x27a470, 0x36

gUnknown_827A4A6: @ 0x0827A4A6
	.incbin "baserom_jp.gba", 0x27a4a6, 0x45

gUnknown_827A4EB: @ 0x0827A4EB
	.incbin "baserom_jp.gba", 0x27a4eb, 0x8c

gUnknown_827A577: @ 0x0827A577
	.incbin "baserom_jp.gba", 0x27a577, 0x141

gUnknown_827A6B8: @ 0x0827A6B8
	.incbin "baserom_jp.gba", 0x27a6b8, 0x47

gUnknown_827A6FF: @ 0x0827A6FF
	.incbin "baserom_jp.gba", 0x27a6ff, 0xdd

gUnknown_827A7DC: @ 0x0827A7DC
	.incbin "baserom_jp.gba", 0x27a7dc, 0xc0

gUnknown_827A89C: @ 0x0827A89C
	.incbin "baserom_jp.gba", 0x27a89c, 0xf9

gUnknown_827A995: @ 0x0827A995
	.incbin "baserom_jp.gba", 0x27a995, 0x115

gUnknown_827AAAA: @ 0x0827AAAA
	.incbin "baserom_jp.gba", 0x27aaaa, 0x11c

gUnknown_827ABC6: @ 0x0827ABC6
	.incbin "baserom_jp.gba", 0x27abc6, 0x83

gUnknown_827AC49: @ 0x0827AC49
	.incbin "baserom_jp.gba", 0x27ac49, 0x5d

gUnknown_827ACA6: @ 0x0827ACA6
	.incbin "baserom_jp.gba", 0x27aca6, 0x6d

gUnknown_827AD13: @ 0x0827AD13
	.incbin "baserom_jp.gba", 0x27ad13, 0x7d

gUnknown_827AD90: @ 0x0827AD90
	.incbin "baserom_jp.gba", 0x27ad90, 0x17d

gUnknown_827AF0D: @ 0x0827AF0D
	.incbin "baserom_jp.gba", 0x27af0d, 0x7f

gUnknown_827AF8C: @ 0x0827AF8C
	.incbin "baserom_jp.gba", 0x27af8c, 0xd4

gUnknown_827B060: @ 0x0827B060
	.incbin "baserom_jp.gba", 0x27b060, 0x5d

gUnknown_827B0BD: @ 0x0827B0BD
	.incbin "baserom_jp.gba", 0x27b0bd, 0x4d

gUnknown_827B10A: @ 0x0827B10A
	.incbin "baserom_jp.gba", 0x27b10a, 0x123

gUnknown_827B22D: @ 0x0827B22D
	.incbin "baserom_jp.gba", 0x27b22d, 0x11c

gUnknown_827B349: @ 0x0827B349
	.incbin "baserom_jp.gba", 0x27b349, 0x1d

gUnknown_827B366: @ 0x0827B366
	.incbin "baserom_jp.gba", 0x27b366, 0x4a

gUnknown_827B3B0: @ 0x0827B3B0
	.incbin "baserom_jp.gba", 0x27b3b0, 0x58

gUnknown_827B408: @ 0x0827B408
	.incbin "baserom_jp.gba", 0x27b408, 0x76

gUnknown_827B47E: @ 0x0827B47E
	.incbin "baserom_jp.gba", 0x27b47e, 0x19

gUnknown_827B497: @ 0x0827B497
	.incbin "baserom_jp.gba", 0x27b497, 0x47

gUnknown_827B4DE: @ 0x0827B4DE
	.incbin "baserom_jp.gba", 0x27b4de, 0x13

gUnknown_827B4F1: @ 0x0827B4F1
	.incbin "baserom_jp.gba", 0x27b4f1, 0x2a

gUnknown_827B51B: @ 0x0827B51B
	.incbin "baserom_jp.gba", 0x27b51b, 0xc6

gUnknown_827B5E1: @ 0x0827B5E1
	.incbin "baserom_jp.gba", 0x27b5e1, 0x24

gUnknown_827B605: @ 0x0827B605
	.incbin "baserom_jp.gba", 0x27b605, 0x51

gUnknown_827B656: @ 0x0827B656
	.incbin "baserom_jp.gba", 0x27b656, 0x69

gUnknown_827B6BF: @ 0x0827B6BF
	.incbin "baserom_jp.gba", 0x27b6bf, 0x48

gUnknown_827B707: @ 0x0827B707
	.incbin "baserom_jp.gba", 0x27b707, 0x198

gUnknown_827B89F: @ 0x0827B89F
	.incbin "baserom_jp.gba", 0x27b89f, 0xd

gUnknown_827B8AC: @ 0x0827B8AC
	.incbin "baserom_jp.gba", 0x27b8ac, 0x15

gUnknown_827B8C1: @ 0x0827B8C1
	.incbin "baserom_jp.gba", 0x27b8c1, 0x19

gUnknown_827B8DA: @ 0x0827B8DA
	.incbin "baserom_jp.gba", 0x27b8da, 0xc

gUnknown_827B8E6: @ 0x0827B8E6
	.incbin "baserom_jp.gba", 0x27b8e6, 0x81

gUnknown_827B967: @ 0x0827B967
	.incbin "baserom_jp.gba", 0x27b967, 0x3a

gUnknown_827B9A1: @ 0x0827B9A1
	.incbin "baserom_jp.gba", 0x27b9a1, 0x66

gUnknown_827BA07: @ 0x0827BA07
	.incbin "baserom_jp.gba", 0x27ba07, 0x28

gUnknown_827BA2F: @ 0x0827BA2F
	.incbin "baserom_jp.gba", 0x27ba2f, 0x56

gUnknown_827BA85: @ 0x0827BA85
	.incbin "baserom_jp.gba", 0x27ba85, 0x3d

gUnknown_827BAC2: @ 0x0827BAC2
	.incbin "baserom_jp.gba", 0x27bac2, 0x2f

gUnknown_827BAF1: @ 0x0827BAF1
	.incbin "baserom_jp.gba", 0x27baf1, 0x88

gUnknown_827BB79: @ 0x0827BB79
	.incbin "baserom_jp.gba", 0x27bb79, 0x3f

gUnknown_827BBB8: @ 0x0827BBB8
	.incbin "baserom_jp.gba", 0x27bbb8, 0x5b

gUnknown_827BC13: @ 0x0827BC13
	.incbin "baserom_jp.gba", 0x27bc13, 0x94

gUnknown_827BCA7: @ 0x0827BCA7
	.incbin "baserom_jp.gba", 0x27bca7, 0x43

gUnknown_827BCEA: @ 0x0827BCEA
	.incbin "baserom_jp.gba", 0x27bcea, 0x41

gUnknown_827BD2B: @ 0x0827BD2B
	.incbin "baserom_jp.gba", 0x27bd2b, 0x87

gUnknown_827BDB2: @ 0x0827BDB2
	.incbin "baserom_jp.gba", 0x27bdb2, 0x48

gUnknown_827BDFA: @ 0x0827BDFA
	.incbin "baserom_jp.gba", 0x27bdfa, 0x42

gUnknown_827BE3C: @ 0x0827BE3C
	.incbin "baserom_jp.gba", 0x27be3c, 0x91

gUnknown_827BECD: @ 0x0827BECD
	.incbin "baserom_jp.gba", 0x27becd, 0x6d

gUnknown_827BF3A: @ 0x0827BF3A
	.incbin "baserom_jp.gba", 0x27bf3a, 0x90

gUnknown_827BFCA: @ 0x0827BFCA
	.incbin "baserom_jp.gba", 0x27bfca, 0xbe

gUnknown_827C088: @ 0x0827C088
	.incbin "baserom_jp.gba", 0x27c088, 0xca

gUnknown_827C152: @ 0x0827C152
	.incbin "baserom_jp.gba", 0x27c152, 0xb0

gUnknown_827C202: @ 0x0827C202
	.incbin "baserom_jp.gba", 0x27c202, 0x38

gUnknown_827C23A: @ 0x0827C23A
	.incbin "baserom_jp.gba", 0x27c23a, 0x44

gUnknown_827C27E: @ 0x0827C27E
	.incbin "baserom_jp.gba", 0x27c27e, 0x44

gUnknown_827C2C2: @ 0x0827C2C2
	.incbin "baserom_jp.gba", 0x27c2c2, 0x20

gUnknown_827C2E2: @ 0x0827C2E2
	.incbin "baserom_jp.gba", 0x27c2e2, 0x5b

gUnknown_827C33D: @ 0x0827C33D
	.incbin "baserom_jp.gba", 0x27c33d, 0x1f

gUnknown_827C35C: @ 0x0827C35C
	.incbin "baserom_jp.gba", 0x27c35c, 0x9b

gUnknown_827C3F7: @ 0x0827C3F7
	.incbin "baserom_jp.gba", 0x27c3f7, 0x54

gUnknown_827C44B: @ 0x0827C44B
	.incbin "baserom_jp.gba", 0x27c44b, 0x73

gUnknown_827C4BE: @ 0x0827C4BE
	.incbin "baserom_jp.gba", 0x27c4be, 0x71

gUnknown_827C52F: @ 0x0827C52F
	.incbin "baserom_jp.gba", 0x27c52f, 0xbb

gUnknown_827C5EA: @ 0x0827C5EA
	.incbin "baserom_jp.gba", 0x27c5ea, 0x34

gUnknown_827C61E: @ 0x0827C61E
	.incbin "baserom_jp.gba", 0x27c61e, 0x1c1

gUnknown_827C7DF: @ 0x0827C7DF
	.incbin "baserom_jp.gba", 0x27c7df, 0x43

gUnknown_827C822: @ 0x0827C822
	.incbin "baserom_jp.gba", 0x27c822, 0x75

gUnknown_827C897: @ 0x0827C897
	.incbin "baserom_jp.gba", 0x27c897, 0xcd

gUnknown_827C964: @ 0x0827C964
	.incbin "baserom_jp.gba", 0x27c964, 0x4b

gUnknown_827C9AF: @ 0x0827C9AF
	.incbin "baserom_jp.gba", 0x27c9af, 0x43

gUnknown_827C9F2: @ 0x0827C9F2
	.incbin "baserom_jp.gba", 0x27c9f2, 0x28

gUnknown_827CA1A: @ 0x0827CA1A
	.incbin "baserom_jp.gba", 0x27ca1a, 0x46

gUnknown_827CA60: @ 0x0827CA60
	.incbin "baserom_jp.gba", 0x27ca60, 0x43

gUnknown_827CAA3: @ 0x0827CAA3
	.incbin "baserom_jp.gba", 0x27caa3, 0x117

gUnknown_827CBBA: @ 0x0827CBBA
	.incbin "baserom_jp.gba", 0x27cbba, 0x8f

gUnknown_827CC49: @ 0x0827CC49
	.incbin "baserom_jp.gba", 0x27cc49, 0xd0

gUnknown_827CD19: @ 0x0827CD19
	.incbin "baserom_jp.gba", 0x27cd19, 0x6b

gUnknown_827CD84: @ 0x0827CD84
	.incbin "baserom_jp.gba", 0x27cd84, 0x137

gUnknown_827CEBB: @ 0x0827CEBB
	.incbin "baserom_jp.gba", 0x27cebb, 0x1b0

gUnknown_827D06B: @ 0x0827D06B
	.incbin "baserom_jp.gba", 0x27d06b, 0x18

gUnknown_827D083: @ 0x0827D083
	.incbin "baserom_jp.gba", 0x27d083, 0x6f

gUnknown_827D0F2: @ 0x0827D0F2
	.incbin "baserom_jp.gba", 0x27d0f2, 0x162

gUnknown_827D254: @ 0x0827D254
	.incbin "baserom_jp.gba", 0x27d254, 0x90

gUnknown_827D2E4: @ 0x0827D2E4
	.incbin "baserom_jp.gba", 0x27d2e4, 0x62

gUnknown_827D346: @ 0x0827D346
	.incbin "baserom_jp.gba", 0x27d346, 0x4a

gUnknown_827D390: @ 0x0827D390
	.incbin "baserom_jp.gba", 0x27d390, 0xf3

gUnknown_827D483: @ 0x0827D483
	.incbin "baserom_jp.gba", 0x27d483, 0x6c

gUnknown_827D4EF: @ 0x0827D4EF
	.incbin "baserom_jp.gba", 0x27d4ef, 0x2e

gUnknown_827D51D: @ 0x0827D51D
	.incbin "baserom_jp.gba", 0x27d51d, 0x5b

gUnknown_827D578: @ 0x0827D578
	.incbin "baserom_jp.gba", 0x27d578, 0x68

gUnknown_827D5E0: @ 0x0827D5E0
	.incbin "baserom_jp.gba", 0x27d5e0, 0x6a

gUnknown_827D64A: @ 0x0827D64A
	.incbin "baserom_jp.gba", 0x27d64a, 0x2a

gUnknown_827D674: @ 0x0827D674
	.incbin "baserom_jp.gba", 0x27d674, 0xf

gUnknown_827D683: @ 0x0827D683
	.incbin "baserom_jp.gba", 0x27d683, 0x22

gUnknown_827D6A5: @ 0x0827D6A5
	.incbin "baserom_jp.gba", 0x27d6a5, 0x1e

gUnknown_827D6C3: @ 0x0827D6C3
	.incbin "baserom_jp.gba", 0x27d6c3, 0x5d

gUnknown_827D720: @ 0x0827D720
	.incbin "baserom_jp.gba", 0x27d720, 0xf8

gUnknown_827D818: @ 0x0827D818
	.incbin "baserom_jp.gba", 0x27d818, 0x26

gUnknown_827D83E: @ 0x0827D83E
	.incbin "baserom_jp.gba", 0x27d83e, 0x7e

gUnknown_827D8BC: @ 0x0827D8BC
	.incbin "baserom_jp.gba", 0x27d8bc, 0x83

gUnknown_827D93F: @ 0x0827D93F
	.incbin "baserom_jp.gba", 0x27d93f, 0x6f

gUnknown_827D9AE: @ 0x0827D9AE
	.incbin "baserom_jp.gba", 0x27d9ae, 0xa2

gUnknown_827DA50: @ 0x0827DA50
	.incbin "baserom_jp.gba", 0x27da50, 0x15

gUnknown_827DA65: @ 0x0827DA65
	.incbin "baserom_jp.gba", 0x27da65, 0xe8

gUnknown_827DB4D: @ 0x0827DB4D
	.incbin "baserom_jp.gba", 0x27db4d, 0x138

gUnknown_827DC85: @ 0x0827DC85
	.incbin "baserom_jp.gba", 0x27dc85, 0xeb

gUnknown_827DD70: @ 0x0827DD70
	.incbin "baserom_jp.gba", 0x27dd70, 0x40

gUnknown_827DDB0: @ 0x0827DDB0
	.incbin "baserom_jp.gba", 0x27ddb0, 0x61

gUnknown_827DE11: @ 0x0827DE11
	.incbin "baserom_jp.gba", 0x27de11, 0x63

gUnknown_827DE74: @ 0x0827DE74
	.incbin "baserom_jp.gba", 0x27de74, 0x4d

gUnknown_827DEC1: @ 0x0827DEC1
	.incbin "baserom_jp.gba", 0x27dec1, 0x15a

gUnknown_827E01B: @ 0x0827E01B
	.incbin "baserom_jp.gba", 0x27e01b, 0xc9

gUnknown_827E0E4: @ 0x0827E0E4
	.incbin "baserom_jp.gba", 0x27e0e4, 0x1e7

gUnknown_827E2CB: @ 0x0827E2CB
	.incbin "baserom_jp.gba", 0x27e2cb, 0x32

gUnknown_827E2FD: @ 0x0827E2FD
	.incbin "baserom_jp.gba", 0x27e2fd, 0x114

gUnknown_827E411: @ 0x0827E411
	.incbin "baserom_jp.gba", 0x27e411, 0x97

gUnknown_827E4A8: @ 0x0827E4A8
	.incbin "baserom_jp.gba", 0x27e4a8, 0x41

gUnknown_827E4E9: @ 0x0827E4E9
	.incbin "baserom_jp.gba", 0x27e4e9, 0x90

gUnknown_827E579: @ 0x0827E579
	.incbin "baserom_jp.gba", 0x27e579, 0x8c

gUnknown_827E605: @ 0x0827E605
	.incbin "baserom_jp.gba", 0x27e605, 0x26

gUnknown_827E62B: @ 0x0827E62B
	.incbin "baserom_jp.gba", 0x27e62b, 0x53

gUnknown_827E67E: @ 0x0827E67E
	.incbin "baserom_jp.gba", 0x27e67e, 0x1d

gUnknown_827E69B: @ 0x0827E69B
	.incbin "baserom_jp.gba", 0x27e69b, 0xd6

gUnknown_827E771: @ 0x0827E771
	.incbin "baserom_jp.gba", 0x27e771, 0x7b

gUnknown_827E7EC: @ 0x0827E7EC
	.incbin "baserom_jp.gba", 0x27e7ec, 0x87

gUnknown_827E873: @ 0x0827E873
	.incbin "baserom_jp.gba", 0x27e873, 0xa8

gUnknown_827E91B: @ 0x0827E91B
	.incbin "baserom_jp.gba", 0x27e91b, 0x9e

gUnknown_827E9B9: @ 0x0827E9B9
	.incbin "baserom_jp.gba", 0x27e9b9, 0xdd

gUnknown_827EA96: @ 0x0827EA96
	.incbin "baserom_jp.gba", 0x27ea96, 0x4b

gUnknown_827EAE1: @ 0x0827EAE1
	.incbin "baserom_jp.gba", 0x27eae1, 0x5e

gUnknown_827EB3F: @ 0x0827EB3F
	.incbin "baserom_jp.gba", 0x27eb3f, 0xb0

gUnknown_827EBEF: @ 0x0827EBEF
	.incbin "baserom_jp.gba", 0x27ebef, 0x5d

gUnknown_827EC4C: @ 0x0827EC4C
	.incbin "baserom_jp.gba", 0x27ec4c, 0x137

gUnknown_827ED83: @ 0x0827ED83
	.incbin "baserom_jp.gba", 0x27ed83, 0xd

gUnknown_827ED90: @ 0x0827ED90
	.incbin "baserom_jp.gba", 0x27ed90, 0xd4

gUnknown_827EE64: @ 0x0827EE64
	.incbin "baserom_jp.gba", 0x27ee64, 0x255

gUnknown_827F0B9: @ 0x0827F0B9
	.incbin "baserom_jp.gba", 0x27f0b9, 0x18c

gUnknown_827F245: @ 0x0827F245
	.incbin "baserom_jp.gba", 0x27f245, 0xfa

gUnknown_827F33F: @ 0x0827F33F
	.incbin "baserom_jp.gba", 0x27f33f, 0xff

gUnknown_827F43E: @ 0x0827F43E
	.incbin "baserom_jp.gba", 0x27f43e, 0xe8

gUnknown_827F526: @ 0x0827F526
	.incbin "baserom_jp.gba", 0x27f526, 0x118

gUnknown_827F63E: @ 0x0827F63E
	.incbin "baserom_jp.gba", 0x27f63e, 0x190

gUnknown_827F7CE: @ 0x0827F7CE
	.incbin "baserom_jp.gba", 0x27f7ce, 0x208

gUnknown_827F9D6: @ 0x0827F9D6
	.incbin "baserom_jp.gba", 0x27f9d6, 0x82

gUnknown_827FA58: @ 0x0827FA58
	.incbin "baserom_jp.gba", 0x27fa58, 0x2a

gUnknown_827FA82: @ 0x0827FA82
	.incbin "baserom_jp.gba", 0x27fa82, 0x6f

gUnknown_827FAF1: @ 0x0827FAF1
	.incbin "baserom_jp.gba", 0x27faf1, 0x42

gUnknown_827FB33: @ 0x0827FB33
	.incbin "baserom_jp.gba", 0x27fb33, 0x126

gUnknown_827FC59: @ 0x0827FC59
	.incbin "baserom_jp.gba", 0x27fc59, 0xfa

gUnknown_827FD53: @ 0x0827FD53
	.incbin "baserom_jp.gba", 0x27fd53, 0x54

gUnknown_827FDA7: @ 0x0827FDA7
	.incbin "baserom_jp.gba", 0x27fda7, 0x62

gUnknown_827FE09: @ 0x0827FE09
	.incbin "baserom_jp.gba", 0x27fe09, 0x4b

gUnknown_827FE54: @ 0x0827FE54
	.incbin "baserom_jp.gba", 0x27fe54, 0x57

gUnknown_827FEAB: @ 0x0827FEAB
	.incbin "baserom_jp.gba", 0x27feab, 0xed

gUnknown_827FF98: @ 0x0827FF98
	.incbin "baserom_jp.gba", 0x27ff98, 0x51

gUnknown_827FFE9: @ 0x0827FFE9
	.incbin "baserom_jp.gba", 0x27ffe9, 0x9d

gUnknown_8280086: @ 0x08280086
	.incbin "baserom_jp.gba", 0x280086, 0x27

gUnknown_82800AD: @ 0x082800AD
	.incbin "baserom_jp.gba", 0x2800ad, 0x11d

gUnknown_82801CA: @ 0x082801CA
	.incbin "baserom_jp.gba", 0x2801ca, 0x8d

gUnknown_8280257: @ 0x08280257
	.incbin "baserom_jp.gba", 0x280257, 0xfa

gUnknown_8280351: @ 0x08280351
	.incbin "baserom_jp.gba", 0x280351, 0x14

gUnknown_8280365: @ 0x08280365
	.incbin "baserom_jp.gba", 0x280365, 0x9d

gUnknown_8280402: @ 0x08280402
	.incbin "baserom_jp.gba", 0x280402, 0x88

gUnknown_828048A: @ 0x0828048A
	.incbin "baserom_jp.gba", 0x28048a, 0xe3

gUnknown_828056D: @ 0x0828056D
	.incbin "baserom_jp.gba", 0x28056d, 0x6a

gUnknown_82805D7: @ 0x082805D7
	.incbin "baserom_jp.gba", 0x2805d7, 0x63

gUnknown_828063A: @ 0x0828063A
	.incbin "baserom_jp.gba", 0x28063a, 0x52

gUnknown_828068C: @ 0x0828068C
	.incbin "baserom_jp.gba", 0x28068c, 0x69

gUnknown_82806F5: @ 0x082806F5
	.incbin "baserom_jp.gba", 0x2806f5, 0x5d

gUnknown_8280752: @ 0x08280752
	.incbin "baserom_jp.gba", 0x280752, 0x96

gUnknown_82807E8: @ 0x082807E8
	.incbin "baserom_jp.gba", 0x2807e8, 0x32

gUnknown_828081A: @ 0x0828081A
	.incbin "baserom_jp.gba", 0x28081a, 0xc7

gUnknown_82808E1: @ 0x082808E1
	.incbin "baserom_jp.gba", 0x2808e1, 0xc8

gUnknown_82809A9: @ 0x082809A9
	.incbin "baserom_jp.gba", 0x2809a9, 0xcf

gUnknown_8280A78: @ 0x08280A78
	.incbin "baserom_jp.gba", 0x280a78, 0x7b

gUnknown_8280AF3: @ 0x08280AF3
	.incbin "baserom_jp.gba", 0x280af3, 0xf8

gUnknown_8280BEB: @ 0x08280BEB
	.incbin "baserom_jp.gba", 0x280beb, 0xa3

gUnknown_8280C8E: @ 0x08280C8E
	.incbin "baserom_jp.gba", 0x280c8e, 0x56

gUnknown_8280CE4: @ 0x08280CE4
	.incbin "baserom_jp.gba", 0x280ce4, 0x5a

gUnknown_8280D3E: @ 0x08280D3E
	.incbin "baserom_jp.gba", 0x280d3e, 0x65

gUnknown_8280DA3: @ 0x08280DA3
	.incbin "baserom_jp.gba", 0x280da3, 0x138

gUnknown_8280EDB: @ 0x08280EDB
	.incbin "baserom_jp.gba", 0x280edb, 0x107

gUnknown_8280FE2: @ 0x08280FE2
	.incbin "baserom_jp.gba", 0x280fe2, 0x128

gUnknown_828110A: @ 0x0828110A
	.incbin "baserom_jp.gba", 0x28110a, 0x66

gUnknown_8281170: @ 0x08281170
	.incbin "baserom_jp.gba", 0x281170, 0x61

gUnknown_82811D1: @ 0x082811D1
	.incbin "baserom_jp.gba", 0x2811d1, 0x33

gUnknown_8281204: @ 0x08281204
	.incbin "baserom_jp.gba", 0x281204, 0x9b

FireSpreadEffect: @ 0x0828129F
	.incbin "baserom_jp.gba", 0x28129f, 0x78

gUnknown_8281317: @ 0x08281317
	.incbin "baserom_jp.gba", 0x281317, 0x57

gUnknown_828136E: @ 0x0828136E
	.incbin "baserom_jp.gba", 0x28136e, 0x203

gUnknown_8281571: @ 0x08281571
	.incbin "baserom_jp.gba", 0x281571, 0xde

gUnknown_828164F: @ 0x0828164F
	.incbin "baserom_jp.gba", 0x28164f, 0x3a

gUnknown_8281689: @ 0x08281689
	.incbin "baserom_jp.gba", 0x281689, 0x16

gUnknown_828169F: @ 0x0828169F
	.incbin "baserom_jp.gba", 0x28169f, 0x9a

gUnknown_8281739: @ 0x08281739
	.incbin "baserom_jp.gba", 0x281739, 0x60

gUnknown_8281799: @ 0x08281799
	.incbin "baserom_jp.gba", 0x281799, 0x86

gUnknown_828181F: @ 0x0828181F
	.incbin "baserom_jp.gba", 0x28181f, 0xe5

gUnknown_8281904: @ 0x08281904
	.incbin "baserom_jp.gba", 0x281904, 0xaf

gUnknown_82819B3: @ 0x082819B3
	.incbin "baserom_jp.gba", 0x2819b3, 0x5e

gUnknown_8281A11: @ 0x08281A11
	.incbin "baserom_jp.gba", 0x281a11, 0x66

gUnknown_8281A77: @ 0x08281A77
	.incbin "baserom_jp.gba", 0x281a77, 0x93

gUnknown_8281B0A: @ 0x08281B0A
	.incbin "baserom_jp.gba", 0x281b0a, 0x48

gUnknown_8281B52: @ 0x08281B52
	.incbin "baserom_jp.gba", 0x281b52, 0x9a

gUnknown_8281BEC: @ 0x08281BEC
	.incbin "baserom_jp.gba", 0x281bec, 0x43

gUnknown_8281C2F: @ 0x08281C2F
	.incbin "baserom_jp.gba", 0x281c2f, 0x27

gUnknown_8281C56: @ 0x08281C56
	.incbin "baserom_jp.gba", 0x281c56, 0x40

gUnknown_8281C96: @ 0x08281C96
	.incbin "baserom_jp.gba", 0x281c96, 0xff

gUnknown_8281D95: @ 0x08281D95
	.incbin "baserom_jp.gba", 0x281d95, 0xd2

gUnknown_8281E67: @ 0x08281E67
	.incbin "baserom_jp.gba", 0x281e67, 0xa1

gUnknown_8281F08: @ 0x08281F08
	.incbin "baserom_jp.gba", 0x281f08, 0xe6

gUnknown_8281FEE: @ 0x08281FEE
	.incbin "baserom_jp.gba", 0x281fee, 0x2e

gUnknown_828201C: @ 0x0828201C
	.incbin "baserom_jp.gba", 0x28201c, 0xaa

gUnknown_82820C6: @ 0x082820C6
	.incbin "baserom_jp.gba", 0x2820c6, 0x4b

gUnknown_8282111: @ 0x08282111
	.incbin "baserom_jp.gba", 0x282111, 0x68

gUnknown_8282179: @ 0x08282179
	.incbin "baserom_jp.gba", 0x282179, 0xc0

gUnknown_8282239: @ 0x08282239
	.incbin "baserom_jp.gba", 0x282239, 0x82

gUnknown_82822BB: @ 0x082822BB
	.incbin "baserom_jp.gba", 0x2822bb, 0x1fa

gUnknown_82824B5: @ 0x082824B5
	.incbin "baserom_jp.gba", 0x2824b5, 0x3b

gUnknown_82824F0: @ 0x082824F0
	.incbin "baserom_jp.gba", 0x2824f0, 0x63

gUnknown_8282553: @ 0x08282553
	.incbin "baserom_jp.gba", 0x282553, 0x69

gUnknown_82825BC: @ 0x082825BC
	.incbin "baserom_jp.gba", 0x2825bc, 0x47

gUnknown_8282603: @ 0x08282603
	.incbin "baserom_jp.gba", 0x282603, 0x64

gUnknown_8282667: @ 0x08282667
	.incbin "baserom_jp.gba", 0x282667, 0xb1

gUnknown_8282718: @ 0x08282718
	.incbin "baserom_jp.gba", 0x282718, 0x157

gUnknown_828286F: @ 0x0828286F
	.incbin "baserom_jp.gba", 0x28286f, 0x22

gUnknown_8282891: @ 0x08282891
	.incbin "baserom_jp.gba", 0x282891, 0x169

gUnknown_82829FA: @ 0x082829FA
	.incbin "baserom_jp.gba", 0x2829fa, 0xbb

gUnknown_8282AB5: @ 0x08282AB5
	.incbin "baserom_jp.gba", 0x282ab5, 0x67

gUnknown_8282B1C: @ 0x08282B1C
	.incbin "baserom_jp.gba", 0x282b1c, 0x174

gUnknown_8282C90: @ 0x08282C90
	.incbin "baserom_jp.gba", 0x282c90, 0xbe

gUnknown_8282D4E: @ 0x08282D4E
	.incbin "baserom_jp.gba", 0x282d4e, 0xa7

gUnknown_8282DF5: @ 0x08282DF5
	.incbin "baserom_jp.gba", 0x282df5, 0x7e

gUnknown_8282E73: @ 0x08282E73
	.incbin "baserom_jp.gba", 0x282e73, 0x48

gUnknown_8282EBB: @ 0x08282EBB
	.incbin "baserom_jp.gba", 0x282ebb, 0xb7

gUnknown_8282F72: @ 0x08282F72
	.incbin "baserom_jp.gba", 0x282f72, 0x143

gUnknown_82830B5: @ 0x082830B5
	.incbin "baserom_jp.gba", 0x2830b5, 0xac

gUnknown_8283161: @ 0x08283161
	.incbin "baserom_jp.gba", 0x283161, 0x18

gUnknown_8283179: @ 0x08283179
	.incbin "baserom_jp.gba", 0x283179, 0x94

gUnknown_828320D: @ 0x0828320D
	.incbin "baserom_jp.gba", 0x28320d, 0xea

gUnknown_82832F7: @ 0x082832F7
	.incbin "baserom_jp.gba", 0x2832f7, 0x142

gUnknown_8283439: @ 0x08283439
	.incbin "baserom_jp.gba", 0x283439, 0xfc

gUnknown_8283535: @ 0x08283535
	.incbin "baserom_jp.gba", 0x283535, 0x5d

gUnknown_8283592: @ 0x08283592
	.incbin "baserom_jp.gba", 0x283592, 0x43

gUnknown_82835D5: @ 0x082835D5
	.incbin "baserom_jp.gba", 0x2835d5, 0x88

gUnknown_828365D: @ 0x0828365D
	.incbin "baserom_jp.gba", 0x28365d, 0x94

gUnknown_82836F1: @ 0x082836F1
	.incbin "baserom_jp.gba", 0x2836f1, 0xd8

gUnknown_82837C9: @ 0x082837C9
	.incbin "baserom_jp.gba", 0x2837c9, 0x25

gUnknown_82837EE: @ 0x082837EE
	.incbin "baserom_jp.gba", 0x2837ee, 0x95

gUnknown_8283883: @ 0x08283883
	.incbin "baserom_jp.gba", 0x283883, 0x12

gUnknown_8283895: @ 0x08283895
	.incbin "baserom_jp.gba", 0x283895, 0x96

gUnknown_828392B: @ 0x0828392B
	.incbin "baserom_jp.gba", 0x28392b, 0x269

gUnknown_8283B94: @ 0x08283B94
	.incbin "baserom_jp.gba", 0x283b94, 0x9d

gUnknown_8283C31: @ 0x08283C31
	.incbin "baserom_jp.gba", 0x283c31, 0x87

gUnknown_8283CB8: @ 0x08283CB8
	.incbin "baserom_jp.gba", 0x283cb8, 0x97

gUnknown_8283D4F: @ 0x08283D4F
	.incbin "baserom_jp.gba", 0x283d4f, 0x3f

gUnknown_8283D8E: @ 0x08283D8E
	.incbin "baserom_jp.gba", 0x283d8e, 0xc

gUnknown_8283D9A: @ 0x08283D9A
	.incbin "baserom_jp.gba", 0x283d9a, 0x1a4

gUnknown_8283F3E: @ 0x08283F3E
	.incbin "baserom_jp.gba", 0x283f3e, 0x50

gUnknown_8283F8E: @ 0x08283F8E
	.incbin "baserom_jp.gba", 0x283f8e, 0xc7

gUnknown_8284055: @ 0x08284055
	.incbin "baserom_jp.gba", 0x284055, 0x48f

gUnknown_82844E4: @ 0x082844E4
	.incbin "baserom_jp.gba", 0x2844e4, 0x85

gUnknown_8284569: @ 0x08284569
	.incbin "baserom_jp.gba", 0x284569, 0x242

gUnknown_82847AB: @ 0x082847AB
	.incbin "baserom_jp.gba", 0x2847ab, 0xe7

gUnknown_8284892: @ 0x08284892
	.incbin "baserom_jp.gba", 0x284892, 0x218

gUnknown_8284AAA: @ 0x08284AAA
	.incbin "baserom_jp.gba", 0x284aaa, 0x1a

gUnknown_8284AC4: @ 0x08284AC4
	.incbin "baserom_jp.gba", 0x284ac4, 0xba

gUnknown_8284B7E: @ 0x08284B7E
	.incbin "baserom_jp.gba", 0x284b7e, 0x9d

gUnknown_8284C1B: @ 0x08284C1B
	.incbin "baserom_jp.gba", 0x284c1b, 0x2f2

gUnknown_8284F0D: @ 0x08284F0D
	.incbin "baserom_jp.gba", 0x284f0d, 0x132

gUnknown_828503F: @ 0x0828503F
	.incbin "baserom_jp.gba", 0x28503f, 0x48

gUnknown_8285087: @ 0x08285087
	.incbin "baserom_jp.gba", 0x285087, 0x15d

gUnknown_82851E4: @ 0x082851E4
	.incbin "baserom_jp.gba", 0x2851e4, 0x1d

gUnknown_8285201: @ 0x08285201
	.incbin "baserom_jp.gba", 0x285201, 0xf5

gUnknown_82852F6: @ 0x082852F6
	.incbin "baserom_jp.gba", 0x2852f6, 0x74

gUnknown_828536A: @ 0x0828536A
	.incbin "baserom_jp.gba", 0x28536a, 0x90

gUnknown_82853FA: @ 0x082853FA
	.incbin "baserom_jp.gba", 0x2853fa, 0x64

gUnknown_828545E: @ 0x0828545E
	.incbin "baserom_jp.gba", 0x28545e, 0xf9

gUnknown_8285557: @ 0x08285557
	.incbin "baserom_jp.gba", 0x285557, 0x54

gUnknown_82855AB: @ 0x082855AB
	.incbin "baserom_jp.gba", 0x2855ab, 0x15f

gUnknown_828570A: @ 0x0828570A
	.incbin "baserom_jp.gba", 0x28570a, 0x121

gUnknown_828582B: @ 0x0828582B
	.incbin "baserom_jp.gba", 0x28582b, 0x1cf

gUnknown_82859FA: @ 0x082859FA
	.incbin "baserom_jp.gba", 0x2859fa, 0x27c

gUnknown_8285C76: @ 0x08285C76
	.incbin "baserom_jp.gba", 0x285c76, 0x66b

gUnknown_82862E1: @ 0x082862E1
	.incbin "baserom_jp.gba", 0x2862e1, 0x2b

gUnknown_828630C: @ 0x0828630C
	.incbin "baserom_jp.gba", 0x28630c, 0x9

gUnknown_8286315: @ 0x08286315
	.incbin "baserom_jp.gba", 0x286315, 0x30

gUnknown_8286345: @ 0x08286345
	.incbin "baserom_jp.gba", 0x286345, 0x35

gUnknown_828637A: @ 0x0828637A
	.incbin "baserom_jp.gba", 0x28637a, 0x2c

gUnknown_82863A6: @ 0x082863A6
	.incbin "baserom_jp.gba", 0x2863a6, 0x1a

gUnknown_82863C0: @ 0x082863C0
	.incbin "baserom_jp.gba", 0x2863c0, 0x1b

gUnknown_82863DB: @ 0x082863DB
	.incbin "baserom_jp.gba", 0x2863db, 0x25

gUnknown_8286400: @ 0x08286400
	.incbin "baserom_jp.gba", 0x286400, 0x25

gUnknown_8286425: @ 0x08286425
	.incbin "baserom_jp.gba", 0x286425, 0x36

gUnknown_828645B: @ 0x0828645B
	.incbin "baserom_jp.gba", 0x28645b, 0x9

gUnknown_8286464: @ 0x08286464
	.incbin "baserom_jp.gba", 0x286464, 0x3d

gUnknown_82864A1: @ 0x082864A1
	.incbin "baserom_jp.gba", 0x2864a1, 0x8

gUnknown_82864A9: @ 0x082864A9
	.incbin "baserom_jp.gba", 0x2864a9, 0x48

gUnknown_82864F1: @ 0x082864F1
	.incbin "baserom_jp.gba", 0x2864f1, 0xb

gUnknown_82864FC: @ 0x082864FC
	.incbin "baserom_jp.gba", 0x2864fc, 0x193

gUnknown_828668F: @ 0x0828668F
	.incbin "baserom_jp.gba", 0x28668f, 0x74

gUnknown_8286703: @ 0x08286703
	.incbin "baserom_jp.gba", 0x286703, 0xdc

gUnknown_82867DF: @ 0x082867DF
	.incbin "baserom_jp.gba", 0x2867df, 0x4d

gUnknown_828682C: @ 0x0828682C
	.incbin "baserom_jp.gba", 0x28682c, 0x49

gUnknown_8286875: @ 0x08286875
	.incbin "baserom_jp.gba", 0x286875, 0x5

gUnknown_828687A: @ 0x0828687A
	.incbin "baserom_jp.gba", 0x28687a, 0x5

gUnknown_828687F: @ 0x0828687F
	.incbin "baserom_jp.gba", 0x28687f, 0x5

gUnknown_8286884: @ 0x08286884
	.incbin "baserom_jp.gba", 0x286884, 0xe

gUnknown_8286892: @ 0x08286892
	.incbin "baserom_jp.gba", 0x286892, 0x31

gUnknown_82868C3: @ 0x082868C3
	.incbin "baserom_jp.gba", 0x2868c3, 0x25

gUnknown_82868E8: @ 0x082868E8
	.incbin "baserom_jp.gba", 0x2868e8, 0x5e

gUnknown_8286946: @ 0x08286946
	.incbin "baserom_jp.gba", 0x286946, 0x5f

gUnknown_82869A5: @ 0x082869A5
	.incbin "baserom_jp.gba", 0x2869a5, 0xc5

gUnknown_8286A6A: @ 0x08286A6A
	.incbin "baserom_jp.gba", 0x286a6a, 0x40

gUnknown_8286AAA: @ 0x08286AAA
	.incbin "baserom_jp.gba", 0x286aaa, 0x43

gUnknown_8286AED: @ 0x08286AED
	.incbin "baserom_jp.gba", 0x286aed, 0x143
