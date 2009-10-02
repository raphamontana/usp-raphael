/*  ========================================================================  */
/*    Raphael Montanari                                    n° USP: 5890010    */
/*  ========================================================================  */

#include <stdio.h>

int main () {
    char entrada;
    int repeticao = 0;
    while ((entrada = getchar()) != EOF) {
        if (entrada == '!') {
            printf ("\n");
            repeticao = 0;
        }
        else if (entrada == 'b') {
            while (repeticao-- > 0)
                printf (" ");
            repeticao = 0 ;
        }
        else if (entrada == '*' || (entrada >= 'A' && entrada <= 'Z')) {
            while (repeticao-- > 0)
                printf ("%c", entrada);
            repeticao = 0;
        }
        else if (entrada == '\n') {
            printf ("\n");
            repeticao = 0;
        }
        else
            repeticao += entrada - '0';
    }
    return (0);
}
