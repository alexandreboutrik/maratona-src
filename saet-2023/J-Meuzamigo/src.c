#include <err.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define     Reg     register
#define     Byte    char
#define     U32     uint32_t

int
main(void)
{
    U32      N, Ni, A, B;
    Byte    *V, Maior;
    Reg U32  i;

    scanf("%" SCNu32, &N);

    if ((V = (Byte *) calloc(N, sizeof(Byte))) == NULL)
        err(errno, "calloc");

    Ni = (N - 1);
    for (i = 0, Maior = 0; i < Ni; i++)
    {
        scanf("%" SCNu32 " %" SCNu32, &A, &B);

        V[B-1] = V[A-1] + 1;

        if (V[B-1] > Maior)
            Maior = V[B-1];
    }

    printf("%" PRIu32 "\n", Maior);

    free(V);

    return 0;
}

