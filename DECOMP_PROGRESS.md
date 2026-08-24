# 可复现结构审计进度

> 此文件由 `python3 tools/audit_structure.py --markdown-output DECOMP_PROGRESS.md` 生成。
> `--output` 只写 JSON，且会拒绝 Markdown 路径，避免误覆盖本报告。

## 当前快照

- 严格 C：7945/16023 (49.58%)；naked 汇编地址：4709；strict/naked 交集：0。
- 模块归位：7723/7945 (97.21%)；路径对齐：7672/7945 (96.56%)。
- JP 独有 C 迁移记录：46；同名多地址 C 定义：272。
- 过渡文件：tail=0、rest=4、mid=19、stub=0、address=664。
- incbin：7884 引用、6007 条唯一路径、原始二进制 5961、非原始 1923、缺失资源 0。
- 资产命名：4687 条 graphics/sound 引用中，精确 US 路径 26、唯一 basename 候选 16、歧义 0。
- 地图脚本：355/469 (75.69%) 个首 owner 有 scripts.inc；非 owner scripts.inc：0；map.json：27（含 scripts：27）。

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

## 复现与输入

```sh
python3 tools/audit_structure.py
python3 tools/audit_structure.py --json --output build/audit-structure.json \
    --manifest build/jp-only-c-manifest.json
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
