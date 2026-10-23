"""Pacifidlog weekly TM, NPC trade and read-only Mirage Island checks."""
import json
from pathlib import Path
import unittest
try:
    import map_review_script_profile as profile
    import map_semantic_review as review
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review

ROOT = Path(__file__).resolve().parents[1]
MAPS = ['PacifidlogTown_PokemonCenter_1F','PacifidlogTown_PokemonCenter_2F','PacifidlogTown_House1',
        'PacifidlogTown_House2','PacifidlogTown_House3','PacifidlogTown_House4','PacifidlogTown_House5']
SIZES = [(9,237,3),(4,39,0),(5,193,2),(23,795,11),(12,547,6),(11,280,5),(7,182,3)]


def blocks(name):
    return review.label_blocks((ROOT/f'data/maps/{name}/scripts.inc').read_text())


def scene(name,suffix):
    return review.statements(blocks(name)[name+'_'+suffix])


class PacifidlogStoryTests(unittest.TestCase):
    def test_weekly_tm_checks_availability_before_friendship(self):
        lines = scene(MAPS[3],'EventScript_FanClubYoungerBrother')
        update = lines.index('call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag')
        self.assertEqual(lines[update+1],'goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays')
        score = 'specialvar VAR_RESULT, GetLeadMonFriendshipScore'
        self.assertEqual(lines.count(score),2)
        branches = [line for line in lines if line.startswith('goto_if_ge ')]
        self.assertEqual(branches,['goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturn',
                                  'goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort'])
        self.assertIn('goto PacifidlogTown_House2_EventScript_GiveFrustration',lines)

    def test_bag_full_cannot_mark_receipt_or_write_the_day(self):
        for suffix,item in (('GiveReturn','RETURN'),('GiveFrustration','FRUSTRATION')):
            lines = scene(MAPS[3],'EventScript_'+suffix)
            at = lines.index('giveitem ITEM_TM_'+item)
            self.assertEqual(lines[at+1],'goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull')
            self.assertGreater(lines.index('setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK'),at+1)
            self.assertGreater(lines.index('special SetPacifidlogTMReceivedDay'),at+1)

    def test_timer_uses_specialvar_and_a_real_zero_day_condition(self):
        lines = scene(MAPS[3],'EventScript_UpdateFanClubTMFlag')
        self.assertEqual(lines,['goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn',
            'specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable',
            'call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM','return'])
        remaining = scene(MAPS[3],'EventScript_ComeBackInXDays')
        self.assertEqual(remaining[:2],['specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable',
                                      'buffernumberstring STR_VAR_1, VAR_RESULT'])

    def test_trade_preserves_id_and_slot_across_the_party_ui(self):
        lines = scene(MAPS[4],'EventScript_Trader')
        self.assertIn('setvar VAR_0x8008, INGAME_TRADE_HORSEA',lines)
        choose = lines.index('special ChoosePartyMon')
        self.assertEqual(lines[choose+1:choose+3],['copyvar VAR_0x800A, VAR_0x8004',
            'goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PacifidlogTown_House3_EventScript_DeclineTrade'])
        create = lines.index('special CreateInGameTradePokemon')
        self.assertEqual(lines[create-2:create],['copyvar VAR_0x8004, VAR_0x8008','copyvar VAR_0x8005, VAR_0x800A'])
        self.assertIn('goto_if_ne VAR_RESULT, VAR_0x8009, PacifidlogTown_House3_EventScript_NotRequestedMon',lines)
        self.assertGreater(lines.index('setflag FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED'),lines.index('special DoInGameTradeScene'))
        waits = profile.special_waits(ROOT)
        self.assertEqual((waits['ChoosePartyMon'],waits['DoInGameTradeScene']), (1,1))

    def test_mirage_dialogue_queries_bool_not_weather(self):
        lines = scene(MAPS[6],'EventScript_MirageIslandWatcher')
        self.assertEqual(lines[2:4],['specialvar VAR_RESULT, IsMirageIslandPresent',
            'goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent'])
        weather = scene(MAPS[6],'EventScript_Gentleman')
        self.assertEqual(weather,['msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC','end'])

    def test_explosion_tutor_is_the_shared_event_root(self):
        data = json.loads((ROOT/f'data/maps/{MAPS[0]}/map.json').read_text())
        entry = MAPS[0]+'_EventScript_ExplosionTutor'
        self.assertEqual(data['object_events'][4]['script'],entry)
        source = review.label_blocks((ROOT/'data/scripts/move_tutors.inc').read_text())
        tutor = review.statements(source[entry])
        self.assertIn('setvar VAR_0x8005, TUTOR_MOVE_EXPLOSION',tutor)
        at = tutor.index('call MoveTutor_EventScript_OpenPartyMenu')
        self.assertEqual(tutor[at+1:at+3],['goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_ExplosionDeclined',
                                         'setflag FLAG_MOVE_TUTOR_TAUGHT_EXPLOSION'])

    def test_house_layouts_are_shared_without_fabricated_map_named_copies(self):
        for name,owner in ((MAPS[2],'PacifidlogTown_House1'),(MAPS[3],'PacifidlogTown_House2'),
                           (MAPS[4],'PacifidlogTown_House1'),(MAPS[5],'PacifidlogTown_House2'),
                           (MAPS[6],'PacifidlogTown_House1')):
            layout = review.default_layout_owner(ROOT,name,allow_shared=True)
            self.assertEqual(layout['name'],owner+'_Layout')


class PacifidlogNativeTests(unittest.TestCase):
    def test_family_pins_the_raw_trade_dependency_without_calling_it_decompiled(self):
        rows = json.loads((ROOT/review.MANIFEST_PATH).read_text())['batches']
        selected = [row for row in rows if row['id']=='PacifidlogInteriors_story_review_20261023']
        self.assertEqual(len(selected),1)
        self.assertEqual(selected[0]['maps'],MAPS)
        paths = {s['path'] for s in selected[0]['sources'] if s['selector']=='file'}
        self.assertTrue({'src/trade.c','src/data/trade.h','include/constants/trade.h',
                         'graphics/trade/jp/animation/830d114.bin'} <= paths)

    @unittest.skipUnless((ROOT/'pokeemerald_jp.elf').is_file(),'requires native artifacts')
    def test_all_seven_owners_have_exact_native_extent_and_no_invented_fallthrough(self):
        symbols,_ = review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes())
        for name,(labels,size,texts) in zip(MAPS,SIZES):
            values = symbols[name+'_MapScripts']
            self.assertEqual(len(values),1)
            parts = profile.profile_owner(ROOT,(ROOT/f'data/maps/{name}/scripts.inc').read_text(),
                                          version=4,address=next(iter(values)))
            self.assertEqual((len(parts),sum(p.size for p in parts.values()),sum(p.kind=='string' for p in parts.values())),
                             (labels,size,texts))
            self.assertFalse(any(p.may_fall_through for p in parts.values()))

    @unittest.skipUnless((ROOT/'pokeemerald_jp.elf').is_file(),'requires native artifacts')
    def test_jp_trade_species_fields_match_rom_elf_and_the_actual_getter(self):
        symbols,memory = review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes())
        def address(label):
            self.assertEqual(len(symbols[label]),1)
            return next(iter(symbols[label])) & ~1
        def payload(start,size):
            spans = [data[start-base:start-base+size] for base,data in memory
                     if base<=start and start+size<=base+len(data)]
            self.assertEqual(len(spans),1)
            return spans[0]
        table = (ROOT/'graphics/trade/jp/animation/830d114.bin').read_bytes()
        base = address('gUnknown_830D114')
        self.assertEqual(len(table),4*0x3C)
        self.assertEqual(payload(base,len(table)),table)
        rom = (ROOT/'baserom_jp.gba').read_bytes()
        self.assertEqual(rom[base-0x08000000:base-0x08000000+len(table)],table)
        index = review._literal_define(ROOT,'include/constants/trade.h','INGAME_TRADE_HORSEA')
        self.assertEqual(index,2)
        self.assertEqual(int.from_bytes(table[index*0x3C+12:index*0x3C+14],'little'),
                         review._literal_define(ROOT,'include/constants/species.h','SPECIES_HORSEA'))
        self.assertEqual(int.from_bytes(table[index*0x3C+56:index*0x3C+58],'little'),
                         review._literal_define(ROOT,'include/constants/species.h','SPECIES_BAGON'))
        code = payload(address('GetInGameTradeSpeciesInfo'),0x50)
        # JP instructions compute (tradeId*16-tradeId)*4 and load fields+56/+12.
        self.assertIn(bytes.fromhex('0401241aa400'),code)
        self.assertIn(bytes.fromhex('228f'),code)
        self.assertIn(bytes.fromhex('a289'),code)
        self.assertIn(base.to_bytes(4,'little'),code)


if __name__=='__main__':
    unittest.main()
