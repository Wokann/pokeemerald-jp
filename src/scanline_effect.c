#include "global.h"
#include "battle.h"
#include "data.h"
#include "task.h"
#include "trig.h"
#include "scanline_effect.h"

static void CopyValue16Bit(void);
static void CopyValue32Bit(void);

// This stop flag is owned by the JP EWRAM symbol layout.
extern bool8 gUnknown_20397E4;

void ScanlineEffect_Stop(void)
{
    gScanlineEffect.state = 0;
    DmaStop(0);
    if (gScanlineEffect.waveTaskId != TASK_NONE)
    {
        DestroyTask(gScanlineEffect.waveTaskId);
        gScanlineEffect.waveTaskId = TASK_NONE;
    }
}

void ScanlineEffect_Clear(void)
{
    CpuFill16(0, gScanlineEffectRegBuffers, sizeof(gScanlineEffectRegBuffers));
    gScanlineEffect.dmaSrcBuffers[0] = NULL;
    gScanlineEffect.dmaSrcBuffers[1] = NULL;
    gScanlineEffect.dmaDest = NULL;
    gScanlineEffect.dmaControl = 0;
    gScanlineEffect.srcBuffer = 0;
    gScanlineEffect.state = 0;
    gScanlineEffect.unused16 = 0;
    gScanlineEffect.unused17 = 0;
    gScanlineEffect.waveTaskId = TASK_NONE;
}

void ScanlineEffect_SetParams(struct ScanlineEffectParams params)
{
    if (params.dmaControl == SCANLINE_EFFECT_DMACNT_16BIT)
    {
        // The first DMA transfer occurs after the first scanline is drawn.
        gScanlineEffect.dmaSrcBuffers[0] = (u16 *)gScanlineEffectRegBuffers[0] + 1;
        gScanlineEffect.dmaSrcBuffers[1] = (u16 *)gScanlineEffectRegBuffers[1] + 1;
        gScanlineEffect.setFirstScanlineReg = CopyValue16Bit;
    }
    else
    {
        gScanlineEffect.dmaSrcBuffers[0] = (u32 *)gScanlineEffectRegBuffers[0] + 1;
        gScanlineEffect.dmaSrcBuffers[1] = (u32 *)gScanlineEffectRegBuffers[1] + 1;
        gScanlineEffect.setFirstScanlineReg = CopyValue32Bit;
    }

    gScanlineEffect.dmaControl = params.dmaControl;
    gScanlineEffect.dmaDest = params.dmaDest;
    gScanlineEffect.state = params.initState;
    gScanlineEffect.unused16 = params.unused9;
    gScanlineEffect.unused17 = params.unused9;
}

void ScanlineEffect_InitHBlankDmaTransfer(void)
{
    if (gScanlineEffect.state == 0)
    {
        return;
    }
    else if (gScanlineEffect.state == 3)
    {
        gScanlineEffect.state = 0;
        DmaStop(0);
        gUnknown_20397E4 = TRUE;
    }
    else
    {
        DmaStop(0);
        DmaSet(0, gScanlineEffect.dmaSrcBuffers[gScanlineEffect.srcBuffer], gScanlineEffect.dmaDest, gScanlineEffect.dmaControl);
        gScanlineEffect.setFirstScanlineReg();
        gScanlineEffect.srcBuffer ^= 1;
    }
}

static void CopyValue16Bit(void)
{
    vu16 *dest = (vu16 *)gScanlineEffect.dmaDest;
    vu16 *src = (vu16 *)&gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer];

    *dest = *src;
}

static void CopyValue32Bit(void)
{
    vu32 *dest = (vu32 *)gScanlineEffect.dmaDest;
    vu32 *src = (vu32 *)&gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer];

    *dest = *src;
}

#define tStartLine            data[0]
#define tEndLine              data[1]
#define tWaveLength           data[2]
#define tSrcBufferOffset      data[3]
#define tFramesUntilMove      data[4]
#define tDelayInterval        data[5]
#define tRegOffset            data[6]
#define tApplyBattleBgOffsets data[7]

static void TaskFunc_UpdateWavePerFrame(u8 taskId)
{
    int value = 0;
    int i;
    int offset;

    if (gUnknown_20397E4)
    {
        DestroyTask(taskId);
        gScanlineEffect.waveTaskId = TASK_NONE;
    }
    else
    {
        if (gTasks[taskId].tApplyBattleBgOffsets)
        {
            switch (gTasks[taskId].tRegOffset)
            {
            case SCANLINE_EFFECT_REG_BG0HOFS:
                value = gBattle_BG0_X;
                break;
            case SCANLINE_EFFECT_REG_BG0VOFS:
                value = gBattle_BG0_Y;
                break;
            case SCANLINE_EFFECT_REG_BG1HOFS:
                value = gBattle_BG1_X;
                break;
            case SCANLINE_EFFECT_REG_BG1VOFS:
                value = gBattle_BG1_Y;
                break;
            case SCANLINE_EFFECT_REG_BG2HOFS:
                value = gBattle_BG2_X;
                break;
            case SCANLINE_EFFECT_REG_BG2VOFS:
                value = gBattle_BG2_Y;
                break;
            case SCANLINE_EFFECT_REG_BG3HOFS:
                value = gBattle_BG3_X;
                break;
            case SCANLINE_EFFECT_REG_BG3VOFS:
                value = gBattle_BG3_Y;
                break;
            }
        }
        if (gTasks[taskId].tFramesUntilMove != 0)
        {
            gTasks[taskId].tFramesUntilMove--;
            offset = gTasks[taskId].tSrcBufferOffset + 320;
            for (i = gTasks[taskId].tStartLine; i < gTasks[taskId].tEndLine; i++)
            {
                gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = gScanlineEffectRegBuffers[0][offset] + value;
                offset++;
            }
        }
        else
        {
            gTasks[taskId].tFramesUntilMove = gTasks[taskId].tDelayInterval;
            offset = gTasks[taskId].tSrcBufferOffset + 320;
            for (i = gTasks[taskId].tStartLine; i < gTasks[taskId].tEndLine; i++)
            {
                gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer][i] = gScanlineEffectRegBuffers[0][offset] + value;
                offset++;
            }

            gTasks[taskId].tSrcBufferOffset++;
            if (gTasks[taskId].tSrcBufferOffset == gTasks[taskId].tWaveLength)
                gTasks[taskId].tSrcBufferOffset = 0;
        }
    }
}

static void GenerateWave(u16 *buffer, u8 frequency, u8 amplitude, u8 unused)
{
    u16 i = 0;
    u8 theta = 0;

    while (i < 256)
    {
        buffer[i] = (gSineTable[theta] * amplitude) / 256;
        theta += frequency;
        i++;
    }
}

u8 ScanlineEffect_InitWave(u8 startLine, u8 endLine, u8 frequency, u8 amplitude, u8 delayInterval, u8 regOffset, bool8 applyBattleBgOffsets)
{
    int i;
    int offset;
    struct ScanlineEffectParams params;
    u8 taskId;

    ScanlineEffect_Clear();

    params.dmaDest = (void *)(REG_ADDR_BG0HOFS + regOffset);
    params.dmaControl = SCANLINE_EFFECT_DMACNT_16BIT;
    params.initState = 1;
    params.unused9 = 0;
    ScanlineEffect_SetParams(params);

    taskId = CreateTask(TaskFunc_UpdateWavePerFrame, 0);

    gTasks[taskId].tStartLine = startLine;
    gTasks[taskId].tEndLine = endLine;
    gTasks[taskId].tWaveLength = 256 / frequency;
    gTasks[taskId].tSrcBufferOffset = 0;
    gTasks[taskId].tFramesUntilMove = delayInterval;
    gTasks[taskId].tDelayInterval = delayInterval;
    gTasks[taskId].tRegOffset = regOffset;
    gTasks[taskId].tApplyBattleBgOffsets = applyBattleBgOffsets;

    gScanlineEffect.waveTaskId = taskId;
    gUnknown_20397E4 = FALSE;

    GenerateWave(&gScanlineEffectRegBuffers[0][320], frequency, amplitude, endLine - startLine);

    offset = 320;
    for (i = startLine; i < endLine; i++)
    {
        gScanlineEffectRegBuffers[0][i] = gScanlineEffectRegBuffers[0][offset];
        gScanlineEffectRegBuffers[1][i] = gScanlineEffectRegBuffers[0][offset];
        offset++;
    }

    return taskId;
}
