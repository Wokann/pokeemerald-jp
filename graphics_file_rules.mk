CASTFORMGFXDIR := graphics/pokemon/castform

### Castform ###

$(CASTFORMGFXDIR)/front.4bpp: $(CASTFORMGFXDIR)/normal/front.4bpp \
                              $(CASTFORMGFXDIR)/sunny/front.4bpp \
                              $(CASTFORMGFXDIR)/rainy/front.4bpp \
                              $(CASTFORMGFXDIR)/snowy/front.4bpp
	@cat $^ >$@

$(CASTFORMGFXDIR)/back.4bpp: $(CASTFORMGFXDIR)/normal/back.4bpp \
                             $(CASTFORMGFXDIR)/sunny/back.4bpp \
                             $(CASTFORMGFXDIR)/rainy/back.4bpp \
                             $(CASTFORMGFXDIR)/snowy/back.4bpp
	@cat $^ >$@

$(CASTFORMGFXDIR)/anim_front.4bpp: $(CASTFORMGFXDIR)/normal/anim_front.4bpp \
                                   $(CASTFORMGFXDIR)/sunny/anim_front.4bpp \
                                   $(CASTFORMGFXDIR)/rainy/anim_front.4bpp \
                                   $(CASTFORMGFXDIR)/snowy/anim_front.4bpp
	@cat $^ >$@

$(CASTFORMGFXDIR)/normal.gbapal: $(CASTFORMGFXDIR)/normal/normal.gbapal \
                                 $(CASTFORMGFXDIR)/sunny/normal.gbapal \
                                 $(CASTFORMGFXDIR)/rainy/normal.gbapal \
                                 $(CASTFORMGFXDIR)/snowy/normal.gbapal
	@cat $^ >$@

$(CASTFORMGFXDIR)/shiny.gbapal: $(CASTFORMGFXDIR)/normal/shiny.gbapal \
                                $(CASTFORMGFXDIR)/sunny/shiny.gbapal \
                                $(CASTFORMGFXDIR)/rainy/shiny.gbapal \
                                $(CASTFORMGFXDIR)/snowy/shiny.gbapal
	@cat $^ >$@

WALLPAPERGFXDIR := graphics/pokemon_storage/wallpapers

### Pokémon Storage System ###

$(JP_STORAGE_WALLPAPER_DIR)/forest/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 55 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/city/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 52 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/savanna/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 45 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/savanna/bg.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 23 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/crag/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 49 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/volcano/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 56 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/snow/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 57 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/cave/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 55 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/beach/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 46 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/beach/bg.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 23 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/seafloor/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 54 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/river/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 51 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/river/bg.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 11 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/sky/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 45 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/polkadot/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 54 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/pokecenter/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 35 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/machine/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 33 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/plain/frame.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 18 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/friends_frame1.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 57 -Wnum_tiles
$(JP_STORAGE_WALLPAPER_DIR)/friends_frame2.4bpp: JP_STORAGE_TILE_FLAGS := -num_tiles 57 -Wnum_tiles

$(JP_STORAGE_WALLPAPER_PARTS): $(JP_STORAGE_WALLPAPER_DIR)/%.4bpp: $(WALLPAPERGFXDIR)/%.png graphics_file_rules.mk | tools
	@mkdir -p $(dir $@)
	$(GFX) $< $@ $(JP_STORAGE_TILE_FLAGS)

$(JP_STORAGE_WALLPAPER_DIR)/forest/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/forest/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/forest/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/city/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/city/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/city/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/desert/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/desert/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/desert/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/savanna/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/savanna/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/savanna/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/crag/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/crag/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/crag/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/volcano/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/volcano/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/volcano/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/snow/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/snow/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/snow/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/cave/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/cave/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/cave/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/beach/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/beach/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/beach/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/seafloor/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/seafloor/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/seafloor/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/river/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/river/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/river/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/sky/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/sky/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/sky/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/polkadot/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/polkadot/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/polkadot/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/pokecenter/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/pokecenter/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/pokecenter/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/machine/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/machine/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/machine/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/plain/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/plain/frame.4bpp $(JP_STORAGE_WALLPAPER_DIR)/plain/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/zigzagoon/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame1.4bpp $(JP_STORAGE_WALLPAPER_DIR)/zigzagoon/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/screen/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame1.4bpp $(JP_STORAGE_WALLPAPER_DIR)/screen/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/horizontal/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame1.4bpp $(JP_STORAGE_WALLPAPER_DIR)/horizontal/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/diagonal/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame1.4bpp $(JP_STORAGE_WALLPAPER_DIR)/diagonal/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/block/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame1.4bpp $(JP_STORAGE_WALLPAPER_DIR)/block/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/ribbon/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame1.4bpp $(JP_STORAGE_WALLPAPER_DIR)/ribbon/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/pokecenter2/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame1.4bpp $(JP_STORAGE_WALLPAPER_DIR)/pokecenter2/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/frame/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame1.4bpp $(JP_STORAGE_WALLPAPER_DIR)/frame/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/blank/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame1.4bpp $(JP_STORAGE_WALLPAPER_DIR)/blank/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/circles/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame1.4bpp $(JP_STORAGE_WALLPAPER_DIR)/circles/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/azumarill/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame2.4bpp $(JP_STORAGE_WALLPAPER_DIR)/azumarill/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/pikachu/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame2.4bpp $(JP_STORAGE_WALLPAPER_DIR)/pikachu/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/legendary/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame2.4bpp $(JP_STORAGE_WALLPAPER_DIR)/legendary/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/dusclops/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame2.4bpp $(JP_STORAGE_WALLPAPER_DIR)/dusclops/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/ludicolo/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame2.4bpp $(JP_STORAGE_WALLPAPER_DIR)/ludicolo/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_DIR)/whiscash/tiles.4bpp: $(JP_STORAGE_WALLPAPER_DIR)/friends_frame2.4bpp $(JP_STORAGE_WALLPAPER_DIR)/whiscash/bg.4bpp graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@cat $(filter %.4bpp,$^) >$@

$(JP_STORAGE_WALLPAPER_GFX): %.lz: % graphics_file_rules.mk | tools
	$(GFX) $< $@

.SECONDARY: $(JP_STORAGE_WALLPAPER_PARTS)

# Battle animation and retained interface composites.

graphics/battle_anims/sprites/ice_cube.4bpp: graphics/battle_anims/sprites/ice_cube_0.png.4bpp \
	graphics/battle_anims/sprites/ice_cube_1.png.4bpp \
	graphics/battle_anims/sprites/ice_cube_2.png.4bpp \
	graphics/battle_anims/sprites/ice_cube_3.png.4bpp Makefile graphics_file_rules.mk | tools
	@cat $(filter %.4bpp,$^) >$@

graphics/battle_interface/battle_bar.4bpp: graphics/battle_interface/hpbar_anim_unused.png.4bpp \
	graphics/battle_interface/numbers1.png.4bpp \
	graphics/battle_interface/numbers2.png.4bpp Makefile graphics_file_rules.mk | tools
	@cat $(filter %.4bpp,$^) >$@

graphics/unused/obi1.4bpp: graphics/unused/old_bulbasaur.png.4bpp \
	graphics/unused/old_charizard.png.4bpp Makefile graphics_file_rules.mk | tools
	@cat $(filter %.4bpp,$^) >$@

graphics/unused/obi2.4bpp: graphics/unused/old_bulbasaur2.png.4bpp \
	graphics/unused/old_battle_interface_1.png.4bpp \
	graphics/unused/old_battle_interface_2.png.4bpp \
	graphics/unused/old_battle_interface_3.png.4bpp Makefile graphics_file_rules.mk | tools
	@cat $(filter %.4bpp,$^) >$@

graphics/unused/obi_palpak1.gbapal: graphics/unused/old_pal1.pal.gbapal \
	graphics/unused/old_pal2.pal.gbapal \
	graphics/unused/old_pal3.pal.gbapal Makefile graphics_file_rules.mk | tools
	@cat $(filter %.gbapal,$^) >$@

graphics/unused/obi_palpak3.gbapal: graphics/unused/old_pal5.pal.gbapal \
	graphics/unused/old_pal6.pal.gbapal \
	graphics/unused/old_pal7.pal.gbapal Makefile graphics_file_rules.mk | tools
	@cat $(filter %.gbapal,$^) >$@

graphics/unused/redyellowgreen_frame.bin: graphics/unused/red_frame.bin \
	graphics/unused/yellow_frame.bin \
	graphics/unused/green_frame.bin \
	graphics/unused/blank_frame.bin Makefile graphics_file_rules.mk | tools
	@cat $(filter %.bin,$^) >$@
