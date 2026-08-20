#ifndef GUARD_DATA_CONTEST_OPPONENTS_H
#define GUARD_DATA_CONTEST_OPPONENTS_H

// All AI contestants use this trainer ID.
#define CONTEST_AI_TRAINER_ID 0xFFFF

#define CONTEST_OPPONENTS_DATA __attribute__((section(".rodata.contest_mid57b_default_winners")))

CONTEST_OPPONENTS_DATA const struct ContestWinner gDefaultContestWinners[] = {
    [CONTEST_WINNER_HALL_1 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_ELECTRIKE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .monName = _("ブリリアン"),
        .trainerName = _("トシヒコ"),
        .contestRank = CONTEST_RANK_NORMAL,
    },
    [CONTEST_WINNER_HALL_2 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_TROPIUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .monName = _("リック"),
        .trainerName = _("アラン"),
        .contestRank = CONTEST_RANK_HYPER,
    },
    [CONTEST_WINNER_HALL_3 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_XATU,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .monName = _("ティオ"),
        .trainerName = _("ミユウ"),
        .contestRank = CONTEST_RANK_NORMAL,
    },
    [CONTEST_WINNER_HALL_4 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_PLUSLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
        .monName = _("ナナ"),
        .trainerName = _("ヨシノリ"),
        .contestRank = CONTEST_RANK_MASTER,
    },
    [CONTEST_WINNER_HALL_5 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_SHUPPET,
        .contestCategory = CONTEST_CATEGORY_SMART,
        .monName = _("カーボン"),
        .trainerName = _("サカエ"),
        .contestRank = CONTEST_RANK_SUPER,
    },
    [CONTEST_WINNER_HALL_6 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_ZANGOOSE,
        .contestCategory = CONTEST_CATEGORY_COOL,
        .monName = _("スラッシュ"),
        .trainerName = _("ヒナノ"),
        .contestRank = CONTEST_RANK_HYPER,
    },
    [CONTEST_WINNER_HALL_UNUSED_1 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_LOUDRED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
        .monName = _("ドラウド"),
        .trainerName = _("ユラト"),
        .contestRank = CONTEST_RANK_HYPER,
    },
    [CONTEST_WINNER_HALL_UNUSED_2 - 1] = {
        .personality = 0,
        .trainerId = CONTEST_AI_TRAINER_ID,
        .species = SPECIES_DELCATTY,
        .contestCategory = CONTEST_CATEGORY_CUTE,
        .monName = _("エネさん"),
        .trainerName = _("トメキチ"),
        .contestRank = CONTEST_RANK_MASTER,
    },
};

#undef CONTEST_OPPONENTS_DATA

#endif // GUARD_DATA_CONTEST_OPPONENTS_H
