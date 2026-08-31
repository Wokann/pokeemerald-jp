	.section .rodata

	.globl sGrass_Pal
sGrass_Pal: @ 0x085CDBB0
	.incbin "baserom_jp.gba", 0x5cdbb0, 0x20

	.globl sGrassSunset_Pal
sGrassSunset_Pal: @ 0x085CDBD0
	.incbin "baserom_jp.gba", 0x5cdbd0, 0x20

	.globl sGrassNight_Pal
sGrassNight_Pal: @ 0x085CDBF0
	.incbin "baserom_jp.gba", 0x5cdbf0, 0x20

	.globl sGrass_Gfx
sGrass_Gfx: @ 0x085CDC10
	.incbin "baserom_jp.gba", 0x5cdc10, 0x480

	.globl sGrass_Tilemap
sGrass_Tilemap: @ 0x085CE090
	.incbin "baserom_jp.gba", 0x5ce090, 0x13c

	.globl sCloudsBg_Pal
sCloudsBg_Pal: @ 0x085CE1CC
	.incbin "baserom_jp.gba", 0x5ce1cc, 0x60

	.globl sCloudsBgSunset_Pal
sCloudsBgSunset_Pal: @ 0x085CE22C
	.incbin "baserom_jp.gba", 0x5ce22c, 0x60

	.globl sCloudsBg_Gfx
sCloudsBg_Gfx: @ 0x085CE28C
	.incbin "baserom_jp.gba", 0x5ce28c, 0x5dc

	.globl sCloudsBg_Tilemap
sCloudsBg_Tilemap: @ 0x085CE868
	.incbin "baserom_jp.gba", 0x5ce868, 0x2d0

	.globl sClouds_Pal
sClouds_Pal: @ 0x085CEB38
	.incbin "baserom_jp.gba", 0x5ceb38, 0x20

	.globl sCloudsSunset_Pal
sCloudsSunset_Pal: @ 0x085CEB58
	.incbin "baserom_jp.gba", 0x5ceb58, 0x20

	.globl sClouds_Gfx
sClouds_Gfx: @ 0x085CEB78
	.incbin "baserom_jp.gba", 0x5ceb78, 0x13c

	.globl sTrees_Pal
sTrees_Pal: @ 0x085CECB4
	.incbin "baserom_jp.gba", 0x5cecb4, 0x20

	.globl sTreesSunset_Pal
sTreesSunset_Pal: @ 0x085CECD4
	.incbin "baserom_jp.gba", 0x5cecd4, 0x20

	.globl sTrees_Gfx
sTrees_Gfx: @ 0x085CECF4
	.incbin "baserom_jp.gba", 0x5cecf4, 0x688

	.globl sTrees_Tilemap
sTrees_Tilemap: @ 0x085CF37C
	.incbin "baserom_jp.gba", 0x5cf37c, 0x304

	.globl sTreesSmall_Pal
sTreesSmall_Pal: @ 0x085CF680
	.incbin "baserom_jp.gba", 0x5cf680, 0x20

	.globl sTreesSmall_Gfx
sTreesSmall_Gfx: @ 0x085CF6A0
	.incbin "baserom_jp.gba", 0x5cf6a0, 0x14c

	.globl sHouses_Pal
sHouses_Pal: @ 0x085CF7EC
	.incbin "baserom_jp.gba", 0x5cf7ec, 0x40

	.globl sHouses_Gfx
sHouses_Gfx: @ 0x085CF82C
	.incbin "baserom_jp.gba", 0x5cf82c, 0x1ec

	.globl sHouseSilhouette_Pal
sHouseSilhouette_Pal: @ 0x085CFA18
	.incbin "baserom_jp.gba", 0x5cfa18, 0x20

	.globl sHouses_Tilemap
sHouses_Tilemap: @ 0x085CFA38
	.incbin "baserom_jp.gba", 0x5cfa38, 0x2ae4

	.globl sSpriteTemplate_MovingScenery
sSpriteTemplate_MovingScenery: @ 0x085D251C
	.incbin "baserom_jp.gba", 0x5d251c, 0x18

	.globl sSpriteSheet_Clouds
sSpriteSheet_Clouds: @ 0x085D2534
	.incbin "baserom_jp.gba", 0x5d2534, 0x10

	.globl sCloudsAnimCmds
sCloudsAnimCmds: @ 0x085D2544
	.incbin "baserom_jp.gba", 0x5d2544, 0x20

	.globl sAnims_Clouds
sAnims_Clouds: @ 0x085D2564
	.incbin "baserom_jp.gba", 0x5d2564, 0x10

	.globl sSpriteMetadata_Clouds
sSpriteMetadata_Clouds: @ 0x085D2574
	.incbin "baserom_jp.gba", 0x5d2574, 0x48

	.globl sSpriteSheet_TreesSmall
sSpriteSheet_TreesSmall: @ 0x085D25BC
	.incbin "baserom_jp.gba", 0x5d25bc, 0x10

	.globl sTreesAnimCmds
sTreesAnimCmds: @ 0x085D25CC
	.incbin "baserom_jp.gba", 0x5d25cc, 0x18

	.globl sAnims_Trees
sAnims_Trees: @ 0x085D25E4
	.incbin "baserom_jp.gba", 0x5d25e4, 0xc

	.globl sSpriteMetadata_Trees
sSpriteMetadata_Trees: @ 0x085D25F0
	.incbin "baserom_jp.gba", 0x5d25f0, 0x60

	.globl sSpriteSheet_HouseSilhouette
sSpriteSheet_HouseSilhouette: @ 0x085D2650
	.incbin "baserom_jp.gba", 0x5d2650, 0x10

	.globl sHouseAnimCmds
sHouseAnimCmds: @ 0x085D2660
	.incbin "baserom_jp.gba", 0x5d2660, 0x8

	.globl sAnims_HouseSilhouette
sAnims_HouseSilhouette: @ 0x085D2668
	.incbin "baserom_jp.gba", 0x5d2668, 0x4

	.globl sSpriteMetadata_HouseSilhouette
sSpriteMetadata_HouseSilhouette: @ 0x085D266C
	.incbin "baserom_jp.gba", 0x5d266c, 0x30

	.globl sPlayerSpriteData
sPlayerSpriteData: @ 0x085D269C
	.incbin "baserom_jp.gba", 0x5d269c, 0x20

	.globl sSpriteTemplate_Brendan
sSpriteTemplate_Brendan: @ 0x085D26BC
	.incbin "baserom_jp.gba", 0x5d26bc, 0x18

	.globl sSpriteTemplate_May
sSpriteTemplate_May: @ 0x085D26D4
	.incbin "baserom_jp.gba", 0x5d26d4, 0x18

	.globl sBicycleSpriteData
sBicycleSpriteData: @ 0x085D26EC
	.incbin "baserom_jp.gba", 0x5d26ec, 0x20

	.globl sSpriteTemplate_BrendanBicycle
sSpriteTemplate_BrendanBicycle: @ 0x085D270C
	.incbin "baserom_jp.gba", 0x5d270c, 0x18

	.globl sSpriteTemplate_MayBicycle
sSpriteTemplate_MayBicycle: @ 0x085D2724
	.incbin "baserom_jp.gba", 0x5d2724, 0x18

	.globl sFlygonSpriteData
sFlygonSpriteData: @ 0x085D273C
	.incbin "baserom_jp.gba", 0x5d273c, 0x20

	.globl sSpriteTemplate_FlygonLatios
sSpriteTemplate_FlygonLatios: @ 0x085D275C
	.incbin "baserom_jp.gba", 0x5d275c, 0x18

	.globl sSpriteTemplate_FlygonLatias
sSpriteTemplate_FlygonLatias: @ 0x085D2774
	.incbin "baserom_jp.gba", 0x5d2774, 0x18

	.globl gSpriteSheet_IntroBrendan
gSpriteSheet_IntroBrendan: @ 0x085D278C
	.incbin "baserom_jp.gba", 0x5d278c, 0x10

	.globl gSpriteSheet_IntroMay
gSpriteSheet_IntroMay: @ 0x085D279C
	.incbin "baserom_jp.gba", 0x5d279c, 0x10

	.globl gSpriteSheet_IntroBicycle
gSpriteSheet_IntroBicycle: @ 0x085D27AC
	.incbin "baserom_jp.gba", 0x5d27ac, 0x10

	.globl sSpriteSheet_IntroFlygon_Unused
sSpriteSheet_IntroFlygon_Unused: @ 0x085D27BC
	.incbin "baserom_jp.gba", 0x5d27bc, 0x10

	.globl gSpriteSheet_IntroFlygon
gSpriteSheet_IntroFlygon: @ 0x085D27CC
	.incbin "baserom_jp.gba", 0x5d27cc, 0x10

	.globl gSpritePalettes_IntroPlayerFlygon
gSpritePalettes_IntroPlayerFlygon: @ 0x085D27DC
	.incbin "baserom_jp.gba", 0x5d27dc, 0x28

	.globl gSpriteSheet_CreditsBrendan
gSpriteSheet_CreditsBrendan: @ 0x085D2804
	.incbin "baserom_jp.gba", 0x5d2804, 0x10

	.globl gSpriteSheet_CreditsMay
gSpriteSheet_CreditsMay: @ 0x085D2814
	.incbin "baserom_jp.gba", 0x5d2814, 0x10

	.globl gSpriteSheet_CreditsBicycle
gSpriteSheet_CreditsBicycle: @ 0x085D2824
	.incbin "baserom_jp.gba", 0x5d2824, 0x10

	.globl sSpriteSheet_Latios
sSpriteSheet_Latios: @ 0x085D2834
	.incbin "baserom_jp.gba", 0x5d2834, 0x10

	.globl sSpriteSheet_Latias
sSpriteSheet_Latias: @ 0x085D2844
	.incbin "baserom_jp.gba", 0x5d2844, 0x10

	.globl gSpritePalettes_Credits
gSpritePalettes_Credits: @ 0x085D2854
	.incbin "baserom_jp.gba", 0x5d2854, 0x28

	.globl gSpriteSheet_CreditsRivalBrendan
gSpriteSheet_CreditsRivalBrendan: @ 0x085D287C
	.incbin "baserom_jp.gba", 0x5d287c, 0x10

	.globl gSpriteSheet_CreditsRivalMay
gSpriteSheet_CreditsRivalMay: @ 0x085D288C
	.incbin "baserom_jp.gba", 0x5d288c, 0x10
