#!/usr/bin/env python3
"""Check map-script label order against US without claiming semantic parity.

JP-only bytes and US-only release behavior are recorded explicitly. A known
exception still requires the common labels to remain in the same order.
"""

from __future__ import annotations

import argparse
import json
import re
from pathlib import Path


JP_ROOT = Path(__file__).resolve().parents[1]
US_ROOT = JP_ROOT.parent / "pokeemerald"
LABEL_RE = re.compile(r"^([A-Za-z_][A-Za-z_0-9]*):{1,2}(?:\s|$)")

# These are label-list differences, not permission to copy US bytes into JP.
KNOWN_DIFFERENCES = {
    "FallarborTown_BattleTentBattleRoom": {
        "jp_only": {"FallarborTown_BattleTentBattleRoom_EventScript_UnreachableWaitstate"},
        "us_only": set(),
        "reason": "JP has an extra unreachable waitstate byte at 0x081F5B73.",
    },
    "Route101": {
        "jp_only": {"Route101_Movement_UnusedStepEnd1", "Route101_Movement_UnusedStepEnd2"},
        "us_only": set(),
        "reason": "JP names the two extra step_end bytes that US leaves inside preceding movements.",
    },
    "SlateportCity_OceanicMuseum_2F": {
        "jp_only": {"SlateportCity_OceanicMuseum_2F_Text_SubmersibleReplica"},
        "us_only": {"SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica"},
        "reason": "JP uses the correctly spelled text label; US spells it SumbersibleReplica.",
    },
    "TrainerHill_Entrance": {
        "jp_only": set(),
        "us_only": {
            "TrainerHill_Entrance_EventScript_Closed",
            "TrainerHill_Entrance_EventScript_GirlTrainerHillClosed",
            "TrainerHill_Entrance_EventScript_ManTrainerHillClosed",
            "TrainerHill_Entrance_Text_CantWaitToTestTheWaters",
            "TrainerHill_Entrance_Text_DoYouKnowWhenTheyOpen",
            "TrainerHill_Entrance_Text_StillGettingReady",
        },
        "reason": "US has pre-game-clear Trainer Hill closure scenes absent from the JP ROM.",
    },
}


def labels(path: Path) -> list[str]:
    result = []
    for line in path.read_text(encoding="utf-8").splitlines():
        match = LABEL_RE.match(line)
        if match:
            result.append(match.group(1))
    return result


def compare_lists(name: str, jp: list[str], us: list[str], known=None) -> dict:
    known = KNOWN_DIFFERENCES if known is None else known
    jp_set, us_set = set(jp), set(us)
    jp_only = [label for label in jp if label not in us_set]
    us_only = [label for label in us if label not in jp_set]
    shared_jp = [label for label in jp if label in us_set]
    shared_us = [label for label in us if label in jp_set]
    duplicates = len(jp_set) != len(jp) or len(us_set) != len(us)
    expected = known.get(name)
    if not duplicates and jp == us:
        status = "identical"
    elif (not duplicates and expected is not None
          and set(jp_only) == expected["jp_only"]
          and set(us_only) == expected["us_only"]
          and shared_jp == shared_us):
        status = "known_difference"
    else:
        status = "needs_review"
    return {
        "map": name,
        "status": status,
        "jp_labels": len(jp),
        "us_labels": len(us),
        "jp_only": jp_only,
        "us_only": us_only,
        "common_order_matches": shared_jp == shared_us,
        "duplicate_labels": duplicates,
        "reason": expected["reason"] if status == "known_difference" else None,
    }


def report(jp_root: Path, us_root: Path, known=None) -> dict:
    jp_maps = jp_root / "data/maps"
    us_maps = us_root / "data/maps"
    jp_names = {path.parent.name for path in jp_maps.glob("*/scripts.inc")}
    us_names = {path.parent.name for path in us_maps.glob("*/scripts.inc")}
    records = []
    for name in sorted(jp_names & us_names):
        records.append(compare_lists(
            name,
            labels(jp_maps / name / "scripts.inc"),
            labels(us_maps / name / "scripts.inc"),
            known,
        ))
    counts = {status: sum(record["status"] == status for record in records)
              for status in ("identical", "known_difference", "needs_review")}
    return {
        "scope": "script-label names and order only; not semantic or text review",
        "compared_maps": len(records),
        "counts": counts,
        "jp_maps_without_us": sorted(jp_names - us_names),
        "us_maps_without_jp": sorted(us_names - jp_names),
        "differences": [record for record in records if record["status"] != "identical"],
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--jp-root", type=Path, default=JP_ROOT)
    parser.add_argument("--us-root", type=Path, default=US_ROOT)
    parser.add_argument("--json", action="store_true", help="emit deterministic JSON")
    args = parser.parse_args()
    result = report(args.jp_root, args.us_root)
    if args.json:
        print(json.dumps(result, ensure_ascii=False, indent=2, sort_keys=True))
    else:
        counts = result["counts"]
        print(f"map scripts: {result['compared_maps']} compared; "
              f"{counts['identical']} identical labels; "
              f"{counts['known_difference']} known JP/US differences; "
              f"{counts['needs_review']} need review")
        for record in result["differences"]:
            print(f"{record['map']}: {record['status']}; "
                  f"JP-only={record['jp_only']}; US-only={record['us_only']}")
            if record["reason"]:
                print(f"  {record['reason']}")
        print("Label alignment does not establish script, text, or control-code semantics.")
    return bool(result["jp_maps_without_us"] or result["us_maps_without_jp"]
                or result["counts"]["needs_review"])


if __name__ == "__main__":
    raise SystemExit(main())
