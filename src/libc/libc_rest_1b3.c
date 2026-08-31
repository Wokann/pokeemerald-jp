// JP newlib math/syscall stubs.
// The IEEE double-bit classifiers remain naked: agbcc reassigns the bit-test
// intermediates from the JP r3/r2 sequence even when their object sizes match.

__attribute__((naked)) int isinf(double x)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "ldr r3, _0829B670\n\t"
        "ands r3, r0\n\t"
        "rsbs r2, r1, #0\n\t"
        "orrs r2, r1\n\t"
        "lsrs r2, r2, #0x1f\n\t"
        "orrs r3, r2\n\t"
        "ldr r0, _0829B674\n\t"
        "subs r3, r0, r3\n\t"
        "rsbs r0, r3, #0\n\t"
        "orrs r3, r0\n\t"
        "lsrs r3, r3, #0x1f\n\t"
        "movs r0, #1\n\t"
        "subs r0, r0, r3\n\t"
        "bx lr\n\t"
        ".align 2, 0\n\t"
        "_0829B670: .4byte 0x7FFFFFFF\n\t"
        "_0829B674: .4byte 0x7FF00000\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) int isnan(double x)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "ldr r3, _0829B690\n\t"
        "ands r3, r0\n\t"
        "rsbs r2, r1, #0\n\t"
        "orrs r2, r1\n\t"
        "lsrs r2, r2, #0x1f\n\t"
        "orrs r3, r2\n\t"
        "ldr r0, _0829B694\n\t"
        "subs r3, r0, r3\n\t"
        "lsrs r3, r3, #0x1f\n\t"
        "adds r0, r3, #0\n\t"
        "bx lr\n\t"
        ".align 2, 0\n\t"
        "_0829B690: .4byte 0x7FFFFFFF\n\t"
        "_0829B694: .4byte 0x7FF00000\n\t"
        ".syntax divided\n\t"
    );
}

extern void *_sbrk(int incr);

void *_sbrk_r(void *ptr, int incr)
{
    int *err = (int *)0x0300764C;
    void *result;

    *err = 0;
    result = _sbrk(incr);
    if (result == (void *)-1 && *err)
        *(int *)ptr = *err;

    return result;
}

extern int _read_r(void *reent, int fd, char *buf, int len);

int __sread(void *cookie, char *buf, int len)
{
    int result = _read_r(*(void **)((char *)cookie + 0x54), *(short *)((char *)cookie + 0x0E), buf, len);

    if (result >= 0)
        *(int *)((char *)cookie + 0x50) += result;
    else
        *(short *)((char *)cookie + 0x0C) &= ~0x1000;

    return result;
}

extern int _lseek_r(void *reent, int fd, int offset, int whence);
extern int _write_r(void *reent, int fd, char *buf, int len);

int __swrite(void *cookie, char *buf, int len)
{
    if (*(short *)((char *)cookie + 0x0C) & 0x100)
        _lseek_r(*(void **)((char *)cookie + 0x54), *(short *)((char *)cookie + 0x0E), 0, 2);

    *(short *)((char *)cookie + 0x0C) &= ~0x1000;
    return _write_r(*(void **)((char *)cookie + 0x54), *(short *)((char *)cookie + 0x0E), buf, len);
}

int __sseek(void *cookie, int offset, int whence)
{
    int result = _lseek_r(*(void **)((char *)cookie + 0x54), *(short *)((char *)cookie + 0x0E), offset, whence);

    if (result == -1)
        *(short *)((char *)cookie + 0x0C) &= ~0x1000;
    else
    {
        *(short *)((char *)cookie + 0x0C) |= 0x1000;
        *(int *)((char *)cookie + 0x50) = result;
    }

    return result;
}

extern int _close_r(void *reent, int fd);

int __sclose(void *cookie)
{
    return _close_r(*(void **)((char *)cookie + 0x54), *(short *)((char *)cookie + 0x0E));
}
