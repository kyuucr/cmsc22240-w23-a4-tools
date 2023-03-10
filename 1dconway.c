#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int N = 10;
    int loopN = 10;
    int isVerbose = 0;
    int opt;
    while((opt = getopt(argc, argv, "n:l:v")) != -1)
    {
        switch(opt)
        {
            case 'n':
                N = atoi(optarg);
                break;
            case 'l':
                loopN = atoi(optarg);
                break;
            case 'v':
                isVerbose = 1;
        }
    }
    if (isVerbose)
    {
        printf("N: %d, loopN: %d\n", N, loopN);
    }

    // Inits
    srand(1);
    int board[N + 2];
    board[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        board[i] = rand() % 2;
    }
    board[N + 1] = 0;

    for (int loop = 0; loop < loopN; loop++)
    {
        if (isVerbose)
        {
            printf("loop %d: ", loop + 1);
        }
        int temp[N];
        for (int i = 1; i <= N; i++)
        {
            int neighborCount = 0;
            neighborCount += board[i - 1];
            neighborCount += board[i + 1];

            if (neighborCount == 1)
            {
                temp[i - 1] = 1;
            }
            else
            {
                temp[i - 1] = 0;
            }

        }
        for (int i = 1; i <= N; i++)
        {
            board[i] = temp[i - 1];
            if (isVerbose)
            {
                printf("%d", board[i]);
                if (i == N)
                {
                    printf("\n");
                }
                else
                {
                    printf(",");
                }
            }
        }
    }
    return 0;
}

