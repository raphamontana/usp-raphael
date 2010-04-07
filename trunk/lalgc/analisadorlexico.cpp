#include "analisadorlexico.h"

AnalisadorLexico::AnalisadorLexico(FILE * fonte, multimap<char *, char *> *tabelaSimbolos)
{
    this->fonte = fonte;
    this->tabelaSimbolos = tabelaSimbolos;
}

int AnalisadorLexico::proxToken()
{
    int estado = INICIAL;
    char token[102];
    int tokenLen = -1;
    while (true) {
        token[++tokenLen] = proxCaractere();
        switch (estado) {
            case INICIAL:
                if (ehDigito(token[tokenLen])) {
                    estado = ESTADO_DIGITO;
                }
                if (ehLetra(token[tokenLen])) {
                    estado = ESTADO_LETRA;
                }
                else if (token[tokenLen] == '=') {
                    estado = 17;
                }
                else if (token[tokenLen] == ':') {
                    estado = 15;
                }
                else if (token[tokenLen] == '<') {
                    estado = 8;
                }
                else if (token[tokenLen] == '>') {
                    estado = 15;
                }
                else if (token[tokenLen] == ' ') {
                    estado = 15;
                }
                else if (token[tokenLen] == '{') {
                    estado = 26;
                }
                else if (token[tokenLen] == ';') {
                    estado = 15;
                }
                else if (token[tokenLen] == ',') {
                    estado = 18;
                }

                else if (token[tokenLen] == '(') {
                    estado = 15;
                }
                else if (token[tokenLen] == ')') {
                    estado = 25;
                }
                else if (token[tokenLen] == '+') {
                    estado = 15;
                }
                else if (token[tokenLen] == '-') {
                    estado = 15;
                }
                else if (token[tokenLen] == '*') {
                    estado = 15;
                }
                else if (token[tokenLen] == '/') {
                    estado = 22;
                }
                else if (token[tokenLen] == EOF) {
                    estado = 15;
                }
                else return(ERRO);
                break;
            case ESTADO_DIGITO:
                if (ehDigito(token[tokenLen])) {
                    estado = ESTADO_DIGITO;
                }
                else if (token[tokenLen] == '.') {
                    estado = PONTO_DECIMAL;
                }
                else {
                    estado = RETORNA_INTEIRO;
                }
                break;
            case RETORNA_INTEIRO:
                token[tokenLen] = '\0';
                devolveCaractere();
                return(INTEIRO);
            case PONTO_DECIMAL:
                if (ehDigito(token[tokenLen])) {
                    estado = RETORNA_REAL;
                }
                else {
                    estado = RETORNA_ERRO;
                }

                break;
            case ESTADO_REAL:
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

Token * AnalisadorLexico::retornaLexema()
{
    return(NULL);
}

void AnalisadorLexico::devolveCaractere()
{
    fseek(fonte, (-1)*sizeof(char), SEEK_CUR);
}

void AnalisadorLexico::emitirToken(int, char)
{
}

void AnalisadorLexico::emiteErroLexico(int codigo)
{
    fprintf(stderr, "Erro %d na linha %d", codigo, n_linha);
}
