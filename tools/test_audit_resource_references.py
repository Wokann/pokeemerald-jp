#!/usr/bin/env python3
"""Resource occurrence/unique-path and fail-closed preprocessing fixtures."""
from pathlib import Path
import tempfile
import unittest

from audit_resource_references import collect_resource_references as collect
import audit_structure as audit

TEMPLATE = ('#define RESOURCE(symbol, size, path) ' + chr(92) + '\n'
            '    const u8 symbol[size] RESOURCE_DATA = INCBIN_U8(path)\n')


class ResourceReferenceTests(unittest.TestCase):
    def one(self, text, **kwargs):
        return collect({'src/fixture.h': text}, **kwargs)

    def paths(self, result):
        return [row['resource'] for row in result['references']]

    def reasons(self, result):
        return {row['reason'] for row in result['unresolved']}

    def report(self, sources):
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            for owner, text in sources.items():
                path = root / owner
                path.parent.mkdir(parents=True, exist_ok=True)
                path.write_text(text, encoding='utf-8')
            return audit.incbin_progress(root)

    def test_historical_pokedex_fourteen_forwarded_paths(self):
        paths = [f'data/pokedex/jp/search_data_{i:02}.bin' for i in range(13)]
        paths.append('data/pokedex/jp/search_type_ids.bin')
        source = TEMPLATE.replace('RESOURCE', 'POKEDEX_MID55_RESOURCE')
        source += ''.join(f'POKEDEX_MID55_RESOURCE(s{i}, 4, "{p}");\n' for i, p in enumerate(paths))
        result = self.report({'src/data/pokedex.h': source})
        self.assertEqual(result['references'], 14)
        self.assertEqual(result['unique_paths'], 14)
        self.assertEqual(result['raw_binary_references'], 14)
        self.assertEqual(result['unresolved_resource_references'], 0)

    def test_four_real_template_shapes_without_name_allowlist(self):
        sources = {}
        for family, raw_count, named_unique, named_repeats in [
                ('TRAINER_CARD_MID55_RESOURCE', 18, 23, 0),
                ('FRONTIER_PASS_MID56_RESOURCE', 18, 19, 0),
                ('POKEMON_STORAGE_MID56_RESOURCE', 3, 0, 0),
                ('POKEMON_STORAGE_MID57A_RESOURCE', 41, 160, 14)]:
            paths = [f'data/{family}/r{i}.bin' for i in range(raw_count)]
            paths += [f'graphics/{family}/g{i}.4bpp.lz' for i in range(named_unique)]
            paths += [f'graphics/{family}/g{i}.4bpp.lz' for i in range(named_repeats)]
            text = TEMPLATE.replace('RESOURCE', family)
            text += ''.join(f'{family}(s{i}, 4, "{p}");\n' for i, p in enumerate(paths))
            sources[f'src/data/{family}.h'] = text
        result = self.report(sources)
        self.assertEqual(result['references'], 296)
        self.assertEqual(result['unique_paths'], 282)
        self.assertEqual(result['raw_binary_references'], 80)
        self.assertEqual(result['non_raw_references'], 216)
        self.assertEqual(result['unresolved_resource_references'], 0)

    def test_arbitrary_template_name_and_parameter_order(self):
        text = '#define BYTES(file, type, name, count) const type name[count] TAG = INCBIN_U16(file)\n'
        text += 'BYTES("data/good.bin", u16, sData, sizeof(PAIR(1,2)));\n'
        result = self.one(text)
        self.assertEqual(self.paths(result), ['data/good.bin'])
        self.assertEqual(result['references'][0]['macro_trace'][0]['name'], 'BYTES')

    def test_single_line_all_variadic_files(self):
        result = self.one('const u8 data[]=INCBIN_U8("a.4bpp", "b.4bpp");')
        self.assertEqual(self.paths(result), ['a.4bpp', 'b.4bpp'])

    def test_multiline_all_variadic_files_and_comments(self):
        result = self.one('INCBIN_U16(\n "a.bin", /* not a path */\n "b.bin",\n "c.bin")\n')
        self.assertEqual(self.paths(result), ['a.bin', 'b.bin', 'c.bin'])
        self.assertTrue(all(r['line'] == 1 for r in result['references']))

    def test_repeated_path_occurrences_not_deduplicated(self):
        result = self.report({'src/a.c': 'INCBIN_U8("a.bin", "a.bin")\nINCBIN_U8("a.bin")\n'})
        self.assertEqual(result['references'], 3)
        self.assertEqual(result['unique_paths'], 1)

    def test_definitions_are_templates_not_occurrences(self):
        result = self.one(TEMPLATE + '#define UNUSED(path) INCBIN_U8("literal-but-unused.bin")\n')
        self.assertEqual(self.paths(result), [])
        self.assertEqual(result['unresolved'], [])

    def test_comments_and_quoted_macro_spellings_are_not_calls(self):
        source = '// INCBIN_U8("not.bin")\n/* INCBIN_U16("not2.bin") */\n'
        source += 'const char *s = "INCBIN_U8(\\\"not3.bin\\\")";\n'
        self.assertEqual(self.paths(self.one(source)), [])
        self.assertEqual(self.paths(collect({'data/a.s': '@ .incbin "not4.bin"\n'})), [])

    def test_nested_size_expression_and_quoted_comma(self):
        result = self.one(TEMPLATE + 'RESOURCE(s, COUNT(1, 2), "data/a,b.bin");\n')
        self.assertEqual(self.paths(result), ['data/a,b.bin'])

    def test_dynamic_path_explicitly_unresolved(self):
        result = self.one(TEMPLATE + 'RESOURCE(s, 4, PATH_FROM_CONFIG);\n')
        self.assertEqual(self.paths(result), [])
        self.assertIn('nonliteral_incbin_path', self.reasons(result))
        self.assertEqual(result['unresolved'][0]['expression'], 'PATH_FROM_CONFIG')
        self.assertEqual(result['unresolved'][0]['macro_trace'][0]['name'], 'RESOURCE')

    def test_indirection_is_unresolved_not_guessed(self):
        source = TEMPLATE + '#define OUTER(s,n,p) RESOURCE(s,n,p)\nOUTER(s,4,"a.bin");\n'
        result = self.one(source)
        self.assertEqual(self.paths(result), [])
        self.assertIn('unsupported_resource_indirection', self.reasons(result))

    def test_macro_cycle_is_bounded_and_diagnostic(self):
        source = '#define A(p) B(p)\n#define B(p) A(p) + INCBIN_U8(p)\nA("a.bin");\n'
        result = self.one(source)
        self.assertEqual(self.paths(result), [])
        self.assertIn('macro_cycle', self.reasons(result))
        self.assertEqual([item['name'] for item in result['unresolved'][0]['macro_trace']], ['A', 'B', 'A'])

    def test_macro_depth_limit_is_explicit(self):
        source = ''.join(f'#define M{i}(p) M{i+1}(p)\n' for i in range(20))
        source += '#define M20(p) INCBIN_U8(p)\nM0("a.bin");\n'
        result = self.one(source, max_macro_depth=4)
        self.assertIn('macro_depth_limit', self.reasons(result))

    def test_stringification_and_token_paste_are_unresolved(self):
        for argument in ['"data/" #p ".bin"', 'p ## suffix']:
            result = self.one(f'#define RES(p) INCBIN_U8({argument})\nRES(a);\n')
            self.assertEqual(self.paths(result), [])
            self.assertIn('unsupported_macro_stringification_or_paste', self.reasons(result))

    def test_redefinition_and_undef_are_ordered(self):
        source = '#define RES(p) INCBIN_U8(p)\nRES("a.bin");\n#undef RES\nRES("unknown.bin");\n'
        source += '#define RES(ignored, path) INCBIN_U16(path)\nRES(x, "b.bin");\n'
        result = self.one(source)
        self.assertEqual(self.paths(result), ['a.bin', 'b.bin'])
        self.assertIn('resource_macro_binding_unavailable', self.reasons(result))

    def test_same_names_in_distinct_files_do_not_overwrite(self):
        sources = {
            'src/a.h': '#define RES(path,n) INCBIN_U8(path)\nRES("a.bin",1);\n',
            'src/b.h': '#define RES(n,path) INCBIN_U8(path)\nRES(1,"b.bin");\n',
        }
        self.assertEqual(self.paths(collect(sources)), ['a.bin', 'b.bin'])

    def test_other_file_cycles_do_not_poison_local_direct_template(self):
        sources = {
            'src/a.h': '#define A(p) INCBIN_U8(p)\nA("good.bin");\n',
            'src/b.h': '#define A(p) B(p)\n#define B(p) A(p)+INCBIN_U8(p)\nA("bad.bin");\n',
        }
        result = collect(sources)
        self.assertEqual(self.paths(result), ['good.bin'])
        self.assertIn('macro_cycle', self.reasons(result))

    def test_nonresource_local_macro_is_not_poisoned_by_same_name(self):
        result = collect({
            'src/a.h': '#define RES(x) ((x)+1)\nRES(3);\n',
            'src/b.h': '#define RES(p) INCBIN_U8(p)\nRES("good.bin");\n',
        })
        self.assertEqual(self.paths(result), ['good.bin'])
        self.assertEqual(result['unresolved'], [])

    def test_header_is_counted_once_not_per_including_translation_unit(self):
        sources = {
            'src/data/shared.h': '#ifndef GUARD_SHARED_H\n#define GUARD_SHARED_H\n' + TEMPLATE + 'RESOURCE(s,4,"a.bin");\n#endif\n',
            'src/a.c': '#include "data/shared.h"\n',
            'src/b.c': '#include "data/shared.h"\n',
        }
        result = collect(sources)
        self.assertEqual(self.paths(result), ['a.bin'])
        self.assertEqual(result['unresolved'], [])

    def test_include_scope_not_silently_guessed(self):
        result = collect({'src/a.c': '#include "res.h"\nRESOURCE(s,4,"a.bin");\n'},
                         support_sources={'include/res.h': TEMPLATE})
        self.assertEqual(self.paths(result), [])
        self.assertIn('resource_macro_binding_unavailable', self.reasons(result))

    def test_explicit_unknown_resource_macro_has_a_diagnostic(self):
        result = self.one('UNAVAILABLE(s,4,"a.bin");\n', candidate_macros={'UNAVAILABLE'})
        self.assertEqual(self.paths(result), [])
        self.assertIn('resource_macro_binding_unavailable', self.reasons(result))

    def test_gas_template_interpolation_is_not_a_literal_asset(self):
        result = collect({'data/a.s': '.macro LOAD path\n.incbin "\\path"\n.endm\nLOAD "asset.bin"\n'})
        self.assertEqual(self.paths(result), [])
        self.assertEqual(self.reasons(result), {'unsupported_gas_resource_template', 'unsupported_gas_resource_invocation'})

    def test_direct_assembly_resource_and_range_are_one_reference(self):
        result = self.one('.incbin "baserom_jp.gba", 0x10, 0x20\n')
        self.assertEqual(self.paths(result), ['baserom_jp.gba'])
        self.assertEqual(result['references'][0]['syntax'], 'asm_incbin')

    def test_baserom_range_manifest_excludes_templates_and_comments(self):
        source = ('.macro RAW\n.incbin "baserom_jp.gba", 0, 4\n.endm\n'
                  '/*\n.incbin "baserom_jp.gba", 4, 4\n*/\n'
                  '.incbin "baserom_jp.gba", 8, 4\n')
        report = self.report({'data/raw.s': source})
        self.assertEqual(report['references'], 1)
        self.assertEqual(report['raw_baserom_visible_range_references'], 1)
        self.assertEqual(report['raw_baserom_visible_bytes'], 4)
        self.assertEqual(report['raw_baserom_manifest'][0]['file_offset'], '0x8')

    def test_named_asset_incgfx_is_separate_and_context_unresolved(self):
        report = audit.named_asset_progress({'asset': 'INCGFX_U8("a.png", ".4bpp")'}, 'asset')
        self.assertEqual(report['source_count'], 0)
        self.assertEqual(report['incgfx_source_count'], 1)
        self.assertEqual(report['status'], 'unresolved_source')

    def test_gas_parameter_outside_template_is_unresolved(self):
        result = collect({'data/a.s': '.incbin "\\file"\n'})
        self.assertEqual(self.paths(result), [])
        self.assertIn('nonliteral_assembly_incbin_path', self.reasons(result))

    def test_assembly_does_not_steal_a_path_from_the_following_line(self):
        result = collect({'data/a.s': '.incbin\n.string "not-an-asset.bin"\n'})
        self.assertEqual(self.paths(result), [])
        self.assertIn('missing_assembly_path_on_line', self.reasons(result))

    def test_inline_assembly_resource_is_explicitly_unsupported(self):
        direct = '__asm__(".incbin \\\"a.bin\\\"\\n");\n'
        result = self.one(direct)
        self.assertEqual(self.paths(result), [])
        self.assertIn('unsupported_inline_assembly_resource', self.reasons(result))
        result = self.one('#define RES() ' + direct + 'RES();\n')
        self.assertEqual(self.paths(result), [])
        self.assertIn('unsupported_inline_assembly_resource', self.reasons(result))

    def test_both_conditional_source_branches_are_visible_and_marked(self):
        result = self.one('#if FEATURE\nINCBIN_U8("a.bin")\n#else\nINCBIN_U8("b.bin")\n#endif\n')
        self.assertEqual(self.paths(result), ['a.bin', 'b.bin'])
        self.assertEqual(len(result['unresolved']), 2)
        self.assertEqual(self.reasons(result), {'conditional_emission_not_selected'})
        self.assertTrue(all(r['conditions'] for r in result['references']))

    def test_conditional_macro_binding_not_selected(self):
        source = '#if FEATURE\n#define RES(p) INCBIN_U8(p)\n#else\n#define RES(p) INCBIN_U16(p)\n#endif\nRES("a.bin");\n'
        result = self.one(source)
        self.assertEqual(self.paths(result), [])
        self.assertIn('conditional_macro_binding', self.reasons(result))

    def test_incgfx_source_and_generated_identity_are_separate(self):
        result = self.one('INCGFX_U8("g.png", ".4bpp", "-mwidth 2")\nINCGFX_U8("g.png", ".4bpp", "-mwidth 4")\n', graphics_root='build/')
        self.assertEqual(self.paths(result), [])
        self.assertEqual(len(result['incgfx']), 2)
        self.assertEqual({r['source_asset'] for r in result['incgfx']}, {'g.png'})
        self.assertEqual({r['generated_path'] for r in result['incgfx']}, {'build/g.png_mwidth_2.4bpp', 'build/g.png_mwidth_4.4bpp'})
        self.assertEqual(result['incgfx_unresolved'], [])

    def test_incgfx_unknown_root_is_symbolic_not_guessed(self):
        result = self.one('INCGFX_U8("g.png", ".4bpp")\n')
        self.assertEqual(result['incgfx'][0]['generated_tail'], 'g.png.4bpp')
        self.assertIsNone(result['incgfx'][0]['generated_path'])
        self.assertEqual(result['incgfx_unresolved'][0]['reason'], 'graphics_root_unspecified')

    def test_incgfx_dynamic_options_are_unresolved(self):
        result = self.one('INCGFX_U8("g.png", ".4bpp", OPTIONS)\n')
        self.assertEqual(result['incgfx'], [])
        self.assertEqual(result['incgfx_unresolved'][0]['reason'], 'nonliteral_incgfx_argument')

    def test_incgfx_non_ascii_option_normalization_not_guessed(self):
        result = self.one('INCGFX_U8("g.png", ".4bpp", "--name 日本")\n')
        self.assertEqual(result['incgfx'], [])
        self.assertEqual(result['incgfx_unresolved'][0]['reason'], 'unverified_incgfx_option_encoding')

    def test_wrapper_can_forward_incgfx_without_counting_as_incbin(self):
        source = '#define DRAW(s,n,p) const u8 s[n] ATTR = INCGFX_U8(p,".4bpp")\nDRAW(s,4,"g.png");\n'
        result = self.one(source, graphics_root='')
        self.assertEqual(self.paths(result), [])
        self.assertEqual(result['incgfx'][0]['generated_path'], 'g.png.4bpp')

    def test_unsupported_object_macro_usage_is_not_silent(self):
        result = self.one('#define RES INCBIN_U8("a.bin")\nconst u8 s[] = RES;\n')
        self.assertEqual(self.paths(result), [])
        self.assertIn('unsupported_object_resource_macro', self.reasons(result))

    def test_unsupported_variadic_template_is_unresolved(self):
        result = self.one('#define RES(...) INCBIN_U8(__VA_ARGS__)\nRES("a.bin");\n')
        self.assertIn('unsupported_variadic_resource_template', self.reasons(result))

    def test_adjacent_literals_and_unknown_primitive_are_unresolved(self):
        result = self.one('INCBIN_U8("data/" "a.bin")\nINCBIN_F32("b.bin")\n')
        self.assertEqual(self.paths(result), [])
        self.assertEqual(self.reasons(result), {'nonliteral_incbin_path', 'unsupported_incbin_type'})

    def test_macro_arity_and_unclosed_invocation_are_explicit(self):
        result = self.one(TEMPLATE + 'RESOURCE(s, "a.bin");\nINCBIN_U8("b.bin"\n')
        self.assertEqual(self.paths(result), [])
        self.assertEqual(self.reasons(result), {'resource_macro_arity', 'unclosed_resource_invocation'})

    def test_local_primitive_define_and_undef_are_not_bypassed(self):
        cases = [('#define INCBIN_U8(p) replacement(p)\n', 'locally_redefined_resource_primitive'),
                 ('#undef INCBIN_U8\n', 'locally_undefined_resource_primitive')]
        for prefix, reason in cases:
            result = self.one(prefix + 'INCBIN_U8("a.bin");\n')
            self.assertEqual(self.paths(result), [])
            self.assertIn(reason, self.reasons(result))

    def test_conditional_primitive_binding_is_not_bypassed(self):
        source = '#if FEATURE\n#define INCBIN_U8(p) OTHER(p)\n#endif\nINCBIN_U8("a.bin");\n'
        result = self.one(source)
        self.assertEqual(self.paths(result), [])
        self.assertIn('conditional_resource_primitive_binding', self.reasons(result))

    def test_template_leaf_obeys_local_primitive_binding(self):
        result = self.one(TEMPLATE + '#undef INCBIN_U8\nRESOURCE(s,4,"a.bin");\n')
        self.assertEqual(self.paths(result), [])
        self.assertIn('locally_undefined_resource_primitive', self.reasons(result))

    def test_later_primitive_override_does_not_change_earlier_call(self):
        result = self.one('INCBIN_U8("good.bin");\n#define INCBIN_U8(p) replacement(p)\nINCBIN_U8("unknown.bin");\n')
        self.assertEqual(self.paths(result), ['good.bin'])
        self.assertIn('locally_redefined_resource_primitive', self.reasons(result))

    def test_gas_conditions_are_visible_and_not_claimed_unconditional(self):
        source = ('.if FEATURE\n.incbin "a.bin"\n.ifdef OTHER\n.incbin "b.bin"\n.endif\n'
                  '.else\n.incbin "c.bin"\n.endif\n.incbin "d.bin"\n'
                  '.ifc X,Y\n.incbin "e.bin"\n.endif\n')
        result = collect({'data/conditional.s': source})
        self.assertEqual(self.paths(result), ['a.bin', 'b.bin', 'c.bin', 'd.bin', 'e.bin'])
        self.assertEqual([bool(r['conditions']) for r in result['references']], [True, True, True, False, True])
        self.assertEqual(len(result['references'][1]['conditions']), 2)
        self.assertEqual(len(result['unresolved']), 4)
        self.assertEqual(self.reasons(result), {'conditional_emission_not_selected'})

    def test_cpp_and_gas_conditional_contexts_do_not_erase_each_other(self):
        source = '#if CPP_FEATURE\n.if GAS_FEATURE\n.incbin "a.bin"\n.endif\n.incbin "b.bin"\n#endif\n.incbin "c.bin"\n'
        result = collect({'data/mixed.s': source})
        self.assertEqual(self.paths(result), ['a.bin', 'b.bin', 'c.bin'])
        self.assertEqual([len(r['conditions']) for r in result['references']], [2, 1, 0])
        self.assertEqual(len(result['unresolved']), 2)

    def test_compound_prefix_is_not_assumed_a_direct_initializer(self):
        result = self.one('#define RES(p) maybe_emit() + INCBIN_U8(p)\nRES("a.bin");\n')
        self.assertEqual(self.paths(result), [])
        self.assertIn('unsupported_resource_template_shape', self.reasons(result))

    def test_named_asset_progress_reuses_multiline_collector(self):
        report = audit.named_asset_progress({'asset': 'INCBIN_U8(\n"a.bin", "b.bin")\n'}, 'asset')
        self.assertEqual(report['source_count'], 2)
        self.assertEqual(report['unresolved_source_count'], 0)

    def test_named_asset_progress_does_not_hide_unsupported_gas_source(self):
        block = '.macro LOAD path\n.incbin "\\path"\n.endm\nLOAD "a.bin"\n'
        report = audit.named_asset_progress({'asset': block}, 'asset')
        self.assertEqual(report['source_count'], 0)
        self.assertEqual(report['status'], 'unresolved_source')
        self.assertGreater(report['unresolved_source_count'], 0)


if __name__ == '__main__':
    unittest.main()
