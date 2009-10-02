/*  ========================================================================  */
/*  Raphael Montanari                                        Nº USP: 5890010  */
/*  ========================================================================  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void ZeraSaida (char saida [192] [112]) {
     int i, j;
     for (i = 0; i < 192; i++)
          for (j = 0; j < 112; j++)
               saida [i][j] = ' ';
}


void Imprime (char saida [192] [112], int tamanho, int ndigitos) {
     int i, j;
     int UltimaLinha = (2 * tamanho) + 3;
     int UltimaColuna = ((tamanho + 3) * ndigitos) - 1;
     for (i = 0; i < UltimaLinha; i++) {
          for (j = 0; j < UltimaColuna; j++){
               printf ("%c", saida [i] [j]);
               }
          printf ("\n");
     }
     printf ("\n");
}


void InsereDigito (char saida [192] [112], int tamanho, char digito, int posicao) {
     int i, j;
     int PrimeiraLinha = 0;
     int LinhaMeio = tamanho + 1;
     int UltimaLinha = (2 * tamanho) + 2;
     int PrimeiraColuna = posicao;
     int UltimaColuna = posicao + tamanho + 1;
     switch (digito) {
         case '0': {
              for (j = (PrimeiraColuna + 1); j < UltimaColuna; j++) {
                   saida [PrimeiraLinha] [j] = '-';
                   saida [UltimaLinha] [j] = '-';
              }
              for (i = (PrimeiraLinha + 1); i < (LinhaMeio); i++) {
                   saida [i] [PrimeiraColuna] = '|';
                   saida [i] [UltimaColuna] = '|';
              }
              for (i = (LinhaMeio + 1); i < (UltimaLinha); i++) {
                   saida [i] [PrimeiraColuna] = '|';
                   saida [i] [UltimaColuna] = '|';
              }
              break;
         }
         case '1': {
              for (i = (PrimeiraLinha + 1); i < LinhaMeio; i++)
                   saida [i] [UltimaColuna] = '|';
              for (i = (LinhaMeio + 1); i < UltimaLinha; i++)
                   saida [i] [UltimaColuna] = '|';
              break;
         }
         case '2': {
              for (i = (PrimeiraLinha + 1); i < LinhaMeio; i++)
                   saida [i] [UltimaColuna] = '|';
              for (i = (LinhaMeio + 1); i < UltimaLinha; i++)
                   saida [i] [PrimeiraColuna] = '|';
              for (j = (PrimeiraColuna + 1); j < (UltimaColuna); j++) {
                   saida [PrimeiraLinha] [j] = '-';
                   saida [LinhaMeio] [j] = '-';
                   saida [UltimaLinha] [j] = '-';
              }
              break;
         }
         case '3': {
              for (j = (PrimeiraColuna + 1); j < (UltimaColuna); j++) {
                   saida [PrimeiraLinha] [j] = '-';
                   saida [LinhaMeio] [j] = '-';
                   saida [UltimaLinha] [j] = '-';
              }
              for (i = (PrimeiraLinha + 1); i < (UltimaLinha); i++)
                   saida [i] [UltimaColuna] = '|';
              saida [LinhaMeio] [UltimaColuna] = ' ';
              break;
         }
         case '4': {
              for (j = (PrimeiraColuna + 1); j < (UltimaColuna); j++)
                   saida [LinhaMeio] [j] = '-';
              for (i = (PrimeiraLinha + 1); i < (LinhaMeio); i++) {
                   saida [i] [PrimeiraColuna] = '|';
                   saida [i] [UltimaColuna] = '|';
              }
              for (i = (LinhaMeio + 1); i < (UltimaLinha); i++)
                   saida [i] [UltimaColuna] = '|';
              break;
         }
         case '5': {
              for (j = (PrimeiraColuna + 1); j < (UltimaColuna); j++) {
                   saida [PrimeiraLinha] [j] = '-';
                   saida [LinhaMeio] [j] = '-';
                   saida [UltimaLinha] [j] = '-';
              }
              for (i = (PrimeiraLinha + 1); i < (LinhaMeio); i++)
                   saida [i] [PrimeiraColuna] = '|';
              for (i = (LinhaMeio + 1); i < (UltimaLinha); i++)
                   saida [i] [UltimaColuna] = '|';
              break;
         }
         case '6': {
              for (j = (PrimeiraColuna + 1); j < (UltimaColuna); j++) {
                   saida [PrimeiraLinha] [j] = '-';
                   saida [LinhaMeio] [j] = '-';
                   saida [UltimaLinha] [j] = '-';
              }
              for (i = (PrimeiraLinha + 1); i < (LinhaMeio); i++)
                   saida [i] [PrimeiraColuna] = '|';
              for (i = (LinhaMeio + 1); i < (UltimaLinha); i++) {
                   saida [i] [PrimeiraColuna] = '|';
                   saida [i] [UltimaColuna] = '|';
              }
              break;
         }
         case '7': {
              for (j = (PrimeiraColuna + 1); j < (UltimaColuna); j++)
                   saida [PrimeiraLinha] [j] = '-';
              for (i = (PrimeiraLinha + 1); i < (LinhaMeio); i++)
                   saida [i] [UltimaColuna] = '|';
              for (i = (LinhaMeio + 1); i < (UltimaLinha); i++)
                   saida [i] [UltimaColuna] = '|';
              break;
         }
         case '8': {
              for (j = (PrimeiraColuna + 1); j < (UltimaColuna); j++) {
                   saida [PrimeiraLinha] [j] = '-';
                   saida [LinhaMeio] [j] = '-';
                   saida [UltimaLinha] [j] = '-';
              }
              for (i = (PrimeiraLinha + 1); i < (LinhaMeio); i++) {
                   saida [i] [PrimeiraColuna] = '|';
                   saida [i] [UltimaColuna] = '|';
              }
              for (i = (LinhaMeio + 1); i < (UltimaLinha); i++) {
                   saida [i] [PrimeiraColuna] = '|';
                   saida [i] [UltimaColuna] = '|';
              }
              break;
         }
         case '9': {
              for (j = (PrimeiraColuna + 1); j < (UltimaColuna); j++) {
                   saida [PrimeiraLinha] [j] = '-';
                   saida [LinhaMeio] [j] = '-';
                   saida [UltimaLinha] [j] = '-';
              }
              for (i = (PrimeiraLinha + 1); i < (LinhaMeio); i++) {
                   saida [i] [PrimeiraColuna] = '|';
                   saida [i] [UltimaColuna] = '|';
              }
              for (i = (LinhaMeio + 1); i < (UltimaLinha); i++)
                   saida [i] [UltimaColuna] = '|';
              break;
         }
         default: break;
     }
}


int main (void) {
     int s, n;
     int i, posicao, ndigitos = 0;
     char impressao [192] [112];
     char string [10];
     while (scanf ("%d %s", &s, string ) != EOF) {
          ndigitos = strlen (string);
          if((s == 0) && (string[0] == '0') || (s > 10) || (ndigitos > 8) || (s == 0))
               break;
          ZeraSaida (impressao);
          posicao = 0;
          for (i = 0; i < ndigitos; i++) {
               InsereDigito (impressao, s, string [i], posicao);
               posicao += (s + 3);
          }
          Imprime (impressao, s, ndigitos);
     }
     return (0);
}
