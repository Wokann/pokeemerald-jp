#include "global.h"
#include "sprite.h"
#include "unused_anims.h"
#include "battle_affine.h"

// 0x82D2F9C - mon-pic anim pointer table (sAnim_MonPic_* in battle_affine).
const union AnimCmd *const gAnims_MonPic[4] =
{
    sAnim_MonPic_0,
    sAnim_MonPic_1,
    sAnim_MonPic_2,
    sAnim_MonPic_3,
};

// 0x82D2FAC - unused mon-pic anims (values match pokeemerald unused_anims.h).
const union AnimCmd sUnusedAnim_Blaziken_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Blaziken_2[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Blaziken_3[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(2, 10),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Blaziken_4[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Marshtomp_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Marshtomp_2[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Marshtomp_3[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(2, 12),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Poochyena_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Poochyena_2[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(2, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(2, 10),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Mightyena_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Zigzagoon_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Linoone_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Wurmple_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Wurmple_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Silcoon_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Silcoon_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Beautifly_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Beautifly_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Cascoon_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Cascoon_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Dustox_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Dustox_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Lombre_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Ludicolo_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Ludicolo_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Seedot_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Nuzleaf_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Shiftry_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Shiftry_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Taillow_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Swellow_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Shroomish_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Breloom_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Wingull_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Pelipper_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Pelipper_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Surskit_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Surskit_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Masquerain_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Masquerain_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Wailmer_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(8, 15),
    ANIMCMD_FRAME(2, 22),
    ANIMCMD_FRAME(8, 5),
    ANIMCMD_FRAME(3, 8),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(6, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(6, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(6, 5),
    ANIMCMD_FRAME(4, 5),
    ANIMCMD_FRAME(6, 5),
    ANIMCMD_FRAME(5, 5),
    ANIMCMD_FRAME(7, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Wailmer_2[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(8, 15),
    ANIMCMD_FRAME(2, 15),
    ANIMCMD_FRAME(8, 15),
    ANIMCMD_FRAME(9, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(9, 10),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Wailmer_3[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(9, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(10, 20),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Wailmer_4[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(11, 15),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Skitty_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Delcatty_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Kecleon_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(2, 7),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(3, 4),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_FRAME(6, 2),
    ANIMCMD_FRAME(5, 2),
    ANIMCMD_FRAME(6, 2),
    ANIMCMD_FRAME(6, 10),
    ANIMCMD_FRAME(5, 4),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Kecleon_2[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(7, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(7, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(7, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(7, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(7, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(9, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(9, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(7, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Kecleon_3[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(7, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(7, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(7, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(7, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(7, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_FRAME(9, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(9, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(7, 12),
    ANIMCMD_FRAME(8, 12),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Kecleon_4[] =
{
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(10, 18),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Baltoy_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Claydol_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Nosepass_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Sableye_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Sableye_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Luvdisc_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Luvdisc_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Feebas_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Feebas_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Milotic_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Milotic_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Carvanha_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Carvanha_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Sharpedo_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Sharpedo_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Trapinch_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Vibrava_1[] =
{
    ANIMCMD_FRAME(0, 63),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Flygon_1[] =
{
    ANIMCMD_FRAME(0, 63),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Makuhita_1[] =
{
    ANIMCMD_FRAME(0, 63),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Hariyama_1[] =
{
    ANIMCMD_FRAME(0, 63),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Electrike_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Electrike_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Manectric_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Numel_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Numel_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Camerupt_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Spheal_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Sealeo_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Walrein_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Walrein_2[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(2, 18),
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(2, 18),
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(2, 18),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Azurill_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(2, 5),
    ANIMCMD_FRAME(3, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(4, 4),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Azurill_2[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Azurill_3[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(5, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(6, 12),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Azurill_4[] =
{
    ANIMCMD_FRAME(7, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Spoink_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Spoink_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Grumpig_1[] =
{
    ANIMCMD_FRAME(0, 63),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Plusle_1[] =
{
    ANIMCMD_FRAME(0, 63),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Minun_1[] =
{
    ANIMCMD_FRAME(0, 63),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Mawile_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Meditite_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Medicham_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Swablu_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Swablu_2[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Altaria_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Wynaut_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Wynaut_2[] =
{
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Duskull_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Duskull_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Dusclops_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Dusclops_2[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Slakoth_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Vigoroth_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Slaking_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Gulpin_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Swalot_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Tropius_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Clamperl_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Absol_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Shuppet_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Shuppet_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Banette_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Aron_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Lairon_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Aggron_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Castform_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Castform_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Castform_3[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Castform_4[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Volbeat_1[] =
{
    ANIMCMD_FRAME(0, 63),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Illumise_1[] =
{
    ANIMCMD_FRAME(0, 63),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Bagon_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Bagon_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Salamence_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Salamence_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Regirock_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Regice_1[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Registeel_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Registeel_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Rayquaza_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Rayquaza_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Unused1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Unused2[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

const union AnimCmd sUnusedAnim_Jirachi_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};
