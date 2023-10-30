#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define     Reg     register
#define     U32     uint32_t
#define     U8      uint8_t

int
main(void)
{
    U32     N;
    U32     B[8] = { 100, 50, 20, 10, 5, 2, 1 };
    Reg U8  i;

    scanf("%" SCNu32, &N);

    printf("%" PRIu32 "\n", N);

    for (i = 0; i < 7; i++)
    {
        printf("%" PRIu32 " nota(s) de R$ %" PRIu32 ",00\n", (N/B[i]), B[i]);
        N %= B[i];
    }

    return 0;
}

