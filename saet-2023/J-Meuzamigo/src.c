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
    U32     *V;
    U32      N, Ni, A, B, Maior, Tmp;
    Reg U32  i;

    scanf("%" SCNu32, &N);

    if ((V = (U32 *) calloc(N, sizeof(U32))) == NULL)
        err(errno, "calloc");

    Ni = (N - 1);
    for (i = 0, Maior = 0; i < Ni; i++)
    {
        scanf("%" SCNu32 " %" SCNu32, &A, &B);

        A--; B--;

        Tmp = V[A] + 1;

        if (Tmp < V[B] || V[B] == 0)
            V[B] = V[A] + 1;

        if (V[B] > Maior)
            Maior = V[B];
    }

    printf("%" PRIu32 "\n", Maior);

    free(V);

    return 0;
}

