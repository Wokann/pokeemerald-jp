#include "global.h"
#include "main.h"
#include "palette.h"
#include "script.h"
#include "task.h"
#include "constants/rgb.h"

extern void CB2_LoadCableCar(void);

static void Task_LoadCableCar(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_LoadCableCar);
        DestroyTask(taskId);
    }
}

void CableCar(void)
{
    LockPlayerFieldControls();
    CreateTask(Task_LoadCableCar, 1);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
}
