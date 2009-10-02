/*============================================================================*/
/* Raphael Montanari nº USP: 5890010                                          */
/* The 3n+1 Problem                                                           */
/*============================================================================*/


#include <stdio.h>
#include <stdlib.h>

int ciclos (int n) {
    int cont = 1;
    while (n != 1) {
         if (n % 2 == 0) {
              n = n / 2;
         }
         else {
              n = (n * 3) + 1;
         }
         cont += 1;
    }
    return (cont);
}

int maior_ciclo (int inf, int sup) {
    int c, maior = 0;
    for (c = inf; c <= sup; c++) {
         if (ciclos(c) > maior) {
              maior = ciclos(c);
         }
    }
    return (maior);
}

int main (void) {
    int i, j;
    while (scanf ("%d %d", &i, &j) != EOF) {
         if (i <= j) {
              printf ("%d %d %d\n", i, j, maior_ciclo (i, j));
         }
         else {
              printf ("%d %d %d\n", i, j, maior_ciclo (j, i));
         }
    }
    return (0);
}
