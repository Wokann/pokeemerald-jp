"""Native fixtures for measured Glass Workshop arithmetic and institute movement."""
from pathlib import Path
import unittest
import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
PREFIX = 'Route113_GlassWorkshop_EventScript_'
PRICES = (('BlueFlute', 'BLUE_FLUTE_PRICE', 250), ('YellowFlute', 'YELLOW_FLUTE_PRICE', 500),
          ('RedFlute', 'RED_FLUTE_PRICE', 500), ('WhiteFlute', 'WHITE_FLUTE_PRICE', 1000),
          ('BlackFlute', 'BLACK_FLUTE_PRICE', 1000), ('PrettyChair', 'PRETTY_CHAIR_PRICE', 6000),
          ('PrettyDesk', 'PRETTY_DESK_PRICE', 8000))
DECLARATIONS = '\n'.join(f'.set {name}, {value}' for _, name, value in PRICES)
DECLARATIONS += '\n.set LOWEST_ASH_PRICE, BLUE_FLUTE_PRICE\n'
MAP_TABLE = ('Route113_GlassWorkshop_MapScripts::\n'
             'map_script MAP_SCRIPT_ON_TRANSITION, Route113_GlassWorkshop_OnTransition\n.byte 0\n'
             + DECLARATIONS)


class FinalRouteProfileTests(unittest.TestCase):
    def parse(self, body, owner='Entry', version=4):
        return profile.profile_block(ROOT, owner+'::\n'+body,version=version,address=0x08240700)

    def test_scalar_prices_add_no_bytes_and_keep_real_transition_pointer(self):
        result=profile.profile_block(ROOT, MAP_TABLE,version=4,address=0x08240700)
        self.assertEqual((result.size,result.kind,result.targets),
                         (6,'map_table',{'Route113_GlassWorkshop_OnTransition':'script'}))
        for changed in (MAP_TABLE.replace('250','251'), MAP_TABLE.replace('250','0x08240000'),
                        MAP_TABLE.replace('BLUE_FLUTE_PRICE\n','RED_FLUTE_PRICE\n'),
                        MAP_TABLE+'.set EXTRA, 0\n', MAP_TABLE.replace('.byte 0','.byte 1')):
            with self.subTest(changed=changed),self.assertRaises(ValueError):
                profile.profile_block(ROOT,changed,version=4,address=0x08240700)

    def test_price_subtraction_is_bound_to_each_actual_purchase_owner(self):
        for suffix,name,_ in PRICES:
            body=f'subvar VAR_ASH_GATHER_COUNT, {name}\nend'
            self.assertEqual(self.parse(body,PREFIX+suffix).size,6)
            for owner in ('Entry',PREFIX+'NotEnoughAsh',PREFIX+'UnknownPurchase'):
                with self.subTest(owner=owner,name=name),self.assertRaises(ValueError):
                    self.parse(body,owner)
            wrong='RED_FLUTE_PRICE' if name!='RED_FLUTE_PRICE' else 'BLUE_FLUTE_PRICE'
            with self.assertRaises(ValueError):
                self.parse(body.replace(name,wrong),PREFIX+suffix)

    def test_difference_uses_varget_only_at_two_actual_not_enough_owners(self):
        for suffix in ('NotEnoughAsh','NotEnoughAshForItem'):
            body='subvar VAR_0x800A, VAR_ASH_GATHER_COUNT\nend'
            self.assertEqual(self.parse(body,PREFIX+suffix).size,6)
            for changed in (body.replace('800A','800B'),body.replace('VAR_ASH_GATHER_COUNT','VAR_RESULT'),body.replace('COUNT','COUNT, 1')):
                with self.subTest(changed=changed),self.assertRaises(ValueError):
                    self.parse(changed,PREFIX+suffix)
        with self.assertRaises(ValueError):
            self.parse(body)
        self.assertEqual(self.parse('subvar VAR_0x800A, 65535\nend').size,6)
        with self.assertRaises(ValueError):
            self.parse('subvar VAR_0x800A, 65536\nend')

    def test_water_current_movement_has_one_byte_and_requires_termination(self):
        self.assertEqual(self.parse('ride_water_current_up\nstep_end').size,2)
        for body in ('ride_water_current_up 1\nstep_end','ride_water_current_up\nreturn','ride_water_current_up'):
            with self.subTest(body=body),self.assertRaises(ValueError): self.parse(body)

    def test_legacy_review_does_not_acquire_new_scalar_or_movement_forms(self):
        for body,owner in (('subvar VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE\nend',PREFIX+'BlueFlute'),
                           ('subvar VAR_0x800A, VAR_ASH_GATHER_COUNT\nend',PREFIX+'NotEnoughAsh'),
                           ('ride_water_current_up\nstep_end','Movement')):
            with self.subTest(body=body),self.assertRaises(ValueError): self.parse(body,owner,3)
        with self.assertRaises(ValueError): profile.profile_block(ROOT,MAP_TABLE,version=3,address=0x08240700)

    @unittest.skipUnless((ROOT/'tools/preproc/preproc').is_file(),'requires native tools')
    def test_actual_forms_match_fresh_macro_expansion_and_assembler(self):
        forms=[f'subvar VAR_ASH_GATHER_COUNT, {name}' for _,name,_ in PRICES]
        owners={form:PREFIX+suffix for form,(suffix,_,_) in zip(forms,PRICES)}
        difference='subvar VAR_0x800A, VAR_ASH_GATHER_COUNT'
        forms += [difference,'ride_water_current_up']
        owners[difference]=PREFIX+'NotEnoughAsh'
        native_forms.StoryProfileTests().check_native_forms(forms,version=4,source_prefix=DECLARATIONS,source_owners=owners)

    @unittest.skipUnless((ROOT/'pokeemerald_jp.elf').is_file(),'requires native ROM artifacts')
    def test_complete_workshop_owner_and_institute_shove_match_native_rom(self):
        native,_=review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes())
        rom=(ROOT/'baserom_jp.gba').read_bytes()
        source=(ROOT/'data/maps/Route113_GlassWorkshop/scripts.inc').read_text()
        blocks=review.label_blocks(source)
        size=sum(profile.profile_block(ROOT,b,version=4,address=next(iter(native[n]))).size for n,b in blocks.items())
        start=next(iter(native['Route113_GlassWorkshop_MapScripts']))
        self.assertEqual(verifier.assemble_candidate(source,start),rom[start-0x08000000:start-0x08000000+size])
        owner='Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay'
        block=review.label_blocks((ROOT/'data/maps/Route119_WeatherInstitute_2F/scripts.inc').read_text())[owner]
        start=next(iter(native[owner])); parsed=profile.profile_block(ROOT,block,version=4,address=start)
        self.assertEqual(parsed.size,8)
        self.assertEqual(verifier.assemble_candidate(block,start),rom[start-0x08000000:start-0x08000000+8])


if __name__=='__main__': unittest.main()
