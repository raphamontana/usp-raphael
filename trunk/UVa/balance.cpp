/* =========================================================================  */
/*  Raphael Montanari                                        nº USP: 5890010  */
/*  Parentheses Balance                                                       */
/* =========================================================================  */

#include <cstdio>
#include <string.h>
#include <stack>
using namespace std;


int verifica()
{
	stack<char> P;                                   /*  Declaracao de Pilha  */
    char entrada[260];
    int correto = 1;
    int j = 0;
    gets( entrada);
    while (correto && (j < strlen(entrada)))
    {
         if (entrada[j] == ']' && !P.empty())
         {
              if (P.top() != '[')
                   correto = 0;
              else P.pop();
         }
         else if (entrada[j] == ')' && !P.empty())
              {
                   if (P.top() != '(')
                        correto = 0;
                   else P.pop();
              }
              else P.push(entrada[j]);
         j++;
    }
    if (!P.empty())
         correto = 0;
    return (correto);
}


int main()
{
	int N;                                              /*  numero de linhas  */
	int i;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
    {
         if (verifica())
              printf("Yes\n");
         else printf("No\n");
    }
	return 0;
}
