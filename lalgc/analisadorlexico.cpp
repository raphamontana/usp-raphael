#include "analisadorlexico.h"

#define ERRO           -1
#define INTEIRO         0
#define REAL            1
#define IDENTIFICADOR   2

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
                    estado = 15;
                }
                else if (token[tokenLen] == ':') {
                }
                else if (token[tokenLen] == '<') {
                }
                else if (token[tokenLen] == '>') {
                }
                else if (token[tokenLen] == ' ') {
                }
                else if (token[tokenLen] == '{') {
                    estado = 26;
                }
                else if (token[tokenLen] == ';') {
                }
                else if (token[tokenLen] == ',') {
                }
                else if (token[tokenLen] == '(') {
                }
                else if (token[tokenLen] == ')') {
                }
                else if (token[tokenLen] == '+') {
                }
                else if (token[tokenLen] == '-') {
                }
                else if (token[tokenLen] == '*') {
                }
                else if (token[tokenLen] == '/') {
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
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                break;
            case 15:
                break;
            case 16:
                break;
            case 17:
                break;
            case 18:
                break;
            case 19:
                break;
            case 20:
                break;
            case 21:
                break;
            case 22:
                break;
            case 23:
                break;
            case 24:
                break;
            case 25:
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
