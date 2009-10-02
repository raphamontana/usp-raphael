/*  Raphael Montanari          nº USP: 5890010  */
/*  Ogros  */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    int A[10000];
    int F[10000];
    int O[10000];
    int i, nivel;
    scanf("%d %d", &N, &M);
    for (i = 0; i < (N-1); i++)
         scanf("%d", &A[i]);
    for (i = 0; i < N; i++)
         scanf("%d", &F[i]);
    for (i = 0; i < M; i++)
         scanf("%d", &O[i]);
    for (i = 0; i < M; i++)
    {
         nivel = 0;
         while ((O[i] >= A[nivel]) && (nivel < N-1))
              nivel++;
         printf("%d ", F[nivel]);
    }
    return (0);
}
