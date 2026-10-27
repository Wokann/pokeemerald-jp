# 可复现结构审计进度

> 此文件由 `python3 tools/audit_structure.py --markdown-output DECOMP_PROGRESS.md` 生成。
> `--output` 只写 JSON，且会拒绝 Markdown 路径，避免误覆盖本报告。
> US 统计参照：Git `731ad5bfd6e6f265508d0efcca0ba42f9dcf5881`；仅使用该提交的真实文件，不混入工作区或未登记的 US 编译产物。
> US 二进制辅助证据缺失时输出 unavailable/null，而非真实零值；源码归属候选不依赖这些未登记的符号或链接产物。

## 当前快照

- 严格 C：10827/16022 (67.58%，保守可证下界)；naked 汇编地址：4950；strict/naked 交集：0。
- 源码函数体库存：非 naked 10837、naked 4960；地址已绑定 15777、未解析 20；指标证据状态：conservative_verified_lower_bound。
- inline 源码定义：5；对象证实无独立入口 5；其他未解析 15。这些是源码库存单位，不是 ROM 分母。
- 旧名称 fan-out 指标已失效；修正绑定导致计数下降属于测量纠错，不是反编译退步。排除 naked 前自然交集：旧 61、新 0。
- 模块归位：10080/10827 (93.10%)；路径对齐：9911/10827 (91.54%)；US 标准名仍为 funcmap 候选，并非语义复核结论。
- JP 路径独有 C 清单：106；无 US 标准函数 owner 的语义缺口模块：118（两种口径，不沿用旧固定数）；同一源同名多地址未解析定义：0。
- 过渡文件：tail=0、rest=3、mid=2、stub=0、address=0。
- incbin：5399 引用、5287 条唯一路径、原始二进制 519、非原始 4880、缺失资源 0；可见 baserom 范围 97 条/0x45A39F 字节，未限定范围 0 条。
- 资源采集口径：物理源码引用（含全部源码分支），非默认构建发射量；未解决/条件诊断 17 条。INCGFX 单列 3412 次、3115 个源资产，生成上下文诊断 3412 条，不计入 incbin 分母。
- 资产命名：4235 条 graphics/sound 引用中，精确 US 路径 50、唯一 basename 候选 0、歧义 0。
- 地图脚本：468/469 (99.79%) 个首 owner 有 scripts.inc；非 owner scripts.inc：0；结构完整地图：518（直接物理文件满足者 468；合法共享 scripts/events owner 50/11；其中首 owner 469）；map.json 总数：518。
- 地图静态语义复核：recorded；当前证据有效 415/518。仅计显式登记且源码/原生证据仍有效的地图，不代表运行时玩法验证。
- 有效复核证据版本（同一地图仅计一次）：direct_map_v2=7、direct_map_v3=1、direct_map_v4=407。v4 包含按实际地址核对的类型化脚本、事件入口与共享调用闭包；版本统计不代表玩法完成度。
- 三流地图会合：scripts 流 468、events 流 518、共有 468、地图头 518；事件指针状态 direct=507、shared=11；地图内裸 baserom 范围（脚本/事件/资源）=0/0/0。
- script_data 顶层边界：JP linker 明确 owner 8/US 8；待补 JP owner 0；可见 event_scripts 原始 baserom 范围 0。US 只定义 owner 顺序，JP 范围必须由 JP map/ROM 锚点确认。

## 指标定义

| 指标 | 口径 |
| --- | --- |
| 严格 C 转换率 | 默认分支及由明确 Makefile 规则证实的附加编译分支中，非 `naked` C 函数体经 JP ELF 符号与 JP linker 输入对象范围验证 owner 的唯一 funcmap 地址 / funcmap 唯一地址；源码名与显式 `asm`/`__asm__` 链接名分开保留，显式链接名必须有 ELF/object STT_FUNC 证据。同名 static 按 source owner 和地址保留，不建立名称→地址覆盖表。缺证保留 unresolved，因此仅为保守可证下界；没有 ELF 证据时百分比 unavailable，不报 0% 退步。 |
| C 多对象编译 | 同一 C 源码的额外宏编译只接受无条件 Makefile 规则、唯一首 C 输入、字面量整数宏和明确 CPP/CC/AS 配方；每个附加地址仍须通过真实 ET_REL STT_FUNC、输入段、offset/段大小和最终链接 owner 核验。相同定义不按编译次数重复计数；不支持的规则不猜测，不能把所有未选中分支直接并入 C 进度。JSON 保留规则、宏、真实源码 owner、输入对象与 Makefile 哈希；规则或对象晚于 ELF 则不绑定。 |
| 模块归位率 | 已证实 JP owner 的严格 C 地址中，funcmap US 标准名候选在 US 源树有定义的地址 / 严格 C 地址；不代表该候选已逐函数语义复核。 |
| 路径对齐率 | 上述地址中 JP 相对 `src/` 路径也属于 US owner 的地址 / 严格 C 地址。 |
| 过渡文件 | 文件名包含 tail、rest、mid、stub 或地址式片段；分类可重叠。 |
| incbin | 物理源码内 `.incbin`、`INCBIN_U8/U16/U32` 的文件实参引用数，含已证明的直接参数转发模板；宏定义本身不计引用，多文件实参逐个计数，重复路径另算唯一路径。源码分支均可见，条件/作用域/动态或未支持展开显式诊断，不宣称默认构建发射量。INCGFX 的源/生成路径元信息单列，不加入该分母。裸 `.bin/.gba`、asset 根目录外的压缩流及匿名命名压缩资产沿用原 raw 分类；显式 baserom 范围仍另列字节，不是总 ROM 转换率。 |
| 资产命名 | 被引用的 `graphics/`、`sound/` 路径与 US 同名文件比较；仅生成候选，不自动改名。 |
| 地图脚本 owner | `scripts.inc` 与 map-table 实际首 owner 名的交集 / 去重首 owner；共享表只属于首次出现地图。 |
| 地图结构完整 | 同一地图具 `map.json`，且其 scripts/events 为本地图的物理文件与上层 include，或为 map.json 明示、header 精确指向且在 JP `data/` 有真实标签定义的共享 owner；只说明结构已拆分。 |
| 地图静态语义复核 | 只接受 tools/map_semantic_reviews.json 中显式复核决定；校验地图源码、生成规则、宏/常量、布局资源、共享调用和 JP ELF/map/ROM 区间。缺证或失效不计当前有效数；无登记仍为 not_recorded。只覆盖条目声明的静态字段/控制流范围，不代表运行时玩法或共享系统全生命周期已验证。 |
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
# 固定 US 提交重放（默认 HEAD 会在 JSON 中记录解析后的完整 commit/tree）
python3 tools/audit_structure.py --us-ref 731ad5bfd6e6f265508d0efcca0ba42f9dcf5881 --markdown-output DECOMP_PROGRESS.md
# 比较另一份 US 工程时显式指定其根目录
python3 tools/audit_structure.py --us-root /path/to/pokeemerald --markdown-output DECOMP_PROGRESS.md
```

源码库存、funcmap 和 incbin 清单不需要构建。函数地址指标读取匹配的 `pokeemerald_jp.elf` 与 `pokeemerald_jp.map`；输入 section 补证还读取对应 JP 对象的 STT_FUNC，libc 宏名称展开读取真实 include 链。JSON 记录这些输入 SHA-256、未解析原因和旧/新绑定诊断；缺失证据不按名字猜测。采样这些生成文件时须持有共享构建锁，避免 make clean 窗口。完整报告仍需要匹配的 `baserom_jp.gba` 来解析地图 owner。US 默认从指定 Git 提交的真实 blob 读取，不读取该目录的移植 WIP 或未跟踪生成物；资产命名候选只比较该提交实际包含的路径，缺少生成输出不等于 JP 命名错误。未登记的 US `.sym/.map` 不混入快照；缺少辅助证据明确标记 unavailable/null。只有显式 `--us-worktree` 才使用未验证的活目录。

涉及源码或链接输入的变更须执行：

```sh
flock /tmp/pokeemerald-jp-build.lock bash -lc 'make clean && make -j16 && make compare'
```

只有末行 `pokeemerald_jp.gba: OK` 才可提交。
