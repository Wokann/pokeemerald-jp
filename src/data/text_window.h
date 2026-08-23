// Text-window resources, compiled by graphics.c to preserve the exact code
// generation of text_window.c while keeping this data in its own source unit.

TEXT_WINDOW_PALETTES const u16 sTextWindowPalettes[][16] =
{
    {
        0x532E, 0x7FFF, 0x318C, 0x675A, 0x043C, 0x3AFF, 0x0664, 0x4BD2,
        0x6546, 0x7B14, 0x7FFF, 0x73BC, 0x7FFF, 0x4FE0, 0x5F20, 0x51C9,
    },
    {
        0x532E, 0x7FFF, 0x318C, 0x675A, 0x043C, 0x3AFF, 0x0664, 0x4BD2,
        0x6546, 0x7B14, 0x7FFF, 0x6F39, 0x6F39, 0x7FDC, 0x6F39, 0x3DCD,
    },
    {
        0x532E, 0x7FFF, 0x318C, 0x675A, 0x043C, 0x3AFF, 0x0664, 0x4BD2,
        0x6546, 0x7B14, 0x7FFF, 0x7729, 0x7686, 0x4160, 0x6183, 0x71C2,
    },
    {
        0x532E, 0x7FFF, 0x318C, 0x675A, 0x043C, 0x3AFF, 0x0664, 0x4BD2,
        0x6546, 0x7B14, 0x7C1F, 0x6B59, 0x6F33, 0x3DCC, 0x72A8, 0x5A90,
    },
    {
        0x532E, 0x7FFF, 0x318C, 0x675A, 0x043C, 0x3AFF, 0x0664, 0x4BD2,
        0x6546, 0x7B14, 0x3987, 0x4210, 0x5294, 0x6718, 0x779C, 0x3568,
    },
};

TEXT_WINDOW_FRAME_TABLE const struct TilesPal sWindowFrames[WINDOW_FRAMES_COUNT] =
{
    {gTextWindowFrame1_Gfx + 0x000, gTextWindowFrame1_Pal + 0x00},
    {gTextWindowFrame1_Gfx + 0x120, gTextWindowFrame1_Pal + 0x10},
    {gTextWindowFrame1_Gfx + 0x240, gTextWindowFrame1_Pal + 0x20},
    {gTextWindowFrame1_Gfx + 0x360, gTextWindowFrame1_Pal + 0x30},
    {gTextWindowFrame1_Gfx + 0x480, gTextWindowFrame1_Pal + 0x40},
    {gTextWindowFrame1_Gfx + 0x5A0, gTextWindowFrame1_Pal + 0x50},
    {gTextWindowFrame1_Gfx + 0x6C0, gTextWindowFrame1_Pal + 0x60},
    {gTextWindowFrame1_Gfx + 0x7E0, gTextWindowFrame1_Pal + 0x70},
    {gTextWindowFrame1_Gfx + 0x900, gTextWindowFrame1_Pal + 0x80},
    {gTextWindowFrame1_Gfx + 0xA20, gTextWindowFrame1_Pal + 0x90},
    {gTextWindowFrame1_Gfx + 0xB40, gTextWindowFrame1_Pal + 0xA0},
    {gTextWindowFrame1_Gfx + 0xC60, gTextWindowFrame1_Pal + 0xB0},
    {gTextWindowFrame1_Gfx + 0xD80, gTextWindowFrame1_Pal + 0xC0},
    {gTextWindowFrame1_Gfx + 0xEA0, gTextWindowFrame1_Pal + 0xD0},
    {gTextWindowFrame1_Gfx + 0xFC0, gTextWindowFrame1_Pal + 0xE0},
    {gTextWindowFrame1_Gfx + 0x10E0, gTextWindowFrame1_Pal + 0xF0},
    {gTextWindowFrame1_Gfx + 0x1200, gTextWindowFrame1_Pal + 0x100},
    {gTextWindowFrame1_Gfx + 0x1320, gTextWindowFrame1_Pal + 0x110},
    {gTextWindowFrame1_Gfx + 0x1440, gTextWindowFrame1_Pal + 0x120},
    {gTextWindowFrame1_Gfx + 0x1560, gTextWindowFrame1_Pal + 0x130},
};
