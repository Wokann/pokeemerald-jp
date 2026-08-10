#include "global.h"
#include "constants/weather.h"
#include "coord_event_weather.h"

extern void SetWeather(u8 weather);

struct CoordEventWeather
{
    u8 coordEventWeather;
    void (*func)(void);
};

// JP ROM table at 0x084E8924 (13 entries). The id values match the US
// COORD_EVENT_WEATHER_* constants; the JP disassembly labels for entries
// 3/4/6/7/9/10 were wrong, so the names below follow pokeemerald.
extern const struct CoordEventWeather sCoordEventWeatherFuncs[13];

static void CoordEventWeather_Clouds(void)
{
    SetWeather(WEATHER_SUNNY_CLOUDS);
}

static void CoordEventWeather_Sunny(void)
{
    SetWeather(WEATHER_SUNNY);
}

static void CoordEventWeather_Rain(void)
{
    SetWeather(WEATHER_RAIN);
}

static void CoordEventWeather_Snow(void)
{
    SetWeather(WEATHER_SNOW);
}

static void CoordEventWeather_Thunderstorm(void)
{
    SetWeather(WEATHER_RAIN_THUNDERSTORM);
}

static void CoordEventWeather_HorizontalFog(void)
{
    SetWeather(WEATHER_FOG_HORIZONTAL);
}

static void CoordEventWeather_DiagonalFog(void)
{
    SetWeather(WEATHER_FOG_DIAGONAL);
}

static void CoordEventWeather_Ash(void)
{
    SetWeather(WEATHER_VOLCANIC_ASH);
}

static void CoordEventWeather_Sandstorm(void)
{
    SetWeather(WEATHER_SANDSTORM);
}

static void CoordEventWeather_Shade(void)
{
    SetWeather(WEATHER_SHADE);
}

static void CoordEventWeather_Drought(void)
{
    SetWeather(WEATHER_DROUGHT);
}

static void CoordEventWeather_Route119Cycle(void)
{
    SetWeather(WEATHER_ROUTE119_CYCLE);
}

static void CoordEventWeather_Route123Cycle(void)
{
    SetWeather(WEATHER_ROUTE123_CYCLE);
}

void DoCoordEventWeather(u8 coordEventWeather)
{
    u8 i;
    for (i = 0; i < ARRAY_COUNT(sCoordEventWeatherFuncs); i++)
    {
        if (sCoordEventWeatherFuncs[i].coordEventWeather == coordEventWeather)
        {
            sCoordEventWeatherFuncs[i].func();
            return;
        }
    }
}
