# 可复现结构审计进度

> 此文件由 `python3 tools/audit_structure.py --markdown-output DECOMP_PROGRESS.md` 生成。
> `--output` 只写 JSON，且会拒绝 Markdown 路径，避免误覆盖本报告。

## 当前快照

- 严格 C：8424/16023 (52.57%)；naked 汇编地址：4469；strict/naked 交集：0。
- 模块归位：8187/8424 (97.19%)；路径对齐：8136/8424 (96.58%)。
- JP 独有 C 迁移记录：47（动态清单，不沿用旧固定数）；同名多地址 C 定义：271。
- 过渡文件：tail=0、rest=4、mid=18、stub=0、address=0。
- incbin：7601 引用、6672 条唯一路径、原始二进制 5659、非原始 1942、缺失资源 0。
- 资产命名：4841 条 graphics/sound 引用中，精确 US 路径 29、唯一 basename 候选 18、歧义 0。
- 地图脚本：468/469 (99.79%) 个首 owner 有 scripts.inc；非 owner scripts.inc：0；结构完整地图：518（直接物理文件满足者 468；合法共享 scripts/events owner 50/11；其中首 owner 469）；map.json 总数：518。
- 地图语义复核：not_recorded。没有版本化复核清单前，任何 scripts.inc、map.json 或 events.inc 都不计入语义已审计。
- 三流地图会合：scripts 流 468、events 流 507、共有 468、地图头 518；事件指针状态 direct=507、shared=11；地图内裸 baserom 范围（脚本/事件/资源）=0/0/0。
- script_data 顶层边界：JP linker 明确 owner 8/US 8；待补 JP owner 0；可见 event_scripts 原始 baserom 范围 0。US 只定义 owner 顺序，JP 范围必须由 JP map/ROM 锚点确认。

## 指标定义

| 指标 | 口径 |
| --- | --- |
| 严格 C 转换率 | 默认预处理分支中有 C 函数体、非 `naked` 且不与 selected naked 定义重叠的唯一 funcmap ROM 地址 / funcmap 唯一地址；同名 static 按 source owner 和地址保留，不建立名称→地址覆盖表。 |
| 模块归位率 | 严格 C 地址中能按 US 标准名在 US 源树找到定义的地址 / 严格 C 地址。 |
| 路径对齐率 | 上述地址中 JP 相对 `src/` 路径也属于 US owner 的地址 / 严格 C 地址。 |
| 过渡文件 | 文件名包含 tail、rest、mid、stub 或地址式片段；分类可重叠。 |
| incbin | `.incbin` 与 `INCBIN_*` 的引用数，按原始二进制和结构化/编码后缀分组；不是字节转换率。 |
| 资产命名 | 被引用的 `graphics/`、`sound/` 路径与 US 同名文件比较；仅生成候选，不自动改名。 |
| 地图脚本 owner | `scripts.inc` 与 map-table 实际首 owner 名的交集 / 去重首 owner；共享表只属于首次出现地图。 |
| 地图结构完整 | 同一地图具 `map.json`，且其 scripts/events 为本地图的物理文件与上层 include，或为 map.json 明示、header 精确指向且在 JP `data/` 有真实标签定义的共享 owner；只说明结构已拆分。 |
| 地图语义复核 | 仅接受未来版本化复核清单的显式记录；当前为 `not_recorded`，绝不从目录或 include 推断。 |
| 三流地图会合 | 以 `data/event_scripts.s`、`data/data_b2d_mid26.s`、`data/maps.s` 的同图记录连接 scripts、events、地图头/布局/tileset。别名和 baserom 范围均为待办，不构成完成。 |
| script_data 顶层分区 | US linker 提供 8 个对象的目标 owner 顺序；JP linker map 提供实际范围和锚点。只在 JP 起止标签、末尾位置与 ROM 比对均成立时，才允许拆出一个 owner。 |
| JP 独有 C 迁移清单 | 已映射、非裸汇编、但无 US 标准 C owner 的函数模块；动态分类，不沿用失效的固定“38 个”计数。 |

## 复现与输入

```sh
python3 tools/audit_structure.py
python3 tools/audit_structure.py --json --output build/audit-structure.json \
    --manifest build/jp-only-c-manifest.json
python3 tools/audit_structure.py --transition-manifest build/transition-file-manifest.json
python3 tools/audit_structure.py --map-convergence-manifest build/map-convergence-manifest.json
python3 tools/audit_structure.py --script-data-manifest build/script-data-manifest.json
python3 tools/audit_structure.py --markdown-output DECOMP_PROGRESS.md
# 比较另一份 US 工程时显式指定其根目录
python3 tools/audit_structure.py --us-root /path/to/pokeemerald --markdown-output DECOMP_PROGRESS.md
```

源文件、funcmap 和 incbin 清单不读取 `build/`。完整报告仍需要匹配的 `baserom_jp.gba` 来解析地图 owner；US 二进制符号统计使用指定 US 树的 `pokeemerald.sym`（若存在），资源存在性检查也依赖本地提取资源。

涉及源码或链接输入的变更须执行：

```sh
flock /tmp/pokeemerald-jp-build.lock bash -lc 'make clean && make -j16 && make compare'
```

只有末行 `pokeemerald_jp.gba: OK` 才可提交。
