@ Japanese braille cells are represented with Unicode Braille literals.
@ The original six-byte brailleformat headers, labels, and physical order
@ follow the canonical pokeemerald source owner byte-exactly.

	.globl Underwater_SealedChamber_Braille_GoUpHere
Underwater_SealedChamber_Braille_GoUpHere: @ 0x082635D2
	brailleformat 4, 6, 26, 13, 7, 9
	.braille "⠪⠪⠐⠟⠀⠁⠐⠡⠛$"

	.globl SealedChamber_OuterRoom_Braille_ABC
SealedChamber_OuterRoom_Braille_ABC: @ 0x082635E2
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "⠁⠃⠉⠋⠊$"

	.globl SealedChamber_OuterRoom_Braille_GHI
SealedChamber_OuterRoom_Braille_GHI: @ 0x082635EE
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "⠡⠣⠩⠫⠪$"

	.globl SealedChamber_OuterRoom_Braille_MNO
SealedChamber_OuterRoom_Braille_MNO: @ 0x082635FA
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "⠱⠳⠹⠻⠺$"

	.globl SealedChamber_OuterRoom_Braille_TUV
SealedChamber_OuterRoom_Braille_TUV: @ 0x08263606
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "⠕⠗⠝⠟⠞$"

	.globl SealedChamber_OuterRoom_Braille_DEF
SealedChamber_OuterRoom_Braille_DEF: @ 0x08263612
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "⠅⠇⠍⠏⠎$"

	.globl SealedChamber_OuterRoom_Braille_JKL
SealedChamber_OuterRoom_Braille_JKL: @ 0x0826361E
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "⠥⠧⠭⠯⠮$"

	.globl SealedChamber_OuterRoom_Braille_PQRS
SealedChamber_OuterRoom_Braille_PQRS: @ 0x0826362A
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "⠵⠷⠽⠿⠾$"

	.globl SealedChamber_OuterRoom_Braille_Period
SealedChamber_OuterRoom_Braille_Period: @ 0x08263636
	brailleformat 9, 6, 19, 13, 12, 9
	.braille "⠌⠬⠜$"

	.globl SealedChamber_OuterRoom_Braille_WXYZ
SealedChamber_OuterRoom_Braille_WXYZ: @ 0x08263640
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "⠑⠓⠙⠛⠚$"

	.globl SealedChamber_OuterRoom_Braille_Comma
SealedChamber_OuterRoom_Braille_Comma: @ 0x0826364C
	brailleformat 9, 6, 19, 13, 12, 9
	.braille "⠄⠔⠴$"

	.globl SealedChamber_OuterRoom_Braille_DigHere
SealedChamber_OuterRoom_Braille_DigHere: @ 0x08263656
	brailleformat 7, 4, 23, 15, 10, 7
	.braille "⠪⠪⠐⠟\n⠁⠅⠔⠀⠮⠙$"

	.globl SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth
SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth: @ 0x08263668
	brailleformat 0, 0, 29, 19, 3, 3
	.braille "⠱⠃⠈⠺⠇⠀⠮⠋⠙⠊⠒\n⠱⠃⠐⠪⠇⠀⠐⠳⠒⠑⠴⠹\n⠺⠳⠟⠀⠹⠐⠯⠟⠐⠡\n⠧⠑⠡⠛⠙$"

	.globl SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived
SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived: @ 0x08263698
	brailleformat 2, 0, 26, 19, 5, 3
	.braille "⠄⠕⠳⠕⠗⠄\n⠪⠎⠀⠁⠅⠐⠟\n⠩⠑⠳⠀⠻⠃⠡⠝⠀⠳\n⠺⠳⠟⠀⠃⠣⠟⠀⠣⠕$"

	.globl SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon
SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon: @ 0x082636C3
	brailleformat 7, 2, 23, 17, 10, 5
	.braille "⠹⠐⠯⠟⠄\n⠠⠮⠫⠾⠴⠎\n⠊⠡⠐⠫⠐⠕$"

	.globl SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway
SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway: @ 0x082636DD
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "⠐⠕⠐⠡\n⠄⠕⠳⠕⠗⠄\n⠁⠎⠀⠠⠮⠫⠾⠴⠔\n⠞⠐⠳⠪⠿⠕$"

	.globl SealedChamber_InnerRoom_Braille_WeFearedIt
SealedChamber_InnerRoom_Braille_WeFearedIt: @ 0x08263700
	brailleformat 5, 6, 25, 13, 8, 9
	.braille "⠪⠄⠡⠂⠕⠎⠐⠕$"

	.globl SealedChamber_InnerRoom_Braille_ThoseWithCourageHope
SealedChamber_InnerRoom_Braille_ThoseWithCourageHope: @ 0x0826370F
	brailleformat 6, 0, 24, 19, 9, 3
	.braille "⠬⠒⠣⠀⠁⠙\n⠾⠎⠜\n⠣⠐⠮⠒⠇\n⠷⠗⠕⠀⠾⠎⠜$"

	.globl SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits
SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits: @ 0x0826372E
	brailleformat 3, 2, 27, 17, 6, 5
	.braille "⠞⠐⠧⠑⠔⠀⠁⠫⠜\n⠺⠪⠇⠀⠋⠃⠋⠴⠎\n⠠⠮⠫⠾⠴⠐⠡⠀⠃⠙$"

	.globl DesertRuins_Braille_UseRockSmash
DesertRuins_Braille_UseRockSmash: @ 0x08263753
	brailleformat 1, 0, 27, 19, 4, 3
	.braille "⠧⠐⠕⠓⠀⠧⠐⠕⠓\n⠳⠕⠀⠳⠕\n⠺⠪⠐⠟\n⠃⠄⠩⠐⠕⠣⠔⠀⠝⠡⠋$"

	.globl IslandCave_Braille_RunLapAroundWall
IslandCave_Braille_RunLapAroundWall: @ 0x0826377A
	brailleformat 5, 0, 25, 19, 8, 3
	.braille "⠡⠐⠯⠡⠑\n⠥⠅⠛⠐⠹\n⠪⠪⠔\n⠧⠞⠵⠄⠓⠀⠻⠜$"

	.globl AncientTomb_Braille_ShineInTheMiddle
AncientTomb_Braille_ShineInTheMiddle: @ 0x08263799
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "⠄⠛⠄⠛⠎⠀⠃⠳⠔\n⠝⠐⠣⠳⠀⠾⠎⠜\n⠵⠴⠅⠡⠐⠟\n⠧⠡⠓⠡⠐⠡⠌⠫$"
