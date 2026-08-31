#include "global.h"
#include "gba/m4a_internal.h"
#include "gpu_regs.h"
#include "main.h"
#include "multiboot.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "task.h"

extern void LoadBerryFixGraphics(u32 idx);
extern const u8 gMultiBootProgram_BerryGlitchFix_Start[];
extern const u8 gMultiBootProgram_BerryGlitchFix_End[];
extern s16 gUnknown_3005B68[];
extern const u8 *gUnknown_3006070;
extern s32 gUnknown_3006074;
extern u32 gUnknown_3006078;
extern struct MultiBootParam gUnknown_3006080;

void berry_fix_main(u8 taskId);
void berry_fix_text_print(void);

// JP byte-exact berry glitch fix multiboot program.

void berry_fix_bg_hide(void)
{
    volatile u32 zero;
    vu32 *dma;
    u8 taskId;

    DisableInterrupts(0xFFFF);
    EnableInterrupts(1);
    m4aSoundVSyncOff();
    SetVBlankCallback(NULL);

    zero = 0;
    dma = (vu32 *)REG_ADDR_DMA3SAD;
    dma[0] = (u32)&zero;
    dma[1] = VRAM;
    dma[2] = 0x85006000;
    (void)dma[2];

    zero = 0;
    dma[0] = (u32)&zero;
    dma[1] = PLTT;
    dma[2] = 0x85000100;
    (void)dma[2];

    ResetSpriteData();
    ResetTasks();
    ScanlineEffect_Stop();

    taskId = CreateTask(berry_fix_main, 0);
    gTasks[taskId].data[0] = 0;
    SetMainCallback2(berry_fix_text_print);
}

void berry_fix_text_print(void)
{
    RunTasks();
}

void berry_fix_main(u8 taskId)
{
    s16 *data = gUnknown_3005B68 + taskId * 20;

    switch (data[0])
    {
    case 0:
        LoadBerryFixGraphics(5);
        data[0] = 1;
        break;
    case 1:
        if (gMain.newKeys & A_BUTTON)
        {
            LoadBerryFixGraphics(0);
            data[0] = 2;
        }
        break;
    case 2:
        if (gMain.newKeys & A_BUTTON)
        {
            LoadBerryFixGraphics(1);
            data[0] = 4;
        }
        break;
    case 4:
        gUnknown_3006070 = gMultiBootProgram_BerryGlitchFix_Start;
        gUnknown_3006078 = gMultiBootProgram_BerryGlitchFix_End - gMultiBootProgram_BerryGlitchFix_Start;
        gUnknown_3006080.masterp = gMultiBootProgram_BerryGlitchFix_Start;
        gUnknown_3006080.server_type = 0;
        MultiBootInit(&gUnknown_3006080);
        data[1] = 0;
        data[0] = 5;
        break;
    case 5:
    {
        u8 probeCount = gUnknown_3006080.probe_count;
        struct MultiBootParam *multiBoot = &gUnknown_3006080;

        if (probeCount == 0
         && (multiBoot->response_bit & 2)
         && (multiBoot->client_bit & 2))
        {
            if (++data[1] > 180)
            {
                LoadBerryFixGraphics(2);
                MultiBootStartMaster(multiBoot,
                                     gUnknown_3006070 + MULTIBOOT_HEADER_SIZE,
                                     gUnknown_3006078 - MULTIBOOT_HEADER_SIZE,
                                     4,
                                     1);
                data[1] = probeCount;
                data[0] = 6;
                break;
            }
        }
        else
        {
            data[1] = 0;
        }

        gUnknown_3006074 = MultiBootMain(multiBoot);
        break;
    }
    case 6:
        gUnknown_3006074 = MultiBootMain(&gUnknown_3006080);
        if (MultiBootCheckComplete(&gUnknown_3006080))
        {
            LoadBerryFixGraphics(3);
            data[0] = 7;
        }
        else if (!(gUnknown_3006080.client_bit & 2))
        {
            data[0] = 9;
        }
        break;
    case 7:
        data[0] = 8;
        break;
    case 8:
        if (gMain.newKeys & A_BUTTON)
        {
            DestroyTask(taskId);
            DoSoftReset();
        }
        break;
    case 9:
        LoadBerryFixGraphics(4);
        data[0] = 10;
        break;
    case 10:
        if (gMain.newKeys & A_BUTTON)
            data[0] = 0;
        break;
    }
}
