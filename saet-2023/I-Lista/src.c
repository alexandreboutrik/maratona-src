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
    S16      c1, c2, c3, c4, fc;
    U16      N;
    Reg U16  i, j;

    scanf("%" SCNu16, &N);

    if ((S = (Word *) malloc(N * sizeof(Word))) == NULL)
        err(errno, "malloc");

    for (i = 0; i < N; i++)
        scanf("%ls", &(S[i].S[0]));

    for (i = 'a'; i <= 'x';)
    {
        for (j = 0; j < N; j++)
        {
            fc = tolower(S[j].S[0]);

            if (fc == i || fc == i+1 || fc == i+2 || fc == i+3)
                printf("%ls\n", S[j].S);
        }

        if (i == 'u')   i += 3;
        else            i += 4;
    }

    free(S);

    return 0;
}

