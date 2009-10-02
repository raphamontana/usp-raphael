/* =========================================================================  */
/*  Raphael Montanari                                        nº USP: 5890010  */
/*  UVa 10608 - Friends                                             ACCEPTED  */
/* =========================================================================  */


#include <stdio.h>


void Insere_Cjto(int A, int B, int *Cjtos, int habitantes, int set[30001]);


int main(int argc, char *argv[])
{
    int Casos;
    int Habitantes;
    int n_Pares;
    int A, B;
    int Maior;
    int Cjtos;
    int i, j;
    int set[30001];
    int nElSet;

    scanf("%d", &Casos);
    while (Casos--)
    {
         Cjtos = 0;
         scanf("%d %d", &Habitantes, &n_Pares);
         while (n_Pares--)
         {
              scanf("%d %d", &A, &B);
              Insere_Cjto(A, B, &Cjtos, Habitantes, set);
         }
         Maior = 0;
         for (j = 1; j <= Cjtos; j++)                                           /* j vai percorrer todos os conjuntos */
         {
              nElSet = 0;
              for (i = 1; i <= Habitantes; i++)
                   if (set[i] == j)
                        nElSet++;
              if (Maior < nElSet)
                   Maior = nElSet;
         }
         printf("%d\n", Maior);
         for (i = 1; i <= Habitantes; i++)                                       /*  Limpa os conjuntos antes de prosseguir ao caso teste  */
              set[i] = 0;
    }
    return (0);
}

void Insere_Cjto(int A, int B, int *Cjtos, int habitantes, int set[30001])
{
    if (set[A] == 0)
    {
         if (set[B] == 0)                            /*  Nao tem nem A nem B  */
         {
              (*Cjtos)++;
              set[A] = (*Cjtos);
              set[B] = (*Cjtos);
         }
         else                                   /*  Nao tem o A, mas tem o B  */
         {
              set[A] = set[B];
         }
    }
    else
    {
         if (set[B] == 0)                       /*  Tem o A, mas nao tem o B  */
         {
              set[B] = set[A];
         }
         else                               /*  Os dois elementos já existem  */
         {
              int Cjto_do_A = set[A];
              int i;
              for (i = 1; i <= habitantes; i++)
                   if (Cjto_do_A == set[i])
                        set[i] = set[B];
         }
    }
}
