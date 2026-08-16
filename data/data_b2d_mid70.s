.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gText_MoveRelearnerGiveUp
gText_MoveRelearnerGiveUp: @ 0x85ADAAF
	.string "{B_COPY_VAR_1}に　わざを　おぼえさせるのを\n"
	.string "あきらめますか？$"
	.globl gText_MoveRelearnerWhichMoveToForget
gText_MoveRelearnerWhichMoveToForget: @ 0x85ADAC9
	.string "どの　わざを\n"
	.string "わすれさせたい？\p"
	.string "$　　　　　　　　　　　ィ　　　　　　　ぞ　　　　　　"

	.globl sMoveRelearnerSpriteSheet
sMoveRelearnerSpriteSheet: @ 0x85ADAF4
	.4byte 0x085AD820
	.hword 0x0180, 0x1595

	.globl sMoveRelearnerPalette
sMoveRelearnerPalette: @ 0x85ADAFC
	.incbin "graphics/misc/sMoveRelearnerPalette.bin"

	.globl sDisplayModeArrowsTemplate
sDisplayModeArrowsTemplate: @ 0x85ADB04
	.byte 0x00, 0x30, 0x10, 0x01, 0x70, 0x10, 0xFF, 0xFF
	.byte 0xFF, 0xFF, 0xCD, 0x14, 0xCD, 0x14, 0x00, 0x00

	.globl sMoveListScrollArrowsTemplate
sMoveListScrollArrowsTemplate: @ 0x85ADB14
	.byte 0x02  @ firstArrowType (SCROLL_ARROW_UP)
	.byte 0xC8  @ firstX
	.byte 0x08  @ firstY
	.byte 0x03  @ secondArrowType (SCROLL_ARROW_DOWN)
	.byte 0xC8  @ secondX
	.byte 0x68  @ secondY
	.hword 0x00  @ fullyUpThreshold
	.hword 0x00  @ fullyDownThreshold
	.hword 0x1531  @ tileTag
	.hword 0x1531  @ palTag
	.byte 0x00  @ palNum
	.incbin "baserom_jp.gba", 0x5ADB23, 0x31

	.globl sConstestMoveHeartSprite
sConstestMoveHeartSprite: @ 0x85ADB54
	.hword 0x1595, 0x1596
	.4byte 0x085ADADC, 0x085ADB44
	.4byte 0, gDummySpriteAffineAnimTable, 0x08007141

	.globl sMoveRelearnerMenuBackgroundTemplates
sMoveRelearnerMenuBackgroundTemplates: @ 0x85ADB6C
	.byte 0xF0, 0x01, 0x00, 0x00, 0xE1, 0x11, 0x00, 0x00

	.globl sRoamerLocations
sRoamerLocations: @ 0x85ADB74
	.byte 0x19, 0x1A, 0x20, 0x21, 0x31, 0xFF, 0x1A, 0x19, 0x20, 0x21, 0xFF, 0xFF
	.byte 0x20, 0x1A, 0x19, 0x21, 0xFF, 0xFF, 0x21, 0x20, 0x19, 0x1A, 0x22, 0x26
	.byte 0x22, 0x21, 0x23, 0xFF, 0xFF, 0xFF, 0x23, 0x22, 0x24, 0xFF, 0xFF, 0xFF
	.byte 0x24, 0x23, 0x25, 0x26, 0xFF, 0xFF, 0x25, 0x24, 0x26, 0xFF, 0xFF, 0xFF
	.byte 0x26, 0x25, 0x21, 0xFF, 0xFF, 0xFF, 0x27, 0x24, 0x28, 0x29, 0xFF, 0xFF
	.byte 0x28, 0x27, 0x2A, 0xFF, 0xFF, 0xFF, 0x29, 0x27, 0x2A, 0xFF, 0xFF, 0xFF
	.byte 0x2A, 0x28, 0x29, 0x2B, 0xFF, 0xFF, 0x2B, 0x2A, 0x2C, 0xFF, 0xFF, 0xFF
	.byte 0x2C, 0x2B, 0x2D, 0xFF, 0xFF, 0xFF, 0x2D, 0x2C, 0x2E, 0xFF, 0xFF, 0xFF
	.byte 0x2E, 0x2D, 0x2F, 0xFF, 0xFF, 0xFF, 0x2F, 0x2E, 0x30, 0xFF, 0xFF, 0xFF
	.byte 0x30, 0x2F, 0x31, 0xFF, 0xFF, 0xFF, 0x31, 0x30, 0x19, 0xFF, 0xFF, 0xFF
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00

	.globl gBattleFrontierHeldItems
gBattleFrontierHeldItems: @ 0x85ADBF4
	.hword 0x00  @ ITEM_NONE
	.hword 0xBB  @ ITEM_KINGS_ROCK
	.hword 0x8E  @ ITEM_SITRUS_BERRY
	.hword 0x8B  @ ITEM_ORAN_BERRY
	.hword 0x86  @ ITEM_CHESTO_BERRY
	.hword 0xCC  @ ITEM_HARD_STONE
	.hword 0xC4  @ ITEM_FOCUS_BAND
	.hword 0x8C  @ ITEM_PERSIM_BERRY
	.hword 0xCD  @ ITEM_MIRACLE_SEED
	.hword 0x2C  @ ITEM_BERRY_JUICE
	.hword 0xB5  @ ITEM_MACHO_BRACE
	.hword 0xBC  @ ITEM_SILVER_POWDER
	.hword 0x85  @ ITEM_CHERI_BERRY
	.hword 0xCE  @ ITEM_BLACK_GLASSES
	.hword 0xCF  @ ITEM_BLACK_BELT
	.hword 0xBF  @ ITEM_SOUL_DEW
	.hword 0xBA  @ ITEM_CHOICE_BAND
	.hword 0xD0  @ ITEM_MAGNET
	.hword 0xD9  @ ITEM_SILK_SCARF
	.hword 0xB4  @ ITEM_WHITE_HERB
	.hword 0xC1  @ ITEM_DEEP_SEA_SCALE
	.hword 0xC0  @ ITEM_DEEP_SEA_TOOTH
	.hword 0xD1  @ ITEM_MYSTIC_WATER
	.hword 0xD2  @ ITEM_SHARP_BEAK
	.hword 0xB7  @ ITEM_QUICK_CLAW
	.hword 0xC8  @ ITEM_LEFTOVERS
	.hword 0x88  @ ITEM_RAWST_BERRY
	.hword 0xCA  @ ITEM_LIGHT_BALL
	.hword 0xD3  @ ITEM_POISON_BARB
	.hword 0xD4  @ ITEM_NEVER_MELT_ICE
	.hword 0x89  @ ITEM_ASPEAR_BERRY
	.hword 0xD5  @ ITEM_SPELL_TAG
	.hword 0xB3  @ ITEM_BRIGHT_POWDER
	.hword 0x8A  @ ITEM_LEPPA_BERRY
	.hword 0xC6  @ ITEM_SCOPE_LENS
	.hword 0xD6  @ ITEM_TWISTED_SPOON
	.hword 0xC7  @ ITEM_METAL_COAT
	.hword 0xB9  @ ITEM_MENTAL_HERB
	.hword 0xD7  @ ITEM_CHARCOAL
	.hword 0x87  @ ITEM_PECHA_BERRY
	.hword 0xCB  @ ITEM_SOFT_SAND
	.hword 0x8D  @ ITEM_LUM_BERRY
	.hword 0xC9  @ ITEM_DRAGON_SCALE
	.hword 0xD8  @ ITEM_DRAGON_FANG
	.hword 0x93  @ ITEM_IAPAPA_BERRY
	.hword 0x90  @ ITEM_WIKI_BERRY
	.hword 0xDC  @ ITEM_SEA_INCENSE
	.hword 0xDB  @ ITEM_SHELL_BELL
	.hword 0xAA  @ ITEM_SALAC_BERRY
	.hword 0xAD  @ ITEM_LANSAT_BERRY
	.hword 0xAC  @ ITEM_APICOT_BERRY
	.hword 0xAE  @ ITEM_STARF_BERRY
	.hword 0xA8  @ ITEM_LIECHI_BERRY
	.hword 0xE1  @ ITEM_STICK
	.hword 0xDD  @ ITEM_LAX_INCENSE
	.hword 0x92  @ ITEM_AGUAV_BERRY
	.hword 0x8F  @ ITEM_FIGY_BERRY
	.hword 0xE0  @ ITEM_THICK_CLUB
	.hword 0x91  @ ITEM_MAGO_BERRY
	.hword 0xDF  @ ITEM_METAL_POWDER
	.hword 0xAB  @ ITEM_PETAYA_BERRY
	.hword 0xDE  @ ITEM_LUCKY_PUNCH
	.hword 0xA9  @ ITEM_GANLON_BERRY
	.incbin "baserom_jp.gba", 0x5ADC72, 0x6D9E

	.globl gBattleFrontierTrainers
gBattleFrontierTrainers: @ 0x85B4A10
	.incbin "baserom_jp.gba", 0x5b4a10, 0x3cf0

	.globl gBattleFrontierMons
gBattleFrontierMons: @ 0x85B8700
	.incbin "baserom_jp.gba", 0x5b8700, 0x3720

	.globl gTowerMaleFacilityClasses
gTowerMaleFacilityClasses: @ 0x85BBE20
	.byte 0x0E  @ FACILITY_CLASS_RUIN_MANIAC
	.byte 0x11  @ FACILITY_CLASS_TUBER_M
	.byte 0x03  @ FACILITY_CLASS_COOLTRAINER_M
	.byte 0x15  @ FACILITY_CLASS_RICH_BOY
	.byte 0x17  @ FACILITY_CLASS_POKEMANIAC
	.byte 0x07  @ FACILITY_CLASS_SWIMMER_M
	.byte 0x0A  @ FACILITY_CLASS_BLACK_BELT
	.byte 0x19  @ FACILITY_CLASS_GUITARIST
	.byte 0x1A  @ FACILITY_CLASS_KINDLER
	.byte 0x1B  @ FACILITY_CLASS_CAMPER
	.byte 0x1D  @ FACILITY_CLASS_BUG_MANIAC
	.byte 0x1E  @ FACILITY_CLASS_PSYCHIC_M
	.byte 0x20  @ FACILITY_CLASS_GENTLEMAN
	.byte 0x26  @ FACILITY_CLASS_SCHOOL_KID_M
	.byte 0x29  @ FACILITY_CLASS_POKEFAN_M
	.byte 0x09  @ FACILITY_CLASS_EXPERT_M
	.byte 0x2B  @ FACILITY_CLASS_YOUNGSTER
	.byte 0x2D  @ FACILITY_CLASS_FISHERMAN
	.byte 0x2E  @ FACILITY_CLASS_CYCLING_TRIATHLETE_M
	.byte 0x30  @ FACILITY_CLASS_RUNNING_TRIATHLETE_M
	.byte 0x32  @ FACILITY_CLASS_SWIMMING_TRIATHLETE_M
	.byte 0x34  @ FACILITY_CLASS_DRAGON_TAMER
	.byte 0x04  @ FACILITY_CLASS_BIRD_KEEPER
	.byte 0x35  @ FACILITY_CLASS_NINJA_BOY
	.byte 0x3A  @ FACILITY_CLASS_SAILOR
	.byte 0x05  @ FACILITY_CLASS_COLLECTOR
	.byte 0x42  @ FACILITY_CLASS_PKMN_BREEDER_M
	.byte 0x44  @ FACILITY_CLASS_PKMN_RANGER_M
	.byte 0x43  @ FACILITY_CLASS_BUG_CATCHER
	.byte 0x00  @ FACILITY_CLASS_HIKER

	.globl gTowerFemaleFacilityClasses
gTowerFemaleFacilityClasses: @ 0x85BBE3E
	.byte 0x0D  @ FACILITY_CLASS_AROMA_LADY
	.byte 0x10  @ FACILITY_CLASS_TUBER_F
	.byte 0x12  @ FACILITY_CLASS_COOLTRAINER_F
	.byte 0x0C  @ FACILITY_CLASS_HEX_MANIAC
	.byte 0x13  @ FACILITY_CLASS_LADY
	.byte 0x14  @ FACILITY_CLASS_BEAUTY
	.byte 0x1F  @ FACILITY_CLASS_PSYCHIC_F
	.byte 0x27  @ FACILITY_CLASS_SCHOOL_KID_F
	.byte 0x2A  @ FACILITY_CLASS_POKEFAN_F
	.byte 0x16  @ FACILITY_CLASS_EXPERT_F
	.byte 0x2F  @ FACILITY_CLASS_CYCLING_TRIATHLETE_F
	.byte 0x31  @ FACILITY_CLASS_RUNNING_TRIATHLETE_F
	.byte 0x33  @ FACILITY_CLASS_SWIMMING_TRIATHLETE_F
	.byte 0x36  @ FACILITY_CLASS_BATTLE_GIRL
	.byte 0x37  @ FACILITY_CLASS_PARASOL_LADY
	.byte 0x38  @ FACILITY_CLASS_SWIMMER_F
	.byte 0x1C  @ FACILITY_CLASS_PICNICKER
	.byte 0x02  @ FACILITY_CLASS_PKMN_BREEDER_F
	.byte 0x45  @ FACILITY_CLASS_PKMN_RANGER_F
	.byte 0x47  @ FACILITY_CLASS_LASS

	.globl gTowerMaleTrainerGfxIds
gTowerMaleTrainerGfxIds: @ 0x85BBE52
	.byte 0x37  @ OBJ_EVENT_GFX_HIKER
	.byte 0x36  @ OBJ_EVENT_GFX_TUBER_M
	.byte 0x21  @ OBJ_EVENT_GFX_MAN_3
	.byte 0x0F  @ OBJ_EVENT_GFX_RICH_BOY
	.byte 0x27  @ OBJ_EVENT_GFX_MANIAC
	.byte 0x33  @ OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	.byte 0x2C  @ OBJ_EVENT_GFX_BLACK_BELT
	.byte 0x42  @ OBJ_EVENT_GFX_MAN_5
	.byte 0x42  @ OBJ_EVENT_GFX_MAN_5
	.byte 0x1F  @ OBJ_EVENT_GFX_CAMPER
	.byte 0x27  @ OBJ_EVENT_GFX_MANIAC
	.byte 0x25  @ OBJ_EVENT_GFX_PSYCHIC_M
	.byte 0x30  @ OBJ_EVENT_GFX_GENTLEMAN
	.byte 0x26  @ OBJ_EVENT_GFX_SCHOOL_KID_M
	.byte 0x19  @ OBJ_EVENT_GFX_POKEFAN_M
	.byte 0x15  @ OBJ_EVENT_GFX_EXPERT_M
	.byte 0x23  @ OBJ_EVENT_GFX_YOUNGSTER
	.byte 0x32  @ OBJ_EVENT_GFX_FISHERMAN
	.byte 0x38  @ OBJ_EVENT_GFX_CYCLING_TRIATHLETE_M
	.byte 0x33  @ OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	.byte 0x33  @ OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M
	.byte 0x21  @ OBJ_EVENT_GFX_MAN_3
	.byte 0x42  @ OBJ_EVENT_GFX_MAN_5
	.byte 0x05  @ OBJ_EVENT_GFX_NINJA_BOY
	.byte 0x31  @ OBJ_EVENT_GFX_SAILOR
	.byte 0x27  @ OBJ_EVENT_GFX_MANIAC
	.byte 0x41  @ OBJ_EVENT_GFX_MAN_4
	.byte 0x1F  @ OBJ_EVENT_GFX_CAMPER
	.byte 0x24  @ OBJ_EVENT_GFX_BUG_CATCHER
	.byte 0x37  @ OBJ_EVENT_GFX_HIKER

	.globl gTowerFemaleTrainerGfxIds
gTowerFemaleTrainerGfxIds: @ 0x85BBE70
	.byte 0x14  @ OBJ_EVENT_GFX_WOMAN_2
	.byte 0x35  @ OBJ_EVENT_GFX_TUBER_F
	.byte 0x22  @ OBJ_EVENT_GFX_WOMAN_5
	.byte 0x28  @ OBJ_EVENT_GFX_HEX_MANIAC
	.byte 0x14  @ OBJ_EVENT_GFX_WOMAN_2
	.byte 0x2D  @ OBJ_EVENT_GFX_BEAUTY
	.byte 0x2F  @ OBJ_EVENT_GFX_LASS
	.byte 0x0E  @ OBJ_EVENT_GFX_GIRL_3
	.byte 0x12  @ OBJ_EVENT_GFX_POKEFAN_F
	.byte 0x16  @ OBJ_EVENT_GFX_EXPERT_F
	.byte 0x39  @ OBJ_EVENT_GFX_CYCLING_TRIATHLETE_F
	.byte 0x34  @ OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	.byte 0x34  @ OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	.byte 0x0E  @ OBJ_EVENT_GFX_GIRL_3
	.byte 0x22  @ OBJ_EVENT_GFX_WOMAN_5
	.byte 0x34  @ OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F
	.byte 0x20  @ OBJ_EVENT_GFX_PICNICKER
	.byte 0x14  @ OBJ_EVENT_GFX_WOMAN_2
	.byte 0x20  @ OBJ_EVENT_GFX_PICNICKER
	.byte 0x2F  @ OBJ_EVENT_GFX_LASS

	.globl gUnknown_85BBE84
gUnknown_85BBE84: @ 0x85BBE84
	.incbin "baserom_jp.gba", 0x5bbe84, 0x5c0

	.globl gUnknown_85BC444
gUnknown_85BC444: @ 0x85BC444
	.incbin "baserom_jp.gba", 0x5bc444, 0x190

	.globl gUnknown_85BC5D4
gUnknown_85BC5D4: @ 0x85BC5D4
	.incbin "baserom_jp.gba", 0x5bc5d4, 0x40

	.globl gUnknown_85BC614
gUnknown_85BC614: @ 0x85BC614
	.incbin "baserom_jp.gba", 0x5bc614, 0x5

	.globl gUnknown_85BC619
gUnknown_85BC619: @ 0x85BC619
	.incbin "baserom_jp.gba", 0x5bc619, 0x7

	.globl gUnknown_85BC620
gUnknown_85BC620: @ 0x85BC620
	.incbin "baserom_jp.gba", 0x5BC620, 0x338
	.globl gSlateportBattleTentTrainers
gSlateportBattleTentTrainers: @ 0x85BC958
	.incbin "baserom_jp.gba", 0x5bc958, 0x618

	.globl gSlateportBattleTentMons
gSlateportBattleTentMons: @ 0x85BCF70
	.incbin "baserom_jp.gba", 0x5bcf70, 0x5e4
	.globl gUnknown_85BD554
gUnknown_85BD554: @ 0x85BD554
	.incbin "baserom_jp.gba", 0x5bd554, 0x618

	.globl gUnknown_85BDB6C
gUnknown_85BDB6C: @ 0x85BDB6C
	.incbin "baserom_jp.gba", 0x5bdb6c, 0x45c

	.globl gUnknown_85BDFC8
gUnknown_85BDFC8: @ 0x85BDFC8
	.incbin "baserom_jp.gba", 0x5bdfc8, 0x618

	.globl gUnknown_85BE5E0
gUnknown_85BE5E0: @ 0x85BE5E0
	.incbin "baserom_jp.gba", 0x5be5e0, 0x2d0

	.globl gUnknown_85BE8B0
gUnknown_85BE8B0: @ 0x85BE8B0
	.incbin "baserom_jp.gba", 0x5be8b0, 0x40

	.globl gUnknown_85BE8F0
gUnknown_85BE8F0: @ 0x85BE8F0
	.incbin "baserom_jp.gba", 0x5be8f0, 0x20

	.globl gUnknown_85BE910
gUnknown_85BE910: @ 0x85BE910
	.string "\n$$${STRING}$$$$E$$$ァ$$$$\n$$${STRING}$$$\p$$${DYNAMIC}$"
	.globl gUnknown_85BE930
gUnknown_85BE930: @ 0x85BE930
	.incbin "baserom_jp.gba", 0x5be930, 0xa

	.globl gUnknown_85BE93A
gUnknown_85BE93A: @ 0x85BE93A
	.incbin "baserom_jp.gba", 0x5be93a, 0x4

	.globl gUnknown_85BE93E
gUnknown_85BE93E: @ 0x85BE93E
	.incbin "baserom_jp.gba", 0x5be93e, 0x20

	.globl gUnknown_85BE95E
gUnknown_85BE95E: @ 0x85BE95E
	.incbin "baserom_jp.gba", 0x5be95e, 0x28

	.globl gUnknown_85BE986
gUnknown_85BE986: @ 0x85BE986
	.incbin "baserom_jp.gba", 0x5be986, 0xc

	.globl gUnknown_85BE992
gUnknown_85BE992: @ 0x85BE992
	.incbin "baserom_jp.gba", 0x5be992, 0x22e

	.globl gUnknown_85BEBC0
gUnknown_85BEBC0: @ 0x85BEBC0
	.incbin "baserom_jp.gba", 0x5bebc0, 0xcc0

	.globl gUnknown_85BF880
gUnknown_85BF880: @ 0x85BF880
	.incbin "baserom_jp.gba", 0x5bf880, 0x40

	.globl gUnknown_85BF8C0
gUnknown_85BF8C0: @ 0x85BF8C0
	.incbin "baserom_jp.gba", 0x5bf8c0, 0xe0

	.globl gUnknown_85BF9A0
gUnknown_85BF9A0: @ 0x85BF9A0
	.incbin "baserom_jp.gba", 0x5bf9a0, 0xac

	.globl gUnknown_85BFA4C
gUnknown_85BFA4C: @ 0x85BFA4C
	.incbin "baserom_jp.gba", 0x5bfa4c, 0x60

	.globl gUnknown_85BFAAC
gUnknown_85BFAAC: @ 0x85BFAAC
	.incbin "baserom_jp.gba", 0x5bfaac, 0x784

	.globl gUnknown_85C0230
gUnknown_85C0230: @ 0x85C0230
	.incbin "baserom_jp.gba", 0x5c0230, 0x1e0

	.globl gUnknown_85C0410
gUnknown_85C0410: @ 0x85C0410
	.incbin "baserom_jp.gba", 0x5c0410, 0x78

	.globl gUnknown_85C0488
gUnknown_85C0488: @ 0x85C0488
	.incbin "baserom_jp.gba", 0x5c0488, 0x50c

	.globl gUnknown_85C0994
gUnknown_85C0994: @ 0x85C0994
	.incbin "baserom_jp.gba", 0x5c0994, 0x14

	.globl gUnknown_85C09A8
gUnknown_85C09A8: @ 0x85C09A8
	.incbin "baserom_jp.gba", 0x5c09a8, 0x5

	.globl gUnknown_85C09AD
gUnknown_85C09AD: @ 0x85C09AD
	.incbin "baserom_jp.gba", 0x5c09ad, 0x3

	.globl gUnknown_85C09B0
gUnknown_85C09B0: @ 0x85C09B0
	.incbin "baserom_jp.gba", 0x5c09b0, 0x10

	.globl gUnknown_85C09C0
gUnknown_85C09C0: @ 0x85C09C0
	.incbin "baserom_jp.gba", 0x5c09c0, 0x20

	.globl gUnknown_85C09E0
gUnknown_85C09E0: @ 0x85C09E0
	.incbin "baserom_jp.gba", 0x5c09e0, 0x8

	.globl gUnknown_85C09E8
gUnknown_85C09E8: @ 0x85C09E8
	.incbin "baserom_jp.gba", 0x5c09e8, 0x14

	.globl gUnknown_85C09FC
gUnknown_85C09FC: @ 0x85C09FC
	.incbin "baserom_jp.gba", 0x5c09fc, 0x8

	.globl gUnknown_85C0A04
gUnknown_85C0A04: @ 0x85C0A04
	.incbin "baserom_jp.gba", 0x5c0a04, 0x8

	.globl gUnknown_85C0A0C
gUnknown_85C0A0C: @ 0x85C0A0C
	.incbin "baserom_jp.gba", 0x5c0a0c, 0x34

	.globl gUnknown_85C0A40
gUnknown_85C0A40: @ 0x85C0A40
	.incbin "baserom_jp.gba", 0x5c0a40, 0x44

	.globl gUnknown_85C0A84
gUnknown_85C0A84: @ 0x85C0A84
	.incbin "baserom_jp.gba", 0x5c0a84, 0x18

	.globl gUnknown_85C0A9C
gUnknown_85C0A9C: @ 0x85C0A9C
	.incbin "baserom_jp.gba", 0x5c0a9c, 0x8

	.globl gUnknown_85C0AA4
gUnknown_85C0AA4: @ 0x85C0AA4
	.incbin "baserom_jp.gba", 0x5c0aa4, 0xe4

	.globl gUnknown_85C0B88
gUnknown_85C0B88: @ 0x85C0B88
	.incbin "baserom_jp.gba", 0x5c0b88, 0x10

	.globl gUnknown_85C0B98
gUnknown_85C0B98: @ 0x85C0B98
	.incbin "baserom_jp.gba", 0x5c0b98, 0x20

	.globl gUnknown_85C0BB8
gUnknown_85C0BB8: @ 0x85C0BB8
	.incbin "baserom_jp.gba", 0x5c0bb8, 0x4

	.globl gUnknown_85C0BBC
gUnknown_85C0BBC: @ 0x85C0BBC
	.incbin "baserom_jp.gba", 0x5c0bbc, 0x4

	.globl gUnknown_85C0BC0
gUnknown_85C0BC0: @ 0x85C0BC0
	.incbin "baserom_jp.gba", 0x5c0bc0, 0x20

	.globl gUnknown_85C0BE0
gUnknown_85C0BE0: @ 0x85C0BE0
	.incbin "baserom_jp.gba", 0x5c0be0, 0x8

	.globl gUnknown_85C0BE8
gUnknown_85C0BE8: @ 0x85C0BE8
	.incbin "baserom_jp.gba", 0x5c0be8, 0x20

	.globl gUnknown_85C0C08
gUnknown_85C0C08: @ 0x85C0C08
	.incbin "baserom_jp.gba", 0x5c0c08, 0x8

	.globl gUnknown_85C0C10
gUnknown_85C0C10: @ 0x85C0C10
	.incbin "baserom_jp.gba", 0x5c0c10, 0x8

	.globl gUnknown_85C0C18
gUnknown_85C0C18: @ 0x85C0C18
	.incbin "baserom_jp.gba", 0x5c0c18, 0x8

	.globl gUnknown_85C0C20
gUnknown_85C0C20: @ 0x85C0C20
	.incbin "baserom_jp.gba", 0x5c0c20, 0x8

	.globl gUnknown_85C0C28
gUnknown_85C0C28: @ 0x85C0C28
	.incbin "baserom_jp.gba", 0x5c0c28, 0x18

	.globl gUnknown_85C0C40
gUnknown_85C0C40: @ 0x85C0C40
	.incbin "baserom_jp.gba", 0x5c0c40, 0x28

	.globl gUnknown_85C0C68
gUnknown_85C0C68: @ 0x85C0C68
	.incbin "baserom_jp.gba", 0x5c0c68, 0x8

	.globl gUnknown_85C0C70
gUnknown_85C0C70: @ 0x85C0C70
	.incbin "baserom_jp.gba", 0x5c0c70, 0x4

	.globl gUnknown_85C0C74
gUnknown_85C0C74: @ 0x85C0C74
	.incbin "baserom_jp.gba", 0x5c0c74, 0x20

	.globl gUnknown_85C0C94
gUnknown_85C0C94: @ 0x85C0C94
	.incbin "baserom_jp.gba", 0x5c0c94, 0x264

	.globl gUnknown_85C0EF8
gUnknown_85C0EF8: @ 0x85C0EF8
	.incbin "baserom_jp.gba", 0x5c0ef8, 0x780

	.globl gUnknown_85C1678
gUnknown_85C1678: @ 0x85C1678
	.incbin "baserom_jp.gba", 0x5c1678, 0x200

	.globl gUnknown_85C1878
gUnknown_85C1878: @ 0x85C1878
	.incbin "baserom_jp.gba", 0x5c1878, 0x3b4

	.globl gUnknown_85C1C2C
gUnknown_85C1C2C: @ 0x85C1C2C
	.incbin "baserom_jp.gba", 0x5c1c2c, 0x334

	.globl gUnknown_85C1F60
gUnknown_85C1F60: @ 0x85C1F60
	.incbin "baserom_jp.gba", 0x5c1f60, 0x2f0

	.globl gUnknown_85C2250
gUnknown_85C2250: @ 0x85C2250
	.incbin "baserom_jp.gba", 0x5c2250, 0x218

	.globl gUnknown_85C2468
gUnknown_85C2468: @ 0x85C2468
	.incbin "baserom_jp.gba", 0x5c2468, 0x2170

	.globl gUnknown_85C45D8
gUnknown_85C45D8: @ 0x85C45D8
	.incbin "graphics/battle_frontier/gUnknown_85C45D8.gbapal"

	.globl gUnknown_85C47D8
gUnknown_85C47D8: @ 0x85C47D8
	.incbin "baserom_jp.gba", 0x5c47d8, 0x130

	.globl gUnknown_85C4908
gUnknown_85C4908: @ 0x85C4908
	.incbin "baserom_jp.gba", 0x5c4908, 0x1220

	.globl gUnknown_85C5B28
gUnknown_85C5B28: @ 0x85C5B28
	.incbin "baserom_jp.gba", 0x5c5b28, 0x10

	.globl gUnknown_85C5B38
gUnknown_85C5B38: @ 0x85C5B38
	.incbin "baserom_jp.gba", 0x5c5b38, 0x34

	.globl gUnknown_85C5B6C
gUnknown_85C5B6C: @ 0x85C5B6C
	.incbin "baserom_jp.gba", 0x5c5b6c, 0x18

	.globl gUnknown_85C5B84
gUnknown_85C5B84: @ 0x85C5B84
	.incbin "baserom_jp.gba", 0x5c5b84, 0x18

	.globl gUnknown_85C5B9C
gUnknown_85C5B9C: @ 0x85C5B9C
	.incbin "baserom_jp.gba", 0x5c5b9c, 0x20

	.globl gUnknown_85C5BBC
gUnknown_85C5BBC: @ 0x85C5BBC
	.incbin "baserom_jp.gba", 0x5c5bbc, 0x38

	.globl gUnknown_85C5BF4
gUnknown_85C5BF4: @ 0x85C5BF4
	.incbin "baserom_jp.gba", 0x5c5bf4, 0x64

	.globl gUnknown_85C5C58
gUnknown_85C5C58: @ 0x85C5C58
	.incbin "baserom_jp.gba", 0x5c5c58, 0x38

	.globl gUnknown_85C5C90
gUnknown_85C5C90: @ 0x85C5C90
	.incbin "baserom_jp.gba", 0x5c5c90, 0x18

	.globl gUnknown_85C5CA8
gUnknown_85C5CA8: @ 0x85C5CA8
	.incbin "baserom_jp.gba", 0x5c5ca8, 0x10

	.globl gUnknown_85C5CB8
gUnknown_85C5CB8: @ 0x85C5CB8
	.incbin "baserom_jp.gba", 0x5c5cb8, 0x48

	.globl gUnknown_85C5D00
gUnknown_85C5D00: @ 0x85C5D00
	.incbin "baserom_jp.gba", 0x5c5d00, 0x18

	.globl gUnknown_85C5D18
gUnknown_85C5D18: @ 0x85C5D18
	.incbin "baserom_jp.gba", 0x5c5d18, 0x24

	.globl gUnknown_85C5D3C
gUnknown_85C5D3C: @ 0x85C5D3C
	.incbin "baserom_jp.gba", 0x5c5d3c, 0x10

	.globl gUnknown_85C5D4C
gUnknown_85C5D4C: @ 0x85C5D4C
	.incbin "baserom_jp.gba", 0x5c5d4c, 0x10

	.globl gUnknown_85C5D5C
gUnknown_85C5D5C: @ 0x85C5D5C
	.incbin "baserom_jp.gba", 0x5c5d5c, 0x6c

	.globl gUnknown_85C5DC8
gUnknown_85C5DC8: @ 0x85C5DC8
	.incbin "baserom_jp.gba", 0x5c5dc8, 0x50

	.globl gUnknown_85C5E18
gUnknown_85C5E18: @ 0x85C5E18
	.incbin "baserom_jp.gba", 0x5c5e18, 0x60

	.globl gUnknown_85C5E78
gUnknown_85C5E78: @ 0x85C5E78
	.incbin "baserom_jp.gba", 0x5c5e78, 0xd0

	.globl gUnknown_85C5F48
gUnknown_85C5F48: @ 0x85C5F48
	.incbin "baserom_jp.gba", 0x5c5f48, 0xb4

	.globl gUnknown_85C5FFC
gUnknown_85C5FFC: @ 0x85C5FFC
	.incbin "baserom_jp.gba", 0x5c5ffc, 0x14

	.globl gUnknown_85C6010
gUnknown_85C6010: @ 0x85C6010
	.incbin "baserom_jp.gba", 0x5c6010, 0x30

	.globl gUnknown_85C6040
gUnknown_85C6040: @ 0x85C6040
	.incbin "baserom_jp.gba", 0x5c6040, 0x18

	.globl gUnknown_85C6058
gUnknown_85C6058: @ 0x85C6058
	.incbin "baserom_jp.gba", 0x5c6058, 0x20

	.globl gUnknown_85C6078
gUnknown_85C6078: @ 0x85C6078
	.incbin "baserom_jp.gba", 0x5c6078, 0x18

	.globl gUnknown_85C6090
gUnknown_85C6090: @ 0x85C6090
	.incbin "baserom_jp.gba", 0x5c6090, 0x10

	.globl gUnknown_85C60A0
gUnknown_85C60A0: @ 0x85C60A0
	.incbin "baserom_jp.gba", 0x5c60a0, 0x10

	.globl gUnknown_85C60B0
gUnknown_85C60B0: @ 0x85C60B0
	.incbin "baserom_jp.gba", 0x5c60b0, 0x34

	.globl gUnknown_85C60E4
gUnknown_85C60E4: @ 0x85C60E4
	.incbin "baserom_jp.gba", 0x5c60e4, 0x18

	.globl gUnknown_85C60FC
gUnknown_85C60FC: @ 0x85C60FC
	.incbin "baserom_jp.gba", 0x5c60fc, 0x10

	.globl gUnknown_85C610C
gUnknown_85C610C: @ 0x85C610C
	.incbin "baserom_jp.gba", 0x5c610c, 0x10

	.globl gText_Hoenn
gText_Hoenn: @ 0x85C611C
	.string "ホウエンちほう$"
	.globl sFieldRegionMapBgTemplates
sFieldRegionMapBgTemplates: @ 0x85C6124
	.byte 0xF0, 0x01, 0x00, 0x00, 0xCA, 0x2D, 0x00, 0x00

	.globl sFieldRegionMapWindowTemplates
sFieldRegionMapWindowTemplates: @ 0x85C612C
	.byte 0x00, 0x13, 0x11, 0x0A, 0x02, 0x0F, 0x01, 0x00
	.byte 0x00, 0x16, 0x01, 0x07, 0x02, 0x0F, 0x15, 0x00
	.byte 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.globl gUnknown_85C6144
gUnknown_85C6144: @ 0x85C6144
	.incbin "baserom_jp.gba", 0x5c6144, 0xc

	.globl gUnknown_85C6150
gUnknown_85C6150: @ 0x85C6150
	.incbin "baserom_jp.gba", 0x5c6150, 0x60

	.globl gUnknown_85C61B0
gUnknown_85C61B0: @ 0x85C61B0
	.incbin "baserom_jp.gba", 0x5c61b0, 0xc0

	.globl gUnknown_85C6270
gUnknown_85C6270: @ 0x85C6270
	.incbin "baserom_jp.gba", 0x5c6270, 0xc

	.globl gUnknown_85C627C
gUnknown_85C627C: @ 0x85C627C
	.incbin "baserom_jp.gba", 0x5c627c, 0x30

	.globl gUnknown_85C62AC
gUnknown_85C62AC: @ 0x85C62AC
	.incbin "baserom_jp.gba", 0x5c62ac, 0x60

	.globl gUnknown_85C630C
gUnknown_85C630C: @ 0x85C630C
	.incbin "baserom_jp.gba", 0x5c630c, 0xc0

	.globl gUnknown_85C63CC
gUnknown_85C63CC: @ 0x85C63CC
	.incbin "baserom_jp.gba", 0x5c63cc, 0x64

	.globl gUnknown_85C6430
gUnknown_85C6430: @ 0x85C6430
	.incbin "baserom_jp.gba", 0x5c6430, 0xc

	.globl gUnknown_85C643C
gUnknown_85C643C: @ 0x85C643C
	.incbin "baserom_jp.gba", 0x5c643c, 0x8

	.globl gUnknown_85C6444
gUnknown_85C6444: @ 0x85C6444
	.incbin "baserom_jp.gba", 0x5c6444, 0x4

	.globl gUnknown_85C6448
gUnknown_85C6448: @ 0x85C6448
	.incbin "baserom_jp.gba", 0x5c6448, 0x8

	.globl gUnknown_85C6450
gUnknown_85C6450: @ 0x85C6450
	.incbin "baserom_jp.gba", 0x5c6450, 0x10

	.globl gUnknown_85C6460
gUnknown_85C6460: @ 0x85C6460
	.incbin "baserom_jp.gba", 0x5c6460, 0x10

	.globl gUnknown_85C6470
gUnknown_85C6470: @ 0x85C6470
	.incbin "baserom_jp.gba", 0x5c6470, 0x6

	.globl gUnknown_85C6476
gUnknown_85C6476: @ 0x85C6476
	.incbin "baserom_jp.gba", 0x5c6476, 0x2a

	.globl gUnknown_85C64A0
gUnknown_85C64A0: @ 0x85C64A0
	.incbin "baserom_jp.gba", 0x5c64a0, 0x18

	.globl gUnknown_85C64B8
gUnknown_85C64B8: @ 0x85C64B8
	.incbin "baserom_jp.gba", 0x5c64b8, 0xd4

	.globl gUnknown_85C658C
gUnknown_85C658C: @ 0x85C658C
	.incbin "baserom_jp.gba", 0x5c658c, 0x18

	.globl gUnknown_85C65A4
gUnknown_85C65A4: @ 0x85C65A4
	.incbin "baserom_jp.gba", 0x5c65a4, 0x20

	.globl gUnknown_85C65C4
gUnknown_85C65C4: @ 0x85C65C4
	.incbin "baserom_jp.gba", 0x5c65c4, 0x1cc

	.globl gUnknown_85C6790
gUnknown_85C6790: @ 0x85C6790
	.incbin "baserom_jp.gba", 0x5c6790, 0x1c

	.globl gUnknown_85C67AC
gUnknown_85C67AC: @ 0x85C67AC
	.incbin "baserom_jp.gba", 0x5c67ac, 0x80

	.globl gUnknown_85C682C
gUnknown_85C682C: @ 0x85C682C
	.incbin "baserom_jp.gba", 0x5c682c, 0x43c

	.globl gUnknown_85C6C68
gUnknown_85C6C68: @ 0x85C6C68
	.string "　あ　$あ$$あ$$あ$$あ$"
	.globl gUnknown_85C6C77
gUnknown_85C6C77: @ 0x85C6C77
	.incbin "baserom_jp.gba", 0x5c6c77, 0xf

	.globl gUnknown_85C6C86
gUnknown_85C6C86: @ 0x85C6C86
	.incbin "baserom_jp.gba", 0x5c6c86, 0xf

	.globl gUnknown_85C6C95
gUnknown_85C6C95: @ 0x85C6C95
	.incbin "baserom_jp.gba", 0x5c6c95, 0xf

	.globl gUnknown_85C6CA4
gUnknown_85C6CA4: @ 0x85C6CA4
	.incbin "baserom_jp.gba", 0x5c6ca4, 0x8ec

	.globl gUnknown_85C7590
gUnknown_85C7590: @ 0x85C7590
	.incbin "baserom_jp.gba", 0x5c7590, 0x384

	.globl gUnknown_85C7914
gUnknown_85C7914: @ 0x85C7914
	.incbin "baserom_jp.gba", 0x5c7914, 0x4

	.globl gUnknown_85C7918
gUnknown_85C7918: @ 0x85C7918
	.incbin "baserom_jp.gba", 0x5c7918, 0x10

	.globl gUnknown_85C7928
gUnknown_85C7928: @ 0x85C7928
	.incbin "baserom_jp.gba", 0x5c7928, 0x54

	.globl gUnknown_85C797C
gUnknown_85C797C: @ 0x85C797C
	.incbin "baserom_jp.gba", 0x5c797c, 0x40

	.globl gUnknown_85C79BC
gUnknown_85C79BC: @ 0x85C79BC
	.incbin "baserom_jp.gba", 0x5c79bc, 0xc

	.globl gUnknown_85C79C8
gUnknown_85C79C8: @ 0x85C79C8
	.incbin "baserom_jp.gba", 0x5c79c8, 0x10

	.globl gUnknown_85C79D8
gUnknown_85C79D8: @ 0x85C79D8
	.incbin "baserom_jp.gba", 0x5c79d8, 0x3c

	.globl gUnknown_85C7A14
gUnknown_85C7A14: @ 0x85C7A14
	.incbin "baserom_jp.gba", 0x5c7a14, 0x18

	.globl sLotteryPrizes
sLotteryPrizes: @ 0x85C7A2C
	.hword 0x0045, 0x00B6, 0x0019, 0x0001

	.globl sDiplomaPalettes
sDiplomaPalettes: @ 0x85C7A34
	.incbin "graphics/diploma/sDiplomaPalettes.bin"

	.globl sDiplomaTilemap
sDiplomaTilemap: @ 0x85C7A74
	.incbin "graphics/diploma/sDiplomaTilemap.bin"

	.globl sDiplomaTiles
sDiplomaTiles: @ 0x85C81B0
	.incbin "graphics/diploma/sDiplomaTiles.bin"
