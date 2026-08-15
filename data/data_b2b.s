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


gUnknown_82EBCE2: @ 0x82EBCE2
	.incbin "baserom_jp.gba", 0x2ebce2, 0x2

	.globl gTrainerMoneyTable
gTrainerMoneyTable: @ 0x82EBCE4
	.byte TRAINER_CLASS_TEAM_AQUA, 5
	.2byte 0
	.byte TRAINER_CLASS_AQUA_ADMIN, 10
	.2byte 0
	.byte TRAINER_CLASS_AQUA_LEADER, 20
	.2byte 0
	.byte TRAINER_CLASS_AROMA_LADY, 10
	.2byte 0
	.byte TRAINER_CLASS_RUIN_MANIAC, 15
	.2byte 0
	.byte TRAINER_CLASS_INTERVIEWER, 12
	.2byte 0
	.byte TRAINER_CLASS_TUBER_F, 1
	.2byte 0
	.byte TRAINER_CLASS_TUBER_M, 1
	.2byte 0
	.byte TRAINER_CLASS_SIS_AND_BRO, 3
	.2byte 0
	.byte TRAINER_CLASS_COOLTRAINER, 12
	.2byte 0
	.byte TRAINER_CLASS_HEX_MANIAC, 6
	.2byte 0
	.byte TRAINER_CLASS_LADY, 50
	.2byte 0
	.byte TRAINER_CLASS_BEAUTY, 20
	.2byte 0
	.byte TRAINER_CLASS_RICH_BOY, 50
	.2byte 0
	.byte TRAINER_CLASS_POKEMANIAC, 15
	.2byte 0
	.byte TRAINER_CLASS_SWIMMER_M, 2
	.2byte 0
	.byte TRAINER_CLASS_BLACK_BELT, 8
	.2byte 0
	.byte TRAINER_CLASS_GUITARIST, 8
	.2byte 0
	.byte TRAINER_CLASS_KINDLER, 8
	.2byte 0
	.byte TRAINER_CLASS_CAMPER, 4
	.2byte 0
	.byte TRAINER_CLASS_OLD_COUPLE, 10
	.2byte 0
	.byte TRAINER_CLASS_BUG_MANIAC, 15
	.2byte 0
	.byte TRAINER_CLASS_PSYCHIC, 6
	.2byte 0
	.byte TRAINER_CLASS_GENTLEMAN, 20
	.2byte 0
	.byte TRAINER_CLASS_ELITE_FOUR, 25
	.2byte 0
	.byte TRAINER_CLASS_LEADER, 25
	.2byte 0
	.byte TRAINER_CLASS_SCHOOL_KID, 5
	.2byte 0
	.byte TRAINER_CLASS_SR_AND_JR, 4
	.2byte 0
	.byte TRAINER_CLASS_POKEFAN, 20
	.2byte 0
	.byte TRAINER_CLASS_EXPERT, 10
	.2byte 0
	.byte TRAINER_CLASS_YOUNGSTER, 4
	.2byte 0
	.byte TRAINER_CLASS_CHAMPION, 50
	.2byte 0
	.byte TRAINER_CLASS_FISHERMAN, 10
	.2byte 0
	.byte TRAINER_CLASS_TRIATHLETE, 10
	.2byte 0
	.byte TRAINER_CLASS_DRAGON_TAMER, 12
	.2byte 0
	.byte TRAINER_CLASS_BIRD_KEEPER, 8
	.2byte 0
	.byte TRAINER_CLASS_NINJA_BOY, 3
	.2byte 0
	.byte TRAINER_CLASS_BATTLE_GIRL, 6
	.2byte 0
	.byte TRAINER_CLASS_PARASOL_LADY, 10
	.2byte 0
	.byte TRAINER_CLASS_SWIMMER_F, 2
	.2byte 0
	.byte TRAINER_CLASS_PICNICKER, 4
	.2byte 0
	.byte TRAINER_CLASS_TWINS, 3
	.2byte 0
	.byte TRAINER_CLASS_SAILOR, 8
	.2byte 0
	.byte TRAINER_CLASS_COLLECTOR, 15
	.2byte 0
	.byte TRAINER_CLASS_RIVAL, 15
	.2byte 0
	.byte TRAINER_CLASS_PKMN_BREEDER, 10
	.2byte 0
	.byte TRAINER_CLASS_PKMN_RANGER, 12
	.2byte 0
	.byte TRAINER_CLASS_TEAM_MAGMA, 5
	.2byte 0
	.byte TRAINER_CLASS_MAGMA_ADMIN, 10
	.2byte 0
	.byte TRAINER_CLASS_MAGMA_LEADER, 20
	.2byte 0
	.byte TRAINER_CLASS_LASS, 4
	.2byte 0
	.byte TRAINER_CLASS_BUG_CATCHER, 4
	.2byte 0
	.byte TRAINER_CLASS_HIKER, 10
	.2byte 0
	.byte TRAINER_CLASS_YOUNG_COUPLE, 8
	.2byte 0
	.byte TRAINER_CLASS_WINSTRATE, 10
	.2byte 0
	.byte 0xFF, 5
	.2byte 0

