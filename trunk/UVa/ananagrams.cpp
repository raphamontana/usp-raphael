/*  ========================================================================  */
/*  Raphael Montanari                                         nº USP 5890010  */
/*  Ananagrams                                                     UVa 00156  */
/*  ========================================================================  */


#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main()
{
    struct palavra {
         char d[21];
         int c[26];
    } D[1000];

	char t[21];		// temporaria
	scanf("%s", t);
	int i = 0;
	int j, k;
	int indice;
	int tamanho;


	/* lê no dicionario */
	while (strcmp(t, "#") != 0)
    {
		strcpy(D[i].d, t);
		tamanho = strlen(t);
		for (j = 0; j < tamanho; j++)
        {
			indice = (int) (tolower(t[j]) - 'a');
			D[i].c[indice]++;
		}
		i++;
		scanf("%s", t);
  	}

    /* ordena dicionario */
    int temporaria[26];
    int bot = i;
    for (j = 0; j < bot; j++)
         for (k = 0; k < bot-1; k++)
			if (strcmp(D[k].d, D[k+1].d) > 0)
            {
				for (int q = 0; q < 26; q++)
					temporaria[q] = D[k].c[q];
				for (int r = 0; r < 26; r++)
					D[k].c[r] = D[k+1].c[r];
				for (int s = 0; s < 26; s++)
					D[k+1].c[s] = temporaria[s];
				strcpy(t, D[k].d);
				strcpy(D[k].d, D[k+1].d);
				strcpy(D[k+1].d, t);
			}
    int pos;
    int atual;
    int m;
    int imprime;
	for (atual = 0; atual < i; atual++)
    {
         imprime = 0;                                            // imprime
         for (pos = 0; pos < i; pos++)
         {
              if (pos == atual)
                   continue;
              for (m = 0; m < 26; m++)
                   if (D[atual].c[m] != D[pos].c[m])
                        break;
              if (m == 26)
              {                              /* confere, portanto nao imprime */
                   imprime = 1;
                   break;
              }
         }
         if (imprime == 0)
              printf("%s\n", D[atual].d);
    }
    return(0);
}
