/*  ========================================================================  */
/*  Raphael Montanari                                        n° USP: 5890010  */
/*  Decoding the message                                           UVa 11220  */
/*  ========================================================================  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d\n", &T);
    int n_caso;
    char linha[902];
    char saida[31];
    char temp[31];
    int posicao;
    char *ponteiro;
    for (n_caso = 1; n_caso <= T; n_caso++)
    {
         strcpy(saida, "\0");
         while (strcmp(gets(linha), ""))
         {
              posicao = 0;
              strcpy(temp, "\0");
              ponteiro = strtok (linha, " ");
              while (ponteiro != NULL)
              {
                   if (posicao < strlen(ponteiro))
                   {
                        temp[posicao] = ponteiro[posicao];
                        posicao++;
                   }
                   ponteiro = strtok (NULL, " ");
              }
              temp[posicao] = '\0';
              strcat(temp, "\n");
              strcat(saida, temp);
         }
         printf("Case #%d:\n", n_caso);
         printf("%s\n", saida);
    }
    return (0);
}
