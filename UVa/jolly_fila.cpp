/*  ========================================================================  */
/*  ====          Jolly Jumpers (c/ fila de prioridades)                ====  */
/*  Raphael Montanari                                        nº USP: 5890010  */
/*  ========================================================================  */


#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;


int main (void) {
    int n;
    int i, aux;
    int eh_jolly;
    int vetor[3001];
    priority_queue<int> diferenca;

    while (scanf("%d", &n) != EOF)
    {
         eh_jolly = 1;
         for (i = 0; i < n; i++)
              scanf ("%d", &vetor[i]);
         for (i = 0; i < n - 1; i++)
              diferenca.push(abs (vetor [i + 1] - vetor [i]));

         for (i = n - 1; i > 0; i--)
         {
              if (i != diferenca.top())
              {
                   eh_jolly = 0;
                   break;
              }
              diferenca.pop();
         }
         while (!diferenca.empty())
              diferenca.pop();

         if (eh_jolly)
              printf ("Jolly\n");
         else printf ("Not jolly\n");
    }
    return 0;
}
