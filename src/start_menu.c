#include "global.h"

void AppendToList(u8 *list, u8 *pos, u8 newEntry)
{
    list[*pos] = newEntry;
    (*pos)++;
}
