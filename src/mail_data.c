#include "global.h"
#include "mail.h"
#include "constants/items.h"
#include "pokemon.h"
#include "pokemon_icon.h"
#include "text.h"
#include "international_string_util.h"

#define UNOWN_OFFSET 30000

void ClearAllMail(void)
{
    u8 i;

    for (i = 0; i < MAIL_COUNT; i++)
        ClearMail(&gSaveBlock1Ptr->mail[i]);
}

void ClearMail(struct Mail *mail)
{
    s32 i;

    for (i = 0; i < MAIL_WORDS_COUNT; i++)
        mail->words[i] = EC_EMPTY_WORD;

    for (i = 0; i < PLAYER_NAME_LENGTH + 1; i++)
        mail->playerName[i] = EOS;

    for (i = 0; i < TRAINER_ID_LENGTH; i++)
        mail->trainerId[i] = 0;

    mail->species = SPECIES_BULBASAUR;
    mail->itemId = ITEM_NONE;
}

bool8 MonHasMail(struct Pokemon *mon)
{
    u16 heldItem = GetMonData(mon, MON_DATA_HELD_ITEM);
    if (ItemIsMail(heldItem) && GetMonData(mon, MON_DATA_MAIL) != MAIL_NONE)
        return TRUE;
    else
        return FALSE;
}

__attribute__((naked)) u8 GiveMailToMonByItemId(struct Pokemon *mon, u16 itemId)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r5, r6, r7, lr}\n\t"
            "mov r7, sl\n\t"
            "mov r6, sb\n\t"
            "mov r5, r8\n\t"
            "push {r5, r6, r7}\n\t"
            "sub sp, #0xc\n\t"
            "mov r8, r0\n\t"
            "lsls r1, r1, #0x10\n\t"
            "lsrs r0, r1, #0x10\n\t"
            "str r0, [sp, #8]\n\t"
            "mov r0, sp\n\t"
            "movs r2, #0\n\t"
            "ldrb r3, [r0, #8]\n\t"
            "strb r3, [r0]\n\t"
            "lsrs r1, r1, #0x18\n\t"
            "strb r1, [r0, #1]\n\t"
            "add r4, sp, #4\n\t"
            "strb r2, [r4]\n\t"
            "mov ip, r4\n\t"
            "mov sl, r4\n\t"
            "adds r5, r4, #0\n\t"
            "_080D3CEA:\n\t"
            "ldr r2, _080D3E10\n\t"
            "ldr r0, [r2]\n\t"
            "ldrb r3, [r5]\n\t"
            "lsls r1, r3, #3\n\t"
            "adds r1, r1, r3\n\t"
            "lsls r1, r1, #2\n\t"
            "adds r0, r0, r1\n\t"
            "movs r1, #0xb0\n\t"
            "lsls r1, r1, #6\n\t"
            "adds r0, r0, r1\n\t"
            "ldrh r0, [r0]\n\t"
            "cmp r0, #0\n\t"
            "beq _080D3D06\n\t"
            "b _080D3E2C\n\t"
            "_080D3D06:\n\t"
            "movs r4, #0\n\t"
            "ldr r3, _080D3E14\n\t"
            "mov sb, r3\n\t"
            "adds r7, r2, #0\n\t"
            "mov r5, ip\n\t"
            "ldr r0, _080D3E18\n\t"
            "adds r6, r0, #0\n\t"
            "_080D3D14:\n\t"
            "ldr r2, [r7]\n\t"
            "lsls r3, r4, #1\n\t"
            "ldrb r1, [r5]\n\t"
            "lsls r0, r1, #3\n\t"
            "adds r0, r0, r1\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r3, r3, r0\n\t"
            "ldr r1, _080D3E1C\n\t"
            "adds r2, r2, r1\n\t"
            "adds r2, r2, r3\n\t"
            "ldrh r0, [r2]\n\t"
            "orrs r0, r6\n\t"
            "strh r0, [r2]\n\t"
            "adds r0, r4, #1\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r4, r0, #0x18\n\t"
            "cmp r4, #8\n\t"
            "bls _080D3D14\n\t"
            "movs r4, #0\n\t"
            "ldr r5, _080D3E10\n\t"
            "mov r3, ip\n\t"
            "_080D3D3E:\n\t"
            "ldr r2, [r5]\n\t"
            "ldrb r1, [r3]\n\t"
            "lsls r0, r1, #3\n\t"
            "adds r0, r0, r1\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r0, r4, r0\n\t"
            "ldr r1, _080D3E20\n\t"
            "adds r2, r2, r1\n\t"
            "adds r2, r2, r0\n\t"
            "mov r1, sb\n\t"
            "ldr r0, [r1]\n\t"
            "adds r0, r0, r4\n\t"
            "ldrb r0, [r0]\n\t"
            "strb r0, [r2]\n\t"
            "adds r0, r4, #1\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r4, r0, #0x18\n\t"
            "cmp r4, #6\n\t"
            "bls _080D3D3E\n\t"
            "ldr r3, _080D3E10\n\t"
            "ldr r2, [r3]\n\t"
            "mov r0, ip\n\t"
            "ldrb r1, [r0]\n\t"
            "lsls r0, r1, #3\n\t"
            "adds r0, r0, r1\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r0, r4, r0\n\t"
            "ldr r1, _080D3E20\n\t"
            "adds r2, r2, r1\n\t"
            "adds r2, r2, r0\n\t"
            "movs r0, #0xff\n\t"
            "strb r0, [r2]\n\t"
            "movs r4, #0\n\t"
            "adds r5, r3, #0\n\t"
            "mov r3, ip\n\t"
            "_080D3D84:\n\t"
            "ldr r2, [r5]\n\t"
            "ldrb r1, [r3]\n\t"
            "lsls r0, r1, #3\n\t"
            "adds r0, r0, r1\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r0, r4, r0\n\t"
            "ldr r1, _080D3E24\n\t"
            "adds r2, r2, r1\n\t"
            "adds r2, r2, r0\n\t"
            "mov r1, sb\n\t"
            "ldr r0, [r1]\n\t"
            "adds r0, #0xa\n\t"
            "adds r0, r0, r4\n\t"
            "ldrb r0, [r0]\n\t"
            "strb r0, [r2]\n\t"
            "adds r0, r4, #1\n\t"
            "lsls r0, r0, #0x18\n\t"
            "lsrs r4, r0, #0x18\n\t"
            "cmp r4, #3\n\t"
            "bls _080D3D84\n\t"
            "mov r0, r8\n\t"
            "movs r1, #0xb\n\t"
            "bl GetBoxMonData\n\t"
            "adds r4, r0, #0\n\t"
            "lsls r4, r4, #0x10\n\t"
            "lsrs r4, r4, #0x10\n\t"
            "mov r0, r8\n\t"
            "movs r1, #0\n\t"
            "bl GetBoxMonData\n\t"
            "adds r1, r0, #0\n\t"
            "adds r0, r4, #0\n\t"
            "bl SpeciesToMailSpecies\n\t"
            "ldr r1, _080D3E10\n\t"
            "ldr r3, [r1]\n\t"
            "mov r4, sl\n\t"
            "ldrb r2, [r4]\n\t"
            "lsls r1, r2, #3\n\t"
            "adds r1, r1, r2\n\t"
            "lsls r1, r1, #2\n\t"
            "adds r1, r3, r1\n\t"
            "ldr r2, _080D3E28\n\t"
            "adds r1, r1, r2\n\t"
            "strh r0, [r1]\n\t"
            "ldrb r1, [r4]\n\t"
            "lsls r0, r1, #3\n\t"
            "adds r0, r0, r1\n\t"
            "lsls r0, r0, #2\n\t"
            "adds r3, r3, r0\n\t"
            "movs r4, #0xb0\n\t"
            "lsls r4, r4, #6\n\t"
            "adds r3, r3, r4\n\t"
            "mov r0, sp\n\t"
            "ldrh r0, [r0, #8]\n\t"
            "strh r0, [r3]\n\t"
            "mov r0, r8\n\t"
            "movs r1, #0x40\n\t"
            "mov r2, sl\n\t"
            "bl SetMonData\n\t"
            "mov r0, r8\n\t"
            "movs r1, #0xc\n\t"
            "mov r2, sp\n\t"
            "bl SetMonData\n\t"
            "mov r1, sl\n\t"
            "ldrb r0, [r1]\n\t"
            "b _080D3E3A\n\t"
            ".align 2, 0\n\t"
            "_080D3E10: .4byte gSaveBlock1Ptr\n\t"
            "_080D3E14: .4byte gSaveBlock2Ptr\n\t"
            "_080D3E18: .4byte 0x0000FFFF\n\t"
            "_080D3E1C: .4byte 0x00002BE0\n\t"
            "_080D3E20: .4byte 0x00002BF2\n\t"
            "_080D3E24: .4byte 0x00002BFA\n\t"
            "_080D3E28: .4byte 0x00002BFE\n\t"
            "_080D3E2C:\n\t"
            "adds r0, r3, #1\n\t"
            "strb r0, [r4]\n\t"
            "ldrb r0, [r5]\n\t"
            "cmp r0, #5\n\t"
            "bhi _080D3E38\n\t"
            "b _080D3CEA\n\t"
            "_080D3E38:\n\t"
            "movs r0, #0xff\n\t"
            "_080D3E3A:\n\t"
            "add sp, #0xc\n\t"
            "pop {r3, r4, r5}\n\t"
            "mov r8, r3\n\t"
            "mov sb, r4\n\t"
            "mov sl, r5\n\t"
            "pop {r4, r5, r6, r7}\n\t"
            "pop {r1}\n\t"
            "bx r1\n\t"
            ".align 2, 0\n\t"
            ".syntax divided");
}

u16 SpeciesToMailSpecies(u16 species, u32 personality)
{
    if (species == SPECIES_UNOWN)
    {
        u32 species = GetUnownLetterByPersonality(personality) + UNOWN_OFFSET;
        return species;
    }

    return species;
}

u16 MailSpeciesToSpecies(u16 mailSpecies, u16 *buffer)
{
    u16 result;

    if (mailSpecies >= UNOWN_OFFSET && mailSpecies < UNOWN_OFFSET + NUM_UNOWN_FORMS)
    {
        result = SPECIES_UNOWN;
        *buffer = mailSpecies - UNOWN_OFFSET;
    }
    else
    {
        result = mailSpecies;
    }

    return result;
}

u8 GiveMailToMon(struct Pokemon *mon, struct Mail *mail)
{
    u8 heldItem[2];
    u16 itemId = mail->itemId;
    u8 mailId = GiveMailToMonByItemId(mon, itemId);

    if (mailId == MAIL_NONE)
        return MAIL_NONE;

    gSaveBlock1Ptr->mail[mailId] = *mail;

    SetMonData(mon, MON_DATA_MAIL, &mailId);

    heldItem[0] = itemId;
    heldItem[1] = itemId >> 8;

    SetMonData(mon, MON_DATA_HELD_ITEM, heldItem);

    return mailId;
}

static bool32 UNUSED DummyMailFunc(void)
{
    return FALSE;
}

void TakeMailFromMon(struct Pokemon *mon)
{
    u8 heldItem[2];
    u8 mailId;

    if (MonHasMail(mon))
    {
        mailId = GetMonData(mon, MON_DATA_MAIL);
        gSaveBlock1Ptr->mail[mailId].itemId = ITEM_NONE;
        mailId = MAIL_NONE;
        heldItem[0] = ITEM_NONE;
        heldItem[1] = ITEM_NONE << 8;
        SetMonData(mon, MON_DATA_MAIL, &mailId);
        SetMonData(mon, MON_DATA_HELD_ITEM, heldItem);
    }
}

void ClearMailItemId(u8 mailId)
{
    gSaveBlock1Ptr->mail[mailId].itemId = ITEM_NONE;
}

u8 TakeMailFromMonAndSave(struct Pokemon *mon)
{
    u8 i;
    u8 newHeldItem[2];
    u8 newMailId;

    newHeldItem[0] = ITEM_NONE;
    newHeldItem[1] = ITEM_NONE << 8;
    newMailId = MAIL_NONE;

    for (i = PARTY_SIZE; i < MAIL_COUNT; i++)
    {
        if (gSaveBlock1Ptr->mail[i].itemId == ITEM_NONE)
        {
            memcpy(&gSaveBlock1Ptr->mail[i], &gSaveBlock1Ptr->mail[GetMonData(mon, MON_DATA_MAIL)], sizeof(struct Mail));
            gSaveBlock1Ptr->mail[GetMonData(mon, MON_DATA_MAIL)].itemId = ITEM_NONE;
            SetMonData(mon, MON_DATA_MAIL, &newMailId);
            SetMonData(mon, MON_DATA_HELD_ITEM, newHeldItem);
            return i;
        }
    }

    return MAIL_NONE;
}

bool8 ItemIsMail(u16 itemId)
{
    switch (itemId)
    {
    case ITEM_ORANGE_MAIL:
    case ITEM_HARBOR_MAIL:
    case ITEM_GLITTER_MAIL:
    case ITEM_MECH_MAIL:
    case ITEM_WOOD_MAIL:
    case ITEM_WAVE_MAIL:
    case ITEM_BEAD_MAIL:
    case ITEM_SHADOW_MAIL:
    case ITEM_TROPIC_MAIL:
    case ITEM_DREAM_MAIL:
    case ITEM_FAB_MAIL:
    case ITEM_RETRO_MAIL:
        return TRUE;
    default:
        return FALSE;
    }
}
