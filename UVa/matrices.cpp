/*  Raphael Montanari                                        n° USP: 5890010  */
/*  UVa 11360 - Have Fun with Matrices                                        */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TamanhoMax 14

void row(int matriz[TamanhoMax][TamanhoMax], int a, int b, int tamanho)
{
    int i, j;
    int resultante[TamanhoMax][TamanhoMax];
    for (i = 1; i <= tamanho; i++)
         for (j = 1; j <= tamanho; j++)
              resultante[i][j] = matriz[i][j];
    for (i = 1; i <= tamanho; i++)
         resultante[a][i] = matriz[b][i];
    for (i = 1; i <= tamanho; i++)
         resultante[b][i] = matriz[a][i];
    for (i = 1; i <= tamanho; i++)
         for (j = 1; j <= tamanho; j++)
              matriz[i][j] = resultante[i][j];
}


void col(int matriz[TamanhoMax][TamanhoMax], int a, int b, int tamanho)
{
    int i, j;
    int resultante[TamanhoMax][TamanhoMax];
    for (i = 1; i <= tamanho; i++)
         for (j = 1; j <= tamanho; j++)
              resultante[i][j] = matriz[i][j];
    for (i = 1; i <= tamanho; i++)
         resultante[i][a] = matriz[i][b];
    for (i = 1; i <= tamanho; i++)
         resultante[i][b] = matriz[i][a];
    for (i = 1; i <= tamanho; i++)
         for (j = 1; j <= tamanho; j++)
              matriz[i][j] = resultante[i][j];
}


void inc(int matriz[TamanhoMax][TamanhoMax], int tamanho)
{
    int i, j;
    int resultante[TamanhoMax][TamanhoMax];
    for (i = 1; i <= tamanho; i++)
         for (j = 1; j <= tamanho; j++)
              if (matriz[i][j] == 9)
                   resultante[i][j] = 0;
              else resultante[i][j] = matriz[i][j] + 1;
    for (i = 1; i <= tamanho; i++)
         for (j = 1; j <= tamanho; j++)
              matriz[i][j] = resultante[i][j];
}


void dec(int matriz[TamanhoMax][TamanhoMax], int tamanho)
{
    int i, j;
    int resultante[TamanhoMax][TamanhoMax];
    for (i = 1; i <= tamanho; i++)
         for (j = 1; j <= tamanho; j++)
              if (matriz[i][j] == 0)
                   resultante[i][j] = 9;
              else resultante[i][j] = matriz[i][j] - 1;
    for (i = 1; i <= tamanho; i++)
         for (j = 1; j <= tamanho; j++)
              matriz[i][j] = resultante[i][j];
}


void transpose(int matriz[TamanhoMax][TamanhoMax], int tamanho)
{
    int i, j;
    int resultante[TamanhoMax][TamanhoMax];
    for (i = 1; i <= tamanho; i++)
         for (j = 1; j <= tamanho; j++)
              resultante[i][j] = matriz[j][i];
    for (i = 1; i <= tamanho; i++)
         for (j = 1; j <= tamanho; j++)
              matriz[i][j] = resultante[i][j];
}


void imprime(int matriz[TamanhoMax][TamanhoMax], int tamanho)
{
    int i, j;
    for (i = 1; i <= tamanho; i++)
    {
         for (j = 1; j <= tamanho; j++)
              printf("%d", matriz[i][j]);
         printf("\n");
    }
}



int main()
{
    int Casos;
    int Tamanho;
    int Operacoes;
    int a, b;
    int i, j, k;
    int mat[TamanhoMax][TamanhoMax];
    char linha[TamanhoMax];

    scanf("%d", &Casos);
    for (i = 0; i < Casos; i++)
    {
    	   scanf(" %d", &Tamanho);
    	   for (j = 1; j <= Tamanho; j++)
    	   {
    	   	  scanf("%s", linha);
    	   	  for (k = 0; k < Tamanho; k++)
    	   	  {
    	   	       mat[j][k+1] = linha[k] - '0';
    	   	  }
    	   }
    	   scanf("%d", &Operacoes);
    	   for (j = 0; j < Operacoes; j++)
    	   {
    	        scanf("%s", linha);
    	        if (linha[0] == 'r')
    	        {
    	             scanf("%d %d", &a, &b);
    	             row(mat, a, b, Tamanho);
    	        }
    	        if (linha[0] == 'c')
    	        {
    	             scanf("%d %d", &a, &b);
    	             col(mat, a, b, Tamanho);
    	        }
    	        if (!strcmp(linha, "inc"))
    	        {
    	             inc(mat, Tamanho);
    	             continue;
    	        }
    	        if (!strcmp(linha, "dec"))
    	        {
    	             dec(mat, Tamanho);
    	             continue;
    	        }
    	        if (!strcmp(linha, "transpose"))
    	        {
    	             transpose(mat, Tamanho);
    	             continue;
    	        }
    	   }
    	   printf("Case #%d\n", i+1);
    	   imprime(mat, Tamanho);
    	   printf("\n");
    }
}
