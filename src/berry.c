#include "global.h"
#include "berry.h"
#include "constants/berry.h"
#include "constants/items.h"

// BEGIN JP BERRY DATA (generated; do not edit by hand)
#define BERRY_DESCRIPTION_DATA __attribute__((section(".rodata.berry_mid57b_descriptions")))

BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Cheri[] = _("とても　かわいい　はなが　さく。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Cheri[] = _("まっかな　みは　とても　からい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Chesto[] = _("そとの　かわの　ぶぶんも　なかみも　すべてが");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Chesto[] = _("かたい。　どこを　たべても　しぶい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Pecha[] = _("とても　あまくて　おいしい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Pecha[] = _("やわらかいので　はこぶときは　ちゅうい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Rawst[] = _("はっぱの　ぶぶんが　ながく　まるまっていると");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Rawst[] = _("みが　とても　にがく　なるらしい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Aspear[] = _("かたい　みの　なかには　すいぶんが　とても");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Aspear[] = _("おおく　ふくまれている。　かなり　すっぱい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Leppa[] = _("クラボなどに　くらべて　すこし　そだつのが");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Leppa[] = _("おそい。　みが　ちいさいほど　おいしい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Oran[] = _("いろいろな　あじが　まざった　ふしぎな　み。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Oran[] = _("みを　つけるのに　はんにち　かかる。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Persim[] = _("たいようが　だいすき。　ひに　あたると");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Persim[] = _("どんどん　いろが　あざやかに　なる。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Lum[] = _("そだつのに　じかんが　かかるが　たいせつに");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Lum[] = _("そだてると　みが　2つ　つくことも　ある。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Sitrus[] = _("オレンとは　きょうだいの　ような　そんざい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Sitrus[] = _("おおきくて　あじも　ととのっている。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Figy[] = _("たべられた　あとのような　かたちの　なかには");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Figy[] = _("からい　せいぶんが　つまっている。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Wiki[] = _("まわりに　ついている　イボイボは　ポケモンが");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Wiki[] = _("もちやすいように　できたと　いわれている。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Mago[] = _("おおきく　なれば　なるほど　みが　まがる。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Mago[] = _("まがるほど　あまくて　おいしい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Aguav[] = _("ちいさい　サイズの　はなで　しかも　ひかりを");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Aguav[] = _("ひつようと　しない　めずらしい　きのみ。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Iapapa[] = _("とても　おおきな　すっぱい　きのみ。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Iapapa[] = _("そだてるには　みじかくても　1にち　かかる。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Razz[] = _("あかい　みは　たべると　ちょっぴり　からい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Razz[] = _("そだつのが　はやく　4じかんで　みを　つける");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Bluk[] = _("そとがわは　あおいいろだが　たべると");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Bluk[] = _("くちの　なかが　まっくろに　なる。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Nanab[] = _("せかいで　7ばんめに　はっけん　されたので");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Nanab[] = _("ナナという　せつが　ゆうりょく。　あまい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Wepear[] = _("ちいさな　しろい　はなが　さく。　にがさと");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Wepear[] = _("すっぱさが　まざりあった　びみょうな　あじ。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Pinap[] = _("かぜに　よわく　さむさにも　よわい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Pinap[] = _("みの　なかが　からく　そとがわが　すっぱい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Pomeg[] = _("どんなに　みずを　あげても　えいようが");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Pomeg[] = _("あっても　6つの　み　しか　つけない。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Kelpsy[] = _("ねっこの　ような　かたちの　めずらしい");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Kelpsy[] = _("しゅるい。　とても　おおきな　はなが　さく。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Qualot[] = _("みずが　だいすき。　ずっと　あめが　ふる");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Qualot[] = _("ばしょでも　しっかりと　そだつ。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Hondew[] = _("とても　こうかで　なかなか　めに　することが");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Hondew[] = _("できない　きのみ。　とても　おいしい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Grepa[] = _("やわらかさと　まるい　かたちからは");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Grepa[] = _("そうぞうが　できないほど　すっぱい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Tamato[] = _("くちびるが　まがって　しまうほど　からい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Tamato[] = _("そだてるにも　じかんが　かかる。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Cornn[] = _("おおむかしから　はえていた。　たくさん");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Cornn[] = _("うえないと　みが　つかないときも　ある。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Magost[] = _("とても　あじの　バランスが　よいと");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Magost[] = _("ひょうばんの　きのみ。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Rabuta[] = _("たくさんの　けが　はえている　めずらしい");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Rabuta[] = _("しゅるい。　かなり　にがい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Nomel[] = _("かなり　すっぱい。　1くち　たべると");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Nomel[] = _("3にちかん　ほかの　あじが　しなくなる。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Spelon[] = _("まっかになった　みは　とてつもなく　からい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Spelon[] = _("イボからも　からい　せいぶんが　でている。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Pamtre[] = _("どこからともなく　うみを　ただよってくる。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Pamtre[] = _("せかいの　どこかで　そだっている　らしい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Watmel[] = _("とても　おおきく　50センチを　こえるものも");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Watmel[] = _("はっけん　された。　ものすごく　あまい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Durin[] = _("みただけで　にがい。　あまりにも　にがいので");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Durin[] = _("そのままで　たべたひとは　だれもいない。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Belue[] = _("つるつるとして　おいしそうだが　とてつもなく");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Belue[] = _("すっぱい。　そだてるにも　じかんが　かかる。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Liechi[] = _("なぞのタネ。　チイラのみには　うみの");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Liechi[] = _("ちからが　やどるという　うわさが　ある。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Ganlon[] = _("なぞのタネ。　リュガのみには　りくの");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Ganlon[] = _("ちからが　やどるという　うわさが　ある。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Salac[] = _("なぞのタネ。　カムラのみには　そらの");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Salac[] = _("ちからが　やどるという　うわさが　ある。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Petaya[] = _("なぞのタネ。　ヤタピのみには　すべての");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Petaya[] = _("いきものの　ちからが　やどると　いわれている");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Apicot[] = _("ふしぎな　ふしぎな　きのみ。　なにが");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Apicot[] = _("おこるのか　なにが　できるのか　わからない。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Lansat[] = _("でんせつのみ　と　いわれている。　この　みを");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Lansat[] = _("もつと　とても　しあわせに　なるらしい。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Starf[] = _("あまりにも　ちからが　つよすぎるため");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Starf[] = _("せかいの　はてに　すてた　まぼろしのみ。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart1_Enigma[] = _("しょうたい　ふめいの　きのみ。");
BERRY_DESCRIPTION_DATA static const u8 sBerryDescriptionPart2_Enigma[] = _("ほしの　ちからを　もっている　らしい。");

#undef BERRY_DESCRIPTION_DATA

#define BERRY_DATA __attribute__((section(".rodata.berry_mid58_data")))

// JP name fields are FF-filled; __() preserves their explicit EOS padding.
BERRY_DATA const struct Berry gBerries[] =
{
    [ITEM_CHERI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("クラボ$$$$"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 20,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Cheri,
        .description2 = sBerryDescriptionPart2_Cheri,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_CHESTO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("カゴ$$$$$"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 80,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Chesto,
        .description2 = sBerryDescriptionPart2_Chesto,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_PECHA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("モモン$$$$"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 40,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Pecha,
        .description2 = sBerryDescriptionPart2_Pecha,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_RAWST_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("チーゴ$$$$"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 32,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Rawst,
        .description2 = sBerryDescriptionPart2_Rawst,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_ASPEAR_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ナナシ$$$$"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 50,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Aspear,
        .description2 = sBerryDescriptionPart2_Aspear,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 25,
    },

    [ITEM_LEPPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ヒメリ$$$$"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 28,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Leppa,
        .description2 = sBerryDescriptionPart2_Leppa,
        .stageDuration = 4,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_ORAN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("オレン$$$$"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 35,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Oran,
        .description2 = sBerryDescriptionPart2_Oran,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_PERSIM_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("キー$$$$$"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 47,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Persim,
        .description2 = sBerryDescriptionPart2_Persim,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_LUM_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ラム$$$$$"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 34,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Lum,
        .description2 = sBerryDescriptionPart2_Lum,
        .stageDuration = 12,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_SITRUS_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("オボン$$$$"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 95,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Sitrus,
        .description2 = sBerryDescriptionPart2_Sitrus,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_FIGY_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("フィラ$$$$"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 100,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Figy,
        .description2 = sBerryDescriptionPart2_Figy,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_WIKI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ウイ$$$$$"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 115,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Wiki,
        .description2 = sBerryDescriptionPart2_Wiki,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_MAGO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("マゴ$$$$$"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 126,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Mago,
        .description2 = sBerryDescriptionPart2_Mago,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_AGUAV_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("バンジ$$$$"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 64,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Aguav,
        .description2 = sBerryDescriptionPart2_Aguav,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_IAPAPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("イア$$$$$"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 223,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Iapapa,
        .description2 = sBerryDescriptionPart2_Iapapa,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 25,
    },

    [ITEM_RAZZ_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ズリ$$$$$"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 120,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Razz,
        .description2 = sBerryDescriptionPart2_Razz,
        .stageDuration = 1,
        .spicy = 10,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_BLUK_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ブリー$$$$"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 108,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Bluk,
        .description2 = sBerryDescriptionPart2_Bluk,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 10,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_NANAB_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ナナ$$$$$"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 77,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Nanab,
        .description2 = sBerryDescriptionPart2_Nanab,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_WEPEAR_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("セシナ$$$$"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 74,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Wepear,
        .description2 = sBerryDescriptionPart2_Wepear,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_PINAP_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("パイル$$$$"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 80,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Pinap,
        .description2 = sBerryDescriptionPart2_Pinap,
        .stageDuration = 1,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_POMEG_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ザロク$$$$"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 135,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Pomeg,
        .description2 = sBerryDescriptionPart2_Pomeg,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_KELPSY_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ネコブ$$$$"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 150,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Kelpsy,
        .description2 = sBerryDescriptionPart2_Kelpsy,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_QUALOT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("タポル$$$$"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 110,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Qualot,
        .description2 = sBerryDescriptionPart2_Qualot,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_HONDEW_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ロメ$$$$$"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 162,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Hondew,
        .description2 = sBerryDescriptionPart2_Hondew,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_GREPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ウブ$$$$$"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 149,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Grepa,
        .description2 = sBerryDescriptionPart2_Grepa,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 10,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_TAMATO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("マトマ$$$$"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 200,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Tamato,
        .description2 = sBerryDescriptionPart2_Tamato,
        .stageDuration = 6,
        .spicy = 20,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_CORNN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("モコシ$$$$"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 75,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Cornn,
        .description2 = sBerryDescriptionPart2_Cornn,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 20,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_MAGOST_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ゴス$$$$$"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 140,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Magost,
        .description2 = sBerryDescriptionPart2_Magost,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 20,
        .bitter = 10,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_RABUTA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ラブタ$$$$"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 226,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Rabuta,
        .description2 = sBerryDescriptionPart2_Rabuta,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 20,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_NOMEL_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ノメル$$$$"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 285,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Nomel,
        .description2 = sBerryDescriptionPart2_Nomel,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 20,
        .smoothness = 30,
    },

    [ITEM_SPELON_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ノワキ$$$$"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 133,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Spelon,
        .description2 = sBerryDescriptionPart2_Spelon,
        .stageDuration = 18,
        .spicy = 40,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_PAMTRE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("シーヤ$$$$"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 244,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Pamtre,
        .description2 = sBerryDescriptionPart2_Pamtre,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 40,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_WATMEL_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("カイス$$$$"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 250,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Watmel,
        .description2 = sBerryDescriptionPart2_Watmel,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 40,
        .bitter = 10,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_DURIN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ドリ$$$$$"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 280,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Durin,
        .description2 = sBerryDescriptionPart2_Durin,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 40,
        .sour = 10,
        .smoothness = 70,
    },

    [ITEM_BELUE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ベリブ$$$$"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 300,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Belue,
        .description2 = sBerryDescriptionPart2_Belue,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_LIECHI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("チイラ$$$$"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 111,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Liechi,
        .description2 = sBerryDescriptionPart2_Liechi,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 0,
        .sweet = 40,
        .bitter = 0,
        .sour = 10,
        .smoothness = 80,
    },

    [ITEM_GANLON_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("リュガ$$$$"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 33,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Ganlon,
        .description2 = sBerryDescriptionPart2_Ganlon,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 40,
        .sweet = 0,
        .bitter = 40,
        .sour = 0,
        .smoothness = 80,
    },

    [ITEM_SALAC_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("カムラ$$$$"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 95,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Salac,
        .description2 = sBerryDescriptionPart2_Salac,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 0,
        .sweet = 40,
        .bitter = 0,
        .sour = 40,
        .smoothness = 80,
    },

    [ITEM_PETAYA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ヤタピ$$$$"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 237,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Petaya,
        .description2 = sBerryDescriptionPart2_Petaya,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 0,
        .sweet = 0,
        .bitter = 40,
        .sour = 0,
        .smoothness = 80,
    },

    [ITEM_APICOT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ズア$$$$$"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 75,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Apicot,
        .description2 = sBerryDescriptionPart2_Apicot,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 40,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 80,
    },

    [ITEM_LANSAT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("サン$$$$$"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 97,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Lansat,
        .description2 = sBerryDescriptionPart2_Lansat,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_STARF_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("スター$$$$"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 153,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Starf,
        .description2 = sBerryDescriptionPart2_Starf,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = __("ナゾ$$$$$"),
        .firmness = BERRY_FIRMNESS_UNKNOWN,
        .size = 0,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Enigma,
        .description2 = sBerryDescriptionPart2_Enigma,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 40,
        .sweet = 40,
        .bitter = 40,
        .sour = 40,
        .smoothness = 40,
    },
};

BERRY_DATA const struct BerryCrushBerryData gBerryCrush_BerryData[] = {
    [ITEM_CHERI_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  20},
    [ITEM_CHESTO_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  20},
    [ITEM_PECHA_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  20},
    [ITEM_RAWST_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  20},
    [ITEM_ASPEAR_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  20},
    [ITEM_LEPPA_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  30},
    [ITEM_ORAN_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  50, .powder =  30},
    [ITEM_PERSIM_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  30},
    [ITEM_LUM_BERRY - FIRST_BERRY_INDEX]    = {.difficulty =  50, .powder =  30},
    [ITEM_SITRUS_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  30},
    [ITEM_FIGY_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  60, .powder =  50},
    [ITEM_WIKI_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  60, .powder =  50},
    [ITEM_MAGO_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  60, .powder =  50},
    [ITEM_AGUAV_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  60, .powder =  50},
    [ITEM_IAPAPA_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  60, .powder =  50},
    [ITEM_RAZZ_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  80, .powder =  70},
    [ITEM_BLUK_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  80, .powder =  70},
    [ITEM_NANAB_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  80, .powder =  70},
    [ITEM_WEPEAR_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  80, .powder =  70},
    [ITEM_PINAP_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  80, .powder =  70},
    [ITEM_POMEG_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 100, .powder = 100},
    [ITEM_KELPSY_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 100, .powder = 100},
    [ITEM_QUALOT_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 100, .powder = 100},
    [ITEM_HONDEW_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 100, .powder = 100},
    [ITEM_GREPA_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 100, .powder = 100},
    [ITEM_TAMATO_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 130, .powder = 150},
    [ITEM_CORNN_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 130, .powder = 150},
    [ITEM_MAGOST_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 130, .powder = 150},
    [ITEM_RABUTA_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 130, .powder = 150},
    [ITEM_NOMEL_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 130, .powder = 150},
    [ITEM_SPELON_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 160, .powder = 250},
    [ITEM_PAMTRE_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 160, .powder = 250},
    [ITEM_WATMEL_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 160, .powder = 250},
    [ITEM_DURIN_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 160, .powder = 250},
    [ITEM_BELUE_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 160, .powder = 250},
    [ITEM_LIECHI_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_GANLON_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_SALAC_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 180, .powder = 500},
    [ITEM_PETAYA_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_APICOT_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_LANSAT_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 200, .powder = 750},
    [ITEM_STARF_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 200, .powder = 750},
    [ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 150, .powder = 200}
};

BERRY_DATA const struct BerryTree gBlankBerryTree = {};

#undef BERRY_DATA
// END JP BERRY DATA

__attribute__((naked)) void ClearEnigmaBerries()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	mov r1, sp\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r0, _080E0B24\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _080E0B28\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r2, _080E0B2C\n\t"
        "	mov r0, sp\n\t"
        "	bl CpuSet\n\t"
        "	add sp, #4\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E0B24: .4byte gSaveBlock1Ptr\n\t"
        "_080E0B28: .4byte 0x000031F8\n\t"
        "_080E0B2C: .4byte 0x0100001A\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SetEnigmaBerry(u8 *src)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r0, _080E0B54\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E0B58\n\t"
        "	adds r3, r0, r1\n\t"
        "	movs r2, #0\n\t"
        "_080E0B3E:\n\t"
        "	adds r0, r3, r2\n\t"
        "	adds r1, r4, r2\n\t"
        "	ldrb r1, [r1]\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #0x33\n\t"
        "	bls _080E0B3E\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E0B54: .4byte gSaveBlock1Ptr\n\t"
        "_080E0B58: .4byte 0x000031F8\n\t"
        ".syntax divided\n\t"
    );
}

u32 GetEnigmaBerryChecksum(struct EnigmaBerry *enigmaBerry)
{
    u32 i;
    u32 checksum;
    u8 *dest;

    dest = (u8 *)enigmaBerry;
    checksum = 0;
    for (i = 0; i < sizeof(gSaveBlock1Ptr->enigmaBerry) - sizeof(gSaveBlock1Ptr->enigmaBerry.checksum); i++)
        checksum += dest[i];

    return checksum;
}


__attribute__((naked)) bool32 IsEnigmaBerryValid()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r4, _080E0BAC\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r2, _080E0BB0\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E0BC0\n\t"
        "	ldr r2, _080E0BB4\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E0BC0\n\t"
        "	ldr r2, _080E0BB8\n\t"
        "	adds r0, r1, r2\n\t"
        "	bl GetEnigmaBerryChecksum\n\t"
        "	ldr r1, [r4]\n\t"
        "	ldr r2, _080E0BBC\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r1, [r1]\n\t"
        "	cmp r0, r1\n\t"
        "	bne _080E0BC0\n\t"
        "	movs r0, #1\n\t"
        "	b _080E0BC2\n\t"
        "	.align 2, 0\n\t"
        "_080E0BAC: .4byte gSaveBlock1Ptr\n\t"
        "_080E0BB0: .4byte 0x0000320C\n\t"
        "_080E0BB4: .4byte 0x00003202\n\t"
        "_080E0BB8: .4byte 0x000031F8\n\t"
        "_080E0BBC: .4byte 0x00003228\n\t"
        "_080E0BC0:\n\t"
        "	movs r0, #0\n\t"
        "_080E0BC2:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) const struct Berry *GetBerryInfo(u8 berry)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0x2b\n\t"
        "	bne _080E0BEC\n\t"
        "	bl IsEnigmaBerryValid\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E0BEC\n\t"
        "	ldr r0, _080E0BE4\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldr r1, _080E0BE8\n\t"
        "	b _080E0C00\n\t"
        "	.align 2, 0\n\t"
        "_080E0BE4: .4byte gSaveBlock1Ptr\n\t"
        "_080E0BE8: .4byte 0x000031F8\n\t"
        "_080E0BEC:\n\t"
        "	subs r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0x2a\n\t"
        "	bls _080E0BF8\n\t"
        "	movs r4, #1\n\t"
        "_080E0BF8:\n\t"
        "	lsls r0, r4, #3\n\t"
        "	subs r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080E0C08\n\t"
        "_080E0C00:\n\t"
        "	adds r0, r0, r1\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E0C08: .4byte sEscalatorMetatiles_2F_2 + 0x6D2\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) struct BerryTree *GetBerryTreeInfo(u8 id)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r1, _080E0C20\n\t"
        "	lsrs r0, r0, #0x15\n\t"
        "	ldr r2, _080E0C24\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r0, r1, #0\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_080E0C20: .4byte gSaveBlock1Ptr\n\t"
        "_080E0C24: .4byte 0x0000169C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool32 ObjectEventInteractionWaterBerryTree(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E0C50\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl EventObjectGetBerryTreeId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBerryTreeInfo\n\t"
        "	adds r2, r0, #0\n\t"
        "	ldrb r0, [r2, #1]\n\t"
        "	lsls r0, r0, #0x19\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	cmp r0, #2\n\t"
        "	beq _080E0C64\n\t"
        "	cmp r0, #2\n\t"
        "	bgt _080E0C54\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080E0C5E\n\t"
        "	b _080E0C7A\n\t"
        "	.align 2, 0\n\t"
        "_080E0C50: .4byte gSelectedObjectEvent\n\t"
        "_080E0C54:\n\t"
        "	cmp r0, #3\n\t"
        "	beq _080E0C6A\n\t"
        "	cmp r0, #4\n\t"
        "	beq _080E0C70\n\t"
        "	b _080E0C7A\n\t"
        "_080E0C5E:\n\t"
        "	ldrb r0, [r2, #5]\n\t"
        "	movs r1, #0x10\n\t"
        "	b _080E0C74\n\t"
        "_080E0C64:\n\t"
        "	ldrb r0, [r2, #5]\n\t"
        "	movs r1, #0x20\n\t"
        "	b _080E0C74\n\t"
        "_080E0C6A:\n\t"
        "	ldrb r0, [r2, #5]\n\t"
        "	movs r1, #0x40\n\t"
        "	b _080E0C74\n\t"
        "_080E0C70:\n\t"
        "	ldrb r0, [r2, #5]\n\t"
        "	movs r1, #0x80\n\t"
        "_080E0C74:\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2, #5]\n\t"
        "	b _080E0C7E\n\t"
        "_080E0C7A:\n\t"
        "	movs r0, #0\n\t"
        "	b _080E0C80\n\t"
        "_080E0C7E:\n\t"
        "	movs r0, #1\n\t"
        "_080E0C80:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 IsPlayerFacingEmptyBerryTreePatch()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl GetEventObjectScriptPointerPlayerFacing\n\t"
        "	ldr r1, _080E0CAC\n\t"
        "	cmp r0, r1\n\t"
        "	bne _080E0CB4\n\t"
        "	ldr r0, _080E0CB0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl EventObjectGetBerryTreeId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetStageByBerryTreeId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E0CB4\n\t"
        "	movs r0, #1\n\t"
        "	b _080E0CB6\n\t"
        "	.align 2, 0\n\t"
        "_080E0CAC: .4byte BerryTreeScript\n\t"
        "_080E0CB0: .4byte gSelectedObjectEvent\n\t"
        "_080E0CB4:\n\t"
        "	movs r0, #0\n\t"
        "_080E0CB6:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 TryToWaterBerryTree()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl GetEventObjectScriptPointerPlayerFacing\n\t"
        "	ldr r1, _080E0CD4\n\t"
        "	cmp r0, r1\n\t"
        "	bne _080E0CD8\n\t"
        "	bl ObjectEventInteractionWaterBerryTree\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	b _080E0CDA\n\t"
        "	.align 2, 0\n\t"
        "_080E0CD4: .4byte BerryTreeScript\n\t"
        "_080E0CD8:\n\t"
        "	movs r0, #0\n\t"
        "_080E0CDA:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ClearBerryTrees()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	movs r2, #0\n\t"
        "	ldr r6, _080E0D08\n\t"
        "	ldr r5, _080E0D0C\n\t"
        "	ldr r0, _080E0D10\n\t"
        "	ldr r3, [r0]\n\t"
        "	ldr r4, [r0, #4]\n\t"
        "_080E0CEE:\n\t"
        "	ldr r0, [r6]\n\t"
        "	lsls r1, r2, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r0, r5\n\t"
        "	str r3, [r0]\n\t"
        "	str r4, [r0, #4]\n\t"
        "	adds r2, #1\n\t"
        "	cmp r2, #0x7f\n\t"
        "	ble _080E0CEE\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E0D08: .4byte gSaveBlock1Ptr\n\t"
        "_080E0D0C: .4byte 0x0000169C\n\t"
        "_080E0D10: .4byte gBlankBerryTree\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void BerryTreeGrow(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrb r1, [r4, #1]\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E0D26\n\t"
        "_080E0D22:\n\t"
        "	movs r0, #0\n\t"
        "	b _080E0DB2\n\t"
        "_080E0D26:\n\t"
        "	lsls r0, r1, #0x19\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	cmp r0, #5\n\t"
        "	bhi _080E0DB0\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080E0D38\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_080E0D38: .4byte _080E0D3C\n\t"
        "_080E0D3C:\n\t"
        "	.4byte _080E0D22\n\t"
        "	.4byte _080E0D5C\n\t"
        "	.4byte _080E0D5C\n\t"
        "	.4byte _080E0D5C\n\t"
        "	.4byte _080E0D54\n\t"
        "	.4byte _080E0D74\n\t"
        "_080E0D54:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl CalcBerryYield\n\t"
        "	strb r0, [r4, #4]\n\t"
        "_080E0D5C:\n\t"
        "	ldrb r2, [r4, #1]\n\t"
        "	lsls r1, r2, #0x19\n\t"
        "	lsrs r1, r1, #0x19\n\t"
        "	adds r1, #1\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r1, r0\n\t"
        "	movs r0, #0x80\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #1]\n\t"
        "	b _080E0DB0\n\t"
        "_080E0D74:\n\t"
        "	ldrb r0, [r4, #5]\n\t"
        "	movs r1, #0x11\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r0\n\t"
        "	movs r0, #0x21\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r1, r0\n\t"
        "	subs r0, #0x20\n\t"
        "	ands r1, r0\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r1, r0\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r4, #4]\n\t"
        "	ldrb r2, [r4, #1]\n\t"
        "	subs r0, #0x80\n\t"
        "	ands r0, r2\n\t"
        "	movs r2, #2\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r4, #1]\n\t"
        "	adds r1, #1\n\t"
        "	movs r0, #0xf\n\t"
        "	ands r1, r0\n\t"
        "	strb r1, [r4, #5]\n\t"
        "	cmp r1, #0xa\n\t"
        "	bne _080E0DB0\n\t"
        "	ldr r0, _080E0DB8\n\t"
        "	ldr r1, [r0, #4]\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r4]\n\t"
        "	str r1, [r4, #4]\n\t"
        "_080E0DB0:\n\t"
        "	movs r0, #1\n\t"
        "_080E0DB2:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080E0DB8: .4byte gBlankBerryTree\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void BerryTreeTimeUpdate(s32 minutes)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	movs r2, #0\n\t"
        "_080E0DC2:\n\t"
        "	ldr r1, _080E0E0C\n\t"
        "	lsls r0, r2, #3\n\t"
        "	ldr r3, _080E0E10\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r4, r1, r0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	adds r7, r2, #1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E0E5C\n\t"
        "	ldrb r1, [r4, #1]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E0E5C\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080E0E5C\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetStageDurationByBerryType\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	lsls r1, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	subs r1, r1, r0\n\t"
        "	cmp r6, r1\n\t"
        "	blt _080E0E18\n\t"
        "	ldr r0, _080E0E14\n\t"
        "	ldr r1, [r0, #4]\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r4]\n\t"
        "	str r1, [r4, #4]\n\t"
        "	b _080E0E5C\n\t"
        "	.align 2, 0\n\t"
        "_080E0E0C: .4byte gSaveBlock1Ptr\n\t"
        "_080E0E10: .4byte 0x0000169C\n\t"
        "_080E0E14: .4byte gBlankBerryTree\n\t"
        "_080E0E18:\n\t"
        "	adds r5, r6, #0\n\t"
        "	cmp r5, #0\n\t"
        "	beq _080E0E5C\n\t"
        "	ldrh r1, [r4, #2]\n\t"
        "	cmp r1, r5\n\t"
        "	ble _080E0E28\n\t"
        "	subs r0, r1, r5\n\t"
        "	b _080E0E5A\n\t"
        "_080E0E28:\n\t"
        "	subs r5, r5, r1\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetStageDurationByBerryType\n\t"
        "	strh r0, [r4, #2]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl BerryTreeGrow\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E0E5C\n\t"
        "	ldrb r1, [r4, #1]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #5\n\t"
        "	bne _080E0E4C\n\t"
        "	ldrh r0, [r4, #2]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	strh r0, [r4, #2]\n\t"
        "_080E0E4C:\n\t"
        "	cmp r5, #0\n\t"
        "	beq _080E0E5C\n\t"
        "	ldrh r0, [r4, #2]\n\t"
        "	adds r1, r0, #0\n\t"
        "	cmp r0, r5\n\t"
        "	ble _080E0E28\n\t"
        "	subs r0, r0, r5\n\t"
        "_080E0E5A:\n\t"
        "	strh r0, [r4, #2]\n\t"
        "_080E0E5C:\n\t"
        "	adds r2, r7, #0\n\t"
        "	cmp r2, #0x7f\n\t"
        "	ble _080E0DC2\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PlantBerryTree(u8 id, u8 berry, u8 stage, bool8 allowGrowth)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	adds r5, r2, #0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r7, r3, #0x18\n\t"
        "	bl GetBerryTreeInfo\n\t"
        "	adds r6, r0, #0\n\t"
        "	ldr r0, _080E0ECC\n\t"
        "	ldr r1, [r0, #4]\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r6]\n\t"
        "	str r1, [r6, #4]\n\t"
        "	strb r4, [r6]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetStageDurationByBerryType\n\t"
        "	strh r0, [r6, #2]\n\t"
        "	movs r1, #0x7f\n\t"
        "	ands r1, r5\n\t"
        "	ldrb r2, [r6, #1]\n\t"
        "	movs r0, #0x80\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r6, #1]\n\t"
        "	cmp r5, #5\n\t"
        "	bne _080E0EBA\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl CalcBerryYield\n\t"
        "	strb r0, [r6, #4]\n\t"
        "	ldrh r0, [r6, #2]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	strh r0, [r6, #2]\n\t"
        "_080E0EBA:\n\t"
        "	cmp r7, #0\n\t"
        "	bne _080E0EC6\n\t"
        "	ldrb r0, [r6, #1]\n\t"
        "	movs r1, #0x80\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r6, #1]\n\t"
        "_080E0EC6:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E0ECC: .4byte gBlankBerryTree\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void RemoveBerryTree(u8 id)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r1, _080E0EEC\n\t"
        "	ldr r2, [r1]\n\t"
        "	lsrs r0, r0, #0x15\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldr r0, _080E0EF0\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldr r0, _080E0EF4\n\t"
        "	ldr r1, [r0, #4]\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r2]\n\t"
        "	str r1, [r2, #4]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_080E0EEC: .4byte gSaveBlock1Ptr\n\t"
        "_080E0EF0: .4byte 0x0000169C\n\t"
        "_080E0EF4: .4byte gBlankBerryTree\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 GetBerryTypeByBerryTreeId(u8 id)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r1, _080E0F0C\n\t"
        "	ldr r1, [r1]\n\t"
        "	lsrs r0, r0, #0x15\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _080E0F10\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_080E0F0C: .4byte gSaveBlock1Ptr\n\t"
        "_080E0F10: .4byte 0x0000169C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 GetStageByBerryTreeId(u8 id)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r1, _080E0F2C\n\t"
        "	ldr r1, [r1]\n\t"
        "	lsrs r0, r0, #0x15\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _080E0F30\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #0x19\n\t"
        "	lsrs r0, r0, #0x19\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_080E0F2C: .4byte gSaveBlock1Ptr\n\t"
        "_080E0F30: .4byte 0x0000169D\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 ItemIdToBerryType(u16 item)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	ldr r2, _080E0F50\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x2a\n\t"
        "	bhi _080E0F54\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x7c\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	b _080E0F56\n\t"
        "	.align 2, 0\n\t"
        "_080E0F50: .4byte 0xFF7B0000\n\t"
        "_080E0F54:\n\t"
        "	movs r0, #1\n\t"
        "_080E0F56:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void BerryTypeToItemId(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	ldr r2, _080E0F78\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x2a\n\t"
        "	bhi _080E0F7C\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x84\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	b _080E0F7E\n\t"
        "	.align 2, 0\n\t"
        "_080E0F78: .4byte 0xFFFF0000\n\t"
        "_080E0F7C:\n\t"
        "	movs r0, #0x85\n\t"
        "_080E0F7E:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetBerryNameByBerryType(u8 berry, u8 *string)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBerryInfo\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r2, #6\n\t"
        "	bl memcpy\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r4, #6]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ResetBerryTreeSparkleFlag(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBerryTreeInfo\n\t"
        "	ldrb r2, [r0, #1]\n\t"
        "	movs r1, #0x7f\n\t"
        "	ands r1, r2\n\t"
        "	strb r1, [r0, #1]\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void BerryTreeGetNumStagesWatered(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldrb r2, [r0, #5]\n\t"
        "	movs r0, #0x10\n\t"
        "	ands r0, r2\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	lsrs r1, r0, #0x1f\n\t"
        "	movs r0, #0x20\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E0FD6\n\t"
        "	adds r1, #1\n\t"
        "_080E0FD6:\n\t"
        "	movs r0, #0x40\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E0FE4\n\t"
        "	adds r0, r1, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "_080E0FE4:\n\t"
        "	movs r0, #0x80\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E0FF2\n\t"
        "	adds r0, r1, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "_080E0FF2:\n\t"
        "	adds r0, r1, #0\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetNumStagesWateredByBerryTreeId(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBerryTreeInfo\n\t"
        "	bl BerryTreeGetNumStagesWatered\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CalcBerryYieldInternal(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r6, r1, #0x10\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	cmp r2, #0\n\t"
        "	bne _080E1026\n\t"
        "	lsls r0, r6, #0x18\n\t"
        "	b _080E105A\n\t"
        "_080E1026:\n\t"
        "	subs r1, r0, r6\n\t"
        "	subs r0, r2, #1\n\t"
        "	adds r5, r1, #0\n\t"
        "	muls r5, r0, r5\n\t"
        "	adds r4, r1, #0\n\t"
        "	muls r4, r2, r4\n\t"
        "	bl Random\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	subs r4, r4, r5\n\t"
        "	adds r4, #1\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl __umodsi3\n\t"
        "	adds r5, r5, r0\n\t"
        "	movs r0, #3\n\t"
        "	ands r0, r5\n\t"
        "	cmp r0, #1\n\t"
        "	bls _080E1054\n\t"
        "	lsrs r0, r5, #2\n\t"
        "	adds r0, #1\n\t"
        "	b _080E1056\n\t"
        "_080E1054:\n\t"
        "	lsrs r0, r5, #2\n\t"
        "_080E1056:\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "_080E105A:\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CalcBerryYield(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	bl GetBerryInfo\n\t"
        "	ldrb r6, [r0, #0xb]\n\t"
        "	ldrb r5, [r0, #0xa]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl BerryTreeGetNumStagesWatered\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl CalcBerryYieldInternal\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetBerryCountByBerryTreeId(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r1, _080E10A4\n\t"
        "	ldr r1, [r1]\n\t"
        "	lsrs r0, r0, #0x15\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #0xb5\n\t"
        "	lsls r0, r0, #5\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_080E10A4: .4byte gSaveBlock1Ptr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetStageDurationByBerryType(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetBerryInfo\n\t"
        "	ldrb r1, [r0, #0x14]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	subs r0, r0, r1\n\t"
        "	lsls r0, r0, #0x12\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ObjectEventInteractionGetBerryTreeData(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r0, _080E10FC\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl EventObjectGetBerryTreeId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetBerryTypeByBerryTreeId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ResetBerryTreeSparkleFlag\n\t"
        "	ldr r0, _080E1100\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r1, _080E1104\n\t"
        "	ldr r2, [r1]\n\t"
        "	ldrb r1, [r2, #5]\n\t"
        "	ldrb r2, [r2, #4]\n\t"
        "	bl IsBerryTreeSparkling\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E110C\n\t"
        "	ldr r1, _080E1108\n\t"
        "	movs r0, #0xff\n\t"
        "	strh r0, [r1]\n\t"
        "	b _080E111A\n\t"
        "	.align 2, 0\n\t"
        "_080E10FC: .4byte gSelectedObjectEvent\n\t"
        "_080E1100: .4byte gSpecialVar_LastTalked\n\t"
        "_080E1104: .4byte gSaveBlock1Ptr\n\t"
        "_080E1108: .4byte gSpecialVar_0x8004\n\t"
        "_080E110C:\n\t"
        "	ldr r4, _080E1144\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetStageByBerryTreeId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r4]\n\t"
        "_080E111A:\n\t"
        "	ldr r4, _080E1148\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetNumStagesWateredByBerryTreeId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r4]\n\t"
        "	ldr r4, _080E114C\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetBerryCountByBerryTreeId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r4]\n\t"
        "	ldr r1, _080E1150\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetBerryNameByBerryType\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E1144: .4byte gSpecialVar_0x8004\n\t"
        "_080E1148: .4byte gSpecialVar_0x8005\n\t"
        "_080E114C: .4byte gSpecialVar_0x8006\n\t"
        "_080E1150: .4byte gStringVar1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Bag_ChooseBerry()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E1160\n\t"
        "	bl SetMainCallback2\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E1160: .4byte CB2_ChooseBerry\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ObjectEventInteractionPlantBerryTree(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r0, _080E1194\n\t"
        "	ldrh r0, [r0]\n\t"
        "	bl ItemIdToBerryType\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r0, _080E1198\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl EventObjectGetBerryTreeId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #1\n\t"
        "	movs r3, #1\n\t"
        "	bl PlantBerryTree\n\t"
        "	bl ObjectEventInteractionGetBerryTreeData\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E1194: .4byte gSpecialVar_ItemId\n\t"
        "_080E1198: .4byte gSelectedObjectEvent\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ObjectEventInteractionPickBerryTree(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r0, _080E11E0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl EventObjectGetBerryTreeId\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetBerryTypeByBerryTreeId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r6, _080E11E4\n\t"
        "	bl BerryTypeToItemId\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetBerryCountByBerryTreeId\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl AddBagItem\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r6]\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E11E0: .4byte gSelectedObjectEvent\n\t"
        "_080E11E4: .4byte gSpecialVar_0x8004\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ObjectEventInteractionRemoveBerryTree(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _080E1210\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl EventObjectGetBerryTreeId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl RemoveBerryTree\n\t"
        "	ldr r0, _080E1214\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r1, _080E1218\n\t"
        "	ldr r2, [r1]\n\t"
        "	ldrb r1, [r2, #5]\n\t"
        "	ldrb r2, [r2, #4]\n\t"
        "	bl sub_08092860\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E1210: .4byte gSelectedObjectEvent\n\t"
        "_080E1214: .4byte gSpecialVar_LastTalked\n\t"
        "_080E1218: .4byte gSaveBlock1Ptr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 PlayerHasBerries()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	movs r0, #4\n\t"
        "	bl IsBagPocketNonEmpty\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SetBerryTreesSeen()
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #4\n\t"
        "	mov r4, sp\n\t"
        "	adds r4, #2\n\t"
        "	mov r0, sp\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl GetCameraCoords\n\t"
        "	mov r0, sp\n\t"
        "	ldrh r2, [r0]\n\t"
        "	ldrh r1, [r4]\n\t"
        "	adds r1, #3\n\t"
        "	adds r3, r2, #0\n\t"
        "	adds r3, #0xe\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	movs r5, #0x80\n\t"
        "	lsls r5, r5, #0xc\n\t"
        "	adds r0, r1, r5\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov sl, r0\n\t"
        "	mov r5, sp\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	asrs r2, r2, #0x10\n\t"
        "	mov sb, r2\n\t"
        "	ldr r4, _080E12C4\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	asrs r3, r3, #0x10\n\t"
        "	mov r8, r3\n\t"
        "	asrs r7, r1, #0x10\n\t"
        "	movs r6, #0xf\n\t"
        "_080E1270:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r0, r0, #0x1f\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080E12AC\n\t"
        "	ldrb r0, [r4, #6]\n\t"
        "	cmp r0, #0xc\n\t"
        "	bne _080E12AC\n\t"
        "	ldrh r0, [r4, #0x10]\n\t"
        "	strh r0, [r5]\n\t"
        "	ldrh r0, [r4, #0x12]\n\t"
        "	mov r1, sp\n\t"
        "	strh r0, [r1, #2]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	cmp sb, r1\n\t"
        "	bgt _080E12AC\n\t"
        "	cmp r1, r8\n\t"
        "	bgt _080E12AC\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r1, r0, #0x10\n\t"
        "	cmp r7, r1\n\t"
        "	bgt _080E12AC\n\t"
        "	mov r2, sl\n\t"
        "	lsls r0, r2, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r1, r0\n\t"
        "	bgt _080E12AC\n\t"
        "	ldrb r0, [r4, #0x1d]\n\t"
        "	bl ResetBerryTreeSparkleFlag\n\t"
        "_080E12AC:\n\t"
        "	adds r4, #0x24\n\t"
        "	subs r6, #1\n\t"
        "	cmp r6, #0\n\t"
        "	bge _080E1270\n\t"
        "	add sp, #4\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080E12C4: .4byte gObjectEvents\n\t"
        ".syntax divided\n\t"
    );
}
