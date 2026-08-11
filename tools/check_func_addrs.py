#!/usr/bin/env python3
"""Compare C-built function addresses in the map against expected JP addresses."""

import re
import sys


EXPECTED = {
    "Task_SpinPokenavIcon": 0x08196294,
    "TrainerIsEligibleForRematch": 0x081962E8,
    "GetRematchTrainerLocation": 0x0819632C,
    "GetNumRematchTrainersFought": 0x08196340,
    "GetNthRematchTrainerFought": 0x08196374,
    "SelectMatchCallMessage": 0x081963AC,
    "GetTrainerMatchCallId": 0x08196444,
    "GetSameRouteMatchCallText": 0x08196464,
    "GetDifferentRouteMatchCallText": 0x08196490,
    "GetBattleMatchCallText": 0x081964BC,
    "GetGeneralMatchCallText": 0x08196510,
    "BuildMatchCallString": 0x081965E0,
    "PopulateMatchCallStringVars": 0x081965FC,
    "PopulateMatchCallStringVar": 0x0819662C,
    "PopulateTrainerName": 0x08196644,
    "PopulateMapName": 0x08196698,
    "GetLandEncounterSlot": 0x081966B4,
    "GetWaterEncounterSlot": 0x0819674C,
    "PopulateSpeciesFromTrainerLocation": 0x08196794,
    "PopulateSpeciesFromTrainerParty": 0x0819686C,
    "PopulateBattleFrontierFacilityName": 0x081968E8,
    "PopulateBattleFrontierStreak": 0x08196908,
    "GetNumOwnedBadges": 0x08196940,
    "ShouldTrainerRequestBattle": 0x08196968,
    "GetFrontierStreakInfo": 0x081969F8,
    "GetPokedexRatingLevel": 0x08196B84,
    "BufferPokedexRatingForMatchCall": 0x08196C74,
    "LoadMatchCallWindowGfx": 0x08196D78,
    "DrawMatchCallTextBoxBorder": 0x08196DB8,
}


def main():
    with open("pokeemerald_jp.map", encoding="utf-8", errors="replace") as f:
        lines = f.readlines()
    found = {}
    for line in lines:
        m = re.match(r"\s*0x([0-9a-f]+)\s+(\w+)\s*$", line)
        if m:
            addr = int(m.group(1), 16)
            name = m.group(2)
            if name in EXPECTED and name not in found:
                found[name] = addr
    for name, exp in EXPECTED.items():
        got = found.get(name)
        if got is None:
            print(f"{name:40s} NOT FOUND in map")
        elif got != exp:
            print(f"{name:40s} got={got:#x} exp={exp:#x} delta={got - exp:+d}")


if __name__ == "__main__":
    main()
