#include "global.h"
#include "battle_anim.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_weather.h"
#include "overworld.h"
#include "random.h"
#include "script.h"
#include "constants/weather.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "trig.h"
#include "gpu_regs.h"

// Keep the existing JP RAM owners and linker identities; allocate no new state.
extern u8 sCurrentAbnormalWeather asm("gUnknown_2038864");
extern u16 sUnusedWeatherRelated asm("gUnknown_2038866");

// The weather core still exports the original JP linker names.
void ApplyWeatherColorMapIfIdle(s8 colorMapIndex) asm("sub_080AB544");
void ApplyWeatherColorMapIfIdle_Gradual(u8 colorMapIndex, u8 targetColorMapIndex, u8 colorMapStepDelay) asm("sub_080AB578");
void DroughtStateInit(void) asm("sub_080AB8EC");
void DroughtStateRun(void) asm("sub_080AB918");

// Semantic US names retain each original JP function identity, including the
// historically misnamed rain, fog and Sunny/Drought/Shade finish callbacks.
void Clouds_InitVars(void);
void Clouds_InitAll(void);
void Clouds_Main(void);
bool8 Clouds_Finish(void);
void Sunny_InitVars(void);
void Sunny_InitAll(void);
void Sunny_Main(void);
bool8 Sunny_Finish(void) asm("Shade_Finish");
void CreateCloudSprites(void);
void DestroyCloudSprites(void);
void UpdateCloudSprite(struct Sprite *sprite);
void Drought_InitVars(void);
void Drought_InitAll(void);
void Drought_Main(void);
bool8 Drought_Finish(void) asm("Sunny_Finish");
void StartDroughtWeatherBlend(void);
void UpdateDroughtBlend(u8 taskId);
void Rain_InitVars(void) asm("LightRain_InitVars");
void Rain_InitAll(void) asm("LightRain_InitAll");
void Rain_Main(void) asm("LightRain_Main");
bool8 Rain_Finish(void) asm("LightRain_Finish");
void StartRainSpriteFall(struct Sprite *sprite);
void UpdateRainSprite(struct Sprite *sprite);
void WaitRainSprite(struct Sprite *sprite);
void InitRainSpriteMovement(struct Sprite *sprite, u16 val);
void LoadRainSpriteSheet(void);
bool8 CreateRainSprite(void);
bool8 UpdateVisibleRainSprites(void);
void DestroyRainSprites(void);
void Snow_InitVars(void);
void Snow_InitAll(void);
void Snow_Main(void);
bool8 Snow_Finish(void);
bool8 UpdateVisibleSnowflakeSprites(void);
bool8 CreateSnowflakeSprite(void);
bool8 DestroySnowflakeSprite(void);
void InitSnowflakeSpriteMovement(struct Sprite *sprite);
void WaitSnowflakeSprite(struct Sprite *sprite);
void UpdateSnowflakeSprite(struct Sprite *sprite);
void Thunderstorm_InitVars(void) asm("MedRain_InitVars");
void Thunderstorm_InitAll(void) asm("MedRain_InitAll");
void Downpour_InitVars(void) asm("HeavyRain_InitVars");
void Downpour_InitAll(void) asm("HeavyRain_InitAll");
void Thunderstorm_Main(void) asm("Rain_Main");
bool8 Thunderstorm_Finish(void) asm("Rain_Finish");
void EnqueueThunder(u16 waitFrames) asm("SetThunderCounter");
void UpdateThunderSound(void);
void FogHorizontal_InitVars(void) asm("Fog1_InitVars");
void FogHorizontal_InitAll(void) asm("Fog1_InitAll");
void FogHorizontal_Main(void) asm("Fog1_Main");
bool8 FogHorizontal_Finish(void) asm("Fog1_Finish");
void FogHorizontalSpriteCallback(struct Sprite *sprite) asm("Fog1SpriteCallback");
void CreateFogHorizontalSprites(void) asm("CreateFog1Sprites");
void DestroyFogHorizontalSprites(void) asm("DestroyFog1Sprites");
void Ash_InitVars(void);
void Ash_InitAll(void);
void Ash_Main(void);
bool8 Ash_Finish(void);
void LoadAshSpriteSheet(void);
void CreateAshSprites(void);
void DestroyAshSprites(void);
void UpdateAshSprite(struct Sprite *sprite);
void FogDiagonal_InitVars(void) asm("Fog2_InitVars");
void FogDiagonal_InitAll(void) asm("Fog2_InitAll");
void FogDiagonal_Main(void) asm("Fog2_Main");
bool8 FogDiagonal_Finish(void) asm("Fog2_Finish");
void UpdateFogDiagonalMovement(void) asm("UpdateFog2Movement");
void CreateFogDiagonalSprites(void) asm("CreateFog2Sprites");
void DestroyFogDiagonalSprites(void) asm("DestroyFog2Sprites");
void UpdateFogDiagonalSprite(struct Sprite *sprite) asm("UpdateFog2Sprite");
void Sandstorm_InitVars(void);
void Sandstorm_InitAll(void);
void Sandstorm_Main(void);
bool8 Sandstorm_Finish(void);
void UpdateSandstormWaveIndex(void);
void UpdateSandstormMovement(void);
void DestroySandstormSprites(void);
void CreateSandstormSprites(void);
void CreateSwirlSandstormSprites(void);
void UpdateSandstormSprite(struct Sprite *sprite);
void WaitSandSwirlSpriteEntrance(struct Sprite *sprite);
void UpdateSandstormSwirlSprite(struct Sprite *sprite);
void Shade_InitVars(void);
void Shade_InitAll(void);
void Shade_Main(void);
bool8 Shade_Finish(void) asm("Drought_Finish");
void Bubbles_InitVars(void);
void Bubbles_InitAll(void);
void Bubbles_Main(void);
bool8 Bubbles_Finish(void);
void CreateBubbleSprite(u16 coordsIndex);
void DestroyBubbleSprites(void);
void UpdateBubbleSprite(struct Sprite *sprite);
void UnusedSetCurrentAbnormalWeather(u32 weather, u32 unknown) asm("UnusedSetCurrentAlternatingWeather");
void Task_DoAbnormalWeather(u8 taskId) asm("Task_DoAlternatingWeather");
void CreateAbnormalWeatherTask(void) asm("CreateAlternatingWeatherTask");
void SetSavedWeather(u32 weather) asm("SetSav1Weather");
u8 GetSavedWeather(void);
void SetSavedWeatherFromCurrMapHeader(void) asm("SetSav1WeatherFromCurrMapHeader");
void SetWeather(u32 weather);
void SetWeather_Unused(u32 weather);
void DoCurrentWeather(void);
void ResumePausedWeather(void);
u8 TranslateWeatherNum(u8 weather);
void UpdateWeatherPerDay(u16 increment);
void UpdateRainCounter(u8 newWeather, u8 oldWeather);


#define FIELD_WEATHER_EFFECT_RESOURCE_DATA __attribute__((section(".rodata.field_weather_effect_resource_data")))
#define FIELD_WEATHER_EFFECT_STATIC_DATA __attribute__((section(".rodata.field_weather_effect_static_data")))
#define FIELD_WEATHER_EFFECT_WEATHER_CYCLE_DATA __attribute__((section(".rodata.field_weather_effect_weather_cycle_data")))

const u16 gCloudsWeatherPalette[] FIELD_WEATHER_EFFECT_RESOURCE_DATA = INCBIN_U16("graphics/weather/cloud.gbapal");
const u16 gSandstormWeatherPalette[] FIELD_WEATHER_EFFECT_RESOURCE_DATA = INCBIN_U16("graphics/weather/sandstorm.gbapal");
const u8 gWeatherFogDiagonalTiles[] FIELD_WEATHER_EFFECT_RESOURCE_DATA = INCBIN_U8("graphics/weather/fog_diagonal.4bpp");
const u8 gWeatherFogHorizontalTiles[] FIELD_WEATHER_EFFECT_RESOURCE_DATA = INCBIN_U8("graphics/weather/fog_horizontal.4bpp");
const u8 gWeatherCloudTiles[] FIELD_WEATHER_EFFECT_RESOURCE_DATA = INCBIN_U8("graphics/weather/cloud.4bpp");
const u8 gWeatherSnow1Tiles[] FIELD_WEATHER_EFFECT_RESOURCE_DATA = INCBIN_U8("graphics/weather/snow0.4bpp");
const u8 gWeatherSnow2Tiles[] FIELD_WEATHER_EFFECT_RESOURCE_DATA = INCBIN_U8("graphics/weather/snow1.4bpp");
const u8 gWeatherBubbleTiles[] FIELD_WEATHER_EFFECT_RESOURCE_DATA = INCBIN_U8("graphics/weather/bubble.4bpp");
const u8 gWeatherAshTiles[] FIELD_WEATHER_EFFECT_RESOURCE_DATA = INCBIN_U8("graphics/weather/ash.4bpp");
const u8 gWeatherRainTiles[] FIELD_WEATHER_EFFECT_RESOURCE_DATA = INCBIN_U8("graphics/weather/rain.4bpp");
const u8 gWeatherSandstormTiles[] FIELD_WEATHER_EFFECT_RESOURCE_DATA = INCBIN_U8("graphics/weather/sandstorm.4bpp");

#define WEATHER_CYCLE_LENGTH 4

FIELD_WEATHER_EFFECT_WEATHER_CYCLE_DATA static const u8 sWeatherCycleRoute119[WEATHER_CYCLE_LENGTH] =
{
    WEATHER_SUNNY,
    WEATHER_RAIN,
    WEATHER_RAIN_THUNDERSTORM,
    WEATHER_RAIN,
};

FIELD_WEATHER_EFFECT_WEATHER_CYCLE_DATA static const u8 sWeatherCycleRoute123[WEATHER_CYCLE_LENGTH] =
{
    WEATHER_SUNNY,
    WEATHER_SUNNY,
    WEATHER_RAIN,
    WEATHER_SUNNY,
};

#undef WEATHER_CYCLE_LENGTH


static const struct Coords16 sCloudSpriteMapCoords[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    { 0, 66},
    { 5, 73},
    {10, 78},
};

static const struct SpriteSheet sCloudSpriteSheet FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .data = gWeatherCloudTiles,
    .size = sizeof(gWeatherCloudTiles),
    .tag = GFXTAG_CLOUD,
};

static const struct OamData sCloudSpriteOamData FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 3,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sCloudSpriteAnimCmd[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd *const sCloudSpriteAnimCmds[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    sCloudSpriteAnimCmd,
};

static const struct SpriteTemplate sCloudSpriteTemplate FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .tileTag = GFXTAG_CLOUD,
    .paletteTag = PALTAG_WEATHER_2,
    .oam = &sCloudSpriteOamData,
    .anims = sCloudSpriteAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateCloudSprite,
};

static const struct Coords16 sRainSpriteCoords[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    {  0,   0},
    {  0, 160},
    {  0,  64},
    {144, 224},
    {144, 128},
    { 32,  32},
    { 32, 192},
    { 32,  96},
    { 72, 128},
    { 72,  32},
    { 72, 192},
    {216,  96},
    {216,   0},
    {104, 160},
    {104,  64},
    {104, 224},
    {144,   0},
    {144, 160},
    {144,  64},
    { 32, 224},
    { 32, 128},
    { 72,  32},
    { 72, 192},
    { 48,  96},
};

static const struct OamData sRainSpriteOamData FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 2,
    .affineParam = 0,
};

static const union AnimCmd sRainSpriteFallAnimCmd[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd sRainSpriteSplashAnimCmd[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(8, 3),
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(40, 2),
    ANIMCMD_END,
};

static const union AnimCmd sRainSpriteHeavySplashAnimCmd[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(8, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sRainSpriteAnimCmds[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    sRainSpriteFallAnimCmd,
    sRainSpriteSplashAnimCmd,
    sRainSpriteHeavySplashAnimCmd,
};

static const struct SpriteTemplate sRainSpriteTemplate FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .tileTag = GFXTAG_RAIN,
    .paletteTag = PALTAG_WEATHER,
    .oam = &sRainSpriteOamData,
    .anims = sRainSpriteAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateRainSprite,
};

static const s16 sRainSpriteMovement[][2] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    {-0x68,  0xD0},
    {-0xA0, 0x140},
};

static const u16 sRainSpriteFallingDurations[][2] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    {18, 7},
    {12, 10},
};

static const struct SpriteSheet sRainSpriteSheet FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .data = gWeatherRainTiles,
    .size = sizeof(gWeatherRainTiles),
    .tag = GFXTAG_RAIN,
};

static const struct OamData sSnowflakeSpriteOamData FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteFrameImage sSnowflakeSpriteImages[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    {gWeatherSnow1Tiles, sizeof(gWeatherSnow1Tiles)},
    {gWeatherSnow2Tiles, sizeof(gWeatherSnow2Tiles)},
};

static const union AnimCmd sSnowflakeAnimCmd0[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd sSnowflakeAnimCmd1[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_END,
};

static const union AnimCmd *const sSnowflakeAnimCmds[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    sSnowflakeAnimCmd0,
    sSnowflakeAnimCmd1,
};

static const struct SpriteTemplate sSnowflakeSpriteTemplate FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .tileTag = TAG_NONE,
    .paletteTag = PALTAG_WEATHER,
    .oam = &sSnowflakeSpriteOamData,
    .anims = sSnowflakeAnimCmds,
    .images = sSnowflakeSpriteImages,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateSnowflakeSprite,
};

static const u16 sUnusedData[] FIELD_WEATHER_EFFECT_STATIC_DATA = {0, 6, 6, 12, 18, 42, 300, 300};

static const struct OamData sOamData_FogH FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_FogH_0[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_FogH_1[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(32, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_FogH_2[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(64, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_FogH_3[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(96, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_FogH_4[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(128, 16),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_FogH_5[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(160, 16),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_FogH[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    sAnim_FogH_0,
    sAnim_FogH_1,
    sAnim_FogH_2,
    sAnim_FogH_3,
    sAnim_FogH_4,
    sAnim_FogH_5,
};

static const union AffineAnimCmd sAffineAnim_FogH[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    AFFINEANIMCMD_FRAME(0x200, 0x200, 0, 0),
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sAffineAnims_FogH[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    sAffineAnim_FogH,
};

static const struct SpriteTemplate sFogHorizontalSpriteTemplate FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .tileTag = GFXTAG_FOG_H,
    .paletteTag = PALTAG_WEATHER,
    .oam = &sOamData_FogH,
    .anims = sAnims_FogH,
    .images = NULL,
    .affineAnims = sAffineAnims_FogH,
    .callback = FogHorizontalSpriteCallback,
};

static const struct SpriteSheet sFogHorizontalSpriteSheet FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .data = gWeatherFogHorizontalTiles,
    .size = sizeof(gWeatherFogHorizontalTiles),
    .tag = GFXTAG_FOG_H,
};

static const struct SpriteSheet sAshSpriteSheet FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .data = gWeatherAshTiles,
    .size = sizeof(gWeatherAshTiles),
    .tag = GFXTAG_ASH,
};

static const struct OamData sAshSpriteOamData FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 15,
};

static const union AnimCmd sAshSpriteAnimCmd0[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(0, 60),
    ANIMCMD_FRAME(64, 60),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAshSpriteAnimCmds[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    sAshSpriteAnimCmd0,
};

static const struct SpriteTemplate sAshSpriteTemplate FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .tileTag = GFXTAG_ASH,
    .paletteTag = PALTAG_WEATHER,
    .oam = &sAshSpriteOamData,
    .anims = sAshSpriteAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateAshSprite,
};

static const struct SpriteSheet sFogDiagonalSpriteSheet FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .data = gWeatherFogDiagonalTiles,
    .size = sizeof(gWeatherFogDiagonalTiles),
    .tag = GFXTAG_FOG_D,
};

static const struct OamData sFogDiagonalSpriteOamData FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
};

static const union AnimCmd sFogDiagonalSpriteAnimCmd0[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END,
};

static const union AnimCmd *const sFogDiagonalSpriteAnimCmds[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    sFogDiagonalSpriteAnimCmd0,
};

static const struct SpriteTemplate sFogDiagonalSpriteTemplate FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .tileTag = GFXTAG_FOG_D,
    .paletteTag = PALTAG_WEATHER,
    .oam = &sFogDiagonalSpriteOamData,
    .anims = sFogDiagonalSpriteAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateFogDiagonalSprite,
};

static const struct OamData sSandstormSpriteOamData FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_BLEND,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
};

static const union AnimCmd sSandstormSpriteAnimCmd0[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END,
};

static const union AnimCmd sSandstormSpriteAnimCmd1[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(64, 3),
    ANIMCMD_END,
};

static const union AnimCmd *const sSandstormSpriteAnimCmds[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    sSandstormSpriteAnimCmd0,
    sSandstormSpriteAnimCmd1,
};

static const struct SpriteTemplate sSandstormSpriteTemplate FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .tileTag = GFXTAG_SANDSTORM,
    .paletteTag = PALTAG_WEATHER_2,
    .oam = &sSandstormSpriteOamData,
    .anims = sSandstormSpriteAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateSandstormSprite,
};

static const struct SpriteSheet sSandstormSpriteSheet FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .data = gWeatherSandstormTiles,
    .size = sizeof(gWeatherSandstormTiles),
    .tag = GFXTAG_SANDSTORM,
};

static const u16 sSwirlEntranceDelays[] FIELD_WEATHER_EFFECT_STATIC_DATA = {0, 120, 80, 160, 40, 0};

static const u8 sBubbleStartDelays[] FIELD_WEATHER_EFFECT_STATIC_DATA = {40, 90, 60, 90, 2, 60, 40, 30};

static const struct SpriteSheet sWeatherBubbleSpriteSheet FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .data = gWeatherBubbleTiles,
    .size = sizeof(gWeatherBubbleTiles),
    .tag = GFXTAG_BUBBLE,
};

static const s16 sBubbleStartCoords[][2] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    {120, 160},
    {376, 160},
    { 40, 140},
    {296, 140},
    {180, 130},
    {436, 130},
    { 60, 160},
    {436, 160},
    {220, 180},
    {476, 180},
    { 10,  90},
    {266,  90},
    {256, 160},
};

static const union AnimCmd sBubbleSpriteAnimCmd0[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_END,
};

static const union AnimCmd *const sBubbleSpriteAnimCmds[] FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    sBubbleSpriteAnimCmd0,
};

static const struct SpriteTemplate sBubbleSpriteTemplate FIELD_WEATHER_EFFECT_STATIC_DATA =
{
    .tileTag = GFXTAG_BUBBLE,
    .paletteTag = PALTAG_WEATHER,
    .oam = &gOamData_AffineOff_ObjNormal_8x8,
    .anims = sBubbleSpriteAnimCmds,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = UpdateBubbleSprite,
};

enum {
    // This block of states is run only once
    // when first setting up the thunderstorm
    THUNDER_STATE_LOAD_RAIN,
    THUNDER_STATE_CREATE_RAIN,
    THUNDER_STATE_INIT_RAIN,
    THUNDER_STATE_WAIT_CHANGE,

    // The thunderstorm loops through these states,
    // not necessarily in order.
    THUNDER_STATE_NEW_CYCLE,
    THUNDER_STATE_NEW_CYCLE_WAIT,
    THUNDER_STATE_INIT_CYCLE_1,
    THUNDER_STATE_INIT_CYCLE_2,
    THUNDER_STATE_SHORT_BOLT,
    THUNDER_STATE_TRY_NEW_BOLT,
    THUNDER_STATE_WAIT_BOLT_SHORT,
    THUNDER_STATE_INIT_BOLT_LONG,
    THUNDER_STATE_WAIT_BOLT_LONG,
    THUNDER_STATE_FADE_BOLT_LONG,
    THUNDER_STATE_END_BOLT_LONG,
};

void Clouds_InitVars(void)
{
    gWeatherPtr->targetColorMapIndex = 0;
    gWeatherPtr->colorMapStepDelay = 20;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->initStep = 0;
    if (gWeatherPtr->cloudSpritesCreated == FALSE)
        Weather_SetBlendCoeffs(0, 16);
}

void Clouds_InitAll(void)
{
    Clouds_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Clouds_Main();
}

void Clouds_Main(void)
{
    switch (gWeatherPtr->initStep)
    {
    case 0:
        CreateCloudSprites();
        gWeatherPtr->initStep++;
        break;
    case 1:
        Weather_SetTargetBlendCoeffs(12, 8, 1);
        gWeatherPtr->initStep++;
        break;
    case 2:
        if (Weather_UpdateBlend())
        {
            gWeatherPtr->weatherGfxLoaded = TRUE;
            gWeatherPtr->initStep++;
        }
        break;
    }
}

bool8 Clouds_Finish(void)
{
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        Weather_SetTargetBlendCoeffs(0, 16, 1);
        gWeatherPtr->finishStep++;
        return TRUE;
    case 1:
        if (Weather_UpdateBlend())
        {
            DestroyCloudSprites();
            gWeatherPtr->finishStep++;
        }
        return TRUE;
    }
    return FALSE;
}

void Sunny_InitVars(void)
{
    gWeatherPtr->targetColorMapIndex = 0;
    gWeatherPtr->colorMapStepDelay = 20;
}

void Sunny_InitAll(void)
{
    Sunny_InitVars();
}

void Sunny_Main(void)
{
}

bool8 Sunny_Finish(void)
{
    return FALSE;
}

void CreateCloudSprites(void)
{
    u16 i;
    u8 spriteId;
    struct Sprite *sprite;

    if (gWeatherPtr->cloudSpritesCreated == TRUE)
        return;

    LoadSpriteSheet(&sCloudSpriteSheet);
    LoadCustomWeatherSpritePalette(gCloudsWeatherPalette);
    for (i = 0; i < NUM_CLOUD_SPRITES; i++)
    {
        spriteId = CreateSprite(&sCloudSpriteTemplate, 0, 0, 0xFF);
        if (spriteId != MAX_SPRITES)
        {
            gWeatherPtr->sprites.s1.cloudSprites[i] = &gSprites[spriteId];
            sprite = gWeatherPtr->sprites.s1.cloudSprites[i];
            SetSpritePosToMapCoords(sCloudSpriteMapCoords[i].x + MAP_OFFSET, sCloudSpriteMapCoords[i].y + MAP_OFFSET, &sprite->x, &sprite->y);
            sprite->coordOffsetEnabled = TRUE;
        }
        else
        {
            gWeatherPtr->sprites.s1.cloudSprites[i] = NULL;
        }
    }

    gWeatherPtr->cloudSpritesCreated = TRUE;
}

void DestroyCloudSprites(void)
{
    u16 i;

    if (!gWeatherPtr->cloudSpritesCreated)
        return;

    for (i = 0; i < NUM_CLOUD_SPRITES; i++)
    {
        if (gWeatherPtr->sprites.s1.cloudSprites[i] != NULL)
            DestroySprite(gWeatherPtr->sprites.s1.cloudSprites[i]);
    }

    FreeSpriteTilesByTag(GFXTAG_CLOUD);
    gWeatherPtr->cloudSpritesCreated = FALSE;
}

void UpdateCloudSprite(struct Sprite *sprite)
{
    // Move 1 pixel left every 2 frames.
    sprite->data[0] = (sprite->data[0] + 1) & 1;
    if (sprite->data[0])
        sprite->x--;
}

void Drought_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->targetColorMapIndex = 0;
    gWeatherPtr->colorMapStepDelay = 0;
}

void Drought_InitAll(void)
{
    Drought_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Drought_Main();
}

void Drought_Main(void)
{
    switch (gWeatherPtr->initStep)
    {
    case 0:
        if (gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_CHANGING_WEATHER)
            gWeatherPtr->initStep++;
        break;
    case 1:
        ResetDroughtWeatherPaletteLoading();
        gWeatherPtr->initStep++;
        break;
    case 2:
        if (LoadDroughtWeatherPalettes() == FALSE)
            gWeatherPtr->initStep++;
        break;
    case 3:
        DroughtStateInit();
        gWeatherPtr->initStep++;
        break;
    case 4:
        DroughtStateRun();
        if (gWeatherPtr->droughtBrightnessStage == 6)
        {
            gWeatherPtr->weatherGfxLoaded = TRUE;
            gWeatherPtr->initStep++;
        }
        break;
    default:
        DroughtStateRun();
        break;
    }
}

bool8 Drought_Finish(void)
{
    return FALSE;
}

void StartDroughtWeatherBlend(void)
{
    CreateTask(UpdateDroughtBlend, 80);
}

void UpdateDroughtBlend(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        task->data[1] = 0;
        task->data[2] = 0;
        task->data[3] = REG_WININ;
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL | WININ_WIN1_ALL);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_LIGHTEN);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        task->data[0]++;
        // fall through
    case 1:
        task->data[1] += 3;
        if (task->data[1] > 16)
            task->data[1] = 16;
        SetGpuReg(REG_OFFSET_BLDY, task->data[1]);
        if (task->data[1] >= 16)
            task->data[0]++;
        break;
    case 2:
        task->data[2]++;
        if (task->data[2] > 9)
        {
            task->data[2] = 0;
            task->data[1]--;
            if (task->data[1] <= 0)
            {
                task->data[1] = 0;
                task->data[0]++;
            }
            SetGpuReg(REG_OFFSET_BLDY, task->data[1]);
        }
        break;
    case 3:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_WININ, task->data[3]);
        task->data[0]++;
        break;
    case 4:
        ScriptContext_Enable();
        DestroyTask(taskId);
        break;
    }
}

void Rain_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->rainSpriteVisibleCounter = 0;
    gWeatherPtr->rainSpriteVisibleDelay = 8;
    gWeatherPtr->isDownpour = FALSE;
    gWeatherPtr->targetRainSpriteCount = 10;
    gWeatherPtr->targetColorMapIndex = 3;
    gWeatherPtr->colorMapStepDelay = 20;
    SetRainStrengthFromSoundEffect(SE_RAIN);
}

void Rain_InitAll(void)
{
    Rain_InitVars();
    while (!gWeatherPtr->weatherGfxLoaded)
        Rain_Main();
}

void Rain_Main(void)
{
    switch (gWeatherPtr->initStep)
    {
    case 0:
        LoadRainSpriteSheet();
        gWeatherPtr->initStep++;
        break;
    case 1:
        if (!CreateRainSprite())
            gWeatherPtr->initStep++;
        break;
    case 2:
        if (!UpdateVisibleRainSprites())
        {
            gWeatherPtr->weatherGfxLoaded = TRUE;
            gWeatherPtr->initStep++;
        }
        break;
    }
}

bool8 Rain_Finish(void)
{
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        if (gWeatherPtr->nextWeather == WEATHER_RAIN
         || gWeatherPtr->nextWeather == WEATHER_RAIN_THUNDERSTORM
         || gWeatherPtr->nextWeather == WEATHER_DOWNPOUR)
        {
            gWeatherPtr->finishStep = 0xFF;
            return FALSE;
        }
        else
        {
            gWeatherPtr->targetRainSpriteCount = 0;
            gWeatherPtr->finishStep++;
        }
        // fall through
    case 1:
        if (!UpdateVisibleRainSprites())
        {
            DestroyRainSprites();
            gWeatherPtr->finishStep++;
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

void StartRainSpriteFall(struct Sprite *sprite)
{
    u32 rand;
    u16 numFallingFrames;
    int tileX;
    int tileY;

    if (sprite->data[1] == 0)
        sprite->data[1] = 361;

    rand = ISO_RANDOMIZE2(sprite->data[1]);
    sprite->data[1] = ((rand & 0x7FFF0000) >> 16) % 600;

    numFallingFrames = sRainSpriteFallingDurations[gWeatherPtr->isDownpour][0];

    tileX = sprite->data[1] % 30;
    sprite->data[2] = tileX * 8; // Useless assignment, leftover from before fixed-point values were used

    tileY = sprite->data[1] / 30;
    sprite->data[3] = tileY * 8; // Useless assignment, leftover from before fixed-point values were used

    sprite->data[2] = tileX;
    sprite->data[2] <<= 7; // This is tileX * 8, using a fixed-point value with 4 decimal places

    sprite->data[3] = tileY;
    sprite->data[3] <<= 7; // This is tileX * 8, using a fixed-point value with 4 decimal places

    // "Rewind" the rain sprites, from their ending position.
    sprite->data[2] -= sRainSpriteMovement[gWeatherPtr->isDownpour][0] * numFallingFrames;
    sprite->data[3] -= sRainSpriteMovement[gWeatherPtr->isDownpour][1] * numFallingFrames;

    StartSpriteAnim(sprite, 0);
    sprite->data[4] = 0;
    sprite->coordOffsetEnabled = FALSE;
    sprite->data[0] = numFallingFrames;
}

void UpdateRainSprite(struct Sprite *sprite)
{
    if (sprite->data[4] == 0)
    {
        // Raindrop is in its "falling" motion.
        sprite->data[2] += sRainSpriteMovement[gWeatherPtr->isDownpour][0];
        sprite->data[3] += sRainSpriteMovement[gWeatherPtr->isDownpour][1];
        sprite->x = sprite->data[2] >> 4;
        sprite->y = sprite->data[3] >> 4;

        if (sprite->data[5]
         && (sprite->x >= -8 && sprite->x <= DISPLAY_WIDTH + 8)
         && sprite->y >= -16 && sprite->y <= DISPLAY_HEIGHT + 16)
            sprite->invisible = FALSE;
        else
            sprite->invisible = TRUE;

        if (--sprite->data[0] == 0)
        {
            // Make raindrop splash on the ground
            StartSpriteAnim(sprite, gWeatherPtr->isDownpour + 1);
            sprite->data[4] = 1;
            sprite->x -= gSpriteCoordOffsetX;
            sprite->y -= gSpriteCoordOffsetY;
            sprite->coordOffsetEnabled = TRUE;
        }
    }
    else if (sprite->animEnded)
    {
        // The splashing animation ended.
        sprite->invisible = TRUE;
        StartRainSpriteFall(sprite);
    }
}

void WaitRainSprite(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        StartRainSpriteFall(sprite);
        sprite->callback = UpdateRainSprite;
    }
    else
    {
        sprite->data[0]--;
    }
}

void InitRainSpriteMovement(struct Sprite *sprite, u16 val)
{
    u16 numFallingFrames = sRainSpriteFallingDurations[gWeatherPtr->isDownpour][0];
    u16 numAdvanceRng = val / (sRainSpriteFallingDurations[gWeatherPtr->isDownpour][1] + numFallingFrames);
    u16 frameVal = val % (sRainSpriteFallingDurations[gWeatherPtr->isDownpour][1] + numFallingFrames);

    while (--numAdvanceRng != 0xFFFF)
        StartRainSpriteFall(sprite);

    if (frameVal < numFallingFrames)
    {
        while (--frameVal != 0xFFFF)
            UpdateRainSprite(sprite);

        sprite->data[6] = 0;
    }
    else
    {
        sprite->data[0] = frameVal - numFallingFrames;
        sprite->invisible = TRUE;
        sprite->data[6] = 1;
    }
}

void LoadRainSpriteSheet(void)
{
    LoadSpriteSheet(&sRainSpriteSheet);
}

bool8 CreateRainSprite(void)
{
    u8 spriteIndex;
    u8 spriteId;

    if (gWeatherPtr->rainSpriteCount == MAX_RAIN_SPRITES)
        return FALSE;

    spriteIndex = gWeatherPtr->rainSpriteCount;
    spriteId = CreateSpriteAtEnd(&sRainSpriteTemplate,
      sRainSpriteCoords[spriteIndex].x, sRainSpriteCoords[spriteIndex].y, 78);

    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].data[5] = FALSE;
        gSprites[spriteId].data[1] = spriteIndex * 145;
        while (gSprites[spriteId].data[1] >= 600)
            gSprites[spriteId].data[1] -= 600;

        StartRainSpriteFall(&gSprites[spriteId]);
        InitRainSpriteMovement(&gSprites[spriteId], spriteIndex * 9);
        gSprites[spriteId].invisible = TRUE;
        gWeatherPtr->sprites.s1.rainSprites[spriteIndex] = &gSprites[spriteId];
    }
    else
    {
        gWeatherPtr->sprites.s1.rainSprites[spriteIndex] = NULL;
    }

    if (++gWeatherPtr->rainSpriteCount == MAX_RAIN_SPRITES)
    {
        u16 i;
        for (i = 0; i < MAX_RAIN_SPRITES; i++)
        {
            if (gWeatherPtr->sprites.s1.rainSprites[i])
            {
                if (!gWeatherPtr->sprites.s1.rainSprites[i]->data[6])
                    gWeatherPtr->sprites.s1.rainSprites[i]->callback = UpdateRainSprite;
                else
                    gWeatherPtr->sprites.s1.rainSprites[i]->callback = WaitRainSprite;
            }
        }

        return FALSE;
    }

    return TRUE;
}

bool8 UpdateVisibleRainSprites(void)
{
    if (gWeatherPtr->curRainSpriteIndex == gWeatherPtr->targetRainSpriteCount)
        return FALSE;

    if (++gWeatherPtr->rainSpriteVisibleCounter > gWeatherPtr->rainSpriteVisibleDelay)
    {
        gWeatherPtr->rainSpriteVisibleCounter = 0;
        if (gWeatherPtr->curRainSpriteIndex < gWeatherPtr->targetRainSpriteCount)
        {
            gWeatherPtr->sprites.s1.rainSprites[gWeatherPtr->curRainSpriteIndex++]->data[5] = TRUE;
        }
        else
        {
            gWeatherPtr->curRainSpriteIndex--;
            gWeatherPtr->sprites.s1.rainSprites[gWeatherPtr->curRainSpriteIndex]->data[5] = FALSE;
            gWeatherPtr->sprites.s1.rainSprites[gWeatherPtr->curRainSpriteIndex]->invisible = TRUE;
        }
    }
    return TRUE;
}

void DestroyRainSprites(void)
{
    u16 i;

    for (i = 0; i < gWeatherPtr->rainSpriteCount; i++)
    {
        if (gWeatherPtr->sprites.s1.rainSprites[i] != NULL)
            DestroySprite(gWeatherPtr->sprites.s1.rainSprites[i]);
    }
    gWeatherPtr->rainSpriteCount = 0;
    FreeSpriteTilesByTag(GFXTAG_RAIN);
}

void Snow_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->targetColorMapIndex = 3;
    gWeatherPtr->colorMapStepDelay = 20;
    gWeatherPtr->targetSnowflakeSpriteCount = NUM_SNOWFLAKE_SPRITES;
    gWeatherPtr->snowflakeVisibleCounter = 0;
}

void Snow_InitAll(void)
{
    u16 i;

    Snow_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
    {
        Snow_Main();
        for (i = 0; i < gWeatherPtr->snowflakeSpriteCount; i++)
            UpdateSnowflakeSprite(gWeatherPtr->sprites.s1.snowflakeSprites[i]);
    }
}

void Snow_Main(void)
{
    if (gWeatherPtr->initStep == 0 && !UpdateVisibleSnowflakeSprites())
    {
        gWeatherPtr->weatherGfxLoaded = TRUE;
        gWeatherPtr->initStep++;
    }
}

bool8 Snow_Finish(void)
{
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        gWeatherPtr->targetSnowflakeSpriteCount = 0;
        gWeatherPtr->snowflakeVisibleCounter = 0;
        gWeatherPtr->finishStep++;
        // fall through
    case 1:
        if (!UpdateVisibleSnowflakeSprites())
        {
            gWeatherPtr->finishStep++;
            return FALSE;
        }
        return TRUE;
    }

    return FALSE;
}

bool8 UpdateVisibleSnowflakeSprites(void)
{
    if (gWeatherPtr->snowflakeSpriteCount == gWeatherPtr->targetSnowflakeSpriteCount)
        return FALSE;

    if (++gWeatherPtr->snowflakeVisibleCounter > 36)
    {
        gWeatherPtr->snowflakeVisibleCounter = 0;
        if (gWeatherPtr->snowflakeSpriteCount < gWeatherPtr->targetSnowflakeSpriteCount)
            CreateSnowflakeSprite();
        else
            DestroySnowflakeSprite();
    }

    return gWeatherPtr->snowflakeSpriteCount != gWeatherPtr->targetSnowflakeSpriteCount;
}

bool8 CreateSnowflakeSprite(void)
{
    u8 spriteId = CreateSpriteAtEnd(&sSnowflakeSpriteTemplate, 0, 0, 78);
    if (spriteId == MAX_SPRITES)
        return FALSE;

    gSprites[spriteId].data[4] = gWeatherPtr->snowflakeSpriteCount;
    InitSnowflakeSpriteMovement(&gSprites[spriteId]);
    gSprites[spriteId].coordOffsetEnabled = TRUE;
    gWeatherPtr->sprites.s1.snowflakeSprites[gWeatherPtr->snowflakeSpriteCount++] = &gSprites[spriteId];
    return TRUE;
}

bool8 DestroySnowflakeSprite(void)
{
    if (gWeatherPtr->snowflakeSpriteCount)
    {
        DestroySprite(gWeatherPtr->sprites.s1.snowflakeSprites[--gWeatherPtr->snowflakeSpriteCount]);
        return TRUE;
    }

    return FALSE;
}

void InitSnowflakeSpriteMovement(struct Sprite *sprite)
{
    u16 rand;
    u16 x = ((sprite->data[4] * 5) & 7) * 30 + (Random() % 30);

    sprite->y = -3 - (gSpriteCoordOffsetY + sprite->centerToCornerVecY);
    sprite->x = x - (gSpriteCoordOffsetX + sprite->centerToCornerVecX);
    sprite->data[0] = sprite->y * 128;
    sprite->x2 = 0;
    rand = Random();
    sprite->data[1] = (rand & 3) * 5 + 64;
    sprite->data[7] = sprite->data[1];
    StartSpriteAnim(sprite, (rand & 1) ? 0 : 1);
    sprite->data[3] = 0;
    sprite->data[2] = ((rand & 3) == 0) ? 2 : 1;
    sprite->data[6] = (rand & 0x1F) + 210;
    sprite->data[5] = 0;
}

void WaitSnowflakeSprite(struct Sprite *sprite)
{
    // Timer is never incremented
    if (gWeatherPtr->snowflakeTimer > 18)
    {
        sprite->invisible = FALSE;
        sprite->callback = UpdateSnowflakeSprite;
        sprite->y = 250 - (gSpriteCoordOffsetY + sprite->centerToCornerVecY);
        sprite->data[0] = sprite->y * 128;
        gWeatherPtr->snowflakeTimer = 0;
    }
}

void UpdateSnowflakeSprite(struct Sprite *sprite)
{
    s16 x;
    s16 y;

    sprite->data[0] += sprite->data[1];
    sprite->y = sprite->data[0] >> 7;
    sprite->data[3] += sprite->data[2];
    sprite->data[3] &= 0xFF;
    sprite->x2 = gSineTable[sprite->data[3]] / 64;

    x = (sprite->x + sprite->centerToCornerVecX + gSpriteCoordOffsetX) & 0x1FF;
    if (x & 0x100)
        x |= -0x100;

    if (x < -3)
        sprite->x = 242 - (gSpriteCoordOffsetX + sprite->centerToCornerVecX);
    else if (x > 242)
        sprite->x = -3 - (gSpriteCoordOffsetX + sprite->centerToCornerVecX);

    y = (sprite->y + sprite->centerToCornerVecY + gSpriteCoordOffsetY) & 0xFF;
    if (y > 163 && y < 171)
    {
        sprite->y = 250 - (gSpriteCoordOffsetY + sprite->centerToCornerVecY);
        sprite->data[0] = sprite->y * 128;
        sprite->data[5] = 0;
        sprite->data[6] = 220;
    }
    else if (y > 242 && y < 250)
    {
        sprite->y = 163;
        sprite->data[0] = sprite->y * 128;
        sprite->data[5] = 0;
        sprite->data[6] = 220;
        sprite->invisible = TRUE;
        sprite->callback = WaitSnowflakeSprite;
    }

    if (++sprite->data[5] == sprite->data[6])
    {
        InitSnowflakeSpriteMovement(sprite);
        sprite->y = 250;
        sprite->invisible = TRUE;
        sprite->callback = WaitSnowflakeSprite;
    }
}

void Thunderstorm_InitVars(void)
{
    gWeatherPtr->initStep = THUNDER_STATE_LOAD_RAIN;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->rainSpriteVisibleCounter = 0;
    gWeatherPtr->rainSpriteVisibleDelay = 4;
    gWeatherPtr->isDownpour = FALSE;
    gWeatherPtr->targetRainSpriteCount = 16;
    gWeatherPtr->targetColorMapIndex = 3;
    gWeatherPtr->colorMapStepDelay = 20;
    gWeatherPtr->weatherGfxLoaded = FALSE;  // duplicate assignment
    gWeatherPtr->thunderEnqueued = FALSE;
    SetRainStrengthFromSoundEffect(SE_THUNDERSTORM);
}

void Thunderstorm_InitAll(void)
{
    Thunderstorm_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Thunderstorm_Main();
}

void Downpour_InitVars(void)
{
    gWeatherPtr->initStep = THUNDER_STATE_LOAD_RAIN;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->rainSpriteVisibleCounter = 0;
    gWeatherPtr->rainSpriteVisibleDelay = 4;
    gWeatherPtr->isDownpour = TRUE;
    gWeatherPtr->targetRainSpriteCount = 24;
    gWeatherPtr->targetColorMapIndex = 3;
    gWeatherPtr->colorMapStepDelay = 20;
    gWeatherPtr->weatherGfxLoaded = FALSE;  // duplicate assignment
    SetRainStrengthFromSoundEffect(SE_DOWNPOUR);
}

void Downpour_InitAll(void)
{
    Downpour_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Thunderstorm_Main();
}

void Thunderstorm_Main(void)
{
    UpdateThunderSound();
    switch (gWeatherPtr->initStep)
    {
    case THUNDER_STATE_LOAD_RAIN:
        LoadRainSpriteSheet();
        gWeatherPtr->initStep++;
        break;
    case THUNDER_STATE_CREATE_RAIN:
        if (!CreateRainSprite())
            gWeatherPtr->initStep++;
        break;
    case THUNDER_STATE_INIT_RAIN:
        if (!UpdateVisibleRainSprites())
        {
            gWeatherPtr->weatherGfxLoaded = TRUE;
            gWeatherPtr->initStep++;
        }
        break;
    case THUNDER_STATE_WAIT_CHANGE:
        if (gWeatherPtr->palProcessingState != WEATHER_PAL_STATE_CHANGING_WEATHER)
            gWeatherPtr->initStep = THUNDER_STATE_INIT_CYCLE_1;
        break;
    case THUNDER_STATE_NEW_CYCLE:
        gWeatherPtr->thunderAllowEnd = TRUE;
        gWeatherPtr->thunderTimer = (Random() % 360) + 360;
        gWeatherPtr->initStep++;
        // fall through
    case THUNDER_STATE_NEW_CYCLE_WAIT:
        // Wait between 360-720 frames before starting a new cycle.
        if (--gWeatherPtr->thunderTimer == 0)
            gWeatherPtr->initStep++;
        break;
    case THUNDER_STATE_INIT_CYCLE_1:
        gWeatherPtr->thunderAllowEnd = TRUE;
        gWeatherPtr->thunderLongBolt = Random() % 2;
        gWeatherPtr->initStep++;
        break;
    case THUNDER_STATE_INIT_CYCLE_2:
        gWeatherPtr->thunderShortBolts = (Random() & 1) + 1;
        gWeatherPtr->initStep++;
        // fall through
    case THUNDER_STATE_SHORT_BOLT:
        // Short bolt of lightning strikes.
        ApplyWeatherColorMapIfIdle(19);
        // If final lightning bolt, enqueue thunder.
        if (!gWeatherPtr->thunderLongBolt && gWeatherPtr->thunderShortBolts == 1)
            EnqueueThunder(20);

        gWeatherPtr->thunderTimer = (Random() % 3) + 6;
        gWeatherPtr->initStep++;
        break;
    case THUNDER_STATE_TRY_NEW_BOLT:
        if (--gWeatherPtr->thunderTimer == 0)
        {
            // Short bolt of lightning ends.
            ApplyWeatherColorMapIfIdle(3);
            gWeatherPtr->thunderAllowEnd = TRUE;
            if (--gWeatherPtr->thunderShortBolts != 0)
            {
                // Wait a little, then do another short bolt.
                gWeatherPtr->thunderTimer = (Random() % 16) + 60;
                gWeatherPtr->initStep = THUNDER_STATE_WAIT_BOLT_SHORT;
            }
            else if (!gWeatherPtr->thunderLongBolt)
            {
                // No more bolts, restart loop.
                gWeatherPtr->initStep = THUNDER_STATE_NEW_CYCLE;
            }
            else
            {
                // Set up long bolt.
                gWeatherPtr->initStep = THUNDER_STATE_INIT_BOLT_LONG;
            }
        }
        break;
    case THUNDER_STATE_WAIT_BOLT_SHORT:
        if (--gWeatherPtr->thunderTimer == 0)
            gWeatherPtr->initStep = THUNDER_STATE_SHORT_BOLT;
        break;
    case THUNDER_STATE_INIT_BOLT_LONG:
        gWeatherPtr->thunderTimer = (Random() % 16) + 60;
        gWeatherPtr->initStep++;
        break;
    case THUNDER_STATE_WAIT_BOLT_LONG:
        if (--gWeatherPtr->thunderTimer == 0)
        {
            // Do long bolt. Enqueue thunder with a potentially longer delay.
            EnqueueThunder(100);
            ApplyWeatherColorMapIfIdle(19);
            gWeatherPtr->thunderTimer = (Random() & 0xF) + 30;
            gWeatherPtr->initStep++;
        }
        break;
    case THUNDER_STATE_FADE_BOLT_LONG:
        if (--gWeatherPtr->thunderTimer == 0)
        {
            // Fade long bolt out over time.
            ApplyWeatherColorMapIfIdle_Gradual(19, 3, 5);
            gWeatherPtr->initStep++;
        }
        break;
    case THUNDER_STATE_END_BOLT_LONG:
        if (gWeatherPtr->palProcessingState == WEATHER_PAL_STATE_IDLE)
        {
            gWeatherPtr->thunderAllowEnd = TRUE;
            gWeatherPtr->initStep = THUNDER_STATE_NEW_CYCLE;
        }
        break;
    }
}

bool8 Thunderstorm_Finish(void)
{
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        gWeatherPtr->thunderAllowEnd = FALSE;
        gWeatherPtr->finishStep++;
        // fall through
    case 1:
        Thunderstorm_Main();
        if (gWeatherPtr->thunderAllowEnd)
        {
            if (gWeatherPtr->nextWeather == WEATHER_RAIN
             || gWeatherPtr->nextWeather == WEATHER_RAIN_THUNDERSTORM
             || gWeatherPtr->nextWeather == WEATHER_DOWNPOUR)
                return FALSE;

            gWeatherPtr->targetRainSpriteCount = 0;
            gWeatherPtr->finishStep++;
        }
        break;
    case 2:
        if (!UpdateVisibleRainSprites())
        {
            DestroyRainSprites();
            gWeatherPtr->thunderEnqueued = FALSE;
            gWeatherPtr->finishStep++;
            return FALSE;
        }
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

void EnqueueThunder(u16 waitFrames)
{
    if (!gWeatherPtr->thunderEnqueued)
    {
        gWeatherPtr->thunderSETimer = Random() % waitFrames;
        gWeatherPtr->thunderEnqueued = TRUE;
    }
}

void UpdateThunderSound(void)
{
    if (gWeatherPtr->thunderEnqueued == TRUE)
    {
        if (gWeatherPtr->thunderSETimer == 0)
        {
            if (IsSEPlaying())
                return;

            if (Random() & 1)
                PlaySE(SE_THUNDER);
            else
                PlaySE(SE_THUNDER2);

            gWeatherPtr->thunderEnqueued = FALSE;
        }
        else
        {
            gWeatherPtr->thunderSETimer--;
        }
    }
}

void FogHorizontal_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->targetColorMapIndex = 0;
    gWeatherPtr->colorMapStepDelay = 20;
    if (gWeatherPtr->fogHSpritesCreated == 0)
    {
        gWeatherPtr->fogHScrollCounter = 0;
        gWeatherPtr->fogHScrollOffset = 0;
        gWeatherPtr->fogHScrollPosX = 0;
        Weather_SetBlendCoeffs(0, 16);
    }
}

void FogHorizontal_InitAll(void)
{
    FogHorizontal_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        FogHorizontal_Main();
}

void FogHorizontal_Main(void)
{
    gWeatherPtr->fogHScrollPosX = (gSpriteCoordOffsetX - gWeatherPtr->fogHScrollOffset) & 0xFF;
    if (++gWeatherPtr->fogHScrollCounter > 3)
    {
        gWeatherPtr->fogHScrollCounter = 0;
        gWeatherPtr->fogHScrollOffset++;
    }
    switch (gWeatherPtr->initStep)
    {
    case 0:
        CreateFogHorizontalSprites();
        if (gWeatherPtr->currWeather == WEATHER_FOG_HORIZONTAL)
            Weather_SetTargetBlendCoeffs(12, 8, 3);
        else
            Weather_SetTargetBlendCoeffs(4, 16, 0);
        gWeatherPtr->initStep++;
        break;
    case 1:
        if (Weather_UpdateBlend())
        {
            gWeatherPtr->weatherGfxLoaded = TRUE;
            gWeatherPtr->initStep++;
        }
        break;
    }
}

bool8 FogHorizontal_Finish(void)
{
    gWeatherPtr->fogHScrollPosX = (gSpriteCoordOffsetX - gWeatherPtr->fogHScrollOffset) & 0xFF;
    if (++gWeatherPtr->fogHScrollCounter > 3)
    {
        gWeatherPtr->fogHScrollCounter = 0;
        gWeatherPtr->fogHScrollOffset++;
    }

    switch (gWeatherPtr->finishStep)
    {
    case 0:
        Weather_SetTargetBlendCoeffs(0, 16, 3);
        gWeatherPtr->finishStep++;
        break;
    case 1:
        if (Weather_UpdateBlend())
            gWeatherPtr->finishStep++;
        break;
    case 2:
        DestroyFogHorizontalSprites();
        gWeatherPtr->finishStep++;
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

void FogHorizontalSpriteCallback(struct Sprite *sprite)
{
    sprite->y2 = (u8)gSpriteCoordOffsetY;
    sprite->x = gWeatherPtr->fogHScrollPosX + 32 + sprite->data[0] * 64;
    if (sprite->x >= DISPLAY_WIDTH + 32)
    {
        sprite->x = (DISPLAY_WIDTH * 2) + gWeatherPtr->fogHScrollPosX - (4 - sprite->data[0]) * 64;
        sprite->x &= 0x1FF;
    }
}

void CreateFogHorizontalSprites(void)
{
    u16 i;
    u8 spriteId;
    struct Sprite *sprite;

    if (!gWeatherPtr->fogHSpritesCreated)
    {
        struct SpriteSheet fogHorizontalSpriteSheet = sFogHorizontalSpriteSheet;
        LoadSpriteSheet(&fogHorizontalSpriteSheet);
        for (i = 0; i < NUM_FOG_HORIZONTAL_SPRITES; i++)
        {
            spriteId = CreateSpriteAtEnd(&sFogHorizontalSpriteTemplate, 0, 0, 0xFF);
            if (spriteId != MAX_SPRITES)
            {
                sprite = &gSprites[spriteId];
                sprite->data[0] = i % 5;
                sprite->x = (i % 5) * 64 + 32;
                sprite->y = (i / 5) * 64 + 32;
                gWeatherPtr->sprites.s2.fogHSprites[i] = sprite;
            }
            else
            {
                gWeatherPtr->sprites.s2.fogHSprites[i] = NULL;
            }
        }

        gWeatherPtr->fogHSpritesCreated = TRUE;
    }
}

void DestroyFogHorizontalSprites(void)
{
    u16 i;

    if (gWeatherPtr->fogHSpritesCreated)
    {
        for (i = 0; i < NUM_FOG_HORIZONTAL_SPRITES; i++)
        {
            if (gWeatherPtr->sprites.s2.fogHSprites[i] != NULL)
                DestroySprite(gWeatherPtr->sprites.s2.fogHSprites[i]);
        }

        FreeSpriteTilesByTag(GFXTAG_FOG_H);
        gWeatherPtr->fogHSpritesCreated = 0;
    }
}

void Ash_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = FALSE;
    gWeatherPtr->targetColorMapIndex = 0;
    gWeatherPtr->colorMapStepDelay = 20;
    gWeatherPtr->ashUnused = 20; // Never read
    if (!gWeatherPtr->ashSpritesCreated)
    {
        Weather_SetBlendCoeffs(0, 16);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(64, 63)); // These aren't valid blend coefficients!
    }
}

void Ash_InitAll(void)
{
    Ash_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        Ash_Main();
}

void Ash_Main(void)
{
    gWeatherPtr->ashBaseSpritesX = gSpriteCoordOffsetX & 0x1FF;
    while (gWeatherPtr->ashBaseSpritesX >= DISPLAY_WIDTH)
        gWeatherPtr->ashBaseSpritesX -= DISPLAY_WIDTH;

    switch (gWeatherPtr->initStep)
    {
    case 0:
        LoadAshSpriteSheet();
        gWeatherPtr->initStep++;
        break;
    case 1:
        if (!gWeatherPtr->ashSpritesCreated)
            CreateAshSprites();

        Weather_SetTargetBlendCoeffs(16, 0, 1);
        gWeatherPtr->initStep++;
        break;
    case 2:
        if (Weather_UpdateBlend())
        {
            gWeatherPtr->weatherGfxLoaded = TRUE;
            gWeatherPtr->initStep++;
        }
        break;
    default:
        Weather_UpdateBlend();
        break;
    }
}

bool8 Ash_Finish(void)
{
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        Weather_SetTargetBlendCoeffs(0, 16, 1);
        gWeatherPtr->finishStep++;
        break;
    case 1:
        if (Weather_UpdateBlend())
        {
            DestroyAshSprites();
            gWeatherPtr->finishStep++;
        }
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        gWeatherPtr->finishStep++;
        return FALSE;
    default:
        return FALSE;
    }
    return TRUE;
}

void LoadAshSpriteSheet(void)
{
    LoadSpriteSheet(&sAshSpriteSheet);
}

void CreateAshSprites(void)
{
    u8 i;
    u8 spriteId;
    struct Sprite *sprite;

    if (!gWeatherPtr->ashSpritesCreated)
    {
        for (i = 0; i < NUM_ASH_SPRITES; i++)
        {
            spriteId = CreateSpriteAtEnd(&sAshSpriteTemplate, 0, 0, 0x4E);
            if (spriteId != MAX_SPRITES)
            {
                sprite = &gSprites[spriteId];
                sprite->data[1] = 0;
                sprite->data[2] = (u8)(i % 5);
                sprite->data[3] = (u8)(i / 5);
                sprite->data[0] = sprite->data[3] * 64 + 32;
                gWeatherPtr->sprites.s2.ashSprites[i] = sprite;
            }
            else
            {
                gWeatherPtr->sprites.s2.ashSprites[i] = NULL;
            }
        }

        gWeatherPtr->ashSpritesCreated = TRUE;
    }
}

void DestroyAshSprites(void)
{
    u16 i;

    if (gWeatherPtr->ashSpritesCreated)
    {
        for (i = 0; i < NUM_ASH_SPRITES; i++)
        {
            if (gWeatherPtr->sprites.s2.ashSprites[i] != NULL)
                DestroySprite(gWeatherPtr->sprites.s2.ashSprites[i]);
        }

        FreeSpriteTilesByTag(GFXTAG_ASH);
        gWeatherPtr->ashSpritesCreated = FALSE;
    }
}

void UpdateAshSprite(struct Sprite *sprite)
{
    if (++sprite->data[1] > 5)
    {
        sprite->data[1] = 0;
        sprite->data[0]++;
    }

    sprite->y = gSpriteCoordOffsetY + sprite->data[0];
    sprite->x = gWeatherPtr->ashBaseSpritesX + 32 + sprite->data[2] * 64;
    if (sprite->x >= DISPLAY_WIDTH + 32)
    {
        sprite->x = gWeatherPtr->ashBaseSpritesX + (DISPLAY_WIDTH * 2) - (4 - sprite->data[2]) * 64;
        sprite->x &= 0x1FF;
    }
}

void FogDiagonal_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = 0;
    gWeatherPtr->targetColorMapIndex = 0;
    gWeatherPtr->colorMapStepDelay = 20;
    gWeatherPtr->fogHScrollCounter = 0;
    gWeatherPtr->fogHScrollOffset = 1;
    if (!gWeatherPtr->fogDSpritesCreated)
    {
        gWeatherPtr->fogDScrollXCounter = 0;
        gWeatherPtr->fogDScrollYCounter = 0;
        gWeatherPtr->fogDXOffset = 0;
        gWeatherPtr->fogDYOffset = 0;
        gWeatherPtr->fogDBaseSpritesX = 0;
        gWeatherPtr->fogDPosY = 0;
        Weather_SetBlendCoeffs(0, 16);
    }
}

void FogDiagonal_InitAll(void)
{
    FogDiagonal_InitVars();
    while (gWeatherPtr->weatherGfxLoaded == FALSE)
        FogDiagonal_Main();
}

void FogDiagonal_Main(void)
{
    UpdateFogDiagonalMovement();
    switch (gWeatherPtr->initStep)
    {
    case 0:
        CreateFogDiagonalSprites();
        gWeatherPtr->initStep++;
        break;
    case 1:
        Weather_SetTargetBlendCoeffs(12, 8, 8);
        gWeatherPtr->initStep++;
        break;
    case 2:
        if (!Weather_UpdateBlend())
            break;
        gWeatherPtr->weatherGfxLoaded = TRUE;
        gWeatherPtr->initStep++;
        break;
    }
}

bool8 FogDiagonal_Finish(void)
{
    UpdateFogDiagonalMovement();
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        Weather_SetTargetBlendCoeffs(0, 16, 1);
        gWeatherPtr->finishStep++;
        break;
    case 1:
        if (!Weather_UpdateBlend())
            break;
        gWeatherPtr->finishStep++;
        break;
    case 2:
        DestroyFogDiagonalSprites();
        gWeatherPtr->finishStep++;
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

void UpdateFogDiagonalMovement(void)
{
    if (++gWeatherPtr->fogDScrollXCounter > 2)
    {
        gWeatherPtr->fogDXOffset++;
        gWeatherPtr->fogDScrollXCounter = 0;
    }

    if (++gWeatherPtr->fogDScrollYCounter > 4)
    {
        gWeatherPtr->fogDYOffset++;
        gWeatherPtr->fogDScrollYCounter = 0;
    }

    gWeatherPtr->fogDBaseSpritesX = (gSpriteCoordOffsetX - gWeatherPtr->fogDXOffset) & 0xFF;
    gWeatherPtr->fogDPosY = gSpriteCoordOffsetY + gWeatherPtr->fogDYOffset;
}

void CreateFogDiagonalSprites(void)
{
    u16 i;
    struct SpriteSheet fogDiagonalSpriteSheet;
    u8 spriteId;
    struct Sprite *sprite;

    if (!gWeatherPtr->fogDSpritesCreated)
    {
        fogDiagonalSpriteSheet = sFogDiagonalSpriteSheet;
        LoadSpriteSheet(&fogDiagonalSpriteSheet);
        for (i = 0; i < NUM_FOG_DIAGONAL_SPRITES; i++)
        {
            spriteId = CreateSpriteAtEnd(&sFogDiagonalSpriteTemplate, 0, (i / 5) * 64, 0xFF);
            if (spriteId != MAX_SPRITES)
            {
                sprite = &gSprites[spriteId];
                sprite->data[0] = i % 5;
                sprite->data[1] = i / 5;
                gWeatherPtr->sprites.s2.fogDSprites[i] = sprite;
            }
            else
            {
                gWeatherPtr->sprites.s2.fogDSprites[i] = NULL;
            }
        }

        gWeatherPtr->fogDSpritesCreated = TRUE;
    }
}

void DestroyFogDiagonalSprites(void)
{
    u16 i;

    if (gWeatherPtr->fogDSpritesCreated)
    {
        for (i = 0; i < NUM_FOG_DIAGONAL_SPRITES; i++)
        {
            if (gWeatherPtr->sprites.s2.fogDSprites[i])
                DestroySprite(gWeatherPtr->sprites.s2.fogDSprites[i]);
        }

        FreeSpriteTilesByTag(GFXTAG_FOG_D);
        gWeatherPtr->fogDSpritesCreated = FALSE;
    }
}

void UpdateFogDiagonalSprite(struct Sprite *sprite)
{
    sprite->y2 = gWeatherPtr->fogDPosY;
    sprite->x = gWeatherPtr->fogDBaseSpritesX + 32 + sprite->data[0] * 64;
    if (sprite->x >= DISPLAY_WIDTH + 32)
    {
        sprite->x = gWeatherPtr->fogDBaseSpritesX + (DISPLAY_WIDTH * 2) - (4 - sprite->data[0]) * 64;
        sprite->x &= 0x1FF;
    }
}

void Sandstorm_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->weatherGfxLoaded = 0;
    gWeatherPtr->targetColorMapIndex = 0;
    gWeatherPtr->colorMapStepDelay = 20;
    if (!gWeatherPtr->sandstormSpritesCreated)
    {
        gWeatherPtr->sandstormXOffset = gWeatherPtr->sandstormYOffset = 0;
        gWeatherPtr->sandstormWaveIndex = 8;
        gWeatherPtr->sandstormWaveCounter = 0;
        // Dead code. How does the compiler not optimize this out?
        if (gWeatherPtr->sandstormWaveIndex >= 0x80 - 0x20)
            gWeatherPtr->sandstormWaveIndex = 0x80 - gWeatherPtr->sandstormWaveIndex;

        Weather_SetBlendCoeffs(0, 16);
    }
}

void Sandstorm_InitAll(void)
{
    Sandstorm_InitVars();
    while (!gWeatherPtr->weatherGfxLoaded)
        Sandstorm_Main();
}

void Sandstorm_Main(void)
{
    UpdateSandstormMovement();
    UpdateSandstormWaveIndex();
    if (gWeatherPtr->sandstormWaveIndex >= 0x80 - 0x20)
        gWeatherPtr->sandstormWaveIndex = 0x20;

    switch (gWeatherPtr->initStep)
    {
    case 0:
        CreateSandstormSprites();
        CreateSwirlSandstormSprites();
        gWeatherPtr->initStep++;
        break;
    case 1:
        Weather_SetTargetBlendCoeffs(16, 0, 0);
        gWeatherPtr->initStep++;
        break;
    case 2:
        if (Weather_UpdateBlend())
        {
            gWeatherPtr->weatherGfxLoaded = TRUE;
            gWeatherPtr->initStep++;
        }
        break;
    }
}

bool8 Sandstorm_Finish(void)
{
    UpdateSandstormMovement();
    UpdateSandstormWaveIndex();
    switch (gWeatherPtr->finishStep)
    {
    case 0:
        Weather_SetTargetBlendCoeffs(0, 16, 0);
        gWeatherPtr->finishStep++;
        break;
    case 1:
        if (Weather_UpdateBlend())
            gWeatherPtr->finishStep++;
        break;
    case 2:
        DestroySandstormSprites();
        gWeatherPtr->finishStep++;
        break;
    default:
        return FALSE;
    }

    return TRUE;
}

void UpdateSandstormWaveIndex(void)
{
    if (gWeatherPtr->sandstormWaveCounter++ > 4)
    {
        gWeatherPtr->sandstormWaveIndex++;
        gWeatherPtr->sandstormWaveCounter = 0;
    }
}

void UpdateSandstormMovement(void)
{
    gWeatherPtr->sandstormXOffset -= gSineTable[gWeatherPtr->sandstormWaveIndex] * 4;
    gWeatherPtr->sandstormYOffset -= gSineTable[gWeatherPtr->sandstormWaveIndex];
    gWeatherPtr->sandstormBaseSpritesX = (gSpriteCoordOffsetX + (gWeatherPtr->sandstormXOffset >> 8)) & 0xFF;
    gWeatherPtr->sandstormPosY = gSpriteCoordOffsetY + (gWeatherPtr->sandstormYOffset >> 8);
}

void DestroySandstormSprites(void)
{
    u16 i;

    if (gWeatherPtr->sandstormSpritesCreated)
    {
        for (i = 0; i < NUM_SANDSTORM_SPRITES; i++)
        {
            if (gWeatherPtr->sprites.s2.sandstormSprites1[i])
                DestroySprite(gWeatherPtr->sprites.s2.sandstormSprites1[i]);
        }

        gWeatherPtr->sandstormSpritesCreated = FALSE;
        FreeSpriteTilesByTag(GFXTAG_SANDSTORM);
    }

    if (gWeatherPtr->sandstormSwirlSpritesCreated)
    {
        for (i = 0; i < NUM_SWIRL_SANDSTORM_SPRITES; i++)
        {
            if (gWeatherPtr->sprites.s2.sandstormSprites2[i] != NULL)
                DestroySprite(gWeatherPtr->sprites.s2.sandstormSprites2[i]);
        }

        gWeatherPtr->sandstormSwirlSpritesCreated = FALSE;
    }
}

void CreateSandstormSprites(void)
{
    u16 i;
    u8 spriteId;

    if (!gWeatherPtr->sandstormSpritesCreated)
    {
        LoadSpriteSheet(&sSandstormSpriteSheet);
        LoadCustomWeatherSpritePalette(gSandstormWeatherPalette);
        for (i = 0; i < NUM_SANDSTORM_SPRITES; i++)
        {
            spriteId = CreateSpriteAtEnd(&sSandstormSpriteTemplate, 0, (i / 5) * 64, 1);
            if (spriteId != MAX_SPRITES)
            {
                gWeatherPtr->sprites.s2.sandstormSprites1[i] = &gSprites[spriteId];
                gWeatherPtr->sprites.s2.sandstormSprites1[i]->data[0] = i % 5;
                gWeatherPtr->sprites.s2.sandstormSprites1[i]->data[1] = i / 5;
            }
            else
            {
                gWeatherPtr->sprites.s2.sandstormSprites1[i] = NULL;
            }
        }

        gWeatherPtr->sandstormSpritesCreated = TRUE;
    }
}

void CreateSwirlSandstormSprites(void)
{
    u16 i;
    u8 spriteId;

    if (!gWeatherPtr->sandstormSwirlSpritesCreated)
    {
        for (i = 0; i < NUM_SWIRL_SANDSTORM_SPRITES; i++)
        {
            spriteId = CreateSpriteAtEnd(&sSandstormSpriteTemplate, i * 48 + 24, 208, 1);
            if (spriteId != MAX_SPRITES)
            {
                gWeatherPtr->sprites.s2.sandstormSprites2[i] = &gSprites[spriteId];
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->oam.size = ST_OAM_SIZE_2;
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->data[1] = i * 51;
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->data[0] = 8;
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->data[2] = 0;
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->data[4] = 0x6730; // unused value
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->data[3] = sSwirlEntranceDelays[i];
                StartSpriteAnim(gWeatherPtr->sprites.s2.sandstormSprites2[i], 1);
                CalcCenterToCornerVec(gWeatherPtr->sprites.s2.sandstormSprites2[i], SPRITE_SHAPE(32x32), SPRITE_SIZE(32x32), ST_OAM_AFFINE_OFF);
                gWeatherPtr->sprites.s2.sandstormSprites2[i]->callback = WaitSandSwirlSpriteEntrance;
            }
            else
            {
                gWeatherPtr->sprites.s2.sandstormSprites2[i] = NULL;
            }

            gWeatherPtr->sandstormSwirlSpritesCreated = TRUE;
        }
    }
}

void UpdateSandstormSprite(struct Sprite *sprite)
{
    sprite->y2 = gWeatherPtr->sandstormPosY;
    sprite->x = gWeatherPtr->sandstormBaseSpritesX + 32 + sprite->data[0] * 64;
    if (sprite->x >= DISPLAY_WIDTH + 32)
    {
        sprite->x = gWeatherPtr->sandstormBaseSpritesX + (DISPLAY_WIDTH * 2) - (4 - sprite->data[0]) * 64;
        sprite->x &= 0x1FF;
    }
}

void WaitSandSwirlSpriteEntrance(struct Sprite *sprite)
{
    if (--sprite->data[3] == -1)
        sprite->callback = UpdateSandstormSwirlSprite;
}

void UpdateSandstormSwirlSprite(struct Sprite *sprite)
{
    u32 x, y;

    if (--sprite->y < -48)
    {
        sprite->y = DISPLAY_HEIGHT + 48;
        sprite->data[0] = 4;
    }

    x = sprite->data[0] * gSineTable[sprite->data[1]];
    y = sprite->data[0] * gSineTable[sprite->data[1] + 0x40];
    sprite->x2 = x >> 8;
    sprite->y2 = y >> 8;
    sprite->data[1] = (sprite->data[1] + 10) & 0xFF;
    if (++sprite->data[2] > 8)
    {
        sprite->data[2] = 0;
        sprite->data[0]++;
    }
}

void Shade_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->targetColorMapIndex = 3;
    gWeatherPtr->colorMapStepDelay = 20;
}

void Shade_InitAll(void)
{
    Shade_InitVars();
}

void Shade_Main(void)
{
}

bool8 Shade_Finish(void)
{
    return FALSE;
}

void Bubbles_InitVars(void)
{
    FogHorizontal_InitVars();
    if (!gWeatherPtr->bubblesSpritesCreated)
    {
        LoadSpriteSheet(&sWeatherBubbleSpriteSheet);
        gWeatherPtr->bubblesDelayIndex = 0;
        gWeatherPtr->bubblesDelayCounter = sBubbleStartDelays[0];
        gWeatherPtr->bubblesCoordsIndex = 0;
        gWeatherPtr->bubblesSpriteCount = 0;
    }
}

void Bubbles_InitAll(void)
{
    Bubbles_InitVars();
    while (!gWeatherPtr->weatherGfxLoaded)
        Bubbles_Main();
}

void Bubbles_Main(void)
{
    FogHorizontal_Main();
    if (++gWeatherPtr->bubblesDelayCounter > sBubbleStartDelays[gWeatherPtr->bubblesDelayIndex])
    {
        gWeatherPtr->bubblesDelayCounter = 0;
        if (++gWeatherPtr->bubblesDelayIndex > ARRAY_COUNT(sBubbleStartDelays) - 1)
            gWeatherPtr->bubblesDelayIndex = 0;

        CreateBubbleSprite(gWeatherPtr->bubblesCoordsIndex);
        if (++gWeatherPtr->bubblesCoordsIndex > ARRAY_COUNT(sBubbleStartCoords) - 1)
            gWeatherPtr->bubblesCoordsIndex = 0;
    }
}

bool8 Bubbles_Finish(void)
{
    if (!FogHorizontal_Finish())
    {
        DestroyBubbleSprites();
        return FALSE;
    }

    return TRUE;
}

void CreateBubbleSprite(u16 coordsIndex)
{
    s16 x = sBubbleStartCoords[coordsIndex][0];
    s16 y = sBubbleStartCoords[coordsIndex][1] - gSpriteCoordOffsetY;
    u8 spriteId = CreateSpriteAtEnd(&sBubbleSpriteTemplate, x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].oam.priority = 1;
        gSprites[spriteId].coordOffsetEnabled = TRUE;
        gSprites[spriteId].data[0] = 0;
        gSprites[spriteId].data[1] = 0;
        gSprites[spriteId].data[2] = 0;
        gWeatherPtr->bubblesSpriteCount++;
    }
}

void DestroyBubbleSprites(void)
{
    u16 i;

    if (gWeatherPtr->bubblesSpriteCount)
    {
        for (i = 0; i < MAX_SPRITES; i++)
        {
            if (gSprites[i].template == &sBubbleSpriteTemplate)
                DestroySprite(&gSprites[i]);
        }

        FreeSpriteTilesByTag(GFXTAG_BUBBLE);
        gWeatherPtr->bubblesSpriteCount = 0;
    }
}

void UpdateBubbleSprite(struct Sprite *sprite)
{
    ++sprite->data[0];
    if (++sprite->data[0] > 8) // double increment
    {
        sprite->data[0] = 0;
        if (sprite->data[1] == 0)
        {
            if (++sprite->x2 > 4)
                sprite->data[1] = 1;
        }
        else
        {
            if (--sprite->x2 <= 0)
                sprite->data[1] = 0;
        }
    }

    sprite->y -= 3;
    if (++sprite->data[2] >= 120)
        DestroySprite(sprite);
}

void UnusedSetCurrentAbnormalWeather(u32 weather, u32 unknown)
{
    sCurrentAbnormalWeather = weather;
    sUnusedWeatherRelated = unknown;
}

void Task_DoAbnormalWeather(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        if (data[15]-- <= 0)
        {
            SetNextWeather(data[1]);
            sCurrentAbnormalWeather = data[1];
            data[15] = 600;
            data[0]++;
        }
        break;
    case 1:
        if (data[15]-- <= 0)
        {
            SetNextWeather(data[2]);
            sCurrentAbnormalWeather = data[2];
            data[15] = 600;
            data[0] = 0;
        }
        break;
    }
}

void CreateAbnormalWeatherTask(void)
{
    u8 taskId = CreateTask(Task_DoAbnormalWeather, 0);
    s16 *data = gTasks[taskId].data;

    data[15] = 600;
    if (sCurrentAbnormalWeather == WEATHER_DOWNPOUR)
    {
        // Currently Downpour, next will be Drought
        data[1] = WEATHER_DROUGHT;
        data[2] = WEATHER_DOWNPOUR;
    }
    else if (sCurrentAbnormalWeather == WEATHER_DROUGHT)
    {
        // Currently Drought, next will be Downpour
        data[1] = WEATHER_DOWNPOUR;
        data[2] = WEATHER_DROUGHT;
    }
    else
    {
        // Default to starting with Downpour
        sCurrentAbnormalWeather = WEATHER_DOWNPOUR;
        data[1] = WEATHER_DROUGHT;
        data[2] = WEATHER_DOWNPOUR;
    }
}

void SetSavedWeather(u32 weather)
{
    u8 oldWeather = gSaveBlock1Ptr->weather;
    gSaveBlock1Ptr->weather = TranslateWeatherNum(weather);
    UpdateRainCounter(gSaveBlock1Ptr->weather, oldWeather);
}

u8 GetSavedWeather(void)
{
    return gSaveBlock1Ptr->weather;
}

void SetSavedWeatherFromCurrMapHeader(void)
{
    u8 oldWeather = gSaveBlock1Ptr->weather;
    gSaveBlock1Ptr->weather = TranslateWeatherNum(gMapHeader.weather);
    UpdateRainCounter(gSaveBlock1Ptr->weather, oldWeather);
}

void SetWeather(u32 weather)
{
    SetSavedWeather(weather);
    SetNextWeather(GetSavedWeather());
}

void SetWeather_Unused(u32 weather)
{
    SetSavedWeather(weather);
    SetCurrentAndNextWeather(GetSavedWeather());
}

void DoCurrentWeather(void)
{
    u8 weather = GetSavedWeather();

    if (weather == WEATHER_ABNORMAL)
    {
        if (!FuncIsActiveTask(Task_DoAbnormalWeather))
            CreateAbnormalWeatherTask();
        weather = sCurrentAbnormalWeather;
    }
    else
    {
        if (FuncIsActiveTask(Task_DoAbnormalWeather))
            DestroyTask(FindTaskIdByFunc(Task_DoAbnormalWeather));
        sCurrentAbnormalWeather = WEATHER_DOWNPOUR;
    }
    SetNextWeather(weather);
}

void ResumePausedWeather(void)
{
    u8 weather = GetSavedWeather();

    if (weather == WEATHER_ABNORMAL)
    {
        if (!FuncIsActiveTask(Task_DoAbnormalWeather))
            CreateAbnormalWeatherTask();
        weather = sCurrentAbnormalWeather;
    }
    else
    {
        if (FuncIsActiveTask(Task_DoAbnormalWeather))
            DestroyTask(FindTaskIdByFunc(Task_DoAbnormalWeather));
        sCurrentAbnormalWeather = WEATHER_DOWNPOUR;
    }
    SetCurrentAndNextWeather(weather);
}

u8 TranslateWeatherNum(u8 weather)
{
    switch (weather)
    {
    case WEATHER_NONE:               return WEATHER_NONE;
    case WEATHER_SUNNY_CLOUDS:       return WEATHER_SUNNY_CLOUDS;
    case WEATHER_SUNNY:              return WEATHER_SUNNY;
    case WEATHER_RAIN:               return WEATHER_RAIN;
    case WEATHER_SNOW:               return WEATHER_SNOW;
    case WEATHER_RAIN_THUNDERSTORM:  return WEATHER_RAIN_THUNDERSTORM;
    case WEATHER_FOG_HORIZONTAL:     return WEATHER_FOG_HORIZONTAL;
    case WEATHER_VOLCANIC_ASH:       return WEATHER_VOLCANIC_ASH;
    case WEATHER_SANDSTORM:          return WEATHER_SANDSTORM;
    case WEATHER_FOG_DIAGONAL:       return WEATHER_FOG_DIAGONAL;
    case WEATHER_UNDERWATER:         return WEATHER_UNDERWATER;
    case WEATHER_SHADE:              return WEATHER_SHADE;
    case WEATHER_DROUGHT:            return WEATHER_DROUGHT;
    case WEATHER_DOWNPOUR:           return WEATHER_DOWNPOUR;
    case WEATHER_UNDERWATER_BUBBLES: return WEATHER_UNDERWATER_BUBBLES;
    case WEATHER_ABNORMAL:           return WEATHER_ABNORMAL;
    case WEATHER_ROUTE119_CYCLE:     return sWeatherCycleRoute119[gSaveBlock1Ptr->weatherCycleStage];
    case WEATHER_ROUTE123_CYCLE:     return sWeatherCycleRoute123[gSaveBlock1Ptr->weatherCycleStage];
    default:                         return WEATHER_NONE;
    }
}

void UpdateWeatherPerDay(u16 increment)
{
    u16 weatherStage = gSaveBlock1Ptr->weatherCycleStage + increment;
    weatherStage %= 4;
    gSaveBlock1Ptr->weatherCycleStage = weatherStage;
}

void UpdateRainCounter(u8 newWeather, u8 oldWeather)
{
    if (newWeather != oldWeather
     && (newWeather == WEATHER_RAIN || newWeather == WEATHER_RAIN_THUNDERSTORM))
        IncrementGameStat(GAME_STAT_GOT_RAINED_ON);
}
