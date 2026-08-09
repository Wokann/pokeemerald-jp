#include "global.h"

extern void QueueExitLinkRoomKey(void);

void ExitLinkRoom(void)
{
    QueueExitLinkRoomKey();
}
