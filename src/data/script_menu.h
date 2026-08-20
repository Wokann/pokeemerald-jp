// Standard strings used by script commands and TV reports.
#define SCRIPT_MENU_STD_STRINGS __attribute__((section(".rodata.script_menu_mid58_std_strings")))

SCRIPT_MENU_STD_STRINGS const u8 *const gStdStrings[] = {
    [STDSTRING_COOL] = gText_Cool,
    [STDSTRING_BEAUTY] = gText_Beauty,
    [STDSTRING_CUTE] = gText_Cute,
    [STDSTRING_SMART] = gText_Smart,
    [STDSTRING_TOUGH] = gText_Tough,
    [STDSTRING_NORMAL] = gText_Normal,
    [STDSTRING_SUPER] = gText_Super,
    [STDSTRING_HYPER] = gText_Hyper,
    [STDSTRING_MASTER] = gText_Master,
    [STDSTRING_COOL2] = gText_Cool2,
    [STDSTRING_BEAUTY2] = gText_Beauty2,
    [STDSTRING_CUTE2] = gText_Cute2,
    [STDSTRING_SMART2] = gText_Smart2,
    [STDSTRING_TOUGH2] = gText_Tough2,
    [STDSTRING_ITEMS] = gText_Items,
    [STDSTRING_KEYITEMS] = gText_Key_Items,
    [STDSTRING_POKEBALLS] = gText_Poke_Balls,
    [STDSTRING_TMHMS] = gText_TMs_Hms,
    [STDSTRING_BERRIES] = gText_Berries2,
    [STDSTRING_SINGLE] = gText_Single2,
    [STDSTRING_DOUBLE] = gText_Double2,
    [STDSTRING_MULTI] = gText_Multi,
    [STDSTRING_MULTI_LINK] = gText_MultiLink,
    [STDSTRING_BATTLE_TOWER] = gText_BattleTower,
    [STDSTRING_BATTLE_DOME] = gText_BattleDome,
    [STDSTRING_BATTLE_FACTORY] = gText_BattleFactory,
    [STDSTRING_BATTLE_PALACE] = gText_BattlePalace,
    [STDSTRING_BATTLE_ARENA] = gText_BattleArena,
    [STDSTRING_BATTLE_PIKE] = gText_BattlePike,
    [STDSTRING_BATTLE_PYRAMID] = gText_BattlePyramid,
};

#undef SCRIPT_MENU_STD_STRINGS
