#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
    const byte *s = src;
    byte *d = dst;

    while (n--)
        *d++ = *s++;
    return dst;
}

static void ft_cpy(byte *restrict dst, const byte *restrict src, unsigned long n)
{
    while (n--)
        *dst++ = *src++;
}

void *ft_memcpy(void *restrict dst, const void *restrict src, unsigned long n)
{

    if (!dst || !src)
        return NULL;

    __uintmax_t *dest = (__uintmax_t *)dst;
    const __uintmax_t *source = (const __uintmax_t *)src;
    size_t xlen = n / 8;

    while (true)
    {
        if (!xlen)
        {
            ft_cpy((byte *)dest, (const byte *)source, n % 8);
            return dst;
        }
        *dest++ = *source++;
        xlen--;
    }
    return 0;
}
