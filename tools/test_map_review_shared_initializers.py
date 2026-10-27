"""The native standard-message/reset boundary is distinct from map completion."""
from pathlib import Path
import re
import struct
import subprocess
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
BERRY_OWNER = 'EventScript_ResetAllBerries'
PHONE_OWNER = 'Std_MsgboxPokenav'
BERRY = ('setberrytree BERRY_TREE_ROUTE_102_ORAN, '
         'ITEM_TO_BERRY(ITEM_ORAN_BERRY), BERRY_STAGE_BERRIES')


class SharedInitializerProfileTests(unittest.TestCase):
    def parse(self, body, owner='Entry', version=4):
        return profile.profile_block(ROOT, owner+'::\n'+body, version=version, address=0x082423E0)

    def test_indirect_phone_text_is_only_accepted_by_its_actual_standard_owner(self):
        result=self.parse('pokenavcall NULL\nwaitmessage\nreturn',PHONE_OWNER)
        self.assertEqual((result.size,result.texts,result.targets),(7,{},{}))
        for owner in ('Entry','Std_MsgboxDefault','Other_Std_MsgboxPokenav'):
            with self.subTest(owner=owner),self.assertRaises(ValueError):
                self.parse('pokenavcall NULL\nreturn',owner)
        for operand in ('0','NULL, 0'):
            with self.subTest(operand=operand),self.assertRaises(ValueError):
                self.parse('pokenavcall '+operand+'\nreturn',PHONE_OWNER)
        result=self.parse('pokenavcall Text_Direct\nreturn')
        self.assertEqual(result.texts,{'Text_Direct':'string'})

    def test_initial_tree_requires_real_tree_berry_stage_and_reset_owner(self):
        self.assertEqual(self.parse(BERRY+'\nreturn',BERRY_OWNER).size,5)
        for body in (BERRY.replace('ITEM_ORAN_BERRY','ITEM_POTION'),
                     BERRY.replace('ITEM_ORAN_BERRY','ITEM_NOT_A_REAL_BERRY'),
                     BERRY.replace('BERRY_TREE_ROUTE_102_ORAN','BERRY_TREE_ROUTE_UNKNOWN'),
                     BERRY.replace('BERRY_STAGE_BERRIES','BERRY_STAGE_EMPTY'),
                     BERRY.replace('ITEM_TO_BERRY(ITEM_ORAN_BERRY)','ITEM_ORAN_BERRY'),BERRY+', 0'):
            with self.subTest(body=body),self.assertRaises(ValueError): self.parse(body+'\nreturn',BERRY_OWNER)
        with self.assertRaises(ValueError): self.parse(BERRY+'\nreturn')

    def test_legacy_profiles_still_reject_both_new_forms(self):
        for body,owner in ((BERRY+'\nreturn',BERRY_OWNER),('pokenavcall NULL\nreturn',PHONE_OWNER)):
            with self.subTest(body=body),self.assertRaises(ValueError): self.parse(body,owner,3)

    @unittest.skipUnless((ROOT/'tools/preproc/preproc').is_file(),'requires native tools')
    def test_forms_match_fresh_macro_and_assembler_widths(self):
        native_forms.StoryProfileTests().check_native_forms([BERRY,'pokenavcall NULL'],version=4,
            source_owners={BERRY:BERRY_OWNER,'pokenavcall NULL':PHONE_OWNER})

    @unittest.skipUnless((ROOT/'pokeemerald_jp.elf').is_file(),'requires native ROM artifacts')
    def test_all_four_complete_shared_files_match_native_rom_and_us_order(self):
        native,_=review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes())
        rom=(ROOT/'baserom_jp.gba').read_bytes()
        names=('std_msgbox','trainer_battle','new_game','hall_of_fame')
        totals=[]
        for name in names:
            path='data/scripts/'+name+'.inc'
            source=(ROOT/path).read_text()
            blocks=review.label_blocks(source)
            us=review.label_blocks(subprocess.check_output(['git','--no-replace-objects','-C',
                '/home/kenny/pokeemerald','show','731ad5bfd6e6f265508d0efcca0ba42f9dcf5881:'+path],text=True))
            self.assertEqual(list(blocks),list(us),name)
            canonical=lambda block:[re.sub(r'\s*,\s*',',',s) for s in review.statements(block)]
            self.assertEqual([canonical(b) for b in blocks.values()],[canonical(b) for b in us.values()],name)
            start=next(iter(native[next(iter(blocks))]))
            parsed=profile.profile_owner(ROOT,source,version=4,address=start)
            size=sum(b.size for b in parsed.values())
            self.assertEqual(verifier.assemble_candidate(source,start),rom[start-0x08000000:start-0x08000000+size],name)
            totals.append((len(parsed),size))
        self.assertEqual(totals[:3],[(8,63),(19,329),(2,804)])
        table=next(iter(native['gStdScripts']))-0x08000000
        self.assertEqual(struct.unpack_from('<I',rom,table+10*4)[0],next(iter(native[PHONE_OWNER])))
        berries=review.statements(review.label_blocks((ROOT/'data/scripts/new_game.inc').read_text())[BERRY_OWNER])
        self.assertEqual(len([s for s in berries if s.startswith('setberrytree ')]),80)


if __name__=='__main__': unittest.main()
