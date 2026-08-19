#if defined(LIBISAGBPRN_PART_A)
#include <stdarg.h>
#include "gba/gba.h"
#include "malloc.h"

// I/O register alias for use inside inline asm strings. The C macro
// REG_ADDR_WAITCNT cannot be expanded in asm text, so define the same value
// as an assembler symbol here.
__asm__(".equ REG_ADDR_WAITCNT, 0x04000204");
// AGBPrint memory addresses (same values as the C macros above).
__asm__(".equ AGB_PRINT_STRUCT_ADDR, 0x09FE20F8");
__asm__(".equ AGB_PRINT_PROTECT_ADDR, 0x09FE2FFE");

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
#ifndef NONMATCHING
// Verified: the official -O0 AGBPrintInit spills locals and evaluates in an order
// agbcc -O0 cannot reproduce, so the byte-exact naked asm stays the default.
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
            "_0829567C: .4byte AGB_PRINT_STRUCT_ADDR\n\t"
            "_08295680: .4byte REG_ADDR_WAITCNT\n\t"
            "_08295684: .4byte AGB_PRINT_PROTECT_ADDR\n\t"
            ".syntax divided\n");
}
#else
void AGBPrintInit(void)
{
    volatile struct AGBPrintStruct *pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    vu16 *pWSCNT = &REG_WAITCNT;
    u16 *pProtect = (u16 *)AGB_PRINT_PROTECT_ADDR;
    u16 nOldWSCNT = *pWSCNT;
    *pWSCNT = WSCNT_DATA;
    *pProtect = 0x20;
    pPrint->m_nRequest = pPrint->m_nGet = pPrint->m_nPut = 0;
    pPrint->m_nBank = 0xFD;
    *pProtect = 0;
    *pWSCNT = nOldWSCNT;
}
#endif


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
#elif defined(LIBISAGBPRN_PART_PUTC)
#include "gba/gba.h"

// I/O register alias for use inside inline asm strings (see libisagbprn_a.c).
__asm__(".equ REG_ADDR_WAITCNT, 0x04000204");
// AGBPrint memory address (same value as the C macro in libisagbprn_a.c).
__asm__(".equ AGB_PRINT_STRUCT_ADDR, 0x09FE20F8");

void AGBPutcInternal(const char cChr);

// JP 0x08295774: kept as asm (the official -O0 build spills the parameter
// and evaluates m_nPut/m_nGet in an order agbcc -O0/-O2 cannot reproduce).
__attribute__((naked)) void AGBPutc(const char cChr)
{
    __asm__(".syntax unified\n\t"
            ".code 16\n\t"
            "push {r7, lr}\n\t"
            "sub sp, #0x10\n\t"
            "mov r7, sp\n\t"
            "adds r1, r7, #0\n\t"
            "strb r0, [r1]\n\t"
            "ldr r0, _082957CC\n\t"
            "str r0, [r7, #4]\n\t"
            "adds r0, r7, #0\n\t"
            "adds r0, #8\n\t"
            "ldr r1, [r7, #4]\n\t"
            "ldrh r2, [r1]\n\t"
            "strh r2, [r0]\n\t"
            "ldr r0, [r7, #4]\n\t"
            "movs r2, #0xc0\n\t"
            "lsls r2, r2, #5\n\t"
            "adds r1, r2, #0\n\t"
            "strh r1, [r0]\n\t"
            "adds r0, r7, #0\n\t"
            "ldrb r1, [r0]\n\t"
            "adds r0, r1, #0\n\t"
            "bl AGBPutcInternal\n\t"
            "ldr r0, [r7, #4]\n\t"
            "adds r1, r7, #0\n\t"
            "adds r1, #8\n\t"
            "ldrh r2, [r1]\n\t"
            "strh r2, [r0]\n\t"
            "ldr r0, _082957D0\n\t"
            "str r0, [r7, #0xc]\n\t"
            "ldr r1, [r7, #0xc]\n\t"
            "ldrh r0, [r1, #6]\n\t"
            "ldr r1, [r7, #0xc]\n\t"
            "ldrh r2, [r1, #4]\n\t"
            "subs r1, r2, #1\n\t"
            "lsls r2, r1, #0x10\n\t"
            "lsrs r1, r2, #0x10\n\t"
            "cmp r0, r1\n\t"
            "bne _082957C4\n\t"
            "bl AGBPrintFlush1Block\n\t"
            "_082957C4:\n\t"
            "add sp, #0x10\n\t"
            "pop {r7}\n\t"
            "pop {r0}\n\t"
            "bx r0\n\t"
            ".align 2, 0\n\t"
            "_082957CC: .4byte REG_ADDR_WAITCNT\n\t"
            "_082957D0: .4byte AGB_PRINT_STRUCT_ADDR\n\t"
            ".syntax divided\n");
}
#elif defined(LIBISAGBPRN_PART_B)
#include <stdarg.h>
#include "gba/gba.h"
#include "malloc.h"

#define AGB_PRINT_FLUSH_ADDR 0x9FE209D
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

typedef void (*LPFN_PRINT_FLUSH)(void);

int vsprintf(char *buf, const char *format, va_list arg);
extern const char gUnknown_890EEF4[];
extern const char gUnknown_890EF28[];

void AGBPrint(const char *pBuf)
{
    volatile struct AGBPrintStruct *pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    vu16 *pWSCNT = &REG_WAITCNT;
    u16 nOldWSCNT = *pWSCNT;
    *pWSCNT = WSCNT_DATA;
    while (*pBuf)
    {
        AGBPutc(*pBuf);
        pBuf++;
    }
    *pWSCNT = nOldWSCNT;
}

void AGBPutc(const char cChr);

void AGBPrintf(const char *pBuf, ...)
{
    char bufPrint[0x100];
    va_list vArgv;
    va_start(vArgv, pBuf);
    vsprintf(bufPrint, pBuf, vArgv);
    va_end(vArgv);
    AGBPrint(bufPrint);
}

static void AGBPrintTransferDataInternal(u32 bAllData)
{
    LPFN_PRINT_FLUSH lpfnFuncFlush;
    vu16 *pIME;
    u16 nIME;
    vu16 *pWSCNT;
    u16 nOldWSCNT;
    u16 *pProtect;
    volatile struct AGBPrintStruct *pPrint;

    pProtect = (u16 *)AGB_PRINT_PROTECT_ADDR;
    pPrint = (struct AGBPrintStruct *)AGB_PRINT_STRUCT_ADDR;
    lpfnFuncFlush = (LPFN_PRINT_FLUSH)AGB_PRINT_FLUSH_ADDR;
    pIME = &REG_IME;
    nIME = *pIME;
    pWSCNT = &REG_WAITCNT;
    nOldWSCNT = *pWSCNT;
    *pIME = nIME & ~1;
    *pWSCNT = WSCNT_DATA;

    if (bAllData)
    {
        while (pPrint->m_nPut != pPrint->m_nGet)
        {
            *pProtect = 0x20;
            lpfnFuncFlush();
            *pProtect = 0;
        }
    }
    else if (pPrint->m_nPut != pPrint->m_nGet)
    {
        *pProtect = 0x20;
        lpfnFuncFlush();
        *pProtect = 0;
    }

    *pWSCNT = nOldWSCNT;
    *pIME = nIME;
}

void AGBPrintFlush1Block(void)
{
    AGBPrintTransferDataInternal(FALSE);
}

void AGBPrintFlush(void)
{
    AGBPrintTransferDataInternal(TRUE);
}

void AGBAssert(const char *pFile, int nLine, const char *pExpression, int nStopProgram)
{
    if (nStopProgram)
    {
        AGBPrintf(gUnknown_890EEF4, pFile, nLine, pExpression);
        AGBPrintFlush();
        asm(".hword 0xEFFF");
    }
    else
    {
        AGBPrintf(gUnknown_890EF28, pFile, nLine, pExpression);
    }
}
#else
#error "Select a libisagbprn source part"
#endif
