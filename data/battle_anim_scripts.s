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
	.4byte Move_COMET_PUNCH                  @ MOVE_COMET_PUNCH
	.4byte Move_MEGA_PUNCH                   @ MOVE_MEGA_PUNCH
	.4byte Move_PAY_DAY                      @ MOVE_PAY_DAY
	.4byte gUnknown_8281204                  @ 007
	.4byte gUnknown_827DC85                  @ 008
	.4byte gUnknown_827E01B                  @ 009
	.4byte gUnknown_827E2CB                  @ 010
	.4byte Move_VICE_GRIP                    @ MOVE_VICE_GRIP
	.4byte Move_GUILLOTINE                   @ MOVE_GUILLOTINE
	.4byte gUnknown_8281F08                  @ 013
	.4byte Move_SWORDS_DANCE                  @ MOVE_SWORDS_DANCE
	.4byte Move_CUT                           @ MOVE_CUT
	.4byte gUnknown_827FF98                  @ 016
	.4byte gUnknown_827FFE9                  @ 017
	.4byte Move_WHIRLWIND                    @ MOVE_WHIRLWIND
	.4byte gUnknown_828056D                  @ 019
	.4byte gUnknown_828164F                  @ 020
	.4byte Move_SLAM                         @ MOVE_SLAM
	.4byte Move_VINE_WHIP                    @ MOVE_VINE_WHIP
	.4byte Move_STOMP                        @ MOVE_STOMP
	.4byte gUnknown_82807E8                  @ 024
	.4byte Move_MEGA_KICK                    @ MOVE_MEGA_KICK
	.4byte gUnknown_82806F5                  @ 026
	.4byte Move_ROLLING_KICK                 @ MOVE_ROLLING_KICK
	.4byte gUnknown_827E873                  @ 028
	.4byte Move_HEADBUTT                     @ MOVE_HEADBUTT
	.4byte Move_HORN_ATTACK                  @ MOVE_HORN_ATTACK
	.4byte Move_FURY_ATTACK                  @ MOVE_FURY_ATTACK
	.4byte Move_HORN_DRILL                   @ MOVE_HORN_DRILL
	.4byte Move_TACKLE                         @ MOVE_TACKLE
	.4byte Move_BODY_SLAM                      @ MOVE_BODY_SLAM
	.4byte gUnknown_8281689                  @ 035
	.4byte Move_TAKE_DOWN                    @ MOVE_TAKE_DOWN
	.4byte Move_THRASH                       @ MOVE_THRASH
	.4byte Move_DOUBLE_EDGE                  @ MOVE_DOUBLE_EDGE
	.4byte Move_TAIL_WHIP                     @ MOVE_TAIL_WHIP
	.4byte Move_POISON_STING                 @ MOVE_POISON_STING
	.4byte Move_TWINEEDLE                    @ MOVE_TWINEEDLE
	.4byte Move_PIN_MISSILE                  @ MOVE_PIN_MISSILE
	.4byte gUnknown_8281317                  @ 043
	.4byte gUnknown_827EAE1                  @ 044
	.4byte gUnknown_827E4A8                  @ 045
	.4byte gUnknown_827E411                  @ 046
	.4byte Move_SING                         @ MOVE_SING
	.4byte Move_SUPERSONIC                     @ MOVE_SUPERSONIC
	.4byte Move_SONIC_BOOM                   @ MOVE_SONIC_BOOM
	.4byte gUnknown_8281FEE                  @ 050
	.4byte gUnknown_827FC59                  @ 051
	.4byte Move_EMBER                        @ MOVE_EMBER
	.4byte gUnknown_8280365                  @ 053
	.4byte gUnknown_8281170                  @ 054
	.4byte gUnknown_82801CA                  @ 055
	.4byte gUnknown_827F33F                  @ 056
	.4byte gUnknown_8280351                  @ 057
	.4byte gUnknown_827EC4C                  @ 058
	.4byte gUnknown_827F0B9                  @ 059
	.4byte gUnknown_828169F                  @ 060
	.4byte Move_BUBBLE_BEAM                  @ MOVE_BUBBLE_BEAM
	.4byte gUnknown_827ED90                  @ 062
	.4byte gUnknown_82832F7                  @ 063
	.4byte gUnknown_8280086                  @ 064
	.4byte Move_DRILL_PECK                   @ MOVE_DRILL_PECK
	.4byte gUnknown_8280BEB                  @ 066
	.4byte Move_LOW_KICK                     @ MOVE_LOW_KICK
	.4byte gUnknown_82809A9                  @ 068
	.4byte gUnknown_8285087                  @ 069
	.4byte Move_STRENGTH                       @ MOVE_STRENGTH
	.4byte gUnknown_827F526                  @ 071
	.4byte gUnknown_827F63E                  @ 072
	.4byte Move_LEECH_SEED                   @ MOVE_LEECH_SEED
	.4byte Move_GROWTH                       @ MOVE_GROWTH
	.4byte gUnknown_8280EDB                  @ 075
	.4byte gUnknown_827EE64                  @ 076
	.4byte Move_POISON_POWDER                  @ MOVE_POISON_POWDER
	.4byte Move_STUN_SPORE                     @ MOVE_STUN_SPORE
	.4byte Move_SLEEP_POWDER                   @ MOVE_SLEEP_POWDER
	.4byte gUnknown_8280DA3                  @ 080
	.4byte gUnknown_8281D95                  @ 081
	.4byte gUnknown_827E9B9                  @ 082
	.4byte Move_FIRE_SPIN                    @ MOVE_FIRE_SPIN
	.4byte Move_THUNDER_SHOCK                @ MOVE_THUNDER_SHOCK
	.4byte Move_THUNDERBOLT                  @ MOVE_THUNDERBOLT
	.4byte Move_THUNDER_WAVE                 @ MOVE_THUNDER_WAVE
	.4byte gUnknown_827DEC1                  @ 087
	.4byte Move_ROCK_THROW                   @ MOVE_ROCK_THROW
	.4byte Move_EARTHQUAKE                   @ MOVE_EARTHQUAKE
	.4byte Move_FISSURE                      @ MOVE_FISSURE
	.4byte Move_DIG                          @ MOVE_DIG
	.4byte gUnknown_827FA82                  @ 092
	.4byte gUnknown_827DDB0                  @ 093
	.4byte gUnknown_827DE11                  @ 094
	.4byte gUnknown_8281739                  @ 095
	.4byte Move_MEDITATE                     @ MOVE_MEDITATE
	.4byte Move_AGILITY                      @ MOVE_AGILITY
	.4byte Move_QUICK_ATTACK                 @ MOVE_QUICK_ATTACK
	.4byte Move_RAGE                         @ MOVE_RAGE
	.4byte Move_TELEPORT                     @ MOVE_TELEPORT
	.4byte gUnknown_8281B0A                  @ 101
	.4byte gUnknown_82820C6                  @ 102
	.4byte Move_SCREECH                        @ MOVE_SCREECH
	.4byte Move_DOUBLE_TEAM                  @ MOVE_DOUBLE_TEAM
	.4byte gUnknown_828201C                  @ 105
	.4byte gUnknown_827DA50                  @ 106
	.4byte Move_MINIMIZE                     @ MOVE_MINIMIZE
	.4byte Move_SMOKESCREEN                  @ MOVE_SMOKESCREEN
	.4byte Move_CONFUSE_RAY                  @ MOVE_CONFUSE_RAY
	.4byte gUnknown_827ED83                  @ 110
	.4byte Move_DEFENSE_CURL                  @ MOVE_DEFENSE_CURL
	.4byte gUnknown_827E67E                  @ 112
	.4byte gUnknown_827E579                  @ 113
	.4byte gUnknown_82811D1                  @ 114
	.4byte gUnknown_827E62B                  @ 115
	.4byte gUnknown_8281C56                  @ 116
	.4byte gUnknown_8281C96                  @ 117
	.4byte Move_METRONOME                    @ MOVE_METRONOME
	.4byte Move_MIRROR_MOVE                      @ MOVE_MIRROR_MOVE
	.4byte Move_SELF_DESTRUCT                 @ MOVE_SELF_DESTRUCT
	.4byte gUnknown_8281B52                  @ 121
	.4byte gUnknown_8281C2F                  @ 122
	.4byte gUnknown_827E771                  @ 123
	.4byte gUnknown_827FAF1                  @ 124
	.4byte gUnknown_827FDA7                  @ 125
	.4byte Move_FIRE_BLAST                   @ MOVE_FIRE_BLAST
	.4byte Move_WATERFALL                    @ MOVE_WATERFALL
	.4byte gUnknown_827EBEF                  @ 128
	.4byte Move_SWIFT                          @ MOVE_SWIFT
	.4byte Move_SKULL_BASH                   @ MOVE_SKULL_BASH
	.4byte Move_SPIKE_CANNON                  @ MOVE_SPIKE_CANNON
	.4byte gUnknown_8282111                  @ 132
	.4byte Move_AMNESIA                      @ MOVE_AMNESIA
	.4byte Move_KINESIS                      @ MOVE_KINESIS
	.4byte gUnknown_8282239                  @ 135
	.4byte gUnknown_8280752                  @ 136
	.4byte Move_GLARE                        @ MOVE_GLARE
	.4byte gUnknown_828136E                  @ 138
	.4byte gUnknown_8281571                  @ 139
	.4byte Move_BARRAGE                      @ MOVE_BARRAGE
	.4byte gUnknown_827F9D6                  @ 141
	.4byte gUnknown_82825BC                  @ 142
	.4byte Move_SKY_ATTACK                   @ MOVE_SKY_ATTACK
	.4byte gUnknown_8283161                  @ 144
	.4byte gUnknown_827E69B                  @ 145
	.4byte Move_DIZZY_PUNCH                  @ MOVE_DIZZY_PUNCH
	.4byte gUnknown_8280D3E                  @ 147
	.4byte Move_FLASH                        @ MOVE_FLASH
	.4byte gUnknown_8281799                  @ 149
	.4byte Move_SPLASH                       @ MOVE_SPLASH
	.4byte Move_ACID_ARMOR                   @ MOVE_ACID_ARMOR
	.4byte gUnknown_8280257                  @ 152
	.4byte Move_EXPLOSION                     @ MOVE_EXPLOSION
	.4byte gUnknown_8282603                  @ 154
	.4byte gUnknown_827FD53                  @ 155
	.4byte gUnknown_827DD70                  @ 156
	.4byte Move_ROCK_SLIDE                   @ MOVE_ROCK_SLIDE
	.4byte gUnknown_8282AB5                  @ 158
	.4byte Move_SHARPEN                      @ MOVE_SHARPEN
	.4byte Move_CONVERSION                   @ MOVE_CONVERSION
	.4byte gUnknown_8282B1C                  @ 161
	.4byte Move_SUPER_FANG                   @ MOVE_SUPER_FANG
	.4byte Move_SLASH                        @ MOVE_SLASH
	.4byte gUnknown_8283D8E                  @ 164
	.4byte Move_STRUGGLE                     @ MOVE_STRUGGLE
	.4byte Move_SKETCH                       @ MOVE_SKETCH
	.4byte gUnknown_828081A                  @ 167
	.4byte Move_THIEF                        @ MOVE_THIEF
	.4byte gUnknown_8281E67                  @ 169
	.4byte gUnknown_827DB4D                  @ 170
	.4byte Move_NIGHTMARE                    @ MOVE_NIGHTMARE
	.4byte Move_FLAME_WHEEL                   @ MOVE_FLAME_WHEEL
	.4byte gUnknown_827E4E9                  @ 173
	.4byte gUnknown_8282179                  @ 174
	.4byte Move_FLAIL                        @ MOVE_FLAIL
	.4byte Move_CONVERSION_2                 @ MOVE_CONVERSION_2
	.4byte gUnknown_82800AD                  @ 177
	.4byte gUnknown_8280CE4                  @ 178
	.4byte Move_REVERSAL                      @ MOVE_REVERSAL
	.4byte Move_SPITE                        @ MOVE_SPITE
	.4byte gUnknown_827F245                  @ 181
	.4byte Move_PROTECT                       @ MOVE_PROTECT
	.4byte Move_MACH_PUNCH                   @ MOVE_MACH_PUNCH
	.4byte gUnknown_82824F0                  @ 184
	.4byte gUnknown_827E7EC                  @ 185
	.4byte gUnknown_8282553                  @ 186
	.4byte gUnknown_827DA65                  @ 187
	.4byte gUnknown_827FB33                  @ 188
	.4byte gUnknown_827E91B                  @ 189
	.4byte gUnknown_828110A                  @ 190
	.4byte gUnknown_827FE54                  @ 191
	.4byte gUnknown_828181F                  @ 192
	.4byte Move_FORESIGHT                    @ MOVE_FORESIGHT
	.4byte Move_DESTINY_BOND                 @ MOVE_DESTINY_BOND
	.4byte gUnknown_8282891                  @ 195
	.4byte Move_ICY_WIND                     @ MOVE_ICY_WIND
	.4byte Move_DETECT                        @ MOVE_DETECT
	.4byte gUnknown_827FE09                  @ 198
	.4byte Move_LOCK_ON                      @ MOVE_LOCK_ON
	.4byte Move_OUTRAGE                      @ MOVE_OUTRAGE
	.4byte gUnknown_8280402                  @ 201
	.4byte gUnknown_827F7CE                  @ 202
	.4byte Move_ENDURE                        @ MOVE_ENDURE
	.4byte Move_CHARM                         @ MOVE_CHARM
	.4byte Move_ROLLOUT                       @ MOVE_ROLLOUT
	.4byte Move_FALSE_SWIPE                   @ MOVE_FALSE_SWIPE
	.4byte Move_SWAGGER                       @ MOVE_SWAGGER
	.4byte Move_MILK_DRINK                   @ MOVE_MILK_DRINK
	.4byte Move_SPARK                        @ MOVE_SPARK
	.4byte Move_FURY_CUTTER                   @ MOVE_FURY_CUTTER
	.4byte gUnknown_8281904                  @ 211
	.4byte Move_MEAN_LOOK                    @ MOVE_MEAN_LOOK
	.4byte Move_ATTRACT                      @ MOVE_ATTRACT
	.4byte gUnknown_82829FA                  @ 214
	.4byte gUnknown_82822BB                  @ 215
	.4byte gUnknown_8284055                  @ 216
	.4byte gUnknown_8282718                  @ 217
	.4byte Move_FRUSTRATION                   @ MOVE_FRUSTRATION
	.4byte Move_SAFEGUARD                     @ MOVE_SAFEGUARD
	.4byte Move_PAIN_SPLIT                   @ MOVE_PAIN_SPLIT
	.4byte gUnknown_827E0E4                  @ 221
	.4byte Move_MAGNITUDE                    @ MOVE_MAGNITUDE
	.4byte gUnknown_82808E1                  @ 223
	.4byte gUnknown_827FEAB                  @ 224
	.4byte gUnknown_827E2FD                  @ 225
	.4byte gUnknown_828286F                  @ 226
	.4byte gUnknown_8282D4E                  @ 227
	.4byte Move_PURSUIT                       @ MOVE_PURSUIT
	.4byte Move_RAPID_SPIN                   @ MOVE_RAPID_SPIN
	.4byte gUnknown_828320D                  @ 230
	.4byte gUnknown_82819B3                  @ 231
	.4byte gUnknown_8281A77                  @ 232
	.4byte gUnknown_8280A78                  @ 233
	.4byte gUnknown_8283179                  @ 234
	.4byte gUnknown_827FA58                  @ 235
	.4byte Move_MOONLIGHT                    @ MOVE_MOONLIGHT
	.4byte Move_HIDDEN_POWER                  @ MOVE_HIDDEN_POWER
	.4byte gUnknown_828068C                  @ 238
	.4byte gUnknown_82855AB                  @ 239
	.4byte gUnknown_827EA96                  @ 240
	.4byte gUnknown_8280C8E                  @ 241
	.4byte gUnknown_827EB3F                  @ 242
	.4byte gUnknown_827E605                  @ 243
	.4byte Move_PSYCH_UP                     @ MOVE_PSYCH_UP
	.4byte Move_EXTREME_SPEED                @ MOVE_EXTREME_SPEED
	.4byte gUnknown_8280FE2                  @ 246
	.4byte gUnknown_8281BEC                  @ 247
	.4byte gUnknown_827DE74                  @ 248
	.4byte gUnknown_8280AF3                  @ 249
	.4byte gUnknown_828048A                  @ 250
	.4byte Move_BEAT_UP                      @ MOVE_BEAT_UP
	.4byte gUnknown_82824B5                  @ 252
	.4byte Move_UPROAR                       @ MOVE_UPROAR
	.4byte gUnknown_8282EBB                  @ 254
	.4byte gUnknown_8282F72                  @ 255
	.4byte gUnknown_82830B5                  @ 256
	.4byte Move_HEAT_WAVE                    @ MOVE_HEAT_WAVE
	.4byte Move_HAIL                         @ MOVE_HAIL
	.4byte Move_TORMENT                      @ MOVE_TORMENT
	.4byte gUnknown_8283439                  @ 260
	.4byte gUnknown_8282C90                  @ 261
	.4byte Move_MEMENTO                      @ MOVE_MEMENTO
	.4byte Move_FACADE                       @ MOVE_FACADE
	.4byte gUnknown_8283F8E                  @ 264
	.4byte Move_SMELLING_SALT                @ MOVE_SMELLING_SALT
	.4byte Move_FOLLOW_ME                    @ MOVE_FOLLOW_ME
	.4byte gUnknown_8280FE2                  @ 267
	.4byte Move_CHARGE                       @ MOVE_CHARGE
	.4byte Move_TAUNT                        @ MOVE_TAUNT
	.4byte Move_HELPING_HAND                 @ MOVE_HELPING_HAND
	.4byte gUnknown_8282DF5                  @ 271
	.4byte gUnknown_8283535                  @ 272
	.4byte gUnknown_8282E73                  @ 273
	.4byte Move_ASSIST                       @ MOVE_ASSIST
	.4byte gUnknown_8282667                  @ 275
	.4byte Move_SUPERPOWER                   @ MOVE_SUPERPOWER
	.4byte gUnknown_82851E4                  @ 277
	.4byte Move_RECYCLE                      @ MOVE_RECYCLE
	.4byte gUnknown_8283CB8                  @ 279
	.4byte Move_BRICK_BREAK                  @ MOVE_BRICK_BREAK
	.4byte Move_YAWN                         @ MOVE_YAWN
	.4byte gUnknown_828536A                  @ 282
	.4byte Move_ENDEAVOR                     @ MOVE_ENDEAVOR
	.4byte Move_ERUPTION                     @ MOVE_ERUPTION
	.4byte Move_SKILL_SWAP                   @ MOVE_SKILL_SWAP
	.4byte Move_IMPRISON                     @ MOVE_IMPRISON
	.4byte gUnknown_8283592                  @ 287
	.4byte Move_GRUDGE                       @ MOVE_GRUDGE
	.4byte gUnknown_8284AAA                  @ 289
	.4byte gUnknown_8285557                  @ 290
	.4byte gUnknown_8284AC4                  @ 291
	.4byte gUnknown_82837EE                  @ 292
	.4byte Move_CAMOUFLAGE                   @ MOVE_CAMOUFLAGE
	.4byte Move_TAIL_GLOW                    @ MOVE_TAIL_GLOW
	.4byte Move_LUSTER_PURGE                 @ MOVE_LUSTER_PURGE
	.4byte Move_MIST_BALL                    @ MOVE_MIST_BALL
	.4byte Move_FEATHER_DANCE                @ MOVE_FEATHER_DANCE
	.4byte Move_TEETER_DANCE                 @ MOVE_TEETER_DANCE
	.4byte gUnknown_82835D5                  @ 299
	.4byte Move_MUD_SPORT                    @ MOVE_MUD_SPORT
	.4byte gUnknown_828582B                  @ 301
	.4byte Move_NEEDLE_ARM                   @ MOVE_NEEDLE_ARM
	.4byte Move_SLACK_OFF                    @ MOVE_SLACK_OFF
	.4byte gUnknown_828365D                  @ 304
	.4byte gUnknown_8283D4F                  @ 305
	.4byte Move_CRUSH_CLAW                   @ MOVE_CRUSH_CLAW
	.4byte gUnknown_8284569                  @ 307
	.4byte gUnknown_8284F0D                  @ 308
	.4byte gUnknown_8283C31                  @ 309
	.4byte gUnknown_828503F                  @ 310
	.4byte gUnknown_82859FA                  @ 311
	.4byte Move_AROMATHERAPY                 @ MOVE_AROMATHERAPY
	.4byte Move_FAKE_TEARS                   @ MOVE_FAKE_TEARS
	.4byte Move_AIR_CUTTER                   @ MOVE_AIR_CUTTER
	.4byte gUnknown_8284C1B                  @ 315
	.4byte Move_ODOR_SLEUTH                  @ MOVE_ODOR_SLEUTH
	.4byte gUnknown_82847AB                  @ 317
	.4byte gUnknown_8284892                  @ 318
	.4byte gUnknown_8283F3E                  @ 319
	.4byte Move_GRASS_WHISTLE                @ MOVE_GRASS_WHISTLE
	.4byte Move_TICKLE                       @ MOVE_TICKLE
	.4byte gUnknown_82844E4                  @ 322
	.4byte Move_WATER_SPOUT                  @ MOVE_WATER_SPOUT
	.4byte gUnknown_827F43E                  @ 324
	.4byte Move_SHADOW_PUNCH                 @ MOVE_SHADOW_PUNCH
	.4byte Move_EXTRASENSORY                 @ MOVE_EXTRASENSORY
	.4byte gUnknown_828545E                  @ 327
	.4byte gUnknown_82836F1                  @ 328
	.4byte gUnknown_82837C9                  @ 329
	.4byte gUnknown_8283883                  @ 330
	.4byte gUnknown_8283895                  @ 331
	.4byte Move_AERIAL_ACE                   @ MOVE_AERIAL_ACE
	.4byte Move_ICICLE_SPEAR                 @ MOVE_ICICLE_SPEAR
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

Move_PIN_MISSILE: @ 0x082780EC
	loadspritegfx ANIM_TAG_NEEDLE
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	splitbgprio ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_M_JUMP_KICK, SOUND_PAN_ATTACKER
	create_pin_missile_sprite ANIM_ATTACKER, 2, 20, -8, -8, -8, 20, -32
	delay 15
	create_pin_missile_sprite ANIM_ATTACKER, 2, 20, -8, 8, 8, 20, -40
	delay 4
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, -8, -8, ANIM_TARGET, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	delay 9
	create_pin_missile_sprite ANIM_ATTACKER, 2, 20, -8, 0, 0, 20, -32
	delay 4
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, 8, 8, ANIM_TARGET, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	delay 14
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, 0, 0, ANIM_TARGET, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_ICICLE_SPEAR: @ 0x082781B1
	loadspritegfx ANIM_TAG_ICICLE_SPEAR
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	splitbgprio ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_M_ICY_WIND, SOUND_PAN_ATTACKER
	createsprite gIcicleSpearSpriteTemplate, ANIM_ATTACKER, 2, 20, -8, -8, -8, 20, -32
	delay 15
	createsprite gIcicleSpearSpriteTemplate, ANIM_ATTACKER, 2, 20, -8, 8, 8, 20, -40
	delay 4
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, -8, -8, ANIM_TARGET, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	delay 9
	createsprite gIcicleSpearSpriteTemplate, ANIM_ATTACKER, 2, 20, -8, 0, 0, 20, -32
	delay 4
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, 8, 8, ANIM_TARGET, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	delay 14
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, 0, 0, ANIM_TARGET, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_TAKE_DOWN: @ 0x08278276
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_WindUpLunge, 5, ANIM_ATTACKER, -24, 8, 23, 10, 40, 10
	delay 35
	complex_palette_blend selector=F_PAL_BG | F_PAL_BATTLERS, delay=3, num_blends=1, color1=RGB_BLACK, blend_y1=10, color2=RGB_BLACK, blend_y2=0
	create_basic_hitsplat_sprite ANIM_ATTACKER, 4, -10, 0, ANIM_TARGET, 0
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	delay 1
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -16, 0, 0, 4
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 12, 1
	waitforvisualfinish
	delay 2
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 5
	delay 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 7
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_DOUBLE_EDGE: @ 0x08278306
	loadspritegfx ANIM_TAG_IMPACT
	playsewithpan SE_M_SWIFT, SOUND_PAN_ATTACKER
	complex_palette_blend selector=F_PAL_ATTACKER, delay=4, num_blends=2, color1=RGB_WHITE, blend_y1=10, color2=RGB_BLACK, blend_y2=0
	waitforvisualfinish
	delay 10
	playsewithpan SE_M_SWAGGER, SOUND_PAN_ATTACKER
	waitplaysewithpan SE_M_SWAGGER, SOUND_PAN_ATTACKER, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 18, 6, 2, 4
	waitforvisualfinish
	simple_palette_blend selector=F_PAL_BG, delay=0, initial_blend_y=16, target_blend_y=16, color=RGB_WHITE
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, 0, 0, 4
	delay 3
	waitforvisualfinish
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_TARGET, 4, -10, 0, ANIM_TARGET, 0
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -32, 0, 0, 3
	waitforvisualfinish
	createvisualtask AnimTask_RotateMonSpriteToSide, 2, 8, -256, ANIM_ATTACKER, 0
	createvisualtask AnimTask_RotateMonSpriteToSide, 2, 8, -256, ANIM_TARGET, 0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 4, 0, 12, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 12, 1
	simple_palette_blend selector=F_PAL_BG, delay=2, initial_blend_y=16, target_blend_y=0, color=RGB_WHITE
	waitforvisualfinish
	createvisualtask AnimTask_RotateMonSpriteToSide, 2, 8, -256, ANIM_ATTACKER, 1
	createvisualtask AnimTask_RotateMonSpriteToSide, 2, 8, -256, ANIM_TARGET, 1
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 5
	delay 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 7
	waitforvisualfinish
	end

Move_POISON_STING: @ 0x08278419
	loadspritegfx ANIM_TAG_NEEDLE
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_POISON_BUBBLE
	monbg ANIM_TARGET
	splitbgprio ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_M_RAZOR_WIND2, SOUND_PAN_ATTACKER
	create_linear_stinger_sprite ANIM_TARGET, 2, 20, 0, -8, 0, 20
	waitforvisualfinish
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, 0, 0, ANIM_TARGET, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 5, 1
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	waitforvisualfinish
	call PoisonBubblesEffect
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_TWINEEDLE: @ 0x0827846E
	loadspritegfx ANIM_TAG_NEEDLE
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	splitbgprio ANIM_TARGET
	setalpha 12, 8
	loopsewithpan SE_M_RAZOR_WIND2, SOUND_PAN_ATTACKER, 6, 2
	create_linear_stinger_sprite ANIM_TARGET, 2, 10, -4, 0, -4, 20
	create_linear_stinger_sprite ANIM_TARGET, 2, 20, 12, 10, 12, 20
	delay 20
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 5, 1
	create_handle_invert_hitsplat_sprite ANIM_ATTACKER, 3, 0, -4, ANIM_TARGET, 3
	loopsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET, 5, 2
	delay 1
	create_handle_invert_hitsplat_sprite ANIM_ATTACKER, 3, 10, 12, ANIM_TARGET, 3
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_FIRE_BLAST: @ 0x082784E1
	loadspritegfx ANIM_TAG_SMALL_EMBER
	createsoundtask SoundTask_FireBlast, SE_M_FLAME_WHEEL, SE_M_FLAME_WHEEL2
	call FireBlastRing
	call FireBlastRing
	call FireBlastRing
	delay 24
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 3, 0, 8, RGB_BLACK
	waitforvisualfinish
	delay 19
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 20, 1
	call FireBlastCross
	delay 3
	call FireBlastCross
	delay 3
	call FireBlastCross
	delay 3
	call FireBlastCross
	delay 3
	call FireBlastCross
	delay 3
	call FireBlastCross
	delay 3
	call FireBlastCross
	delay 3
	call FireBlastCross
	delay 3
	call FireBlastCross
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 2, 8, 0, RGB_BLACK
	waitforvisualfinish
	end

FireBlastRing:
	createsprite gFireBlastRingSpriteTemplate, ANIM_TARGET, 2, 0, 0, 0
	createsprite gFireBlastRingSpriteTemplate, ANIM_TARGET, 2, 0, 0, 51
	createsprite gFireBlastRingSpriteTemplate, ANIM_TARGET, 2, 0, 0, 102
	createsprite gFireBlastRingSpriteTemplate, ANIM_TARGET, 2, 0, 0, 153
	createsprite gFireBlastRingSpriteTemplate, ANIM_TARGET, 2, 0, 0, 204
	delay 5
	return

FireBlastCross:
	createsprite gFireBlastCrossSpriteTemplate, ANIM_TARGET, 2, 0, 0, 10, 0, -2
	createsprite gFireBlastCrossSpriteTemplate, ANIM_TARGET, 2, 0, 0, 13, -2, 0
	createsprite gFireBlastCrossSpriteTemplate, ANIM_TARGET, 2, 0, 0, 13, 2, 0
	createsprite gFireBlastCrossSpriteTemplate, ANIM_TARGET, 2, 0, 0, 15, -2, 2
	createsprite gFireBlastCrossSpriteTemplate, ANIM_TARGET, 2, 0, 0, 15, 2, 2
	return

Move_LEECH_SEED: @ 0x0827860F
	loadspritegfx ANIM_TAG_SEED
	playsewithpan SE_M_POISON_POWDER, SOUND_PAN_ATTACKER
	createleechseedsprite ANIM_TARGET, 2, 15, 0, 0, 24, 35, -32
	delay 8
	playsewithpan SE_M_POISON_POWDER, SOUND_PAN_ATTACKER
	createleechseedsprite ANIM_TARGET, 2, 15, 0, -16, 24, 35, -40
	delay 8
	playsewithpan SE_M_POISON_POWDER, SOUND_PAN_ATTACKER
	createleechseedsprite ANIM_TARGET, 2, 15, 0, 16, 24, 35, -37
	delay 12
	loopsewithpan SE_M_TAIL_WHIP, SOUND_PAN_TARGET, 10, 8
	waitforvisualfinish
	end

Move_EMBER: @ 0x08278665
	loadspritegfx ANIM_TAG_SMALL_EMBER
	loopsewithpan SE_M_EMBER, SOUND_PAN_ATTACKER, 5, 2
	createsprite gEmberSpriteTemplate, ANIM_TARGET, 2, 20, 0, -16, 24, 20, 1
	delay 4
	createsprite gEmberSpriteTemplate, ANIM_TARGET, 2, 20, 0, 0, 24, 20, 1
	delay 4
	createsprite gEmberSpriteTemplate, ANIM_TARGET, 2, 20, 0, 16, 24, 20, 1
	delay 16
	playsewithpan SE_M_FLAME_WHEEL, SOUND_PAN_TARGET
	call EmberFireHit
	call EmberFireHit
	call EmberFireHit
	end

EmberFireHit:
	createsprite gEmberFlareSpriteTemplate, ANIM_TARGET, 2, -24, 24, 24, 24, 20, ANIM_TARGET, 1
	delay 4
	return

Move_MEGA_PUNCH: @ 0x082786D9
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	monbg ANIM_TARGET
	delay 2
	simple_palette_blend selector=F_PAL_BG, delay=0, initial_blend_y=0, target_blend_y=16, color=RGB_BLACK
	setalpha 12, 8
	playsewithpan SE_M_MEGA_KICK, SOUND_PAN_TARGET
	createsprite gMegaPunchKickSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 0, 50
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_TARGET, 2, 0, 7, RGB_WHITE
	delay 50
	call SetImpactBackground
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=0, y=0, relative_to=ANIM_TARGET, animation=0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 22, 1
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_TARGET, 2, 0, 0, RGB_WHITE
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG | F_PAL_BATTLERS, delay=3, num_blends=1, color1=RGB_BLACK, blend_y1=8, color2=RGB_BLACK, blend_y2=0
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 2
	restorebg
	waitbgfadein
	end

SetImpactBackground:
	delay 2
	createvisualtask AnimTask_IsContest, 2
	jumprettrue SetImpactContestsBG
	createvisualtask AnimTask_IsTargetPlayerSide, 2
	jumpretfalse SetImpactOpponentBG
	jumprettrue SetImpactPlayerBG
SetImpactBackgroundRet:
	return
SetImpactOpponentBG:
	changebg BG_IMPACT_OPPONENT
	goto SetImpactBackgroundRet
SetImpactPlayerBG:
	changebg BG_IMPACT_PLAYER
	goto SetImpactBackgroundRet
SetImpactContestsBG:
	changebg BG_IMPACT_CONTESTS
	goto SetImpactBackgroundRet

Move_MEGA_KICK: @ 0x082787B3
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	monbg ANIM_TARGET
	delay 2
	simple_palette_blend selector=F_PAL_BG, delay=0, initial_blend_y=0, target_blend_y=16, color=RGB_BLACK
	setalpha 12, 8
	playsewithpan SE_M_MEGA_KICK, SOUND_PAN_TARGET
	createsprite gMegaPunchKickSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 50
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_TARGET, 2, 0, 7, RGB_WHITE
	delay 50
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	call SetImpactBackground
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=0, y=0, relative_to=ANIM_TARGET, animation=0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 22, 1
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_TARGET, 2, 0, 0, RGB_WHITE
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG | F_PAL_BATTLERS, delay=3, num_blends=1, color1=RGB_BLACK, blend_y1=8, color2=RGB_BLACK, blend_y2=0
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 2
	restorebg
	waitbgfadein
	end

Move_COMET_PUNCH: @ 0x0827884F
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	monbg ANIM_TARGET
	setalpha 12, 8
	choosetwoturnanim CometPunchLeft, CometPunchRight
CometPunchContinue:
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
CometPunchLeft:
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=-8, y=-8, relative_to=ANIM_TARGET, animation=2
	create_fist_sprite ANIM_ATTACKER, 3, x=-8, y=0, duration=8
	goto CometPunchContinue
CometPunchRight:
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=8, y=-8, relative_to=ANIM_TARGET, animation=2
	create_fist_sprite ANIM_ATTACKER, 3, x=8, y=0, duration=8
	goto CometPunchContinue

Move_SONIC_BOOM: @ 0x082788C7
	loadspritegfx ANIM_TAG_AIR_WAVE
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	splitbgprio ANIM_TARGET
	setalpha 12, 8
	call SonicBoomProjectile
	call SonicBoomProjectile
	call SonicBoomProjectile
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 10, 1
	call SonicBoomHit
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
SonicBoomProjectile:
	playsewithpan SE_M_RAZOR_WIND2, SOUND_PAN_ATTACKER
	createsprite gSonicBoomSpriteTemplate, ANIM_TARGET, 2, 16, 0, 0, 0, 15
	delay 4
	return
SonicBoomHit:
	create_basic_hitsplat_sprite ANIM_TARGET, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	delay 4
	return

Move_THUNDER_SHOCK: @ 0x08278928
	loadspritegfx ANIM_TAG_SPARK
	loadspritegfx ANIM_TAG_SPARK_2
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 0, 0, 6, RGB_BLACK
	waitforvisualfinish
	delay 10
	createvisualtask AnimTask_ElectricBolt, 5, 0, -44, 0
	playsewithpan SE_M_THUNDERBOLT, SOUND_PAN_TARGET
	delay 9
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_TARGET, 0, 0, 13, RGB_BLACK
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_TARGET, 0, 13, 0, RGB_BLACK
	waitforvisualfinish
	delay 20
	call ElectricityEffect
	waitforvisualfinish
	delay 20
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 0, 6, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_THUNDERBOLT: @ 0x08278996
	loadspritegfx ANIM_TAG_SPARK
	loadspritegfx ANIM_TAG_SHOCK_3
	loadspritegfx ANIM_TAG_SPARK_2
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 0, 0, 6, RGB_BLACK
	waitforvisualfinish
	delay 10
	createvisualtask AnimTask_ElectricBolt, 5, 24, -52, 0
	playsewithpan SE_M_THUNDERBOLT, SOUND_PAN_TARGET
	delay 7
	createvisualtask AnimTask_ElectricBolt, 5, -24, -52, 0
	playsewithpan SE_M_THUNDERBOLT, SOUND_PAN_TARGET
	delay 7
	createvisualtask AnimTask_ElectricBolt, 5, 0, -60, 1
	playsewithpan SE_M_THUNDERBOLT, SOUND_PAN_TARGET
	delay 9
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_TARGET, 0, 0, 13, RGB_BLACK
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_TARGET, 0, 13, 0, RGB_BLACK
	waitforvisualfinish
	delay 20
	createsprite gThunderboltOrbSpriteTemplate, ANIM_TARGET, 3, 44, 0, 0, 3
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_TARGET, 4, 0, 0, 32, 44, 0, 40, 0, -32765
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_TARGET, 4, 0, 0, 32, 44, 64, 40, 1, -32765
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_TARGET, 4, 0, 0, 32, 44, 128, 40, 0, -32765
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_TARGET, 4, 0, 0, 32, 44, 192, 40, 2, -32765
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_TARGET, 4, 0, 0, 16, 44, 32, 40, 0, -32765
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_TARGET, 4, 0, 0, 16, 44, 96, 40, 1, -32765
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_TARGET, 4, 0, 0, 16, 44, 160, 40, 0, -32765
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_TARGET, 4, 0, 0, 16, 44, 224, 40, 2, -32765
	playsewithpan SE_M_HYPER_BEAM, SOUND_PAN_TARGET
	delay 0
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 0, 2, 2, RGB_BLACK
	delay 6
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 0, 6, 6, RGB_BLACK
	delay 6
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 0, 2, 2, RGB_BLACK
	delay 6
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 0, 6, 6, RGB_BLACK
	waitforvisualfinish
	delay 20
	waitplaysewithpan SE_M_THUNDERBOLT2, SOUND_PAN_TARGET, 19
	call ElectricityEffect
	waitforvisualfinish
	delay 20
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 0, 6, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_THUNDER_WAVE: @ 0x08278B4C
	loadspritegfx ANIM_TAG_SPARK
	loadspritegfx ANIM_TAG_SPARK_2
	loadspritegfx ANIM_TAG_SPARK_H
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 0, 0, 6, RGB_BLACK
	waitforvisualfinish
	delay 10
	createvisualtask AnimTask_ElectricBolt, 5, 0, -48, 0
	playsewithpan SE_M_THUNDER_WAVE, SOUND_PAN_TARGET
	delay 20
	loopsewithpan SE_M_THUNDERBOLT2, SOUND_PAN_TARGET, 10, 4
	createsprite gThunderWaveSpriteTemplate, ANIM_TARGET, 2, -16, -16
	delay 4
	createsprite gThunderWaveSpriteTemplate, ANIM_TARGET, 2, -16, 0
	delay 4
	createsprite gThunderWaveSpriteTemplate, ANIM_TARGET, 2, -16, 16
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 0, 6, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_BEAT_UP: @ 0x08278BBB
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	monbg ANIM_TARGET
	setalpha 12, 8
	choosetwoturnanim BeatUpLeft, BeatUpRight
BeatUpContinue:
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
BeatUpLeft:
	create_basic_hitsplat_sprite ANIM_TARGET, 2, x=-20, y=-20, relative_to=ANIM_TARGET, animation=2
	create_fist_sprite ANIM_TARGET, 3, x=-20, y=-12, duration=8
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	delay 8
	create_basic_hitsplat_sprite ANIM_TARGET, 2, x=8, y=0, relative_to=ANIM_TARGET, animation=2
	create_fist_sprite ANIM_TARGET, 3, x=8, y=8, duration=8
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	goto BeatUpContinue
BeatUpRight:
	create_basic_hitsplat_sprite ANIM_TARGET, 2, x=12, y=-20, relative_to=ANIM_TARGET, animation=2
	create_fist_sprite ANIM_TARGET, 3, x=12, y=-12, duration=8
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	delay 8
	create_basic_hitsplat_sprite ANIM_TARGET, 2, x=-12, y=0, relative_to=ANIM_TARGET, animation=2
	create_fist_sprite ANIM_TARGET, 3, x=-12, y=8, duration=8
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	goto BeatUpContinue

Move_STOMP: @ 0x08278CB6
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_TARGET
	createsprite gStompFootSpriteTemplate, ANIM_ATTACKER, 3, 0, -32, 15
	delay 19
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=0, y=-8, relative_to=ANIM_TARGET, animation=1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 4, 9, 1
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_TAIL_WHIP:
	loopsewithpan SE_M_TAIL_WHIP, SOUND_PAN_ATTACKER, 24, 3
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 12, 4, 2, 3
	waitforvisualfinish
	end

Move_CUT:
	loadspritegfx ANIM_TAG_CUT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_M_CUT, SOUND_PAN_TARGET
	createsprite gCuttingSliceSpriteTemplate, ANIM_ATTACKER, 2, 40, -32, 0
	delay 5
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 10, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

Move_HIDDEN_POWER:
	loadspritegfx ANIM_TAG_RED_ORB
	playsewithpan SE_M_TAKE_DOWN, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -7, -7, 11, ANIM_ATTACKER, 0
	waitforvisualfinish
	delay 30
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB(31, 31, 19), 12, 5, 1
	delay 4
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -7, -7, 11, ANIM_ATTACKER, 0
	playsewithpan SE_M_REVERSAL, SOUND_PAN_ATTACKER
	createsprite gHiddenPowerOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 0
	createsprite gHiddenPowerOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 42
	createsprite gHiddenPowerOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 84
	createsprite gHiddenPowerOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 126
	createsprite gHiddenPowerOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 168
	createsprite gHiddenPowerOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 210
	delay 52
	setarg 7, 0xFFFF
	playsewithpan SE_M_REFLECT, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -7, -7, 11, ANIM_ATTACKER, 0
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 0
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 32
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 64
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 96
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 128
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 160
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 192
	createsprite gHiddenPowerOrbScatterSpriteTemplate, ANIM_TARGET, 2, 224
	end

Move_REVERSAL:
	loadspritegfx ANIM_TAG_BLUE_ORB
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	playsewithpan SE_M_DETECT, SOUND_PAN_ATTACKER
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG | F_PAL_BATTLERS, delay=3, num_blends=3, color1=RGB_WHITE, blend_y1=8, color2=RGB_BLACK, blend_y2=0
	waitforvisualfinish
	delay 30
	blend_color_cycle priority=2, selector=F_PAL_BG | F_PAL_BATTLERS, delay=3, num_blends=2, initial_blend_y=0, target_blend_y=10, color=RGB_WHITE
	delay 10
	playsewithpan SE_M_REVERSAL, SOUND_PAN_ATTACKER
	createsprite gReversalOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 0
	createsprite gReversalOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 42
	createsprite gReversalOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 84
	createsprite gReversalOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 126
	createsprite gReversalOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 168
	createsprite gReversalOrbSpriteTemplate, ANIM_ATTACKER, 2, 26, 210
	waitforvisualfinish
	delay 20
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 4
	delay 8
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG | F_PAL_BATTLERS, delay=3, num_blends=1, color1=RGB_WHITE, blend_y1=8, color2=RGB_BLACK, blend_y2=0
	create_fist_sprite ANIM_TARGET, 4, x=0, y=0, duration=10
	create_basic_hitsplat_sprite ANIM_TARGET, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=1
	createvisualtask AnimTask_ShakeTargetBasedOnMovePowerOrDmg, 5, FALSE, 1, 8, 1, 0
	end

Move_PURSUIT:
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	fadetobg BG_DARK
	waitbgfadein
	delay 0
	setalpha 12, 8
	choosetwoturnanim PursuitNormal, PursuitOnSwitchout
PursuitContinue:
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 0
	restorebg
	waitbgfadein
	end

PursuitNormal:
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeTargetBasedOnMovePowerOrDmg, 5, FALSE, 1, 6, 1, 0
	goto PursuitContinue

PursuitOnSwitchout:
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=1
	createvisualtask AnimTask_ShakeTargetBasedOnMovePowerOrDmg, 5, FALSE, 1, 6, 1, 0
	goto PursuitContinue

Move_SPIKE_CANNON:
	loadspritegfx ANIM_TAG_NEEDLE
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	splitbgprio ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_WindUpLunge, 5, ANIM_ATTACKER, -4, 0, 4, 6, 8, 4
	waitforvisualfinish
	loopsewithpan SE_M_RAZOR_WIND2, SOUND_PAN_ATTACKER, 5, 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 5
	create_linear_stinger_sprite ANIM_ATTACKER, 2, initial_x=10, initial_y=-8, target_x=-8, target_y=-8, duration=20
	create_linear_stinger_sprite ANIM_ATTACKER, 2, initial_x=18, initial_y=0, target_x=0, target_y=0, duration=20
	create_linear_stinger_sprite ANIM_ATTACKER, 2, initial_x=26, initial_y=8, target_x=8, target_y=8, duration=20
	waitforvisualfinish
	create_handle_invert_hitsplat_sprite ANIM_ATTACKER, 3, x=-8, y=-8, relative_to=ANIM_TARGET, animation=2
	create_handle_invert_hitsplat_sprite ANIM_ATTACKER, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	create_handle_invert_hitsplat_sprite ANIM_ATTACKER, 3, x=8, y=8, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 7, 1
	loopsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET, 5, 3
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SWORDS_DANCE:
	loadspritegfx ANIM_TAG_SWORD
	monbg ANIM_ATTACKER
	setalpha 12, 8
	playsewithpan SE_M_SWORDS_DANCE, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 16, 6, 1, 4
	createsprite gSwordsDanceBladeSpriteTemplate, ANIM_ATTACKER, 2, 0, 0
	delay 22
	flash_anim_tag_with_color tag=ANIM_TAG_SWORD, delay=2, num_blends=2, color1=RGB(18, 31, 31), blend_y1=16, color2=RGB_BLACK, blend_y2=0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 1 @ JP-specific post-blend delay
	end

Move_PSYCH_UP:
	loadspritegfx ANIM_TAG_SPIRAL
	monbg ANIM_ATK_PARTNER
	blend_color_cycleexclude unk0=1, delay=2, num_blends=6, initial_blend_y=1, target_blend_y=11, color=RGB_BLACK
	setalpha 12, 8
	loopsewithpan SE_M_PSYBEAM2, SOUND_PAN_ATTACKER, 5, 10
	createsprite gPsychUpSpiralSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 0, 0
	createvisualtask AnimTask_SwayMon, 5, 0, 5, 2560, 8, ANIM_ATTACKER
	delay 127
	delay 4
	playsewithpan SE_M_PSYBEAM, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -5, -5, 10, ANIM_ATTACKER, 1
	createvisualtask AnimTask_BlendBattleAnimPal, 9, F_PAL_ATTACKER, 2, 10, 0, RGB_YELLOW
	delay 30
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	waitforvisualfinish
	end

Move_DIZZY_PUNCH:
	loadspritegfx ANIM_TAG_DUCK
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	call DizzyPunchLunge
	create_fist_sprite ANIM_TARGET, 5, x=16, y=8, duration=20
	create_basic_hitsplat_sprite ANIM_TARGET, 4, x=16, y=0, relative_to=ANIM_TARGET, animation=1
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	createsprite gDizzyPunchDuckSpriteTemplate, ANIM_TARGET, 3, 16, 8, 160, -32
	createsprite gDizzyPunchDuckSpriteTemplate, ANIM_TARGET, 3, 16, 8, -256, -40
	createsprite gDizzyPunchDuckSpriteTemplate, ANIM_TARGET, 3, 16, 8, 128, -16
	createsprite gDizzyPunchDuckSpriteTemplate, ANIM_TARGET, 3, 16, 8, 416, -38
	createsprite gDizzyPunchDuckSpriteTemplate, ANIM_TARGET, 3, 16, 8, -128, -22
	createsprite gDizzyPunchDuckSpriteTemplate, ANIM_TARGET, 3, 16, 8, -384, -31
	delay 10
	call DizzyPunchLunge
	create_fist_sprite ANIM_TARGET, 5, x=-16, y=-8, duration=20
	create_basic_hitsplat_sprite ANIM_TARGET, 4, x=-16, y=-16, relative_to=ANIM_TARGET, animation=1
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	createsprite gDizzyPunchDuckSpriteTemplate, ANIM_TARGET, 3, -16, -8, 160, -32
	createsprite gDizzyPunchDuckSpriteTemplate, ANIM_TARGET, 3, -16, -8, -256, -40
	createsprite gDizzyPunchDuckSpriteTemplate, ANIM_TARGET, 3, -16, -8, 128, -16
	createsprite gDizzyPunchDuckSpriteTemplate, ANIM_TARGET, 3, -16, -8, 416, -38
	createsprite gDizzyPunchDuckSpriteTemplate, ANIM_TARGET, 3, -16, -8, -128, -22
	createsprite gDizzyPunchDuckSpriteTemplate, ANIM_TARGET, 3, -16, -8, -384, -31
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

DizzyPunchLunge:
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 4
	delay 6
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 7, 1
	return

Move_FIRE_SPIN:
	loadspritegfx ANIM_TAG_SMALL_EMBER
	playsewithpan SE_M_SACRED_FIRE2, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 2, 47, 1
	call FireSpinEffect
	call FireSpinEffect
	call FireSpinEffect
	waitforvisualfinish
	end

FireSpinEffect:
	createsprite gFireSpinSpriteTemplate, ANIM_TARGET, 2, 0, 28, 528, 30, 13, 50, ANIM_TARGET
	delay 2
	createsprite gFireSpinSpriteTemplate, ANIM_TARGET, 2, 0, 32, 480, 20, 16, -46, ANIM_TARGET
	delay 2
	createsprite gFireSpinSpriteTemplate, ANIM_TARGET, 2, 0, 33, 576, 20, 8, 42, ANIM_TARGET
	delay 2
	createsprite gFireSpinSpriteTemplate, ANIM_TARGET, 2, 0, 31, 400, 25, 11, -42, ANIM_TARGET
	delay 2
	createsprite gFireSpinSpriteTemplate, ANIM_TARGET, 2, 0, 28, 512, 25, 16, 46, ANIM_TARGET
	delay 2
	createsprite gFireSpinSpriteTemplate, ANIM_TARGET, 2, 0, 33, 464, 30, 15, -50, ANIM_TARGET
	delay 2
	return

Move_FURY_CUTTER:
	loadspritegfx ANIM_TAG_CUT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_M_RAZOR_WIND, SOUND_PAN_TARGET
	createvisualtask AnimTask_IsFuryCutterHitRight, 2
	jumpretfalse FuryCutterLeft
	goto FuryCutterRight
FuryCutterContinue:
	createvisualtask AnimTask_GetFuryCutterHitCount, 2
	jumpreteq 1, FuryCutterContinue2
	jumpreteq 2, FuryCutterMedium
	jumpreteq 3, FuryCutterStrong
	goto FuryCutterStrongest
FuryCutterContinue2:
	delay 5
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 10, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end
FuryCutterLeft:
	createsprite gCuttingSliceSpriteTemplate, ANIM_ATTACKER, 2, 40, -32, 0
	goto FuryCutterContinue
FuryCutterRight:
	createsprite gCuttingSliceSpriteTemplate, ANIM_ATTACKER, 2, 40, -32, 1
	goto FuryCutterContinue
FuryCutterMedium:
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG | F_PAL_BATTLERS, delay=3, num_blends=1, color1=RGB(9, 8, 10), blend_y1=4, color2=RGB_BLACK, blend_y2=0
	goto FuryCutterContinue2
FuryCutterStrong:
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG | F_PAL_BATTLERS, delay=3, num_blends=3, color1=RGB(9, 8, 10), blend_y1=4, color2=RGB_BLACK, blend_y2=0
	goto FuryCutterContinue2
FuryCutterStrongest:
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG | F_PAL_BATTLERS, delay=3, num_blends=3, color1=RGB(9, 8, 10), blend_y1=4, color2=RGB_BLACK, blend_y2=0
	goto FuryCutterContinue2

Move_SELF_DESTRUCT:
	loadspritegfx ANIM_TAG_EXPLOSION
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 1, 0, 9, RGB_RED
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_PLAYER_LEFT, 6, 0, 38, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_PLAYER_RIGHT, 6, 0, 38, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_OPPONENT_LEFT, 6, 0, 38, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_OPPONENT_RIGHT, 6, 0, 38, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_ATTACKER_FORCE, 6, 0, 38, 1
	call SelfDestructExplode
	call SelfDestructExplode
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 1, 9, 0, RGB_RED
	end

SelfDestructExplode:
	playsewithpan SE_M_SELF_DESTRUCT, SOUND_PAN_ATTACKER
	createsprite gExplosionSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 0, 1
	delay 6
	playsewithpan SE_M_SELF_DESTRUCT, SOUND_PAN_ATTACKER
	createsprite gExplosionSpriteTemplate, ANIM_ATTACKER, 3, 24, -24, 0, 1
	delay 6
	playsewithpan SE_M_SELF_DESTRUCT, SOUND_PAN_ATTACKER
	createsprite gExplosionSpriteTemplate, ANIM_ATTACKER, 3, -16, 16, 0, 1
	delay 6
	playsewithpan SE_M_SELF_DESTRUCT, SOUND_PAN_ATTACKER
	createsprite gExplosionSpriteTemplate, ANIM_ATTACKER, 3, -24, -12, 0, 1
	delay 6
	playsewithpan SE_M_SELF_DESTRUCT, SOUND_PAN_ATTACKER
	createsprite gExplosionSpriteTemplate, ANIM_ATTACKER, 3, 16, 16, 0, 1
	delay 6
	return

Move_SLAM:
	loadspritegfx ANIM_TAG_SLAM_HIT
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_ATTACKER
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, 3, 0, 4
	delay 1
	createsprite gSlamHitSpriteTemplate, ANIM_ATTACKER, 2, 0, 0
	delay 3
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=1
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 1, -12, 10, 0, 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 5
	delay 3
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 0, 3, 6, 1
	waitforvisualfinish
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 1, 0, 6
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_VINE_WHIP:
	loadspritegfx ANIM_TAG_WHIP_HIT
	playsewithpan SE_M_JUMP_KICK, SOUND_PAN_ATTACKER
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 6
	delay 6
	playsewithpan SE_M_SCRATCH, SOUND_PAN_TARGET
	createsprite gVineWhipSpriteTemplate, ANIM_TARGET, 2, 0, 0
	delay 6
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 6, 1
	end

Move_DRILL_PECK:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_WHIRLWIND_LINES
	createsprite gBowMonSpriteTemplate, ANIM_ATTACKER, 2, 0
	playsewithpan SE_M_HEADBUTT, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 2
	createsprite gBowMonSpriteTemplate, ANIM_ATTACKER, 2, 1
	delay 2
	loopsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET, 4, 8
	createvisualtask AnimTask_DrillPeckHitSplats, 5
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 18, 1
	waitforvisualfinish
	createsprite gBowMonSpriteTemplate, ANIM_ATTACKER, 2, 2
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 6
	waitforvisualfinish
	end

Move_WATERFALL:
	loadspritegfx ANIM_TAG_WATER_IMPACT
	loadspritegfx ANIM_TAG_SMALL_BUBBLES
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 23, 1
	delay 5
	playsewithpan SE_M_CRABHAMMER, SOUND_PAN_ATTACKER
	createsprite gSmallBubblePairSpriteTemplate, ANIM_ATTACKER, 2, 10, 10, 25, ANIM_ATTACKER
	delay 4
	playsewithpan SE_M_CRABHAMMER, SOUND_PAN_ATTACKER
	createsprite gSmallBubblePairSpriteTemplate, ANIM_ATTACKER, 2, -15, 0, 25, ANIM_ATTACKER
	delay 4
	playsewithpan SE_M_CRABHAMMER, SOUND_PAN_ATTACKER
	createsprite gSmallBubblePairSpriteTemplate, ANIM_ATTACKER, 2, 20, 10, 25, ANIM_ATTACKER
	delay 4
	playsewithpan SE_M_CRABHAMMER, SOUND_PAN_ATTACKER
	createsprite gSmallBubblePairSpriteTemplate, ANIM_ATTACKER, 2, 0, -10, 25, ANIM_ATTACKER
	delay 4
	playsewithpan SE_M_CRABHAMMER, SOUND_PAN_ATTACKER
	createsprite gSmallBubblePairSpriteTemplate, ANIM_ATTACKER, 2, -10, 15, 25, ANIM_ATTACKER
	delay 4
	playsewithpan SE_M_CRABHAMMER, SOUND_PAN_ATTACKER
	createsprite gSmallBubblePairSpriteTemplate, ANIM_ATTACKER, 2, 25, 20, 25, ANIM_ATTACKER
	delay 4
	playsewithpan SE_M_CRABHAMMER, SOUND_PAN_ATTACKER
	createsprite gSmallBubblePairSpriteTemplate, ANIM_ATTACKER, 2, -20, 20, 25, ANIM_ATTACKER
	delay 4
	playsewithpan SE_M_CRABHAMMER, SOUND_PAN_ATTACKER
	createsprite gSmallBubblePairSpriteTemplate, ANIM_ATTACKER, 2, 12, 0, 25, ANIM_ATTACKER
	waitforvisualfinish
	delay 10
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 5
	delay 6
	call RisingWaterHitEffect
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

RisingWaterHitEffect:
	playsewithpan SE_M_WATERFALL, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 17, 1
	createsprite gWaterHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 20, ANIM_TARGET, 1
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, 20
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, 20
	delay 2
	createsprite gWaterHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 15, ANIM_TARGET, 1
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, 15
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, 15
	delay 2
	createsprite gWaterHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 10, ANIM_TARGET, 1
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, 10
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, 10
	delay 2
	createsprite gWaterHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 5, ANIM_TARGET, 1
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, 5
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, 5
	delay 2
	createsprite gWaterHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, ANIM_TARGET, 1
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, 0
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, 0
	delay 2
	createsprite gWaterHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, -5, ANIM_TARGET, 1
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, -5
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, -5
	delay 2
	createsprite gWaterHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, -10, ANIM_TARGET, 1
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, -10
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, -10
	delay 2
	createsprite gWaterHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, -15, ANIM_TARGET, 1
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, -15
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, -15
	delay 2
	createsprite gWaterHitSplatSpriteTemplate, ANIM_ATTACKER, 3, 0, -20, ANIM_TARGET, 1
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, -20
	createsprite gSmallDriftingBubblesSpriteTemplate, ANIM_ATTACKER, 4, 0, -20
	return

Move_EXPLOSION:
	loadspritegfx ANIM_TAG_EXPLOSION
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG, delay=8, num_blends=9, color1=RGB(26, 8, 8), blend_y1=8, color2=RGB_BLACK, blend_y2=8
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_PLAYER_LEFT, 8, 0, 40, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_PLAYER_RIGHT, 8, 0, 40, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_OPPONENT_LEFT, 8, 0, 40, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_OPPONENT_RIGHT, 8, 0, 40, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_ATTACKER_FORCE, 8, 0, 40, 1
	call Explosion1
	call Explosion1
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 1, 16, 16, RGB_WHITE
	delay 50
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 3, 16, 0, RGB_WHITE
	end

Explosion1:
	playsewithpan SE_M_EXPLOSION, SOUND_PAN_ATTACKER
	createsprite gExplosionSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 0, 1
	delay 6
	playsewithpan SE_M_EXPLOSION, SOUND_PAN_ATTACKER
	createsprite gExplosionSpriteTemplate, ANIM_ATTACKER, 3, 24, -24, 0, 1
	delay 6
	playsewithpan SE_M_EXPLOSION, SOUND_PAN_ATTACKER
	createsprite gExplosionSpriteTemplate, ANIM_ATTACKER, 3, -16, 16, 0, 1
	delay 6
	playsewithpan SE_M_EXPLOSION, SOUND_PAN_ATTACKER
	createsprite gExplosionSpriteTemplate, ANIM_ATTACKER, 3, -24, -12, 0, 1
	delay 6
	playsewithpan SE_M_EXPLOSION, SOUND_PAN_ATTACKER
	createsprite gExplosionSpriteTemplate, ANIM_ATTACKER, 3, 16, 16, 0, 1
	delay 6
	return

Move_DEFENSE_CURL:
	loadspritegfx ANIM_TAG_ECLIPSING_ORB
	loopsewithpan SE_M_TRI_ATTACK, SOUND_PAN_ATTACKER, 18, 3
	set_grayscale_pal battler=ANIM_ATTACKER
	createvisualtask AnimTask_DefenseCurlDeformMon, 5
	waitforvisualfinish
	createsprite gEclipsingOrbSpriteTemplate, ANIM_ATTACKER, 2, 0, 6, 0, 1
	waitforvisualfinish
	set_original_pal battler=ANIM_ATTACKER
	waitforvisualfinish
	end

Move_PROTECT:
	loadspritegfx ANIM_TAG_PROTECT
	monbg ANIM_ATK_PARTNER
	splitbgprio ANIM_ATTACKER
	waitplaysewithpan SE_M_REFLECT, SOUND_PAN_ATTACKER, 16
	createsprite gProtectSpriteTemplate, ANIM_ATTACKER, 2, 24, 0, 90
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	end

Move_DETECT:
	loadspritegfx ANIM_TAG_SPARKLE_4
	simple_palette_blend selector=F_PAL_BG, delay=2, initial_blend_y=0, target_blend_y=9, color=RGB_BLACK
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 1, 0, 9, RGB_WHITE
	delay 18
	playsewithpan SE_M_DETECT, SOUND_PAN_ATTACKER
	createsprite gSpinningSparkleSpriteTemplate, ANIM_ATTACKER, 13, 20, -20
	waitforvisualfinish
	delay 10
	simple_palette_blend selector=F_PAL_BG, delay=2, initial_blend_y=9, target_blend_y=0, color=RGB_BLACK
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 2, 9, 0, RGB_WHITE
	waitforvisualfinish
	end

Move_FRUSTRATION:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_ANGER
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_GetFrustrationPowerLevel, 1
	jumpreteq 0, Frustration_Strongest
	jumpreteq 1, Frustration_Strong
	jumpreteq 2, Frustration_Medium
	goto Frustration_Weak
Frustration_Continue:
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
Frustration_Strongest:
	playsewithpan SE_M_DRAGON_RAGE, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_ATTACKER, 1, 0, 15, 1
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 3, 0, 9, RGB_RED
	waitforvisualfinish
	delay 20
	playsewithpan SE_M_SWAGGER2, SOUND_PAN_ATTACKER
	createsprite gAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, -28
	waitforvisualfinish
	playsewithpan SE_M_SWAGGER2, SOUND_PAN_ATTACKER
	createsprite gAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, -28
	waitforvisualfinish
	delay 10
	createvisualtask AnimTask_SwayMon, 5, 0, 16, 6144, 8, ANIM_ATTACKER
	delay 5
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 30, 1
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=0
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	delay 5
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=24, y=8, relative_to=ANIM_TARGET, animation=0
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	delay 5
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=-24, y=-16, relative_to=ANIM_TARGET, animation=0
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	delay 5
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=8, y=4, relative_to=ANIM_TARGET, animation=0
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	delay 5
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=-16, y=19, relative_to=ANIM_TARGET, animation=0
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	delay 5
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=18, y=-18, relative_to=ANIM_TARGET, animation=0
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 3, 9, 0, RGB_RED
	goto Frustration_Continue
Frustration_Strong:
	playsewithpan SE_M_DRAGON_RAGE, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_ATTACKER, 1, 0, 15, 1
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 3, 0, 9, RGB_RED
	waitforvisualfinish
	delay 20
	playsewithpan SE_M_SWAGGER2, SOUND_PAN_ATTACKER
	createsprite gAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, -28
	waitforvisualfinish
	delay 5
	createvisualtask AnimTask_StrongFrustrationGrowAndShrink, 5
	delay 7
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=0, y=8, relative_to=ANIM_TARGET, animation=1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 6, 1
	delay 14
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=12, y=-6, relative_to=ANIM_TARGET, animation=1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 6, 1
	delay 14
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=-12, y=-6, relative_to=ANIM_TARGET, animation=1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 6, 1
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 3, 9, 0, RGB_RED
	goto Frustration_Continue
Frustration_Medium:
	playsewithpan SE_M_SWAGGER2, SOUND_PAN_ATTACKER
	createsprite gAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, -28
	waitforvisualfinish
	delay 5
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 4
	delay 6
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=10, y=4, relative_to=ANIM_TARGET, animation=1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 4
	delay 6
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=-10, y=-4, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 6, 1
	goto Frustration_Continue
Frustration_Weak:
	createsprite gWeakFrustrationAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 20, -28
	waitforvisualfinish
	delay 10
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 10, 2
	delay 12
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 6, 1
	goto Frustration_Continue

Move_SAFEGUARD:
	loadspritegfx ANIM_TAG_GUARD_RING
	monbg ANIM_ATK_PARTNER
	setalpha 8, 8
	playsewithpan SE_M_MILK_DRINK, SOUND_PAN_ATTACKER
	createsprite gGuardRingSpriteTemplate, ANIM_ATTACKER, 2
	delay 4
	createsprite gGuardRingSpriteTemplate, ANIM_ATTACKER, 2
	delay 4
	createsprite gGuardRingSpriteTemplate, ANIM_ATTACKER, 2
	waitforvisualfinish
	playsewithpan SE_SHINY, SOUND_PAN_ATTACKER
	blend_color_cycle priority=2, selector=F_PAL_ATK_SIDE, delay=0, num_blends=2, initial_blend_y=0, target_blend_y=10, color=RGB_WHITE
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

Move_PAIN_SPLIT: @ 0x08279CC5
	loadspritegfx ANIM_TAG_PAIN_SPLIT
	createsprite gPainSplitProjectileSpriteTemplate, ANIM_ATTACKER, 2, -8, -42, ANIM_ATTACKER
	createsprite gPainSplitProjectileSpriteTemplate, ANIM_TARGET, 2, -8, -42, ANIM_TARGET
	delay 10
	playsewithpan SE_M_SWAGGER2, 0
	createvisualtask AnimTask_PainSplitMovement, 2, ANIM_ATTACKER, 0
	createvisualtask AnimTask_PainSplitMovement, 2, ANIM_TARGET, 0
	waitforvisualfinish
	createsprite gPainSplitProjectileSpriteTemplate, ANIM_ATTACKER, 2, -24, -42, ANIM_ATTACKER
	createsprite gPainSplitProjectileSpriteTemplate, ANIM_TARGET, 2, -24, -42, ANIM_TARGET
	delay 10
	playsewithpan SE_M_SWAGGER2, 0
	createvisualtask AnimTask_PainSplitMovement, 2, ANIM_ATTACKER, 1
	createvisualtask AnimTask_PainSplitMovement, 2, ANIM_TARGET, 1
	waitforvisualfinish
	createsprite gPainSplitProjectileSpriteTemplate, ANIM_ATTACKER, 2, 8, -42, ANIM_ATTACKER
	createsprite gPainSplitProjectileSpriteTemplate, ANIM_TARGET, 2, 8, -42, ANIM_TARGET
	delay 10
	playsewithpan SE_M_SWAGGER2, 0
	createvisualtask AnimTask_PainSplitMovement, 2, ANIM_ATTACKER, 2
	createvisualtask AnimTask_PainSplitMovement, 2, ANIM_TARGET, 2
	end

Move_VICE_GRIP: @ 0x08279D6D
	loadspritegfx ANIM_TAG_CUT
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_M_VICEGRIP, SOUND_PAN_TARGET
	createsprite gViceGripSpriteTemplate, ANIM_ATTACKER, 2, 0
	createsprite gViceGripSpriteTemplate, ANIM_ATTACKER, 2, 1
	delay 9
	create_basic_hitsplat_sprite ANIM_ATTACKER, 1, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 2, 0, 5, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_GUILLOTINE: @ 0x08279DB5
	loadspritegfx ANIM_TAG_CUT
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	fadetobgfromset BG_GUILLOTINE_OPPONENT, BG_GUILLOTINE_PLAYER, BG_GUILLOTINE_CONTESTS
	waitbgfadein
	playsewithpan SE_M_VICEGRIP, SOUND_PAN_TARGET
	createsprite gGuillotineSpriteTemplate, ANIM_ATTACKER, 2, 0
	createsprite gGuillotineSpriteTemplate, ANIM_ATTACKER, 2, 1
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_TARGET, 2, 0, 16, RGB_BLACK
	delay 9
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 2, 0, 23, 1
	delay 46
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 8, 1
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=0
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG | F_PAL_BATTLERS, delay=3, num_blends=1, color1=RGB_BLACK, blend_y1=8, color2=RGB_BLACK, blend_y2=0
	playsewithpan SE_M_RAZOR_WIND, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	restorebg
	waitbgfadein
	end

Move_PAY_DAY: @ 0x08279E41
	loadspritegfx ANIM_TAG_COIN
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	splitbgprio ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_M_RAZOR_WIND2, SOUND_PAN_ATTACKER
	createsprite gCoinThrowSpriteTemplate, ANIM_ATTACKER, 2, 20, 0, 0, 0, 1152
	waitforvisualfinish
	playsewithpan SE_M_PAY_DAY, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 1, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	createsprite gFallingCoinSpriteTemplate, ANIM_ATTACKER, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_OUTRAGE: @ 0x08279E94
	loadspritegfx ANIM_TAG_SMALL_EMBER
	loopsewithpan SE_M_DRAGON_RAGE, SOUND_PAN_ATTACKER, 8, 3
	blend_color_cycle priority=2, selector=F_PAL_BG | F_PAL_ATTACKER | F_PAL_TARGET, delay=2, num_blends=5, initial_blend_y=3, target_blend_y=8, color=RGB(14, 13, 0)
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 12, 6, 5, 4
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=5, y_velocity=0, flicker_duration=3
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=-5, y_velocity=0, flicker_duration=3
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=0, y_velocity=5, flicker_duration=3
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=0, y_velocity=-5, flicker_duration=3
	delay 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 40, 1
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=5, y_velocity=3, flicker_duration=3
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=-5, y_velocity=3, flicker_duration=3
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=5, y_velocity=-3, flicker_duration=3
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=-5, y_velocity=-3, flicker_duration=3
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=5, y_velocity=0, flicker_duration=3
	call OutrageFlames
	call OutrageFlames
	waitforvisualfinish
	end

OutrageFlames:
	delay 3
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=-5, y_velocity=0, flicker_duration=3
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=0, y_velocity=5, flicker_duration=3
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=0, y_velocity=-5, flicker_duration=3
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=5, y_velocity=3, flicker_duration=3
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=-5, y_velocity=3, flicker_duration=3
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=5, y_velocity=-3, flicker_duration=3
	delay 0
	create_outrage_flame_sprite ANIM_TARGET, 2, x=0, y=0, duration=30, x_velocity=-5, y_velocity=-3, flicker_duration=3
	return

Move_SPARK: @ 0x0827A02F
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_SPARK_2
	delay 0
	blend_color_cycle priority=2, selector=F_PAL_BG | F_PAL_ATTACKER, delay=-31, num_blends=1, initial_blend_y=5, target_blend_y=5, color=RGB(31, 31, 22)
	playsewithpan SE_M_THUNDERBOLT2, SOUND_PAN_ATTACKER
	createsprite gSparkElectricitySpriteTemplate, ANIM_ATTACKER, 0, 32, 24, 190, 12, ANIM_ATTACKER, 1, 0
	delay 0
	createsprite gSparkElectricitySpriteTemplate, ANIM_ATTACKER, 0, 80, 24, 22, 12, ANIM_ATTACKER, 1, 0
	createsprite gSparkElectricitySpriteTemplate, ANIM_ATTACKER, 0, 156, 24, 121, 13, ANIM_ATTACKER, 1, 1
	delay 0
	blend_color_cycle priority=2, selector=F_PAL_BG | F_PAL_ATTACKER, delay=-31, num_blends=1, initial_blend_y=0, target_blend_y=0, color=RGB(31, 31, 22)
	delay 10
	blend_color_cycle priority=2, selector=F_PAL_BG | F_PAL_ATTACKER, delay=-31, num_blends=1, initial_blend_y=5, target_blend_y=5, color=RGB(31, 31, 22)
	playsewithpan SE_M_THUNDERBOLT2, SOUND_PAN_ATTACKER
	createsprite gSparkElectricitySpriteTemplate, ANIM_ATTACKER, 0, 100, 24, 60, 10, ANIM_ATTACKER, 1, 0
	createsprite gSparkElectricitySpriteTemplate, ANIM_ATTACKER, 0, 170, 24, 42, 11, ANIM_ATTACKER, 1, 1
	delay 0
	createsprite gSparkElectricitySpriteTemplate, ANIM_ATTACKER, 0, 238, 24, 165, 10, ANIM_ATTACKER, 1, 1
	delay 0
	blend_color_cycle priority=2, selector=F_PAL_BG | F_PAL_ATTACKER, delay=-31, num_blends=1, initial_blend_y=0, target_blend_y=0, color=RGB(31, 31, 22)
	delay 20
	blend_color_cycle priority=2, selector=F_PAL_BG | F_PAL_ATTACKER, delay=-31, num_blends=1, initial_blend_y=7, target_blend_y=7, color=RGB(31, 31, 22)
	playsewithpan SE_M_THUNDERBOLT2, SOUND_PAN_ATTACKER
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_ATTACKER, 4, 0, 0, 32, 12, 0, 20, 0, 0
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_ATTACKER, 4, 0, 0, 32, 12, 64, 20, 1, 0
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_ATTACKER, 4, 0, 0, 32, 12, 128, 20, 0, 0
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_ATTACKER, 4, 0, 0, 32, 12, 192, 20, 2, 0
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_ATTACKER, 4, 0, 0, 16, 12, 32, 20, 0, 0
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_ATTACKER, 4, 0, 0, 16, 12, 96, 20, 1, 0
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_ATTACKER, 4, 0, 0, 16, 12, 160, 20, 0, 0
	createsprite gSparkElectricityFlashingSpriteTemplate, ANIM_ATTACKER, 4, 0, 0, 16, 12, 224, 20, 2, 0
	delay 4
	waitforvisualfinish
	blend_color_cycle priority=2, selector=F_PAL_BG | F_PAL_ATTACKER, delay=-31, num_blends=1, initial_blend_y=0, target_blend_y=0, color=RGB(31, 31, 22)
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 4
	delay 4
	playsewithpan SE_M_HYPER_BEAM, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_TARGET, 2, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	blend_color_cycle priority=2, selector=F_PAL_TARGET, delay=-31, num_blends=2, initial_blend_y=0, target_blend_y=6, color=RGB(31, 31, 22)
	call ElectricityEffect
	waitforvisualfinish
	end

Move_ATTRACT: @ 0x0827A246
	loadspritegfx ANIM_TAG_RED_HEART
	loopsewithpan SE_M_CHARM, SOUND_PAN_ATTACKER, 12, 3
	createvisualtask AnimTask_SwayMon, 5, 0, 12, 4096, 4, ANIM_ATTACKER
	delay 15
	createsprite gRedHeartProjectileSpriteTemplate, ANIM_TARGET, 3, 20, -8
	waitforvisualfinish
	playsewithpan SE_M_ATTRACT, SOUND_PAN_TARGET
	createsprite gRedHeartBurstSpriteTemplate, ANIM_TARGET, 3, 160, -32
	createsprite gRedHeartBurstSpriteTemplate, ANIM_TARGET, 3, -256, -40
	createsprite gRedHeartBurstSpriteTemplate, ANIM_TARGET, 3, 128, -16
	createsprite gRedHeartBurstSpriteTemplate, ANIM_TARGET, 3, 416, -38
	createsprite gRedHeartBurstSpriteTemplate, ANIM_TARGET, 3, -128, -22
	createsprite gRedHeartBurstSpriteTemplate, ANIM_TARGET, 3, -384, -31
	waitforvisualfinish
	waitplaysewithpan SE_M_ATTRACT2, 0, 15
	createvisualtask AnimTask_HeartsBackground, 5
	createsprite gRedHeartRisingSpriteTemplate, ANIM_ATTACKER, 40, 16, 256, 0
	createsprite gRedHeartRisingSpriteTemplate, ANIM_ATTACKER, 40, 224, 240, 15
	createsprite gRedHeartRisingSpriteTemplate, ANIM_ATTACKER, 40, 126, 272, 30
	createsprite gRedHeartRisingSpriteTemplate, ANIM_ATTACKER, 40, 80, 224, 45
	createsprite gRedHeartRisingSpriteTemplate, ANIM_ATTACKER, 40, 170, 272, 60
	createsprite gRedHeartRisingSpriteTemplate, ANIM_ATTACKER, 40, 40, 256, 75
	createsprite gRedHeartRisingSpriteTemplate, ANIM_ATTACKER, 40, 112, 256, 90
	createsprite gRedHeartRisingSpriteTemplate, ANIM_ATTACKER, 40, 200, 272, 90
	delay 75
	blend_color_cycle priority=2, selector=F_PAL_TARGET, delay=4, num_blends=4, initial_blend_y=0, target_blend_y=10, color=RGB(31, 25, 27)
	end

Move_GROWTH: @ 0x0827A33F
	call GrowthEffect
	waitforvisualfinish
	call GrowthEffect
	waitforvisualfinish
	end

GrowthEffect:
	blend_color_cycle priority=2, selector=F_PAL_ATTACKER, delay=0, num_blends=2, initial_blend_y=0, target_blend_y=8, color=RGB_WHITE
	playsewithpan SE_M_TAKE_DOWN, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -3, -3, 16, ANIM_ATTACKER, 0
	return

Move_WHIRLWIND: @ 0x0827A375
	loadspritegfx ANIM_TAG_WHIRLWIND_LINES
	createsprite gWhirlwindLineSpriteTemplate, ANIM_ATTACKER, 2, 0, -8, ANIM_TARGET, 60, 0
	createsprite gWhirlwindLineSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, ANIM_TARGET, 60, 1
	createsprite gWhirlwindLineSpriteTemplate, ANIM_ATTACKER, 2, 0, 8, ANIM_TARGET, 60, 2
	createsprite gWhirlwindLineSpriteTemplate, ANIM_ATTACKER, 2, 0, 16, ANIM_TARGET, 60, 3
	createsprite gWhirlwindLineSpriteTemplate, ANIM_ATTACKER, 2, 0, 24, ANIM_TARGET, 60, 4
	createsprite gWhirlwindLineSpriteTemplate, ANIM_ATTACKER, 2, 0, 32, ANIM_TARGET, 60, 0
	delay 5
	loopsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_TARGET, 10, 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 15, 1
	delay 29
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_TARGET, 12, 6, 1, 5
	delay 7
	playsewithpan SE_M_STRING_SHOT, SOUND_PAN_TARGET
	createvisualtask AnimTask_SlideOffScreen, 5, ANIM_TARGET, 8
	waitforvisualfinish
	end

Move_CONFUSE_RAY: @ 0x0827A41D
	loadspritegfx ANIM_TAG_YELLOW_BALL
	monbg ANIM_DEF_PARTNER
	fadetobg BG_GHOST
	waitbgfadein
	createvisualtask SoundTask_AdjustPanningVar, 2, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, 2, 0
	blend_color_cyclebytag tag=ANIM_TAG_YELLOW_BALL, delay=0, num_blends=6, initial_blend_y=0, target_blend_y=14, color=RGB(31, 10, 0)
	createsprite gConfuseRayBallBounceSpriteTemplate, ANIM_TARGET, 2, 28, 0, 288
	waitforvisualfinish
	setalpha 8, 8
	playsewithpan SE_M_STRING_SHOT2, SOUND_PAN_TARGET
	createsprite gConfuseRayBallSpiralSpriteTemplate, ANIM_TARGET, 2, 0, -16
	waitforvisualfinish
	delay 0
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	restorebg
	waitbgfadein
	end

Move_LOCK_ON: @ 0x0827A470
	loadspritegfx ANIM_TAG_LOCK_ON
	createsprite gLockOnTargetSpriteTemplate, ANIM_ATTACKER, 40
	createsprite gLockOnMoveTargetSpriteTemplate, ANIM_ATTACKER, 40, 1
	createsprite gLockOnMoveTargetSpriteTemplate, ANIM_ATTACKER, 40, 2
	createsprite gLockOnMoveTargetSpriteTemplate, ANIM_ATTACKER, 40, 3
	createsprite gLockOnMoveTargetSpriteTemplate, ANIM_ATTACKER, 40, 4
	delay 120
	setarg 7, 0xFFFF
	waitforvisualfinish
	end

Move_MEAN_LOOK: @ 0x0827A4A6
	loadspritegfx ANIM_TAG_EYE
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_M_PSYBEAM, SOUND_PAN_ATTACKER
	simple_palette_blend selector=F_PAL_BG, delay=1, initial_blend_y=0, target_blend_y=16, color=RGB_BLACK
	loopsewithpan SE_M_CONFUSE_RAY, SOUND_PAN_TARGET, 15, 4
	waitplaysewithpan SE_M_LEER, SOUND_PAN_TARGET, 85
	createsprite gMeanLookEyeSpriteTemplate, ANIM_ATTACKER, 2
	delay 120
	simple_palette_blend selector=F_PAL_BG, delay=2, initial_blend_y=16, target_blend_y=0, color=RGB_BLACK
	delay 30
	clearmonbg ANIM_DEF_PARTNER
	waitforvisualfinish
	end

Move_ROCK_THROW:: @ 0x0827A4EB
	loadspritegfx ANIM_TAG_ROCKS
	shake_mon_or_platform unused_anim_battler=ANIM_TARGET, velocity=6, shake_timer=1, shake_duration=15, type=SHAKE_BG_Y
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, 0, 1, 0, 0
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 6
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, 19, 1, 10, 0
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 6
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, -23, 2, -10, 0
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 5, 20, 1
	delay 6
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, -15, 1, -10, 0
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 6
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, 23, 2, 10, 0
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	waitforvisualfinish
	end

Move_ROCK_SLIDE:: @ 0x0827A577
	loadspritegfx ANIM_TAG_ROCKS
	monbg ANIM_DEF_PARTNER
	shake_mon_or_platform velocity=7, shake_timer=1, shake_duration=11, type=SHAKE_BG_Y
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, -5, 1, -5, 1
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 2
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, 5, 0, 6, 1
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 2
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, 19, 1, 10, 1
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 2
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, -23, 2, -10, 1
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 5, 50, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_DEF_PARTNER, 0, 5, 50, 1
	delay 2
	call RockSlideRocks
	call RockSlideRocks
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

RockSlideRocks:
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, -20, 0, -10, 1
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 2
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, 28, 1, 10, 1
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 2
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, -10, 1, -5, 1
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 2
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, 10, 0, 6, 1
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 2
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, 24, 1, 10, 1
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 2
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, -32, 2, -10, 1
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 2
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, -20, 0, -10, 1
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 2
	createsprite gFallingRockSpriteTemplate, ANIM_TARGET, 2, 30, 2, 10, 1
	playsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET
	delay 2
	return

Move_THIEF:: @ 0x0827A6B8
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	delay 1
	fadetobg BG_DARK
	waitbgfadein
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 4
	delay 6
	playsewithpan SE_M_VITAL_THROW, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 8, 1
	waitforvisualfinish
	delay 20
	clearmonbg ANIM_TARGET
	blendoff
	restorebg
	waitbgfadein
	end

Move_BUBBLE_BEAM:: @ 0x0827A6FF
	loadspritegfx ANIM_TAG_BUBBLE
	loadspritegfx ANIM_TAG_SMALL_BUBBLES
	monbg ANIM_TARGET
	splitbgprio ANIM_TARGET
	setalpha 12, 8
	delay 1
	call BubblebeamCreateBubbles
	createvisualtask AnimTask_SwayMon, 5, 0, 3, 3072, 8, ANIM_TARGET
	call BubblebeamCreateBubbles
	call BubblebeamCreateBubbles
	waitforvisualfinish
	call WaterBubblesEffectShort
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

BubblebeamCreateBubbles:
	createsprite gWaterBubbleProjectileSpriteTemplate, ANIM_ATTACKER, 2, 18, 0, 35, 70, 0, 256, 50
	playsewithpan SE_M_BUBBLE, SOUND_PAN_ATTACKER
	delay 3
	createsprite gWaterBubbleProjectileSpriteTemplate, ANIM_ATTACKER, 2, 18, 0, 20, 40, -10, 256, 50
	playsewithpan SE_M_BUBBLE, SOUND_PAN_ATTACKER
	delay 3
	createsprite gWaterBubbleProjectileSpriteTemplate, ANIM_ATTACKER, 2, 18, 0, 10, -60, 0, 256, 50
	playsewithpan SE_M_BUBBLE, SOUND_PAN_ATTACKER
	delay 3
	createsprite gWaterBubbleProjectileSpriteTemplate, ANIM_ATTACKER, 2, 18, 0, 15, -15, 10, 256, 50
	playsewithpan SE_M_BUBBLE, SOUND_PAN_ATTACKER
	delay 3
	createsprite gWaterBubbleProjectileSpriteTemplate, ANIM_ATTACKER, 2, 18, 0, 30, 10, -10, 256, 50
	playsewithpan SE_M_BUBBLE, SOUND_PAN_ATTACKER
	delay 3
	createsprite gWaterBubbleProjectileSpriteTemplate, ANIM_ATTACKER, 2, 18, 0, 25, -30, 10, 256, 50
	playsewithpan SE_M_BUBBLE, SOUND_PAN_ATTACKER
	delay 3
	return

Move_ICY_WIND:: @ 0x0827A7DC
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	loadspritegfx ANIM_TAG_ICE_SPIKES
	monbg ANIM_DEF_PARTNER
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG | F_PAL_ATK_SIDE, 4, 0, 4, RGB_BLACK
	fadetobg BG_ICE
	waitbgfadeout
	playsewithpan SE_M_ICY_WIND, 0
	waitbgfadein
	waitforvisualfinish
	panse SE_M_GUST, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	call IcyWindSwirlingSnowballs
	delay 5
	call IcyWindSwirlingSnowballs
	playsewithpan SE_M_GUST2, SOUND_PAN_TARGET
	delay 55
	call IceSpikesEffectLong
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	restorebg
	waitbgfadeout
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG | F_PAL_ATK_SIDE, 4, 4, 0, RGB_BLACK
	waitbgfadein
	end

IcyWindSwirlingSnowballs:
	createsprite gSwirlingSnowballSpriteTemplate, ANIM_TARGET, 40, 0, 0, 0, 0, 72, 1
	delay 5
	createsprite gSwirlingSnowballSpriteTemplate, ANIM_TARGET, 40, 0, 10, 0, 10, 72, 1
	delay 5
	createsprite gSwirlingSnowballSpriteTemplate, ANIM_TARGET, 40, 0, -10, 0, -10, 72, 1
	delay 5
	createsprite gSwirlingSnowballSpriteTemplate, ANIM_TARGET, 40, 0, 15, 0, 15, 72, 1
	delay 5
	createsprite gSwirlingSnowballSpriteTemplate, ANIM_TARGET, 40, 0, -5, 0, -5, 72, 1
	return

Move_SMOKESCREEN:: @ 0x0827A89C
	loadspritegfx ANIM_TAG_BLACK_SMOKE
	loadspritegfx ANIM_TAG_BLACK_BALL
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	createsprite gBlackBallSpriteTemplate, ANIM_TARGET, 2, 20, 0, 0, 0, 35, -25
	waitforvisualfinish
	createvisualtask AnimTask_SmokescreenImpact, 2
	delay 2
	playsewithpan SE_M_SAND_ATTACK, SOUND_PAN_TARGET
	createsprite gBlackSmokeSpriteTemplate, ANIM_TARGET, 4, 0, -12, 104, 0, 75
	createsprite gBlackSmokeSpriteTemplate, ANIM_TARGET, 4, 0, -12, 72, 1, 75
	createsprite gBlackSmokeSpriteTemplate, ANIM_TARGET, 4, 0, -6, 56, 1, 75
	createsprite gBlackSmokeSpriteTemplate, ANIM_TARGET, 4, 0, -6, 88, 0, 75
	createsprite gBlackSmokeSpriteTemplate, ANIM_TARGET, 4, 0, 0, 56, 0, 75
	createsprite gBlackSmokeSpriteTemplate, ANIM_TARGET, 4, 0, 0, 88, 1, 75
	createsprite gBlackSmokeSpriteTemplate, ANIM_TARGET, 4, 0, 6, 72, 0, 75
	createsprite gBlackSmokeSpriteTemplate, ANIM_TARGET, 4, 0, 6, 104, 1, 75
	createsprite gBlackSmokeSpriteTemplate, ANIM_TARGET, 4, 0, 12, 72, 0, 75
	createsprite gBlackSmokeSpriteTemplate, ANIM_TARGET, 4, 0, 12, 56, 1, 75
	createsprite gBlackSmokeSpriteTemplate, ANIM_TARGET, 4, 0, 18, 80, 0, 75
	createsprite gBlackSmokeSpriteTemplate, ANIM_TARGET, 4, 0, 18, 72, 1, 75
	waitforvisualfinish
	end

Move_CONVERSION:: @ 0x0827A995
	loadspritegfx ANIM_TAG_CONVERSION
	monbg ANIM_ATK_PARTNER
	splitbgprio ANIM_ATTACKER
	setalpha 16, 0
	delay 0
	playsewithpan SE_M_SWIFT, SOUND_PAN_ATTACKER
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, -24, -24
	delay 3
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, -8, -24
	delay 3
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, 8, -24
	delay 3
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, 24, -24
	delay 3
	playsewithpan SE_M_SWIFT, SOUND_PAN_ATTACKER
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, -24, -8
	delay 3
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, -8, -8
	delay 3
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, 8, -8
	delay 3
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, 24, -8
	delay 3
	playsewithpan SE_M_SWIFT, SOUND_PAN_ATTACKER
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, -24, 8
	delay 3
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, -8, 8
	delay 3
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, 8, 8
	delay 3
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, 24, 8
	delay 3
	playsewithpan SE_M_SWIFT, SOUND_PAN_ATTACKER
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, -24, 24
	delay 3
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, -8, 24
	delay 3
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, 8, 24
	delay 3
	createsprite gConversionSpriteTemplate, ANIM_ATTACKER, 2, 24, 24
	delay 20
	playsewithpan SE_M_BARRIER, SOUND_PAN_ATTACKER
	flash_anim_tag_with_color tag=ANIM_TAG_CONVERSION, delay=1, num_blends=1, color1=RGB(31, 31, 13), blend_y1=12, color2=RGB_BLACK, blend_y2=0
	delay 6
	createvisualtask AnimTask_ConversionAlphaBlend, 5
	waitforvisualfinish
	delay 1
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

Move_CONVERSION_2:: @ 0x0827AAAA
	loadspritegfx ANIM_TAG_CONVERSION
	monbg ANIM_DEF_PARTNER
	splitbgprio_foes ANIM_TARGET
	setalpha 0, 16
	delay 0
	playsewithpan SE_M_BARRIER, SOUND_PAN_TARGET
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, -24, -24, 60
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, -8, -24, 65
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, 8, -24, 70
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, 24, -24, 75
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, -24, -8, 80
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, -8, -8, 85
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, 8, -8, 90
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, 24, -8, 95
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, -24, 8, 100
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, -8, 8, 105
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, 8, 8, 110
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, 24, 8, 115
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, -24, 24, 120
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, -8, 24, 125
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, 8, 24, 130
	createsprite gConversion2SpriteTemplate, ANIM_ATTACKER, 2, 24, 24, 135
	createvisualtask AnimTask_Conversion2AlphaBlend, 5
	delay 60
	playsewithpan SE_M_SWIFT, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_M_SWIFT, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_M_SWIFT, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_M_SWIFT, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_M_SWIFT, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_M_SWIFT, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_M_SWIFT, SOUND_PAN_TARGET
	delay 10
	playsewithpan SE_M_SWIFT, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_ROLLING_KICK:: @ 0x0827ABC6
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 18, 6, 1, 4
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 6
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, 0, 0, 4
	createsprite gSlidingKickSpriteTemplate, ANIM_ATTACKER, 2, -24, 0, 48, 10, 160, 0
	delay 5
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=-8, y=0, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 1, 8
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_HEADBUTT:: @ 0x0827AC49
	loadspritegfx ANIM_TAG_IMPACT
	createsprite gBowMonSpriteTemplate, ANIM_ATTACKER, 2, 0
	playsewithpan SE_M_HEADBUTT, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 2
	createsprite gBowMonSpriteTemplate, ANIM_ATTACKER, 2, 1
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 4, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	createsprite gBowMonSpriteTemplate, ANIM_ATTACKER, 2, 2
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=1
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	waitforvisualfinish
	end

Move_HORN_ATTACK:: @ 0x0827ACA6
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HORN_HIT
	createsprite gBowMonSpriteTemplate, ANIM_ATTACKER, 2, 0
	playsewithpan SE_M_HEADBUTT, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 2
	createsprite gBowMonSpriteTemplate, ANIM_ATTACKER, 2, 1
	createsprite gHornHitSpriteTemplate, ANIM_TARGET, 4, 0, 0, 10
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 4, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	createsprite gBowMonSpriteTemplate, ANIM_ATTACKER, 2, 2
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=1
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	waitforvisualfinish
	end

Move_FURY_ATTACK:: @ 0x0827AD13
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HORN_HIT
	createvisualtask AnimTask_RotateMonSpriteToSide, 2, 4, 256, ANIM_ATTACKER, 2
	choosetwoturnanim FuryAttackRight, FuryAttackLeft
FuryAttackContinue:
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	waitforvisualfinish
	end

FuryAttackRight:
	createsprite gHornHitSpriteTemplate, ANIM_TARGET, 4, 8, 8, 10
	waitforvisualfinish
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=1
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	goto FuryAttackContinue

FuryAttackLeft:
	createsprite gHornHitSpriteTemplate, ANIM_TARGET, 4, -8, -8, 10
	waitforvisualfinish
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=1
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	goto FuryAttackContinue

Move_HORN_DRILL:: @ 0x0827AD90
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HORN_HIT
	jumpifcontest HornDrillInContest
	fadetobg BG_DRILL
	waitbgfadeout
	createvisualtask AnimTask_StartSlidingBg, 5, -2304, 768, 1, -1
HornDrillContinue:
	waitbgfadein
	setalpha 12, 8
	createsprite gBowMonSpriteTemplate, ANIM_ATTACKER, 2, 0
	playsewithpan SE_M_HEADBUTT, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 2
	createsprite gBowMonSpriteTemplate, ANIM_ATTACKER, 2, 1
	createsprite gHornHitSpriteTemplate, ANIM_TARGET, 4, 0, 0, 12
	waitforvisualfinish
	playse SE_BANG
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 40, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 10, 0, 40, 1
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=3
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	delay 4
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=0, y=2, relative_to=ANIM_TARGET, animation=3
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	delay 4
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=-4, y=3, relative_to=ANIM_TARGET, animation=3
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	delay 4
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=-8, y=-5, relative_to=ANIM_TARGET, animation=3
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	delay 4
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=4, y=-12, relative_to=ANIM_TARGET, animation=3
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	delay 4
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=16, y=0, relative_to=ANIM_TARGET, animation=3
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	delay 4
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=5, y=18, relative_to=ANIM_TARGET, animation=3
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	delay 4
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=-17, y=12, relative_to=ANIM_TARGET, animation=2
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	delay 4
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=-21, y=-15, relative_to=ANIM_TARGET, animation=2
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	delay 4
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=8, y=-27, relative_to=ANIM_TARGET, animation=2
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	delay 4
	create_flashing_hitsplat_sprite ANIM_TARGET, 3, x=32, y=0, relative_to=ANIM_TARGET, animation=2
	playsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET
	delay 4
	createsprite gBowMonSpriteTemplate, ANIM_ATTACKER, 2, 2
	waitforvisualfinish
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	end

HornDrillInContest:
	fadetobg BG_DRILL_CONTESTS
	waitbgfadeout
	createvisualtask AnimTask_StartSlidingBg, 5, 2304, 768, 0, -1
	goto HornDrillContinue

Move_THRASH:: @ 0x0827AF0D
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	createvisualtask AnimTask_ThrashMoveMonHorizontal, 2
	createvisualtask AnimTask_ThrashMoveMonVertical, 2
	createsprite gFistFootRandomPosSpriteTemplate, ANIM_TARGET, 3, 1, 10, 0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 7, 1
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	delay 28
	createsprite gFistFootRandomPosSpriteTemplate, ANIM_TARGET, 3, 1, 10, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 7, 1
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	delay 28
	createsprite gFistFootRandomPosSpriteTemplate, ANIM_TARGET, 3, 1, 10, 3
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 8, 0, 16, 1
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	end

Move_SING:: @ 0x0827AF8C
	loadspritegfx ANIM_TAG_MUSIC_NOTES
	monbg ANIM_DEF_PARTNER
	createvisualtask AnimTask_MusicNotesRainbowBlend, 2
	waitforvisualfinish
	panse SE_M_SING, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 7, 0, 12
	delay 5
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 6, 1, 12
	delay 5
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 1, 2, 12
	delay 5
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 2, 3, 12
	delay 5
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 3, 0, 12
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 2, 1, 12
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 5, 2, 12
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 6, 3, 12
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 2, 0, 12
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 2, 1, 12
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 1, 2, 12
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 5, 3, 12
	delay 4
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	createvisualtask AnimTask_MusicNotesClearRainbowBlend, 2
	waitforvisualfinish
	end

Move_LOW_KICK:: @ 0x0827B060
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_IMPACT
	createsprite gSlideMonToOffsetSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, 0, 0, 4
	createsprite gSlidingKickSpriteTemplate, ANIM_TARGET, 2, -24, 28, 40, 8, 160, 0
	delay 4
	create_basic_hitsplat_sprite ANIM_TARGET, 2, x=-8, y=8, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_RotateMonSpriteToSide, 2, 6, 384, ANIM_TARGET, 2
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, ANIM_ATTACKER, 2, 0, 1, 4
	end

Move_EARTHQUAKE:: @ 0x0827B0BD
	createvisualtask AnimTask_HorizontalShake, 5, (MAX_BATTLERS_COUNT + 1), 10, 50
	createvisualtask AnimTask_HorizontalShake, 5, MAX_BATTLERS_COUNT, 10, 50
	playsewithpan SE_M_EARTHQUAKE, 0
	delay 10
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG, delay=3, num_blends=1, color1=RGB_BLACK, blend_y1=14, color2=RGB_WHITE, blend_y2=14
	delay 16
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG, delay=3, num_blends=1, color1=RGB_BLACK, blend_y1=14, color2=RGB_WHITE, blend_y2=14
	end

Move_FISSURE:: @ 0x0827B10A
	loadspritegfx ANIM_TAG_MUD_SAND
	createvisualtask AnimTask_HorizontalShake, 3, (MAX_BATTLERS_COUNT + 1), 10, 50
	createvisualtask AnimTask_HorizontalShake, 3, ANIM_TARGET, 10, 50
	playsewithpan SE_M_EARTHQUAKE, SOUND_PAN_TARGET
	delay 8
	call FissureDirtPlumeFar
	delay 15
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG, delay=3, num_blends=1, color1=RGB_BLACK, blend_y1=14, color2=RGB_WHITE, blend_y2=14
	delay 15
	call FissureDirtPlumeClose
	delay 15
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG, delay=3, num_blends=1, color1=RGB_BLACK, blend_y1=14, color2=RGB_WHITE, blend_y2=14
	delay 15
	call FissureDirtPlumeFar
	delay 50
	fadetobg BG_FISSURE
	waitbgfadeout
	createvisualtask AnimTask_PositionFissureBgOnBattler, 5, ANIM_TARGET, 5, -1
	waitbgfadein
	delay 40
	restorebg
	waitbgfadeout
	setarg 7, -1
	waitbgfadein
	end

FissureDirtPlumeFar:
	createsprite gDirtPlumeSpriteTemplate, ANIM_TARGET, 2, 1, 0, 12, -48, -16, 24
	createsprite gDirtPlumeSpriteTemplate, ANIM_TARGET, 2, 1, 0, 16, -16, -10, 24
	createsprite gDirtPlumeSpriteTemplate, ANIM_TARGET, 2, 1, 1, 14, -52, -18, 24
	createsprite gDirtPlumeSpriteTemplate, ANIM_TARGET, 2, 1, 1, 12, -32, -16, 24
	playsewithpan SE_M_DIG, SOUND_PAN_TARGET
	return

FissureDirtPlumeClose:
	createsprite gDirtPlumeSpriteTemplate, ANIM_TARGET, 2, 1, 0, 12, -24, -16, 24
	createsprite gDirtPlumeSpriteTemplate, ANIM_TARGET, 2, 1, 0, 16, -38, -10, 24
	createsprite gDirtPlumeSpriteTemplate, ANIM_TARGET, 2, 1, 1, 14, -20, -18, 24
	createsprite gDirtPlumeSpriteTemplate, ANIM_TARGET, 2, 1, 1, 12, -36, -16, 24
	playsewithpan SE_M_DIG, SOUND_PAN_TARGET
	return

Move_DIG:: @ 0x0827B22D
	choosetwoturnanim DigSetUp, DigUnleash
DigEnd:
	end
DigSetUp:
	loadspritegfx ANIM_TAG_MUD_SAND
	loadspritegfx ANIM_TAG_DIRT_MOUND
	createsprite gDirtMoundSpriteTemplate, ANIM_ATTACKER, 1, 0, 0, 180
	createsprite gDirtMoundSpriteTemplate, ANIM_ATTACKER, 1, 0, 1, 180
	monbg_static ANIM_ATTACKER
	delay 1
	createvisualtask AnimTask_DigDownMovement, 2, FALSE
	delay 6
	call DigThrowDirt
	call DigThrowDirt
	call DigThrowDirt
	call DigThrowDirt
	call DigThrowDirt
	waitforvisualfinish
	clearmonbg_static ANIM_ATTACKER
	delay 1
	createvisualtask AnimTask_DigDownMovement, 2, TRUE
	goto DigEnd
DigUnleash:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_DIRT_MOUND
	createvisualtask AnimTask_DigUpMovement, 2, FALSE
	waitforvisualfinish
	monbg ANIM_ATTACKER
	createsprite gDirtMoundSpriteTemplate, ANIM_ATTACKER, 1, 0, 0, 48
	createsprite gDirtMoundSpriteTemplate, ANIM_ATTACKER, 1, 0, 1, 48
	delay 1
	createvisualtask AnimTask_DigUpMovement, 2, TRUE
	delay 16
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=-8, y=0, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_ATTACKER
	clearmonbg ANIM_ATTACKER
	goto DigEnd
DigThrowDirt:
	createsprite gDirtPlumeSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 12, 4, -16, 18
	createsprite gDirtPlumeSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 16, 4, -10, 18
	createsprite gDirtPlumeSpriteTemplate, ANIM_ATTACKER, 2, 0, 1, 14, 4, -18, 18
	createsprite gDirtPlumeSpriteTemplate, ANIM_ATTACKER, 2, 0, 1, 12, 4, -16, 18
	playsewithpan SE_M_DIG, SOUND_PAN_ATTACKER
	delay 32
	return

Move_MEDITATE:: @ 0x0827B349
	call SetPsychicBackground
	createvisualtask AnimTask_MeditateStretchAttacker, 2
	playsewithpan SE_M_HEADBUTT, SOUND_PAN_ATTACKER
	delay 16
	playsewithpan SE_M_TAKE_DOWN, SOUND_PAN_ATTACKER
	waitforvisualfinish
	call UnsetPsychicBackground
	end

Move_AGILITY:: @ 0x0827B366
	monbg ANIM_ATK_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 24, 6, 4, 4
	createvisualtask AnimTask_TraceMonBlended, 2, 0, 4, 7, 10
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 12
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 12
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 12
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 12
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 12
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 1
	end

Move_QUICK_ATTACK:: @ 0x0827B3B0
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_ATK_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 24, 6, 1, 5
	createvisualtask AnimTask_TraceMonBlended, 2, 0, 4, 7, 3
	playsewithpan SE_M_JUMP_KICK, SOUND_PAN_ATTACKER
	delay 4
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	create_basic_hitsplat_sprite ANIM_TARGET, 4, x=0, y=0, relative_to=ANIM_TARGET, animation=1
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	waitforvisualfinish
	end

Move_RAGE:: @ 0x0827B408
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_ANGER
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_BlendMonInAndOut, 3, ANIM_ATTACKER, RGB_RED, 10, 0, 2
	createsprite gAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 0, -20, -28
	playsewithpan SE_M_SWAGGER2, SOUND_PAN_ATTACKER
	delay 20
	createsprite gAngerMarkSpriteTemplate, ANIM_ATTACKER, 2, 0, 20, -28
	playsewithpan SE_M_SWAGGER2, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 6
	delay 4
	create_basic_hitsplat_sprite ANIM_ATTACKER, 2, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeTargetBasedOnMovePowerOrDmg, 2, TRUE, 1, 10, 1, 0
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	end

Move_TELEPORT:: @ 0x0827B47E
	call SetPsychicBackground
	createvisualtask AnimTask_Teleport, 2
	playsewithpan SE_M_TELEPORT, SOUND_PAN_ATTACKER
	delay 15
	call UnsetPsychicBackground
	waitforvisualfinish
	end

Move_DOUBLE_TEAM:: @ 0x0827B497
	createvisualtask AnimTask_DoubleTeam, 2
	setalpha 12, 8
	monbg ANIM_ATK_PARTNER
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 32
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 24
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 16
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 8
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 8
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 8
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 8
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	delay 8
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 1
	end

Move_MINIMIZE:: @ 0x0827B4DE
	setalpha 10, 8
	createvisualtask AnimTask_Minimize, 2
	loopsewithpan SE_M_MINIMIZE, SOUND_PAN_ATTACKER, 34, 3
	waitforvisualfinish
	blendoff
	end

Move_METRONOME:: @ 0x0827B4F1
	loadspritegfx ANIM_TAG_FINGER
	loadspritegfx ANIM_TAG_THOUGHT_BUBBLE
	createsprite gThoughtBubbleSpriteTemplate, ANIM_ATTACKER, 11, 0, 100
	playsewithpan SE_M_METRONOME, SOUND_PAN_ATTACKER
	delay 6
	createsprite gMetronomeFingerSpriteTemplate, ANIM_ATTACKER, 12, 0
	delay 24
	loopsewithpan SE_M_TAIL_WHIP, SOUND_PAN_ATTACKER, 22, 3
	waitforvisualfinish
	end

Move_SKULL_BASH:: @ 0x0827B51B
	choosetwoturnanim SkullBashSetUp, SkullBashAttack
SkullBashEnd:
	end
SkullBashSetUp:
	call SkullBashSetUpHeadDown
	call SkullBashSetUpHeadDown
	waitforvisualfinish
	goto SkullBashEnd
SkullBashSetUpHeadDown:
	createsprite gSlideMonToOffsetAndBackSpriteTemplate, ANIM_ATTACKER, 2, ANIM_ATTACKER, -24, 0, 0, 10, 0
	playsewithpan SE_M_TAKE_DOWN, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask AnimTask_RotateMonSpriteToSide, 2, 16, 96, ANIM_ATTACKER, 2
	waitforvisualfinish
	createsprite gSlideMonToOffsetAndBackSpriteTemplate, ANIM_ATTACKER, 2, ANIM_ATTACKER, 24, 0, 0, 10, 1
	waitforvisualfinish
	return
SkullBashAttack:
	loadspritegfx ANIM_TAG_IMPACT
	createvisualtask AnimTask_SkullBashPosition, 2, 0
	playsewithpan SE_M_TAKE_DOWN, SOUND_PAN_ATTACKER
	waitforvisualfinish
	playse SE_BANG
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG, delay=3, num_blends=1, color1=RGB_BLACK, blend_y1=14, color2=RGB_WHITE, blend_y2=14
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 40, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 10, 0, 40, 1
	create_flashing_hitsplat_sprite ANIM_TARGET, 4, x=0, y=0, relative_to=ANIM_TARGET, animation=0
	loopsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET, 8, 3
	waitforvisualfinish
	createvisualtask AnimTask_SkullBashPosition, 2, 1
	goto SkullBashEnd

Move_AMNESIA:: @ 0x0827B5E1
	loadspritegfx ANIM_TAG_AMNESIA
	call SetPsychicBackground
	delay 8
	createsprite gQuestionMarkSpriteTemplate, ANIM_ATTACKER, 20
	playsewithpan SE_M_METRONOME, SOUND_PAN_ATTACKER
	delay 54
	loopsewithpan SE_M_METRONOME, SOUND_PAN_ATTACKER, 16, 3
	waitforvisualfinish
	call UnsetPsychicBackground
	end

Move_KINESIS:: @ 0x0827B605
	loadspritegfx ANIM_TAG_ALERT
	loadspritegfx ANIM_TAG_BENT_SPOON
	playsewithpan SE_M_PSYBEAM, SOUND_PAN_ATTACKER
	call SetPsychicBackground
	createsprite gBentSpoonSpriteTemplate, ANIM_ATTACKER, 20
	createsprite gKinesisZapEnergySpriteTemplate, ANIM_ATTACKER, 19, 32, -8, 0
	createsprite gKinesisZapEnergySpriteTemplate, ANIM_ATTACKER, 19, 32, 16, 1
	loopsewithpan SE_M_CONFUSE_RAY, SOUND_PAN_ATTACKER, 21, 2
	delay 60
	playsewithpan SE_M_DIZZY_PUNCH, SOUND_PAN_ATTACKER
	delay 30
	loopsewithpan SE_M_DIZZY_PUNCH, SOUND_PAN_ATTACKER, 20, 2
	delay 70
	playsewithpan SE_M_SWAGGER2, SOUND_PAN_ATTACKER
	waitforvisualfinish
	call UnsetPsychicBackground
	end

Move_GLARE:: @ 0x0827B656
	loadspritegfx ANIM_TAG_SMALL_RED_EYE
	loadspritegfx ANIM_TAG_EYE_SPARKLE
	createvisualtask AnimTask_GlareEyeDots, 5, 0
	playsewithpan SE_M_PSYBEAM2, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPal, 5, F_PAL_BG, 0, 0, 16, RGB_BLACK
	waitforvisualfinish
	createsprite gEyeSparkleSpriteTemplate, ANIM_ATTACKER, 0, -16, -8
	createsprite gEyeSparkleSpriteTemplate, ANIM_ATTACKER, 0, 16, -8
	createvisualtask AnimTask_ScaryFace, 5
	playsewithpan SE_M_LEER, SOUND_PAN_ATTACKER
	delay 2
	createvisualtask AnimTask_ShakeTargetInPattern, 3, 20, 1, FALSE
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPal, 5, F_PAL_BG, 0, 16, 0, RGB_BLACK
	end

Move_BARRAGE:: @ 0x0827B6BF
	loadspritegfx ANIM_TAG_RED_BALL
	createvisualtask AnimTask_BarrageBall, 3
	playsewithpan SE_M_SWAGGER, SOUND_PAN_ATTACKER
	delay 24
	shake_mon_or_platform velocity=8, shake_timer=1, shake_duration=40, type=SHAKE_BG_Y
	createvisualtask AnimTask_ShakeMon, 3, ANIM_TARGET, 0, 4, 20, 1
	createvisualtask AnimTask_ShakeMon, 3, ANIM_DEF_PARTNER, 0, 4, 20, 1
	loopsewithpan SE_M_STRENGTH, SOUND_PAN_TARGET, 8, 2
	end

Move_SKY_ATTACK:: @ 0x0827B707
	choosetwoturnanim SkyAttackSetUp, SkyAttackUnleash
SkyAttackEnd:
	end

SkyAttackSetUp:
	monbg ANIM_DEF_PARTNER
	setalpha 12, 11
	createvisualtask AnimTask_GetTargetIsAttackerPartner, 5, ARG_RET_ID
	jumpretfalse SkyAttackSetUpAgainstOpponent
	goto SkyAttackSetUpAgainstPartner

SkyAttackSetUpAgainstOpponent:
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG | F_PAL_ATK_SIDE | F_PAL_DEF_PARTNER, 1, 0, 12, RGB_BLACK
	waitforvisualfinish
	delay 12
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 1, 8, 0, RGB_BLACK
	createvisualtask AnimTask_HorizontalShake, 5, ANIM_ATTACKER, 2, 16
	loopsewithpan SE_M_STAT_INCREASE, SOUND_PAN_ATTACKER, 4, 8
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 1, 0, 15, RGB_WHITE
	delay 20
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 1, 15, 0, RGB_WHITE
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG | F_PAL_ATK_PARTNER | F_PAL_DEF_PARTNER, 1, 8, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto SkyAttackEnd

SkyAttackSetUpAgainstPartner:
	createvisualtask AnimTask_BlendBattleAnimPalExclude, 10, ANIM_TARGET, 1, 0, 12, RGB_BLACK
	waitforvisualfinish
	delay 12
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 1, 8, 0, RGB_BLACK
	createvisualtask AnimTask_HorizontalShake, 5, ANIM_ATTACKER, 2, 16
	playsewithpan SE_M_STAT_INCREASE, SOUND_PAN_ATTACKER
	delay 8
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 1, 0, 15, RGB_WHITE
	delay 20
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 1, 15, 0, RGB_WHITE
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPalExclude, 10, 4, 1, 8, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto SkyAttackEnd

SkyAttackUnleash:
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_BIRD
	call SetSkyBg
	monbg ANIM_ATTACKER
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 0, 0, 16, RGB_WHITE
	delay 4
	attacker_fade_to_invisible priority=5, step_delay=0
	waitforvisualfinish
	createvisualtask SoundTask_PlaySE2WithPanning, 5, SE_M_SKY_UPPERCUT, SOUND_PAN_ATTACKER
	createsprite gSkyAttackBirdSpriteTemplate, ANIM_TARGET, 2
	delay 14
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 10, 0, 18, 1
	createvisualtask SoundTask_PlaySE1WithPanning, 5, SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	delay 20
	attacker_fade_from_invisible priority=5, step_delay=1
	delay 2
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_ATTACKER, 0, 15, 0, RGB_WHITE
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	call UnsetSkyBg
	goto SkyAttackEnd

Move_FLASH:: @ 0x0827B89F
	playsewithpan SE_M_LEER, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_Flash, 2
	waitforvisualfinish
	end

Move_SPLASH:: @ 0x0827B8AC
	createvisualtask AnimTask_Splash, 2, 0, 3
	delay 8
	loopsewithpan SE_M_TAIL_WHIP, SOUND_PAN_ATTACKER, 38, 3
	waitforvisualfinish
	end

Move_ACID_ARMOR:: @ 0x0827B8C1
	monbg ANIM_ATTACKER
	setalpha 15, 0
	createvisualtask AnimTask_AcidArmor, 2, ANIM_ATTACKER
	playsewithpan SE_M_ACID_ARMOR, SOUND_PAN_ATTACKER
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_ATTACKER
	delay 1
	end

Move_SHARPEN:: @ 0x0827B8DA
	loadspritegfx ANIM_TAG_SPHERE_TO_CUBE
	createsprite gSharpenSphereSpriteTemplate, ANIM_ATTACKER, 2
	waitforvisualfinish
	end

Move_SUPER_FANG:: @ 0x0827B8E6
	loadspritegfx ANIM_TAG_FANG_ATTACK
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 1, 0, 20, 1
	playsewithpan SE_M_DRAGON_RAGE, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 3, 0, 48, 1
	createvisualtask AnimTask_BlendMonInAndOut, 2, ANIM_ATTACKER, RGB(31, 6, 1), 12, 4, 1
	waitforvisualfinish
	delay 20
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 4, 4
	delay 4
	createsprite gSuperFangSpriteTemplate, ANIM_TARGET, 2
	playsewithpan SE_M_BITE, SOUND_PAN_TARGET
	delay 8
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG, delay=3, num_blends=1, color1=RGB(31, 2, 2), blend_y1=14, color2=RGB_WHITE, blend_y2=14
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 7, 12, 1
	waitforvisualfinish
	blendoff
	end

Move_SLASH:: @ 0x0827B967
	loadspritegfx ANIM_TAG_SLASH
	createsprite gSlashSliceSpriteTemplate, ANIM_TARGET, 2, 1, -8, 0
	playsewithpan SE_M_RAZOR_WIND, SOUND_PAN_TARGET
	delay 4
	createsprite gSlashSliceSpriteTemplate, ANIM_TARGET, 2, 1, 8, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 18, 1
	playsewithpan SE_M_RAZOR_WIND, SOUND_PAN_TARGET
	waitforvisualfinish
	end

Move_STRUGGLE:: @ 0x0827B9A1
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_MOVEMENT_WAVES
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 3, 0, 12, 4
	createsprite gMovementWavesSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 2
	createsprite gMovementWavesSpriteTemplate, ANIM_ATTACKER, 2, 0, 1, 2
	loopsewithpan SE_M_HEADBUTT, SOUND_PAN_ATTACKER, 12, 4
	waitforvisualfinish
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SKETCH:: @ 0x0827BA07
	loadspritegfx ANIM_TAG_PENCIL
	monbg ANIM_TARGET
	createvisualtask AnimTask_SketchDrawMon, 2
	createsprite gPencilSpriteTemplate, ANIM_TARGET, 2
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	createvisualtask AnimTask_Splash, 2, 0, 2
	loopsewithpan SE_M_TAIL_WHIP, SOUND_PAN_ATTACKER, 38, 2
	end

Move_NIGHTMARE:: @ 0x0827BA2F
	fadetobg BG_GHOST
	waitbgfadein
	jumpifcontest NightmareInContest
	monbg ANIM_DEF_PARTNER
	createvisualtask AnimTask_NightmareClone, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 40, 1
	playsewithpan SE_M_NIGHTMARE, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	restorebg
	waitbgfadein
	end

NightmareInContest:
	createvisualtask AnimTask_BlendMonInAndOut, 2, ANIM_ATTACKER, RGB_WHITE, 10, 2, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 3, 0, 32, 1
	playsewithpan SE_M_NIGHTMARE, SOUND_PAN_TARGET
	waitforvisualfinish
	restorebg
	waitbgfadein
	end

Move_FLAIL:: @ 0x0827BA85
	loadspritegfx ANIM_TAG_IMPACT
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_FlailMovement, 2, ANIM_ATTACKER
	loopsewithpan SE_M_HEADBUTT, SOUND_PAN_ATTACKER, 8, 2
	waitforvisualfinish
	create_random_pos_hitsplat_sprite ANIM_TARGET, 3, ANIM_TARGET, 3
	createvisualtask AnimTask_ShakeTargetBasedOnMovePowerOrDmg, 2, FALSE, 1, 30, 1, 0
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SPITE:: @ 0x0827BAC2
	fadetobg BG_GHOST
	playsewithpan SE_M_PSYBEAM, SOUND_PAN_ATTACKER
	waitbgfadein
	monbg ANIM_DEF_PARTNER
	blend_color_cycle priority=2, selector=F_PAL_ATTACKER, delay=2, num_blends=6, initial_blend_y=0, target_blend_y=8, color=RGB_WHITE
	createvisualtask AnimTask_SpiteTargetShadow, 2
	loopsewithpan SE_M_PSYBEAM, SOUND_PAN_TARGET, 20, 3
	waitforvisualfinish
	restorebg
	waitbgfadein
	clearmonbg ANIM_TARGET
	end

Move_MACH_PUNCH:: @ 0x0827BAF1
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	monbg ANIM_ATK_PARTNER
	createvisualtask AnimTask_GetAttackerSide, 2
	jumprettrue MachPunchAgainstPlayer
	fadetobg BG_HIGHSPEED_OPPONENT
MachPunchContinue:
	waitbgfadeout
	createvisualtask AnimTask_StartSlidingBg, 5, -2304, 0, 1, -1
	waitbgfadein
	delay 0
	setalpha 9, 8
	createvisualtask AnimTask_AttackerPunchWithTrace, 2, RGB(8, 9, 28), 10
	playsewithpan SE_M_JUMP_KICK, SOUND_PAN_ATTACKER
	delay 6
	create_basic_hitsplat_sprite ANIM_TARGET, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=1
	create_fist_sprite ANIM_TARGET, 4, x=0, y=0, duration=8
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	end
MachPunchAgainstPlayer:
	fadetobg BG_HIGHSPEED_PLAYER
	goto MachPunchContinue

Move_FORESIGHT:: @ 0x0827BB79
	loadspritegfx ANIM_TAG_MAGNIFYING_GLASS
	monbg ANIM_DEF_PARTNER
	splitbgprio ANIM_TARGET
	setalpha 16, 0
	createsprite gForesightMagnifyingGlassSpriteTemplate, ANIM_TARGET, 2, ANIM_TARGET
	delay 17
	loopsewithpan SE_M_SKETCH, SOUND_PAN_TARGET, 16, 4
	delay 48
	delay 24
	playsewithpan SE_M_SKETCH, SOUND_PAN_TARGET
	delay 10
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_TARGET, RGB_WHITE, 12, 2, 1
	playsewithpan SE_M_DETECT, SOUND_PAN_TARGET
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	end

Move_DESTINY_BOND:: @ 0x0827BBB8
	loadspritegfx ANIM_TAG_WHITE_SHADOW
	fadetobg BG_GHOST
	playsewithpan SE_M_PSYBEAM, SOUND_PAN_ATTACKER
	waitbgfadein
	createvisualtask AnimTask_DestinyBondWhiteShadow, 5, 0, 48
	playsewithpan SE_M_CONFUSE_RAY, SOUND_PAN_ATTACKER
	delay 48
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 24, 1
	createvisualtask AnimTask_BlendBattleAnimPalExclude, 2, 6, 1, 0, 12, RGB(29, 29, 29)
	delay 24
	createvisualtask AnimTask_BlendBattleAnimPalExclude, 2, 6, 1, 12, 0, RGB(29, 29, 29)
	playsewithpan SE_M_NIGHTMARE, SOUND_PAN_TARGET
	waitforvisualfinish
	restorebg
	waitbgfadein
	blendoff
	clearmonbg 5
	end

Move_ENDURE:: @ 0x0827BC13
	loadspritegfx ANIM_TAG_FOCUS_ENERGY
	playsewithpan SE_M_DRAGON_RAGE, SOUND_PAN_ATTACKER
	call EndureEffect
	delay 8
	blend_color_cycle priority=2, selector=F_PAL_ATTACKER, delay=2, num_blends=2, initial_blend_y=0, target_blend_y=11, color=RGB_RED
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 32, 1
	call EndureEffect
	delay 8
	call EndureEffect
	waitforvisualfinish
	end

EndureEffect:
	createsprite gEndureEnergySpriteTemplate, ANIM_ATTACKER, 2, 0, -24, 26, 2
	delay 4
	createsprite gEndureEnergySpriteTemplate, ANIM_ATTACKER, 2, 0, 14, 28, 1
	delay 4
	createsprite gEndureEnergySpriteTemplate, ANIM_ATTACKER, 2, 0, -5, 10, 2
	delay 4
	createsprite gEndureEnergySpriteTemplate, ANIM_ATTACKER, 2, 0, 28, 26, 3
	delay 4
	createsprite gEndureEnergySpriteTemplate, ANIM_ATTACKER, 2, 0, -12, 0, 1
	return

Move_CHARM:: @ 0x0827BCA7
	loadspritegfx ANIM_TAG_MAGENTA_HEART
	createvisualtask AnimTask_RockMonBackAndForth, 5, ANIM_ATTACKER, 2, 0
	createsprite gMagentaHeartSpriteTemplate, ANIM_ATTACKER, 3, 0, 20
	playsewithpan SE_M_CHARM, SOUND_PAN_ATTACKER
	delay 15
	createsprite gMagentaHeartSpriteTemplate, ANIM_ATTACKER, 3, -20, 20
	playsewithpan SE_M_CHARM, SOUND_PAN_ATTACKER
	delay 15
	createsprite gMagentaHeartSpriteTemplate, ANIM_ATTACKER, 3, 20, 20
	playsewithpan SE_M_CHARM, SOUND_PAN_ATTACKER
	waitforvisualfinish
	end

Move_ROLLOUT:: @ 0x0827BCEA
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_MUD_SAND
	loadspritegfx ANIM_TAG_ROCKS
	monbg ANIM_DEF_PARTNER
	splitbgprio ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_Rollout, 2
	waitforvisualfinish
	createvisualtask AnimTask_ShakeTargetBasedOnMovePowerOrDmg, 2, FALSE, 1, 30, 1, 0
	create_basic_hitsplat_sprite ANIM_ATTACKER, 4, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_FALSE_SWIPE:: @ 0x0827BD2B
	loadspritegfx ANIM_TAG_SLASH_2
	loadspritegfx ANIM_TAG_IMPACT
	createsprite gFalseSwipeSliceSpriteTemplate, ANIM_TARGET, 2
	playsewithpan SE_M_VITAL_THROW, SOUND_PAN_TARGET
	delay 16
	createsprite gFalseSwipePositionedSliceSpriteTemplate, ANIM_TARGET, 2, 0
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_TARGET
	delay 2
	createsprite gFalseSwipePositionedSliceSpriteTemplate, ANIM_TARGET, 2, 16
	delay 2
	createsprite gFalseSwipePositionedSliceSpriteTemplate, ANIM_TARGET, 2, 32
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_TARGET
	delay 2
	createsprite gFalseSwipePositionedSliceSpriteTemplate, ANIM_TARGET, 2, 48
	delay 2
	createsprite gFalseSwipePositionedSliceSpriteTemplate, ANIM_TARGET, 2, 64
	playsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_TARGET
	delay 2
	createsprite gFalseSwipePositionedSliceSpriteTemplate, ANIM_TARGET, 2, 80
	delay 2
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	create_basic_hitsplat_sprite ANIM_TARGET, 4, x=0, y=0, relative_to=ANIM_TARGET, animation=3
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	end

Move_SWAGGER:: @ 0x0827BDB2
	loadspritegfx ANIM_TAG_BREATH
	loadspritegfx ANIM_TAG_ANGER
	createvisualtask AnimTask_GrowAndShrink, 2
	playsewithpan SE_M_SWAGGER, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gBreathPuffSpriteTemplate, ANIM_ATTACKER, 2
	loopsewithpan SE_M_SWAGGER, SOUND_PAN_ATTACKER, 4, 2
	waitforvisualfinish
	delay 24
	createsprite gAngerMarkSpriteTemplate, ANIM_TARGET, 2, 1, -20, -28
	playsewithpan SE_M_SWAGGER2, SOUND_PAN_TARGET
	delay 12
	createsprite gAngerMarkSpriteTemplate, ANIM_TARGET, 2, 1, 20, -28
	playsewithpan SE_M_SWAGGER2, SOUND_PAN_TARGET
	waitforvisualfinish
	end

Move_MILK_DRINK:: @ 0x0827BDFA
	loadspritegfx ANIM_TAG_MILK_BOTTLE
	loadspritegfx ANIM_TAG_THIN_RING
	loadspritegfx ANIM_TAG_BLUE_STAR
	monbg ANIM_TARGET
	createsprite gMilkBottleSpriteTemplate, ANIM_ATTACKER, 2
	delay 40
	playsewithpan SE_M_CRABHAMMER, SOUND_PAN_ATTACKER
	delay 12
	playsewithpan SE_M_CRABHAMMER, SOUND_PAN_ATTACKER
	delay 20
	playsewithpan SE_M_CRABHAMMER, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gThinRingExpandingSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 1, 0
	playsewithpan SE_M_MILK_DRINK, SOUND_PAN_ATTACKER
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	call HealingEffect2
	waitforvisualfinish
	end

Move_MAGNITUDE:: @ 0x0827BE3C
	createvisualtask AnimTask_IsPowerOver99, 2
	waitforvisualfinish
.ifdef UBFIX
	jumpreteq FALSE, MagnitudeRegular
	jumpreteq TRUE, MagnitudeIntense
.else
	jumpargeq 15, FALSE, MagnitudeRegular
	jumpargeq 15, TRUE, MagnitudeIntense
.endif

MagnitudeEnd:
	end
MagnitudeRegular:
	createvisualtask AnimTask_HorizontalShake, 5, (MAX_BATTLERS_COUNT + 1), 0, 50
	createvisualtask AnimTask_HorizontalShake, 5, MAX_BATTLERS_COUNT, 0, 50
	loopsewithpan SE_M_STRENGTH, SOUND_PAN_TARGET, 8, 10
	goto MagnitudeEnd
MagnitudeIntense:
	createvisualtask AnimTask_HorizontalShake, 5, (MAX_BATTLERS_COUNT + 1), 0, 50
	createvisualtask AnimTask_HorizontalShake, 5, MAX_BATTLERS_COUNT, 0, 50
	loopsewithpan SE_M_STRENGTH, SOUND_PAN_TARGET, 8, 10
	delay 10
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG, delay=3, num_blends=1, color1=RGB_BLACK, blend_y1=14, color2=RGB_WHITE, blend_y2=14
	delay 16
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG, delay=3, num_blends=1, color1=RGB_BLACK, blend_y1=14, color2=RGB_WHITE, blend_y2=14
	goto MagnitudeEnd

Move_RAPID_SPIN:: @ 0x0827BECD
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_RAPID_SPIN
	monbg ANIM_ATTACKER
	createsprite gRapidSpinSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, 32, -32, 40, -2
	createvisualtask AnimTask_RapinSpinMonElevation, 2, 0, 2, 0
	loopsewithpan SE_M_RAZOR_WIND2, SOUND_PAN_ATTACKER, 8, 4
	waitforvisualfinish
	create_basic_hitsplat_sprite ANIM_TARGET, 2, x=0, y=0, relative_to=ANIM_TARGET, animation=2
	createvisualtask AnimTask_ShakeTargetBasedOnMovePowerOrDmg, 2, FALSE, 1, 10, 1, 0
	playsewithpan SE_M_DOUBLE_SLAP, SOUND_PAN_TARGET
	waitforvisualfinish
	delay 8
	createvisualtask AnimTask_RapinSpinMonElevation, 2, 0, 2, 1
	loopsewithpan SE_M_RAZOR_WIND2, SOUND_PAN_ATTACKER, 8, 4
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	end

Move_MOONLIGHT:: @ 0x0827BF3A
	loadspritegfx ANIM_TAG_MOON
	loadspritegfx ANIM_TAG_GREEN_SPARKLE
	loadspritegfx ANIM_TAG_BLUE_STAR
	setalpha 0, 16
	simple_palette_blend selector=F_PAL_BG, delay=1, initial_blend_y=0, target_blend_y=16, color=RGB_BLACK
	waitforvisualfinish
	createsprite gMoonSpriteTemplate, ANIM_ATTACKER, 2, 120, 56
	createvisualtask AnimTask_AlphaFadeIn, 3, 0, 16, 16, 0, 1
	playsewithpan SE_M_MOONLIGHT, 0
	delay 30
	createsprite gMoonlightSparkleSpriteTemplate, ANIM_ATTACKER, 40, -12, 0
	delay 30
	createsprite gMoonlightSparkleSpriteTemplate, ANIM_ATTACKER, 40, -24, 0
	delay 30
	createsprite gMoonlightSparkleSpriteTemplate, ANIM_ATTACKER, 40, 21, 0
	delay 30
	createsprite gMoonlightSparkleSpriteTemplate, ANIM_ATTACKER, 40, 0, 0
	delay 30
	createsprite gMoonlightSparkleSpriteTemplate, ANIM_ATTACKER, 40, 10, 0
	delay 20
	createvisualtask AnimTask_MoonlightEndFade, 2
	waitforvisualfinish
	call HealingEffect
	waitforvisualfinish
	end

Move_EXTREME_SPEED:: @ 0x0827BFCA
	loadspritegfx ANIM_TAG_SPEED_DUST
	loadspritegfx ANIM_TAG_IMPACT
	createvisualtask AnimTask_GetAttackerSide, 2
	jumprettrue ExtremeSpeedAgainstPlayer
	fadetobg BG_HIGHSPEED_OPPONENT
ExtremeSpeedContinue:
	waitbgfadeout
	createvisualtask AnimTask_StartSlidingBg, 5, -2304, 0, 1, -1
	waitbgfadein
	createvisualtask AnimTask_AttackerStretchAndDisappear, 2
	loopsewithpan SE_M_RAZOR_WIND2, SOUND_PAN_ATTACKER, 8, 3
	waitforvisualfinish
	delay 1
	createvisualtask AnimTask_SetAttackerInvisibleWaitForSignal, 2
	monbg ANIM_TARGET
	setalpha 12, 8
	delay 18
	createvisualtask AnimTask_ExtremeSpeedImpact, 2
	delay 2
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	create_mon_edge_hitsplat_sprite ANIM_TARGET, 2, relative_to=ANIM_TARGET, x=0, y=-12, animation=3
	delay 10
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	create_mon_edge_hitsplat_sprite ANIM_TARGET, 2, relative_to=ANIM_TARGET, x=0, y=12, animation=3
	delay 10
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	create_mon_edge_hitsplat_sprite ANIM_TARGET, 2, relative_to=ANIM_TARGET, x=0, y=0, animation=3
	waitforvisualfinish
	createvisualtask AnimTask_SpeedDust, 2
	delay 10
	createvisualtask AnimTask_ExtremeSpeedMonReappear, 2
	loopsewithpan SE_M_DOUBLE_TEAM, SOUND_PAN_ATTACKER, 8, 4
	waitforvisualfinish
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	setarg 7, 0x1000
	delay 1
	end
ExtremeSpeedAgainstPlayer:
	fadetobg BG_HIGHSPEED_PLAYER
	goto ExtremeSpeedContinue

Move_UPROAR:: @ 0x0827C088
	loadspritegfx ANIM_TAG_JAGGED_MUSIC_NOTE
	loadspritegfx ANIM_TAG_THIN_RING
	monbg ANIM_DEF_PARTNER
	createvisualtask AnimTask_UproarDistortion, 2, 0
	createsprite gUproarRingSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_M_UPROAR, SOUND_PAN_ATTACKER
	createsprite gJaggedMusicNoteSpriteTemplate, ANIM_ATTACKER, 2, 0, 29, -12, 0
	createsprite gJaggedMusicNoteSpriteTemplate, ANIM_ATTACKER, 2, 0, -12, -29, 1
	delay 16
	createvisualtask AnimTask_UproarDistortion, 2, 0
	createsprite gUproarRingSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_M_UPROAR, SOUND_PAN_ATTACKER
	createsprite gJaggedMusicNoteSpriteTemplate, ANIM_ATTACKER, 2, 0, 12, -29, 1
	createsprite gJaggedMusicNoteSpriteTemplate, ANIM_ATTACKER, 2, 0, -29, -12, 0
	delay 16
	createvisualtask AnimTask_UproarDistortion, 2, 0
	createsprite gUproarRingSpriteTemplate, ANIM_ATTACKER, 3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_M_UPROAR, SOUND_PAN_ATTACKER
	createsprite gJaggedMusicNoteSpriteTemplate, ANIM_ATTACKER, 2, 0, 24, -24, 1
	createsprite gJaggedMusicNoteSpriteTemplate, ANIM_ATTACKER, 2, 0, -24, -24, 0
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_HEAT_WAVE:: @ 0x0827C152
	loadspritegfx ANIM_TAG_FLYING_DIRT
	createvisualtask AnimTask_BlendParticle, 5, ANIM_TAG_FLYING_DIRT, 0, 6, 6, RGB_RED
	createvisualtask AnimTask_LoadSandstormBackground, 5, TRUE
	createvisualtask AnimTask_BlendBackground, 6, 6, RGB_RED
	panse SE_M_HEAT_WAVE, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	delay 4
	createvisualtask AnimTask_MoveHeatWaveTargets, 5
	delay 12
	createsprite gFlyingSandCrescentSpriteTemplate, ANIM_ATTACKER, 40, 10, 2304, 96, 1
	delay 10
	createsprite gFlyingSandCrescentSpriteTemplate, ANIM_ATTACKER, 40, 90, 2048, 96, 1
	delay 10
	createsprite gFlyingSandCrescentSpriteTemplate, ANIM_ATTACKER, 40, 50, 2560, 96, 1
	delay 10
	createsprite gFlyingSandCrescentSpriteTemplate, ANIM_ATTACKER, 40, 20, 2304, 96, 1
	delay 10
	createsprite gFlyingSandCrescentSpriteTemplate, ANIM_ATTACKER, 40, 70, 1984, 96, 1
	delay 10
	createsprite gFlyingSandCrescentSpriteTemplate, ANIM_ATTACKER, 40, 0, 2816, 96, 1
	delay 10
	createsprite gFlyingSandCrescentSpriteTemplate, ANIM_ATTACKER, 40, 60, 2560, 96, 1
	end

Move_HAIL:: @ 0x0827C202
	loadspritegfx ANIM_TAG_HAIL
	loadspritegfx ANIM_TAG_ICE_CRYSTALS
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 3, 0, 6, RGB_BLACK
	waitforvisualfinish
	createvisualtask AnimTask_Hail, 5
	loopsewithpan SE_M_HAIL, 0, 8, 10
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_BG, 3, 6, 0, RGB_BLACK
	end

Move_TORMENT:: @ 0x0827C23A
	loadspritegfx ANIM_TAG_ANGER
	loadspritegfx ANIM_TAG_THOUGHT_BUBBLE
	createvisualtask AnimTask_TormentAttacker, 2
	waitforvisualfinish
	createvisualtask AnimTask_BlendMonInAndOut, 2, ANIM_TARGET, RGB_RED, 10, 1, 1
	createsprite gAngerMarkSpriteTemplate, ANIM_TARGET, 2, 1, -20, -28
	playsewithpan SE_M_SWAGGER2, SOUND_PAN_TARGET
	delay 20
	createsprite gAngerMarkSpriteTemplate, ANIM_TARGET, 2, 1, 20, -28
	playsewithpan SE_M_SWAGGER2, SOUND_PAN_TARGET
	end

Move_MEMENTO:: @ 0x0827C27E
	setalpha 0, 16
	delay 1
	createvisualtask AnimTask_InitMementoShadow, 2
	delay 1
	createvisualtask AnimTask_MoveAttackerMementoShadow, 5
	playsewithpan SE_M_PSYBEAM, SOUND_PAN_ATTACKER
	delay 48
	playsewithpan SE_M_PSYBEAM2, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createvisualtask AnimTask_MementoHandleBg, 2
	delay 12
	setalpha 0, 16
	delay 1
	monbg_static ANIM_TARGET
	createvisualtask AnimTask_MoveTargetMementoShadow, 5
	playsewithpan SE_M_PSYBEAM, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg_static ANIM_TARGET
	delay 1
	blendoff
	delay 1
	end

Move_FACADE:: @ 0x0827C2C2
	loadspritegfx ANIM_TAG_SWEAT_DROP
	createvisualtask AnimTask_SquishAndSweatDroplets, 2, ANIM_ATTACKER, 3
	createvisualtask AnimTask_FacadeColorBlend, 2, ANIM_ATTACKER, 72
	loopsewithpan SE_M_SWAGGER, SOUND_PAN_ATTACKER, 24, 3
	end

Move_SMELLING_SALT:: @ 0x0827C2E2
	loadspritegfx ANIM_TAG_TAG_HAND
	loadspritegfx ANIM_TAG_SMELLINGSALT_EFFECT
	createsprite gSmellingSaltsHandSpriteTemplate, ANIM_TARGET, 2, ANIM_TARGET, 0, 2
	createsprite gSmellingSaltsHandSpriteTemplate, ANIM_TARGET, 2, ANIM_TARGET, 1, 2
	delay 32
	createvisualtask AnimTask_SmellingSaltsSquish, 3, ANIM_TARGET, 2
	loopsewithpan SE_M_DOUBLE_SLAP, SOUND_PAN_TARGET, 12, 2
	waitforvisualfinish
	delay 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 6, 2
	createsprite gSmellingSaltExclamationSpriteTemplate, ANIM_TARGET, 2, ANIM_TARGET, 8, 3
	loopsewithpan SE_M_SWAGGER2, SOUND_PAN_TARGET, 16, 3
	end

Move_FOLLOW_ME:: @ 0x0827C33D
	loadspritegfx ANIM_TAG_FINGER
	createsprite gFollowMeFingerSpriteTemplate, ANIM_ATTACKER, 2, 0
	playsewithpan SE_M_TAIL_WHIP, SOUND_PAN_ATTACKER
	delay 18
	playsewithpan SE_M_ATTRACT, SOUND_PAN_ATTACKER
	delay 71
	loopsewithpan SE_M_TAIL_WHIP, SOUND_PAN_ATTACKER, 22, 3
	end

Move_CHARGE:: @ 0x0827C35C
	loadspritegfx ANIM_TAG_ELECTRIC_ORBS
	loadspritegfx ANIM_TAG_CIRCLE_OF_LIGHT
	loadspritegfx ANIM_TAG_ELECTRICITY
	monbg ANIM_ATTACKER
	setalpha 12, 8
	simple_palette_blend selector=F_PAL_BG, delay=2, initial_blend_y=0, target_blend_y=4, color=RGB_BLACK
	waitforvisualfinish
	createvisualtask AnimTask_ElectricChargingParticles, 2, ANIM_ATTACKER, 60, 2, 12
	playsewithpan SE_M_CHARGE, SOUND_PAN_ATTACKER
	delay 30
	playsewithpan SE_M_CHARGE, SOUND_PAN_ATTACKER
	delay 30
	playsewithpan SE_M_CHARGE, SOUND_PAN_ATTACKER
	createsprite gGrowingChargeOrbSpriteTemplate, ANIM_ATTACKER, 2, 0
	delay 25
	playsewithpan SE_M_CHARGE, SOUND_PAN_ATTACKER
	delay 20
	playsewithpan SE_M_CHARGE, SOUND_PAN_ATTACKER
	delay 15
	playsewithpan SE_M_CHARGE, SOUND_PAN_ATTACKER
	delay 10
	delay 6
	loopsewithpan SE_M_CHARGE, SOUND_PAN_ATTACKER, 6, 5
	waitforvisualfinish
	create_electric_puff_sprite ANIM_ATTACKER, 2, relative_to=0, x=16, y=16
	delay 2
	create_electric_puff_sprite ANIM_ATTACKER, 2, relative_to=0, x=-16, y=-16
	playsewithpan SE_M_THUNDERBOLT2, SOUND_PAN_ATTACKER
	waitforvisualfinish
	simple_palette_blend selector=F_PAL_BG, delay=4, initial_blend_y=4, target_blend_y=0, color=RGB_BLACK
	clearmonbg ANIM_ATTACKER
	blendoff
	end

Move_TAUNT:: @ 0x0827C3F7
	loadspritegfx ANIM_TAG_FINGER_2
	loadspritegfx ANIM_TAG_THOUGHT_BUBBLE
	loadspritegfx ANIM_TAG_ANGER
	createsprite gThoughtBubbleSpriteTemplate, ANIM_ATTACKER, 11, 0, 45
	playsewithpan SE_M_METRONOME, SOUND_PAN_ATTACKER
	delay 6
	createsprite gTauntFingerSpriteTemplate, ANIM_ATTACKER, 12, 0
	delay 4
	loopsewithpan SE_M_TAIL_WHIP, SOUND_PAN_ATTACKER, 16, 2
	waitforvisualfinish
	delay 8
	createsprite gAngerMarkSpriteTemplate, ANIM_TARGET, 2, 1, -20, -28
	playsewithpan SE_M_SWAGGER2, SOUND_PAN_TARGET
	waitforvisualfinish
	delay 12
	createsprite gAngerMarkSpriteTemplate, ANIM_TARGET, 2, 1, 20, -28
	playsewithpan SE_M_SWAGGER2, SOUND_PAN_TARGET
	end

Move_HELPING_HAND:: @ 0x0827C44B
	loadspritegfx ANIM_TAG_TAG_HAND
	createvisualtask AnimTask_HelpingHandAttackerMovement, 5
	createsprite gHelpingHandClapSpriteTemplate, ANIM_ATTACKER, 40, 0
	createsprite gHelpingHandClapSpriteTemplate, ANIM_ATTACKER, 40, 1
	delay 19
	playsewithpan SE_M_ENCORE, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATK_PARTNER, 2, 0, 5, 1
	delay 14
	playsewithpan SE_M_ENCORE, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATK_PARTNER, 2, 0, 5, 1
	delay 20
	playsewithpan SE_M_ENCORE, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATK_PARTNER, 3, 0, 10, 1
	createvisualtask AnimTask_BlendMonInAndOut, 2, ANIM_ATK_PARTNER, RGB_YELLOW, 12, 1, 1
	end

Move_ASSIST:: @ 0x0827C4BE
	loadspritegfx ANIM_TAG_PAW_PRINT
	createsprite gAssistPawprintSpriteTemplate, ANIM_ATTACKER, 50, 112, -16, 140, 128, 36
	delay 2
	createsprite gAssistPawprintSpriteTemplate, ANIM_ATTACKER, 50, 208, 128, -16, 48, 36
	playsewithpan SE_M_SCRATCH, 0
	delay 2
	createsprite gAssistPawprintSpriteTemplate, ANIM_ATTACKER, 50, -16, 112, 256, -16, 36
	playsewithpan SE_M_SCRATCH, 0
	delay 2
	createsprite gAssistPawprintSpriteTemplate, ANIM_ATTACKER, 50, 108, 128, 84, -16, 36
	playsewithpan SE_M_SCRATCH, 0
	delay 2
	createsprite gAssistPawprintSpriteTemplate, ANIM_ATTACKER, 50, -16, 56, 256, 56, 36
	playsewithpan SE_M_SCRATCH, 0
	end

Move_SUPERPOWER:: @ 0x0827C52F
	loadspritegfx ANIM_TAG_CIRCLE_OF_LIGHT
	loadspritegfx ANIM_TAG_METEOR
	loadspritegfx ANIM_TAG_FLAT_ROCK
	monbg ANIM_ATK_PARTNER
	splitbgprio ANIM_ATTACKER
	setalpha 12, 8
	createsprite gSuperpowerOrbSpriteTemplate, ANIM_TARGET, 2, ANIM_ATTACKER
	playsewithpan SE_M_MEGA_KICK, SOUND_PAN_ATTACKER
	delay 20
	shake_mon_or_platform velocity=4, shake_timer=1, shake_duration=180, type=SHAKE_BG_Y
	createvisualtask SoundTask_PlaySE2WithPanning, 5, SE_M_EARTHQUAKE, 0
	delay 40
	createsprite gSuperpowerRockSpriteTemplate, ANIM_ATTACKER, 41, 200, 96, 1, 120
	delay 8
	createsprite gSuperpowerRockSpriteTemplate, ANIM_ATTACKER, 41, 20, 248, 4, 112
	delay 8
	createsprite gSuperpowerRockSpriteTemplate, ANIM_ATTACKER, 41, 130, 160, 2, 104
	delay 8
	createsprite gSuperpowerRockSpriteTemplate, ANIM_ATTACKER, 41, 160, 192, 0, 96
	delay 8
	createsprite gSuperpowerRockSpriteTemplate, ANIM_ATTACKER, 41, 60, 288, 3, 88
	delay 74
	createsprite gSuperpowerFireballSpriteTemplate, ANIM_TARGET, 3, ANIM_ATTACKER
	playsewithpan SE_M_SWAGGER, SOUND_PAN_ATTACKER
	delay 16
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 8, 0, 16, 1
	playsewithpan SE_M_MEGA_KICK2, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 1
	end

Move_RECYCLE:: @ 0x0827C5EA
	loadspritegfx ANIM_TAG_RECYCLE
	monbg ANIM_ATTACKER
	setalpha 0, 16
	delay 1
	createsprite gRecycleSpriteTemplate, ANIM_ATTACKER, 2
	loopsewithpan SE_M_TAKE_DOWN, SOUND_PAN_ATTACKER, 24, 3
	waitforvisualfinish
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB_WHITE, 12, 2, 1
	playsewithpan SE_M_TAKE_DOWN, SOUND_PAN_ATTACKER
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_ATTACKER
	delay 1
	end

Move_BRICK_BREAK:: @ 0x0827C61E
	loadspritegfx ANIM_TAG_BLUE_LIGHT_WALL
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loadspritegfx ANIM_TAG_TORN_METAL
	choosetwoturnanim BrickBreakNormal, BrickBreakShatteredWall

BrickBreakNormal:
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 3, 8
	delay 4
	delay 1
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=-18, y=-18, relative_to=ANIM_TARGET, animation=1
	playsewithpan SE_M_VITAL_THROW, SOUND_PAN_TARGET
	delay 20
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 3, 8
	delay 5
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=18, y=18, relative_to=ANIM_TARGET, animation=1
	playsewithpan SE_M_VITAL_THROW, SOUND_PAN_TARGET
	delay 20
	createvisualtask AnimTask_WindUpLunge, 2, ANIM_ATTACKER, -24, 0, 24, 10, 24, 3
	simple_palette_blend selector=F_PAL_BG, delay=2, initial_blend_y=0, target_blend_y=6, color=RGB_BLACK
	delay 37
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=1
	create_fist_sprite ANIM_ATTACKER, 4, x=0, y=0, duration=10
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	waitforvisualfinish
	simple_palette_blend selector=F_PAL_BG, delay=2, initial_blend_y=6, target_blend_y=0, color=RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	end

BrickBreakShatteredWall:
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 3, 8
	delay 4
	createsprite gBrickBreakWallSpriteTemplate, ANIM_ATTACKER, 3, ANIM_TARGET, 0, 0, 90, 10
	delay 1
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=-18, y=-18, relative_to=ANIM_TARGET, animation=1
	playsewithpan SE_M_VITAL_THROW, SOUND_PAN_TARGET
	delay 20
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 3, 8
	delay 5
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=18, y=18, relative_to=ANIM_TARGET, animation=1
	playsewithpan SE_M_VITAL_THROW, SOUND_PAN_TARGET
	delay 20
	createvisualtask AnimTask_WindUpLunge, 2, ANIM_ATTACKER, -24, 0, 24, 10, 24, 3
	simple_palette_blend selector=F_PAL_BG, delay=2, initial_blend_y=0, target_blend_y=6, color=RGB_BLACK
	delay 37
	create_basic_hitsplat_sprite ANIM_ATTACKER, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=1
	create_fist_sprite ANIM_ATTACKER, 4, x=0, y=0, duration=10
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	waitforvisualfinish
	createsprite gBrickBreakWallShardSpriteTemplate, ANIM_ATTACKER, 2, ANIM_TARGET, 0, -8, -12
	createsprite gBrickBreakWallShardSpriteTemplate, ANIM_ATTACKER, 2, ANIM_TARGET, 1, 8, -12
	createsprite gBrickBreakWallShardSpriteTemplate, ANIM_ATTACKER, 2, ANIM_TARGET, 2, -8, 12
	createsprite gBrickBreakWallShardSpriteTemplate, ANIM_ATTACKER, 2, ANIM_TARGET, 3, 8, 12
	playsewithpan SE_M_BRICK_BREAK, SOUND_PAN_TARGET
	waitforvisualfinish
	simple_palette_blend selector=F_PAL_BG, delay=2, initial_blend_y=6, target_blend_y=0, color=RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	end

Move_YAWN:: @ 0x0827C7DF
	loadspritegfx ANIM_TAG_PINK_CLOUD
	createvisualtask AnimTask_DeepInhale, 2, ANIM_ATTACKER
	playsewithpan SE_M_YAWN, SOUND_PAN_ATTACKER
	waitforvisualfinish
	createsprite gYawnCloudSpriteTemplate, ANIM_TARGET, 5, 2
	playsewithpan SE_M_SPIT_UP, SOUND_PAN_ATTACKER
	delay 4
	createsprite gYawnCloudSpriteTemplate, ANIM_TARGET, 5, 1
	delay 4
	createsprite gYawnCloudSpriteTemplate, ANIM_TARGET, 5, 0
	waitforvisualfinish
	createvisualtask AnimTask_DeepInhale, 2, ANIM_TARGET
	playsewithpan SE_M_YAWN, SOUND_PAN_TARGET
	end

Move_ENDEAVOR:: @ 0x0827C822
	loadspritegfx ANIM_TAG_SWEAT_DROP
	loadspritegfx ANIM_TAG_IMPACT
	createvisualtask AnimTask_SquishAndSweatDroplets, 2, ANIM_ATTACKER, 2
	loopsewithpan SE_M_TAIL_WHIP, SOUND_PAN_ATTACKER, 24, 2
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB(31, 21, 0), 12, 1, 2
	delay 6
	createvisualtask AnimTask_ShakeTargetBasedOnMovePowerOrDmg, 5, FALSE, 1, 8, 1, 0
	create_basic_hitsplat_sprite ANIM_TARGET, 2, x=12, y=-12, relative_to=ANIM_TARGET, animation=2
	playsewithpan SE_M_DOUBLE_SLAP, SOUND_PAN_TARGET
	delay 24
	createvisualtask AnimTask_ShakeTargetBasedOnMovePowerOrDmg, 5, FALSE, 1, 8, 1, 0
	create_basic_hitsplat_sprite ANIM_TARGET, 2, x=-12, y=12, relative_to=ANIM_TARGET, animation=2
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	end

Move_ERUPTION:: @ 0x0827C897
	loadspritegfx ANIM_TAG_WARM_ROCK
	simple_palette_blend selector=F_PAL_BG | F_PAL_BATTLERS, delay=2, initial_blend_y=0, target_blend_y=4, color=RGB_RED
	waitforvisualfinish
	createvisualtask AnimTask_EruptionLaunchRocks, 2
	waitplaysewithpan SE_M_EXPLOSION, SOUND_PAN_ATTACKER, 60
	waitforvisualfinish
	createvisualtask AnimTask_EruptionLaunchRocks, 2
	waitplaysewithpan SE_M_EXPLOSION, SOUND_PAN_ATTACKER, 60
	waitforvisualfinish
	delay 30
	createsprite gEruptionFallingRockSpriteTemplate, ANIM_ATTACKER, 40, 200, -32, 0, 100, 0
	createsprite gEruptionFallingRockSpriteTemplate, ANIM_ATTACKER, 40, 30, -32, 16, 90, 1
	createsprite gEruptionFallingRockSpriteTemplate, ANIM_ATTACKER, 40, 150, -32, 32, 60, 2
	createsprite gEruptionFallingRockSpriteTemplate, ANIM_ATTACKER, 40, 90, -32, 48, 80, 3
	createsprite gEruptionFallingRockSpriteTemplate, ANIM_ATTACKER, 40, 110, -32, 64, 50, 0
	createsprite gEruptionFallingRockSpriteTemplate, ANIM_ATTACKER, 40, 60, -32, 80, 70, 1
	delay 22
	createvisualtask AnimTask_HorizontalShake, 5, (MAX_BATTLERS_COUNT + 1), 8, 60
	createvisualtask AnimTask_HorizontalShake, 5, MAX_BATTLERS_COUNT, 8, 60
	loopsewithpan SE_M_ROCK_THROW, SOUND_PAN_TARGET, 16, 12
	delay 80
	simple_palette_blend unused_subpriority_offset=40, selector=F_PAL_BG | F_PAL_BATTLERS, delay=4, initial_blend_y=4, target_blend_y=0, color=RGB_RED
	end

Move_SKILL_SWAP:: @ 0x0827C964
	loadspritegfx ANIM_TAG_BLUEGREEN_ORB
	call SetPsychicBackground
	createvisualtask AnimTask_SkillSwap, 3, ANIM_TARGET
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_TARGET, RGB_WHITE, 12, 3, 1
	loopsewithpan SE_M_REVERSAL, SOUND_PAN_ATTACKER, 24, 3
	delay 16
	createvisualtask AnimTask_SkillSwap, 3, ANIM_ATTACKER
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB_WHITE, 12, 3, 1
	waitforvisualfinish
	call UnsetPsychicBackground
	end

Move_IMPRISON:: @ 0x0827C9AF
	loadspritegfx ANIM_TAG_HOLLOW_ORB
	loadspritegfx ANIM_TAG_X_SIGN
	call SetPsychicBackground
	monbg ANIM_DEF_PARTNER
	createvisualtask AnimTask_ImprisonOrbs, 5
	delay 8
	loopsewithpan SE_M_HORN_ATTACK, SOUND_PAN_ATTACKER, 8, 5
	waitforvisualfinish
	delay 4
	createsprite gRedXSpriteTemplate, ANIM_ATTACKER, 5, ANIM_ATTACKER, 40
	createvisualtask AnimTask_HorizontalShake, 5, MAX_BATTLERS_COUNT, 1, 10
	playsewithpan SE_M_HYPER_BEAM, SOUND_PAN_ATTACKER
	clearmonbg ANIM_DEF_PARTNER
	call UnsetPsychicBackground
	end

Move_GRUDGE:: @ 0x0827C9F2
	loadspritegfx ANIM_TAG_PURPLE_FLAME
	monbg ANIM_ATTACKER
	splitbgprio_all
	fadetobg BG_GHOST
	playsewithpan SE_M_PSYBEAM, SOUND_PAN_ATTACKER
	waitbgfadein
	createvisualtask AnimTask_GrudgeFlames, 3
	loopsewithpan SE_M_EMBER, SOUND_PAN_ATTACKER, 16, 4
	delay 10
	delay 80
	playsewithpan SE_M_NIGHTMARE, SOUND_PAN_TARGET
	waitforvisualfinish
	restorebg
	waitbgfadein
	clearmonbg ANIM_ATTACKER
	end

Move_CAMOUFLAGE:: @ 0x0827CA1A
	monbg ANIM_ATK_PARTNER
	splitbgprio ANIM_ATTACKER
	setalpha 16, 0
	createvisualtask AnimTask_SetCamouflageBlend, 5, F_PAL_ATTACKER, 3, 0, 14
	delay 16
	attacker_fade_to_invisible step_delay=4
	playsewithpan SE_M_FAINT_ATTACK, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 8
	createvisualtask AnimTask_SetCamouflageBlend, 5, F_PAL_ATTACKER, 0, 0, 0
	waitforvisualfinish
	attacker_fade_from_invisible step_delay=1
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_ATK_PARTNER
	end

Move_TAIL_GLOW:: @ 0x0827CA60
	loadspritegfx ANIM_TAG_CIRCLE_OF_LIGHT
	monbg ANIM_ATTACKER
	setalpha 12, 8
	simple_palette_blend selector=F_PAL_BG, delay=2, initial_blend_y=0, target_blend_y=4, color=RGB_BLACK
	waitforvisualfinish
	create_tail_glow_orb_sprite ANIM_ATTACKER, 66, relative_to=ANIM_ATTACKER
	delay 18
	loopsewithpan SE_M_MORNING_SUN, SOUND_PAN_ATTACKER, 16, 6
	waitforvisualfinish
	simple_palette_blend selector=F_PAL_BG, delay=4, initial_blend_y=4, target_blend_y=0, color=RGB_BLACK
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 1
	end

Move_LUSTER_PURGE:: @ 0x0827CAA3
	loadspritegfx ANIM_TAG_WHITE_CIRCLE_OF_LIGHT
	loadspritegfx ANIM_TAG_IMPACT
	fadetobg BG_PSYCHIC
	waitbgfadeout
	createvisualtask AnimTask_FadeScreenToWhite, 5
	waitbgfadein
	monbg ANIM_ATTACKER
	setalpha 12, 8
	playsewithpan SE_M_SOLAR_BEAM, SOUND_PAN_ATTACKER
	createsprite gLusterPurgeCircleSpriteTemplate, ANIM_ATTACKER, 41, 0, 0, 0, 0
	delay 20
	createvisualtask AnimTask_BlendBattleAnimPalExclude, 5, 5, 2, 0, 16, RGB_WHITEALPHA
	createvisualtask AnimTask_BlendParticle, 5, ANIM_TAG_WHITE_CIRCLE_OF_LIGHT, 2, 0, 16, RGB_WHITEALPHA
	waitforvisualfinish
	createvisualtask AnimTask_BlendParticle, 5, ANIM_TAG_IMPACT, 0, 12, 12, RGB(0, 0, 23)
	waitforvisualfinish
	create_random_pos_hitsplat_sprite ANIM_TARGET, 3, relative_to=ANIM_TARGET, animation=2
	createvisualtask SoundTask_PlaySE1WithPanning, 5, SE_M_HYPER_BEAM, SOUND_PAN_TARGET
	delay 3
	create_random_pos_hitsplat_sprite ANIM_TARGET, 3, relative_to=ANIM_TARGET, animation=2
	createvisualtask SoundTask_PlaySE1WithPanning, 5, SE_M_HYPER_BEAM, SOUND_PAN_TARGET
	delay 3
	create_random_pos_hitsplat_sprite ANIM_TARGET, 3, relative_to=ANIM_TARGET, animation=2
	createvisualtask SoundTask_PlaySE1WithPanning, 5, SE_M_HYPER_BEAM, SOUND_PAN_TARGET
	delay 3
	create_random_pos_hitsplat_sprite ANIM_TARGET, 3, relative_to=ANIM_TARGET, animation=2
	createvisualtask SoundTask_PlaySE1WithPanning, 5, SE_M_HYPER_BEAM, SOUND_PAN_TARGET
	delay 3
	create_random_pos_hitsplat_sprite ANIM_TARGET, 3, relative_to=ANIM_TARGET, animation=2
	createvisualtask SoundTask_PlaySE1WithPanning, 5, SE_M_HYPER_BEAM, SOUND_PAN_TARGET
	delay 3
	create_random_pos_hitsplat_sprite ANIM_TARGET, 3, relative_to=ANIM_TARGET, animation=2
	createvisualtask SoundTask_PlaySE1WithPanning, 5, SE_M_HYPER_BEAM, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_BlendBattleAnimPalExclude, 5, 5, 2, 16, 0, RGB_WHITEALPHA
	createvisualtask AnimTask_HorizontalShake, 5, ANIM_TARGET, 5, 14
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	call UnsetPsychicBackground
	end

Move_MIST_BALL:: @ 0x0827CBBA
	loadspritegfx ANIM_TAG_SMALL_BUBBLES
	loadspritegfx ANIM_TAG_WHITE_FEATHER
	delay 0
	playsewithpan SE_M_STRING_SHOT, SOUND_PAN_ATTACKER
	createsprite gMistBallSpriteTemplate, ANIM_TARGET, 0, 0, 0, 0, 0, 30, 0
	waitforvisualfinish
	playsewithpan SE_M_SAND_ATTACK, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 10, 0
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=0, selector=F_PAL_BG, delay=1, num_blends=1, color1=RGB(23, 16, 31), blend_y1=16, color2=RGB_WHITE, blend_y2=16
	delay 0
	playsewithpan SE_M_HAZE, 0
	createvisualtask AnimTask_MistBallFog, 5
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_TARGET, 3, 0, 16, RGB_WHITE
	delay 8
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 4, 0, 70, 0
	delay 70
	createvisualtask AnimTask_BlendBattleAnimPal, 10, F_PAL_TARGET, 2, 16, 0, RGB_WHITE
	end

Move_FEATHER_DANCE:: @ 0x0827CC49
	loadspritegfx ANIM_TAG_WHITE_FEATHER
	monbg ANIM_DEF_PARTNER
	splitbgprio_all
	playsewithpan SE_M_PETAL_DANCE, SOUND_PAN_TARGET
	delay 0
	createsprite gFallingFeatherSpriteTemplate, ANIM_TARGET, 0, 0, -16, 64, 2, 104, 11304, 32, 1
	delay 6
	createsprite gFallingFeatherSpriteTemplate, ANIM_TARGET, 0, 0, -16, 32, 2, 104, 11304, 32, 1
	createsprite gFallingFeatherSpriteTemplate, ANIM_TARGET, 0, 0, -16, 0, 2, 104, 11304, 32, 1
	delay 6
	createsprite gFallingFeatherSpriteTemplate, ANIM_TARGET, 0, 0, -16, 224, 2, 104, 11304, 32, 1
	createsprite gFallingFeatherSpriteTemplate, ANIM_TARGET, 0, 0, -16, 128, 2, 104, 11304, 32, 1
	delay 6
	createsprite gFallingFeatherSpriteTemplate, ANIM_TARGET, 0, 0, -16, 192, 2, 104, 11304, 32, 1
	createsprite gFallingFeatherSpriteTemplate, ANIM_TARGET, 0, 0, -16, 160, 2, 104, 11304, 32, 1
	delay 6
	createsprite gFallingFeatherSpriteTemplate, ANIM_TARGET, 0, 0, -16, 96, 2, 104, 11304, 32, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_TEETER_DANCE: @ 0x0827CD19
	loadspritegfx ANIM_TAG_MUSIC_NOTES
	loadspritegfx ANIM_TAG_DUCK
	createvisualtask AnimTask_TeeterDanceMovement, 5
	createsprite gFastFlyingMusicNotesSpriteTemplate, ANIM_ATTACKER, 2, 0, 16, -2
	playsewithpan SE_M_TEETER_DANCE, SOUND_PAN_ATTACKER
	delay 24
	createsprite gFastFlyingMusicNotesSpriteTemplate, ANIM_ATTACKER, 2, 0, 0, -2
	playsewithpan SE_M_TEETER_DANCE, SOUND_PAN_ATTACKER
	delay 24
	createsprite gFastFlyingMusicNotesSpriteTemplate, ANIM_ATTACKER, 2, 0, -16, -2
	playsewithpan SE_M_TEETER_DANCE, SOUND_PAN_ATTACKER
	delay 24
	createsprite gFastFlyingMusicNotesSpriteTemplate, ANIM_ATTACKER, 2, 1, -8, -2
	playsewithpan SE_M_TEETER_DANCE, SOUND_PAN_ATTACKER
	delay 24
	createsprite gFastFlyingMusicNotesSpriteTemplate, ANIM_ATTACKER, 2, 2, 8, -2
	playsewithpan SE_M_TEETER_DANCE, SOUND_PAN_ATTACKER
	end

Move_MUD_SPORT: @ 0x0827CD84
	loadspritegfx ANIM_TAG_MUD_SAND
	createvisualtask AnimTask_Splash, 2, 0, 6
	delay 24
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 0, -4, -16
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 0, 4, -12
	playsewithpan SE_M_DIG, SOUND_PAN_ATTACKER
	delay 32
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 0, -3, -12
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 0, 5, -14
	playsewithpan SE_M_DIG, SOUND_PAN_ATTACKER
	delay 32
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 0, -5, -18
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 0, 3, -14
	playsewithpan SE_M_DIG, SOUND_PAN_ATTACKER
	delay 16
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 1, 220, 60
	waitplaysewithpan SE_M_BUBBLE2, 0, 15
	delay 2
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 1, 60, 100
	waitplaysewithpan SE_M_BUBBLE2, 0, 25
	delay 2
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 1, 140, 55
	waitplaysewithpan SE_M_BUBBLE2, 0, 14
	delay 2
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 1, 180, 50
	waitplaysewithpan SE_M_BUBBLE2, 0, 10
	delay 2
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 1, 20, 90
	waitplaysewithpan SE_M_BUBBLE2, 0, 22
	delay 2
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 1, 90, 90
	waitplaysewithpan SE_M_BUBBLE2, 0, 22
	delay 2
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 1, 160, 60
	waitplaysewithpan SE_M_BUBBLE2, 0, 15
	delay 2
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 1, 30, 90
	waitplaysewithpan SE_M_BUBBLE2, 0, 22
	delay 2
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 1, 120, 60
	waitplaysewithpan SE_M_BUBBLE2, 0, 15
	delay 2
	createsprite gMudsportMudSpriteTemplate, ANIM_TARGET, 2, 1, 200, 40
	waitplaysewithpan SE_M_BUBBLE2, 0, 10
	end

Move_NEEDLE_ARM: @ 0x0827CEBB
	loadspritegfx ANIM_TAG_GREEN_SPIKE
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	loopsewithpan SE_M_HORN_ATTACK, SOUND_PAN_TARGET, 2, 16
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 0, 0, -32, 16
	delay 2
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 0, 22, -22, 16
	delay 2
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 0, 30, 0, 16
	delay 2
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 0, 20, 20, 16
	delay 2
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 0, 0, 28, 16
	delay 2
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 0, -19, 19, 16
	delay 2
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 0, -27, 0, 16
	delay 2
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 0, -18, -18, 16
	delay 2
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 0, 0, -25, 16
	delay 2
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 0, 17, -17, 16
	delay 2
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 0, 23, 0, 16
	delay 2
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 0, 16, 16, 16
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 18, 1
	create_basic_hitsplat_sprite ANIM_TARGET, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=1
	create_fist_sprite ANIM_TARGET, 4, x=0, y=0, duration=8
	playsewithpan SE_M_VITAL_THROW2, SOUND_PAN_TARGET
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 1, 0, -24, 10
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 1, 17, -17, 10
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 1, 24, 0, 10
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 1, 17, 17, 10
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 1, 0, 24, 10
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 1, -17, 17, 10
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 1, -24, 0, 10
	createsprite gNeedleArmSpikeSpriteTemplate, ANIM_TARGET, 2, 1, 1, -17, -17, 10
	end

Move_SLACK_OFF: @ 0x0827D06B
	loadspritegfx ANIM_TAG_BLUE_STAR
	createvisualtask AnimTask_SlackOffSquish, 2, ANIM_ATTACKER
	playsewithpan SE_M_YAWN, SOUND_PAN_ATTACKER
	waitforvisualfinish
	call HealingEffect
	waitforvisualfinish
	end

Move_CRUSH_CLAW: @ 0x0827D083
	loadspritegfx ANIM_TAG_BLUE_LIGHT_WALL
	loadspritegfx ANIM_TAG_CLAW_SLASH
	loadspritegfx ANIM_TAG_TORN_METAL
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 6, 4
	delay 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 18, 1
	create_claw_slash_sprite ANIM_TARGET, 2, x=-10, y=-10, animation=0
	create_claw_slash_sprite ANIM_TARGET, 2, x=-10, y=10, animation=0
	playsewithpan SE_M_RAZOR_WIND, SOUND_PAN_TARGET
	delay 12
	create_claw_slash_sprite ANIM_TARGET, 2, x=10, y=-10, animation=1
	create_claw_slash_sprite ANIM_TARGET, 2, x=10, y=10, animation=1
	playsewithpan SE_M_RAZOR_WIND, SOUND_PAN_TARGET
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_TARGET
	end

Move_AROMATHERAPY: @ 0x0827D0F2
	playsewithpan SE_M_PETAL_DANCE, 0
	loadspritegfx ANIM_TAG_FLOWER
	loadspritegfx ANIM_TAG_THIN_RING
	loadspritegfx ANIM_TAG_SPARKLE_2
	simple_palette_blend unused_subpriority_offset=0, selector=F_PAL_BG, delay=0, initial_blend_y=0, target_blend_y=7, color=RGB(13, 31, 12)
	delay 1
	monbg ANIM_ATTACKER
	delay 1
	createsprite gAromatherapySmallFlowerSpriteTemplate, ANIM_ATTACKER, 0, 24, 16, 0, 2, 2, 0, 0
	createsprite gAromatherapySmallFlowerSpriteTemplate, ANIM_ATTACKER, 66, 64, 24, 0, 3, 1, 1, 0
	createsprite gAromatherapyBigFlowerSpriteTemplate, ANIM_ATTACKER, 0, 16, 24, 0, 2, 1, 0, 0
	delay 20
	createsprite gAromatherapySmallFlowerSpriteTemplate, ANIM_ATTACKER, 66, 48, 12, 0, 4, 3, 1, 0
	createsprite gAromatherapySmallFlowerSpriteTemplate, ANIM_ATTACKER, 0, 100, 16, 0, 3, 2, 0, 0
	createsprite gAromatherapySmallFlowerSpriteTemplate, ANIM_ATTACKER, 0, 74, 24, 180, 3, 2, 0, 0
	delay 10
	createsprite gAromatherapySmallFlowerSpriteTemplate, ANIM_ATTACKER, 66, 80, 30, 0, 4, 1, 1, 0
	createsprite gAromatherapySmallFlowerSpriteTemplate, ANIM_ATTACKER, 0, 128, 12, 0, 3, 3, 0, 0
	createsprite gAromatherapyBigFlowerSpriteTemplate, ANIM_ATTACKER, 0, 90, 16, 0, 2, 1, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 1
	simple_palette_blend unused_subpriority_offset=0, selector=F_PAL_BG, delay=0, initial_blend_y=7, target_blend_y=0, color=RGB(13, 31, 12)
	delay 1
	playsewithpan SE_M_STAT_INCREASE, SOUND_PAN_ATTACKER
	createvisualtask AnimTask_StatusClearedEffect, 2, 1
	waitforvisualfinish
	playsewithpan SE_M_MORNING_SUN, SOUND_PAN_ATTACKER
	createsprite gSparklingStarsSpriteTemplate, ANIM_ATTACKER, 16, -15, 0, 0, 0, 32, 60, 1
	delay 8
	createsprite gSparklingStarsSpriteTemplate, ANIM_ATTACKER, 16, 12, -5, 0, 0, 32, 60, 1
	waitforvisualfinish
	playsewithpan SE_SHINY, SOUND_PAN_ATTACKER
	simple_palette_blend unused_subpriority_offset=0, selector=F_PAL_BG | F_PAL_ATK_SIDE | F_PAL_ANIM_1, delay=3, initial_blend_y=10, target_blend_y=0, color=RGB(13, 31, 12)
	createsprite gBlendThinRingExpandingSpriteTemplate, ANIM_ATTACKER, 16, 0, 0, 0, 1
	waitforvisualfinish
	end

Move_FAKE_TEARS: @ 0x0827D254
	loadspritegfx ANIM_TAG_SMALL_BUBBLES
	loadspritegfx ANIM_TAG_THOUGHT_BUBBLE
	loadspritegfx ANIM_TAG_MUSIC_NOTES
	createvisualtask AnimTask_BlendParticle, 5, ANIM_TAG_SMALL_BUBBLES, 0, 4, 4, RGB(12, 11, 31)
	waitforvisualfinish
	createvisualtask AnimTask_RockMonBackAndForth, 5, ANIM_ATTACKER, 2, 1
	loopsewithpan SE_M_TAIL_WHIP, SOUND_PAN_ATTACKER, 12, 4
	delay 8
	create_tear_drop_sprite ANIM_ATTACKER, 2, relative_to=ANIM_ATTACKER, type=0
	create_tear_drop_sprite ANIM_ATTACKER, 2, relative_to=ANIM_ATTACKER, type=1
	delay 8
	create_tear_drop_sprite ANIM_ATTACKER, 2, relative_to=ANIM_ATTACKER, type=2
	create_tear_drop_sprite ANIM_ATTACKER, 2, relative_to=ANIM_ATTACKER, type=3
	delay 8
	create_tear_drop_sprite ANIM_ATTACKER, 2, relative_to=ANIM_ATTACKER, type=0
	create_tear_drop_sprite ANIM_ATTACKER, 2, relative_to=ANIM_ATTACKER, type=1
	delay 8
	create_tear_drop_sprite ANIM_ATTACKER, 2, relative_to=ANIM_ATTACKER, type=2
	create_tear_drop_sprite ANIM_ATTACKER, 2, relative_to=ANIM_ATTACKER, type=3
	waitforvisualfinish
	end

Move_AIR_CUTTER: @ 0x0827D2E4
	loadspritegfx ANIM_TAG_AIR_WAVE
	loadspritegfx ANIM_TAG_CUT
	loadspritegfx ANIM_TAG_IMPACT
	delay 0
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	delay 0
	createvisualtask AnimTask_AirCutterProjectile, 2, 32, -24, 6 * 256, 2, 128
	waitforvisualfinish
	playsewithpan SE_M_CUT, SOUND_PAN_TARGET
	createsprite gAirCutterSliceSpriteTemplate, ANIM_ATTACKER, 2, 40, -32, 0, 2
	delay 5
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 2, 0, 8, 1
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	delay 0
	end

Move_ODOR_SLEUTH: @ 0x0827D346
	monbg ANIM_TARGET
	createvisualtask AnimTask_OdorSleuthMovement, 5
	delay 24
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 3, 4
	playsewithpan SE_M_SWAGGER, SOUND_PAN_ATTACKER
	delay 6
	createsprite gHorizontalLungeSpriteTemplate, ANIM_ATTACKER, 2, 3, 4
	playsewithpan SE_M_SWAGGER, SOUND_PAN_ATTACKER
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	delay 1
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG, delay=3, num_blends=1, color1=RGB_WHITEALPHA, blend_y1=16, color2=RGB_WHITEALPHA, blend_y2=0
	playsewithpan SE_M_LEER, SOUND_PAN_ATTACKER
	end

Move_GRASS_WHISTLE: @ 0x0827D390
	loadspritegfx ANIM_TAG_MUSIC_NOTES
	simple_palette_blend selector=F_PAL_BG, delay=2, initial_blend_y=0, target_blend_y=4, color=RGB(18, 31, 12)
	waitforvisualfinish
	createvisualtask AnimTask_MusicNotesRainbowBlend, 2
	waitforvisualfinish
	panse SE_M_GRASSWHISTLE, SOUND_PAN_ATTACKER, SOUND_PAN_TARGET, +2, 0
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 7, 1, 0
	delay 5
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 6, 1, 0
	delay 5
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 1, 1, 0
	delay 5
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 2, 1, 0
	delay 5
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 3, 1, 0
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 2, 1, 0
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 5, 1, 0
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 6, 1, 0
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 2, 1, 0
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 2, 1, 0
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 1, 1, 0
	delay 4
	createsprite gWavyMusicNotesSpriteTemplate, ANIM_TARGET, 2, 5, 1, 0
	delay 4
	waitforvisualfinish
	createvisualtask AnimTask_MusicNotesClearRainbowBlend, 2
	simple_palette_blend selector=F_PAL_BG, delay=4, initial_blend_y=4, target_blend_y=0, color=RGB(18, 31, 12)
	waitforvisualfinish
	end

Move_TICKLE: @ 0x0827D483
	loadspritegfx ANIM_TAG_EYE_SPARKLE
	simple_palette_blend selector=F_PAL_ATTACKER, delay=0, initial_blend_y=0, target_blend_y=16, color=RGB_BLACK
	waitforvisualfinish
	createsprite gEyeSparkleSpriteTemplate, ANIM_ATTACKER, 0, -16, -8
	createsprite gEyeSparkleSpriteTemplate, ANIM_ATTACKER, 0, 16, -8
	playsewithpan SE_M_DETECT, SOUND_PAN_ATTACKER
	waitforvisualfinish
	simple_palette_blend selector=F_PAL_ATTACKER, delay=0, initial_blend_y=16, target_blend_y=0, color=RGB_BLACK
	waitforvisualfinish
	delay 20
	createvisualtask AnimTask_SwayMon, 3, 0, 6, 1280, 3, ANIM_ATTACKER
	delay 12
	createvisualtask AnimTask_RockMonBackAndForth, 3, ANIM_TARGET, 6, 2
	loopsewithpan SE_M_TAIL_WHIP, SOUND_PAN_TARGET, 8, 8
	waitforvisualfinish
	end

Move_WATER_SPOUT: @ 0x0827D4EF
	loadspritegfx ANIM_TAG_GLOWY_BLUE_ORB
	loadspritegfx ANIM_TAG_WATER_IMPACT
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_WaterSpoutLaunch, 5
	playsewithpan SE_M_HEADBUTT, SOUND_PAN_ATTACKER
	delay 44
	playsewithpan SE_M_DIVE, SOUND_PAN_ATTACKER
	waitforvisualfinish
	delay 16
	createvisualtask AnimTask_WaterSpoutRain, 5
	playsewithpan SE_M_SURF, SOUND_PAN_TARGET
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SHADOW_PUNCH: @ 0x0827D51D
	loadspritegfx ANIM_TAG_IMPACT
	loadspritegfx ANIM_TAG_HANDS_AND_FEET
	fadetobg BG_GHOST
	waitbgfadein
	monbg ANIM_ATK_PARTNER
	setalpha 9, 8
	createvisualtask AnimTask_AttackerPunchWithTrace, 2, RGB_BLACK, 13
	playsewithpan SE_M_JUMP_KICK, SOUND_PAN_ATTACKER
	delay 6
	create_basic_hitsplat_sprite ANIM_TARGET, 3, x=0, y=0, relative_to=ANIM_TARGET, animation=1
	create_fist_sprite ANIM_TARGET, 4, x=0, y=0, duration=8
	playsewithpan SE_M_COMET_PUNCH, SOUND_PAN_TARGET
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	restorebg
	waitbgfadein
	end

Move_EXTRASENSORY: @ 0x0827D578
	call SetPsychicBackground
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB(27, 27, 0), 12, 1, 1
	createvisualtask AnimTask_ExtrasensoryDistortion, 5, 0
	playsewithpan SE_M_BIND, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB(27, 27, 0), 12, 1, 1
	createvisualtask AnimTask_ExtrasensoryDistortion, 5, 1
	playsewithpan SE_M_BIND, SOUND_PAN_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_TransparentCloneGrowAndShrink, 5, ANIM_ATTACKER
	createvisualtask AnimTask_ExtrasensoryDistortion, 5, 2
	playsewithpan SE_M_LEER, SOUND_PAN_ATTACKER
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	call UnsetPsychicBackground
	end

Move_AERIAL_ACE: @ 0x0827D5E0
	loadspritegfx ANIM_TAG_CUT
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 24, 6, 1, 5
	createvisualtask AnimTask_TraceMonBlended, 2, 0, 4, 7, 3
	createsprite gCuttingSliceSpriteTemplate, ANIM_ATTACKER, 2, 40, -32, 0
	playsewithpan SE_M_RAZOR_WIND2, SOUND_PAN_ATTACKER
	delay 5
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 10, 1
	complex_palette_blend unused_anim_battler=ANIM_ATTACKER, unused_subpriority_offset=2, selector=F_PAL_BG | F_PAL_BATTLERS, delay=3, num_blends=1, color1=RGB_BLACK, blend_y1=10, color2=RGB_BLACK, blend_y2=0
	playsewithpan SE_M_RAZOR_WIND, SOUND_PAN_TARGET
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

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
	.incbin "baserom_jp.gba", 0x285c76, 0x209

IceSpikesEffectLong: @ 0x08285E7F
	.incbin "baserom_jp.gba", 0x285e7f, 0xe7

HealingEffect: @ 0x08285F66
	playsewithpan SE_M_ABSORB_2, SOUND_PAN_ATTACKER
	createsprite gHealingBlueStarSpriteTemplate, ANIM_ATTACKER, 2, 0, -5, 0, 0
	delay 7
	createsprite gHealingBlueStarSpriteTemplate, ANIM_ATTACKER, 2, -15, 10, 0, 0
	delay 7
	createsprite gHealingBlueStarSpriteTemplate, ANIM_ATTACKER, 2, -15, -15, 0, 0
	delay 7
	createsprite gHealingBlueStarSpriteTemplate, ANIM_ATTACKER, 2, 10, -5, 0, 0
	delay 7
	return

HealingEffect2: @ 0x08285FAF
	playsewithpan SE_M_ABSORB_2, SOUND_PAN_TARGET
	createsprite gHealingBlueStarSpriteTemplate, ANIM_TARGET, 2, 0, -5, 1, 0
	delay 7
	createsprite gHealingBlueStarSpriteTemplate, ANIM_TARGET, 2, -15, 10, 1, 0
	delay 7
	createsprite gHealingBlueStarSpriteTemplate, ANIM_TARGET, 2, -15, -15, 1, 0
	delay 7
	createsprite gHealingBlueStarSpriteTemplate, ANIM_TARGET, 2, 10, -5, 1, 0
	delay 7
	return

PoisonBubblesEffect: @ 0x08285FF8
	.incbin "baserom_jp.gba", 0x285ff8, 0x71

WaterBubblesEffectShort: @ 0x08286069
	.incbin "baserom_jp.gba", 0x286069, 0x108

ElectricityEffect: @ 0x08286171
	.incbin "baserom_jp.gba", 0x286171, 0xe7

SetPsychicBackground: @ 0x08286258
	.incbin "baserom_jp.gba", 0x286258, 0xc

UnsetPsychicBackground: @ 0x08286264
	.incbin "baserom_jp.gba", 0x286264, 0x8

SetSkyBg: @ 0x0828626C
	.incbin "baserom_jp.gba", 0x28626c, 0x30

UnsetSkyBg: @ 0x0828629C
	.incbin "baserom_jp.gba", 0x28629c, 0x8

gUnknown_82862A4: @ 0x082862A4
	.incbin "baserom_jp.gba", 0x2862a4, 0x3d

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
