#include "global.h"

extern void *sHeapStart;
extern void *AllocInternal(void *heapStart, u32 size);
extern void *AllocZeroedInternal(void *heapStart, u32 size);
extern bool32 CheckMemBlockInternal(void *heapStart, void *pointer);

void *Alloc(u32 size)
{
    return AllocInternal(sHeapStart, size);
}

void *AllocZeroed(u32 size)
{
    return AllocZeroedInternal(sHeapStart, size);
}

bool32 CheckMemBlock(void *pointer)
{
    return CheckMemBlockInternal(sHeapStart, pointer);
}
