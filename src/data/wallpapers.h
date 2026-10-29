enum {
    WALLPAPER_FOREST,
    WALLPAPER_CITY,
    WALLPAPER_DESERT,
    WALLPAPER_SAVANNA,
    WALLPAPER_CRAG,
    WALLPAPER_VOLCANO,
    WALLPAPER_SNOW,
    WALLPAPER_CAVE,
    WALLPAPER_BEACH,
    WALLPAPER_SEAFLOOR,
    WALLPAPER_RIVER,
    WALLPAPER_SKY,
    WALLPAPER_POLKADOT,
    WALLPAPER_POKECENTER,
    WALLPAPER_MACHINE,
    WALLPAPER_PLAIN,
    WALLPAPER_FRIENDS, // The one received as a gift from Walda's parents.
    WALLPAPER_COUNT
};
#define MAX_DEFAULT_WALLPAPER WALLPAPER_SAVANNA

static const u16 sWallpaperPalettes_Forest[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/forest/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/forest/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Forest[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/forest/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Forest[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/forest/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_City[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/city/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/city/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_City[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/city/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_City[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/city/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Desert[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/desert/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/desert/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Desert[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/desert/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Desert[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/desert/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Savanna[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/savanna/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/savanna/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Savanna[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/savanna/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Savanna[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/savanna/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Crag[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/crag/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/crag/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Crag[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/crag/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Crag[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/crag/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Volcano[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/volcano/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/volcano/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Volcano[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/volcano/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Volcano[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/volcano/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Snow[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/snow/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/snow/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Snow[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/snow/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Snow[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/snow/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Cave[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/cave/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/cave/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Cave[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/cave/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Cave[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/cave/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Beach[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/beach/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/beach/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Beach[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/beach/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Beach[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/beach/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Seafloor[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/seafloor/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/seafloor/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Seafloor[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/seafloor/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Seafloor[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/seafloor/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_River[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/river/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/river/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_River[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/river/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_River[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/river/tilemap.bin", ".lz");
static const u16 sWallpaperPalettes_Sky[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/sky/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/sky/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Sky[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/sky/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Sky[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/sky/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_PolkaDot[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/polkadot/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/polkadot/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_PolkaDot[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/polkadot/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_PolkaDot[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/polkadot/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Pokecenter[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/pokecenter/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/pokecenter/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Pokecenter[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/pokecenter/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Pokecenter[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/pokecenter/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Machine[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/machine/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/machine/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Machine[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/machine/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Machine[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/machine/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Plain[][16] DEFAULT_WALLPAPER_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/plain/frame.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/plain/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Plain[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/plain/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Plain[] DEFAULT_WALLPAPER_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/plain/tilemap.bin", ".lz");

// 12x18 tilemap
static const u32 sWallpaperTilemap_Unused[] DEFAULT_WALLPAPER_DATA = INCBIN_U32("graphics/pokemon_storage/wallpapers/unused.bin");

// Shadow color, text color
static const u16 sBoxTitleColors[WALLPAPER_COUNT][2] DEFAULT_WALLPAPER_DATA =
{
    [WALLPAPER_FOREST]     = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_CITY]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_DESERT]     = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SAVANNA]    = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_CRAG]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_VOLCANO]    = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SNOW]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_CAVE]       = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_BEACH]      = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SEAFLOOR]   = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_RIVER]      = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_SKY]        = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_POLKADOT]   = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_POKECENTER] = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_MACHINE]    = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_PLAIN]      = {RGB(7, 7, 7), RGB_WHITE},
    [WALLPAPER_FRIENDS]    = {RGB(7, 7, 7), RGB_WHITE}
};

#define WALLPAPER_ENTRY(name) {sWallpaperTiles_##name, sWallpaperTilemap_##name, sWallpaperPalettes_##name[0]}
// A few wallpapers are not defined in this file
#define WALLPAPER_ENTRY_G(name) {gWallpaperTiles_##name, gWallpaperTilemap_##name, gWallpaperPalettes_##name[0]}

static const struct Wallpaper sWallpapers[WALLPAPER_COUNT - 1] DEFAULT_WALLPAPER_DATA =
{
    [WALLPAPER_FOREST]     = WALLPAPER_ENTRY(Forest),
    [WALLPAPER_CITY]       = WALLPAPER_ENTRY(City),
    [WALLPAPER_DESERT]     = WALLPAPER_ENTRY(Desert),
    [WALLPAPER_SAVANNA]    = WALLPAPER_ENTRY(Savanna),
    [WALLPAPER_CRAG]       = WALLPAPER_ENTRY(Crag),
    [WALLPAPER_VOLCANO]    = WALLPAPER_ENTRY(Volcano),
    [WALLPAPER_SNOW]       = WALLPAPER_ENTRY(Snow),
    [WALLPAPER_CAVE]       = WALLPAPER_ENTRY(Cave),
    [WALLPAPER_BEACH]      = WALLPAPER_ENTRY(Beach),
    [WALLPAPER_SEAFLOOR]   = WALLPAPER_ENTRY(Seafloor),
    [WALLPAPER_RIVER]      = WALLPAPER_ENTRY(River),
    [WALLPAPER_SKY]        = WALLPAPER_ENTRY(Sky),
    [WALLPAPER_POLKADOT]   = WALLPAPER_ENTRY(PolkaDot),
    [WALLPAPER_POKECENTER] = WALLPAPER_ENTRY(Pokecenter),
    [WALLPAPER_MACHINE]    = WALLPAPER_ENTRY(Machine),
    [WALLPAPER_PLAIN]      = WALLPAPER_ENTRY(Plain),
};

static const u8 sArrow_Gfx[] DEFAULT_WALLPAPER_DATA = INCGFX_U8("graphics/pokemon_storage/arrow.png", ".4bpp");

static const u16 sWallpaperPalettes_Zigzagoon[][16] WALDA_ZIGZAGOON_SCREEN_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/friends_frame1.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/zigzagoon/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Zigzagoon[] WALDA_ZIGZAGOON_SCREEN_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/zigzagoon/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Zigzagoon[] WALDA_ZIGZAGOON_SCREEN_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/zigzagoon/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Screen[][16] WALDA_ZIGZAGOON_SCREEN_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/friends_frame1.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/screen/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Screen[] WALDA_ZIGZAGOON_SCREEN_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/screen/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Screen[] WALDA_ZIGZAGOON_SCREEN_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/screen/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Diagonal[][16] WALDA_DIAGONAL_BLOCK_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/friends_frame1.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/diagonal/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Diagonal[] WALDA_DIAGONAL_BLOCK_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/diagonal/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Diagonal[] WALDA_DIAGONAL_BLOCK_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/diagonal/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Block[][16] WALDA_DIAGONAL_BLOCK_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/block/bg.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/block/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Block[] WALDA_DIAGONAL_BLOCK_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/block/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Block[] WALDA_DIAGONAL_BLOCK_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/block/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Pokecenter2[][16] WALDA_BACKGROUND_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/pokecenter2/bg.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/pokecenter2/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Pokecenter2[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/pokecenter2/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Pokecenter2[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/pokecenter2/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Frame[][16] WALDA_BACKGROUND_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/frame/bg.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/frame/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Frame[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/frame/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Frame[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/frame/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Blank[][16] WALDA_BACKGROUND_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/friends_frame1.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/zigzagoon/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Blank[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/blank/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Blank[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/blank/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Circles[][16] WALDA_BACKGROUND_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/friends_frame2.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/circles/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Circles[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/circles/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Circles[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/circles/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Azumarill[][16] WALDA_BACKGROUND_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/friends_frame2.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/azumarill/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Azumarill[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/azumarill/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Azumarill[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/azumarill/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Pikachu[][16] WALDA_BACKGROUND_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/friends_frame2.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/pikachu/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Pikachu[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/pikachu/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Pikachu[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/pikachu/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Legendary[][16] WALDA_BACKGROUND_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/friends_frame2.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/legendary/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Legendary[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/legendary/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Legendary[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/legendary/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Dusclops[][16] WALDA_BACKGROUND_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/friends_frame2.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/dusclops/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Dusclops[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/dusclops/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Dusclops[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/dusclops/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Ludicolo[][16] WALDA_BACKGROUND_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/friends_frame2.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/ludicolo/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Ludicolo[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/ludicolo/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Ludicolo[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/ludicolo/tilemap.bin", ".lz");

static const u16 sWallpaperPalettes_Whiscash[][16] WALDA_BACKGROUND_DATA =
{
    INCGFX_U16("graphics/pokemon_storage/wallpapers/friends_frame2.png", ".gbapal"),
    INCGFX_U16("graphics/pokemon_storage/wallpapers/whiscash/bg.png", ".gbapal"),
};
static const u32 sWallpaperTiles_Whiscash[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/whiscash/tiles.4bpp", ".lz");
static const u32 sWallpaperTilemap_Whiscash[] WALDA_BACKGROUND_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/whiscash/tilemap.bin", ".lz");

static const u32 sWallpaperIcon_Aqua[] WALDA_ICONS_AQUA_DOT_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/aqua.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Heart[] WALDA_ICONS_AQUA_DOT_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/heart.png", ".4bpp.lz");
static const u32 sWallpaperIcon_FiveStar[] WALDA_ICONS_AQUA_DOT_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/five_star.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Brick[] WALDA_ICONS_AQUA_DOT_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/brick.png", ".4bpp.lz");
static const u32 sWallpaperIcon_FourStar[] WALDA_ICONS_AQUA_DOT_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/four_star.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Asterisk[] WALDA_ICONS_AQUA_DOT_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/asterisk.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Dot[] WALDA_ICONS_AQUA_DOT_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/dot.png", ".4bpp.lz");
static const u32 sWallpaperIcon_LineCircle[] WALDA_ICONS_LINE_CIRCLE_RIBBON_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/line_circle.png", ".4bpp.lz");
static const u32 sWallpaperIcon_PokeBall[] WALDA_ICONS_LINE_CIRCLE_RIBBON_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/pokeball.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Maze[] WALDA_ICONS_LINE_CIRCLE_RIBBON_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/maze.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Footprint[] WALDA_ICONS_LINE_CIRCLE_RIBBON_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/footprint.png", ".4bpp.lz");
static const u32 sWallpaperIcon_BigAsterisk[] WALDA_ICONS_LINE_CIRCLE_RIBBON_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/big_asterisk.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Circle[] WALDA_ICONS_LINE_CIRCLE_RIBBON_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/circle.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Koffing[] WALDA_ICONS_LINE_CIRCLE_RIBBON_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/koffing.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Ribbon[] WALDA_ICONS_LINE_CIRCLE_RIBBON_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/ribbon.png", ".4bpp.lz");
static const u32 sWallpaperIcon_FourCircles[] WALDA_ICONS_FOUR_CIRCLES_LATIS_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/four_circles.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Lotad[] WALDA_ICONS_FOUR_CIRCLES_LATIS_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/lotad.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Crystal[] WALDA_ICONS_FOUR_CIRCLES_LATIS_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/crystal.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Pichu[] WALDA_ICONS_FOUR_CIRCLES_LATIS_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/pichu.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Diglett[] WALDA_ICONS_FOUR_CIRCLES_LATIS_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/diglett.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Luvdisc[] WALDA_ICONS_FOUR_CIRCLES_LATIS_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/luvdisc.png", ".4bpp.lz");
static const u32 sWallpaperIcon_StarInCircle[] WALDA_ICONS_FOUR_CIRCLES_LATIS_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/star_in_circle.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Spinda[] WALDA_ICONS_FOUR_CIRCLES_LATIS_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/spinda.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Latis[] WALDA_ICONS_FOUR_CIRCLES_LATIS_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/latis.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Minun[] WALDA_ICONS_MINUN_MAGMA_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/minun.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Togepi[] WALDA_ICONS_MINUN_MAGMA_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/togepi.png", ".4bpp.lz");
static const u32 sWallpaperIcon_Magma[] WALDA_ICONS_MINUN_MAGMA_DATA = INCGFX_U32("graphics/pokemon_storage/wallpapers/icons/magma.png", ".4bpp.lz");

static const struct Wallpaper sWaldaWallpapers[] WALDA_WALLPAPER_TABLES_DATA =
{
    WALLPAPER_ENTRY(Zigzagoon),
    WALLPAPER_ENTRY(Screen),
    WALLPAPER_ENTRY_G(Horizontal),
    WALLPAPER_ENTRY(Diagonal),
    WALLPAPER_ENTRY(Block),
    WALLPAPER_ENTRY_G(Ribbon),
    WALLPAPER_ENTRY(Pokecenter2),
    WALLPAPER_ENTRY(Frame),
    WALLPAPER_ENTRY(Blank),
    WALLPAPER_ENTRY(Circles),
    WALLPAPER_ENTRY(Azumarill),
    WALLPAPER_ENTRY(Pikachu),
    WALLPAPER_ENTRY(Legendary),
    WALLPAPER_ENTRY(Dusclops),
    WALLPAPER_ENTRY(Ludicolo),
    WALLPAPER_ENTRY(Whiscash),
};

static const u32 *const sWaldaWallpaperIcons[] WALDA_WALLPAPER_TABLES_DATA =
{
    sWallpaperIcon_Aqua,
    sWallpaperIcon_Heart,
    sWallpaperIcon_FiveStar,
    sWallpaperIcon_Brick,
    sWallpaperIcon_FourStar,
    sWallpaperIcon_Asterisk,
    sWallpaperIcon_Dot,
    gWallpaperIcon_Cross,
    sWallpaperIcon_LineCircle,
    sWallpaperIcon_PokeBall,
    sWallpaperIcon_Maze,
    sWallpaperIcon_Footprint,
    sWallpaperIcon_BigAsterisk,
    sWallpaperIcon_Circle,
    sWallpaperIcon_Koffing,
    sWallpaperIcon_Ribbon,
    gWallpaperIcon_Bolt,
    sWallpaperIcon_FourCircles,
    sWallpaperIcon_Lotad,
    sWallpaperIcon_Crystal,
    sWallpaperIcon_Pichu,
    sWallpaperIcon_Diglett,
    sWallpaperIcon_Luvdisc,
    sWallpaperIcon_StarInCircle,
    sWallpaperIcon_Spinda,
    sWallpaperIcon_Latis,
    gWallpaperIcon_Plusle,
    sWallpaperIcon_Minun,
    sWallpaperIcon_Togepi,
    sWallpaperIcon_Magma,
};
