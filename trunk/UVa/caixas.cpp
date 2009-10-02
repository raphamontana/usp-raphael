/*  Raphael Montanari                                        nº USP: 5890010  */
/*  Desempilhando Caixas                                                      */


#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;


int main(int argc, char *argv[])
{
   int nCaixas;
   int nPilhas;
   int Altura;

   stack<int> Pilha[1002];
   int Box;
   int Pilha_do_1;
   int nMinimo;
   int Direita;
   int Esquerda;
   int i, j;

   while (scanf("%d %d", &nCaixas, &nPilhas) && (nCaixas != 0) || nPilhas != 0)
   {
      nMinimo = 0;
      Esquerda = 0;
      Direita = 0;
      for (i = 1; i <= nPilhas; i++)
      {
         scanf("%d", &Altura);
         for (j = 0; j < Altura; j++)
         {
            scanf("%d", &Box);
            Pilha[i].push(Box);
            if (Box == 1)
               Pilha_do_1 = i;
         }
      }
      Box = Pilha[Pilha_do_1].top();
      while (Box != 1)
      {
            Pilha[Pilha_do_1].pop();
            Box = Pilha[Pilha_do_1].top();
            nMinimo++;
      }

      Altura = Pilha[Pilha_do_1].size() - 1;

      i = Pilha_do_1 - 1;
      while ((Pilha[i].size() > Altura) && (i > 0))
      {
         while(Pilha[i].size() > Altura)
         {
            Pilha[i].pop();
            Esquerda++;
         }
         i--;
      }

      i = Pilha_do_1 + 1;
      while ((Pilha[i].size() > Altura) && (i <= nPilhas))
      {
         while (Pilha[i].size() > Altura)
         {
            Pilha[i].pop();
            Direita++;
         }
         i++;
      }
      if (Direita < Esquerda)
         nMinimo += Direita;
      else
         nMinimo += Esquerda;

//Esvazia Pilha
      for (i = 1; i <= nPilhas; i++)
         while (!Pilha[i].empty())
            Pilha[i].pop();
      printf("%d\n", nMinimo);
   }
   return 0;
}
