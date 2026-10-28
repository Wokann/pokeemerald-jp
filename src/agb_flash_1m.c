#include "gba/gba.h"
#include "gba/flash_internal.h"

static const struct FlashSetupInfo *const sSetupInfos[] __attribute__((section(".rodata.agb_flash_setup_infos"))) =
{
    &MX29L010,
    &LE26FV10N1TS,
    &DefaultFlash
};

// Retained JP copies of library state pointers; no runtime references.
static const void *const sUnusedIdentifyFlashPointers[] __attribute__((section(".rodata.agb_flash_setup_pointer_copies"))) =
{
    (const void *)sSetupInfos,
    (const void *)&ProgramFlashByte,
    (const void *)&ProgramFlashSector,
    (const void *)&EraseFlashChip,
    (const void *)&EraseFlashSector,
    (const void *)&WaitForFlashWrite,
    (const void *)&gFlashMaxTime,
    (const void *)&gFlash,
    (const void *)&PollFlashStatus,
    (const void *)&gFlashTimeoutFlag,
};

u16 IdentifyFlash(void)
{
    u16 result;
    u16 flashId;
    const struct FlashSetupInfo *const *setupInfo;

    REG_WAITCNT = (REG_WAITCNT & ~WAITCNT_SRAM_MASK) | WAITCNT_SRAM_8;

    flashId = ReadFlashId();

    setupInfo = sSetupInfos;
    result = 1;

    for (;;)
    {
        if ((*setupInfo)->type.ids.separate.makerId == 0)
            break;

        if (flashId == (*setupInfo)->type.ids.joined)
        {
            result = 0;
            break;
        }

        setupInfo++;
    }

    ProgramFlashByte = (*setupInfo)->programFlashByte;
    ProgramFlashSector = (*setupInfo)->programFlashSector;
    EraseFlashChip = (*setupInfo)->eraseFlashChip;
    EraseFlashSector = (*setupInfo)->eraseFlashSector;
    WaitForFlashWrite = (*setupInfo)->WaitForFlashWrite;
    gFlashMaxTime = (*setupInfo)->maxTime;
    gFlash = &(*setupInfo)->type;

    return result;
}

u16 WaitForFlashWrite_Common(u8 phase, u8 *addr, u8 lastData)
{
    u16 result = 0;
    u8 status;

    StartFlashTimer(phase);

    while ((status = PollFlashStatus(addr)) != lastData)
    {
        if (status & 0x20)
        {
            // The write operation exceeded the flash chip's time limit.

            if (PollFlashStatus(addr) == lastData)
                break;

            FLASH_WRITE(0x5555, 0xF0);
            result = phase | 0xA000u;
            break;
        }

        if (gFlashTimeoutFlag)
        {
            if (PollFlashStatus(addr) == lastData)
                break;

            FLASH_WRITE(0x5555, 0xF0);
            result = phase | 0xC000u;
            break;
        }
    }

    StopFlashTimer();

    return result;
}
