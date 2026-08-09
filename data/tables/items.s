	.globl gItems
	.globl gUnknown_855CEE8
gItems:
gUnknown_855CEE8:

	@ 000 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 001 "マスターボール"
	.string "マスターボール${SE_RG_SHOP}"
	.2byte 0x0001  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855A9D0  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x02  @ pocket
	.byte 0x00  @ type
	.4byte 0x00000000  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PokeBall  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 002 "ハイパーボール"
	.string "ハイパーボール${SE_RG_SHOP}"
	.2byte 0x0002  @ itemId
	.2byte 0x04B0  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855A9F2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x02  @ pocket
	.byte 0x01  @ type
	.4byte 0x00000000  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PokeBall  @ battleUseFunc
	.byte 0x01  @ secondaryId
	.space 3  @ padding

	@ 003 "スーパーボール"
	.string "スーパーボール${SE_RG_SHOP}"
	.2byte 0x0003  @ itemId
	.2byte 0x0258  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AA15  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x02  @ pocket
	.byte 0x02  @ type
	.4byte 0x00000000  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PokeBall  @ battleUseFunc
	.byte 0x02  @ secondaryId
	.space 3  @ padding

	@ 004 "モンスターボール"
	.string "モンスターボール{SE_RG_SHOP}"
	.2byte 0x0004  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AA39  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x02  @ pocket
	.byte 0x03  @ type
	.4byte 0x00000000  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PokeBall  @ battleUseFunc
	.byte 0x03  @ secondaryId
	.space 3  @ padding

	@ 005 "サファリボール"
	.string "サファリボール${SE_RG_SHOP}"
	.2byte 0x0005  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AA50  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x02  @ pocket
	.byte 0x04  @ type
	.4byte 0x00000000  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PokeBall  @ battleUseFunc
	.byte 0x04  @ secondaryId
	.space 3  @ padding

	@ 006 "ネットボール"
	.string "ネットボール$${SE_RG_SHOP}"
	.2byte 0x0006  @ itemId
	.2byte 0x03E8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AA71  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x02  @ pocket
	.byte 0x05  @ type
	.4byte 0x00000000  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PokeBall  @ battleUseFunc
	.byte 0x05  @ secondaryId
	.space 3  @ padding

	@ 007 "ダイブボール"
	.string "ダイブボール$${SE_RG_SHOP}"
	.2byte 0x0007  @ itemId
	.2byte 0x03E8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AA91  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x02  @ pocket
	.byte 0x06  @ type
	.4byte 0x00000000  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PokeBall  @ battleUseFunc
	.byte 0x06  @ secondaryId
	.space 3  @ padding

	@ 008 "ネストボール"
	.string "ネストボール$${SE_RG_SHOP}"
	.2byte 0x0008  @ itemId
	.2byte 0x03E8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AAAF  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x02  @ pocket
	.byte 0x07  @ type
	.4byte 0x00000000  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PokeBall  @ battleUseFunc
	.byte 0x07  @ secondaryId
	.space 3  @ padding

	@ 009 "リピートボール"
	.string "リピートボール${SE_RG_SHOP}"
	.2byte 0x0009  @ itemId
	.2byte 0x03E8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AAD0  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x02  @ pocket
	.byte 0x08  @ type
	.4byte 0x00000000  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PokeBall  @ battleUseFunc
	.byte 0x08  @ secondaryId
	.space 3  @ padding

	@ 010 "タイマーボール"
	.string "タイマーボール${SE_RG_SHOP}"
	.2byte 0x000A  @ itemId
	.2byte 0x03E8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AAF2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x02  @ pocket
	.byte 0x09  @ type
	.4byte 0x00000000  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PokeBall  @ battleUseFunc
	.byte 0x09  @ secondaryId
	.space 3  @ padding

	@ 011 "ゴージャスボール"
	.string "ゴージャスボール{SE_RG_SHOP}"
	.2byte 0x000B  @ itemId
	.2byte 0x03E8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AB13  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x02  @ pocket
	.byte 0x0A  @ type
	.4byte 0x00000000  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PokeBall  @ battleUseFunc
	.byte 0x0A  @ secondaryId
	.space 3  @ padding

	@ 012 "プレミアボール"
	.string "プレミアボール${SE_RG_SHOP}"
	.2byte 0x000C  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AB36  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x02  @ pocket
	.byte 0x0B  @ type
	.4byte 0x00000000  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PokeBall  @ battleUseFunc
	.byte 0x0B  @ secondaryId
	.space 3  @ padding

	@ 013 "キズぐ{DYNAMIC_COLOR4}り"
	.string "キズぐ{DYNAMIC_COLOR4}り$$${SE_RG_SHOP}"
	.2byte 0x000D  @ itemId
	.2byte 0x012C  @ price
	.byte 0x00  @ holdEffect
	.byte 0x14  @ holdEffectParam
	.4byte 0x0855AB55  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 014 "ど{BLUE}{LIGHT_BLUE}{DYNAMIC_COLOR3}"
	.string "ど{BLUE}{LIGHT_BLUE}{DYNAMIC_COLOR3}$$$${SE_RG_SHOP}"
	.2byte 0x000E  @ itemId
	.2byte 0x0064  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AB6C  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 015 "や{LIGHT_BLUE}どな{LIGHT_RED}{DYNAMIC_COLOR3}"
	.string "や{LIGHT_BLUE}どな{LIGHT_RED}{DYNAMIC_COLOR3}$${SE_RG_SHOP}"
	.2byte 0x000F  @ itemId
	.2byte 0x00FA  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AB7D  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 016 "{DYNAMIC_COLOR1}{LIGHT_RED}りな{LIGHT_RED}{DYNAMIC_COLOR3}"
	.string "{DYNAMIC_COLOR1}{LIGHT_RED}りな{LIGHT_RED}{DYNAMIC_COLOR3}$${SE_RG_SHOP}"
	.2byte 0x0010  @ itemId
	.2byte 0x00FA  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AB8F  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 017 "ねむ{LIGHT_BLUE}ざま{DYNAMIC_COLOR3}"
	.string "ねむ{LIGHT_BLUE}ざま{DYNAMIC_COLOR3}$${SE_RG_SHOP}"
	.2byte 0x0011  @ itemId
	.2byte 0x00FA  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855ABA1  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 018 "まひな{LIGHT_RED}{DYNAMIC_COLOR3}"
	.string "まひな{LIGHT_RED}{DYNAMIC_COLOR3}$$${SE_RG_SHOP}"
	.2byte 0x0012  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855ABB3  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 019 "{MUS_RG_POKE_TOWER}ふ{BLUE}の{BLUE}{DYNAMIC_COLOR4}り"
	.string "{MUS_RG_POKE_TOWER}ふ{BLUE}の{BLUE}{DYNAMIC_COLOR4}り{SE_RG_SHOP}"
	.2byte 0x0013  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0xFF  @ holdEffectParam
	.4byte 0x0855ABC4  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 020 "まんたんの{BLUE}{DYNAMIC_COLOR4}り"
	.string "まんたんの{BLUE}{DYNAMIC_COLOR4}り{SE_RG_SHOP}"
	.2byte 0x0014  @ itemId
	.2byte 0x09C4  @ price
	.byte 0x00  @ holdEffect
	.byte 0xFF  @ holdEffectParam
	.4byte 0x0855ABE6  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 021 "{DYNAMIC_COLOR4}{PH_FLEECE_BLEND}キズぐ{DYNAMIC_COLOR4}り"
	.string "{DYNAMIC_COLOR4}{PH_FLEECE_BLEND}キズぐ{DYNAMIC_COLOR4}り{SE_RG_SHOP}"
	.2byte 0x0015  @ itemId
	.2byte 0x04B0  @ price
	.byte 0x00  @ holdEffect
	.byte 0xC8  @ holdEffectParam
	.4byte 0x0855ABFC  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 022 "{MUS_RG_OAK}キズぐ{DYNAMIC_COLOR4}り"
	.string "{MUS_RG_OAK}キズぐ{DYNAMIC_COLOR4}り${SE_RG_SHOP}"
	.2byte 0x0016  @ itemId
	.2byte 0x02BC  @ price
	.byte 0x00  @ holdEffect
	.byte 0x32  @ holdEffectParam
	.4byte 0x0855AC14  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 023 "なんでもな{LIGHT_RED}{DYNAMIC_COLOR3}"
	.string "なんでもな{LIGHT_RED}{DYNAMIC_COLOR3}${SE_RG_SHOP}"
	.2byte 0x0017  @ itemId
	.2byte 0x0258  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AC2B  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 024 "げん{LIGHT_GREEN}の{GREEN}{LIGHT_BLUE}ら"
	.string "げん{LIGHT_GREEN}の{GREEN}{LIGHT_BLUE}ら${SE_RG_SHOP}"
	.2byte 0x0018  @ itemId
	.2byte 0x05DC  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AC42  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 025 "げん{LIGHT_GREEN}の{GREEN}たまり"
	.string "げん{LIGHT_GREEN}の{GREEN}たまり{SE_RG_SHOP}"
	.2byte 0x0019  @ itemId
	.2byte 0x0FA0  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AC62  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 026 "{MUS_RG_SURF}{MUS_RG_VICTORY_GYM_LEADER}みず"
	.string "{MUS_RG_SURF}{MUS_RG_VICTORY_GYM_LEADER}みず$${SE_RG_SHOP}"
	.2byte 0x001A  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x32  @ holdEffectParam
	.4byte 0x0855AC7E  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 027 "サイコソーダ"
	.string "サイコソーダ$${SE_RG_SHOP}"
	.2byte 0x001B  @ itemId
	.2byte 0x012C  @ price
	.byte 0x00  @ holdEffect
	.byte 0x3C  @ holdEffectParam
	.4byte 0x0855ACA2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 028 "ミックスオレ"
	.string "ミックスオレ$${SE_RG_SHOP}"
	.2byte 0x001C  @ itemId
	.2byte 0x015E  @ price
	.byte 0x00  @ holdEffect
	.byte 0x50  @ holdEffectParam
	.4byte 0x0855ACC5  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 029 "モーモーミルク"
	.string "モーモーミルク${SE_RG_SHOP}"
	.2byte 0x001D  @ itemId
	.2byte 0x01F4  @ price
	.byte 0x00  @ holdEffect
	.byte 0x64  @ holdEffectParam
	.4byte 0x0855ACE6  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 030 "ち{GREEN}らの{DYNAMIC_COLOR1}な"
	.string "ち{GREEN}らの{DYNAMIC_COLOR1}な$${SE_RG_SHOP}"
	.2byte 0x001E  @ itemId
	.2byte 0x01F4  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AD08  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 031 "ち{GREEN}らのねっ{DYNAMIC_COLOR1}"
	.string "ち{GREEN}らのねっ{DYNAMIC_COLOR1}${SE_RG_SHOP}"
	.2byte 0x001F  @ itemId
	.2byte 0x0320  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AD2A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 032 "ばんの{LIGHT_GRAY}ごな"
	.string "ばんの{LIGHT_GRAY}ごな$${SE_RG_SHOP}"
	.2byte 0x0020  @ itemId
	.2byte 0x01C2  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AD4E  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 033 "ふっ{GREEN}つ{DYNAMIC_COLOR6}{LIGHT_GRAY}"
	.string "ふっ{GREEN}つ{DYNAMIC_COLOR6}{LIGHT_GRAY}$${SE_RG_SHOP}"
	.2byte 0x0021  @ itemId
	.2byte 0x0AF0  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AD70  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 034 "ピーピーエイド"
	.string "ピーピーエイド${SE_RG_SHOP}"
	.2byte 0x0022  @ itemId
	.2byte 0x04B0  @ price
	.byte 0x00  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855AD8E  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_PPRecovery  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PPRecovery  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 035 "ピーピーリカバー"
	.string "ピーピーリカバー{SE_RG_SHOP}"
	.2byte 0x0023  @ itemId
	.2byte 0x07D0  @ price
	.byte 0x00  @ holdEffect
	.byte 0xFF  @ holdEffectParam
	.4byte 0x0855ADA8  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_PPRecovery  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PPRecovery  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 036 "ピーピーエイダー"
	.string "ピーピーエイダー{SE_RG_SHOP}"
	.2byte 0x0024  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855ADC1  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_PPRecovery  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PPRecovery  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 037 "ピーピーマックス"
	.string "ピーピーマックス{SE_RG_SHOP}"
	.2byte 0x0025  @ itemId
	.2byte 0x1194  @ price
	.byte 0x00  @ holdEffect
	.byte 0xFF  @ holdEffectParam
	.4byte 0x0855ADDC  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_PPRecovery  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PPRecovery  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 038 "フエン{DYNAMIC_COLOR5}ん{PH_GOAT_SOLO}"
	.string "フエン{DYNAMIC_COLOR5}ん{PH_GOAT_SOLO}${SE_RG_SHOP}"
	.2byte 0x0026  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855ADFC  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 039 "{WHITE}{MUS_RG_SURF}ビードロ"
	.string "{WHITE}{MUS_RG_SURF}ビードロ${SE_RG_SHOP}"
	.2byte 0x0027  @ itemId
	.2byte 0x0064  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AE1D  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 040 "{MUS_RG_SILPH}ろビードロ"
	.string "{MUS_RG_SILPH}ろビードロ${SE_RG_SHOP}"
	.2byte 0x0028  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AE3B  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 041 "{WHITE}{MUS_RG_POKE_TOWER}ビードロ"
	.string "{WHITE}{MUS_RG_POKE_TOWER}ビードロ${SE_RG_SHOP}"
	.2byte 0x0029  @ itemId
	.2byte 0x012C  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AE5A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 042 "{BLUE}{MUS_RG_ENCOUNTER_DEOXYS}ビードロ"
	.string "{BLUE}{MUS_RG_ENCOUNTER_DEOXYS}ビードロ${SE_RG_SHOP}"
	.2byte 0x002A  @ itemId
	.2byte 0x0190  @ price
	.byte 0x00  @ holdEffect
	.byte 0x32  @ holdEffectParam
	.4byte 0x0855AE79  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_BlackWhiteFlute  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 043 "{DYNAMIC_COLOR3}{MUS_RG_ENCOUNTER_DEOXYS}ビードロ"
	.string "{DYNAMIC_COLOR3}{MUS_RG_ENCOUNTER_DEOXYS}ビードロ${SE_RG_SHOP}"
	.2byte 0x002B  @ itemId
	.2byte 0x01F4  @ price
	.byte 0x00  @ holdEffect
	.byte 0x96  @ holdEffectParam
	.4byte 0x0855AE9B  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_BlackWhiteFlute  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 044 "{LIGHT_GREEN}のみジュース"
	.string "{LIGHT_GREEN}のみジュース${SE_RG_SHOP}"
	.2byte 0x002C  @ itemId
	.2byte 0x0064  @ price
	.byte 0x01  @ holdEffect
	.byte 0x14  @ holdEffectParam
	.4byte 0x0855AEBD  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 045 "{MUS_RG_PEWTER}なる{MUS_RG_POKE_JUMP}"
	.string "{MUS_RG_PEWTER}なる{MUS_RG_POKE_JUMP}$${SE_RG_SHOP}"
	.2byte 0x002D  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AEE1  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_SacredAsh  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 046 "{WHITE}{DYNAMIC_COLOR2}{DYNAMIC_COLOR5}の{DYNAMIC_COLOR3}{LIGHT_RED}"
	.string "{WHITE}{DYNAMIC_COLOR2}{DYNAMIC_COLOR5}の{DYNAMIC_COLOR3}{LIGHT_RED}$${SE_RG_SHOP}"
	.2byte 0x002E  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AF04  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 047 "{WHITE}{DYNAMIC_COLOR2}{DYNAMIC_COLOR5}の{MUS_RG_POKE_TOWER}がら"
	.string "{WHITE}{DYNAMIC_COLOR2}{DYNAMIC_COLOR5}の{MUS_RG_POKE_TOWER}がら{SE_RG_SHOP}"
	.2byte 0x002F  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AF16  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 048 "{WHITE}{MUS_RG_POKE_TOWER}{GREEN}{LIGHT_BLUE}ら"
	.string "{WHITE}{MUS_RG_POKE_TOWER}{GREEN}{LIGHT_BLUE}ら$${SE_RG_SHOP}"
	.2byte 0x0030  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AF2A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 049 "{WHITE}{MUS_RG_SURF}{GREEN}{LIGHT_BLUE}ら"
	.string "{WHITE}{MUS_RG_SURF}{GREEN}{LIGHT_BLUE}ら$${SE_RG_SHOP}"
	.2byte 0x0031  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AF4A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 050 "{MUS_RG_SILPH}{MUS_RG_ENCOUNTER_DEOXYS}{GREEN}{LIGHT_BLUE}ら"
	.string "{MUS_RG_SILPH}{MUS_RG_ENCOUNTER_DEOXYS}{GREEN}{LIGHT_BLUE}ら${SE_RG_SHOP}"
	.2byte 0x0032  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AF6A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 051 "みどりの{GREEN}{LIGHT_BLUE}ら"
	.string "みどりの{GREEN}{LIGHT_BLUE}ら${SE_RG_SHOP}"
	.2byte 0x0033  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AF8A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 052 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 053 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 054 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 055 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 056 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 057 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 058 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 059 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 060 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 061 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 062 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 063 "マックスアップ"
	.string "マックスアップ${SE_RG_SHOP}"
	.2byte 0x003F  @ itemId
	.2byte 0x2648  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AFAA  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 064 "タウリン"
	.string "タウリン$$$${SE_RG_SHOP}"
	.2byte 0x0040  @ itemId
	.2byte 0x2648  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AFBD  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 065 "ブロムヘキシン"
	.string "ブロムヘキシン${SE_RG_SHOP}"
	.2byte 0x0041  @ itemId
	.2byte 0x2648  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AFCF  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 066 "インドメタシン"
	.string "インドメタシン${SE_RG_SHOP}"
	.2byte 0x0042  @ itemId
	.2byte 0x2648  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AFE1  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 067 "リゾチウム"
	.string "リゾチウム$$${SE_RG_SHOP}"
	.2byte 0x0043  @ itemId
	.2byte 0x2648  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855AFF3  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 068 "ふ{DYNAMIC_COLOR3}ぎなアメ"
	.string "ふ{DYNAMIC_COLOR3}ぎなアメ$${SE_RG_SHOP}"
	.2byte 0x0044  @ itemId
	.2byte 0x12C0  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B005  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_RareCandy  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 069 "ポイントアップ"
	.string "ポイントアップ${SE_RG_SHOP}"
	.2byte 0x0045  @ itemId
	.2byte 0x2648  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B016  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_PPUp  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 070 "キトサン"
	.string "キトサン$$$${SE_RG_SHOP}"
	.2byte 0x0046  @ itemId
	.2byte 0x2648  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B029  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 071 "ポイントマックス"
	.string "ポイントマックス{SE_RG_SHOP}"
	.2byte 0x0047  @ itemId
	.2byte 0x2648  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B03B  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_PPUp  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 072 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 073 "エフェクトガード"
	.string "エフェクトガード{SE_RG_SHOP}"
	.2byte 0x0049  @ itemId
	.2byte 0x02BC  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B04F  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_StatIncrease  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 074 "クリティカッター"
	.string "クリティカッター{SE_RG_SHOP}"
	.2byte 0x004A  @ itemId
	.2byte 0x028A  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B06F  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_StatIncrease  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 075 "プラスパワー"
	.string "プラスパワー$${SE_RG_SHOP}"
	.2byte 0x004B  @ itemId
	.2byte 0x01F4  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B091  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_StatIncrease  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 076 "ディフェンダー"
	.string "ディフェンダー${SE_RG_SHOP}"
	.2byte 0x004C  @ itemId
	.2byte 0x0226  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B0AB  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_StatIncrease  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 077 "スピーダー"
	.string "スピーダー$$${SE_RG_SHOP}"
	.2byte 0x004D  @ itemId
	.2byte 0x015E  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B0C5  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_StatIncrease  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 078 "ヨクアタール"
	.string "ヨクアタール$${SE_RG_SHOP}"
	.2byte 0x004E  @ itemId
	.2byte 0x03B6  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B0DC  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_StatIncrease  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 079 "スペシャルアップ"
	.string "スペシャルアップ{SE_RG_SHOP}"
	.2byte 0x004F  @ itemId
	.2byte 0x015E  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B0F6  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_StatIncrease  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 080 "ピッピにんぎょ{LIGHT_GRAY}"
	.string "ピッピにんぎょ{LIGHT_GRAY}{SE_RG_SHOP}"
	.2byte 0x0050  @ itemId
	.2byte 0x03E8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B113  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Escape  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 081 "エネコのシッポ"
	.string "エネコのシッポ${SE_RG_SHOP}"
	.2byte 0x0051  @ itemId
	.2byte 0x03E8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B136  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x02  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Escape  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 082 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 083 "シルバースプレー"
	.string "シルバースプレー{SE_RG_SHOP}"
	.2byte 0x0053  @ itemId
	.2byte 0x01F4  @ price
	.byte 0x00  @ holdEffect
	.byte 0xC8  @ holdEffectParam
	.4byte 0x0855B159  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_Repel  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 084 "ゴールドスプレー"
	.string "ゴールドスプレー{SE_RG_SHOP}"
	.2byte 0x0054  @ itemId
	.2byte 0x02BC  @ price
	.byte 0x00  @ holdEffect
	.byte 0xFA  @ holdEffectParam
	.4byte 0x0855B17B  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_Repel  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 085 "{WHITE}なぬ{LIGHT_BLUE}のヒモ"
	.string "{WHITE}なぬ{LIGHT_BLUE}のヒモ${SE_RG_SHOP}"
	.2byte 0x0055  @ itemId
	.2byte 0x0226  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B19D  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x02  @ type
	.4byte ItemUseOutOfBattle_EscapeRope  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 086 "む{DYNAMIC_COLOR3}よ{LIGHT_BLUE}スプレー"
	.string "む{DYNAMIC_COLOR3}よ{LIGHT_BLUE}スプレー{SE_RG_SHOP}"
	.2byte 0x0056  @ itemId
	.2byte 0x015E  @ price
	.byte 0x00  @ holdEffect
	.byte 0x64  @ holdEffectParam
	.4byte 0x0855B1B0  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_Repel  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 087 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 088 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 089 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 090 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 091 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 092 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 093 "{MUS_RG_RIVAL_EXIT}よ{LIGHT_GRAY}{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}"
	.string "{MUS_RG_RIVAL_EXIT}よ{LIGHT_GRAY}{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}${SE_RG_SHOP}"
	.2byte 0x005D  @ itemId
	.2byte 0x0834  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B1D2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_EvolutionStone  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 094 "つ{LIGHT_GREEN}{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}"
	.string "つ{LIGHT_GREEN}{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}$$${SE_RG_SHOP}"
	.2byte 0x005E  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B1E5  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_EvolutionStone  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 095 "ほの{LIGHT_RED}{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}"
	.string "ほの{LIGHT_RED}{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}$${SE_RG_SHOP}"
	.2byte 0x005F  @ itemId
	.2byte 0x0834  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B1F8  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_EvolutionStone  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 096 "{GREEN}みなり{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}"
	.string "{GREEN}みなり{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}${SE_RG_SHOP}"
	.2byte 0x0060  @ itemId
	.2byte 0x0834  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B20B  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_EvolutionStone  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 097 "みず{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}"
	.string "みず{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}$$${SE_RG_SHOP}"
	.2byte 0x0061  @ itemId
	.2byte 0x0834  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B21E  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_EvolutionStone  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 098 "リーフ{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}"
	.string "リーフ{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}$${SE_RG_SHOP}"
	.2byte 0x0062  @ itemId
	.2byte 0x0834  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B231  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_EvolutionStone  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 099 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 100 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 101 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 102 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 103 "{MUS_RG_DEX_RATING}{DYNAMIC_COLOR2}なキノコ"
	.string "{MUS_RG_DEX_RATING}{DYNAMIC_COLOR2}なキノコ${SE_RG_SHOP}"
	.2byte 0x0067  @ itemId
	.2byte 0x01F4  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B244  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 104 "{LIGHT_RED}{LIGHT_RED}{LIGHT_GREEN}なキノコ"
	.string "{LIGHT_RED}{LIGHT_RED}{LIGHT_GREEN}なキノコ${SE_RG_SHOP}"
	.2byte 0x0068  @ itemId
	.2byte 0x1388  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B255  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 105 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 106 "{DYNAMIC_COLOR3}んじゅ"
	.string "{DYNAMIC_COLOR3}んじゅ$$$${SE_RG_SHOP}"
	.2byte 0x006A  @ itemId
	.2byte 0x0578  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B267  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 107 "{LIGHT_RED}{LIGHT_RED}{LIGHT_GREEN}な{DYNAMIC_COLOR3}んじゅ"
	.string "{LIGHT_RED}{LIGHT_RED}{LIGHT_GREEN}な{DYNAMIC_COLOR3}んじゅ{SE_RG_SHOP}"
	.2byte 0x006B  @ itemId
	.2byte 0x1D4C  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B279  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 108 "ほ{DYNAMIC_COLOR3}の{DYNAMIC_COLOR4}な"
	.string "ほ{DYNAMIC_COLOR3}の{DYNAMIC_COLOR4}な$$${SE_RG_SHOP}"
	.2byte 0x006C  @ itemId
	.2byte 0x07D0  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B295  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 109 "ほ{DYNAMIC_COLOR3}の{GREEN}{LIGHT_BLUE}ら"
	.string "ほ{DYNAMIC_COLOR3}の{GREEN}{LIGHT_BLUE}ら$${SE_RG_SHOP}"
	.2byte 0x006D  @ itemId
	.2byte 0x2648  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B2AA  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 110 "{LIGHT_GREEN}んのたま"
	.string "{LIGHT_GREEN}んのたま$$${SE_RG_SHOP}"
	.2byte 0x006E  @ itemId
	.2byte 0x2710  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B2CA  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 111 "ハートのウロコ"
	.string "ハートのウロコ${SE_RG_SHOP}"
	.2byte 0x006F  @ itemId
	.2byte 0x0064  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B2DB  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 112 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 113 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 114 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 115 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 116 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 117 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 118 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 119 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 120 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 121 "オレンジメール"
	.string "オレンジメール${SE_RG_SHOP}"
	.2byte 0x0079  @ itemId
	.2byte 0x0032  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B2F7  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x00  @ type
	.4byte ItemUseOutOfBattle_Mail  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 122 "ハーバーメール"
	.string "ハーバーメール${SE_RG_SHOP}"
	.2byte 0x007A  @ itemId
	.2byte 0x0032  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B31B  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x00  @ type
	.4byte ItemUseOutOfBattle_Mail  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x01  @ secondaryId
	.space 3  @ padding

	@ 123 "キラキラメール"
	.string "キラキラメール${SE_RG_SHOP}"
	.2byte 0x007B  @ itemId
	.2byte 0x0032  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B33E  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x00  @ type
	.4byte ItemUseOutOfBattle_Mail  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x02  @ secondaryId
	.space 3  @ padding

	@ 124 "メカニカルメール"
	.string "メカニカルメール{SE_RG_SHOP}"
	.2byte 0x007C  @ itemId
	.2byte 0x0032  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B362  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x00  @ type
	.4byte ItemUseOutOfBattle_Mail  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x03  @ secondaryId
	.space 3  @ padding

	@ 125 "ウッディメール"
	.string "ウッディメール${SE_RG_SHOP}"
	.2byte 0x007D  @ itemId
	.2byte 0x0032  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B384  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x00  @ type
	.4byte ItemUseOutOfBattle_Mail  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x04  @ secondaryId
	.space 3  @ padding

	@ 126 "クロスメール"
	.string "クロスメール$${SE_RG_SHOP}"
	.2byte 0x007E  @ itemId
	.2byte 0x0032  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B3A7  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x00  @ type
	.4byte ItemUseOutOfBattle_Mail  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x05  @ secondaryId
	.space 3  @ padding

	@ 127 "トレジャーメール"
	.string "トレジャーメール{SE_RG_SHOP}"
	.2byte 0x007F  @ itemId
	.2byte 0x0032  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B3CA  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x00  @ type
	.4byte ItemUseOutOfBattle_Mail  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x06  @ secondaryId
	.space 3  @ padding

	@ 128 "シャドーメール"
	.string "シャドーメール${SE_RG_SHOP}"
	.2byte 0x0080  @ itemId
	.2byte 0x0032  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B3E2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x00  @ type
	.4byte ItemUseOutOfBattle_Mail  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x07  @ secondaryId
	.space 3  @ padding

	@ 129 "トロピカルメール"
	.string "トロピカルメール{SE_RG_SHOP}"
	.2byte 0x0081  @ itemId
	.2byte 0x0032  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B405  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x00  @ type
	.4byte ItemUseOutOfBattle_Mail  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x08  @ secondaryId
	.space 3  @ padding

	@ 130 "ドリームメール"
	.string "ドリームメール${SE_RG_SHOP}"
	.2byte 0x0082  @ itemId
	.2byte 0x0032  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B429  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x00  @ type
	.4byte ItemUseOutOfBattle_Mail  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x09  @ secondaryId
	.space 3  @ padding

	@ 131 "ミラクルメール"
	.string "ミラクルメール${SE_RG_SHOP}"
	.2byte 0x0083  @ itemId
	.2byte 0x0032  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B441  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x00  @ type
	.4byte ItemUseOutOfBattle_Mail  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x0A  @ secondaryId
	.space 3  @ padding

	@ 132 "レトロメール"
	.string "レトロメール$${SE_RG_SHOP}"
	.2byte 0x0084  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B463  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x00  @ type
	.4byte ItemUseOutOfBattle_Mail  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x0B  @ secondaryId
	.space 3  @ padding

	@ 133 "クラボのみ"
	.string "クラボのみ$$${SE_RG_SHOP}"
	.2byte 0x0085  @ itemId
	.2byte 0x0014  @ price
	.byte 0x02  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B486  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 134 "カゴのみ"
	.string "カゴのみ$$$${SE_RG_SHOP}"
	.2byte 0x0086  @ itemId
	.2byte 0x0014  @ price
	.byte 0x03  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B4A2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 135 "モモンのみ"
	.string "モモンのみ$$${SE_RG_SHOP}"
	.2byte 0x0087  @ itemId
	.2byte 0x0014  @ price
	.byte 0x04  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B4BF  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 136 "チーゴのみ"
	.string "チーゴのみ$$${SE_RG_SHOP}"
	.2byte 0x0088  @ itemId
	.2byte 0x0014  @ price
	.byte 0x05  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B4DB  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 137 "ナナシのみ"
	.string "ナナシのみ$$${SE_RG_SHOP}"
	.2byte 0x0089  @ itemId
	.2byte 0x0014  @ price
	.byte 0x06  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B4F8  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 138 "ヒメリのみ"
	.string "ヒメリのみ$$${SE_RG_SHOP}"
	.2byte 0x008A  @ itemId
	.2byte 0x0014  @ price
	.byte 0x07  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855B515  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_PPRecovery  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_PPRecovery  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 139 "オレンのみ"
	.string "オレンのみ$$${SE_RG_SHOP}"
	.2byte 0x008B  @ itemId
	.2byte 0x0014  @ price
	.byte 0x01  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855B532  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 140 "キーのみ"
	.string "キーのみ$$$${SE_RG_SHOP}"
	.2byte 0x008C  @ itemId
	.2byte 0x0014  @ price
	.byte 0x08  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B54E  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 141 "ラムのみ"
	.string "ラムのみ$$$${SE_RG_SHOP}"
	.2byte 0x008D  @ itemId
	.2byte 0x0014  @ price
	.byte 0x09  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B56C  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 142 "オボンのみ"
	.string "オボンのみ$$${SE_RG_SHOP}"
	.2byte 0x008E  @ itemId
	.2byte 0x0014  @ price
	.byte 0x01  @ holdEffect
	.byte 0x1E  @ holdEffectParam
	.4byte 0x0855B58A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_Medicine  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_Medicine  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 143 "フィラのみ"
	.string "フィラのみ$$${SE_RG_SHOP}"
	.2byte 0x008F  @ itemId
	.2byte 0x0014  @ price
	.byte 0x0A  @ holdEffect
	.byte 0x08  @ holdEffectParam
	.4byte 0x0855B5A6  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 144 "ウイのみ"
	.string "ウイのみ$$$${SE_RG_SHOP}"
	.2byte 0x0090  @ itemId
	.2byte 0x0014  @ price
	.byte 0x0B  @ holdEffect
	.byte 0x08  @ holdEffectParam
	.4byte 0x0855B5CA  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 145 "マゴのみ"
	.string "マゴのみ$$$${SE_RG_SHOP}"
	.2byte 0x0091  @ itemId
	.2byte 0x0014  @ price
	.byte 0x0C  @ holdEffect
	.byte 0x08  @ holdEffectParam
	.4byte 0x0855B5EE  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 146 "バンジのみ"
	.string "バンジのみ$$${SE_RG_SHOP}"
	.2byte 0x0092  @ itemId
	.2byte 0x0014  @ price
	.byte 0x0D  @ holdEffect
	.byte 0x08  @ holdEffectParam
	.4byte 0x0855B612  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 147 "イアのみ"
	.string "イアのみ$$$${SE_RG_SHOP}"
	.2byte 0x0093  @ itemId
	.2byte 0x0014  @ price
	.byte 0x0E  @ holdEffect
	.byte 0x08  @ holdEffectParam
	.4byte 0x0855B636  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 148 "ズリのみ"
	.string "ズリのみ$$$${SE_RG_SHOP}"
	.2byte 0x0094  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B65A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 149 "ブリーのみ"
	.string "ブリーのみ$$${SE_RG_SHOP}"
	.2byte 0x0095  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B67A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 150 "ナナのみ"
	.string "ナナのみ$$$${SE_RG_SHOP}"
	.2byte 0x0096  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B69B  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 151 "セシナのみ"
	.string "セシナのみ$$${SE_RG_SHOP}"
	.2byte 0x0097  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B6BB  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 152 "パイルのみ"
	.string "パイルのみ$$${SE_RG_SHOP}"
	.2byte 0x0098  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B6DC  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 153 "ザロクのみ"
	.string "ザロクのみ$$${SE_RG_SHOP}"
	.2byte 0x0099  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B6FD  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_ReduceEV  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 154 "ネコブのみ"
	.string "ネコブのみ$$${SE_RG_SHOP}"
	.2byte 0x009A  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B71D  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_ReduceEV  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 155 "タポルのみ"
	.string "タポルのみ$$${SE_RG_SHOP}"
	.2byte 0x009B  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B73F  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_ReduceEV  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 156 "ロメのみ"
	.string "ロメのみ$$$${SE_RG_SHOP}"
	.2byte 0x009C  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B761  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_ReduceEV  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 157 "ウブのみ"
	.string "ウブのみ$$$${SE_RG_SHOP}"
	.2byte 0x009D  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B783  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_ReduceEV  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 158 "マトマのみ"
	.string "マトマのみ$$${SE_RG_SHOP}"
	.2byte 0x009E  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B7A5  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_ReduceEV  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 159 "モコシのみ"
	.string "モコシのみ$$${SE_RG_SHOP}"
	.2byte 0x009F  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B7C7  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 160 "ゴスのみ"
	.string "ゴスのみ$$$${SE_RG_SHOP}"
	.2byte 0x00A0  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B7E8  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 161 "ラブタのみ"
	.string "ラブタのみ$$${SE_RG_SHOP}"
	.2byte 0x00A1  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B808  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 162 "ノメルのみ"
	.string "ノメルのみ$$${SE_RG_SHOP}"
	.2byte 0x00A2  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B829  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 163 "ノワキのみ"
	.string "ノワキのみ$$${SE_RG_SHOP}"
	.2byte 0x00A3  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B84A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 164 "シーヤのみ"
	.string "シーヤのみ$$${SE_RG_SHOP}"
	.2byte 0x00A4  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B86B  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 165 "カイスのみ"
	.string "カイスのみ$$${SE_RG_SHOP}"
	.2byte 0x00A5  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B88C  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 166 "ドリのみ"
	.string "ドリのみ$$$${SE_RG_SHOP}"
	.2byte 0x00A6  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B8AD  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 167 "ベリブのみ"
	.string "ベリブのみ$$${SE_RG_SHOP}"
	.2byte 0x00A7  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B8CD  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 168 "チイラのみ"
	.string "チイラのみ$$${SE_RG_SHOP}"
	.2byte 0x00A8  @ itemId
	.2byte 0x0014  @ price
	.byte 0x0F  @ holdEffect
	.byte 0x04  @ holdEffectParam
	.4byte 0x0855B8EE  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 169 "リュガのみ"
	.string "リュガのみ$$${SE_RG_SHOP}"
	.2byte 0x00A9  @ itemId
	.2byte 0x0014  @ price
	.byte 0x10  @ holdEffect
	.byte 0x04  @ holdEffectParam
	.4byte 0x0855B908  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 170 "カムラのみ"
	.string "カムラのみ$$${SE_RG_SHOP}"
	.2byte 0x00AA  @ itemId
	.2byte 0x0014  @ price
	.byte 0x11  @ holdEffect
	.byte 0x04  @ holdEffectParam
	.4byte 0x0855B922  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 171 "ヤタピのみ"
	.string "ヤタピのみ$$${SE_RG_SHOP}"
	.2byte 0x00AB  @ itemId
	.2byte 0x0014  @ price
	.byte 0x12  @ holdEffect
	.byte 0x04  @ holdEffectParam
	.4byte 0x0855B939  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 172 "ズアのみ"
	.string "ズアのみ$$$${SE_RG_SHOP}"
	.2byte 0x00AC  @ itemId
	.2byte 0x0014  @ price
	.byte 0x13  @ holdEffect
	.byte 0x04  @ holdEffectParam
	.4byte 0x0855B950  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 173 "サンのみ"
	.string "サンのみ$$$${SE_RG_SHOP}"
	.2byte 0x00AD  @ itemId
	.2byte 0x0014  @ price
	.byte 0x14  @ holdEffect
	.byte 0x04  @ holdEffectParam
	.4byte 0x0855B967  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 174 "スターのみ"
	.string "スターのみ$$${SE_RG_SHOP}"
	.2byte 0x00AE  @ itemId
	.2byte 0x0014  @ price
	.byte 0x15  @ holdEffect
	.byte 0x04  @ holdEffectParam
	.4byte 0x0855B989  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 175 "ナゾのみ"
	.string "ナゾのみ$$$${SE_RG_SHOP}"
	.2byte 0x00AF  @ itemId
	.2byte 0x0014  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B9AE  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x04  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_EnigmaBerry  @ fieldUseFunc
	.byte 0x01  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte ItemUseInBattle_EnigmaBerry  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 176 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 177 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 178 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 179 "ひ{GREEN}りの{DYNAMIC_COLOR1}な"
	.string "ひ{GREEN}りの{DYNAMIC_COLOR1}な$${SE_RG_SHOP}"
	.2byte 0x00B3  @ itemId
	.2byte 0x000A  @ price
	.byte 0x16  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855B9D1  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 180 "{DYNAMIC_COLOR3}{MUS_RG_ENCOUNTER_DEOXYS}ハーブ"
	.string "{DYNAMIC_COLOR3}{MUS_RG_ENCOUNTER_DEOXYS}ハーブ$${SE_RG_SHOP}"
	.2byte 0x00B4  @ itemId
	.2byte 0x0064  @ price
	.byte 0x17  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855B9F4  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 181 "{LIGHT_GREEN}ょ{LIGHT_GRAY}{MUS_RG_PEWTER}ギプス"
	.string "{LIGHT_GREEN}ょ{LIGHT_GRAY}{MUS_RG_PEWTER}ギプス{SE_RG_SHOP}"
	.2byte 0x00B5  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x18  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BA13  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 182 "が{BLUE}{DYNAMIC_COLOR3}ゅ{LIGHT_GRAY}{DYNAMIC_COLOR6}{LIGHT_GRAY}ち"
	.string "が{BLUE}{DYNAMIC_COLOR3}ゅ{LIGHT_GRAY}{DYNAMIC_COLOR6}{LIGHT_GRAY}ち{SE_RG_SHOP}"
	.2byte 0x00B6  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x19  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BA33  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 183 "{DYNAMIC_COLOR5}ん{MUS_RG_PEWTER}のツメ"
	.string "{DYNAMIC_COLOR5}ん{MUS_RG_PEWTER}のツメ${SE_RG_SHOP}"
	.2byte 0x00B7  @ itemId
	.2byte 0x0064  @ price
	.byte 0x1A  @ holdEffect
	.byte 0x14  @ holdEffectParam
	.4byte 0x0855BA4E  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 184 "や{DYNAMIC_COLOR4}らぎの{DYNAMIC_COLOR4}ず"
	.string "や{DYNAMIC_COLOR4}らぎの{DYNAMIC_COLOR4}ず${SE_RG_SHOP}"
	.2byte 0x00B8  @ itemId
	.2byte 0x0064  @ price
	.byte 0x1B  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BA6D  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 185 "メンタルハーブ"
	.string "メンタルハーブ${SE_RG_SHOP}"
	.2byte 0x00B9  @ itemId
	.2byte 0x0064  @ price
	.byte 0x1C  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BA8F  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 186 "{DYNAMIC_COLOR1}だわりハチマキ"
	.string "{DYNAMIC_COLOR1}だわりハチマキ{SE_RG_SHOP}"
	.2byte 0x00BA  @ itemId
	.2byte 0x0064  @ price
	.byte 0x1D  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BAAF  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 187 "{LIGHT_RED}{LIGHT_GRAY}じゃの{DYNAMIC_COLOR3}る{DYNAMIC_COLOR3}"
	.string "{LIGHT_RED}{LIGHT_GRAY}じゃの{DYNAMIC_COLOR3}る{DYNAMIC_COLOR3}{SE_RG_SHOP}"
	.2byte 0x00BB  @ itemId
	.2byte 0x0064  @ price
	.byte 0x1E  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BAD0  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 188 "ぎんの{DYNAMIC_COLOR1}な"
	.string "ぎんの{DYNAMIC_COLOR1}な$$${SE_RG_SHOP}"
	.2byte 0x00BC  @ itemId
	.2byte 0x0064  @ price
	.byte 0x1F  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BAF3  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 189 "{LIGHT_RED}まもり{DYNAMIC_COLOR1}ばん"
	.string "{LIGHT_RED}まもり{DYNAMIC_COLOR1}ばん${SE_RG_SHOP}"
	.2byte 0x00BD  @ itemId
	.2byte 0x0064  @ price
	.byte 0x20  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BB13  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 190 "{LIGHT_GREEN}よめの{LIGHT_RED}ふだ"
	.string "{LIGHT_GREEN}よめの{LIGHT_RED}ふだ${SE_RG_SHOP}"
	.2byte 0x00BE  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x21  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BB35  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 191 "{DYNAMIC_COLOR1}{DYNAMIC_COLOR1}ろの{DYNAMIC_COLOR3}ず{BLUE}"
	.string "{DYNAMIC_COLOR1}{DYNAMIC_COLOR1}ろの{DYNAMIC_COLOR3}ず{BLUE}${SE_RG_SHOP}"
	.2byte 0x00BF  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x22  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BB59  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 192 "{DYNAMIC_COLOR3}ん{MUS_RG_POKE_TOWER}のキバ"
	.string "{DYNAMIC_COLOR3}ん{MUS_RG_POKE_TOWER}のキバ${SE_RG_SHOP}"
	.2byte 0x00C0  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x23  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BB7C  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 193 "{DYNAMIC_COLOR3}ん{MUS_RG_POKE_TOWER}のウロコ"
	.string "{DYNAMIC_COLOR3}ん{MUS_RG_POKE_TOWER}のウロコ{SE_RG_SHOP}"
	.2byte 0x00C1  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x24  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BB9E  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 194 "{LIGHT_BLUE}むりだま"
	.string "{LIGHT_BLUE}むりだま$$${SE_RG_SHOP}"
	.2byte 0x00C2  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x25  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BBC0  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 195 "{GREEN}わらず{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}"
	.string "{GREEN}わらず{MUS_RG_NEW_GAME_EXIT}{DYNAMIC_COLOR3}${SE_RG_SHOP}"
	.2byte 0x00C3  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x26  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BBDE  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 196 "{SE_POKENAV_CALL}{DARK_GRAY}のハチマキ"
	.string "{SE_POKENAV_CALL}{DARK_GRAY}のハチマキ{SE_RG_SHOP}"
	.2byte 0x00C4  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x27  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BBFB  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 197 "{SE_PIKE_CURTAIN_OPEN}わ{DYNAMIC_COLOR5}タマゴ"
	.string "{SE_PIKE_CURTAIN_OPEN}わ{DYNAMIC_COLOR5}タマゴ${SE_RG_SHOP}"
	.2byte 0x00C5  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x28  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BC1B  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 198 "ピントレンズ"
	.string "ピントレンズ$${SE_RG_SHOP}"
	.2byte 0x00C6  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x29  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BC3D  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 199 "メタルコート"
	.string "メタルコート$${SE_RG_SHOP}"
	.2byte 0x00C7  @ itemId
	.2byte 0x0064  @ price
	.byte 0x2A  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BC5A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 200 "たべの{DYNAMIC_COLOR1}{DYNAMIC_COLOR3}"
	.string "たべの{DYNAMIC_COLOR1}{DYNAMIC_COLOR3}$$${SE_RG_SHOP}"
	.2byte 0x00C8  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x2B  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BC7B  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 201 "りゅ{LIGHT_GRAY}のウロコ"
	.string "りゅ{LIGHT_GRAY}のウロコ${SE_RG_SHOP}"
	.2byte 0x00C9  @ itemId
	.2byte 0x0834  @ price
	.byte 0x2C  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BC9F  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 202 "でん{LIGHT_GREEN}だま"
	.string "でん{LIGHT_GREEN}だま$$${SE_RG_SHOP}"
	.2byte 0x00CA  @ itemId
	.2byte 0x0064  @ price
	.byte 0x2D  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BCBD  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 203 "やわら{MUS_RG_POKE_TOWER}{DYNAMIC_COLOR4}な"
	.string "やわら{MUS_RG_POKE_TOWER}{DYNAMIC_COLOR4}な${SE_RG_SHOP}"
	.2byte 0x00CB  @ itemId
	.2byte 0x0064  @ price
	.byte 0x2E  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BCE0  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 204 "{GREEN}{MUS_RG_RIVAL_EXIT}{DARK_GRAY}{DYNAMIC_COLOR3}"
	.string "{GREEN}{MUS_RG_RIVAL_EXIT}{DARK_GRAY}{DYNAMIC_COLOR3}$$${SE_RG_SHOP}"
	.2byte 0x00CC  @ itemId
	.2byte 0x0064  @ price
	.byte 0x2F  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BD01  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 205 "{LIGHT_GREEN}{DYNAMIC_COLOR5}{LIGHT_GREEN}のタネ"
	.string "{LIGHT_GREEN}{DYNAMIC_COLOR5}{LIGHT_GREEN}のタネ$${SE_RG_SHOP}"
	.2byte 0x00CD  @ itemId
	.2byte 0x0064  @ price
	.byte 0x30  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BD21  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 206 "{BLUE}{MUS_RG_ENCOUNTER_DEOXYS}メガネ"
	.string "{BLUE}{MUS_RG_ENCOUNTER_DEOXYS}メガネ$${SE_RG_SHOP}"
	.2byte 0x00CE  @ itemId
	.2byte 0x0064  @ price
	.byte 0x31  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BD41  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 207 "{BLUE}ろ{LIGHT_RED}び"
	.string "{BLUE}ろ{LIGHT_RED}び$$$${SE_RG_SHOP}"
	.2byte 0x00CF  @ itemId
	.2byte 0x0064  @ price
	.byte 0x32  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BD61  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 208 "じ{DYNAMIC_COLOR3}ゃ{BLUE}"
	.string "じ{DYNAMIC_COLOR3}ゃ{BLUE}$$$${SE_RG_SHOP}"
	.2byte 0x00D0  @ itemId
	.2byte 0x0064  @ price
	.byte 0x33  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BD83  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 209 "{DYNAMIC_COLOR3}んぴの{DYNAMIC_COLOR3}ず{BLUE}"
	.string "{DYNAMIC_COLOR3}んぴの{DYNAMIC_COLOR3}ず{BLUE}${SE_RG_SHOP}"
	.2byte 0x00D1  @ itemId
	.2byte 0x0064  @ price
	.byte 0x34  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BDA4  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 210 "{DYNAMIC_COLOR4}る{PH_LOT_HELD}{BLUE}ちば{DYNAMIC_COLOR3}"
	.string "{DYNAMIC_COLOR4}る{PH_LOT_HELD}{BLUE}ちば{DYNAMIC_COLOR3}{SE_RG_SHOP}"
	.2byte 0x00D2  @ itemId
	.2byte 0x0064  @ price
	.byte 0x35  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BDC4  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 211 "ど{BLUE}バリ"
	.string "ど{BLUE}バリ$$$${SE_RG_SHOP}"
	.2byte 0x00D3  @ itemId
	.2byte 0x0064  @ price
	.byte 0x36  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BDE5  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 212 "と{LIGHT_BLUE}{MUS_RG_GAME_FREAK}{DYNAMIC_COLOR1}{LIGHT_RED}り"
	.string "と{LIGHT_BLUE}{MUS_RG_GAME_FREAK}{DYNAMIC_COLOR1}{LIGHT_RED}り${SE_RG_SHOP}"
	.2byte 0x00D4  @ itemId
	.2byte 0x0064  @ price
	.byte 0x37  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BE05  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 213 "の{MUS_RG_ENCOUNTER_DEOXYS}の{LIGHT_RED}ふだ"
	.string "の{MUS_RG_ENCOUNTER_DEOXYS}の{LIGHT_RED}ふだ${SE_RG_SHOP}"
	.2byte 0x00D5  @ itemId
	.2byte 0x0064  @ price
	.byte 0x38  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BE26  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 214 "まがったスプーン"
	.string "まがったスプーン{SE_RG_SHOP}"
	.2byte 0x00D6  @ itemId
	.2byte 0x0064  @ price
	.byte 0x39  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BE48  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 215 "も{BLUE}たん"
	.string "も{BLUE}たん$$$${SE_RG_SHOP}"
	.2byte 0x00D7  @ itemId
	.2byte 0x2648  @ price
	.byte 0x3A  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BE6A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 216 "りゅ{LIGHT_GRAY}のキバ"
	.string "りゅ{LIGHT_GRAY}のキバ$${SE_RG_SHOP}"
	.2byte 0x00D8  @ itemId
	.2byte 0x0064  @ price
	.byte 0x3B  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BE8B  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 217 "シルクのスカーフ"
	.string "シルクのスカーフ{SE_RG_SHOP}"
	.2byte 0x00D9  @ itemId
	.2byte 0x0064  @ price
	.byte 0x3C  @ holdEffect
	.byte 0x0A  @ holdEffectParam
	.4byte 0x0855BEAD  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 218 "アップグレード"
	.string "アップグレード${SE_RG_SHOP}"
	.2byte 0x00DA  @ itemId
	.2byte 0x0834  @ price
	.byte 0x3D  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BECF  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 219 "{MUS_RG_POKE_TOWER}がらの{DYNAMIC_COLOR4}ず"
	.string "{MUS_RG_POKE_TOWER}がらの{DYNAMIC_COLOR4}ず${SE_RG_SHOP}"
	.2byte 0x00DB  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x3E  @ holdEffect
	.byte 0x08  @ holdEffectParam
	.4byte 0x0855BEE3  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 220 "{LIGHT_GRAY}{DYNAMIC_COLOR3}{LIGHT_RED}の{LIGHT_RED}{DYNAMIC_COLOR1}{LIGHT_GRAY}"
	.string "{LIGHT_GRAY}{DYNAMIC_COLOR3}{LIGHT_RED}の{LIGHT_RED}{DYNAMIC_COLOR1}{LIGHT_GRAY}${SE_RG_SHOP}"
	.2byte 0x00DC  @ itemId
	.2byte 0x2580  @ price
	.byte 0x34  @ holdEffect
	.byte 0x05  @ holdEffectParam
	.4byte 0x0855BF06  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 221 "のん{LIGHT_GREEN}の{LIGHT_RED}{DYNAMIC_COLOR1}{LIGHT_GRAY}"
	.string "のん{LIGHT_GREEN}の{LIGHT_RED}{DYNAMIC_COLOR1}{LIGHT_GRAY}${SE_RG_SHOP}"
	.2byte 0x00DD  @ itemId
	.2byte 0x2580  @ price
	.byte 0x16  @ holdEffect
	.byte 0x05  @ holdEffectParam
	.4byte 0x0855BF2C  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 222 "ラッキーパンチ"
	.string "ラッキーパンチ${SE_RG_SHOP}"
	.2byte 0x00DE  @ itemId
	.2byte 0x000A  @ price
	.byte 0x3F  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BF4F  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 223 "メタルパウダー"
	.string "メタルパウダー${SE_RG_SHOP}"
	.2byte 0x00DF  @ itemId
	.2byte 0x000A  @ price
	.byte 0x40  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BF70  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 224 "ふ{MUS_RG_PHOTO}ホネ"
	.string "ふ{MUS_RG_PHOTO}ホネ$$${SE_RG_SHOP}"
	.2byte 0x00E0  @ itemId
	.2byte 0x01F4  @ price
	.byte 0x41  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BF86  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 225 "ながねぎ"
	.string "ながねぎ$$$${SE_RG_SHOP}"
	.2byte 0x00E1  @ itemId
	.2byte 0x00C8  @ price
	.byte 0x42  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BFA8  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 226 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 227 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 228 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 229 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 230 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 231 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 232 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 233 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 234 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 235 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 236 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 237 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 238 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 239 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 240 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 241 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 242 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 243 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 244 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 245 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 246 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 247 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 248 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 249 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 250 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 251 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 252 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 253 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 254 "{WHITE}{MUS_RG_POKE_TOWER}バンダナ"
	.string "{WHITE}{MUS_RG_POKE_TOWER}バンダナ${SE_RG_SHOP}"
	.2byte 0x00FE  @ itemId
	.2byte 0x0064  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BFC4  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 255 "{WHITE}{MUS_RG_SURF}バンダナ"
	.string "{WHITE}{MUS_RG_SURF}バンダナ${SE_RG_SHOP}"
	.2byte 0x00FF  @ itemId
	.2byte 0x0064  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855BFE8  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 256 "ピンクのバンダナ"
	.string "ピンクのバンダナ{SE_RG_SHOP}"
	.2byte 0x0100  @ itemId
	.2byte 0x0064  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C00C  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 257 "みどりのバンダナ"
	.string "みどりのバンダナ{SE_RG_SHOP}"
	.2byte 0x0101  @ itemId
	.2byte 0x0064  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C02F  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 258 "{MUS_RG_SILPH}ろのバンダナ"
	.string "{MUS_RG_SILPH}ろのバンダナ{SE_RG_SHOP}"
	.2byte 0x0102  @ itemId
	.2byte 0x0064  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C052  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 259 "マッハじてん{DYNAMIC_COLOR3}ゃ"
	.string "マッハじてん{DYNAMIC_COLOR3}ゃ{SE_RG_SHOP}"
	.2byte 0x0103  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C076  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x02  @ type
	.4byte ItemUseOutOfBattle_Bike  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 260 "コインケース"
	.string "コインケース$${SE_RG_SHOP}"
	.2byte 0x0104  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C09A  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CoinCase  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 261 "ダウジングマシン"
	.string "ダウジングマシン{SE_RG_SHOP}"
	.2byte 0x0105  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C0B9  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x02  @ type
	.4byte ItemUseOutOfBattle_Itemfinder  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 262 "ボロのつりざ{LIGHT_RED}"
	.string "ボロのつりざ{LIGHT_RED}${SE_RG_SHOP}"
	.2byte 0x0106  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C0D7  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x02  @ type
	.4byte ItemUseOutOfBattle_Rod  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 263 "{MUS_RG_OAK}つりざ{LIGHT_RED}"
	.string "{MUS_RG_OAK}つりざ{LIGHT_RED}$${SE_RG_SHOP}"
	.2byte 0x0107  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C0F7  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x02  @ type
	.4byte ItemUseOutOfBattle_Rod  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x01  @ secondaryId
	.space 3  @ padding

	@ 264 "{DYNAMIC_COLOR4}{PH_FLEECE_BLEND}つりざ{LIGHT_RED}"
	.string "{DYNAMIC_COLOR4}{PH_FLEECE_BLEND}つりざ{LIGHT_RED}${SE_RG_SHOP}"
	.2byte 0x0108  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C116  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x02  @ type
	.4byte ItemUseOutOfBattle_Rod  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x02  @ secondaryId
	.space 3  @ padding

	@ 265 "ふねのチケット"
	.string "ふねのチケット${SE_RG_SHOP}"
	.2byte 0x0109  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C135  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 266 "コンテストパス"
	.string "コンテストパス${SE_RG_SHOP}"
	.2byte 0x010A  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C147  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 267 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 268 "ホエルコじょ{LIGHT_GRAY}ろ"
	.string "ホエルコじょ{LIGHT_GRAY}ろ{SE_RG_SHOP}"
	.2byte 0x010C  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C15F  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x02  @ type
	.4byte ItemUseOutOfBattle_WailmerPail  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 269 "デボンのにもつ"
	.string "デボンのにもつ${SE_RG_SHOP}"
	.2byte 0x010D  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C182  @ description
	.byte 0x02  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 270 "{MUS_RG_POKE_JUMP}ぶ{BLUE}ろ"
	.string "{MUS_RG_POKE_JUMP}ぶ{BLUE}ろ$$${SE_RG_SHOP}"
	.2byte 0x010E  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C1A2  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 271 "ち{GREEN}のカギ"
	.string "ち{GREEN}のカギ$$${SE_RG_SHOP}"
	.2byte 0x010F  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C1BA  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 272 "ダートじてん{DYNAMIC_COLOR3}ゃ"
	.string "ダートじてん{DYNAMIC_COLOR3}ゃ{SE_RG_SHOP}"
	.2byte 0x0110  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C1DA  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x02  @ type
	.4byte ItemUseOutOfBattle_Bike  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x01  @ secondaryId
	.space 3  @ padding

	@ 273 "ポロックケース"
	.string "ポロックケース${SE_RG_SHOP}"
	.2byte 0x0111  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C1FE  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x03  @ type
	.4byte ItemUseOutOfBattle_PokeblockCase  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 274 "ダイゴへのてがみ"
	.string "ダイゴへのてがみ{SE_RG_SHOP}"
	.2byte 0x0112  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C21E  @ description
	.byte 0x02  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 275 "むげんのチケット"
	.string "むげんのチケット{SE_RG_SHOP}"
	.2byte 0x0113  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C234  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x01  @ secondaryId
	.space 3  @ padding

	@ 276 "べ{MUS_RG_CAUGHT}ろのたま"
	.string "べ{MUS_RG_CAUGHT}ろのたま${SE_RG_SHOP}"
	.2byte 0x0114  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C249  @ description
	.byte 0x02  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 277 "{MUS_RG_OAK_LAB}{DARK_GRAY}ろのたま"
	.string "{MUS_RG_OAK_LAB}{DARK_GRAY}ろのたま${SE_RG_SHOP}"
	.2byte 0x0115  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C26D  @ description
	.byte 0x02  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 278 "たんち{LIGHT_GREEN}"
	.string "たんち{LIGHT_GREEN}$$$${SE_RG_SHOP}"
	.2byte 0x0116  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C291  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 279 "ゴーゴーゴーグル"
	.string "ゴーゴーゴーグル{SE_RG_SHOP}"
	.2byte 0x0117  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C2A6  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 280 "{DARK_GRAY}ん{DYNAMIC_COLOR5}{LIGHT_GREEN}"
	.string "{DARK_GRAY}ん{DYNAMIC_COLOR5}{LIGHT_GREEN}$$$${SE_RG_SHOP}"
	.2byte 0x0118  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C2C8  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 281 "1ご{LIGHT_GRAY}{DYNAMIC_COLOR3}つのカギ"
	.string "1ご{LIGHT_GRAY}{DYNAMIC_COLOR3}つのカギ{SE_RG_SHOP}"
	.2byte 0x0119  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C2DD  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 282 "2ご{LIGHT_GRAY}{DYNAMIC_COLOR3}つのカギ"
	.string "2ご{LIGHT_GRAY}{DYNAMIC_COLOR3}つのカギ{SE_RG_SHOP}"
	.2byte 0x011A  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C2F4  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 283 "4ご{LIGHT_GRAY}{DYNAMIC_COLOR3}つのカギ"
	.string "4ご{LIGHT_GRAY}{DYNAMIC_COLOR3}つのカギ{SE_RG_SHOP}"
	.2byte 0x011B  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C30B  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 284 "6ご{LIGHT_GRAY}{DYNAMIC_COLOR3}つのカギ"
	.string "6ご{LIGHT_GRAY}{DYNAMIC_COLOR3}つのカギ{SE_RG_SHOP}"
	.2byte 0x011C  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C322  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 285 "{DYNAMIC_COLOR6}{LIGHT_GRAY}{DYNAMIC_COLOR1}のカギ"
	.string "{DYNAMIC_COLOR6}{LIGHT_GRAY}{DYNAMIC_COLOR1}のカギ$${SE_RG_SHOP}"
	.2byte 0x011D  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C339  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 286 "ねっ{DYNAMIC_COLOR1}のカセキ"
	.string "ねっ{DYNAMIC_COLOR1}のカセキ${SE_RG_SHOP}"
	.2byte 0x011E  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C351  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 287 "ツメのカセキ"
	.string "ツメのカセキ$${SE_RG_SHOP}"
	.2byte 0x011F  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C376  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 288 "デボンスコープ"
	.string "デボンスコープ${SE_RG_SHOP}"
	.2byte 0x0120  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C39B  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 289 "わざマシン01"
	.string "わざマシン01${SE_RG_SHOP}"
	.2byte 0x0121  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C3BF  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 290 "わざマシン02"
	.string "わざマシン02${SE_RG_SHOP}"
	.2byte 0x0122  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C3E4  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 291 "わざマシン03"
	.string "わざマシン03${SE_RG_SHOP}"
	.2byte 0x0123  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C402  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 292 "わざマシン04"
	.string "わざマシン04${SE_RG_SHOP}"
	.2byte 0x0124  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C421  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 293 "わざマシン05"
	.string "わざマシン05${SE_RG_SHOP}"
	.2byte 0x0125  @ itemId
	.2byte 0x03E8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C442  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 294 "わざマシン06"
	.string "わざマシン06${SE_RG_SHOP}"
	.2byte 0x0126  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C461  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 295 "わざマシン07"
	.string "わざマシン07${SE_RG_SHOP}"
	.2byte 0x0127  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C480  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 296 "わざマシン08"
	.string "わざマシン08${SE_RG_SHOP}"
	.2byte 0x0128  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C4A1  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 297 "わざマシン09"
	.string "わざマシン09${SE_RG_SHOP}"
	.2byte 0x0129  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C4C0  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 298 "わざマシン10"
	.string "わざマシン10${SE_RG_SHOP}"
	.2byte 0x012A  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C4E2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 299 "わざマシン11"
	.string "わざマシン11${SE_RG_SHOP}"
	.2byte 0x012B  @ itemId
	.2byte 0x07D0  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C505  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 300 "わざマシン12"
	.string "わざマシン12${SE_RG_SHOP}"
	.2byte 0x012C  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C524  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 301 "わざマシン13"
	.string "わざマシン13${SE_RG_SHOP}"
	.2byte 0x012D  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C545  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 302 "わざマシン14"
	.string "わざマシン14${SE_RG_SHOP}"
	.2byte 0x012E  @ itemId
	.2byte 0x157C  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C568  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 303 "わざマシン15"
	.string "わざマシン15${SE_RG_SHOP}"
	.2byte 0x012F  @ itemId
	.2byte 0x1D4C  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C58A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 304 "わざマシン16"
	.string "わざマシン16${SE_RG_SHOP}"
	.2byte 0x0130  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C5AF  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 305 "わざマシン17"
	.string "わざマシン17${SE_RG_SHOP}"
	.2byte 0x0131  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C5CC  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 306 "わざマシン18"
	.string "わざマシン18${SE_RG_SHOP}"
	.2byte 0x0132  @ itemId
	.2byte 0x07D0  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C5F3  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 307 "わざマシン19"
	.string "わざマシン19${SE_RG_SHOP}"
	.2byte 0x0133  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C611  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 308 "わざマシン20"
	.string "わざマシン20${SE_RG_SHOP}"
	.2byte 0x0134  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C632  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 309 "わざマシン21"
	.string "わざマシン21${SE_RG_SHOP}"
	.2byte 0x0135  @ itemId
	.2byte 0x03E8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C653  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 310 "わざマシン22"
	.string "わざマシン22${SE_RG_SHOP}"
	.2byte 0x0136  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C673  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 311 "わざマシン23"
	.string "わざマシン23${SE_RG_SHOP}"
	.2byte 0x0137  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C698  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 312 "わざマシン24"
	.string "わざマシン24${SE_RG_SHOP}"
	.2byte 0x0138  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C6B9  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 313 "わざマシン25"
	.string "わざマシン25${SE_RG_SHOP}"
	.2byte 0x0139  @ itemId
	.2byte 0x157C  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C6D9  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 314 "わざマシン26"
	.string "わざマシン26${SE_RG_SHOP}"
	.2byte 0x013A  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C6F8  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 315 "わざマシン27"
	.string "わざマシン27${SE_RG_SHOP}"
	.2byte 0x013B  @ itemId
	.2byte 0x03E8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C71F  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 316 "わざマシン28"
	.string "わざマシン28${SE_RG_SHOP}"
	.2byte 0x013C  @ itemId
	.2byte 0x07D0  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C73E  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 317 "わざマシン29"
	.string "わざマシン29${SE_RG_SHOP}"
	.2byte 0x013D  @ itemId
	.2byte 0x07D0  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C761  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 318 "わざマシン30"
	.string "わざマシン30${SE_RG_SHOP}"
	.2byte 0x013E  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C782  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 319 "わざマシン31"
	.string "わざマシン31${SE_RG_SHOP}"
	.2byte 0x013F  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C7A3  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 320 "わざマシン32"
	.string "わざマシン32${SE_RG_SHOP}"
	.2byte 0x0140  @ itemId
	.2byte 0x07D0  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C7C6  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 321 "わざマシン33"
	.string "わざマシン33${SE_RG_SHOP}"
	.2byte 0x0141  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C7E6  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 322 "わざマシン34"
	.string "わざマシン34${SE_RG_SHOP}"
	.2byte 0x0142  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C807  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 323 "わざマシン35"
	.string "わざマシン35${SE_RG_SHOP}"
	.2byte 0x0143  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C829  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 324 "わざマシン36"
	.string "わざマシン36${SE_RG_SHOP}"
	.2byte 0x0144  @ itemId
	.2byte 0x03E8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C84A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 325 "わざマシン37"
	.string "わざマシン37${SE_RG_SHOP}"
	.2byte 0x0145  @ itemId
	.2byte 0x07D0  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C86D  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 326 "わざマシン38"
	.string "わざマシン38${SE_RG_SHOP}"
	.2byte 0x0146  @ itemId
	.2byte 0x157C  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C88E  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 327 "わざマシン39"
	.string "わざマシン39${SE_RG_SHOP}"
	.2byte 0x0147  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C8B3  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 328 "わざマシン40"
	.string "わざマシン40${SE_RG_SHOP}"
	.2byte 0x0148  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C8D6  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 329 "わざマシン41"
	.string "わざマシン41${SE_RG_SHOP}"
	.2byte 0x0149  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C8F7  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 330 "わざマシン42"
	.string "わざマシン42${SE_RG_SHOP}"
	.2byte 0x014A  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C913  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 331 "わざマシン43"
	.string "わざマシン43${SE_RG_SHOP}"
	.2byte 0x014B  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C937  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 332 "わざマシン44"
	.string "わざマシン44${SE_RG_SHOP}"
	.2byte 0x014C  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C95A  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 333 "わざマシン45"
	.string "わざマシン45${SE_RG_SHOP}"
	.2byte 0x014D  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C97E  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 334 "わざマシン46"
	.string "わざマシン46${SE_RG_SHOP}"
	.2byte 0x014E  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C99C  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 335 "わざマシン47"
	.string "わざマシン47${SE_RG_SHOP}"
	.2byte 0x014F  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C9BF  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 336 "わざマシン48"
	.string "わざマシン48${SE_RG_SHOP}"
	.2byte 0x0150  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855C9E2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 337 "わざマシン49"
	.string "わざマシン49${SE_RG_SHOP}"
	.2byte 0x0151  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CA04  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 338 "わざマシン50"
	.string "わざマシン50${SE_RG_SHOP}"
	.2byte 0x0152  @ itemId
	.2byte 0x0BB8  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CA22  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 339 "ひでんマシン01"
	.string "ひでんマシン01{SE_RG_SHOP}"
	.2byte 0x0153  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CA46  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 340 "ひでんマシン02"
	.string "ひでんマシン02{SE_RG_SHOP}"
	.2byte 0x0154  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CA69  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 341 "ひでんマシン03"
	.string "ひでんマシン03{SE_RG_SHOP}"
	.2byte 0x0155  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CA8A  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 342 "ひでんマシン04"
	.string "ひでんマシン04{SE_RG_SHOP}"
	.2byte 0x0156  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CAAC  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 343 "ひでんマシン05"
	.string "ひでんマシン05{SE_RG_SHOP}"
	.2byte 0x0157  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CACD  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 344 "ひでんマシン06"
	.string "ひでんマシン06{SE_RG_SHOP}"
	.2byte 0x0158  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CAF0  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 345 "ひでんマシン07"
	.string "ひでんマシン07{SE_RG_SHOP}"
	.2byte 0x0159  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CB11  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 346 "ひでんマシン08"
	.string "ひでんマシン08{SE_RG_SHOP}"
	.2byte 0x015A  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CB2F  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x03  @ pocket
	.byte 0x01  @ type
	.4byte ItemUseOutOfBattle_TMHM  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 347 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 348 "？？？？？？？？"
	.string "？？？？？？？？{SE_RG_SHOP}"
	.2byte 0x0000  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEE2  @ description
	.byte 0x00  @ importance
	.byte 0x00  @ registrability
	.byte 0x01  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 349 "{LIGHT_RED}とど{LIGHT_BLUE}もの"
	.string "{LIGHT_RED}とど{LIGHT_BLUE}もの$${SE_RG_SHOP}"
	.2byte 0x015D  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CB52  @ description
	.byte 0x02  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 350 "ポケモンのふ{RED}"
	.string "ポケモンのふ{RED}${SE_RG_SHOP}"
	.2byte 0x015E  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CB79  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 351 "ひみつのカギ"
	.string "ひみつのカギ$${SE_RG_SHOP}"
	.2byte 0x015F  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CB9B  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 352 "ひ{LIGHT_GREEN}{GREEN}{RED}{LIGHT_BLUE}ん"
	.string "ひ{LIGHT_GREEN}{GREEN}{RED}{LIGHT_BLUE}ん$${SE_RG_SHOP}"
	.2byte 0x0160  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CBB2  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 353 "{LIGHT_GREEN}ん{MUS_RG_NEW_GAME_EXIT}れば"
	.string "{LIGHT_GREEN}ん{MUS_RG_NEW_GAME_EXIT}れば$${SE_RG_SHOP}"
	.2byte 0x0161  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CBD6  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 354 "ひみつのコハク"
	.string "ひみつのコハク${SE_RG_SHOP}"
	.2byte 0x0162  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CBF5  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 355 "カードキー"
	.string "カードキー$$${SE_RG_SHOP}"
	.2byte 0x0163  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CC18  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 356 "エレベータのカギ"
	.string "エレベータのカギ{SE_RG_SHOP}"
	.2byte 0x0164  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CC3D  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 357 "{MUS_RG_POKE_TOWER}のカセキ"
	.string "{MUS_RG_POKE_TOWER}のカセキ$${SE_RG_SHOP}"
	.2byte 0x0165  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CC61  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 358 "{DYNAMIC_COLOR1}{LIGHT_GRAY}らのカセキ"
	.string "{DYNAMIC_COLOR1}{LIGHT_GRAY}らのカセキ${SE_RG_SHOP}"
	.2byte 0x0166  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CC81  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 359 "シルフスコープ"
	.string "シルフスコープ${SE_RG_SHOP}"
	.2byte 0x0167  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CCA0  @ description
	.byte 0x01  @ importance
	.byte 0x00  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 360 "じてん{DYNAMIC_COLOR3}ゃ"
	.string "じてん{DYNAMIC_COLOR3}ゃ$$${SE_RG_SHOP}"
	.2byte 0x0168  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CCC2  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x02  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 361 "タウンマップ"
	.string "タウンマップ$${SE_RG_SHOP}"
	.2byte 0x0169  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CCE3  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 362 "バトルサーチャー"
	.string "バトルサーチャー{SE_RG_SHOP}"
	.2byte 0x016A  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CD07  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x02  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 363 "ボイスチェッカー"
	.string "ボイスチェッカー{SE_RG_SHOP}"
	.2byte 0x016B  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CD2C  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 364 "わざマシンケース"
	.string "わざマシンケース{SE_RG_SHOP}"
	.2byte 0x016C  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CD50  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 365 "{LIGHT_GREEN}のみぶ{BLUE}ろ"
	.string "{LIGHT_GREEN}のみぶ{BLUE}ろ$${SE_RG_SHOP}"
	.2byte 0x016D  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CD67  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 366 "{LIGHT_RED}{DYNAMIC_COLOR3}{RED}テレビ"
	.string "{LIGHT_RED}{DYNAMIC_COLOR3}{RED}テレビ$${SE_RG_SHOP}"
	.2byte 0x016E  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CD7C  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x02  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 367 "トライパス"
	.string "トライパス$$${SE_RG_SHOP}"
	.2byte 0x016F  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CD9D  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 368 "レインボーパス"
	.string "レインボーパス${SE_RG_SHOP}"
	.2byte 0x0170  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CDBE  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 369 "{LIGHT_RED}ちゃ"
	.string "{LIGHT_RED}ちゃ$$$$${SE_RG_SHOP}"
	.2byte 0x0171  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CDDB  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 370 "{DYNAMIC_COLOR3}んぴのチケット"
	.string "{DYNAMIC_COLOR3}んぴのチケット{SE_RG_SHOP}"
	.2byte 0x0172  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CDF9  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 371 "オーロラチケット"
	.string "オーロラチケット{SE_RG_SHOP}"
	.2byte 0x0173  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CE15  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 372 "{DYNAMIC_COLOR1}{MUS_RG_GAME_FREAK}れ"
	.string "{DYNAMIC_COLOR1}{MUS_RG_GAME_FREAK}れ$$$${SE_RG_SHOP}"
	.2byte 0x0174  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CE34  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_PowderJar  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 373 "ルビー"
	.string "ルビー$$$$${SE_RG_SHOP}"
	.2byte 0x0175  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CE56  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 374 "サファイア"
	.string "サファイア$$${SE_RG_SHOP}"
	.2byte 0x0176  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CE7A  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 375 "マグマの{DYNAMIC_COLOR3}る{DYNAMIC_COLOR3}"
	.string "マグマの{DYNAMIC_COLOR3}る{DYNAMIC_COLOR3}${SE_RG_SHOP}"
	.2byte 0x0177  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CE9D  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding

	@ 376 "ふるびた{MUS_RG_POKE_TOWER}ず"
	.string "ふるびた{MUS_RG_POKE_TOWER}ず${SE_RG_SHOP}"
	.2byte 0x0178  @ itemId
	.2byte 0x0000  @ price
	.byte 0x00  @ holdEffect
	.byte 0x00  @ holdEffectParam
	.4byte 0x0855CEC0  @ description
	.byte 0x01  @ importance
	.byte 0x01  @ registrability
	.byte 0x05  @ pocket
	.byte 0x04  @ type
	.4byte ItemUseOutOfBattle_CannotUse  @ fieldUseFunc
	.byte 0x00  @ battleUsage
	.byte 0x00, 0x00, 0x00  @ unknown
	.4byte 0x00000000  @ battleUseFunc
	.byte 0x00  @ secondaryId
	.space 3  @ padding
