#include "global.h"
#include "constants/weather.h"

extern void SetWeather(u8 weather);

static void CoordEventWeather_Clouds(void)
{
    SetWeather(WEATHER_SUNNY_CLOUDS);
}

static void CoordEventWeather_Sunny(void)
{
    SetWeather(WEATHER_SUNNY);
}

static void CoordEventWeather_Thunderstorm(void)
{
    SetWeather(WEATHER_RAIN_THUNDERSTORM);
}

static void CoordEventWeather_Ash(void)
{
    SetWeather(WEATHER_VOLCANIC_ASH);
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
