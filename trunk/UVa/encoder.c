/* =========================================================================  */
/*  Raphael Montanari                                        nº USP: 5890010  */
/*  Encoder and Decoder                                                       */
/* =========================================================================  */


#include <stdio.h>
#include <string.h>


void inverte(char string[300]) {
    int i;
    int tamanho = strlen(string);
    char saida[300];
    for (i = 0; i < tamanho; i++)
         saida[i] = string[tamanho-1-i];
    for (i = 0; i < tamanho; i++)
         string[i] = saida[i];
}


void encoder(char string[300])
{
    int i;
    int aux=strlen(string);
    char temp[5];
    int linha[300];
    char linha2[300];
    strcpy(linha2, "" );
    for (i=0; i<aux; i++)
         linha[i] = string[i];
    for (i=0; i<aux; i++) {
         sprintf (temp, "%d", linha[i]);
         strcat(linha2, temp);
    }
    inverte(linha2);
    printf("%s", linha2);
}


void decoder(char string[300])
{
    int i;
    int tamanho = strlen(string);
    inverte(string);
    for(i = 0; i < tamanho; i+=2) {
         if (string[i] == '1') {
              printf("%c", (100 + (string[i+1] - '0') * 10 + string[i+2] - '0'));
              i++;
         }
         else
              printf("%c", ((string[i]-'0')*10 + string[i+1]-'0'));
    }
}


int main()
{
    char entrada[300];
    while(gets(entrada) != 0)
    {
         if (entrada[0] >= '0' && entrada[0] <= '9')
              decoder (entrada);
         else
              encoder (entrada);
         printf("\n");
    }
    return 0;
}
