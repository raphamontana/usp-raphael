/*  Raphael Montanari 5890010  */
/*  Palindromes  */

#include <cstdio>
#include <map>

using namespace std;


typedef map<char,char> CharMap;


void Fill (CharMap &charMap);


int main()
{
	CharMap charMap;
	Fill (charMap);

	char palavra[21];
	while (scanf("%s", palavra) != EOF)
	{
		int palindrome = 1;
		int mirror = 1;

		int tamanho = strlen(palavra);
		for (int i = 0; i < tamanho/2; i++)
		{
			palindrome &= (palavra[i] == palavra[tamanho-i-1]);
			mirror &= (palavra[i] == charMap[palavra[tamanho-i-1]]);
		}

		if ((tamanho % 2) != 0)
			mirror &= (palavra[tamanho/2] == charMap[palavra[tamanho/2]]);

			if (palindrome && mirror) printf("%s is a mirrored palindrome.\n\n", palavra);
			else if (mirror) printf("%s is a mirrored string.\n\n", palavra);
		   else if (palindrome) printf("%s is a regular palindrome.\n\n", palavra);
		   else printf("%s is not a palindrome.\n\n", palavra);
	}

    return 0;
}


void Fill (CharMap &charMap)
{
	charMap['A'] = 'A';
	charMap['B'] = ' ';
	charMap['C'] = ' ';
	charMap['D'] = ' ';
	charMap['E'] = '3';
	charMap['F'] = ' ';
	charMap['G'] = ' ';
	charMap['H'] = 'H';
	charMap['I'] = 'I';
	charMap['J'] = 'L';
	charMap['K'] = ' ';
	charMap['L'] = 'J';
	charMap['M'] = 'M';
	charMap['N'] = ' ';
	charMap['O'] = 'O';
	charMap['P'] = ' ';
	charMap['Q'] = ' ';
	charMap['R'] = ' ';
	charMap['S'] = '2';
	charMap['T'] = 'T';
	charMap['U'] = 'U';
	charMap['V'] = 'V';
	charMap['W'] = 'W';
	charMap['X'] = 'X';
	charMap['Y'] = 'Y';
	charMap['Z'] = '5';
	charMap['1'] = '1';
	charMap['2'] = 'S';
	charMap['3'] = 'E';
	charMap['4'] = ' ';
	charMap['5'] = 'Z';
	charMap['6'] = ' ';
	charMap['7'] = ' ';
	charMap['8'] = '8';
	charMap['9'] = ' ';
}
