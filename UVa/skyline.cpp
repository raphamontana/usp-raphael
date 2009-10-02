/*  ========================================================================  */
/*  Raphael Montanari                                        Nº USP: 5890010  */
/*  ========================================================================  */

#include <stdio.h>

int main(void) {
	int esq, dir, alt;
	int Altura [10000];
	int Esquerda = 10000, Direita = 0;
	int i;

	for (i = 0; i < 10000; i++)
         Altura [i] = 0;
	while (scanf("%d %d %d", &esq, &alt, &dir) != EOF) {
		 if (esq < Esquerda)
		      Esquerda = esq;
		 if (Direita < dir)
              Direita = dir;
		 for (i = esq; i < dir; i++)
              if (alt > Altura [i])
				   Altura [i] = alt;
    }
	for (i = Esquerda; i <= Direita; i++ ) {
		 if (i == Esquerda)
              printf ("%d %d ", i, Altura [i]);
		 else
              if (Altura [i] != Altura [i - 1]) {
			       printf ("%d %d", i, Altura [i]);
                   if (i != Direita)
                        printf (" ");
		      }
	}
    printf("\n");
}
