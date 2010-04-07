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
                    estado = RETORNA_IGUAL;
                }
                else if (token[tokenLen] == ':') {
                    estado = ESTADO_ATRIBUICAO;
                }
                else if (token[tokenLen] == '<') {
                    estado = ESTADO_MENOR;
                }
                else if (token[tokenLen] == '>') {
                    estado = ESTADO_MAIOR;
                }
                else if (token[tokenLen] == ' ') {
                    //estado = 15;
                }
                else if (token[tokenLen] == '{') {
                    estado = ESTADO_COMENTARIO;
                }
                else if (token[tokenLen] == ';') {
                    estado = RETORNA_PONTO_VIRGULA;
                }
                else if (token[tokenLen] == ',') {
                    estado = RETORNA_VIRGULA;
                }

                else if (token[tokenLen] == '(') {
                    estado = RETORNA_ABRE_PARENTESES;
                }
                else if (token[tokenLen] == ')') {
                    estado = RETORNA_FECHA_PARENTESES;
                }
                else if (token[tokenLen] == '+') {
                    estado = RETORNA_MAIS;
                }
                else if (token[tokenLen] == '-') {
                    estado = RETORNA_MENOS;
                }
                else if (token[tokenLen] == '*') {
                    estado = RETORNA_MULTIPLICACAO;
                }
                else if (token[tokenLen] == '/') {
                    estado = RETORNA_DIVISAO;
                }
                else if (token[tokenLen] == EOF) {
                    estado = RETORNA_FIM_ARQUIVO;
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
            case RETORNA_REAL:
                break;
            case ESTADO_LETRA:
                break;
            case RETORNA_IDENTIFICADOR:
                break;
            case ESTADO_MENOR:{
                    if(token[tokenLen] == '=')
                        estado = RETORNA_MENOR_IGUAL;
                    else if(token[tokenLen] == '>')
                        estado = RETORNA_NAO_IGUAL;
                    else estado = RETORNA_MENOR;

                }
                break;
            case RETORNA_MENOR_IGUAL:
                    return LE;
                break;
            case RETORNA_NAO_IGUAL:
                    return NE;
                break;
            case RETORNA_MENOR:{
                    devolveCaractere();
                    return LT;
                }
                break;
            case ESTADO_ATRIBUICAO:
                    if(token[tokenLen] == '=')
                        estado = RETORNA_ATRIBUICAO;
                    else
                        return ERRO;
                break;
            case RETORNA_ATRIBUICAO:
                    return ASSIGN;
                break;
            case ESTADO_MAIOR:
                    if(token[tokenLen] == '=')
                        estado = RETORNA_MAIOR_IGUAL;
                    else estado = RETORNA_MAIOR;

                break;
            case RETORNA_MAIOR_IGUAL:
                    return GE;
                break;
            case RETORNA_MAIOR:{
                    devolveCaractere();
                    return GT;
                }
                break;
            case RETORNA_IGUAL:
                    return EQ;
                break;
            case RETORNA_VIRGULA:
                    return COMMA;
                break;
            case RETORNA_MAIS:
                    return PLUS;
                break;
            case RETORNA_MENOS:
                    return MINUS;
                break;
            case RETORNA_MULTIPLICACAO:
                    return MULT;
                break;
            case RETORNA_DIVISAO:
                    return DIV;
                break;
            case RETORNA_PONTO_VIRGULA:
                    return SMCLN;
                break;
            case RETORNA_ABRE_PARENTESES:
                    return OPENPAR;
                break;
            case RETORNA_FECHA_PARENTESES:
                    return CLOSEPAR;
                break;
            case 26:    return ERRO;
                break;
            case 27:    return ERRO;
                break;
            case 28:    return ERRO;
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
