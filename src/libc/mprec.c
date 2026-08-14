/****************************************************************
 *
 * The author of this software is David M. Gay.
 *
 * Copyright (c) 1991 by AT&T.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy
 * or modification of this software and in all copies of the supporting
 * documentation for such software.
 *
 * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY.  IN PARTICULAR, NEITHER THE AUTHOR NOR AT&T MAKES ANY
 * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
 * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 ***************************************************************/

/* Please send bug reports to
	David M. Gay
	AT&T Bell Laboratories, Room 2C-463
	600 Mountain Avenue
	Murray Hill, NJ 07974-2070
	U.S.A.
	dmg@research.att.com or research!dmg
 */

/* strtod for IEEE-, VAX-, and IBM-arithmetic machines.
 *
 * This strtod returns a nearest machine number to the input decimal
 * string (or sets errno to ERANGE).  With IEEE arithmetic, ties are
 * broken by the IEEE round-even rule.  Otherwise ties are broken by
 * biased rounding (add half and chop).
 *
 * Inspired loosely by William D. Clinger's paper "How to Read Floating
 * Point Numbers Accurately" [Proc. ACM SIGPLAN '90, pp. 92-101].
 *
 * Modifications:
 *
 *	1. We only require IEEE, IBM, or VAX double-precision
 *		arithmetic (not IEEE double-extended).
 *	2. We get by with floating-point arithmetic in a case that
 *		Clinger missed -- when we're computing d * 10^n
 *		for a small integer d and the integer n is not too
 *		much larger than 22 (the maximum integer k for which
 *		we can represent 10^k exactly), we may be able to
 *		compute (d*10^k) * 10^(e-k) with just one roundoff.
 *	3. Rather than a bit-at-a-time adjustment of the binary
 *		result in the hard case, we use floating-point
 *		arithmetic to determine the adjustment to within
 *		one bit; only in really hard cases do we need to
 *		compute a second residual.
 *	4. Because of 3., we don't need a large table of powers of 10
 *		for ten-to-e (just some small tables, e.g. of 10^k
 *		for 0 <= k <= 22).
 */

/*
 * #define IEEE_8087 for IEEE-arithmetic machines where the least
 *	significant byte has the lowest address.
 * #define IEEE_MC68k for IEEE-arithmetic machines where the most
 *	significant byte has the lowest address.
 * #define Sudden_Underflow for IEEE-format machines without gradual
 *	underflow (i.e., that flush to zero on underflow).
 * #define IBM for IBM mainframe-style floating-point arithmetic.
 * #define VAX for VAX-style floating-point arithmetic.
 * #define Unsigned_Shifts if >> does treats its left operand as unsigned.
 * #define No_leftright to omit left-right logic in fast floating-point
 *	computation of dtoa.
 * #define Check_FLT_ROUNDS if FLT_ROUNDS can assume the values 2 or 3.
 * #define RND_PRODQUOT to use rnd_prod and rnd_quot (assembly routines
 *	that use extended-precision instructions to compute rounded
 *	products and quotients) with IBM.
 * #define ROUND_BIASED for IEEE-format with biased rounding.
 * #define Inaccurate_Divide for IEEE-format with correctly rounded
 *	products but inaccurate quotients, e.g., for Intel i860.
 * #define Just_16 to store 16 bits per 32-bit long when doing high-precision
 *	integer arithmetic.  Whether this speeds things up or slows things
 *	down depends on the machine and the number being converted.
 */

#include <_ansi.h>
#include <stdlib.h>
#include <string.h>
#include <reent.h>
#include "mprec.h"

/* reent.c knows this value */
#define _Kmax 15


_Bigint *
_DEFUN (Balloc, (ptr, k), struct _reent *ptr _AND int k)
{
  int x;
  _Bigint *rv;

  if (!ptr->_freelist)
    {
      ptr->_freelist = (_Bigint **) _calloc_r (ptr, 4, 0x10);
      if (!ptr->_freelist)
	return NULL;
    }
  if ((rv = ptr->_freelist[k]))
    {
      ptr->_freelist[k] = rv->_next;
    }
  else
    {
      x = 1 << k;
      rv = (_Bigint *) _calloc_r (ptr, 1, sizeof (_Bigint) + (x - 1) * sizeof (ULong));
      if (!rv)
	return NULL;
      rv->_k = k;
      rv->_maxwds = x;
    }
  rv->_sign = rv->_wds = 0;
  return rv;
}


void
_DEFUN (Bfree, (ptr, v), struct _reent *ptr _AND _Bigint * v)
{
  if (v)
    {
      v->_next = ptr->_freelist[v->_k];
      ptr->_freelist[v->_k] = v;
    }
}

int
_DEFUN (hi0bits,
	(x), register ULong x)
{
  register int k = 0;

  if (!(x & 0xffff0000))
    {
      k = 16;
      x <<= 16;
    }
  if (!(x & 0xff000000))
    {
      k += 8;
      x <<= 8;
    }
  if (!(x & 0xf0000000))
    {
      k += 4;
      x <<= 4;
    }
  if (!(x & 0xc0000000))
    {
      k += 2;
      x <<= 2;
    }
  if (!(x & 0x80000000))
    {
      k++;
      if (!(x & 0x40000000))
	return 32;
    }
  return k;
}

int
_DEFUN (lo0bits, (y), ULong *y)
{
  register int k;
  register ULong x = *y;

  if (x & 7)
    {
      if (x & 1)
	return 0;
      if (x & 2)
	{
	  *y = x >> 1;
	  return 1;
	}
      *y = x >> 2;
      return 2;
    }
  k = 0;
  if (!(x & 0xffff))
    {
      k = 16;
      x >>= 16;
    }
  if (!(x & 0xff))
    {
      k += 8;
      x >>= 8;
    }
  if (!(x & 0xf))
    {
      k += 4;
      x >>= 4;
    }
  if (!(x & 0x3))
    {
      k += 2;
      x >>= 2;
    }
  if (!(x & 1))
    {
      k++;
      x >>= 1;
      if (!x & 1)
	return 32;
    }
  *y = x;
  return k;
}

int
_DEFUN (cmp, (a, b), _Bigint * a _AND _Bigint * b)
{
  ULong *xa, *xa0, *xb, *xb0;
  int i, j;

  i = a->_wds;
  j = b->_wds;
#ifdef DEBUG
  if (i > 1 && !a->_x[i - 1])
    Bug ("cmp called with a->_x[a->_wds-1] == 0");
  if (j > 1 && !b->_x[j - 1])
    Bug ("cmp called with b->_x[b->_wds-1] == 0");
#endif
  if (i -= j)
    return i;
  xa0 = a->_x;
  xa = xa0 + j;
  xb0 = b->_x;
  xb = xb0 + j;
  for (;;)
    {
      if (*--xa != *--xb)
	return *xa < *xb ? -1 : 1;
      if (xa <= xa0)
	break;
    }
  return 0;
}

// JP byte-exact: agbcc uses a different register allocation than the JP
// ROM for the newlib mprec helpers; keep naked asm for _multadd/_s2b.
__attribute__((naked)) _Bigint *_DEFUN(multadd, (ptr, b, m, a),
	struct _reent *ptr _AND _Bigint * b _AND int m _AND int a)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, r6, r7, lr}\n\t"
        "mov r7, sb\n\t"
        "mov r6, r8\n\t"
        "push {r6, r7}\n\t"
        "mov sb, r0\n\t"
        "adds r5, r1, #0\n\t"
        "adds r4, r2, #0\n\t"
        "mov r8, r3\n\t"
        "ldr r6, [r5, #0x10]\n\t"
        "adds r3, r5, #0\n\t"
        "adds r3, #0x14\n\t"
        "movs r7, #0\n\t"
        "ldr r0, _0829AE88\n\t"
        "mov ip, r0\n\t"
        "_0829AE10:\n\t"
        "ldr r1, [r3]\n\t"
        "adds r0, r1, #0\n\t"
        "mov r2, ip\n\t"
        "ands r0, r2\n\t"
        "adds r2, r0, #0\n\t"
        "muls r2, r4, r2\n\t"
        "add r2, r8\n\t"
        "lsrs r1, r1, #0x10\n\t"
        "adds r0, r1, #0\n\t"
        "muls r0, r4, r0\n\t"
        "lsrs r1, r2, #0x10\n\t"
        "adds r0, r0, r1\n\t"
        "lsrs r1, r0, #0x10\n\t"
        "mov r8, r1\n\t"
        "lsls r0, r0, #0x10\n\t"
        "mov r1, ip\n\t"
        "ands r2, r1\n\t"
        "adds r0, r0, r2\n\t"
        "stm r3!, {r0}\n\t"
        "adds r7, #1\n\t"
        "cmp r7, r6\n\t"
        "blt _0829AE10\n\t"
        "mov r2, r8\n\t"
        "cmp r2, #0\n\t"
        "beq _0829AE7E\n\t"
        "ldr r0, [r5, #8]\n\t"
        "cmp r6, r0\n\t"
        "blt _0829AE6E\n\t"
        "ldr r1, [r5, #4]\n\t"
        "adds r1, #1\n\t"
        "mov r0, sb\n\t"
        "bl _Balloc\n\t"
        "adds r4, r0, #0\n\t"
        "adds r0, #0xc\n\t"
        "adds r1, r5, #0\n\t"
        "adds r1, #0xc\n\t"
        "ldr r2, [r5, #0x10]\n\t"
        "lsls r2, r2, #2\n\t"
        "adds r2, #8\n\t"
        "bl memcpy\n\t"
        "mov r0, sb\n\t"
        "adds r1, r5, #0\n\t"
        "bl _Bfree\n\t"
        "adds r5, r4, #0\n\t"
        "_0829AE6E:\n\t"
        "lsls r1, r6, #2\n\t"
        "adds r0, r5, #0\n\t"
        "adds r0, #0x14\n\t"
        "adds r0, r0, r1\n\t"
        "mov r1, r8\n\t"
        "str r1, [r0]\n\t"
        "adds r6, #1\n\t"
        "str r6, [r5, #0x10]\n\t"
        "_0829AE7E:\n\t"
        "adds r0, r5, #0\n\t"
        "pop {r3, r4}\n\t"
        "mov r8, r3\n\t"
        "mov sb, r4\n\t"
        "pop {r4, r5, r6, r7, pc}\n\t"
        ".align 2, 0\n\t"
        "_0829AE88: .4byte 0x0000FFFF\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) _Bigint *_DEFUN(s2b, (ptr, s, nd0, nd, y9),
	struct _reent *ptr _AND _CONST char *s _AND int nd0 _AND int nd _AND ULong y9)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, r6, r7, lr}\n\t"
        "mov r7, r8\n\t"
        "push {r7}\n\t"
        "adds r7, r0, #0\n\t"
        "adds r4, r1, #0\n\t"
        "adds r6, r2, #0\n\t"
        "mov r8, r3\n\t"
        "mov r0, r8\n\t"
        "adds r0, #8\n\t"
        "movs r1, #9\n\t"
        "bl __divsi3\n\t"
        "movs r1, #0\n\t"
        "movs r2, #1\n\t"
        "cmp r0, #1\n\t"
        "ble _0829AEB4\n\t"
        "_0829AEAC:\n\t"
        "lsls r2, r2, #1\n\t"
        "adds r1, #1\n\t"
        "cmp r0, r2\n\t"
        "bgt _0829AEAC\n\t"
        "_0829AEB4:\n\t"
        "adds r0, r7, #0\n\t"
        "bl _Balloc\n\t"
        "adds r1, r0, #0\n\t"
        "ldr r0, [sp, #0x18]\n\t"
        "str r0, [r1, #0x14]\n\t"
        "movs r0, #1\n\t"
        "str r0, [r1, #0x10]\n\t"
        "movs r5, #9\n\t"
        "cmp r6, #9\n\t"
        "ble _0829AEE6\n\t"
        "adds r4, #9\n\t"
        "_0829AECC:\n\t"
        "ldrb r3, [r4]\n\t"
        "subs r3, #0x30\n\t"
        "adds r4, #1\n\t"
        "adds r0, r7, #0\n\t"
        "movs r2, #0xa\n\t"
        "bl _multadd\n\t"
        "adds r1, r0, #0\n\t"
        "adds r5, #1\n\t"
        "cmp r5, r6\n\t"
        "blt _0829AECC\n\t"
        "adds r4, #1\n\t"
        "b _0829AEE8\n\t"
        "_0829AEE6:\n\t"
        "adds r4, #0xa\n\t"
        "_0829AEE8:\n\t"
        "cmp r5, r8\n\t"
        "bge _0829AF06\n\t"
        "mov r0, r8\n\t"
        "subs r5, r0, r5\n\t"
        "_0829AEF0:\n\t"
        "ldrb r3, [r4]\n\t"
        "subs r3, #0x30\n\t"
        "adds r4, #1\n\t"
        "adds r0, r7, #0\n\t"
        "movs r2, #0xa\n\t"
        "bl _multadd\n\t"
        "adds r1, r0, #0\n\t"
        "subs r5, #1\n\t"
        "cmp r5, #0\n\t"
        "bne _0829AEF0\n\t"
        "_0829AF06:\n\t"
        "adds r0, r1, #0\n\t"
        "pop {r3}\n\t"
        "mov r8, r3\n\t"
        "pop {r4, r5, r6, r7, pc}\n\t"
        ".syntax divided\n\t"
    );
}

// JP byte-exact mprec helpers (newlib variants with agbcc-incompatible
// register allocation / modified pow5mult that uses multiply instead of
// multadd); keep naked asm for _i2b/_multiply/_pow5mult/_lshift.
__attribute__((naked)) _Bigint *_DEFUN(i2b, (ptr, i),
	struct _reent *ptr _AND int i)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, lr}\n\t"
        "adds r4, r1, #0\n\t"
        "movs r1, #1\n\t"
        "bl _Balloc\n\t"
        "str r4, [r0, #0x14]\n\t"
        "movs r1, #1\n\t"
        "str r1, [r0, #0x10]\n\t"
        "pop {r4, pc}\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) _Bigint *_DEFUN(mult, (ptr, a, b),
	struct _reent *ptr _AND _Bigint * a _AND _Bigint * b)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, r6, r7, lr}\n\t"
        "mov r7, sl\n\t"
        "mov r6, sb\n\t"
        "mov r5, r8\n\t"
        "push {r5, r6, r7}\n\t"
        "sub sp, #0x24\n\t"
        "adds r3, r0, #0\n\t"
        "adds r4, r1, #0\n\t"
        "adds r5, r2, #0\n\t"
        "ldr r1, [r4, #0x10]\n\t"
        "ldr r0, [r5, #0x10]\n\t"
        "cmp r1, r0\n\t"
        "bge _0829B020\n\t"
        "str r4, [sp]\n\t"
        "adds r4, r5, #0\n\t"
        "ldr r5, [sp]\n\t"
        "_0829B020:\n\t"
        "ldr r1, [r4, #4]\n\t"
        "ldr r6, [r4, #0x10]\n\t"
        "ldr r0, [r5, #0x10]\n\t"
        "mov r8, r0\n\t"
        "mov r2, r8\n\t"
        "adds r2, r6, r2\n\t"
        "str r2, [sp, #4]\n\t"
        "ldr r0, [r4, #8]\n\t"
        "cmp r2, r0\n\t"
        "ble _0829B036\n\t"
        "adds r1, #1\n\t"
        "_0829B036:\n\t"
        "adds r0, r3, #0\n\t"
        "bl _Balloc\n\t"
        "str r0, [sp]\n\t"
        "adds r7, r0, #0\n\t"
        "adds r7, #0x14\n\t"
        "ldr r1, [sp, #4]\n\t"
        "lsls r0, r1, #2\n\t"
        "adds r2, r7, r0\n\t"
        "str r2, [sp, #8]\n\t"
        "str r0, [sp, #0x18]\n\t"
        "adds r1, r4, #0\n\t"
        "adds r1, #0x14\n\t"
        "lsls r3, r6, #2\n\t"
        "adds r2, r5, #0\n\t"
        "adds r2, #0x14\n\t"
        "mov r5, r8\n\t"
        "lsls r4, r5, #2\n\t"
        "ldr r0, [sp, #8]\n\t"
        "cmp r7, r0\n\t"
        "bhs _0829B06A\n\t"
        "movs r0, #0\n\t"
        "_0829B062:\n\t"
        "stm r7!, {r0}\n\t"
        "ldr r5, [sp, #8]\n\t"
        "cmp r7, r5\n\t"
        "blo _0829B062\n\t"
        "_0829B06A:\n\t"
        "str r1, [sp, #8]\n\t"
        "adds r3, r1, r3\n\t"
        "str r3, [sp, #0xc]\n\t"
        "mov r8, r2\n\t"
        "add r4, r8\n\t"
        "str r4, [sp, #0x10]\n\t"
        "ldr r0, [sp]\n\t"
        "adds r0, #0x14\n\t"
        "mov sb, r0\n\t"
        "mov r1, sb\n\t"
        "str r1, [sp, #0x20]\n\t"
        "cmp r8, r4\n\t"
        "bhs _0829B132\n\t"
        "_0829B084:\n\t"
        "mov r2, r8\n\t"
        "ldm r2!, {r6}\n\t"
        "str r2, [sp, #0x14]\n\t"
        "ldr r0, _0829B140\n\t"
        "ands r6, r0\n\t"
        "mov r4, sb\n\t"
        "adds r4, #4\n\t"
        "str r4, [sp, #0x1c]\n\t"
        "cmp r6, #0\n\t"
        "beq _0829B0DC\n\t"
        "ldr r7, [sp, #8]\n\t"
        "mov r5, sb\n\t"
        "movs r1, #0\n\t"
        "mov ip, r1\n\t"
        "mov sl, r0\n\t"
        "_0829B0A2:\n\t"
        "ldm r7!, {r3}\n\t"
        "adds r0, r3, #0\n\t"
        "mov r2, sl\n\t"
        "ands r0, r2\n\t"
        "adds r1, r0, #0\n\t"
        "muls r1, r6, r1\n\t"
        "ldr r2, [r5]\n\t"
        "adds r0, r2, #0\n\t"
        "mov r4, sl\n\t"
        "ands r0, r4\n\t"
        "adds r1, r1, r0\n\t"
        "mov r0, ip\n\t"
        "adds r4, r1, r0\n\t"
        "lsrs r1, r4, #0x10\n\t"
        "lsrs r3, r3, #0x10\n\t"
        "adds r0, r3, #0\n\t"
        "muls r0, r6, r0\n\t"
        "lsrs r2, r2, #0x10\n\t"
        "adds r0, r0, r2\n\t"
        "adds r2, r0, r1\n\t"
        "lsrs r0, r2, #0x10\n\t"
        "mov ip, r0\n\t"
        "strh r2, [r5]\n\t"
        "strh r4, [r5, #2]\n\t"
        "adds r5, #4\n\t"
        "ldr r1, [sp, #0xc]\n\t"
        "cmp r7, r1\n\t"
        "blo _0829B0A2\n\t"
        "str r0, [r5]\n\t"
        "_0829B0DC:\n\t"
        "mov r2, r8\n\t"
        "ldrh r6, [r2, #2]\n\t"
        "cmp r6, #0\n\t"
        "beq _0829B124\n\t"
        "ldr r7, [sp, #8]\n\t"
        "mov r5, sb\n\t"
        "movs r4, #0\n\t"
        "mov ip, r4\n\t"
        "ldr r2, [r5]\n\t"
        "ldr r3, _0829B140\n\t"
        "_0829B0F0:\n\t"
        "ldm r7!, {r1}\n\t"
        "adds r0, r1, #0\n\t"
        "ands r0, r3\n\t"
        "muls r0, r6, r0\n\t"
        "ldrh r4, [r5, #2]\n\t"
        "adds r4, r4, r0\n\t"
        "mov r8, r4\n\t"
        "add r4, ip\n\t"
        "lsrs r0, r4, #0x10\n\t"
        "mov ip, r0\n\t"
        "strh r4, [r5]\n\t"
        "strh r2, [r5, #2]\n\t"
        "adds r5, #4\n\t"
        "lsrs r1, r1, #0x10\n\t"
        "muls r1, r6, r1\n\t"
        "ldr r0, [r5]\n\t"
        "ands r0, r3\n\t"
        "adds r1, r1, r0\n\t"
        "mov r4, ip\n\t"
        "adds r2, r1, r4\n\t"
        "lsrs r0, r2, #0x10\n\t"
        "mov ip, r0\n\t"
        "ldr r1, [sp, #0xc]\n\t"
        "cmp r7, r1\n\t"
        "blo _0829B0F0\n\t"
        "str r2, [r5]\n\t"
        "_0829B124:\n\t"
        "ldr r2, [sp, #0x14]\n\t"
        "mov r8, r2\n\t"
        "ldr r4, [sp, #0x1c]\n\t"
        "mov sb, r4\n\t"
        "ldr r5, [sp, #0x10]\n\t"
        "cmp r8, r5\n\t"
        "blo _0829B084\n\t"
        "_0829B132:\n\t"
        "ldr r0, [sp, #0x20]\n\t"
        "ldr r1, [sp, #0x18]\n\t"
        "adds r5, r0, r1\n\t"
        "ldr r2, [sp, #4]\n\t"
        "cmp r2, #0\n\t"
        "ble _0829B156\n\t"
        "b _0829B14E\n\t"
        ".align 2, 0\n\t"
        "_0829B140: .4byte 0x0000FFFF\n\t"
        "_0829B144:\n\t"
        "ldr r4, [sp, #4]\n\t"
        "subs r4, #1\n\t"
        "str r4, [sp, #4]\n\t"
        "cmp r4, #0\n\t"
        "ble _0829B156\n\t"
        "_0829B14E:\n\t"
        "subs r5, #4\n\t"
        "ldr r0, [r5]\n\t"
        "cmp r0, #0\n\t"
        "beq _0829B144\n\t"
        "_0829B156:\n\t"
        "ldr r5, [sp, #4]\n\t"
        "ldr r0, [sp]\n\t"
        "str r5, [r0, #0x10]\n\t"
        "ldr r0, [sp]\n\t"
        "add sp, #0x24\n\t"
        "pop {r3, r4, r5}\n\t"
        "mov r8, r3\n\t"
        "mov sb, r4\n\t"
        "mov sl, r5\n\t"
        "pop {r4, r5, r6, r7, pc}\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) _Bigint *_DEFUN(pow5mult, (ptr, b, k),
	struct _reent *ptr _AND _Bigint * b _AND int k)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, r6, r7, lr}\n\t"
        "mov r7, r8\n\t"
        "push {r7}\n\t"
        "mov r8, r0\n\t"
        "adds r7, r1, #0\n\t"
        "adds r6, r2, #0\n\t"
        "movs r1, #3\n\t"
        "ands r1, r6\n\t"
        "cmp r1, #0\n\t"
        "beq _0829B196\n\t"
        "ldr r0, _0829B1B8\n\t"
        "subs r1, #1\n\t"
        "lsls r1, r1, #2\n\t"
        "adds r1, r1, r0\n\t"
        "ldr r2, [r1]\n\t"
        "mov r0, r8\n\t"
        "adds r1, r7, #0\n\t"
        "movs r3, #0\n\t"
        "bl _multadd\n\t"
        "adds r7, r0, #0\n\t"
        "_0829B196:\n\t"
        "asrs r6, r6, #2\n\t"
        "cmp r6, #0\n\t"
        "beq _0829B1FC\n\t"
        "mov r0, r8\n\t"
        "ldr r5, [r0, #0x48]\n\t"
        "adds r4, r5, #0\n\t"
        "cmp r5, #0\n\t"
        "bne _0829B1D8\n\t"
        "ldr r1, _0829B1BC\n\t"
        "bl _i2b\n\t"
        "mov r1, r8\n\t"
        "str r0, [r1, #0x48]\n\t"
        "adds r5, r0, #0\n\t"
        "str r4, [r5]\n\t"
        "b _0829B1D8\n\t"
        ".align 2, 0\n\t"
        "_0829B1B8: .4byte 0x0890F228\n\t"
        "_0829B1BC: .4byte 0x00000271\n\t"
        "_0829B1C0:\n\t"
        "ldr r0, [r5]\n\t"
        "adds r4, r0, #0\n\t"
        "cmp r0, #0\n\t"
        "bne _0829B1D6\n\t"
        "mov r0, r8\n\t"
        "adds r1, r5, #0\n\t"
        "adds r2, r5, #0\n\t"
        "bl _multiply\n\t"
        "str r0, [r5]\n\t"
        "str r4, [r0]\n\t"
        "_0829B1D6:\n\t"
        "adds r5, r0, #0\n\t"
        "_0829B1D8:\n\t"
        "movs r0, #1\n\t"
        "ands r0, r6\n\t"
        "cmp r0, #0\n\t"
        "beq _0829B1F6\n\t"
        "mov r0, r8\n\t"
        "adds r1, r7, #0\n\t"
        "adds r2, r5, #0\n\t"
        "bl _multiply\n\t"
        "adds r4, r0, #0\n\t"
        "mov r0, r8\n\t"
        "adds r1, r7, #0\n\t"
        "bl _Bfree\n\t"
        "adds r7, r4, #0\n\t"
        "_0829B1F6:\n\t"
        "asrs r6, r6, #1\n\t"
        "cmp r6, #0\n\t"
        "bne _0829B1C0\n\t"
        "_0829B1FC:\n\t"
        "adds r0, r7, #0\n\t"
        "pop {r3}\n\t"
        "mov r8, r3\n\t"
        "pop {r4, r5, r6, r7, pc}\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) _Bigint *_DEFUN(lshift, (ptr, b, k),
	struct _reent *ptr _AND _Bigint * b _AND int k)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "push {r4, r5, r6, r7, lr}\n\t"
        "mov r7, sl\n\t"
        "mov r6, sb\n\t"
        "mov r5, r8\n\t"
        "push {r5, r6, r7}\n\t"
        "mov sl, r0\n\t"
        "mov r8, r1\n\t"
        "adds r5, r2, #0\n\t"
        "asrs r6, r5, #5\n\t"
        "ldr r1, [r1, #4]\n\t"
        "mov r2, r8\n\t"
        "ldr r0, [r2, #0x10]\n\t"
        "adds r0, r6, r0\n\t"
        "adds r7, r0, #1\n\t"
        "ldr r2, [r2, #8]\n\t"
        "cmp r7, r2\n\t"
        "ble _0829B22E\n\t"
        "_0829B226:\n\t"
        "adds r1, #1\n\t"
        "lsls r2, r2, #1\n\t"
        "cmp r7, r2\n\t"
        "bgt _0829B226\n\t"
        "_0829B22E:\n\t"
        "mov r0, sl\n\t"
        "bl _Balloc\n\t"
        "mov sb, r0\n\t"
        "mov r4, sb\n\t"
        "adds r4, #0x14\n\t"
        "mov r0, r8\n\t"
        "adds r0, #0x14\n\t"
        "cmp r6, #0\n\t"
        "ble _0829B24E\n\t"
        "movs r1, #0\n\t"
        "adds r2, r6, #0\n\t"
        "_0829B246:\n\t"
        "stm r4!, {r1}\n\t"
        "subs r2, #1\n\t"
        "cmp r2, #0\n\t"
        "bne _0829B246\n\t"
        "_0829B24E:\n\t"
        "adds r3, r0, #0\n\t"
        "mov r1, r8\n\t"
        "ldr r0, [r1, #0x10]\n\t"
        "lsls r0, r0, #2\n\t"
        "adds r6, r3, r0\n\t"
        "movs r0, #0x1f\n\t"
        "ands r5, r0\n\t"
        "cmp r5, #0\n\t"
        "beq _0829B280\n\t"
        "movs r0, #0x20\n\t"
        "subs r1, r0, r5\n\t"
        "movs r2, #0\n\t"
        "_0829B266:\n\t"
        "ldr r0, [r3]\n\t"
        "lsls r0, r5\n\t"
        "orrs r0, r2\n\t"
        "stm r4!, {r0}\n\t"
        "ldm r3!, {r2}\n\t"
        "lsrs r2, r1\n\t"
        "cmp r3, r6\n\t"
        "blo _0829B266\n\t"
        "str r2, [r4]\n\t"
        "cmp r2, #0\n\t"
        "beq _0829B288\n\t"
        "adds r7, #1\n\t"
        "b _0829B288\n\t"
        "_0829B280:\n\t"
        "ldm r3!, {r0}\n\t"
        "stm r4!, {r0}\n\t"
        "cmp r3, r6\n\t"
        "blo _0829B280\n\t"
        "_0829B288:\n\t"
        "subs r0, r7, #1\n\t"
        "mov r2, sb\n\t"
        "str r0, [r2, #0x10]\n\t"
        "mov r0, sl\n\t"
        "mov r1, r8\n\t"
        "bl _Bfree\n\t"
        "mov r0, sb\n\t"
        "pop {r3, r4, r5}\n\t"
        "mov r8, r3\n\t"
        "mov sb, r4\n\t"
        "mov sl, r5\n\t"
        "pop {r4, r5, r6, r7, pc}\n\t"
        ".syntax divided\n\t"
    );
}
