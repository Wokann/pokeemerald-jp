#ifndef POKEEMERALD_JP_RTC_DATA_H
#define POKEEMERALD_JP_RTC_DATA_H

#include "global.h"
#include "siirtc.h"

// RTC const data (0x82D254C..0x82D2588)

extern const struct SiiRtcInfo sRtcDummy; // 2000 Jan 1
extern const s32 sNumDaysInMonths[MONTH_COUNT];

#endif // POKEEMERALD_JP_RTC_DATA_H
