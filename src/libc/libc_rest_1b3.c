// JP newlib math/syscall stubs.
// The IEEE double-bit classifiers use the JP newlib bit-test sequence.

union IeeeDoubleBits
{
    double value;
    unsigned int words[2];
};

int isinf(double x)
{
    union IeeeDoubleBits bits;
    unsigned int high;
    unsigned int low;

    bits.value = x;
    high = bits.words[0] & 0x7FFFFFFF;
    low = bits.words[1];
    low = -low | low;
    high |= low >> 31;
    high = 0x7FF00000 - high;
    high = -high | high;
    return 1 - (high >> 31);
}

int isnan(double x)
{
    union IeeeDoubleBits bits;
    unsigned int high;
    unsigned int low;

    bits.value = x;
    high = bits.words[0] & 0x7FFFFFFF;
    low = bits.words[1];
    low = -low | low;
    high |= low >> 31;
    high = 0x7FF00000 - high;
    return high >> 31;
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
