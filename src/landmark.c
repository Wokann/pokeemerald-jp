#include "global.h"
#include "event_data.h"
#include "landmark.h"
#include "constants/region_map_sections.h"

struct Landmark
{
    const u8 *name;
    u16 flag;
};

struct LandmarkList
{
    mapsec_u8_t mapSection;
    u8 id;
    const struct Landmark *const *landmarks;
};

#define LANDMARK_DATA __attribute__((section(".rodata.landmark_data")))

static const u8 LandmarkName_FlowerShop[] LANDMARK_DATA = __("フラワ-ショップ$");
static const u8 LandmarkName_PetalburgWoods[] LANDMARK_DATA = __("トウカのもり$");
static const u8 LandmarkName_MrBrineysCottage[] LANDMARK_DATA = __("ハギろうじんのこや$");
static const u8 LandmarkName_AbandonedShip[] LANDMARK_DATA = __("すてられぶね$");
static const u8 LandmarkName_SeashoreHouse[] LANDMARK_DATA = __("うみのいえ$");
static const u8 LandmarkName_SlateportBeach[] LANDMARK_DATA = __("カイナのすなはま$");
static const u8 LandmarkName_CyclingRoad[] LANDMARK_DATA = __("サイクリング　ロ-ド$");
static const u8 LandmarkName_NewMauville[] LANDMARK_DATA = __("ニュ-キンセツ$");
static const u8 LandmarkName_TrickHouse[] LANDMARK_DATA = __("カラクリやしき$");
static const u8 LandmarkName_OldLadysRestShop[] LANDMARK_DATA = __("ケンコ-ばあさん$");
static const u8 LandmarkName_Desert[] LANDMARK_DATA = __("さばく$");
static const u8 LandmarkName_WinstrateFamily[] LANDMARK_DATA = __("カチヌキ　ファミリ-$");
static const u8 LandmarkName_CableCar[] LANDMARK_DATA = __("ロ-プウェイのりば$");
static const u8 LandmarkName_GlassWorkshop[] LANDMARK_DATA = __("ガラスざいくのみせ$");
static const u8 LandmarkName_WeatherInstitute[] LANDMARK_DATA = __("てんきけんきゅうじょ$");
static const u8 LandmarkName_MeteorFalls[] LANDMARK_DATA = __("りゅうせいのたき$");
static const u8 LandmarkName_TunnelersRestHouse[] LANDMARK_DATA = __("さぎょういんつめしょ$");
static const u8 LandmarkName_RusturfTunnel[] LANDMARK_DATA = __("カナシダトンネル$");
static const u8 LandmarkName_PokemonDayCare[] LANDMARK_DATA = __("ポケモンそだてや$");
static const u8 LandmarkName_SafariZoneEntrance[] LANDMARK_DATA = __("サファリゾ-ンいりぐち$");
static const u8 LandmarkName_MtPyre[] LANDMARK_DATA = __("おくりびやま$");
static const u8 LandmarkName_ShoalCave[] LANDMARK_DATA = __("あさせのほらあな$");
static const u8 LandmarkName_SeafloorCavern[] LANDMARK_DATA = __("かいていどうくつ$");
static const u8 LandmarkName_GraniteCave[] LANDMARK_DATA = __("いしのどうくつ$");
static const u8 LandmarkName_OceanCurrent[] LANDMARK_DATA = __("かいりゅう$");
static const u8 LandmarkName_LanettesHouse[] LANDMARK_DATA = __("マユミのいえ$");
static const u8 LandmarkName_FieryPath[] LANDMARK_DATA = __("ほのおのぬけみち$");
static const u8 LandmarkName_JaggedPass[] LANDMARK_DATA = __("デコボコさんどう$");
static const u8 LandmarkName_SkyPillar[] LANDMARK_DATA = __("そらのはしら$");
static const u8 LandmarkName_BerryMastersHouse[] LANDMARK_DATA = __("きのみ　めいじんのいえ$");
static const u8 LandmarkName_IslandCave[] LANDMARK_DATA = __("こじまのよこあな$");
static const u8 LandmarkName_DesertRuins[] LANDMARK_DATA = __("さばくいせき$");
static const u8 LandmarkName_ScorchedSlab[] LANDMARK_DATA = __("ひでりのいわと$");
static const u8 LandmarkName_AncientTomb[] LANDMARK_DATA = __("こだいづか$");
static const u8 LandmarkName_SealedChamber[] LANDMARK_DATA = __("おふれのせきしつ$");
static const u8 LandmarkName_FossilManiacsHouse[] LANDMARK_DATA = __("かせきマニアのいえ$");
static const u8 LandmarkName_HuntersHouse[] LANDMARK_DATA = __("ハンタ-のこや$");
static const u8 LandmarkName_MagmaHideout[] LANDMARK_DATA = __("マグマだんアジト$");
static const u8 LandmarkName_MirageTower[] LANDMARK_DATA = __("げんえいのとう$");
static const u8 LandmarkName_AlteringCave[] LANDMARK_DATA = __("へんげのどうくつ$");
static const u8 LandmarkName_DesertUnderpass[] LANDMARK_DATA = __("さばくのちかどう$");
static const u8 LandmarkName_TrainerHill[] LANDMARK_DATA = __("トレ-ナ-ヒル$");

static const struct Landmark Landmark_FlowerShop LANDMARK_DATA = {LandmarkName_FlowerShop, FLAG_LANDMARK_FLOWER_SHOP};
static const struct Landmark Landmark_PetalburgWoods LANDMARK_DATA = {LandmarkName_PetalburgWoods, -1};
static const struct Landmark Landmark_MrBrineysCottage LANDMARK_DATA = {LandmarkName_MrBrineysCottage, FLAG_LANDMARK_MR_BRINEY_HOUSE};
static const struct Landmark Landmark_AbandonedShip LANDMARK_DATA = {LandmarkName_AbandonedShip, FLAG_LANDMARK_ABANDONED_SHIP};
static const struct Landmark Landmark_SeashoreHouse LANDMARK_DATA = {LandmarkName_SeashoreHouse, FLAG_LANDMARK_SEASHORE_HOUSE};
static const struct Landmark Landmark_SlateportBeach LANDMARK_DATA = {LandmarkName_SlateportBeach, -1};
static const struct Landmark Landmark_CyclingRoad LANDMARK_DATA = {LandmarkName_CyclingRoad, -1};
static const struct Landmark Landmark_NewMauville LANDMARK_DATA = {LandmarkName_NewMauville, FLAG_LANDMARK_NEW_MAUVILLE};
static const struct Landmark Landmark_TrickHouse LANDMARK_DATA = {LandmarkName_TrickHouse, FLAG_LANDMARK_TRICK_HOUSE};
static const struct Landmark Landmark_OldLadysRestShop LANDMARK_DATA = {LandmarkName_OldLadysRestShop, FLAG_LANDMARK_OLD_LADY_REST_SHOP};
static const struct Landmark Landmark_Desert LANDMARK_DATA = {LandmarkName_Desert, -1};
static const struct Landmark Landmark_WinstrateFamily LANDMARK_DATA = {LandmarkName_WinstrateFamily, FLAG_LANDMARK_WINSTRATE_FAMILY};
static const struct Landmark Landmark_CableCar LANDMARK_DATA = {LandmarkName_CableCar, -1};
static const struct Landmark Landmark_GlassWorkshop LANDMARK_DATA = {LandmarkName_GlassWorkshop, FLAG_LANDMARK_GLASS_WORKSHOP};
static const struct Landmark Landmark_WeatherInstitute LANDMARK_DATA = {LandmarkName_WeatherInstitute, -1};
static const struct Landmark Landmark_MeteorFalls LANDMARK_DATA = {LandmarkName_MeteorFalls, -1};
static const struct Landmark Landmark_TunnelersRestHouse LANDMARK_DATA = {LandmarkName_TunnelersRestHouse, FLAG_LANDMARK_TUNNELERS_REST_HOUSE};
static const struct Landmark Landmark_RusturfTunnel LANDMARK_DATA = {LandmarkName_RusturfTunnel, -1};
static const struct Landmark Landmark_PokemonDayCare LANDMARK_DATA = {LandmarkName_PokemonDayCare, FLAG_LANDMARK_POKEMON_DAYCARE};
static const struct Landmark Landmark_SafariZoneEntrance LANDMARK_DATA = {LandmarkName_SafariZoneEntrance, -1};
static const struct Landmark Landmark_MtPyre LANDMARK_DATA = {LandmarkName_MtPyre, -1};
static const struct Landmark Landmark_ShoalCave LANDMARK_DATA = {LandmarkName_ShoalCave, -1};
static const struct Landmark Landmark_SeafloorCavern LANDMARK_DATA = {LandmarkName_SeafloorCavern, FLAG_LANDMARK_SEAFLOOR_CAVERN};
static const struct Landmark Landmark_GraniteCave LANDMARK_DATA = {LandmarkName_GraniteCave, -1};
static const struct Landmark Landmark_OceanCurrent LANDMARK_DATA = {LandmarkName_OceanCurrent, -1};
static const struct Landmark Landmark_LanettesHouse LANDMARK_DATA = {LandmarkName_LanettesHouse, FLAG_LANDMARK_LANETTES_HOUSE};
static const struct Landmark Landmark_FieryPath LANDMARK_DATA = {LandmarkName_FieryPath, FLAG_LANDMARK_FIERY_PATH};
static const struct Landmark Landmark_JaggedPass LANDMARK_DATA = {LandmarkName_JaggedPass, -1};
static const struct Landmark Landmark_BerryMastersHouse LANDMARK_DATA = {LandmarkName_BerryMastersHouse, FLAG_LANDMARK_BERRY_MASTERS_HOUSE};
static const struct Landmark Landmark_IslandCave LANDMARK_DATA = {LandmarkName_IslandCave, FLAG_LANDMARK_ISLAND_CAVE};
static const struct Landmark Landmark_DesertRuins LANDMARK_DATA = {LandmarkName_DesertRuins, FLAG_LANDMARK_DESERT_RUINS};
static const struct Landmark Landmark_ScorchedSlab LANDMARK_DATA = {LandmarkName_ScorchedSlab, FLAG_LANDMARK_SCORCHED_SLAB};
static const struct Landmark Landmark_AncientTomb LANDMARK_DATA = {LandmarkName_AncientTomb, FLAG_LANDMARK_ANCIENT_TOMB};
static const struct Landmark Landmark_SealedChamber LANDMARK_DATA = {LandmarkName_SealedChamber, FLAG_LANDMARK_SEALED_CHAMBER};
static const struct Landmark Landmark_FossilManiacsHouse LANDMARK_DATA = {LandmarkName_FossilManiacsHouse, FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE};
static const struct Landmark Landmark_HuntersHouse LANDMARK_DATA = {LandmarkName_HuntersHouse, FLAG_LANDMARK_HUNTERS_HOUSE};
static const struct Landmark Landmark_SkyPillar LANDMARK_DATA = {LandmarkName_SkyPillar, FLAG_LANDMARK_SKY_PILLAR};
static const struct Landmark Landmark_MirageTower LANDMARK_DATA = {LandmarkName_MirageTower, FLAG_LANDMARK_MIRAGE_TOWER};
static const struct Landmark Landmark_AlteringCave LANDMARK_DATA = {LandmarkName_AlteringCave, FLAG_LANDMARK_ALTERING_CAVE};
static const struct Landmark Landmark_DesertUnderpass LANDMARK_DATA = {LandmarkName_DesertUnderpass, FLAG_LANDMARK_DESERT_UNDERPASS};
static const struct Landmark Landmark_TrainerHill LANDMARK_DATA = {LandmarkName_TrainerHill, FLAG_LANDMARK_TRAINER_HILL};

static const struct Landmark *const Landmarks_Route103_2[] LANDMARK_DATA =
{
    &Landmark_AlteringCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route104_0[] LANDMARK_DATA =
{
    &Landmark_FlowerShop,
    NULL,
};

static const struct Landmark *const Landmarks_Route104_1[] LANDMARK_DATA =
{
    &Landmark_PetalburgWoods,
    &Landmark_MrBrineysCottage,
    NULL,
};

static const struct Landmark *const Landmarks_Route105_0[] LANDMARK_DATA =
{
    &Landmark_IslandCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route106_1[] LANDMARK_DATA =
{
    &Landmark_GraniteCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route108_0[] LANDMARK_DATA =
{
    &Landmark_AbandonedShip,
    NULL,
};

static const struct Landmark *const Landmarks_Route109_0[] LANDMARK_DATA =
{
    &Landmark_SeashoreHouse,
    &Landmark_SlateportBeach,
    NULL,
};

static const struct Landmark *const Landmarks_Route110_0[] LANDMARK_DATA =
{
    &Landmark_CyclingRoad,
    &Landmark_NewMauville,
    NULL,
};

static const struct Landmark *const Landmarks_Route110_1[] LANDMARK_DATA =
{
    &Landmark_CyclingRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route110_2[] LANDMARK_DATA =
{
    &Landmark_CyclingRoad,
    &Landmark_TrickHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_0[] LANDMARK_DATA =
{
    &Landmark_OldLadysRestShop,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_1[] LANDMARK_DATA =
{
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_2[] LANDMARK_DATA =
{
    &Landmark_MirageTower,
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_3[] LANDMARK_DATA =
{
    &Landmark_DesertRuins,
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_4[] LANDMARK_DATA =
{
    &Landmark_TrainerHill,
    &Landmark_WinstrateFamily,
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route112_0[] LANDMARK_DATA =
{
    &Landmark_FieryPath,
    &Landmark_JaggedPass,
    NULL,
};

static const struct Landmark *const Landmarks_Route112_1[] LANDMARK_DATA =
{
    &Landmark_CableCar,
    &Landmark_FieryPath,
    NULL,
};

static const struct Landmark *const Landmarks_Route113_1[] LANDMARK_DATA =
{
    &Landmark_GlassWorkshop,
    NULL,
};

static const struct Landmark *const Landmarks_Route114_1[] LANDMARK_DATA =
{
    &Landmark_DesertUnderpass,
    &Landmark_FossilManiacsHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route114_2[] LANDMARK_DATA =
{
    &Landmark_LanettesHouse,
    NULL,
};

static const struct Landmark *const Landmarks_MeteorFalls[] LANDMARK_DATA =
{
    &Landmark_MeteorFalls,
    NULL,
};

static const struct Landmark *const Landmarks_Route116_1[] LANDMARK_DATA =
{
    &Landmark_TunnelersRestHouse,
    &Landmark_RusturfTunnel,
    NULL,
};

static const struct Landmark *const Landmarks_Route116_2[] LANDMARK_DATA =
{
    &Landmark_RusturfTunnel,
    NULL,
};

static const struct Landmark *const Landmarks_Route117_2[] LANDMARK_DATA =
{
    &Landmark_PokemonDayCare,
    NULL,
};

static const struct Landmark *const Landmarks_Route119_1[] LANDMARK_DATA =
{
    &Landmark_WeatherInstitute,
    NULL,
};

static const struct Landmark *const Landmarks_Route120_0[] LANDMARK_DATA =
{
    &Landmark_ScorchedSlab,
    NULL,
};

static const struct Landmark *const Landmarks_Route120_2[] LANDMARK_DATA =
{
    &Landmark_AncientTomb,
    NULL,
};

static const struct Landmark *const Landmarks_Route121_2[] LANDMARK_DATA =
{
    &Landmark_SafariZoneEntrance,
    NULL,
};

static const struct Landmark *const Landmarks_Route122_0[] LANDMARK_DATA =
{
    &Landmark_MtPyre,
    NULL,
};

static const struct Landmark *const Landmarks_Route123_0[] LANDMARK_DATA =
{
    &Landmark_BerryMastersHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route124_7[] LANDMARK_DATA =
{
    &Landmark_HuntersHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route125_2[] LANDMARK_DATA =
{
    &Landmark_ShoalCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route128_1[] LANDMARK_DATA =
{
    &Landmark_SeafloorCavern,
    NULL,
};

static const struct Landmark *const Landmarks_Route131_1[] LANDMARK_DATA =
{
    &Landmark_SkyPillar,
    NULL,
};

static const struct Landmark *const Landmarks_OceanCurrent[] LANDMARK_DATA =
{
    &Landmark_OceanCurrent,
    NULL,
};

static const struct Landmark *const Landmarks_Route134_2[] LANDMARK_DATA =
{
    &Landmark_SealedChamber,
    &Landmark_OceanCurrent,
    NULL,
};

static const struct Landmark *const Landmarks_MtChimney_2[] LANDMARK_DATA =
{
    &Landmark_CableCar,
    &Landmark_JaggedPass,
    NULL,
};

static const struct LandmarkList sLandmarkLists[] LANDMARK_DATA =
{
    {MAPSEC_ROUTE_103, 2, Landmarks_Route103_2},
    {MAPSEC_ROUTE_104, 0, Landmarks_Route104_0},
    {MAPSEC_ROUTE_104, 1, Landmarks_Route104_1},
    {MAPSEC_ROUTE_105, 0, Landmarks_Route105_0},
    {MAPSEC_ROUTE_106, 1, Landmarks_Route106_1},
    {MAPSEC_ROUTE_108, 0, Landmarks_Route108_0},
    {MAPSEC_ROUTE_109, 0, Landmarks_Route109_0},
    {MAPSEC_ROUTE_110, 0, Landmarks_Route110_0},
    {MAPSEC_ROUTE_110, 1, Landmarks_Route110_1},
    {MAPSEC_ROUTE_110, 2, Landmarks_Route110_2},
    {MAPSEC_ROUTE_111, 0, Landmarks_Route111_0},
    {MAPSEC_ROUTE_111, 1, Landmarks_Route111_1},
    {MAPSEC_ROUTE_111, 2, Landmarks_Route111_2},
    {MAPSEC_ROUTE_111, 3, Landmarks_Route111_3},
    {MAPSEC_ROUTE_111, 4, Landmarks_Route111_4},
    {MAPSEC_ROUTE_112, 0, Landmarks_Route112_0},
    {MAPSEC_ROUTE_112, 1, Landmarks_Route112_1},
    {MAPSEC_ROUTE_113, 1, Landmarks_Route113_1},
    {MAPSEC_ROUTE_114, 1, Landmarks_Route114_1},
    {MAPSEC_ROUTE_114, 2, Landmarks_Route114_2},
    {MAPSEC_ROUTE_114, 3, Landmarks_MeteorFalls},
    {MAPSEC_ROUTE_115, 0, Landmarks_MeteorFalls},
    {MAPSEC_ROUTE_115, 1, Landmarks_MeteorFalls},
    {MAPSEC_ROUTE_116, 1, Landmarks_Route116_1},
    {MAPSEC_ROUTE_116, 2, Landmarks_Route116_2},
    {MAPSEC_ROUTE_117, 2, Landmarks_Route117_2},
    {MAPSEC_ROUTE_119, 1, Landmarks_Route119_1},
    {MAPSEC_ROUTE_120, 0, Landmarks_Route120_0},
    {MAPSEC_ROUTE_120, 2, Landmarks_Route120_2},
    {MAPSEC_ROUTE_121, 2, Landmarks_Route121_2},
    {MAPSEC_ROUTE_122, 0, Landmarks_Route122_0},
#ifdef BUGFIX
    {MAPSEC_ROUTE_122, 1, Landmarks_Route122_0},
    {MAPSEC_ROUTE_123, 0, Landmarks_Route123_0},
#else
    {MAPSEC_ROUTE_123, 0, Landmarks_Route123_0},
    {MAPSEC_ROUTE_122, 1, Landmarks_Route122_0},
#endif
    {MAPSEC_ROUTE_124, 7, Landmarks_Route124_7},
    {MAPSEC_ROUTE_125, 2, Landmarks_Route125_2},
    {MAPSEC_ROUTE_128, 1, Landmarks_Route128_1},
    {MAPSEC_ROUTE_131, 1, Landmarks_Route131_1},
    {MAPSEC_ROUTE_132, 0, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_132, 1, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_133, 0, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_133, 1, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_133, 2, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_134, 0, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_134, 1, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_134, 2, Landmarks_Route134_2},
    {MAPSEC_MT_CHIMNEY, 2, Landmarks_MtChimney_2},
    {MAPSEC_NONE, 0, NULL},
};

const u8 *GetLandmarkName(mapsec_u8_t mapSection, u8 id, u8 count)
{
    const struct Landmark *const *landmarks = GetLandmarks(mapSection, id);

    if (!landmarks)
        return NULL;

    while (1)
    {
        const struct Landmark *landmark = *landmarks;

        if (landmark->flag == 0xFFFF || FlagGet(landmark->flag) == TRUE)
        {
            if (count == 0)
                break;
            else
                count--;
        }

        landmarks++;
        if (!*landmarks)
            return NULL;
    }

    return (*landmarks)->name;
}

const struct Landmark *const *GetLandmarks(mapsec_u8_t mapSection, u8 id)
{
    u16 i = 0;

    for (; sLandmarkLists[i].mapSection != MAPSEC_NONE; i++)
    {
        if (sLandmarkLists[i].mapSection > mapSection)
            return NULL;
        if (sLandmarkLists[i].mapSection == mapSection)
            break;
    }

    if (sLandmarkLists[i].mapSection == MAPSEC_NONE)
        return NULL;

    for (; sLandmarkLists[i].mapSection == mapSection; i++)
    {
        if (sLandmarkLists[i].id == id)
            return sLandmarkLists[i].landmarks;
    }

    return NULL;
}
