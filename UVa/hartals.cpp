/* =========================================================================  */
/*  Raphael Montanari                                        nº USP: 5890010  */
/*  Hartals                                                                   */
/* =========================================================================  */


#include <stdio.h>


int main()
{
    int CasosTestes, nDias, nPartidos;
    int hartals[3651];
    int hartal, contador, i, j;
    scanf("%d", &CasosTestes);
    while (CasosTestes--)
    {
         contador = 0;
         scanf("%d %d", &nDias, &nPartidos);
         for (i = 0; i <= nDias; i++)
              hartals[i] = 0;
         for (i = 0; i < nPartidos; i++)
	     {
              scanf("%d", &hartal);
              for (j = 0; j*hartal - 1 <= nDias; j++)
                   hartals[j*hartal - 1] = 1;
         }
	     for (i = 0; i < nDias; i++)
              if ((hartals[i]) && (i%7 != 5) && (i%7 != 6))
                   contador++;
         printf("%d\n", contador);
    }
}
