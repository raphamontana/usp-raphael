/*  ========================================================================  */
/*  Raphael Montanari                                        n° USP: 5890010  */
/*  My Dear Neighbours                                             UVa 10928  */
/*  ========================================================================  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int Ncasos;
    scanf("%d", &Ncasos);
    int Places;
    int nVizinhos;
    int i, j;
    int v[1010];
    char string [2010];
    while (Ncasos--)
    {
         scanf("%d\n", &Places);
         for (i = 1; i <= Places; i++)
         {
              fgets(string, 2010, stdin);
              char * ch;
              ch = strtok (string, " ");
              v[i] = 1;
              while (ch != NULL)
              {
                   ch = strtok (NULL, " \0");
                   v[i]++;
              }
         }
         int Menor = 1;
         for (i = 2; i <= Places; i++)
         {
              if (v[Menor] > v[i])
                   Menor = i;
              else if (v[Menor] == v[i])
              {
                   printf ("%d ", Menor);
                   Menor = i;
              }
         }
         printf ("%d\n", Menor);
    }
    return 0;
}
