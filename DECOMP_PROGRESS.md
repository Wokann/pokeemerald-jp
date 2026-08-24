# 可复现结构审计口径

本仓库的进度不使用单一百分比。`src/` 中的对象可能含有
`__attribute__((naked))` 内联汇编，也可能为了 ROM 链接顺序暂时保留
`*_mid`、`*_tail` 等分段名称；将它们一概计作“C 已完成”会掩盖真实的
转换与归位工作。

统一入口：

```sh
python3 tools/audit_structure.py
python3 tools/audit_structure.py --json --output build/audit-structure.json \\
    --manifest build/jp-only-c-manifest.json
```

文件、函数与 incbin 指标读取受版本控制的源目录（`src/`、`asm/`、`data/`，
其中包含 `.h`）和 `funcmap_jp.txt`，不读取 `build/`。这不意味着完整报告
不依赖本地输入：地图 owner 指标有意通过 map emitter 解析匹配的
`baserom_jp.gba`，US 二进制符号统计会读取指定 US 树的 `pokeemerald.sym`（若
存在），而 incbin 的存在性还会检查未跟踪的提取资源。因此完整报告只在同一
提交、同一明确指定的 `--us-root`、匹配 JP 基础 ROM 和相同资源集下可复现。
审计会临时把 emitter 的 US map JSON 指向 `--us-root/data/maps/map_groups.json`，
不会让其硬编码默认 US 路径绕过此参数。

`funcmap_jp.txt` 支持普通三列行（地址、JP 名、US 标准名）、保留 asm 范围的
三列行（地址、源 `.s` 文件、符号）以及四列行（地址、源 `.s` 文件、JP 名、
US 标准名）。审计保留每一行而非建立全局“名称→地址”字典：同名 static 函数
按源 owner 优先消歧，仍无 source owner 的多地址关系全部保留并列入
`multi_address_c_definitions`，以免静默丢失地址。

## 指标定义

| 指标 | 分子 | 分母 | 说明 |
| --- | --- | --- | --- |
| 严格 C 转换率 | `funcmap_jp.txt` 中默认预处理分支有 C 函数体、非 `naked` 且不与 selected naked 定义重叠的唯一 ROM 地址 | `funcmap_jp.txt` 的唯一函数地址 | 默认构建把 `NONMATCHING` 视为未定义，并使用 C99 `__STDC_VERSION__`；互斥分支不会双计。未映射及多地址 C 定义会列出，避免静默膨胀或覆盖。 |
| 模块归位率 | 严格 C 地址中，能以 `funcmap` 的 US 标准名在 US 源树找到定义的唯一地址数 | 严格 C 地址数 | 表示函数已有上游语义归属，不等同于文件路径已对齐。 |
| 路径对齐率 | 上述地址中，JP 相对 `src/` 路径也是 US 定义路径之一的唯一地址数 | 严格 C 地址数 | 以路径而非 basename 比较，避免 `src/data` 与 `src/` 同名误判。 |
| 过渡文件数 | 文件名含 `tail`、`rest`、`mid`、`stub` 或地址式片段的源文件 | 各类别独立计数 | 同一文件可属于多个类别；`transition_manifest` 给出文件级重命名/拆分建议，不是负向质量分。 |
| incbin 资源结构化 | `.incbin`/`INCBIN_*` 引用数，按原始二进制后缀与非原始后缀分组 | 无百分比 | `incbin.manifest` 记录每项 owner、资源、存在性和建议动作；资源尺寸和格式不同，不能把“引用数”误报为字节转换率。 |
| 资产命名对齐 | 被 incbin 引用的 `graphics/`、`sound/` 路径，与 `--us-root` 中同名资产比较 | 无百分比 | `asset_naming.manifest` 区分 exact path、唯一 US basename 候选、歧义候选和无匹配项；它只产生复核清单，绝不自动重命名或改引用。 |
| 地图脚本 owner | `scripts.inc` 与 map-table 实际首 owner 名的交集 | JP ROM map-table 的去重首 owner 数 | 报告非 owner `scripts.inc`；共享表只归首次出现的地图，空表 owner 仍是结构化工作。 |

`jp_only_c_manifest` 是迁移清单而非“恰好 N 个”硬编码断言：它按照每个
C 文件中已映射、非裸汇编、但没有 US 标准函数 owner 的定义生成，并分类为
`library_or_runtime`、`placeholder_only`、`numbered_variant_only`、
`us_binary_only`、`needs_counterpart_review` 或 `mixed_non_mainline`。每个函数还附带建议动作：
保留运行时拆分、记录占位、与 US 基函数比较，或人工审查 US 对应项。
这能在上游更新或文件拆分后保持可验证；提交时应记录实际条目数，而不应
沿用失效的固定计数（例如旧的“38 个”）。

## 验证

审计脚本本身无需构建输出。涉及源码或链接输入的变更，仍必须串行执行：

```sh
flock /tmp/pokeemerald-jp-build.lock bash -lc 'make clean && make -j16 && make compare'
```

只有末行 `pokeemerald_jp.gba: OK` 才可提交。
