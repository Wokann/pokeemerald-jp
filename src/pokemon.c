#include "global.h"

extern void *memcpy(void *dest, const void *src, unsigned int size);

void CopyMon(void *dest, void *src, unsigned int size)
{
    memcpy(dest, src, size);
}
