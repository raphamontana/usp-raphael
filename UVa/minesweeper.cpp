/*============================================================================*/
/*  Raphael Montanari                                        nº USP: 5890010  */
/*  Minesweeper                                                               */
/*============================================================================*/

#include <stdio.h>

int main (void) {
    int field = 0;
    char minas;
    int coluna, linha;
    char entrada [100] [100];
    char saida [100] [100];
    int i, j;
    while (scanf("%d %d", &linha, &coluna) && (linha || coluna)) {
         field++;
         if (field > 1)
              printf("\n");
         printf ("Field #%d:\n", field);
         for (i = 0; i < linha; i++)
              for (j = 0; j < coluna; j++)
                   scanf (" %c", &entrada [i] [j]);
         for (i = 0; i < linha; i++)
              for (j = 0; j < coluna; j++)
                   if (entrada [i][j] == '*')
                        saida [i] [j] = '*';
                   else {
                        minas = '0';
                        if (i-1>=0 && j-1 >=0 && entrada[i-1][j-1]=='*') minas++;
                        if (i-1>=0 && entrada[i-1][j] == '*') minas++;
                        if (i-1>=0 && j+1<coluna && entrada[i-1][j+1]=='*') minas++;
                        if (j+1<coluna && entrada[i][j+1]=='*') minas++;
                        if (i+1<linha && j+1<coluna && entrada[i+1][j+1]=='*') minas++;
                        if (i+1<linha && entrada[i+1][j]=='*') minas++;
                        if (i+1<linha && j-1>=0 && entrada[i+1][j-1]=='*') minas++;
                        if (j-1>=0 && entrada[i][j-1]=='*') minas++;
                        saida [i] [j] = minas;
                   }
         for (i = 0; i < linha; i++){
              for (j = 0; j < coluna; j++)
                   printf ("%c", saida [i] [j]);
              printf ("\n");
         }
    }
    return (0);
}
