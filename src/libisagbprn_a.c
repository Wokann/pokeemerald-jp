#include <stdarg.h>
#include "gba/gba.h"
#include "malloc.h"

#define AGB_PRINT_STRUCT_ADDR 0x9FE20F8
#define AGB_PRINT_PROTECT_ADDR 0x9FE2FFE
#define WSCNT_DATA (WAITCNT_PHI_OUT_16MHZ | WAITCNT_WS0_S_2 | WAITCNT_WS0_N_4)

struct AGBPrintStruct
{
    u16 m_nRequest;
    u16 m_nBank;
    u16 m_nGet;
    u16 m_nPut;
};

// JP 0x08295600: kept as asm (agbcc -O0 register allocation differs from the
// official library build: it uses r0-r3 for the clearing temps, the JP ROM
// uses r4 and a different pPrint reload register).
__attribute__((naked)) void AGBPrintInit(void)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r4, r7, lr}\n\t"
            "sub sp, #0x10\n\t"
            "mov r7, sp\n\t"
            "ldr r0, _0829567C\n\t"
            "str r0, [r7]\n\t"
            "ldr r0, _08295680\n\t"
            "str r0, [r7, #4]\n\t"
            "ldr r0, _08295684\n\t"
            "str r0, [r7, #8]\n\t"
            "adds r0, r7, #0\n\t"
            "adds r0, #0xc\n\t"
            "ldr r1, [r7, #4]\n\t"
            "ldrh r2, [r1]\n\t"
            "strh r2, [r0]\n\t"
            "ldr r0, [r7, #4]\n\t"
            "movs r2, #0xc0\n\t"
            "lsls r2, r2, #5\n\t"
            "adds r1, r2, #0\n\t"
            "strh r1, [r0]\n\t"
            "ldr r0, [r7, #8]\n\t"
            "movs r1, #0x20\n\t"
            "strh r1, [r0]\n\t"
            "ldr r0, [r7]\n\t"
            "ldr r1, [r7]\n\t"
            "ldr r2, [r7]\n\t"
            "ldrh r3, [r2, #6]\n\t"
            "movs r4, #0\n\t"
            "ands r3, r4\n\t"
            "adds r4, r3, #0\n\t"
            "strh r4, [r2, #6]\n\t"
            "ldrh r2, [r1, #4]\n\t"
            "movs r3, #0\n\t"
            "ands r2, r3\n\t"
            "adds r3, r2, #0\n\t"
            "strh r3, [r1, #4]\n\t"
            "ldrh r1, [r0]\n\t"
            "movs r2, #0\n\t"
            "ands r1, r2\n\t"
            "adds r2, r1, #0\n\t"
            "strh r2, [r0]\n\t"
            "ldr r0, [r7]\n\t"
            "ldrh r1, [r0, #2]\n\t"
            "movs r2, #0\n\t"
            "ands r1, r2\n\t"
            "adds r2, r1, #0\n\t"
            "movs r3, #0xfd\n\t"
            "adds r1, r2, #0\n\t"
            "orrs r1, r3\n\t"
            "adds r2, r1, #0\n\t"
            "strh r2, [r0, #2]\n\t"
            "ldr r0, [r7, #8]\n\t"
            "movs r1, #0\n\t"
            "strh r1, [r0]\n\t"
            "ldr r0, [r7, #4]\n\t"
            "adds r1, r7, #0\n\t"
            "adds r1, #0xc\n\t"
            "ldrh r2, [r1]\n\t"
            "strh r2, [r0]\n\t"
            "add sp, #0x10\n\t"
            "pop {r4, r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_0829567C: .4byte 0x09FE20F8\n\t"
            "_08295680: .4byte 0x04000204\n\t"
            "_08295684: .4byte 0x09FE2FFE\n\t"
            ".syntax divided\n");
}

void AGBPutcInternal(const char cChr)
{
    volatile struct AGBPrintStruct *pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    u16 *pPrintBuf = (u16 *)(0x8000000 + (pPrint->m_nBank << 16));
    u16 *pProtect = (u16 *)AGB_PRINT_PROTECT_ADDR;
    u16 nData = pPrintBuf[pPrint->m_nPut / 2];
    *pProtect = 0x20;
    nData = (pPrint->m_nPut & 1) ? (nData & 0xFF) | (cChr << 8) : (nData & 0xFF00) | cChr;
    pPrintBuf[pPrint->m_nPut / 2] = nData;
    pPrint->m_nPut++;
    *pProtect = 0;
}
