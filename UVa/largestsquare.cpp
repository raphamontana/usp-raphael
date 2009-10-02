/*  ========================================================================  */
/*  Raphael Montanari                                                5890010  */
/*  Largest Square                                                            */
/*  ========================================================================  */


#include <stdio.h>
#include <stdlib.h>


/*  Declaração das FUNÇÕES  ================================================  */
int calcula (int M, int N, int linha, int coluna, char Mat [100] [100]) {
    int nDir, Acabou, aux;
    nDir = 1;                                        // Armazena n° de elementos
    Acabou = 0;                                     // Variavel booleana que diz se chegou ao fim do loop, isto é: quando o elemento ao lado da posicao verificada difere.
    while (!Acabou)
         if ((linha - nDir >= 0) && (coluna - nDir >= 0) && (linha + nDir < M) && (coluna + nDir < N)) {
              for (aux = (coluna - nDir); aux <= (coluna + nDir); aux++)
                   if ((Mat [linha - nDir] [aux] != Mat [linha] [coluna]) || (Mat [linha + nDir] [aux] != Mat [linha] [coluna]))
                        Acabou++;
              for (aux = (linha - nDir + 1); aux <= (linha + nDir - 1); aux++)
                   if ((Mat [aux] [coluna - nDir] != Mat [linha] [coluna]) || (Mat [aux] [coluna + nDir] != Mat [linha] [coluna]))
                        Acabou++;
              if (!Acabou) nDir++;
         }
         else Acabou++;
    return ((2 * nDir) - 1);       // Isto é pq nDir diz quantos elemento iguai existem a direita, sendo a matriz simetrica temos (2*nDir), só q isto conta o centro duas vezes, por isso removemos 1.
}


/*  PROGRAMA PRINCIPAL  ===================================================== */
int main() {
    char matriz[100][100];
    int T, M, N, Q, r[20], c[20], i, j, k;
    scanf ("%d", &T);
    for (i = 0; i < T; i++) {
         scanf("%d %d %d", &M, &N, &Q);
         for (j = 0; j < M; j++)
              for (k = 0; k < N; k++)
                   scanf (" %c", &matriz [j] [k]);
         for (j = 0; j < Q; j++)
                   scanf ("%d %d", &r[j], &c[j]);
         printf ("%d %d %d\n", M, N, Q);
         for (k = 0; k < Q; k++) {
              printf ("%d\n", calcula (M, N, r[k], c[k], matriz));
         }
    }
    system ("PAUSE");
    return 0 ;
}
