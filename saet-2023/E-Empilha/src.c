#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define     Reg     register
#define     U16     uint16_t

int
main(void)
{
    U16     N;
    Reg U16 B, Copos;

    scanf("%" SCNu16, &N);

    for (B = 2, Copos = 1; Copos <= N; B++)
        Copos += B;

    B -= 2;

    printf("%" PRIu16 "\n", B);

    return 0;
}

