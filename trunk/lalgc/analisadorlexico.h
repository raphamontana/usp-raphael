#ifndef ANALISADORLEXICO_H
#define ANALISADORLEXICO_H

#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

#define ERRO           -1
#define INTEIRO         0
#define REAL            1
#define IDENTIFICADOR   2
#define LE              9
#define NE              10
#define LT              11
#define ASSIGN          13
#define GE              15
#define GT              16
#define EQ              17
#define COMMA           18
#define PLUS            19
#define MINUS           20
#define MULT            21
#define DIV             22
#define SMCLN           23
#define OPENPAR         24
#define CLOSEPAR        25

enum estados {INICIAL,
             ESTADO_DIGITO,
             RETORNA_INTEIRO,
             PONTO_DECIMAL,
             ESTADO_REAL,
             RETORNA_REAL,
             ESTADO_LETRA,
             RETORNA_IDENTIFICADOR,
             ESTADO_MENOR,
             RETORNA_MENOR_IGUAL,
             RETORNA_NAO_IGUAL,
             RETORNA_MENOR,
             ESTADO_ATRIBUICAO,
             RETORNA_TIPO_VAR,
             RETORNA_ATRIBUICAO,
             ESTADO_MAIOR,
             RETORNA_MAIOR,
             RETORNA_MAIOR_IGUAL,
             RETORNA_IGUAL,
             RETORNA_VIRGULA,
             RETORNA_MAIS,
             RETORNA_MENOS,
             RETORNA_MULTIPLICACAO,
             RETORNA_DIVISAO,
             RETORNA_PONTO_VIRGULA,
             RETORNA_ABRE_PARENTESES,
             RETORNA_FECHA_PARENTESES,
             ESTADO_COMENTARIO,
             RETORNA_PONTO,
             RETORNA_FIM_ARQUIVO,
             RETORNA_ERRO
            };

typedef struct {
    char simbolo[128];
    char tipo[24];
} Token;

class AnalisadorLexico
{
public:
    AnalisadorLexico(FILE * fonte, multimap<char *, char *> *tabelaSimbolos);

    Token proxToken();

    void emitirToken(Token token);

private:
    char proxCaractere();

    int ehDigito(char c);

    int ehLetra(char c);

    Token * retornaLexema();

    void devolveCaractere(int n);

    void emiteErroLexico(int codigo);

    FILE * fonte;

    multimap<char *, char *> *tabelaSimbolos;

    int n_linha;
};

#endif // ANALISADORLEXICO_H
