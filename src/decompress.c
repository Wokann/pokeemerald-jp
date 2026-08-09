#include "global.h"

extern void LZ77UnCompWram(const u32 *src, void *dest);

void LZDecompressVram(const u32 *src, void *dest)
{
    LZ77UnCompWram(src, dest);
}
