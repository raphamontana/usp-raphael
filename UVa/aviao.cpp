/*  Raphael Montanari          nº USP: 5890010  */
/*  Avião  */


#include <stdio.h>
#include <stdlib.h>


int main()
{
    int nFileiras, nAssentos, pFila, pEmbarque;
    int i, j;
    int disponiveis;
    scanf("%d %d %d %d", &nFileiras, &nAssentos, &pFila, &pEmbarque);
    disponiveis = (nFileiras - pFila) * nAssentos;  
    if (pEmbarque > disponiveis)
         printf("PROXIMO VOO");
    else
    {
         i = pFila;
         j = 0;
         while (nAssentos < pEmbarque)
         {
              pEmbarque -= nAssentos;
              i++; 
         }
         while (pEmbarque > 0)
         {
              pEmbarque--;
              j++;
         }
         j--;
         printf("%d %c", i, (j + 'A'));
    } 
    return (0);
}
