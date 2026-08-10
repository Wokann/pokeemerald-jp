/*
 * C runtime library functions extracted from the official agbcc newlib
 * sources (https://github.com/pret/agbcc, libc/ directory).
 * They compile with old_agbcc -O2 -fno-builtin to match the bytes in the
 * Japanese Emerald ROM.
 */

#define size_t unsigned int

#define _PTR void *
#define _AND ,
#define _CONST const
#define _DEFUN(name, arglist, args) name(args)
#define UNALIGNED(X, Y) (((long)X & (sizeof(long) - 1)) | ((long)Y & (sizeof(long) - 1)))
#define BIGBLOCKSIZE (sizeof(long) << 2)
#define LITTLEBLOCKSIZE (sizeof(long))
#define TOO_SMALL(LEN) ((LEN) < BIGBLOCKSIZE)
#define DETECTNULL(X) (((X) - 0x01010101) & ~(X) & 0x80808080)

_PTR _DEFUN(memcpy, (dst0, src0, len0),
	_PTR dst0 _AND
	_CONST _PTR src0 _AND
	size_t len0)
{
  char *dst = dst0;
  _CONST char *src = src0;
  long *aligned_dst;
  _CONST long *aligned_src;
  int   len =  len0;

  if (!TOO_SMALL(len) && !UNALIGNED (src, dst))
    {
      aligned_dst = (long*)dst;
      aligned_src = (long*)src;
      while (len >= BIGBLOCKSIZE)
        {
          *aligned_dst++ = *aligned_src++;
          *aligned_dst++ = *aligned_src++;
          *aligned_dst++ = *aligned_src++;
          *aligned_dst++ = *aligned_src++;
          len -= BIGBLOCKSIZE;
        }
      while (len >= LITTLEBLOCKSIZE)
        {
          *aligned_dst++ = *aligned_src++;
          len -= LITTLEBLOCKSIZE;
        }
      dst = (char*)aligned_dst;
      src = (char*)aligned_src;
    }
  while (len--)
    *dst++ = *src++;
  return dst0;
}

int
_DEFUN (strcmp, (s1, s2),
	_CONST char *s1 _AND
	_CONST char *s2)
{
  unsigned long *a1;
  unsigned long *a2;

  if (!UNALIGNED (s1, s2))
    {
      a1 = (unsigned long*)s1;
      a2 = (unsigned long*)s2;
      while (*a1 == *a2)
        {
          if (DETECTNULL (*a1))
            return 0;
          a1++;
          a2++;
        }
      s1 = (char*)a1;
      s2 = (char*)a2;
    }

  while (*s1 != '\0' && *s1 == *s2)
    {
      s1++;
      s2++;
    }
  return (*(unsigned char *) s1) - (*(unsigned char *) s2);
}

char*
_DEFUN (strcpy, (dst0, src0),
	char *dst0 _AND
	_CONST char *src0)
{
  char *dst = dst0;
  _CONST char *src = src0;
  long *aligned_dst;
  _CONST long *aligned_src;

  if (!UNALIGNED (src, dst))
    {
      aligned_dst = (long*)dst;
      aligned_src = (long*)src;
      while (!DETECTNULL(*aligned_src))
        {
          *aligned_dst++ = *aligned_src++;
        }
      dst = (char*)aligned_dst;
      src = (char*)aligned_src;
    }

  while (*dst++ = *src++)
    ;
  return dst0;
}
