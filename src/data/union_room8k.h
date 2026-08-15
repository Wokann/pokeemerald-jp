#include "global.h"
#include "constants/union_room.h"

// Activity-name and card-color tables/texts
extern const u8 sText_EmptyString[];
extern const u8 sText_SingleBattle[];
extern const u8 sText_DoubleBattle[];
extern const u8 sText_MultiBattle[];
extern const u8 sText_PokemonTrades[];
extern const u8 sText_Chat[];
extern const u8 sText_WonderCards[];
extern const u8 sText_WonderNews[];
extern const u8 sText_Cards[];
extern const u8 sText_PokemonJump[];
extern const u8 sText_BerryCrush[];
extern const u8 sText_BerryPicking[];
extern const u8 sText_Search[];
extern const u8 sText_BattleTowerOpenLv[];
extern const u8 sText_RecordCorner[];
extern const u8 sText_BerryBlender[];
extern const u8 sText_CoolContest[];
extern const u8 sText_BeautyContest[];
extern const u8 sText_CuteContest[];
extern const u8 sText_SmartContest[];
extern const u8 sText_ToughContest[];
extern const u8 sText_BattleTowerLv50[];

const u8 *const sLinkGroupActivityNameTexts[] = {
    [ACTIVITY_NONE] = sText_EmptyString,
    [ACTIVITY_BATTLE_SINGLE] = sText_SingleBattle,
    [ACTIVITY_BATTLE_DOUBLE] = sText_DoubleBattle,
    [ACTIVITY_BATTLE_MULTI] = sText_MultiBattle,
    [ACTIVITY_TRADE] = sText_PokemonTrades,
    [ACTIVITY_CHAT] = sText_Chat,
    [ACTIVITY_WONDER_CARD_DUP] = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS_DUP] = sText_WonderNews,
    [ACTIVITY_CARD] = sText_Cards,
    [ACTIVITY_POKEMON_JUMP] = sText_PokemonJump,
    [ACTIVITY_BERRY_CRUSH] = sText_BerryCrush,
    [ACTIVITY_BERRY_PICK] = sText_BerryPicking,
    [ACTIVITY_SEARCH] = sText_Search,
    [ACTIVITY_SPIN_TRADE] = sText_EmptyString,
    [ACTIVITY_BATTLE_TOWER_OPEN] = sText_BattleTowerOpenLv + 3,
    [ACTIVITY_RECORD_CORNER] = sText_RecordCorner,
    [ACTIVITY_BERRY_BLENDER] = sText_BerryBlender,
    [ACTIVITY_ACCEPT] = sText_EmptyString,
    [ACTIVITY_DECLINE] = sText_EmptyString,
    [ACTIVITY_NPCTALK] = sText_EmptyString,
    [ACTIVITY_PLYRTALK] = sText_EmptyString,
    [ACTIVITY_WONDER_CARD] = sText_EmptyString,
    [ACTIVITY_WONDER_NEWS] = sText_EmptyString,
    [ACTIVITY_CONTEST_COOL] = sText_CoolContest,
    [ACTIVITY_CONTEST_BEAUTY] = sText_BeautyContest,
    [ACTIVITY_CONTEST_CUTE] = sText_CuteContest,
    [ACTIVITY_CONTEST_SMART] = sText_SmartContest,
    [ACTIVITY_CONTEST_TOUGH] = sText_ToughContest,
    [ACTIVITY_BATTLE_TOWER] = sText_BattleTowerLv50 + 1,
};

ALIGNED(4) const u8 sText_ItsNormalCard[] = _("ノーマルカードだ！");

ALIGNED(4) const u8 sText_ItsBronzeCard[] = _("ブロンズカードだ！");

ALIGNED(4) const u8 sText_ItsCopperCard[] = _("カッパーカードだ！");

ALIGNED(4) const u8 sText_ItsSilverCard[] = _("シルバーカードだ！");

ALIGNED(4) const u8 sText_ItsGoldCard[] = _("ゴールドカードだ！");

const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard,
};

