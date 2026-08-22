#ifndef GUARD_DATA_OBJECT_EVENTS_OBJECT_EVENT_GRAPHICS_H
#define GUARD_DATA_OBJECT_EVENTS_OBJECT_EVENT_GRAPHICS_H

// This JP-owned subset is emitted by event_object_movement.c at its original ROM range.
OBJECT_EVENT_GRAPHICS_CUT_GRASS const u8 gFieldEffectPic_CutGrass[] = INCBIN_U8("graphics/field_effects/pics/cut_grass.4bpp");
OBJECT_EVENT_GRAPHICS_CUT_GRASS const u32 gFieldEffectPic_CutGrass_Copy[] = INCBIN_U32("graphics/field_effects/pics/cut_grass.4bpp");
OBJECT_EVENT_GRAPHICS_CUT_GRASS const u16 gFieldEffectPal_CutGrass[] = INCBIN_U16("graphics/field_effects/palettes/cut_grass.gbapal");

// These two palettes are physically later in the JP ROM than the Cut Grass data.
OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_PALETTES const u16 gFieldEffectObjectPalette0[] = INCBIN_U16("graphics/field_effects/palettes/general_0.gbapal");
OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_PALETTES const u16 gFieldEffectObjectPalette1[] = INCBIN_U16("graphics/field_effects/palettes/general_1.gbapal");

#endif // GUARD_DATA_OBJECT_EVENTS_OBJECT_EVENT_GRAPHICS_H
