#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define     Reg     register
#define     S16     wchar_t
#define     U16     uint16_t

typedef struct Word Word;
struct Word {
    S16 S[32];
};

int
main(void)
{
    Word    *S; 
    S16      c;
    U16      N;
    Reg U16  i, j, k, inc;

    scanf("%" SCNu16, &N);

    if ((S = (Word *) malloc(N * sizeof(Word))) == NULL)
        err(errno, "malloc");

    for (i = 0; i < N; i++)
        scanf("%ls", &(S[i].S[0]));

    for (i = 'a', inc = 4; i <= 'x'; i += inc)
    {
        if (i == 'u') inc--;

        for (j = 0; j < N; j++)
        {
            c = tolower(S[j].S[0]);

            for (k = 0; k < inc; k++)
                if (c == i+k)
                    printf("%ls\n", S[j].S);
        }
    }

    free(S);

    return 0;
}

