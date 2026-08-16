#ifndef GUARD_POKEMON_JUMP_H
#define GUARD_POKEMON_JUMP_H

#include "main.h"

// JP: enum order matches the JP ROM data (sPokeJumpMons jumpType bytes).
// US order is NORMAL, FAST, SLOW; JP data stores NORMAL=0, FAST=1, SLOW=2.
enum {
    JUMP_TYPE_NORMAL,
    JUMP_TYPE_FAST,
    JUMP_TYPE_SLOW,
};

struct PokemonJumpMons
{
    u16 species;
    u16 jumpType;
};

// US keeps an anonymous struct for sPrizeQuantityData; JP names it so the
// data can live in a separate file.
struct PrizeQuantityData
{
    u32 score;
    u32 quantity;
};

struct PokeJumpGfxFunc
{
    int id;
    void (*func)(void);
};

void StartPokemonJump(u16 partyId, MainCallback exitCallback);
bool32 IsSpeciesAllowedInPokemonJump(u16 species);
void IsPokemonJumpSpeciesInParty(void);
void ResetPokemonJumpRecords(void);
void ShowPokemonJumpRecords(void);

#endif // GUARD_POKEMON_JUMP_H
