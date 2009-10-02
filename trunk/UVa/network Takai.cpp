/*  ========================================================================  */
/*  Raphael Montanari                                                5890010  */
/*  UVa 10050 - Network Connection - Accepted                                 */
/*  ========================================================================  */


#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
    int casos;                                                                  /*  Número de casos de teste  */
    int computadores;                                                           /*  Número de computadores  */
    int sim, nao;                                                               /*  Resposta do problema  */
    int C1, C2;                                                                 /*  Pares de máquinas a operar  */
    int conjuntos;                                                              /*  Número de conjuntos  */
    bool inseriu, achou, acabou;
    int i, j;
    set<int> s[102];

    scanf("%d", &casos);
    while (casos--)
    {
         conjuntos = 0;
         sim = 0;
         nao = 0;
         acabou = 0;
         scanf(" %d", &computadores);
         while (!acabou)
         {
              if (scanf(" c %d %d", &C1, &C2) == 2)
              {
                   inseriu = 0;
                   for (i = 0; i < conjuntos; i++)
                   {
                        if (s[i].find(C1) != s[i].end())
                        {
                             for (j = i; j < conjuntos; j++)
                                  if (s[j].find(C2) != s[j].end())
                                  {
                                       set_union(s[i].begin(), s[i].end(), s[j].begin(), s[j].end(), inserter(s[i], s[i].begin()));
                                       set_union(s[i].begin(), s[i].end(), s[j].begin(), s[j].end(), inserter(s[j], s[j].begin()));
                                       s[i].insert(C1);
                                       s[i].insert(C2);
                                       s[j].insert(C1);
                                       s[j].insert(C2);
                                       inseriu = 1;
                                  }
                             if (!inseriu)
                             {
                                  s[i].insert(C2);
                                  inseriu = 1;
                             }
                        }
                        if ((s[i].find(C2) != s[i].end()))
                        {
                             for (j = i; j < conjuntos; j++)
                                  if (s[j].find(C1) != s[j].end())
                                  {
                                       set_union(s[i].begin(), s[i].end(), s[j].begin(), s[j].end(), inserter(s[i], s[i].begin()));
                                       set_union(s[i].begin(), s[i].end(), s[j].begin(), s[j].end(), inserter(s[j], s[j].begin()));
                                       s[i].insert(C1);
                                       s[i].insert(C2);
                                       s[j].insert(C1);
                                       s[j].insert(C2);
                                       inseriu = 1;
                                  }
                             if (!inseriu)
                             {
                                  s[i].insert(C1);
                                  inseriu = 1;
                             }
                        }
                   }
                   if (!inseriu)                                                /*  Cria novo conjunto  */
                   {
                        s[conjuntos].insert(C1);
                        s[conjuntos].insert(C2);
                        conjuntos++;
                   }
              }
              else
                   if (scanf(" q %d %d", &C1, &C2) == 2)
                   {
                        achou = 0;
                        for (i = 0; i < conjuntos; i++)
                             if ((s[i].find(C1) != s[i].end()) && (s[i].find(C2) != s[i].end()))
                                  achou = 1;
                        if (achou)
                             sim += 1;
                        else
                             nao += 1;
                   }
                   else
                        acabou = 1;                                             /*  Não é nem inserção nem consulta  */
         }
         for (i = 0; i < 100; i++)                                              /*  Limpa os conjuntos antes de prosseguir ao proximo caso teste  */
              s[i].clear();
         printf("%d,%d\n", sim, nao);                                           /*  Imprime o resultado  */
         if (casos)
              printf("\n");
    }
    return 0;
}
