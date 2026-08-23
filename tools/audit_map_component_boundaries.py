#!/usr/bin/env python3
"""Audit JP map components from the top down.

The US project keeps map headers/layouts, map event records, and script_data
in distinct build inputs.  The JP ROM can place some of those records near one
another, so this report makes their actual boundaries and pointer edges
explicit before a raw range is converted.

Examples:
    python3 tools/audit_map_component_boundaries.py
    python3 tools/audit_map_component_boundaries.py --map RustboroCity
    python3 tools/audit_map_component_boundaries.py --map RustboroCity --json
"""

import argparse
import json
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
US_ROOT = Path('/home/kenny/pokeemerald')
sys.path.insert(0, str(ROOT / 'tools'))

import jp_emit_maps as emitter
import jp_script_parser as script_parser
import split_script_region


ROM_START = 0x08000000
ROM_END = ROM_START + len(script_parser.ROM)
SCRIPT_DATA_START = split_script_region.REGION_BASE + split_script_region.REGION_START
SCRIPT_DATA_END = split_script_region.REGION_BASE + split_script_region.REGION_END

MAP_EVENTS_HEADER_SIZE = 20
OBJECT_EVENT_SIZE = 0x18
WARP_EVENT_SIZE = 8
COORD_EVENT_SIZE = 0x10
BG_EVENT_SIZE = 0x0C


def hex_addr(value):
    return '0x%08X' % value


def is_rom_addr(value):
    return ROM_START <= value < ROM_END


def in_script_data(addr, size):
    return addr < SCRIPT_DATA_END and SCRIPT_DATA_START < addr + size


def component(name, addr, size, count=None):
    if not is_rom_addr(addr) or size == 0:
        return None
    out = {
        'name': name,
        'address': hex_addr(addr),
        'end': hex_addr(addr + size),
        'size': size,
        'inside_script_data': in_script_data(addr, size),
    }
    if count is not None:
        out['count'] = count
    return out


def read_event_data(events_addr):
    """Return MapEvents component ranges and the script-facing pointer edges."""
    if not is_rom_addr(events_addr):
        return {
            'address': hex_addr(events_addr),
            'counts': {'object_events': 0, 'warp_events': 0,
                       'coord_events': 0, 'bg_events': 0},
            'components': [],
            'script_refs': [],
            'bg_data_refs': [],
        }

    rom = script_parser.ROM
    base = events_addr - ROM_START
    counts = {
        'object_events': rom[base],
        'warp_events': rom[base + 1],
        'coord_events': rom[base + 2],
        'bg_events': rom[base + 3],
    }
    objects = script_parser.rd32(events_addr + 4)
    warps = script_parser.rd32(events_addr + 8)
    coords = script_parser.rd32(events_addr + 12)
    bgs = script_parser.rd32(events_addr + 16)

    components = [component('map_events_header', events_addr, MAP_EVENTS_HEADER_SIZE)]
    components.extend([
        component('object_events', objects, counts['object_events'] * OBJECT_EVENT_SIZE,
                  counts['object_events']),
        component('warp_events', warps, counts['warp_events'] * WARP_EVENT_SIZE,
                  counts['warp_events']),
        component('coord_events', coords, counts['coord_events'] * COORD_EVENT_SIZE,
                  counts['coord_events']),
        component('bg_events', bgs, counts['bg_events'] * BG_EVENT_SIZE,
                  counts['bg_events']),
    ])
    components = [item for item in components if item is not None]

    script_refs = []
    bg_data_refs = []
    if is_rom_addr(objects):
        for i in range(counts['object_events']):
            target = script_parser.rd32(objects + i * OBJECT_EVENT_SIZE + 0x10)
            if is_rom_addr(target):
                script_refs.append({'source': 'object[%d]' % i, 'target': hex_addr(target)})
    if is_rom_addr(coords):
        for i in range(counts['coord_events']):
            target = script_parser.rd32(coords + i * COORD_EVENT_SIZE + 0xC)
            if is_rom_addr(target):
                script_refs.append({'source': 'coord[%d]' % i, 'target': hex_addr(target)})
    if is_rom_addr(bgs):
        for i in range(counts['bg_events']):
            record = bgs + i * BG_EVENT_SIZE
            kind = rom[record - ROM_START + 5]
            target = script_parser.rd32(record + 8)
            if not is_rom_addr(target):
                continue
            ref = {'source': 'bg[%d]' % i, 'kind': kind, 'target': hex_addr(target)}
            if kind <= 4:
                script_refs.append(ref)
            else:
                bg_data_refs.append(ref)

    return {
        'address': hex_addr(events_addr),
        'counts': counts,
        'components': components,
        'script_refs': script_refs,
        'bg_data_refs': bg_data_refs,
    }


def map_script_owners():
    """Map name -> script table plus its physical region in script_data."""
    owners = emitter.map_entries(include_empty=True)
    unique_starts = sorted({entry[0] for entry in owners})
    region_ends = {
        start: unique_starts[i + 1] if i + 1 < len(unique_starts) else None
        for i, start in enumerate(unique_starts)
    }
    by_name = {}
    for start, name, _group, _num, entries, _events in owners:
        frame_tables = []
        refs = []
        for tag, target in entries:
            refs.append({'source': 'map_script[%d]' % tag, 'target': hex_addr(target)})
            if tag in (2, 4) and is_rom_addr(target):
                values = emitter.parse_frame_table(target)
                frame_tables.append({
                    'address': hex_addr(target),
                    'end': hex_addr(target + len(values) * 8 + 2),
                    'entries': len(values),
                    'refs': [
                        {'source': 'frame[%d]' % i, 'target': hex_addr(script)}
                        for i, (_var, _compare, script) in enumerate(values)
                    ],
                })
        by_name[name] = {
            'address': hex_addr(start),
            'end': hex_addr(region_ends[start]) if region_ends[start] else None,
            'entries': len(entries),
            'table_size': len(entries) * 5 + 1,
            'refs': refs,
            'frame_tables': frame_tables,
        }
    return by_name


def us_map_counts(name):
    path = US_ROOT / 'data' / 'maps' / name / 'map.json'
    scripts = US_ROOT / 'data' / 'maps' / name / 'scripts.inc'
    if not path.is_file():
        return {
            'map_json': False,
            'scripts_inc': scripts.is_file(),
            'counts': None,
        }
    data = json.loads(path.read_text(encoding='utf-8'))
    return {
        'map_json': True,
        'scripts_inc': scripts.is_file(),
        'counts': {
            'object_events': len(data.get('object_events', [])),
            'warp_events': len(data.get('warp_events', [])),
            'coord_events': len(data.get('coord_events', [])),
            'bg_events': len(data.get('bg_events', [])),
        },
    }


def build_records():
    owner_data = map_script_owners()
    records = []
    for group, number, header, layout, events, map_scripts, wild, _name in emitter.MAP_HEADERS:
        name = emitter.MAP_NAMES.get((group, number))
        if name is None:
            continue
        header = emitter.toi(header)
        layout = emitter.toi(layout)
        events = emitter.toi(events)
        map_scripts = emitter.toi(map_scripts)
        wild = emitter.toi(wild)
        event_data = read_event_data(events)
        record = {
            'name': name,
            'map': {'group': group, 'number': number},
            'header': hex_addr(header),
            'layout': hex_addr(layout),
            'wild': hex_addr(wild),
            'map_scripts': owner_data.get(name),
            'map_events': event_data,
            'us': us_map_counts(name),
        }
        records.append(record)
    return sorted(records, key=lambda item: (item['map']['group'], item['map']['number']))


def print_summary(records):
    event_counts = Counter()
    script_refs = 0
    bg_data_refs = 0
    event_components_in_script_data = []
    us_count_mismatches = []
    map_script_owners_count = 0
    for record in records:
        if record['map_scripts'] is not None:
            map_script_owners_count += 1
        event_data = record['map_events']
        event_counts.update(event_data['counts'])
        script_refs += len(event_data['script_refs'])
        bg_data_refs += len(event_data['bg_data_refs'])
        embedded = [item['name'] for item in event_data['components'] if item['inside_script_data']]
        if embedded:
            event_components_in_script_data.append((record['name'], embedded))
        us_counts = record['us']['counts']
        if us_counts is not None and us_counts != event_data['counts']:
            us_count_mismatches.append(record['name'])

    print('JP map headers:                    %d' % len(records))
    print('JP map-script table owners:       %d' % map_script_owners_count)
    print('JP MapEvents script references:   %d' % script_refs)
    print('JP non-script BG data references: %d' % bg_data_refs)
    print('JP event records: objects=%d warps=%d coords=%d bgs=%d' % (
        event_counts['object_events'], event_counts['warp_events'],
        event_counts['coord_events'], event_counts['bg_events']))
    print('Map-event components inside current script_data region: %d maps' %
          len(event_components_in_script_data))
    print('JP/US event-count mismatches:     %d maps' % len(us_count_mismatches))
    print('script_data build region:          %s-%s' % (
        hex_addr(SCRIPT_DATA_START), hex_addr(SCRIPT_DATA_END)))
    if event_components_in_script_data:
        print('\nMaps whose event components overlap script_data (audit before decoding raw bytes):')
        for name, kinds in event_components_in_script_data[:20]:
            print('  %-44s %s' % (name, ', '.join(kinds)))
        if len(event_components_in_script_data) > 20:
            print('  ... %d more' % (len(event_components_in_script_data) - 20))


def find_record(records, name):
    folded = name.casefold()
    matches = [record for record in records if record['name'].casefold() == folded]
    if not matches:
        matches = [record for record in records if folded in record['name'].casefold()]
    if len(matches) != 1:
        choices = ', '.join(record['name'] for record in matches[:12]) or 'none'
        raise SystemExit('map query %r matched %d entries: %s' % (name, len(matches), choices))
    return matches[0]


def print_record(record):
    print('%s (group %d, map %d)' % (
        record['name'], record['map']['group'], record['map']['number']))
    print('JP header=%s layout=%s wild=%s' % (
        record['header'], record['layout'], record['wild']))
    scripts = record['map_scripts']
    if scripts is None:
        print('JP map scripts: none')
    else:
        print('JP map scripts: table=%s size=0x%X entries=%d region=%s-%s' % (
            scripts['address'], scripts['table_size'], scripts['entries'],
            scripts['address'], scripts['end'] or 'unknown'))
        print('  map-script refs=%d frame tables=%d' % (
            len(scripts['refs']), len(scripts['frame_tables'])))
    event_data = record['map_events']
    counts = event_data['counts']
    print('JP map events: header=%s objects=%d warps=%d coords=%d bgs=%d' % (
        event_data['address'], counts['object_events'], counts['warp_events'],
        counts['coord_events'], counts['bg_events']))
    for item in event_data['components']:
        print('  %-18s %s-%s size=0x%X%s' % (
            item['name'], item['address'], item['end'], item['size'],
            ' inside script_data' if item['inside_script_data'] else ''))
    print('  event script refs=%d; BG data refs=%d' % (
        len(event_data['script_refs']), len(event_data['bg_data_refs'])))
    us = record['us']
    print('US source: map.json=%s scripts.inc=%s counts=%s' % (
        us['map_json'], us['scripts_inc'], us['counts']))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--map', dest='map_name', help='exact or unique partial map name')
    parser.add_argument('--json', action='store_true', help='emit structured JSON instead of text')
    args = parser.parse_args()

    records = build_records()
    if args.map_name:
        record = find_record(records, args.map_name)
        if args.json:
            print(json.dumps(record, ensure_ascii=False, indent=2))
        else:
            print_record(record)
    elif args.json:
        print(json.dumps(records, ensure_ascii=False, indent=2))
    else:
        print_summary(records)


if __name__ == '__main__':
    main()
