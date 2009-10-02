/* =========================================================================  */
/*  Raphael Montanari                                        nº USP: 5890010  */
/*  WERTYU                                                                    */
/* =========================================================================  */

#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

int  main (void) {
     map <char, char> m;
// 1° linha
     m['1'] = '`';
     m['2'] = '1';
     m['3'] = '2';
     m['4'] = '3';
     m['5'] = '4';
     m['6'] = '5';
     m['7'] = '6';
     m['8'] = '7';
     m['9'] = '8';
     m['0'] = '9';
     m['-'] = '0';
     m['='] = '-';
// 2° linha
     m['W'] = 'Q';
     m['E'] = 'W';
     m['R'] = 'E';
     m['T'] = 'R';
     m['Y'] = 'T';
     m['U'] = 'Y';
     m['I'] = 'U';
     m['O'] = 'I';
     m['P'] = 'O';
     m['['] = 'P';
     m[']'] = '[';
     m['\\'] = ']';
// 3° linha
     m['S'] = 'A';
     m['D'] = 'S';
     m['F'] = 'D';
     m['G'] = 'F';
     m['H'] = 'G';
     m['J'] = 'H';
     m['K'] = 'J';
     m['L'] = 'K';
     m[';'] = 'L';
     m['\''] = ';';
// 4° linha
     m['X'] = 'Z';
     m['C'] = 'X';
     m['V'] = 'C';
     m['B'] = 'V';
     m['N'] = 'B';
     m['M'] = 'N';
     m[','] = 'M';
     m['.'] = ',';
     m['/'] = '.';
//  casos especiais
     m[' '] = ' ';
     m['\n'] = '\n';

     char linha [1024];
     int i, j, tamanho;
	 while (fgets (linha, 1024, stdin) != 0) {
         tamanho = strlen(linha);
         for (i = 0; i < tamanho; i++)
              printf ("%c", m[linha [i]]);
     }
     return 0;
}
