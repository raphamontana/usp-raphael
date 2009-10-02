/*  Raphael Montanari    nºUSP: 5890010  */
/*  Copa do Mundo                        */


#include <cstdio>
#include <cstdlib>
#include <cstring>


int main()
{
   int nTimes;
   int nPartidas;
   char time[11];

   int Total;
   int nEmpates;
   int Pontos[201];
   int i;

   while (scanf("%d %d", &nTimes, &nPartidas) && nTimes != 0)
   {
      nEmpates = 0;
      Total = 0;
      for (i = 0; i < nTimes; i++)
      {
         scanf("%s %d", &time, &Pontos[i]);
         Total += Pontos[i];
      }
      nEmpates = 3*nPartidas - Total;
      printf("%d\n", nEmpates);
   }
}
