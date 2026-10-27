"""Shared ownership requires real declarations, definitions and native pointers."""
from pathlib import Path
import copy
import json
import re
import struct
import tempfile
import unittest

import map_semantic_review as review

ROOT = Path(__file__).resolve().parents[1]
SAMPLES = ('SecretBase_RedCave1','ContestHallBeauty','BattlePyramidSquare02')
BATCH = dict(review_type='shared_map_v1')


class SharedMapOwnershipTests(unittest.TestCase):
    def fixture(self,name):
        temporary=tempfile.TemporaryDirectory(dir=ROOT/'.tmp/agent-work/tests',prefix='shared-map-input-')
        self.addCleanup(temporary.cleanup)
        root=Path(temporary.name)
        resolved=review.shared_map_inputs(ROOT,BATCH,name)
        paths={f'data/maps/{name}/map.json',resolved['script_path'],
               f'data/maps/{resolved["events_owner"]}/map.json'}
        for path in paths:
            target=root/path; target.parent.mkdir(parents=True,exist_ok=True)
            target.write_bytes((ROOT/path).read_bytes())
        return root

    def mutate(self,root,map_name,**values):
        path=root/f'data/maps/{map_name}/map.json'
        meta=json.loads(path.read_text()); meta.update(values)
        path.write_text(json.dumps(meta))

    def test_real_three_families_use_actual_files_without_synthetic_map_scripts(self):
        expected=(('SecretBase','data/scripts/shared_secret_base.inc','SecretBase_RedCave1'),
                  ('ContestHall','data/maps/ContestHall/scripts.inc','ContestHall'),
                  ('BattlePyramidSquare01','data/maps/BattlePyramidSquare01/scripts.inc','BattlePyramidSquare02'))
        for name,(owner,path,events) in zip(SAMPLES,expected):
            with self.subTest(name=name):
                resolved=review.shared_map_inputs(ROOT,BATCH,name)
                self.assertEqual((resolved['script_owner'],resolved['script_path'],resolved['events_owner']),
                                 (owner,path,events))
                self.assertFalse((ROOT/f'data/maps/{name}/scripts.inc').exists())
                required=review.review_component_sources(ROOT,BATCH,[name])
                self.assertIn(path,required)
                self.assertNotIn(f'data/maps/{name}/scripts.inc',required)
                self.assertTrue(review.SHARED_MAP_RUNTIME_CONTEXT[owner]<=required)
                self.assertTrue(all((ROOT/p).is_file() for p in required))

    def test_wrong_script_or_events_owner_and_connection_declarations_fail(self):
        for change in ({'shared_scripts_map':'ContestHall'}, {'shared_scripts_map':''},
                       {'shared_scripts_map':1}, {'shared_events_map':'ContestHall'},
                       {'shared_events_map':None}, {'connections':[]}, {'name':'OtherMap'}):
            with self.subTest(change=change):
                root=self.fixture(SAMPLES[0]); self.mutate(root,SAMPLES[0],**change)
                with self.assertRaises(ValueError): review.shared_map_inputs(root,BATCH,SAMPLES[0])

    def test_wrong_family_and_canonical_owner_cannot_claim_shared_credit(self):
        for name in ('PetalburgCity','ContestHall','BattlePyramidSquare01'):
            with self.subTest(name=name),self.assertRaises(ValueError): review.shared_map_inputs(ROOT,BATCH,name)
        direct=review.review_component_sources(ROOT,dict(review_type='direct_map_v4'),[SAMPLES[0]])
        self.assertIn(f'data/maps/{SAMPLES[0]}/scripts.inc',direct)

    def test_address_alias_cannot_replace_actual_map_script_definition(self):
        root=self.fixture(SAMPLES[0])
        path=root/'data/scripts/shared_secret_base.inc'
        path.write_text('.globl SecretBase_MapScripts\n.set SecretBase_MapScripts, 0x0821D372\n')
        with self.assertRaisesRegex(ValueError,'noncanonical_shared_script_definition'):
            review.shared_map_inputs(root,BATCH,SAMPLES[0])

    def test_chained_shared_events_are_rejected(self):
        root=self.fixture(SAMPLES[1]); self.mutate(root,'ContestHall',shared_events_map='Other')
        with self.assertRaisesRegex(ValueError,'chained_or_mismatched_shared_events'):
            review.shared_map_inputs(root,BATCH,SAMPLES[1])

    def base_record(self):
        batches = json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches']
        return next(batch for batch in batches if batch['id'] == 'SecretBase_interiors_shared_review_20261028')

    def test_complete_twenty_four_map_record_uses_reachable_real_shared_owners(self):
        batch = self.base_record()
        self.assertEqual(len(batch['maps']), 24)
        result = review._review_batch(ROOT, batch, set(batch['maps']), {})
        self.assertEqual(result['errors'], [])
        self.assertEqual(result['status'], 'current')

    def test_complete_record_cannot_omit_any_c_installed_entry(self):
        for entry in review.SECRET_BASE_RUNTIME_ROOTS:
            batch = copy.deepcopy(self.base_record())
            batch['shared_dependencies'] = [dep for dep in batch['shared_dependencies'] if dep['entry'] != entry]
            with self.subTest(entry=entry), self.assertRaisesRegex(ValueError, '^missing_shared_call_evidence:' + entry + '$'):
                review.component_contracts(ROOT, batch, batch['maps'])

    def test_c_installed_base_entries_are_required_despite_null_json_scripts(self):
        roots = review.shared_map_runtime_roots(ROOT, BATCH, [SAMPLES[0]])
        self.assertEqual(len(roots), 5)
        self.assertIn('SecretBase_EventScript_DollInteract', roots)
        self.assertIn('SecretBase_EventScript_CushionInteract', roots)
        self.assertEqual(review.shared_map_runtime_roots(ROOT, BATCH, list(SAMPLES[1:])), {})
        self.assertEqual(review.shared_map_runtime_roots(ROOT, dict(review_type='direct_map_v4'), [SAMPLES[0]]), {})
        meta = json.loads((ROOT / f'data/maps/{SAMPLES[0]}/map.json').read_text())
        self.assertTrue(all(e['script'] == '0x0' for e in meta['object_events'][1:]))

    def test_missing_runtime_source_and_comment_or_extern_substitutes_fail(self):
        for entry, (path, kind) in review.SECRET_BASE_RUNTIME_ROOTS.items():
            root = self.fixture(SAMPLES[0])
            for source, unused in review.SECRET_BASE_RUNTIME_ROOTS.values():
                target = root / source
                target.parent.mkdir(parents=True, exist_ok=True)
                target.write_bytes((ROOT / source).read_bytes())
            target = root / path
            source = target.read_text()
            source = source.replace(entry, entry + '_Removed')
            source += '\nextern const unsigned char ' + entry + '[];\n'
            source += '/* "_literal: .4byte ' + entry + '\\n\\t" */\n'
            source += '// OverrideObjectEventTemplateScript(&gObjectEvents[objectEventId], ' + entry + ');\n'
            target.write_text(source)
            with self.subTest(entry=entry), self.assertRaisesRegex(ValueError, 'missing_shared_runtime_script_source:' + entry):
                review.shared_map_runtime_roots(root, BATCH, [SAMPLES[0]])

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_runtime_entries_bind_real_c_owner_literals_and_reject_mutated_pointers(self):
        symbols, unused = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        owners = []
        for line in (ROOT / 'pokeemerald_jp.map').read_text().splitlines():
            match = re.match(r'^\s*(?:\S+\s+)?(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+(\S+\.o)\s*$', line)
            if match:
                owners.append((int(match[1], 16), int(match[2], 16), match[3]))
        native = dict(symbols=symbols, owners=owners, rom=(ROOT / 'baserom_jp.gba').read_bytes())
        errors = []
        review._shared_map_runtime_native(ROOT, BATCH, [SAMPLES[0]], native, errors)
        self.assertEqual(errors, [])
        for entry, path in review.shared_map_runtime_roots(ROOT, BATCH, [SAMPLES[0]]).items():
            pointer = struct.pack('<I', next(iter(symbols[entry])))
            changed = dict(native)
            changed['rom'] = bytearray(native['rom'])
            object_path = path[:-2] + '.o'
            for start, size, owner in owners:
                if owner == object_path or owner.endswith('/' + object_path):
                    offset = start - 0x08000000
                    if offset >= 0:
                        changed['rom'][offset:offset+size] = changed['rom'][offset:offset+size].replace(pointer, b'\0' * 4)
            errors = []
            review._shared_map_runtime_native(ROOT, BATCH, [SAMPLES[0]], changed, errors)
            with self.subTest(entry=entry):
                self.assertIn('native_shared_runtime_script_pointer_mismatch:' + entry, errors)

    @unittest.skipUnless((ROOT/'pokeemerald_jp.elf').is_file(),'requires native artifacts')
    def test_all_fifty_native_headers_point_to_actual_shared_definitions(self):
        symbols,_=review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes())
        native=dict(symbols=symbols,rom=(ROOT/'baserom_jp.gba').read_bytes())
        meta=[p for p in (ROOT/'data/maps').glob('*/map.json') if 'shared_scripts_map' in json.loads(p.read_text())]
        self.assertEqual(len(meta),50)
        errors=[]; review._shared_map_header_native(ROOT,BATCH,[p.parent.name for p in meta],native,errors)
        self.assertEqual(errors,[])
        for field in range(4):
            changed=dict(native); changed['rom']=bytearray(native['rom'])
            at=next(iter(symbols[SAMPLES[0]]))-0x08000000+field*4
            struct.pack_into('<I',changed['rom'],at,struct.unpack_from('<I',native['rom'],at)[0]^4)
            errors=[]; review._shared_map_header_native(ROOT,BATCH,[SAMPLES[0]],changed,errors)
            self.assertIn('native_shared_map_header_pointer_mismatch:'+SAMPLES[0],errors)

    def test_exact_terminal_secret_base_boundary_excludes_adjacent_tm_owner(self):
        dep=dict(path='data/scripts/secret_base.inc',entry='SecretBase_EventScript_LostSecretBaseBattle',
                 labels=['SecretBase_EventScript_LostSecretBaseBattle'],
                 end_before_includes=['data/scripts/secret_power_tm.inc'])
        body=review.shared_script_blocks(ROOT,dep)[dep['entry']]
        self.assertEqual(review.statements(body),['special LostSecretBaseBattle','return'])
        self.assertEqual(review.shared_include_entry(ROOT,dep),'Route111_Text_MakingRoomUseTMToMakeYourOwn')
        payload=review.source_payload(ROOT,dict(path=dep['path'],selector='asm_labels',labels=dep['labels']))
        self.assertIn(b'.include "data/scripts/secret_power_tm.inc"',payload)
        for change in ({'entry':'SecretBase_EventScript_WonSecretBaseBattle'},
                       {'path':'data/scripts/other.inc'},
                       {'end_before_includes':['data/scripts/new_game.inc']},
                       {'end_before_includes':['data/scripts/secret_power_tm.inc']*2}):
            wrong=copy.deepcopy(dep); wrong.update(change)
            with self.subTest(change=change),self.assertRaises(ValueError): review.shared_include_entry(ROOT,wrong)


if __name__=='__main__': unittest.main()
