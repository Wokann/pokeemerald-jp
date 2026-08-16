#ifndef POKEEMERALD_JP_POKEJUMP1_H
#define POKEEMERALD_JP_POKEJUMP1_H

#include "global.h"
#include "pokemon_jump.h"
#include "constants/items.h"
#include "constants/songs.h"
#include "constants/species.h"

// Pokemon-jump tables (0x82CECF0..0x82CEFA0)

bool32 sub_0802AF3C(void);
bool32 sub_0802AFC8(void);
bool32 sub_0802B05C(void);
bool32 sub_0802B0C8(void);
bool32 sub_0802B1C0(void);
bool32 sub_0802B2BC(void);
bool32 sub_0802B358(void);
bool32 sub_0802B3AC(void);
bool32 sub_0802B414(void);
bool32 sub_0802AF90(void);
bool32 sub_0802B010(void);
bool32 sub_0802B0A8(void);
bool32 sub_0802B164(void);
bool32 sub_0802B25C(void);
bool32 sub_0802B31C(void);
bool32 sub_0802B3F8(void);

// 0x82CECF0
const struct PokemonJumpMons sPokeJumpMons[] =
{
    { .species = SPECIES_BULBASAUR, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_CHARMANDER, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_SQUIRTLE, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_CATERPIE, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_METAPOD, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_WEEDLE, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_KAKUNA, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_RATTATA, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_RATICATE, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_PIKACHU, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_SANDSHREW, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_NIDORAN_F, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_NIDORAN_M, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_CLEFAIRY, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_VULPIX, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_JIGGLYPUFF, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_ODDISH, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_PARAS, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_MEOWTH, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_PSYDUCK, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_MANKEY, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_GROWLITHE, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_POLIWAG, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_BELLSPROUT, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_SHELLDER, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_KRABBY, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_EXEGGCUTE, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_CUBONE, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_DITTO, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_EEVEE, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_OMANYTE, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_KABUTO, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_CHIKORITA, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_CYNDAQUIL, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_TOTODILE, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_SPINARAK, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_PICHU, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_CLEFFA, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_IGGLYBUFF, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_TOGEPI, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_MAREEP, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_BELLOSSOM, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_MARILL, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_SUNKERN, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_WOOPER, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_PINECO, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_SNUBBULL, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_SHUCKLE, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_TEDDIURSA, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_SLUGMA, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_SWINUB, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_HOUNDOUR, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_PHANPY, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_PORYGON2, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_TYROGUE, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_SMOOCHUM, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_ELEKID, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_MAGBY, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_LARVITAR, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_TREECKO, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_TORCHIC, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_MUDKIP, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_MARSHTOMP, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_POOCHYENA, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_ZIGZAGOON, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_LINOONE, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_WURMPLE, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_SILCOON, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_CASCOON, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_LOTAD, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_SEEDOT, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_RALTS, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_KIRLIA, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_SURSKIT, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_SHROOMISH, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_NINCADA, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_WHISMUR, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_AZURILL, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_SKITTY, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_SABLEYE, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_MAWILE, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_ARON, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_MEDITITE, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_ELECTRIKE, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_PLUSLE, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_MINUN, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_VOLBEAT, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_ILLUMISE, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_ROSELIA, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_GULPIN, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_NUMEL, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_TORKOAL, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_SPOINK, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_TRAPINCH, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_CACNEA, .jumpType = JUMP_TYPE_SLOW },
    { .species = SPECIES_ANORITH, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_WYNAUT, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_SNORUNT, .jumpType = JUMP_TYPE_NORMAL },
    { .species = SPECIES_CLAMPERL, .jumpType = JUMP_TYPE_FAST },
    { .species = SPECIES_BAGON, .jumpType = JUMP_TYPE_FAST },
};

// 0x82CEE80 / 0x82CEEA4
bool32 (*const sPokeJumpLeaderFuncs[])(void) =
{
    sub_0802AF3C,
    sub_0802AFC8,
    sub_0802B05C,
    sub_0802B0C8,
    sub_0802B1C0,
    sub_0802B2BC,
    sub_0802B358,
    sub_0802B3AC,
    sub_0802B414,
};

bool32 (*const sPokeJumpMemberFuncs[])(void) =
{
    sub_0802AF90,
    sub_0802B010,
    sub_0802B0A8,
    sub_0802B164,
    sub_0802B25C,
    sub_0802B31C,
    sub_0802B358,
    sub_0802B3F8,
    sub_0802B414,
};

// 0x82CEEC8
const u16 sVineBaseSpeeds[] = { 26, 31, 36, 41, 46, 51, 56, 61 };

// 0x82CEED8
const u16 sVineSpeedDelays[] = { 0, 1, 1, 2 };

// 0x82CEEE0
const u16 sSoundEffects[] = { SE_SHOP, SE_SHINY, SE_M_MORNING_SUN, SE_RG_POKE_JUMP_SUCCESS };

// 0x82CEEE8
const s8 sJumpOffsets[][48] =
{
    { 253, 250, 248, 246, 243, 241, 239, 237, 235, 233, 231, 229, 228, 227, 226, 226, 226, 228, 229, 230, 231, 233, 234, 236, 238, 239, 241, 243, 245, 248, 250, 252, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 253, 250, 247, 245, 242, 240, 238, 236, 234, 232, 230, 228, 227, 226, 226, 228, 230, 232, 234, 236, 238, 240, 242, 245, 247, 250, 252, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 253, 250, 247, 245, 243, 241, 239, 237, 235, 233, 231, 229, 228, 227, 226, 226, 226, 226, 227, 227, 228, 228, 229, 229, 230, 231, 232, 234, 236, 238, 240, 242, 244, 245, 247, 250, 252, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

// 0x82CEF78
const s32 sScoreBonuses[] = { 0, 0, 50, 100, 200, 500 };

// 0x82CEF90
const u16 sPrizeItems[] =
{
    ITEM_LEPPA_BERRY,
    ITEM_LUM_BERRY,
    ITEM_SITRUS_BERRY,
    ITEM_FIGY_BERRY,
    ITEM_WIKI_BERRY,
    ITEM_MAGO_BERRY,
    ITEM_AGUAV_BERRY,
    ITEM_IAPAPA_BERRY,
};

#endif // POKEEMERALD_JP_POKEJUMP1_H
