/*  Raphael Montanari    nºUSP: 5890010  */
/*  Circuito Bioquímico Digital          */


#include <cstdio>
#include <cstdlib>
#include <cstring>


int main()
{
   int nPontos;
   int nMedicoes;
   int Comprimento;

   int nPalitos;
   int Matriz[1002][1002];
   int i, j;
   int Serie;

   while (scanf("%d %d %d", &nPontos, &nMedicoes, &Comprimento) && (nPontos != 0) || nMedicoes != 0 || Comprimento != 0)
   {
      nPalitos = 0;
      for (i = 0; i < nMedicoes; i++)
         for (j = 0; j < nPontos; j++)
            scanf(" %d", &Matriz[i][j]);
      for (j = 0; j < nPontos; j++)
         for (i = 0; i < nMedicoes; i++)
         {
            Serie = 0;
            while ((Matriz[i][j] == 1) && (i < nMedicoes))
            {
               Serie++;
               i++;
            }
            if (Serie >= Comprimento)
               nPalitos += 1;
         }
      printf("%d\n", nPalitos);
   }
}
