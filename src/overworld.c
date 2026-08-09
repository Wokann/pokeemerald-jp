#include "global.h"
#include "overworld.h"

extern void SafariZoneRetirePrompt(void);

void CB2_OverworldBasic(void)
{
    SafariZoneRetirePrompt();
}

static void MovementStatusHandler_EnterFreeMode(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent)
{
    linkPlayerObjEvent->movementMode = MOVEMENT_MODE_FREE;
}

static void ZeroLinkPlayerObjectEvent(struct LinkPlayerObjectEvent *linkPlayerObjEvent)
{
    memset(linkPlayerObjEvent, 0, sizeof(struct LinkPlayerObjectEvent));
}
