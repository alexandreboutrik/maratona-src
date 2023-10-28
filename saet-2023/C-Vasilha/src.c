#include <inttypes.h>
#include <locale.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define     Reg     register
#define     F64     double
#define     UX      uintmax_t
#define     U16     uint16_t

int
main(void)
{
    F64     L1, L2, L3, P, A;
    U16     N;
    Reg U16 i;

    scanf("%" SCNu16, &N);

    for (i = 0; i < N; i++)
    {
        scanf("%lf %lf %lf", &L1, &L2, &L3);

        P = ((L1 + L2 + L3) / 2);
        A = sqrt((P * (P - L1) * (P - L2) * (P - L3)));

        printf("%.2lf\n", (A/P));
    }

    return 0;
}

