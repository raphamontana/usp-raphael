/* =========================================================================  */
/*  Raphael Montanari                                        nº USP: 5890010  */
/*  Network Connections                                                       */
/* =========================================================================  */


#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;


int main()
{
    int casos;
    int nComputadores;
    int pc[1000];
    int no1, no2;
    int sim, nao;
    int j, k, sai;
    int g;

    scanf("%d", &casos);
    while (casos--)
    {
	    sim = nao = sai = 0;
         scanf("\n%d", &nComputadores);
         for (j = 1; j <= nComputadores; j++)
              pc[j] = 0;
         g = 1;
         while (!sai)
         {
              if (scanf("\nc %d %d", &no1, &no2) == 2)
              {
                   if (pc[no1] == 0)
                   {
                        if (pc[no2] == 0)
                        {
                             pc[no1] = g;
                             pc[no2] = g;
                             g++;
                        }
                        else
                             pc[no1] = pc[no2];
                   }
                   else
                   {
                        if (pc[no2] == 0)
                             pc[no2] = pc[no1];
                        else
                        {
                             k = pc[no1];
                             for (j = 1; j <= nComputadores; j++)
                                  if (k == pc[j])
                                       pc[j] = pc[no2];
                        }
                   }
              }
              else if (scanf("\nq %d %d", &no1, &no2) == 2)
                        if (pc[no1] == pc[no2] && pc[no1] != 0)
                             sim++;
                        else
                             nao++;
                   else sai++;
         }
         printf("%d,%d\n", sim, nao);
         if (casos)
              printf("\n");
    }
}
