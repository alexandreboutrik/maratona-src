#include <err.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define     Reg     register
#define     S16     wchar_t
#define     UX      uintmax_t
#define     U8      uint8_t

int
main(void)
{
    S16     *s, c;
    UX       k;
    U8       t;
    Reg U8   i;

    scanf("%" SCNu8 " %" SCNuMAX, &t, &k);

    if ((s = (S16 *) malloc(t * sizeof(S16))) == NULL)
        err(errno, "malloc");

    scanf("%ls", &(s[0]));

    for (i = 0; i < t; i++)
    {
        c = s[i] + (k % 26);

        while (c > 122) c -= 26;

        printf("%lc", c);
    }

    printf("\n");

    free(s);

    return 0;
}

