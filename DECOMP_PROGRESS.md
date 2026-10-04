# 可复现结构审计进度

> 此文件由 `python3 tools/audit_structure.py --markdown-output DECOMP_PROGRESS.md` 生成。
> `--output` 只写 JSON，且会拒绝 Markdown 路径，避免误覆盖本报告。

## 当前快照

- 严格 C：10096/16023 (63.01%，保守可证下界)；naked 汇编地址：5578；strict/naked 交集：0。
- 源码函数体库存：非 naked 10106、naked 5588；地址已绑定 15674、未解析 20；指标证据状态：conservative_verified_lower_bound。
- inline 源码定义：5；对象证实无独立入口 5；其他未解析 15。这些是源码库存单位，不是 ROM 分母。
- 旧名称 fan-out 指标已失效；修正绑定导致计数下降属于测量纠错，不是反编译退步。排除 naked 前自然交集：旧 64、新 0。
- 模块归位：9409/10096 (93.20%)；路径对齐：9250/10096 (91.62%)；US 标准名仍为 funcmap 候选，并非语义复核结论。
- JP 路径独有 C 清单：164；无 US 标准函数 owner 的语义缺口模块：116（两种口径，不沿用旧固定数）；同一源同名多地址未解析定义：0。
- 过渡文件：tail=0、rest=3、mid=5、stub=0、address=0。
- incbin：7560 引用、7017 条唯一路径、原始二进制 996、非原始 6564、缺失资源 0；可见 baserom 范围 542 条/0x4B01C8 字节，未限定范围 0 条。
- 资产命名：4904 条 graphics/sound 引用中，精确 US 路径 35、唯一 basename 候选 18、歧义 0。
- 地图脚本：468/469 (99.79%) 个首 owner 有 scripts.inc；非 owner scripts.inc：0；结构完整地图：518（直接物理文件满足者 468；合法共享 scripts/events owner 50/11；其中首 owner 469）；map.json 总数：518。
- 地图语义复核：not_recorded。没有版本化复核清单前，任何 scripts.inc、map.json 或 events.inc 都不计入语义已审计。
- 三流地图会合：scripts 流 468、events 流 518、共有 468、地图头 518；事件指针状态 direct=507、shared=11；地图内裸 baserom 范围（脚本/事件/资源）=0/0/0。
- script_data 顶层边界：JP linker 明确 owner 8/US 8；待补 JP owner 0；可见 event_scripts 原始 baserom 范围 0。US 只定义 owner 顺序，JP 范围必须由 JP map/ROM 锚点确认。

## 指标定义

| 指标 | 口径 |
| --- | --- |
| 严格 C 转换率 | 默认分支有非 `naked` C 函数体，经 JP ELF 同名可执行符号与 JP linker 输入对象范围验证 owner 的唯一 funcmap 地址 / funcmap 唯一地址；同名 static 按 source owner 和地址保留，不建立名称→地址覆盖表。缺证保留 unresolved，因此仅为保守可证下界；没有 ELF 证据时百分比 unavailable，不报 0% 退步。 |
| 模块归位率 | 已证实 JP owner 的严格 C 地址中，funcmap US 标准名候选在 US 源树有定义的地址 / 严格 C 地址；不代表该候选已逐函数语义复核。 |
| 路径对齐率 | 上述地址中 JP 相对 `src/` 路径也属于 US owner 的地址 / 严格 C 地址。 |
| 过渡文件 | 文件名包含 tail、rest、mid、stub 或地址式片段；分类可重叠。 |
| incbin | `.incbin` 与 `INCBIN_*` 的引用数。裸 `.bin/.gba`、asset 根目录外的压缩流，以及 `gUnknown`/`unknown`/`unk` 命名的压缩资产记为原始；`graphics/`、`sound/` 内其余具名 `.lz/.rl/.huff` 记为已结构化编码资产。另列显式 `baserom_jp.gba, offset, size` 指令的可见字节和未限定范围数；该字节值不含无法判定范围的指令，不是总 ROM 转换率。 |
| 资产命名 | 被引用的 `graphics/`、`sound/` 路径与 US 同名文件比较；仅生成候选，不自动改名。 |
| 地图脚本 owner | `scripts.inc` 与 map-table 实际首 owner 名的交集 / 去重首 owner；共享表只属于首次出现地图。 |
| 地图结构完整 | 同一地图具 `map.json`，且其 scripts/events 为本地图的物理文件与上层 include，或为 map.json 明示、header 精确指向且在 JP `data/` 有真实标签定义的共享 owner；只说明结构已拆分。 |
| 地图语义复核 | 仅接受未来版本化复核清单的显式记录；当前为 `not_recorded`，绝不从目录或 include 推断。 |
| 三流地图会合 | 以 `data/event_scripts.s`、`data/map_events.s`（旧树回退 `data/data_b2d_mid26.s`）和 `data/maps.s` 的同图记录连接 scripts、events、地图头/布局/tileset。别名和 baserom 范围均为待办，不构成完成。 |
| script_data 顶层分区 | US linker 提供 8 个对象的目标 owner 顺序；JP linker map 提供实际范围和锚点。只在 JP 起止标签、末尾位置与 ROM 比对均成立时，才允许拆出一个 owner。 |
| JP 路径独有 C 清单 | JP src/**/*.c 路径与 US 的差集；包含零函数的文本/数据包装文件。独立于无 US 标准函数 owner 的语义缺口模块清单。 |
| 无 US 函数 owner 语义缺口清单 | 已证实 JP 地址绑定、非裸汇编、但无 US 标准 C owner 的函数模块；旧 jp_only_c_manifest 字段和 --manifest 保留此兼容口径，不是完整路径独有模块清单。 |

## 复现与输入

```sh
python3 tools/audit_structure.py
python3 tools/audit_structure.py --json --output build/audit-structure.json \
    --manifest build/jp-only-c-manifest.json
python3 tools/audit_structure.py --transition-manifest build/transition-file-manifest.json
python3 tools/audit_structure.py --jp-path-manifest build/jp-exclusive-c-paths.json
python3 tools/audit_structure.py --map-convergence-manifest build/map-convergence-manifest.json
python3 tools/audit_structure.py --script-data-manifest build/script-data-manifest.json
python3 tools/audit_structure.py --markdown-output DECOMP_PROGRESS.md
# 比较另一份 US 工程时显式指定其根目录
python3 tools/audit_structure.py --us-root /path/to/pokeemerald --markdown-output DECOMP_PROGRESS.md
```

源码库存、funcmap 和 incbin 清单不需要构建。函数地址指标读取匹配的 `pokeemerald_jp.elf` 与 `pokeemerald_jp.map`；输入 section 补证还读取对应 JP 对象的 STT_FUNC，libc 宏名称展开读取真实 include 链。JSON 记录这些输入 SHA-256、未解析原因和旧/新绑定诊断；缺失证据不按名字猜测。采样这些生成文件时须持有共享构建锁，避免 make clean 窗口。完整报告仍需要匹配的 `baserom_jp.gba` 来解析地图 owner；US 二进制符号统计使用指定 US 树的 `pokeemerald.sym`（若存在），资源存在性检查也依赖本地提取资源。

涉及源码或链接输入的变更须执行：

```sh
flock /tmp/pokeemerald-jp-build.lock bash -lc 'make clean && make -j16 && make compare'
```

只有末行 `pokeemerald_jp.gba: OK` 才可提交。
