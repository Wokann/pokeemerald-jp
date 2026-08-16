#include "global.h"
#include "sprite.h"
#include "battle_affine.h"
#include "front_pic_anims.h"

// 0x82D97F8 - front pic anims (values match pokeemerald front_pic_anims.h).

static const union AnimCmd sAnim_None_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Bulbasaur_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ivysaur_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Venusaur_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Charmander_1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 46),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Charmeleon_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Charizard_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Squirtle_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Wartortle_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Blastoise_1[] =
{
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Caterpie_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Metapod_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Butterfree_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Weedle_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Kakuna_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Beedrill_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pidgey_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pidgeotto_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pidgeot_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Rattata_1[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 28),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Raticate_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Spearow_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Fearow_1[] =
{
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ekans_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Arbok_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pikachu_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pikachu_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Raichu_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Raichu_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sandshrew_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sandshrew_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sandslash_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sandslash_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_NidoranF_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Nidorina_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Nidoqueen_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_NidoranM_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Nidorino_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Nidoking_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Clefairy_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Clefable_1[] =
{
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 24),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Vulpix_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Vulpix_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ninetales_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ninetales_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Jigglypuff_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Jigglypuff_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Wigglytuff_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Wigglytuff_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Zubat_1[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Golbat_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Oddish_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Gloom_1[] =
{
    ANIMCMD_FRAME(0, 21),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Vileplume_1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 21),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 21),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Paras_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Parasect_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Venonat_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 35),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Venomoth_1[] =
{
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Diglett_1[] =
{
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Dugtrio_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Meowth_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 17),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Persian_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Psyduck_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Psyduck_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Golduck_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Golduck_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Mankey_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Primeape_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Growlithe_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Arcanine_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Poliwag_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Poliwhirl_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Poliwrath_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Abra_1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 21),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 21),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Kadabra_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Alakazam_1[] =
{
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 54),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Machop_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Machoke_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Machamp_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Bellsprout_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Weepinbell_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Victreebel_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Tentacool_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Tentacruel_1[] =
{
    ANIMCMD_FRAME(0, 19),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 19),
    ANIMCMD_FRAME(1, 19),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Geodude_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 36),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Graveler_1[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Golem_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 31),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ponyta_1[] =
{
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Rapidash_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Slowpoke_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Slowbro_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Magnemite_1[] =
{
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 28),
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 28),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Magneton_1[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Farfetchd_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Doduo_1[] =
{
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Dodrio_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Seel_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Dewgong_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Grimer_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Grimer_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Muk_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Muk_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Shellder_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cloyster_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Gastly_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Haunter_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Gengar_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Onix_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Drowzee_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Hypno_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Krabby_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Kingler_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Voltorb_1[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Electrode_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Exeggcute_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Exeggutor_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cubone_1[] =
{
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Marowak_1[] =
{
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Hitmonlee_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Hitmonchan_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Lickitung_1[] =
{
    ANIMCMD_FRAME(0, 28),
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Koffing_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Koffing_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Weezing_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Weezing_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Rhyhorn_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Rhyhorn_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Rhydon_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 48),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Rhydon_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Chansey_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Tangela_1[] =
{
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Kangaskhan_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Horsea_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Horsea_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Seadra_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Seadra_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Goldeen_1[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Seaking_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Staryu_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Staryu_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Starmie_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Starmie_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_MrMime_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Scyther_1[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Jynx_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Electabuzz_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Magmar_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pinsir_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pinsir_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Tauros_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Magikarp_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Gyarados_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Lapras_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ditto_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Eevee_1[] =
{
    ANIMCMD_FRAME(1, 33),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Vaporeon_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Jolteon_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Flareon_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Porygon_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Omanyte_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Omastar_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Kabuto_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Kabutops_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Aerodactyl_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Snorlax_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Articuno_1[] =
{
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Zapdos_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Moltres_1[] =
{
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Dratini_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Dragonair_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Dragonite_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Mewtwo_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Mew_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Chikorita_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Bayleef_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Meganium_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cyndaquil_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Quilava_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Typhlosion_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Totodile_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Croconaw_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Feraligatr_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 40),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sentret_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Furret_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Hoothoot_1[] =
{
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Noctowl_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ledyba_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ledian_1[] =
{
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Spinarak_1[] =
{
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ariados_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Crobat_1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Chinchou_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Chinchou_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Lanturn_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Lanturn_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pichu_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pichu_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cleffa_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Igglybuff_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Igglybuff_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Togepi_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Togetic_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Natu_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Natu_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Xatu_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 45),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Xatu_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Mareep_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Flaaffy_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ampharos_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Bellossom_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Marill_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Azumarill_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sudowoodo_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Politoed_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Hoppip_1[] =
{
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Skiploom_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Jumpluff_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 25),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Aipom_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sunkern_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sunflora_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Yanma_1[] =
{
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Wooper_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Quagsire_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Espeon_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Umbreon_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Murkrow_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Slowking_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Misdreavus_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Unown_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Wobbuffet_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Wobbuffet_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Girafarig_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Girafarig_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pineco_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Forretress_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Dunsparce_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Gligar_1[] =
{
    ANIMCMD_FRAME(1, 17),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Steelix_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Snubbull_1[] =
{
    ANIMCMD_FRAME(1, 32),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Granbull_1[] =
{
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Qwilfish_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Scizor_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Shuckle_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Heracross_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Heracross_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sneasel_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Teddiursa_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ursaring_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Slugma_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Slugma_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Magcargo_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Magcargo_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Swinub_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Piloswine_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Corsola_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Corsola_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Remoraid_1[] =
{
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Octillery_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Delibird_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Mantine_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 40),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Skarmory_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Skarmory_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Houndour_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Houndoom_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Kingdra_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Kingdra_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Phanpy_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Phanpy_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Donphan_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Donphan_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Porygon2_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Stantler_1[] =
{
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Smeargle_1[] =
{
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Tyrogue_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Hitmontop_1[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Smoochum_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Elekid_1[] =
{
    ANIMCMD_FRAME(1, 50),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Magby_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Miltank_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Blissey_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Raikou_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Entei_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Suicune_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Larvitar_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pupitar_1[] =
{
    ANIMCMD_FRAME(1, 40),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Tyranitar_1[] =
{
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Lugia_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_HoOh_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Celebi_1[] =
{
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_OldUnownB_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Treecko_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Grovyle_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sceptile_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 26),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Torchic_1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Combusken_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Blaziken_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Blaziken_2[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Blaziken_3[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(2, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Blaziken_4[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Mudkip_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 13),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Marshtomp_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Swampert_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Poochyena_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Mightyena_1[] =
{
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Zigzagoon_1[] =
{
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Linoone_1[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Wurmple_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Silcoon_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Silcoon_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Beautifly_1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Beautifly_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cascoon_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cascoon_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Dustox_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(1, 4),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Dustox_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Lotad_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 55),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Lombre_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ludicolo_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Seedot_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Nuzleaf_1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Shiftry_1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Nincada_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 33),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ninjask_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Shedinja_1[] =
{
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(1, 33),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(1, 33),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Taillow_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Swellow_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Shroomish_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Breloom_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Wingull_1[] =
{
    ANIMCMD_FRAME(0, 17),
    ANIMCMD_FRAME(1, 23),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Pelipper_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Surskit_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Surskit_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Masquerain_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Masquerain_2[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Wailmer_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Wailord_1[] =
{
    ANIMCMD_FRAME(0, 26),
    ANIMCMD_FRAME(1, 48),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Skitty_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 35),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Delcatty_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 46),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Kecleon_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Baltoy_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Claydol_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Nosepass_1[] =
{
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 27),
    ANIMCMD_FRAME(1, 27),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Torkoal_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sableye_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Barboach_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Whiscash_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Luvdisc_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Corphish_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Crawdaunt_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Feebas_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Milotic_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Carvanha_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sharpedo_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Trapinch_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Vibrava_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Flygon_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Makuhita_1[] =
{
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 7),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Hariyama_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Electrike_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 17),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Manectric_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 33),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Numel_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 40),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Camerupt_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Spheal_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 43),
    ANIMCMD_FRAME(1, 60),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sealeo_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Walrein_1[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cacnea_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cacturne_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Snorunt_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Glalie_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Lunatone_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Lunatone_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Solrock_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Solrock_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Azurill_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 12),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Spoink_1[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Grumpig_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Plusle_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Minun_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Mawile_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Meditite_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 2),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Medicham_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Swablu_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Swablu_2[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(2, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Altaria_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Altaria_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Wynaut_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Duskull_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Dusclops_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Roselia_1[] =
{
    ANIMCMD_FRAME(0, 18),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Slakoth_1[] =
{
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Vigoroth_1[] =
{
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 13),
    ANIMCMD_FRAME(1, 7),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Slaking_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Gulpin_1[] =
{
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 14),
    ANIMCMD_FRAME(1, 14),
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Swalot_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Tropius_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Whismur_1[] =
{
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Loudred_1[] =
{
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Exploud_1[] =
{
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Clamperl_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Huntail_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Gorebyss_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Absol_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Shuppet_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Banette_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Seviper_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Zangoose_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 50),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Relicanth_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Aron_1[] =
{
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 33),
    ANIMCMD_FRAME(1, 33),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Lairon_1[] =
{
    ANIMCMD_FRAME(0, 12),
    ANIMCMD_FRAME(1, 29),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 29),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Aggron_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 44),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Castform_0[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Castform_1[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Castform_2[] =
{
    ANIMCMD_FRAME(2, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Castform_3[] =
{
    ANIMCMD_FRAME(3, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Volbeat_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 11),
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Illumise_1[] =
{
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 22),
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Lileep_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cradily_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Anorith_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Armaldo_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Ralts_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 25),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Kirlia_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 39),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Gardevoir_1[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(1, 3),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Bagon_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Shelgon_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Salamence_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Beldum_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Metang_1[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Metagross_1[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Regirock_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Regirock_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Regice_1[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 18),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Registeel_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Registeel_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Kyogre_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Kyogre_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Groudon_1[] =
{
    ANIMCMD_FRAME(0, 11),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Groudon_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Rayquaza_1[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_FRAME(1, 8),
    ANIMCMD_FRAME(0, 22),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Rayquaza_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Latias_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Latias_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Latios_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Latios_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Jirachi_1[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(1, 10),
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Jirachi_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Deoxys_1[] =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 26),
    ANIMCMD_FRAME(1, 16),
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Deoxys_2[] =
{
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_FRAME(0, 20),
    ANIMCMD_FRAME(2, 20),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Chimecho_1[] =
{
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_FRAME(1, 15),
    ANIMCMD_FRAME(0, 15),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Egg_1[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(1, 6),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownB_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownC_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownD_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownE_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownF_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownG_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownH_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownI_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownJ_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownK_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownL_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownM_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownN_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownO_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownP_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownQ_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownR_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownS_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownT_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownU_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownV_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownW_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownX_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownY_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownZ_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownEMark_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_UnownQMark_1[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_FRAME(1, 30),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

// 0x82DC54C - per-species anim pointer arrays, in gMonFrontAnimsPtrTable order.

static const union AnimCmd *const sAnims_None[] =
{
    sAnim_GeneralFrame0,
    sAnim_None_1,
};

static const union AnimCmd *const sAnims_Bulbasaur[] =
{
    sAnim_GeneralFrame0,
    sAnim_Bulbasaur_1,
};

static const union AnimCmd *const sAnims_Ivysaur[] =
{
    sAnim_GeneralFrame0,
    sAnim_Ivysaur_1,
};

static const union AnimCmd *const sAnims_Venusaur[] =
{
    sAnim_GeneralFrame0,
    sAnim_Venusaur_1,
};

static const union AnimCmd *const sAnims_Charmander[] =
{
    sAnim_GeneralFrame0,
    sAnim_Charmander_1,
};

static const union AnimCmd *const sAnims_Charmeleon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Charmeleon_1,
};

static const union AnimCmd *const sAnims_Charizard[] =
{
    sAnim_GeneralFrame0,
    sAnim_Charizard_1,
};

static const union AnimCmd *const sAnims_Squirtle[] =
{
    sAnim_GeneralFrame0,
    sAnim_Squirtle_1,
};

static const union AnimCmd *const sAnims_Wartortle[] =
{
    sAnim_GeneralFrame0,
    sAnim_Wartortle_1,
};

static const union AnimCmd *const sAnims_Blastoise[] =
{
    sAnim_GeneralFrame0,
    sAnim_Blastoise_1,
};

static const union AnimCmd *const sAnims_Caterpie[] =
{
    sAnim_GeneralFrame0,
    sAnim_Caterpie_1,
};

static const union AnimCmd *const sAnims_Metapod[] =
{
    sAnim_GeneralFrame0,
    sAnim_Metapod_1,
};

static const union AnimCmd *const sAnims_Butterfree[] =
{
    sAnim_GeneralFrame0,
    sAnim_Butterfree_1,
};

static const union AnimCmd *const sAnims_Weedle[] =
{
    sAnim_GeneralFrame0,
    sAnim_Weedle_1,
};

static const union AnimCmd *const sAnims_Kakuna[] =
{
    sAnim_GeneralFrame0,
    sAnim_Kakuna_1,
};

static const union AnimCmd *const sAnims_Beedrill[] =
{
    sAnim_GeneralFrame0,
    sAnim_Beedrill_1,
};

static const union AnimCmd *const sAnims_Pidgey[] =
{
    sAnim_GeneralFrame0,
    sAnim_Pidgey_1,
};

static const union AnimCmd *const sAnims_Pidgeotto[] =
{
    sAnim_GeneralFrame0,
    sAnim_Pidgeotto_1,
};

static const union AnimCmd *const sAnims_Pidgeot[] =
{
    sAnim_GeneralFrame0,
    sAnim_Pidgeot_1,
};

static const union AnimCmd *const sAnims_Rattata[] =
{
    sAnim_GeneralFrame0,
    sAnim_Rattata_1,
};

static const union AnimCmd *const sAnims_Raticate[] =
{
    sAnim_GeneralFrame0,
    sAnim_Raticate_1,
};

static const union AnimCmd *const sAnims_Spearow[] =
{
    sAnim_GeneralFrame0,
    sAnim_Spearow_1,
};

static const union AnimCmd *const sAnims_Fearow[] =
{
    sAnim_GeneralFrame0,
    sAnim_Fearow_1,
};

static const union AnimCmd *const sAnims_Ekans[] =
{
    sAnim_GeneralFrame0,
    sAnim_Ekans_1,
};

static const union AnimCmd *const sAnims_Arbok[] =
{
    sAnim_GeneralFrame0,
    sAnim_Arbok_1,
};

static const union AnimCmd *const sAnims_Pikachu[] =
{
    sAnim_GeneralFrame0,
    sAnim_Pikachu_1,
    sAnim_Pikachu_2,
};

static const union AnimCmd *const sAnims_Raichu[] =
{
    sAnim_GeneralFrame0,
    sAnim_Raichu_1,
    sAnim_Raichu_2,
};

static const union AnimCmd *const sAnims_Sandshrew[] =
{
    sAnim_GeneralFrame0,
    sAnim_Sandshrew_1,
    sAnim_Sandshrew_2,
};

static const union AnimCmd *const sAnims_Sandslash[] =
{
    sAnim_GeneralFrame0,
    sAnim_Sandslash_1,
    sAnim_Sandslash_2,
};

static const union AnimCmd *const sAnims_NidoranF[] =
{
    sAnim_GeneralFrame0,
    sAnim_NidoranF_1,
};

static const union AnimCmd *const sAnims_Nidorina[] =
{
    sAnim_GeneralFrame0,
    sAnim_Nidorina_1,
};

static const union AnimCmd *const sAnims_Nidoqueen[] =
{
    sAnim_GeneralFrame0,
    sAnim_Nidoqueen_1,
};

static const union AnimCmd *const sAnims_NidoranM[] =
{
    sAnim_GeneralFrame0,
    sAnim_NidoranM_1,
};

static const union AnimCmd *const sAnims_Nidorino[] =
{
    sAnim_GeneralFrame0,
    sAnim_Nidorino_1,
};

static const union AnimCmd *const sAnims_Nidoking[] =
{
    sAnim_GeneralFrame0,
    sAnim_Nidoking_1,
};

static const union AnimCmd *const sAnims_Clefairy[] =
{
    sAnim_GeneralFrame0,
    sAnim_Clefairy_1,
};

static const union AnimCmd *const sAnims_Clefable[] =
{
    sAnim_GeneralFrame0,
    sAnim_Clefable_1,
};

static const union AnimCmd *const sAnims_Vulpix[] =
{
    sAnim_GeneralFrame0,
    sAnim_Vulpix_1,
    sAnim_Vulpix_2,
};

static const union AnimCmd *const sAnims_Ninetales[] =
{
    sAnim_GeneralFrame0,
    sAnim_Ninetales_1,
    sAnim_Ninetales_2,
};

static const union AnimCmd *const sAnims_Jigglypuff[] =
{
    sAnim_GeneralFrame0,
    sAnim_Jigglypuff_1,
    sAnim_Jigglypuff_2,
};

static const union AnimCmd *const sAnims_Wigglytuff[] =
{
    sAnim_GeneralFrame0,
    sAnim_Wigglytuff_1,
    sAnim_Wigglytuff_2,
};

static const union AnimCmd *const sAnims_Zubat[] =
{
    sAnim_GeneralFrame0,
    sAnim_Zubat_1,
};

static const union AnimCmd *const sAnims_Golbat[] =
{
    sAnim_GeneralFrame0,
    sAnim_Golbat_1,
};

static const union AnimCmd *const sAnims_Oddish[] =
{
    sAnim_GeneralFrame0,
    sAnim_Oddish_1,
};

static const union AnimCmd *const sAnims_Gloom[] =
{
    sAnim_GeneralFrame0,
    sAnim_Gloom_1,
};

static const union AnimCmd *const sAnims_Vileplume[] =
{
    sAnim_GeneralFrame0,
    sAnim_Vileplume_1,
};

static const union AnimCmd *const sAnims_Paras[] =
{
    sAnim_GeneralFrame0,
    sAnim_Paras_1,
};

static const union AnimCmd *const sAnims_Parasect[] =
{
    sAnim_GeneralFrame0,
    sAnim_Parasect_1,
};

static const union AnimCmd *const sAnims_Venonat[] =
{
    sAnim_GeneralFrame0,
    sAnim_Venonat_1,
};

static const union AnimCmd *const sAnims_Venomoth[] =
{
    sAnim_GeneralFrame0,
    sAnim_Venomoth_1,
};

static const union AnimCmd *const sAnims_Diglett[] =
{
    sAnim_GeneralFrame0,
    sAnim_Diglett_1,
};

static const union AnimCmd *const sAnims_Dugtrio[] =
{
    sAnim_GeneralFrame0,
    sAnim_Dugtrio_1,
};

static const union AnimCmd *const sAnims_Meowth[] =
{
    sAnim_GeneralFrame0,
    sAnim_Meowth_1,
};

static const union AnimCmd *const sAnims_Persian[] =
{
    sAnim_GeneralFrame0,
    sAnim_Persian_1,
};

static const union AnimCmd *const sAnims_Psyduck[] =
{
    sAnim_GeneralFrame0,
    sAnim_Psyduck_1,
    sAnim_Psyduck_2,
};

static const union AnimCmd *const sAnims_Golduck[] =
{
    sAnim_GeneralFrame0,
    sAnim_Golduck_1,
    sAnim_Golduck_2,
};

static const union AnimCmd *const sAnims_Mankey[] =
{
    sAnim_GeneralFrame0,
    sAnim_Mankey_1,
};

static const union AnimCmd *const sAnims_Primeape[] =
{
    sAnim_GeneralFrame0,
    sAnim_Primeape_1,
};

static const union AnimCmd *const sAnims_Growlithe[] =
{
    sAnim_GeneralFrame0,
    sAnim_Growlithe_1,
};

static const union AnimCmd *const sAnims_Arcanine[] =
{
    sAnim_GeneralFrame0,
    sAnim_Arcanine_1,
};

static const union AnimCmd *const sAnims_Poliwag[] =
{
    sAnim_GeneralFrame0,
    sAnim_Poliwag_1,
};

static const union AnimCmd *const sAnims_Poliwhirl[] =
{
    sAnim_GeneralFrame0,
    sAnim_Poliwhirl_1,
};

static const union AnimCmd *const sAnims_Poliwrath[] =
{
    sAnim_GeneralFrame0,
    sAnim_Poliwrath_1,
};

static const union AnimCmd *const sAnims_Abra[] =
{
    sAnim_GeneralFrame0,
    sAnim_Abra_1,
};

static const union AnimCmd *const sAnims_Kadabra[] =
{
    sAnim_GeneralFrame0,
    sAnim_Kadabra_1,
};

static const union AnimCmd *const sAnims_Alakazam[] =
{
    sAnim_GeneralFrame0,
    sAnim_Alakazam_1,
};

static const union AnimCmd *const sAnims_Machop[] =
{
    sAnim_GeneralFrame0,
    sAnim_Machop_1,
};

static const union AnimCmd *const sAnims_Machoke[] =
{
    sAnim_GeneralFrame0,
    sAnim_Machoke_1,
};

static const union AnimCmd *const sAnims_Machamp[] =
{
    sAnim_GeneralFrame0,
    sAnim_Machamp_1,
};

static const union AnimCmd *const sAnims_Bellsprout[] =
{
    sAnim_GeneralFrame0,
    sAnim_Bellsprout_1,
};

static const union AnimCmd *const sAnims_Weepinbell[] =
{
    sAnim_GeneralFrame0,
    sAnim_Weepinbell_1,
};

static const union AnimCmd *const sAnims_Victreebel[] =
{
    sAnim_GeneralFrame0,
    sAnim_Victreebel_1,
};

static const union AnimCmd *const sAnims_Tentacool[] =
{
    sAnim_GeneralFrame0,
    sAnim_Tentacool_1,
};

static const union AnimCmd *const sAnims_Tentacruel[] =
{
    sAnim_GeneralFrame0,
    sAnim_Tentacruel_1,
};

static const union AnimCmd *const sAnims_Geodude[] =
{
    sAnim_GeneralFrame0,
    sAnim_Geodude_1,
};

static const union AnimCmd *const sAnims_Graveler[] =
{
    sAnim_GeneralFrame0,
    sAnim_Graveler_1,
};

static const union AnimCmd *const sAnims_Golem[] =
{
    sAnim_GeneralFrame0,
    sAnim_Golem_1,
};

static const union AnimCmd *const sAnims_Ponyta[] =
{
    sAnim_GeneralFrame0,
    sAnim_Ponyta_1,
};

static const union AnimCmd *const sAnims_Rapidash[] =
{
    sAnim_GeneralFrame0,
    sAnim_Rapidash_1,
};

static const union AnimCmd *const sAnims_Slowpoke[] =
{
    sAnim_GeneralFrame0,
    sAnim_Slowpoke_1,
};

static const union AnimCmd *const sAnims_Slowbro[] =
{
    sAnim_GeneralFrame0,
    sAnim_Slowbro_1,
};

static const union AnimCmd *const sAnims_Magnemite[] =
{
    sAnim_GeneralFrame0,
    sAnim_Magnemite_1,
};

static const union AnimCmd *const sAnims_Magneton[] =
{
    sAnim_GeneralFrame0,
    sAnim_Magneton_1,
};

static const union AnimCmd *const sAnims_Farfetchd[] =
{
    sAnim_GeneralFrame0,
    sAnim_Farfetchd_1,
};

static const union AnimCmd *const sAnims_Doduo[] =
{
    sAnim_GeneralFrame0,
    sAnim_Doduo_1,
};

static const union AnimCmd *const sAnims_Dodrio[] =
{
    sAnim_GeneralFrame0,
    sAnim_Dodrio_1,
};

static const union AnimCmd *const sAnims_Seel[] =
{
    sAnim_GeneralFrame0,
    sAnim_Seel_1,
};

static const union AnimCmd *const sAnims_Dewgong[] =
{
    sAnim_GeneralFrame0,
    sAnim_Dewgong_1,
};

static const union AnimCmd *const sAnims_Grimer[] =
{
    sAnim_GeneralFrame0,
    sAnim_Grimer_1,
    sAnim_Grimer_2,
};

static const union AnimCmd *const sAnims_Muk[] =
{
    sAnim_GeneralFrame0,
    sAnim_Muk_1,
    sAnim_Muk_2,
};

static const union AnimCmd *const sAnims_Shellder[] =
{
    sAnim_GeneralFrame0,
    sAnim_Shellder_1,
};

static const union AnimCmd *const sAnims_Cloyster[] =
{
    sAnim_GeneralFrame0,
    sAnim_Cloyster_1,
};

static const union AnimCmd *const sAnims_Gastly[] =
{
    sAnim_GeneralFrame0,
    sAnim_Gastly_1,
};

static const union AnimCmd *const sAnims_Haunter[] =
{
    sAnim_GeneralFrame0,
    sAnim_Haunter_1,
};

static const union AnimCmd *const sAnims_Gengar[] =
{
    sAnim_GeneralFrame0,
    sAnim_Gengar_1,
};

static const union AnimCmd *const sAnims_Onix[] =
{
    sAnim_GeneralFrame0,
    sAnim_Onix_1,
};

static const union AnimCmd *const sAnims_Drowzee[] =
{
    sAnim_GeneralFrame0,
    sAnim_Drowzee_1,
};

static const union AnimCmd *const sAnims_Hypno[] =
{
    sAnim_GeneralFrame0,
    sAnim_Hypno_1,
};

static const union AnimCmd *const sAnims_Krabby[] =
{
    sAnim_GeneralFrame0,
    sAnim_Krabby_1,
};

static const union AnimCmd *const sAnims_Kingler[] =
{
    sAnim_GeneralFrame0,
    sAnim_Kingler_1,
};

static const union AnimCmd *const sAnims_Voltorb[] =
{
    sAnim_GeneralFrame0,
    sAnim_Voltorb_1,
};

static const union AnimCmd *const sAnims_Electrode[] =
{
    sAnim_GeneralFrame0,
    sAnim_Electrode_1,
};

static const union AnimCmd *const sAnims_Exeggcute[] =
{
    sAnim_GeneralFrame0,
    sAnim_Exeggcute_1,
};

static const union AnimCmd *const sAnims_Exeggutor[] =
{
    sAnim_GeneralFrame0,
    sAnim_Exeggutor_1,
};

static const union AnimCmd *const sAnims_Cubone[] =
{
    sAnim_GeneralFrame0,
    sAnim_Cubone_1,
};

static const union AnimCmd *const sAnims_Marowak[] =
{
    sAnim_GeneralFrame0,
    sAnim_Marowak_1,
};

static const union AnimCmd *const sAnims_Hitmonlee[] =
{
    sAnim_GeneralFrame0,
    sAnim_Hitmonlee_1,
};

static const union AnimCmd *const sAnims_Hitmonchan[] =
{
    sAnim_GeneralFrame0,
    sAnim_Hitmonchan_1,
};

static const union AnimCmd *const sAnims_Lickitung[] =
{
    sAnim_GeneralFrame0,
    sAnim_Lickitung_1,
};

static const union AnimCmd *const sAnims_Koffing[] =
{
    sAnim_GeneralFrame0,
    sAnim_Koffing_1,
    sAnim_Koffing_2,
};

static const union AnimCmd *const sAnims_Weezing[] =
{
    sAnim_GeneralFrame0,
    sAnim_Weezing_1,
    sAnim_Weezing_2,
};

static const union AnimCmd *const sAnims_Rhyhorn[] =
{
    sAnim_GeneralFrame0,
    sAnim_Rhyhorn_1,
    sAnim_Rhyhorn_2,
};

static const union AnimCmd *const sAnims_Rhydon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Rhydon_1,
    sAnim_Rhydon_2,
};

static const union AnimCmd *const sAnims_Chansey[] =
{
    sAnim_GeneralFrame0,
    sAnim_Chansey_1,
};

static const union AnimCmd *const sAnims_Tangela[] =
{
    sAnim_GeneralFrame0,
    sAnim_Tangela_1,
};

static const union AnimCmd *const sAnims_Kangaskhan[] =
{
    sAnim_GeneralFrame0,
    sAnim_Kangaskhan_1,
};

static const union AnimCmd *const sAnims_Horsea[] =
{
    sAnim_GeneralFrame0,
    sAnim_Horsea_1,
    sAnim_Horsea_2,
};

static const union AnimCmd *const sAnims_Seadra[] =
{
    sAnim_GeneralFrame0,
    sAnim_Seadra_1,
    sAnim_Seadra_2,
};

static const union AnimCmd *const sAnims_Goldeen[] =
{
    sAnim_GeneralFrame0,
    sAnim_Goldeen_1,
};

static const union AnimCmd *const sAnims_Seaking[] =
{
    sAnim_GeneralFrame0,
    sAnim_Seaking_1,
};

static const union AnimCmd *const sAnims_Staryu[] =
{
    sAnim_GeneralFrame0,
    sAnim_Staryu_1,
    sAnim_Staryu_2,
};

static const union AnimCmd *const sAnims_Starmie[] =
{
    sAnim_GeneralFrame0,
    sAnim_Starmie_1,
    sAnim_Starmie_2,
};

static const union AnimCmd *const sAnims_MrMime[] =
{
    sAnim_GeneralFrame0,
    sAnim_MrMime_1,
};

static const union AnimCmd *const sAnims_Scyther[] =
{
    sAnim_GeneralFrame0,
    sAnim_Scyther_1,
};

static const union AnimCmd *const sAnims_Jynx[] =
{
    sAnim_GeneralFrame0,
    sAnim_Jynx_1,
};

static const union AnimCmd *const sAnims_Electabuzz[] =
{
    sAnim_GeneralFrame0,
    sAnim_Electabuzz_1,
};

static const union AnimCmd *const sAnims_Magmar[] =
{
    sAnim_GeneralFrame0,
    sAnim_Magmar_1,
};

static const union AnimCmd *const sAnims_Pinsir[] =
{
    sAnim_GeneralFrame0,
    sAnim_Pinsir_1,
    sAnim_Pinsir_2,
};

static const union AnimCmd *const sAnims_Tauros[] =
{
    sAnim_GeneralFrame0,
    sAnim_Tauros_1,
};

static const union AnimCmd *const sAnims_Magikarp[] =
{
    sAnim_GeneralFrame0,
    sAnim_Magikarp_1,
};

static const union AnimCmd *const sAnims_Gyarados[] =
{
    sAnim_GeneralFrame0,
    sAnim_Gyarados_1,
};

static const union AnimCmd *const sAnims_Lapras[] =
{
    sAnim_GeneralFrame0,
    sAnim_Lapras_1,
};

static const union AnimCmd *const sAnims_Ditto[] =
{
    sAnim_GeneralFrame0,
    sAnim_Ditto_1,
};

static const union AnimCmd *const sAnims_Eevee[] =
{
    sAnim_GeneralFrame0,
    sAnim_Eevee_1,
};

static const union AnimCmd *const sAnims_Vaporeon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Vaporeon_1,
};

static const union AnimCmd *const sAnims_Jolteon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Jolteon_1,
};

static const union AnimCmd *const sAnims_Flareon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Flareon_1,
};

static const union AnimCmd *const sAnims_Porygon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Porygon_1,
};

static const union AnimCmd *const sAnims_Omanyte[] =
{
    sAnim_GeneralFrame0,
    sAnim_Omanyte_1,
};

static const union AnimCmd *const sAnims_Omastar[] =
{
    sAnim_GeneralFrame0,
    sAnim_Omastar_1,
};

static const union AnimCmd *const sAnims_Kabuto[] =
{
    sAnim_GeneralFrame0,
    sAnim_Kabuto_1,
};

static const union AnimCmd *const sAnims_Kabutops[] =
{
    sAnim_GeneralFrame0,
    sAnim_Kabutops_1,
};

static const union AnimCmd *const sAnims_Aerodactyl[] =
{
    sAnim_GeneralFrame0,
    sAnim_Aerodactyl_1,
};

static const union AnimCmd *const sAnims_Snorlax[] =
{
    sAnim_GeneralFrame0,
    sAnim_Snorlax_1,
};

static const union AnimCmd *const sAnims_Articuno[] =
{
    sAnim_GeneralFrame0,
    sAnim_Articuno_1,
};

static const union AnimCmd *const sAnims_Zapdos[] =
{
    sAnim_GeneralFrame0,
    sAnim_Zapdos_1,
};

static const union AnimCmd *const sAnims_Moltres[] =
{
    sAnim_GeneralFrame0,
    sAnim_Moltres_1,
};

static const union AnimCmd *const sAnims_Dratini[] =
{
    sAnim_GeneralFrame0,
    sAnim_Dratini_1,
};

static const union AnimCmd *const sAnims_Dragonair[] =
{
    sAnim_GeneralFrame0,
    sAnim_Dragonair_1,
};

static const union AnimCmd *const sAnims_Dragonite[] =
{
    sAnim_GeneralFrame0,
    sAnim_Dragonite_1,
};

static const union AnimCmd *const sAnims_Mewtwo[] =
{
    sAnim_GeneralFrame0,
    sAnim_Mewtwo_1,
};

static const union AnimCmd *const sAnims_Mew[] =
{
    sAnim_GeneralFrame0,
    sAnim_Mew_1,
};

static const union AnimCmd *const sAnims_Chikorita[] =
{
    sAnim_GeneralFrame0,
    sAnim_Chikorita_1,
};

static const union AnimCmd *const sAnims_Bayleef[] =
{
    sAnim_GeneralFrame0,
    sAnim_Bayleef_1,
};

static const union AnimCmd *const sAnims_Meganium[] =
{
    sAnim_GeneralFrame0,
    sAnim_Meganium_1,
};

static const union AnimCmd *const sAnims_Cyndaquil[] =
{
    sAnim_GeneralFrame0,
    sAnim_Cyndaquil_1,
};

static const union AnimCmd *const sAnims_Quilava[] =
{
    sAnim_GeneralFrame0,
    sAnim_Quilava_1,
};

static const union AnimCmd *const sAnims_Typhlosion[] =
{
    sAnim_GeneralFrame0,
    sAnim_Typhlosion_1,
};

static const union AnimCmd *const sAnims_Totodile[] =
{
    sAnim_GeneralFrame0,
    sAnim_Totodile_1,
};

static const union AnimCmd *const sAnims_Croconaw[] =
{
    sAnim_GeneralFrame0,
    sAnim_Croconaw_1,
};

static const union AnimCmd *const sAnims_Feraligatr[] =
{
    sAnim_GeneralFrame0,
    sAnim_Feraligatr_1,
};

static const union AnimCmd *const sAnims_Sentret[] =
{
    sAnim_GeneralFrame0,
    sAnim_Sentret_1,
};

static const union AnimCmd *const sAnims_Furret[] =
{
    sAnim_GeneralFrame0,
    sAnim_Furret_1,
};

static const union AnimCmd *const sAnims_Hoothoot[] =
{
    sAnim_GeneralFrame0,
    sAnim_Hoothoot_1,
};

static const union AnimCmd *const sAnims_Noctowl[] =
{
    sAnim_GeneralFrame0,
    sAnim_Noctowl_1,
};

static const union AnimCmd *const sAnims_Ledyba[] =
{
    sAnim_GeneralFrame0,
    sAnim_Ledyba_1,
};

static const union AnimCmd *const sAnims_Ledian[] =
{
    sAnim_GeneralFrame0,
    sAnim_Ledian_1,
};

static const union AnimCmd *const sAnims_Spinarak[] =
{
    sAnim_GeneralFrame0,
    sAnim_Spinarak_1,
};

static const union AnimCmd *const sAnims_Ariados[] =
{
    sAnim_GeneralFrame0,
    sAnim_Ariados_1,
};

static const union AnimCmd *const sAnims_Crobat[] =
{
    sAnim_GeneralFrame0,
    sAnim_Crobat_1,
};

static const union AnimCmd *const sAnims_Chinchou[] =
{
    sAnim_GeneralFrame0,
    sAnim_Chinchou_1,
    sAnim_Chinchou_2,
};

static const union AnimCmd *const sAnims_Lanturn[] =
{
    sAnim_GeneralFrame0,
    sAnim_Lanturn_1,
    sAnim_Lanturn_2,
};

static const union AnimCmd *const sAnims_Pichu[] =
{
    sAnim_GeneralFrame0,
    sAnim_Pichu_1,
    sAnim_Pichu_2,
};

static const union AnimCmd *const sAnims_Cleffa[] =
{
    sAnim_GeneralFrame0,
    sAnim_Cleffa_1,
};

static const union AnimCmd *const sAnims_Igglybuff[] =
{
    sAnim_GeneralFrame0,
    sAnim_Igglybuff_1,
    sAnim_Igglybuff_2,
};

static const union AnimCmd *const sAnims_Togepi[] =
{
    sAnim_GeneralFrame0,
    sAnim_Togepi_1,
};

static const union AnimCmd *const sAnims_Togetic[] =
{
    sAnim_GeneralFrame0,
    sAnim_Togetic_1,
};

static const union AnimCmd *const sAnims_Natu[] =
{
    sAnim_GeneralFrame0,
    sAnim_Natu_1,
    sAnim_Natu_2,
};

static const union AnimCmd *const sAnims_Xatu[] =
{
    sAnim_GeneralFrame0,
    sAnim_Xatu_1,
    sAnim_Xatu_2,
};

static const union AnimCmd *const sAnims_Mareep[] =
{
    sAnim_GeneralFrame0,
    sAnim_Mareep_1,
};

static const union AnimCmd *const sAnims_Flaaffy[] =
{
    sAnim_GeneralFrame0,
    sAnim_Flaaffy_1,
};

static const union AnimCmd *const sAnims_Ampharos[] =
{
    sAnim_GeneralFrame0,
    sAnim_Ampharos_1,
};

static const union AnimCmd *const sAnims_Bellossom[] =
{
    sAnim_GeneralFrame0,
    sAnim_Bellossom_1,
};

static const union AnimCmd *const sAnims_Marill[] =
{
    sAnim_GeneralFrame0,
    sAnim_Marill_1,
};

static const union AnimCmd *const sAnims_Azumarill[] =
{
    sAnim_GeneralFrame0,
    sAnim_Azumarill_1,
};

static const union AnimCmd *const sAnims_Sudowoodo[] =
{
    sAnim_GeneralFrame0,
    sAnim_Sudowoodo_1,
};

static const union AnimCmd *const sAnims_Politoed[] =
{
    sAnim_GeneralFrame0,
    sAnim_Politoed_1,
};

static const union AnimCmd *const sAnims_Hoppip[] =
{
    sAnim_GeneralFrame0,
    sAnim_Hoppip_1,
};

static const union AnimCmd *const sAnims_Skiploom[] =
{
    sAnim_GeneralFrame0,
    sAnim_Skiploom_1,
};

static const union AnimCmd *const sAnims_Jumpluff[] =
{
    sAnim_GeneralFrame0,
    sAnim_Jumpluff_1,
};

static const union AnimCmd *const sAnims_Aipom[] =
{
    sAnim_GeneralFrame0,
    sAnim_Aipom_1,
};

static const union AnimCmd *const sAnims_Sunkern[] =
{
    sAnim_GeneralFrame0,
    sAnim_Sunkern_1,
};

static const union AnimCmd *const sAnims_Sunflora[] =
{
    sAnim_GeneralFrame0,
    sAnim_Sunflora_1,
};

static const union AnimCmd *const sAnims_Yanma[] =
{
    sAnim_GeneralFrame0,
    sAnim_Yanma_1,
};

static const union AnimCmd *const sAnims_Wooper[] =
{
    sAnim_GeneralFrame0,
    sAnim_Wooper_1,
};

static const union AnimCmd *const sAnims_Quagsire[] =
{
    sAnim_GeneralFrame0,
    sAnim_Quagsire_1,
};

static const union AnimCmd *const sAnims_Espeon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Espeon_1,
};

static const union AnimCmd *const sAnims_Umbreon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Umbreon_1,
};

static const union AnimCmd *const sAnims_Murkrow[] =
{
    sAnim_GeneralFrame0,
    sAnim_Murkrow_1,
};

static const union AnimCmd *const sAnims_Slowking[] =
{
    sAnim_GeneralFrame0,
    sAnim_Slowking_1,
};

static const union AnimCmd *const sAnims_Misdreavus[] =
{
    sAnim_GeneralFrame0,
    sAnim_Misdreavus_1,
};

static const union AnimCmd *const sAnims_Unown[] =
{
    sAnim_GeneralFrame0,
    sAnim_Unown_1,
};

static const union AnimCmd *const sAnims_Wobbuffet[] =
{
    sAnim_GeneralFrame0,
    sAnim_Wobbuffet_1,
    sAnim_Wobbuffet_2,
};

static const union AnimCmd *const sAnims_Girafarig[] =
{
    sAnim_GeneralFrame0,
    sAnim_Girafarig_1,
    sAnim_Girafarig_2,
};

static const union AnimCmd *const sAnims_Pineco[] =
{
    sAnim_GeneralFrame0,
    sAnim_Pineco_1,
};

static const union AnimCmd *const sAnims_Forretress[] =
{
    sAnim_GeneralFrame0,
    sAnim_Forretress_1,
};

static const union AnimCmd *const sAnims_Dunsparce[] =
{
    sAnim_GeneralFrame0,
    sAnim_Dunsparce_1,
};

static const union AnimCmd *const sAnims_Gligar[] =
{
    sAnim_GeneralFrame0,
    sAnim_Gligar_1,
};

static const union AnimCmd *const sAnims_Steelix[] =
{
    sAnim_GeneralFrame0,
    sAnim_Steelix_1,
};

static const union AnimCmd *const sAnims_Snubbull[] =
{
    sAnim_GeneralFrame0,
    sAnim_Snubbull_1,
};

static const union AnimCmd *const sAnims_Granbull[] =
{
    sAnim_GeneralFrame0,
    sAnim_Granbull_1,
};

static const union AnimCmd *const sAnims_Qwilfish[] =
{
    sAnim_GeneralFrame0,
    sAnim_Qwilfish_1,
};

static const union AnimCmd *const sAnims_Scizor[] =
{
    sAnim_GeneralFrame0,
    sAnim_Scizor_1,
};

static const union AnimCmd *const sAnims_Shuckle[] =
{
    sAnim_GeneralFrame0,
    sAnim_Shuckle_1,
};

static const union AnimCmd *const sAnims_Heracross[] =
{
    sAnim_GeneralFrame0,
    sAnim_Heracross_1,
    sAnim_Heracross_2,
};

static const union AnimCmd *const sAnims_Sneasel[] =
{
    sAnim_GeneralFrame0,
    sAnim_Sneasel_1,
};

static const union AnimCmd *const sAnims_Teddiursa[] =
{
    sAnim_GeneralFrame0,
    sAnim_Teddiursa_1,
};

static const union AnimCmd *const sAnims_Ursaring[] =
{
    sAnim_GeneralFrame0,
    sAnim_Ursaring_1,
};

static const union AnimCmd *const sAnims_Slugma[] =
{
    sAnim_GeneralFrame0,
    sAnim_Slugma_1,
    sAnim_Slugma_2,
};

static const union AnimCmd *const sAnims_Magcargo[] =
{
    sAnim_GeneralFrame0,
    sAnim_Magcargo_1,
    sAnim_Magcargo_2,
};

static const union AnimCmd *const sAnims_Swinub[] =
{
    sAnim_GeneralFrame0,
    sAnim_Swinub_1,
};

static const union AnimCmd *const sAnims_Piloswine[] =
{
    sAnim_GeneralFrame0,
    sAnim_Piloswine_1,
};

static const union AnimCmd *const sAnims_Corsola[] =
{
    sAnim_GeneralFrame0,
    sAnim_Corsola_1,
    sAnim_Corsola_2,
};

static const union AnimCmd *const sAnims_Remoraid[] =
{
    sAnim_GeneralFrame0,
    sAnim_Remoraid_1,
};

static const union AnimCmd *const sAnims_Octillery[] =
{
    sAnim_GeneralFrame0,
    sAnim_Octillery_1,
};

static const union AnimCmd *const sAnims_Delibird[] =
{
    sAnim_GeneralFrame0,
    sAnim_Delibird_1,
};

static const union AnimCmd *const sAnims_Mantine[] =
{
    sAnim_GeneralFrame0,
    sAnim_Mantine_1,
};

static const union AnimCmd *const sAnims_Skarmory[] =
{
    sAnim_GeneralFrame0,
    sAnim_Skarmory_1,
    sAnim_Skarmory_2,
};

static const union AnimCmd *const sAnims_Houndour[] =
{
    sAnim_GeneralFrame0,
    sAnim_Houndour_1,
};

static const union AnimCmd *const sAnims_Houndoom[] =
{
    sAnim_GeneralFrame0,
    sAnim_Houndoom_1,
};

static const union AnimCmd *const sAnims_Kingdra[] =
{
    sAnim_GeneralFrame0,
    sAnim_Kingdra_1,
    sAnim_Kingdra_2,
};

static const union AnimCmd *const sAnims_Phanpy[] =
{
    sAnim_GeneralFrame0,
    sAnim_Phanpy_1,
    sAnim_Phanpy_2,
};

static const union AnimCmd *const sAnims_Donphan[] =
{
    sAnim_GeneralFrame0,
    sAnim_Donphan_1,
    sAnim_Donphan_2,
};

static const union AnimCmd *const sAnims_Porygon2[] =
{
    sAnim_GeneralFrame0,
    sAnim_Porygon2_1,
};

static const union AnimCmd *const sAnims_Stantler[] =
{
    sAnim_GeneralFrame0,
    sAnim_Stantler_1,
};

static const union AnimCmd *const sAnims_Smeargle[] =
{
    sAnim_GeneralFrame0,
    sAnim_Smeargle_1,
};

static const union AnimCmd *const sAnims_Tyrogue[] =
{
    sAnim_GeneralFrame0,
    sAnim_Tyrogue_1,
};

static const union AnimCmd *const sAnims_Hitmontop[] =
{
    sAnim_GeneralFrame0,
    sAnim_Hitmontop_1,
};

static const union AnimCmd *const sAnims_Smoochum[] =
{
    sAnim_GeneralFrame0,
    sAnim_Smoochum_1,
};

static const union AnimCmd *const sAnims_Elekid[] =
{
    sAnim_GeneralFrame0,
    sAnim_Elekid_1,
};

static const union AnimCmd *const sAnims_Magby[] =
{
    sAnim_GeneralFrame0,
    sAnim_Magby_1,
};

static const union AnimCmd *const sAnims_Miltank[] =
{
    sAnim_GeneralFrame0,
    sAnim_Miltank_1,
};

static const union AnimCmd *const sAnims_Blissey[] =
{
    sAnim_GeneralFrame0,
    sAnim_Blissey_1,
};

static const union AnimCmd *const sAnims_Raikou[] =
{
    sAnim_GeneralFrame0,
    sAnim_Raikou_1,
};

static const union AnimCmd *const sAnims_Entei[] =
{
    sAnim_GeneralFrame0,
    sAnim_Entei_1,
};

static const union AnimCmd *const sAnims_Suicune[] =
{
    sAnim_GeneralFrame0,
    sAnim_Suicune_1,
};

static const union AnimCmd *const sAnims_Larvitar[] =
{
    sAnim_GeneralFrame0,
    sAnim_Larvitar_1,
};

static const union AnimCmd *const sAnims_Pupitar[] =
{
    sAnim_GeneralFrame0,
    sAnim_Pupitar_1,
};

static const union AnimCmd *const sAnims_Tyranitar[] =
{
    sAnim_GeneralFrame0,
    sAnim_Tyranitar_1,
};

static const union AnimCmd *const sAnims_Lugia[] =
{
    sAnim_GeneralFrame0,
    sAnim_Lugia_1,
};

static const union AnimCmd *const sAnims_HoOh[] =
{
    sAnim_GeneralFrame0,
    sAnim_HoOh_1,
};

static const union AnimCmd *const sAnims_Celebi[] =
{
    sAnim_GeneralFrame0,
    sAnim_Celebi_1,
};

static const union AnimCmd *const sAnims_OldUnownB[] =
{
    sAnim_GeneralFrame0,
    sAnim_OldUnownB_1,
};

static const union AnimCmd *const sAnims_Treecko[] =
{
    sAnim_GeneralFrame0,
    sAnim_Treecko_1,
};

static const union AnimCmd *const sAnims_Grovyle[] =
{
    sAnim_GeneralFrame0,
    sAnim_Grovyle_1,
};

static const union AnimCmd *const sAnims_Sceptile[] =
{
    sAnim_GeneralFrame0,
    sAnim_Sceptile_1,
};

static const union AnimCmd *const sAnims_Torchic[] =
{
    sAnim_GeneralFrame0,
    sAnim_Torchic_1,
};

static const union AnimCmd *const sAnims_Combusken[] =
{
    sAnim_GeneralFrame0,
    sAnim_Combusken_1,
};

static const union AnimCmd *const sAnims_Blaziken[] =
{
    sAnim_GeneralFrame0,
    sAnim_Blaziken_1,
    sAnim_Blaziken_2,
    sAnim_Blaziken_3,
    sAnim_Blaziken_4,
};

static const union AnimCmd *const sAnims_Mudkip[] =
{
    sAnim_GeneralFrame0,
    sAnim_Mudkip_1,
};

static const union AnimCmd *const sAnims_Marshtomp[] =
{
    sAnim_GeneralFrame0,
    sAnim_Marshtomp_1,
};

static const union AnimCmd *const sAnims_Swampert[] =
{
    sAnim_GeneralFrame0,
    sAnim_Swampert_1,
};

static const union AnimCmd *const sAnims_Poochyena[] =
{
    sAnim_GeneralFrame0,
    sAnim_Poochyena_1,
};

static const union AnimCmd *const sAnims_Mightyena[] =
{
    sAnim_GeneralFrame0,
    sAnim_Mightyena_1,
};

static const union AnimCmd *const sAnims_Zigzagoon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Zigzagoon_1,
};

static const union AnimCmd *const sAnims_Linoone[] =
{
    sAnim_GeneralFrame0,
    sAnim_Linoone_1,
};

static const union AnimCmd *const sAnims_Wurmple[] =
{
    sAnim_GeneralFrame0,
    sAnim_Wurmple_1,
};

static const union AnimCmd *const sAnims_Silcoon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Silcoon_1,
    sAnim_Silcoon_2,
};

static const union AnimCmd *const sAnims_Beautifly[] =
{
    sAnim_GeneralFrame0,
    sAnim_Beautifly_1,
    sAnim_Beautifly_2,
};

static const union AnimCmd *const sAnims_Cascoon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Cascoon_1,
    sAnim_Cascoon_2,
};

static const union AnimCmd *const sAnims_Dustox[] =
{
    sAnim_GeneralFrame0,
    sAnim_Dustox_1,
    sAnim_Dustox_2,
};

static const union AnimCmd *const sAnims_Lotad[] =
{
    sAnim_GeneralFrame0,
    sAnim_Lotad_1,
};

static const union AnimCmd *const sAnims_Lombre[] =
{
    sAnim_GeneralFrame0,
    sAnim_Lombre_1,
};

static const union AnimCmd *const sAnims_Ludicolo[] =
{
    sAnim_GeneralFrame0,
    sAnim_Ludicolo_1,
};

static const union AnimCmd *const sAnims_Seedot[] =
{
    sAnim_GeneralFrame0,
    sAnim_Seedot_1,
};

static const union AnimCmd *const sAnims_Nuzleaf[] =
{
    sAnim_GeneralFrame0,
    sAnim_Nuzleaf_1,
};

static const union AnimCmd *const sAnims_Shiftry[] =
{
    sAnim_GeneralFrame0,
    sAnim_Shiftry_1,
};

static const union AnimCmd *const sAnims_Nincada[] =
{
    sAnim_GeneralFrame0,
    sAnim_Nincada_1,
};

static const union AnimCmd *const sAnims_Ninjask[] =
{
    sAnim_GeneralFrame0,
    sAnim_Ninjask_1,
};

static const union AnimCmd *const sAnims_Shedinja[] =
{
    sAnim_GeneralFrame0,
    sAnim_Shedinja_1,
};

static const union AnimCmd *const sAnims_Taillow[] =
{
    sAnim_GeneralFrame0,
    sAnim_Taillow_1,
};

static const union AnimCmd *const sAnims_Swellow[] =
{
    sAnim_GeneralFrame0,
    sAnim_Swellow_1,
};

static const union AnimCmd *const sAnims_Shroomish[] =
{
    sAnim_GeneralFrame0,
    sAnim_Shroomish_1,
};

static const union AnimCmd *const sAnims_Breloom[] =
{
    sAnim_GeneralFrame0,
    sAnim_Breloom_1,
};

static const union AnimCmd *const sAnims_Spinda[] =
{
    sAnim_GeneralFrame0,
};

static const union AnimCmd *const sAnims_Wingull[] =
{
    sAnim_GeneralFrame0,
    sAnim_Wingull_1,
};

static const union AnimCmd *const sAnims_Pelipper[] =
{
    sAnim_GeneralFrame0,
    sAnim_Pelipper_1,
};

static const union AnimCmd *const sAnims_Surskit[] =
{
    sAnim_GeneralFrame0,
    sAnim_Surskit_1,
    sAnim_Surskit_2,
};

static const union AnimCmd *const sAnims_Masquerain[] =
{
    sAnim_GeneralFrame0,
    sAnim_Masquerain_1,
    sAnim_Masquerain_2,
};

static const union AnimCmd *const sAnims_Wailmer[] =
{
    sAnim_GeneralFrame0,
    sAnim_Wailmer_1,
};

static const union AnimCmd *const sAnims_Wailord[] =
{
    sAnim_GeneralFrame0,
    sAnim_Wailord_1,
};

static const union AnimCmd *const sAnims_Skitty[] =
{
    sAnim_GeneralFrame0,
    sAnim_Skitty_1,
};

static const union AnimCmd *const sAnims_Delcatty[] =
{
    sAnim_GeneralFrame0,
    sAnim_Delcatty_1,
};

static const union AnimCmd *const sAnims_Kecleon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Kecleon_1,
};

static const union AnimCmd *const sAnims_Baltoy[] =
{
    sAnim_GeneralFrame0,
    sAnim_Baltoy_1,
};

static const union AnimCmd *const sAnims_Claydol[] =
{
    sAnim_GeneralFrame0,
    sAnim_Claydol_1,
};

static const union AnimCmd *const sAnims_Nosepass[] =
{
    sAnim_GeneralFrame0,
    sAnim_Nosepass_1,
};

static const union AnimCmd *const sAnims_Torkoal[] =
{
    sAnim_GeneralFrame0,
    sAnim_Torkoal_1,
};

static const union AnimCmd *const sAnims_Sableye[] =
{
    sAnim_GeneralFrame0,
    sAnim_Sableye_1,
};

static const union AnimCmd *const sAnims_Barboach[] =
{
    sAnim_GeneralFrame0,
    sAnim_Barboach_1,
};

static const union AnimCmd *const sAnims_Whiscash[] =
{
    sAnim_GeneralFrame0,
    sAnim_Whiscash_1,
};

static const union AnimCmd *const sAnims_Luvdisc[] =
{
    sAnim_GeneralFrame0,
    sAnim_Luvdisc_1,
};

static const union AnimCmd *const sAnims_Corphish[] =
{
    sAnim_GeneralFrame0,
    sAnim_Corphish_1,
};

static const union AnimCmd *const sAnims_Crawdaunt[] =
{
    sAnim_GeneralFrame0,
    sAnim_Crawdaunt_1,
};

static const union AnimCmd *const sAnims_Feebas[] =
{
    sAnim_GeneralFrame0,
    sAnim_Feebas_1,
};

static const union AnimCmd *const sAnims_Milotic[] =
{
    sAnim_GeneralFrame0,
    sAnim_Milotic_1,
};

static const union AnimCmd *const sAnims_Carvanha[] =
{
    sAnim_GeneralFrame0,
    sAnim_Carvanha_1,
};

static const union AnimCmd *const sAnims_Sharpedo[] =
{
    sAnim_GeneralFrame0,
    sAnim_Sharpedo_1,
};

static const union AnimCmd *const sAnims_Trapinch[] =
{
    sAnim_GeneralFrame0,
    sAnim_Trapinch_1,
};

static const union AnimCmd *const sAnims_Vibrava[] =
{
    sAnim_GeneralFrame0,
    sAnim_Vibrava_1,
};

static const union AnimCmd *const sAnims_Flygon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Flygon_1,
};

static const union AnimCmd *const sAnims_Makuhita[] =
{
    sAnim_GeneralFrame0,
    sAnim_Makuhita_1,
};

static const union AnimCmd *const sAnims_Hariyama[] =
{
    sAnim_GeneralFrame0,
    sAnim_Hariyama_1,
};

static const union AnimCmd *const sAnims_Electrike[] =
{
    sAnim_GeneralFrame0,
    sAnim_Electrike_1,
};

static const union AnimCmd *const sAnims_Manectric[] =
{
    sAnim_GeneralFrame0,
    sAnim_Manectric_1,
};

static const union AnimCmd *const sAnims_Numel[] =
{
    sAnim_GeneralFrame0,
    sAnim_Numel_1,
};

static const union AnimCmd *const sAnims_Camerupt[] =
{
    sAnim_GeneralFrame0,
    sAnim_Camerupt_1,
};

static const union AnimCmd *const sAnims_Spheal[] =
{
    sAnim_GeneralFrame0,
    sAnim_Spheal_1,
};

static const union AnimCmd *const sAnims_Sealeo[] =
{
    sAnim_GeneralFrame0,
    sAnim_Sealeo_1,
};

static const union AnimCmd *const sAnims_Walrein[] =
{
    sAnim_GeneralFrame0,
    sAnim_Walrein_1,
};

static const union AnimCmd *const sAnims_Cacnea[] =
{
    sAnim_GeneralFrame0,
    sAnim_Cacnea_1,
};

static const union AnimCmd *const sAnims_Cacturne[] =
{
    sAnim_GeneralFrame0,
    sAnim_Cacturne_1,
};

static const union AnimCmd *const sAnims_Snorunt[] =
{
    sAnim_GeneralFrame0,
    sAnim_Snorunt_1,
};

static const union AnimCmd *const sAnims_Glalie[] =
{
    sAnim_GeneralFrame0,
    sAnim_Glalie_1,
};

static const union AnimCmd *const sAnims_Lunatone[] =
{
    sAnim_GeneralFrame0,
    sAnim_Lunatone_1,
    sAnim_Lunatone_2,
};

static const union AnimCmd *const sAnims_Solrock[] =
{
    sAnim_GeneralFrame0,
    sAnim_Solrock_1,
    sAnim_Solrock_2,
};

static const union AnimCmd *const sAnims_Azurill[] =
{
    sAnim_GeneralFrame0,
    sAnim_Azurill_1,
};

static const union AnimCmd *const sAnims_Spoink[] =
{
    sAnim_GeneralFrame0,
    sAnim_Spoink_1,
};

static const union AnimCmd *const sAnims_Grumpig[] =
{
    sAnim_GeneralFrame0,
    sAnim_Grumpig_1,
};

static const union AnimCmd *const sAnims_Plusle[] =
{
    sAnim_GeneralFrame0,
    sAnim_Plusle_1,
};

static const union AnimCmd *const sAnims_Minun[] =
{
    sAnim_GeneralFrame0,
    sAnim_Minun_1,
};

static const union AnimCmd *const sAnims_Mawile[] =
{
    sAnim_GeneralFrame0,
    sAnim_Mawile_1,
};

static const union AnimCmd *const sAnims_Meditite[] =
{
    sAnim_GeneralFrame0,
    sAnim_Meditite_1,
};

static const union AnimCmd *const sAnims_Medicham[] =
{
    sAnim_GeneralFrame0,
    sAnim_Medicham_1,
};

static const union AnimCmd *const sAnims_Swablu[] =
{
    sAnim_GeneralFrame0,
    sAnim_Swablu_1,
    sAnim_Swablu_2,
};

static const union AnimCmd *const sAnims_Altaria[] =
{
    sAnim_GeneralFrame0,
    sAnim_Altaria_1,
    sAnim_Altaria_2,
};

static const union AnimCmd *const sAnims_Wynaut[] =
{
    sAnim_GeneralFrame0,
    sAnim_Wynaut_1,
};

static const union AnimCmd *const sAnims_Duskull[] =
{
    sAnim_GeneralFrame0,
    sAnim_Duskull_1,
};

static const union AnimCmd *const sAnims_Dusclops[] =
{
    sAnim_GeneralFrame0,
    sAnim_Dusclops_1,
};

static const union AnimCmd *const sAnims_Roselia[] =
{
    sAnim_GeneralFrame0,
    sAnim_Roselia_1,
};

static const union AnimCmd *const sAnims_Slakoth[] =
{
    sAnim_GeneralFrame0,
    sAnim_Slakoth_1,
};

static const union AnimCmd *const sAnims_Vigoroth[] =
{
    sAnim_GeneralFrame0,
    sAnim_Vigoroth_1,
};

static const union AnimCmd *const sAnims_Slaking[] =
{
    sAnim_GeneralFrame0,
    sAnim_Slaking_1,
};

static const union AnimCmd *const sAnims_Gulpin[] =
{
    sAnim_GeneralFrame0,
    sAnim_Gulpin_1,
};

static const union AnimCmd *const sAnims_Swalot[] =
{
    sAnim_GeneralFrame0,
    sAnim_Swalot_1,
};

static const union AnimCmd *const sAnims_Tropius[] =
{
    sAnim_GeneralFrame0,
    sAnim_Tropius_1,
};

static const union AnimCmd *const sAnims_Whismur[] =
{
    sAnim_GeneralFrame0,
    sAnim_Whismur_1,
};

static const union AnimCmd *const sAnims_Loudred[] =
{
    sAnim_GeneralFrame0,
    sAnim_Loudred_1,
};

static const union AnimCmd *const sAnims_Exploud[] =
{
    sAnim_GeneralFrame0,
    sAnim_Exploud_1,
};

static const union AnimCmd *const sAnims_Clamperl[] =
{
    sAnim_GeneralFrame0,
    sAnim_Clamperl_1,
};

static const union AnimCmd *const sAnims_Huntail[] =
{
    sAnim_GeneralFrame0,
    sAnim_Huntail_1,
};

static const union AnimCmd *const sAnims_Gorebyss[] =
{
    sAnim_GeneralFrame0,
    sAnim_Gorebyss_1,
};

static const union AnimCmd *const sAnims_Absol[] =
{
    sAnim_GeneralFrame0,
    sAnim_Absol_1,
};

static const union AnimCmd *const sAnims_Shuppet[] =
{
    sAnim_GeneralFrame0,
    sAnim_Shuppet_1,
};

static const union AnimCmd *const sAnims_Banette[] =
{
    sAnim_GeneralFrame0,
    sAnim_Banette_1,
};

static const union AnimCmd *const sAnims_Seviper[] =
{
    sAnim_GeneralFrame0,
    sAnim_Seviper_1,
};

static const union AnimCmd *const sAnims_Zangoose[] =
{
    sAnim_GeneralFrame0,
    sAnim_Zangoose_1,
};

static const union AnimCmd *const sAnims_Relicanth[] =
{
    sAnim_GeneralFrame0,
    sAnim_Relicanth_1,
};

static const union AnimCmd *const sAnims_Aron[] =
{
    sAnim_GeneralFrame0,
    sAnim_Aron_1,
};

static const union AnimCmd *const sAnims_Lairon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Lairon_1,
};

static const union AnimCmd *const sAnims_Aggron[] =
{
    sAnim_GeneralFrame0,
    sAnim_Aggron_1,
};

static const union AnimCmd *const sAnims_Castform[] =
{
    sAnim_Castform_0,
    sAnim_Castform_1,
    sAnim_Castform_2,
    sAnim_Castform_3,
};

static const union AnimCmd *const sAnims_Volbeat[] =
{
    sAnim_GeneralFrame0,
    sAnim_Volbeat_1,
};

static const union AnimCmd *const sAnims_Illumise[] =
{
    sAnim_GeneralFrame0,
    sAnim_Illumise_1,
};

static const union AnimCmd *const sAnims_Lileep[] =
{
    sAnim_GeneralFrame0,
    sAnim_Lileep_1,
};

static const union AnimCmd *const sAnims_Cradily[] =
{
    sAnim_GeneralFrame0,
    sAnim_Cradily_1,
};

static const union AnimCmd *const sAnims_Anorith[] =
{
    sAnim_GeneralFrame0,
    sAnim_Anorith_1,
};

static const union AnimCmd *const sAnims_Armaldo[] =
{
    sAnim_GeneralFrame0,
    sAnim_Armaldo_1,
};

static const union AnimCmd *const sAnims_Ralts[] =
{
    sAnim_GeneralFrame0,
    sAnim_Ralts_1,
};

static const union AnimCmd *const sAnims_Kirlia[] =
{
    sAnim_GeneralFrame0,
    sAnim_Kirlia_1,
};

static const union AnimCmd *const sAnims_Gardevoir[] =
{
    sAnim_GeneralFrame0,
    sAnim_Gardevoir_1,
};

static const union AnimCmd *const sAnims_Bagon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Bagon_1,
};

static const union AnimCmd *const sAnims_Shelgon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Shelgon_1,
};

static const union AnimCmd *const sAnims_Salamence[] =
{
    sAnim_GeneralFrame0,
    sAnim_Salamence_1,
};

static const union AnimCmd *const sAnims_Beldum[] =
{
    sAnim_GeneralFrame0,
    sAnim_Beldum_1,
};

static const union AnimCmd *const sAnims_Metang[] =
{
    sAnim_GeneralFrame0,
    sAnim_Metang_1,
};

static const union AnimCmd *const sAnims_Metagross[] =
{
    sAnim_GeneralFrame0,
    sAnim_Metagross_1,
};

static const union AnimCmd *const sAnims_Regirock[] =
{
    sAnim_GeneralFrame0,
    sAnim_Regirock_1,
    sAnim_Regirock_2,
};

static const union AnimCmd *const sAnims_Regice[] =
{
    sAnim_GeneralFrame0,
    sAnim_Regice_1,
};

static const union AnimCmd *const sAnims_Registeel[] =
{
    sAnim_GeneralFrame0,
    sAnim_Registeel_1,
    sAnim_Registeel_2,
};

static const union AnimCmd *const sAnims_Kyogre[] =
{
    sAnim_GeneralFrame0,
    sAnim_Kyogre_1,
    sAnim_Kyogre_2,
};

static const union AnimCmd *const sAnims_Groudon[] =
{
    sAnim_GeneralFrame0,
    sAnim_Groudon_1,
    sAnim_Groudon_2,
};

static const union AnimCmd *const sAnims_Rayquaza[] =
{
    sAnim_GeneralFrame0,
    sAnim_Rayquaza_1,
    sAnim_Rayquaza_2,
};

static const union AnimCmd *const sAnims_Latias[] =
{
    sAnim_GeneralFrame0,
    sAnim_Latias_1,
    sAnim_Latias_2,
};

static const union AnimCmd *const sAnims_Latios[] =
{
    sAnim_GeneralFrame0,
    sAnim_Latios_1,
    sAnim_Latios_2,
};

static const union AnimCmd *const sAnims_Jirachi[] =
{
    sAnim_GeneralFrame0,
    sAnim_Jirachi_1,
    sAnim_Jirachi_2,
};

static const union AnimCmd *const sAnims_Deoxys[] =
{
    sAnim_GeneralFrame0,
    sAnim_Deoxys_1,
    sAnim_Deoxys_2,
};

static const union AnimCmd *const sAnims_Chimecho[] =
{
    sAnim_GeneralFrame0,
    sAnim_Chimecho_1,
};

static const union AnimCmd *const sAnims_Egg[] =
{
    sAnim_GeneralFrame0,
    sAnim_Egg_1,
};

static const union AnimCmd *const sAnims_UnownB[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownB_1,
};

static const union AnimCmd *const sAnims_UnownC[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownC_1,
};

static const union AnimCmd *const sAnims_UnownD[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownD_1,
};

static const union AnimCmd *const sAnims_UnownE[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownE_1,
};

static const union AnimCmd *const sAnims_UnownF[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownF_1,
};

static const union AnimCmd *const sAnims_UnownG[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownG_1,
};

static const union AnimCmd *const sAnims_UnownH[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownH_1,
};

static const union AnimCmd *const sAnims_UnownI[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownI_1,
};

static const union AnimCmd *const sAnims_UnownJ[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownJ_1,
};

static const union AnimCmd *const sAnims_UnownK[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownK_1,
};

static const union AnimCmd *const sAnims_UnownL[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownL_1,
};

static const union AnimCmd *const sAnims_UnownM[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownM_1,
};

static const union AnimCmd *const sAnims_UnownN[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownN_1,
};

static const union AnimCmd *const sAnims_UnownO[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownO_1,
};

static const union AnimCmd *const sAnims_UnownP[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownP_1,
};

static const union AnimCmd *const sAnims_UnownQ[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownQ_1,
};

static const union AnimCmd *const sAnims_UnownR[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownR_1,
};

static const union AnimCmd *const sAnims_UnownS[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownS_1,
};

static const union AnimCmd *const sAnims_UnownT[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownT_1,
};

static const union AnimCmd *const sAnims_UnownU[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownU_1,
};

static const union AnimCmd *const sAnims_UnownV[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownV_1,
};

static const union AnimCmd *const sAnims_UnownW[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownW_1,
};

static const union AnimCmd *const sAnims_UnownX[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownX_1,
};

static const union AnimCmd *const sAnims_UnownY[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownY_1,
};

static const union AnimCmd *const sAnims_UnownZ[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownZ_1,
};

static const union AnimCmd *const sAnims_UnownEMark[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownEMark_1,
};

static const union AnimCmd *const sAnims_UnownQMark[] =
{
    sAnim_GeneralFrame0,
    sAnim_UnownQMark_1,
};

// 0x82DD33C

const union AnimCmd *const *const gMonFrontAnimsPtrTable[] =
{
    [SPECIES_NONE] = sAnims_None,
    [SPECIES_BULBASAUR] = sAnims_Bulbasaur,
    [SPECIES_IVYSAUR] = sAnims_Ivysaur,
    [SPECIES_VENUSAUR] = sAnims_Venusaur,
    [SPECIES_CHARMANDER] = sAnims_Charmander,
    [SPECIES_CHARMELEON] = sAnims_Charmeleon,
    [SPECIES_CHARIZARD] = sAnims_Charizard,
    [SPECIES_SQUIRTLE] = sAnims_Squirtle,
    [SPECIES_WARTORTLE] = sAnims_Wartortle,
    [SPECIES_BLASTOISE] = sAnims_Blastoise,
    [SPECIES_CATERPIE] = sAnims_Caterpie,
    [SPECIES_METAPOD] = sAnims_Metapod,
    [SPECIES_BUTTERFREE] = sAnims_Butterfree,
    [SPECIES_WEEDLE] = sAnims_Weedle,
    [SPECIES_KAKUNA] = sAnims_Kakuna,
    [SPECIES_BEEDRILL] = sAnims_Beedrill,
    [SPECIES_PIDGEY] = sAnims_Pidgey,
    [SPECIES_PIDGEOTTO] = sAnims_Pidgeotto,
    [SPECIES_PIDGEOT] = sAnims_Pidgeot,
    [SPECIES_RATTATA] = sAnims_Rattata,
    [SPECIES_RATICATE] = sAnims_Raticate,
    [SPECIES_SPEAROW] = sAnims_Spearow,
    [SPECIES_FEAROW] = sAnims_Fearow,
    [SPECIES_EKANS] = sAnims_Ekans,
    [SPECIES_ARBOK] = sAnims_Arbok,
    [SPECIES_PIKACHU] = sAnims_Pikachu,
    [SPECIES_RAICHU] = sAnims_Raichu,
    [SPECIES_SANDSHREW] = sAnims_Sandshrew,
    [SPECIES_SANDSLASH] = sAnims_Sandslash,
    [SPECIES_NIDORAN_F] = sAnims_NidoranF,
    [SPECIES_NIDORINA] = sAnims_Nidorina,
    [SPECIES_NIDOQUEEN] = sAnims_Nidoqueen,
    [SPECIES_NIDORAN_M] = sAnims_NidoranM,
    [SPECIES_NIDORINO] = sAnims_Nidorino,
    [SPECIES_NIDOKING] = sAnims_Nidoking,
    [SPECIES_CLEFAIRY] = sAnims_Clefairy,
    [SPECIES_CLEFABLE] = sAnims_Clefable,
    [SPECIES_VULPIX] = sAnims_Vulpix,
    [SPECIES_NINETALES] = sAnims_Ninetales,
    [SPECIES_JIGGLYPUFF] = sAnims_Jigglypuff,
    [SPECIES_WIGGLYTUFF] = sAnims_Wigglytuff,
    [SPECIES_ZUBAT] = sAnims_Zubat,
    [SPECIES_GOLBAT] = sAnims_Golbat,
    [SPECIES_ODDISH] = sAnims_Oddish,
    [SPECIES_GLOOM] = sAnims_Gloom,
    [SPECIES_VILEPLUME] = sAnims_Vileplume,
    [SPECIES_PARAS] = sAnims_Paras,
    [SPECIES_PARASECT] = sAnims_Parasect,
    [SPECIES_VENONAT] = sAnims_Venonat,
    [SPECIES_VENOMOTH] = sAnims_Venomoth,
    [SPECIES_DIGLETT] = sAnims_Diglett,
    [SPECIES_DUGTRIO] = sAnims_Dugtrio,
    [SPECIES_MEOWTH] = sAnims_Meowth,
    [SPECIES_PERSIAN] = sAnims_Persian,
    [SPECIES_PSYDUCK] = sAnims_Psyduck,
    [SPECIES_GOLDUCK] = sAnims_Golduck,
    [SPECIES_MANKEY] = sAnims_Mankey,
    [SPECIES_PRIMEAPE] = sAnims_Primeape,
    [SPECIES_GROWLITHE] = sAnims_Growlithe,
    [SPECIES_ARCANINE] = sAnims_Arcanine,
    [SPECIES_POLIWAG] = sAnims_Poliwag,
    [SPECIES_POLIWHIRL] = sAnims_Poliwhirl,
    [SPECIES_POLIWRATH] = sAnims_Poliwrath,
    [SPECIES_ABRA] = sAnims_Abra,
    [SPECIES_KADABRA] = sAnims_Kadabra,
    [SPECIES_ALAKAZAM] = sAnims_Alakazam,
    [SPECIES_MACHOP] = sAnims_Machop,
    [SPECIES_MACHOKE] = sAnims_Machoke,
    [SPECIES_MACHAMP] = sAnims_Machamp,
    [SPECIES_BELLSPROUT] = sAnims_Bellsprout,
    [SPECIES_WEEPINBELL] = sAnims_Weepinbell,
    [SPECIES_VICTREEBEL] = sAnims_Victreebel,
    [SPECIES_TENTACOOL] = sAnims_Tentacool,
    [SPECIES_TENTACRUEL] = sAnims_Tentacruel,
    [SPECIES_GEODUDE] = sAnims_Geodude,
    [SPECIES_GRAVELER] = sAnims_Graveler,
    [SPECIES_GOLEM] = sAnims_Golem,
    [SPECIES_PONYTA] = sAnims_Ponyta,
    [SPECIES_RAPIDASH] = sAnims_Rapidash,
    [SPECIES_SLOWPOKE] = sAnims_Slowpoke,
    [SPECIES_SLOWBRO] = sAnims_Slowbro,
    [SPECIES_MAGNEMITE] = sAnims_Magnemite,
    [SPECIES_MAGNETON] = sAnims_Magneton,
    [SPECIES_FARFETCHD] = sAnims_Farfetchd,
    [SPECIES_DODUO] = sAnims_Doduo,
    [SPECIES_DODRIO] = sAnims_Dodrio,
    [SPECIES_SEEL] = sAnims_Seel,
    [SPECIES_DEWGONG] = sAnims_Dewgong,
    [SPECIES_GRIMER] = sAnims_Grimer,
    [SPECIES_MUK] = sAnims_Muk,
    [SPECIES_SHELLDER] = sAnims_Shellder,
    [SPECIES_CLOYSTER] = sAnims_Cloyster,
    [SPECIES_GASTLY] = sAnims_Gastly,
    [SPECIES_HAUNTER] = sAnims_Haunter,
    [SPECIES_GENGAR] = sAnims_Gengar,
    [SPECIES_ONIX] = sAnims_Onix,
    [SPECIES_DROWZEE] = sAnims_Drowzee,
    [SPECIES_HYPNO] = sAnims_Hypno,
    [SPECIES_KRABBY] = sAnims_Krabby,
    [SPECIES_KINGLER] = sAnims_Kingler,
    [SPECIES_VOLTORB] = sAnims_Voltorb,
    [SPECIES_ELECTRODE] = sAnims_Electrode,
    [SPECIES_EXEGGCUTE] = sAnims_Exeggcute,
    [SPECIES_EXEGGUTOR] = sAnims_Exeggutor,
    [SPECIES_CUBONE] = sAnims_Cubone,
    [SPECIES_MAROWAK] = sAnims_Marowak,
    [SPECIES_HITMONLEE] = sAnims_Hitmonlee,
    [SPECIES_HITMONCHAN] = sAnims_Hitmonchan,
    [SPECIES_LICKITUNG] = sAnims_Lickitung,
    [SPECIES_KOFFING] = sAnims_Koffing,
    [SPECIES_WEEZING] = sAnims_Weezing,
    [SPECIES_RHYHORN] = sAnims_Rhyhorn,
    [SPECIES_RHYDON] = sAnims_Rhydon,
    [SPECIES_CHANSEY] = sAnims_Chansey,
    [SPECIES_TANGELA] = sAnims_Tangela,
    [SPECIES_KANGASKHAN] = sAnims_Kangaskhan,
    [SPECIES_HORSEA] = sAnims_Horsea,
    [SPECIES_SEADRA] = sAnims_Seadra,
    [SPECIES_GOLDEEN] = sAnims_Goldeen,
    [SPECIES_SEAKING] = sAnims_Seaking,
    [SPECIES_STARYU] = sAnims_Staryu,
    [SPECIES_STARMIE] = sAnims_Starmie,
    [SPECIES_MR_MIME] = sAnims_MrMime,
    [SPECIES_SCYTHER] = sAnims_Scyther,
    [SPECIES_JYNX] = sAnims_Jynx,
    [SPECIES_ELECTABUZZ] = sAnims_Electabuzz,
    [SPECIES_MAGMAR] = sAnims_Magmar,
    [SPECIES_PINSIR] = sAnims_Pinsir,
    [SPECIES_TAUROS] = sAnims_Tauros,
    [SPECIES_MAGIKARP] = sAnims_Magikarp,
    [SPECIES_GYARADOS] = sAnims_Gyarados,
    [SPECIES_LAPRAS] = sAnims_Lapras,
    [SPECIES_DITTO] = sAnims_Ditto,
    [SPECIES_EEVEE] = sAnims_Eevee,
    [SPECIES_VAPOREON] = sAnims_Vaporeon,
    [SPECIES_JOLTEON] = sAnims_Jolteon,
    [SPECIES_FLAREON] = sAnims_Flareon,
    [SPECIES_PORYGON] = sAnims_Porygon,
    [SPECIES_OMANYTE] = sAnims_Omanyte,
    [SPECIES_OMASTAR] = sAnims_Omastar,
    [SPECIES_KABUTO] = sAnims_Kabuto,
    [SPECIES_KABUTOPS] = sAnims_Kabutops,
    [SPECIES_AERODACTYL] = sAnims_Aerodactyl,
    [SPECIES_SNORLAX] = sAnims_Snorlax,
    [SPECIES_ARTICUNO] = sAnims_Articuno,
    [SPECIES_ZAPDOS] = sAnims_Zapdos,
    [SPECIES_MOLTRES] = sAnims_Moltres,
    [SPECIES_DRATINI] = sAnims_Dratini,
    [SPECIES_DRAGONAIR] = sAnims_Dragonair,
    [SPECIES_DRAGONITE] = sAnims_Dragonite,
    [SPECIES_MEWTWO] = sAnims_Mewtwo,
    [SPECIES_MEW] = sAnims_Mew,
    [SPECIES_CHIKORITA] = sAnims_Chikorita,
    [SPECIES_BAYLEEF] = sAnims_Bayleef,
    [SPECIES_MEGANIUM] = sAnims_Meganium,
    [SPECIES_CYNDAQUIL] = sAnims_Cyndaquil,
    [SPECIES_QUILAVA] = sAnims_Quilava,
    [SPECIES_TYPHLOSION] = sAnims_Typhlosion,
    [SPECIES_TOTODILE] = sAnims_Totodile,
    [SPECIES_CROCONAW] = sAnims_Croconaw,
    [SPECIES_FERALIGATR] = sAnims_Feraligatr,
    [SPECIES_SENTRET] = sAnims_Sentret,
    [SPECIES_FURRET] = sAnims_Furret,
    [SPECIES_HOOTHOOT] = sAnims_Hoothoot,
    [SPECIES_NOCTOWL] = sAnims_Noctowl,
    [SPECIES_LEDYBA] = sAnims_Ledyba,
    [SPECIES_LEDIAN] = sAnims_Ledian,
    [SPECIES_SPINARAK] = sAnims_Spinarak,
    [SPECIES_ARIADOS] = sAnims_Ariados,
    [SPECIES_CROBAT] = sAnims_Crobat,
    [SPECIES_CHINCHOU] = sAnims_Chinchou,
    [SPECIES_LANTURN] = sAnims_Lanturn,
    [SPECIES_PICHU] = sAnims_Pichu,
    [SPECIES_CLEFFA] = sAnims_Cleffa,
    [SPECIES_IGGLYBUFF] = sAnims_Igglybuff,
    [SPECIES_TOGEPI] = sAnims_Togepi,
    [SPECIES_TOGETIC] = sAnims_Togetic,
    [SPECIES_NATU] = sAnims_Natu,
    [SPECIES_XATU] = sAnims_Xatu,
    [SPECIES_MAREEP] = sAnims_Mareep,
    [SPECIES_FLAAFFY] = sAnims_Flaaffy,
    [SPECIES_AMPHAROS] = sAnims_Ampharos,
    [SPECIES_BELLOSSOM] = sAnims_Bellossom,
    [SPECIES_MARILL] = sAnims_Marill,
    [SPECIES_AZUMARILL] = sAnims_Azumarill,
    [SPECIES_SUDOWOODO] = sAnims_Sudowoodo,
    [SPECIES_POLITOED] = sAnims_Politoed,
    [SPECIES_HOPPIP] = sAnims_Hoppip,
    [SPECIES_SKIPLOOM] = sAnims_Skiploom,
    [SPECIES_JUMPLUFF] = sAnims_Jumpluff,
    [SPECIES_AIPOM] = sAnims_Aipom,
    [SPECIES_SUNKERN] = sAnims_Sunkern,
    [SPECIES_SUNFLORA] = sAnims_Sunflora,
    [SPECIES_YANMA] = sAnims_Yanma,
    [SPECIES_WOOPER] = sAnims_Wooper,
    [SPECIES_QUAGSIRE] = sAnims_Quagsire,
    [SPECIES_ESPEON] = sAnims_Espeon,
    [SPECIES_UMBREON] = sAnims_Umbreon,
    [SPECIES_MURKROW] = sAnims_Murkrow,
    [SPECIES_SLOWKING] = sAnims_Slowking,
    [SPECIES_MISDREAVUS] = sAnims_Misdreavus,
    [SPECIES_UNOWN] = sAnims_Unown,
    [SPECIES_WOBBUFFET] = sAnims_Wobbuffet,
    [SPECIES_GIRAFARIG] = sAnims_Girafarig,
    [SPECIES_PINECO] = sAnims_Pineco,
    [SPECIES_FORRETRESS] = sAnims_Forretress,
    [SPECIES_DUNSPARCE] = sAnims_Dunsparce,
    [SPECIES_GLIGAR] = sAnims_Gligar,
    [SPECIES_STEELIX] = sAnims_Steelix,
    [SPECIES_SNUBBULL] = sAnims_Snubbull,
    [SPECIES_GRANBULL] = sAnims_Granbull,
    [SPECIES_QWILFISH] = sAnims_Qwilfish,
    [SPECIES_SCIZOR] = sAnims_Scizor,
    [SPECIES_SHUCKLE] = sAnims_Shuckle,
    [SPECIES_HERACROSS] = sAnims_Heracross,
    [SPECIES_SNEASEL] = sAnims_Sneasel,
    [SPECIES_TEDDIURSA] = sAnims_Teddiursa,
    [SPECIES_URSARING] = sAnims_Ursaring,
    [SPECIES_SLUGMA] = sAnims_Slugma,
    [SPECIES_MAGCARGO] = sAnims_Magcargo,
    [SPECIES_SWINUB] = sAnims_Swinub,
    [SPECIES_PILOSWINE] = sAnims_Piloswine,
    [SPECIES_CORSOLA] = sAnims_Corsola,
    [SPECIES_REMORAID] = sAnims_Remoraid,
    [SPECIES_OCTILLERY] = sAnims_Octillery,
    [SPECIES_DELIBIRD] = sAnims_Delibird,
    [SPECIES_MANTINE] = sAnims_Mantine,
    [SPECIES_SKARMORY] = sAnims_Skarmory,
    [SPECIES_HOUNDOUR] = sAnims_Houndour,
    [SPECIES_HOUNDOOM] = sAnims_Houndoom,
    [SPECIES_KINGDRA] = sAnims_Kingdra,
    [SPECIES_PHANPY] = sAnims_Phanpy,
    [SPECIES_DONPHAN] = sAnims_Donphan,
    [SPECIES_PORYGON2] = sAnims_Porygon2,
    [SPECIES_STANTLER] = sAnims_Stantler,
    [SPECIES_SMEARGLE] = sAnims_Smeargle,
    [SPECIES_TYROGUE] = sAnims_Tyrogue,
    [SPECIES_HITMONTOP] = sAnims_Hitmontop,
    [SPECIES_SMOOCHUM] = sAnims_Smoochum,
    [SPECIES_ELEKID] = sAnims_Elekid,
    [SPECIES_MAGBY] = sAnims_Magby,
    [SPECIES_MILTANK] = sAnims_Miltank,
    [SPECIES_BLISSEY] = sAnims_Blissey,
    [SPECIES_RAIKOU] = sAnims_Raikou,
    [SPECIES_ENTEI] = sAnims_Entei,
    [SPECIES_SUICUNE] = sAnims_Suicune,
    [SPECIES_LARVITAR] = sAnims_Larvitar,
    [SPECIES_PUPITAR] = sAnims_Pupitar,
    [SPECIES_TYRANITAR] = sAnims_Tyranitar,
    [SPECIES_LUGIA] = sAnims_Lugia,
    [SPECIES_HO_OH] = sAnims_HoOh,
    [SPECIES_CELEBI] = sAnims_Celebi,
    [SPECIES_OLD_UNOWN_B] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_C] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_D] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_E] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_F] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_G] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_H] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_I] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_J] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_K] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_L] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_M] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_N] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_O] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_P] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_Q] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_R] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_S] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_T] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_U] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_V] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_W] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_X] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_Y] = sAnims_OldUnownB,
    [SPECIES_OLD_UNOWN_Z] = sAnims_OldUnownB,
    [SPECIES_TREECKO] = sAnims_Treecko,
    [SPECIES_GROVYLE] = sAnims_Grovyle,
    [SPECIES_SCEPTILE] = sAnims_Sceptile,
    [SPECIES_TORCHIC] = sAnims_Torchic,
    [SPECIES_COMBUSKEN] = sAnims_Combusken,
    [SPECIES_BLAZIKEN] = sAnims_Blaziken,
    [SPECIES_MUDKIP] = sAnims_Mudkip,
    [SPECIES_MARSHTOMP] = sAnims_Marshtomp,
    [SPECIES_SWAMPERT] = sAnims_Swampert,
    [SPECIES_POOCHYENA] = sAnims_Poochyena,
    [SPECIES_MIGHTYENA] = sAnims_Mightyena,
    [SPECIES_ZIGZAGOON] = sAnims_Zigzagoon,
    [SPECIES_LINOONE] = sAnims_Linoone,
    [SPECIES_WURMPLE] = sAnims_Wurmple,
    [SPECIES_SILCOON] = sAnims_Silcoon,
    [SPECIES_BEAUTIFLY] = sAnims_Beautifly,
    [SPECIES_CASCOON] = sAnims_Cascoon,
    [SPECIES_DUSTOX] = sAnims_Dustox,
    [SPECIES_LOTAD] = sAnims_Lotad,
    [SPECIES_LOMBRE] = sAnims_Lombre,
    [SPECIES_LUDICOLO] = sAnims_Ludicolo,
    [SPECIES_SEEDOT] = sAnims_Seedot,
    [SPECIES_NUZLEAF] = sAnims_Nuzleaf,
    [SPECIES_SHIFTRY] = sAnims_Shiftry,
    [SPECIES_NINCADA] = sAnims_Nincada,
    [SPECIES_NINJASK] = sAnims_Ninjask,
    [SPECIES_SHEDINJA] = sAnims_Shedinja,
    [SPECIES_TAILLOW] = sAnims_Taillow,
    [SPECIES_SWELLOW] = sAnims_Swellow,
    [SPECIES_SHROOMISH] = sAnims_Shroomish,
    [SPECIES_BRELOOM] = sAnims_Breloom,
    [SPECIES_SPINDA] = sAnims_Spinda,
    [SPECIES_WINGULL] = sAnims_Wingull,
    [SPECIES_PELIPPER] = sAnims_Pelipper,
    [SPECIES_SURSKIT] = sAnims_Surskit,
    [SPECIES_MASQUERAIN] = sAnims_Masquerain,
    [SPECIES_WAILMER] = sAnims_Wailmer,
    [SPECIES_WAILORD] = sAnims_Wailord,
    [SPECIES_SKITTY] = sAnims_Skitty,
    [SPECIES_DELCATTY] = sAnims_Delcatty,
    [SPECIES_KECLEON] = sAnims_Kecleon,
    [SPECIES_BALTOY] = sAnims_Baltoy,
    [SPECIES_CLAYDOL] = sAnims_Claydol,
    [SPECIES_NOSEPASS] = sAnims_Nosepass,
    [SPECIES_TORKOAL] = sAnims_Torkoal,
    [SPECIES_SABLEYE] = sAnims_Sableye,
    [SPECIES_BARBOACH] = sAnims_Barboach,
    [SPECIES_WHISCASH] = sAnims_Whiscash,
    [SPECIES_LUVDISC] = sAnims_Luvdisc,
    [SPECIES_CORPHISH] = sAnims_Corphish,
    [SPECIES_CRAWDAUNT] = sAnims_Crawdaunt,
    [SPECIES_FEEBAS] = sAnims_Feebas,
    [SPECIES_MILOTIC] = sAnims_Milotic,
    [SPECIES_CARVANHA] = sAnims_Carvanha,
    [SPECIES_SHARPEDO] = sAnims_Sharpedo,
    [SPECIES_TRAPINCH] = sAnims_Trapinch,
    [SPECIES_VIBRAVA] = sAnims_Vibrava,
    [SPECIES_FLYGON] = sAnims_Flygon,
    [SPECIES_MAKUHITA] = sAnims_Makuhita,
    [SPECIES_HARIYAMA] = sAnims_Hariyama,
    [SPECIES_ELECTRIKE] = sAnims_Electrike,
    [SPECIES_MANECTRIC] = sAnims_Manectric,
    [SPECIES_NUMEL] = sAnims_Numel,
    [SPECIES_CAMERUPT] = sAnims_Camerupt,
    [SPECIES_SPHEAL] = sAnims_Spheal,
    [SPECIES_SEALEO] = sAnims_Sealeo,
    [SPECIES_WALREIN] = sAnims_Walrein,
    [SPECIES_CACNEA] = sAnims_Cacnea,
    [SPECIES_CACTURNE] = sAnims_Cacturne,
    [SPECIES_SNORUNT] = sAnims_Snorunt,
    [SPECIES_GLALIE] = sAnims_Glalie,
    [SPECIES_LUNATONE] = sAnims_Lunatone,
    [SPECIES_SOLROCK] = sAnims_Solrock,
    [SPECIES_AZURILL] = sAnims_Azurill,
    [SPECIES_SPOINK] = sAnims_Spoink,
    [SPECIES_GRUMPIG] = sAnims_Grumpig,
    [SPECIES_PLUSLE] = sAnims_Plusle,
    [SPECIES_MINUN] = sAnims_Minun,
    [SPECIES_MAWILE] = sAnims_Mawile,
    [SPECIES_MEDITITE] = sAnims_Meditite,
    [SPECIES_MEDICHAM] = sAnims_Medicham,
    [SPECIES_SWABLU] = sAnims_Swablu,
    [SPECIES_ALTARIA] = sAnims_Altaria,
    [SPECIES_WYNAUT] = sAnims_Wynaut,
    [SPECIES_DUSKULL] = sAnims_Duskull,
    [SPECIES_DUSCLOPS] = sAnims_Dusclops,
    [SPECIES_ROSELIA] = sAnims_Roselia,
    [SPECIES_SLAKOTH] = sAnims_Slakoth,
    [SPECIES_VIGOROTH] = sAnims_Vigoroth,
    [SPECIES_SLAKING] = sAnims_Slaking,
    [SPECIES_GULPIN] = sAnims_Gulpin,
    [SPECIES_SWALOT] = sAnims_Swalot,
    [SPECIES_TROPIUS] = sAnims_Tropius,
    [SPECIES_WHISMUR] = sAnims_Whismur,
    [SPECIES_LOUDRED] = sAnims_Loudred,
    [SPECIES_EXPLOUD] = sAnims_Exploud,
    [SPECIES_CLAMPERL] = sAnims_Clamperl,
    [SPECIES_HUNTAIL] = sAnims_Huntail,
    [SPECIES_GOREBYSS] = sAnims_Gorebyss,
    [SPECIES_ABSOL] = sAnims_Absol,
    [SPECIES_SHUPPET] = sAnims_Shuppet,
    [SPECIES_BANETTE] = sAnims_Banette,
    [SPECIES_SEVIPER] = sAnims_Seviper,
    [SPECIES_ZANGOOSE] = sAnims_Zangoose,
    [SPECIES_RELICANTH] = sAnims_Relicanth,
    [SPECIES_ARON] = sAnims_Aron,
    [SPECIES_LAIRON] = sAnims_Lairon,
    [SPECIES_AGGRON] = sAnims_Aggron,
    [SPECIES_CASTFORM] = sAnims_Castform,
    [SPECIES_VOLBEAT] = sAnims_Volbeat,
    [SPECIES_ILLUMISE] = sAnims_Illumise,
    [SPECIES_LILEEP] = sAnims_Lileep,
    [SPECIES_CRADILY] = sAnims_Cradily,
    [SPECIES_ANORITH] = sAnims_Anorith,
    [SPECIES_ARMALDO] = sAnims_Armaldo,
    [SPECIES_RALTS] = sAnims_Ralts,
    [SPECIES_KIRLIA] = sAnims_Kirlia,
    [SPECIES_GARDEVOIR] = sAnims_Gardevoir,
    [SPECIES_BAGON] = sAnims_Bagon,
    [SPECIES_SHELGON] = sAnims_Shelgon,
    [SPECIES_SALAMENCE] = sAnims_Salamence,
    [SPECIES_BELDUM] = sAnims_Beldum,
    [SPECIES_METANG] = sAnims_Metang,
    [SPECIES_METAGROSS] = sAnims_Metagross,
    [SPECIES_REGIROCK] = sAnims_Regirock,
    [SPECIES_REGICE] = sAnims_Regice,
    [SPECIES_REGISTEEL] = sAnims_Registeel,
    [SPECIES_KYOGRE] = sAnims_Kyogre,
    [SPECIES_GROUDON] = sAnims_Groudon,
    [SPECIES_RAYQUAZA] = sAnims_Rayquaza,
    [SPECIES_LATIAS] = sAnims_Latias,
    [SPECIES_LATIOS] = sAnims_Latios,
    [SPECIES_JIRACHI] = sAnims_Jirachi,
    [SPECIES_DEOXYS] = sAnims_Deoxys,
    [SPECIES_CHIMECHO] = sAnims_Chimecho,
    [SPECIES_EGG] = sAnims_Egg,
    [SPECIES_UNOWN_B] = sAnims_UnownB,
    [SPECIES_UNOWN_C] = sAnims_UnownC,
    [SPECIES_UNOWN_D] = sAnims_UnownD,
    [SPECIES_UNOWN_E] = sAnims_UnownE,
    [SPECIES_UNOWN_F] = sAnims_UnownF,
    [SPECIES_UNOWN_G] = sAnims_UnownG,
    [SPECIES_UNOWN_H] = sAnims_UnownH,
    [SPECIES_UNOWN_I] = sAnims_UnownI,
    [SPECIES_UNOWN_J] = sAnims_UnownJ,
    [SPECIES_UNOWN_K] = sAnims_UnownK,
    [SPECIES_UNOWN_L] = sAnims_UnownL,
    [SPECIES_UNOWN_M] = sAnims_UnownM,
    [SPECIES_UNOWN_N] = sAnims_UnownN,
    [SPECIES_UNOWN_O] = sAnims_UnownO,
    [SPECIES_UNOWN_P] = sAnims_UnownP,
    [SPECIES_UNOWN_Q] = sAnims_UnownQ,
    [SPECIES_UNOWN_R] = sAnims_UnownR,
    [SPECIES_UNOWN_S] = sAnims_UnownS,
    [SPECIES_UNOWN_T] = sAnims_UnownT,
    [SPECIES_UNOWN_U] = sAnims_UnownU,
    [SPECIES_UNOWN_V] = sAnims_UnownV,
    [SPECIES_UNOWN_W] = sAnims_UnownW,
    [SPECIES_UNOWN_X] = sAnims_UnownX,
    [SPECIES_UNOWN_Y] = sAnims_UnownY,
    [SPECIES_UNOWN_Z] = sAnims_UnownZ,
    [SPECIES_UNOWN_EMARK] = sAnims_UnownEMark,
    [SPECIES_UNOWN_QMARK] = sAnims_UnownQMark
};