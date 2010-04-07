#include "analisadorlexico.h"

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

enum estados{INICIAL, ESTADO_DIGITO, RETORNA_INTEIRO, PONTO_DECIMAL, ESTADO_REAL, RETORNA_REAL};

AnalisadorLexico::AnalisadorLexico(FILE * fonte, multimap<char *, char *> *tabelaSimbolos)
{
    this->fonte = fonte;
    this->tabelaSimbolos = tabelaSimbolos;
}

int AnalisadorLexico::proxToken()
{
    int estado = INICIAL;
    char token[102];
    int tokenLen = 0;
    token[tokenLen] = proxCaractere();
    while (true) {
        switch (estado) {
            case INICIAL:
                if (ehDigito(token[tokenLen])) {
                    estado = ESTADO_DIGITO;
                }
                if (ehLetra(token[tokenLen])) {
                    estado = 24;
                }
                else if (token[tokenLen] == '=') {
                    estado = 17;
                }
                else if (token[tokenLen] == ':') {
                    estado = 12;
                }
                else if (token[tokenLen] == '<') {
                    estado = 8;
                }
                else if (token[tokenLen] == '>') {
                    estado = 14;
                }
                else if (token[tokenLen] == ' ') {
                }
                else if (token[tokenLen] == '{') {
                    estado = 26;
                }
                else if (token[tokenLen] == ';') {
                    estado = 23;
                }
                else if (token[tokenLen] == ',') {
                    estado = 18;
                }

                else if (token[tokenLen] == '(') {
                    estado = 24;
                }
                else if (token[tokenLen] == ')') {
                    estado = 25;
                }
                else if (token[tokenLen] == '+') {
                    estado = 19;
                }
                else if (token[tokenLen] == '-') {
                    estado = 20;
                }
                else if (token[tokenLen] == '*') {
                    estado = 21;
                }
                else if (token[tokenLen] == '/') {
                    estado = 22;
                }
                else if (token[tokenLen] == EOF) {
                }
                else return(ERRO);
                break;
            case ESTADO_DIGITO:
                token[++tokenLen] = proxCaractere();
                if (ehDigito(token[tokenLen])) {
                }
                else if (token[tokenLen] == '.') {
                    estado = ESTADO_REAL;
                }
                else {
                    token[tokenLen] = '\0';
                    devolveCaractere();
                    return(INTEIRO);//eh inteiro
                }
                break;
            case 2:

                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:{
                    if(token[tokenLen] == '=')
                        estado = 9;
                    else if(token[tokenLen] == '>')
                        estado = 10;
                    else estado = 11;

                }
                break;
            case 9:
                    return LE;
                break;
            case 10:
                    return NE;
                break;
            case 11:{
                    devolveCaractere();
                    return LT;
                }
                break;
            case 12:
                    if(token[tokenLen] == '=')
                        estado = 13;
                    else
                        return ERRO;
                break;
            case 13:
                    return ASSIGN;
                break;
            case 14:
                    if(token[tokenLen] == '=')
                        estado = 15;
                    else estado = 16;

                break;
            case 15:
                    return GE;
                break;
            case 16:{
                    devolveCaractere();
                    return GT;
                }
                break;
            case 17:
                    return EQ;
                break;
            case 18:
                    return COMMA;
                break;
            case 19:
                    return PLUS;
                break;
            case 20:
                    return MINUS;
                break;
            case 21:
                    return MULT;
                break;
            case 22:
                    return DIV;
                break;
            case 23:
                    return SMCLN;
                break;
            case 24:
                    return OPENPAR;
                break;
            case 25:
                    return CLOSEPAR;
                break;
            case 26:
                break;
            case 27:
                break;
            case 28:
                break;
            default:
                break;
        }
    }
    return(0);
}

char AnalisadorLexico::proxCaractere()
{
    char c = fgetc(fonte);
    return(c);
}

int AnalisadorLexico::ehDigito(char c)
{
    return((c > 47) && (c < 58));
}

int AnalisadorLexico::ehLetra(char c)
{
    return(((c > 64) && (c < 91)) || ((c > 96) && (c < 123)));
}

Entrada * AnalisadorLexico::retornaLexema()
{
    return(NULL);
}

void AnalisadorLexico::devolveCaractere()
{
    fseek(fonte, -1, SEEK_CUR);
}

void AnalisadorLexico::emitirToken(int, char)
{
}

void AnalisadorLexico::emiteErroLexico(int codigo)
{
    fprintf(stderr, "Erro %d na linha %d", codigo, n_linha);
}
