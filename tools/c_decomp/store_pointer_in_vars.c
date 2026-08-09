typedef signed short s16;
typedef unsigned int u32;
typedef long intptr_t;

void StorePointerInVars(s16 *lo, s16 *hi, const void *ptr)
{
    *lo = ((intptr_t) ptr) & 0xffff;
    *hi = (((intptr_t) ptr) >> 16) & 0xffff;
}
