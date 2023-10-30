#include <err.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define     Fn      static
#define     In      inline
#define     Reg     register
#define     Cst     const

#define     S16     wchar_t
#define     U32     uint32_t
#define     U8      uint8_t
#define     U0      void

Fn  In U0   Alloc   (U8**, Cst U32);
Fn  In U0   Exit    (wchar_t, U8**, U8**);

Fn In U0
Alloc(U8 **V, Cst U32 N)
{
    if ((*V = (U8 *) malloc(N * sizeof(U8))) == NULL)
        err(errno, "malloc");
}

Fn In U0
Exit(S16 C, U8 **V, U8 **W)
{
    printf("%lc\n", C);

    free(*V); free(*W);
    exit(EXIT_SUCCESS);
}

int
main(void)
{
    U8       N;
    U8      *R, *A;
    Reg U8   i;

    scanf("%" SCNu8, &N);

    Alloc(&R, N); Alloc(&A, N);

    for (i = 0; i < N; i++)
        scanf("%" SCNu8, &(R[i]));

    for (i = 0; i < N; i++)
    {
        scanf("%" SCNu8, &(A[i]));

        if (R[i] == A[i] && A[i] == 1)
            Exit('N', &R, &A);
    }

    Exit('S', &R, &A);
    return 0;
}

