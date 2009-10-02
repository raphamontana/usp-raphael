/* =========================================================================  */
/*  Raphael Montanari                                        nº USP: 5890010  */
/*  Jolly Jumpers                                                             */
/* =========================================================================  */

#include <stdio.h>                               // procedimentos de leitura
#include <stdlib.h>                              // função abs (módulo)

int main (void) {
    int n;                                       // Tamanho da sequencia a ser lida
    int i;
    while (scanf("%d", &n) != EOF) {
         int vetor [3001] = {0};                 //  declara e inicia com 0 o vetor de inteiros que armazenara a sequencia lida
         for (i = 0; i < n; i++)
              scanf ("%d", &vetor [i]);          //  le a sequencia
         int diferenca [3000] = {0};             //  vetoror que guarda a diferença entre a[i] e a[i+1]
         int aux = 0;                            //  valor da diferenca entre os n°s adjacentes da sequencia
         for (i = 0; i < n - 1; i++) {
              aux = abs (vetor [i + 1] - vetor [i]);
              diferenca [aux] = 1;               //  guarda diferencas no vetor
         }
         int eh_jolly = 0;                       //  flag: para cada valor da diferença, se se esse valor existir na sequencia de
                                                 //   entrada, entao este é incrementado se no fim ele for igual ao numero de termos
                                                 //   da sequencia menos um (o primeiro nao é contado) entao a sequencia é jolly jumper
         for (i = 1; i < n; i++)
              if (diferenca [i] == 1) eh_jolly++;  //  percorre o vetor de diferenças pra saber o n° de termos que esta neste vetor e na sequencia de entrada
         if (eh_jolly == n-1)
              printf ("Jolly\n");
         else if (eh_jolly != n-1)
                   printf ("Not jolly\n");
    }
    return 0;
}
