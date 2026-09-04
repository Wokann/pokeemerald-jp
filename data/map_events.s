#include "constants/global.h"
#include "constants/event_bg.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/secret_bases.h"
#include "constants/trainer_types.h"
#include "constants/berry.h"
#include "constants/vars.h"
#include "constants/weather.h"

#define NULL 0

.include "sound/MPlayDef.s"
	.include "asm/macros.inc"

#include "constants/tms_hms.inc"

	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.section .rodata.map_events, "a", %progbits
	.include "data/maps/events.inc"
