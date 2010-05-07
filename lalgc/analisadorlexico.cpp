#include "analisadorlexico.h"

/**
 * O construtor recebe os enderecos na memoria do arquivo fonte
 * e da tabela de simbolos para inserir os tokens que ele ler.
 */
AnalisadorLexico::AnalisadorLexico(FILE * fonte, multimap<string, string> *tabelaSimbolos)
{
    this->fonte = fonte;
    this->tabelaSimbolos = tabelaSimbolos;
}

/**
 * Este eh o metodo que varre o arquivo letra por letra,
 * e identifica os identificadoes, numeros, operadores, entre outros.
 */
Token AnalisadorLexico::proxToken()
{
    int estado = INICIAL;
    Token token;
    int tokenLen = -1;
    while (true) {
        token.simbolo[++tokenLen] = proxCaractere();
        switch (estado) {
            case INICIAL:
                if (ehDigito(token.simbolo[tokenLen])) {
                    estado = ESTADO_DIGITO;
                }
                else if (ehLetra(token.simbolo[tokenLen])) {
                    estado = ESTADO_LETRA;
                }
                else if (token.simbolo[tokenLen] == '=') {
                    estado = RETORNA_IGUAL;
                }
                else if (token.simbolo[tokenLen] == ':') {
                    estado = ESTADO_ATRIBUICAO;
                }
                else if (token.simbolo[tokenLen] == '<') {
                    estado = ESTADO_MENOR;
                }
                else if (token.simbolo[tokenLen] == '>') {
                    estado = ESTADO_MAIOR;
                }
                else if (token.simbolo[tokenLen] == ' ') {
                    tokenLen = -1;
                    estado = INICIAL;
                }
                else if (token.simbolo[tokenLen] == '{') {
                    estado = ESTADO_COMENTARIO;
                }
                else if (token.simbolo[tokenLen] == ';') {
                    estado = RETORNA_PONTO_VIRGULA;
                }
                else if ((token.simbolo[tokenLen] == '\n') || (token.simbolo[tokenLen] == '\r')) {
                    tokenLen = -1;
                    estado = INICIAL;
                }
                else if (token.simbolo[tokenLen] == ',') {
                    estado = RETORNA_VIRGULA;
                }
                else if (token.simbolo[tokenLen] == '(') {
                    estado = RETORNA_ABRE_PARENTESES;
                }
                else if (token.simbolo[tokenLen] == ')') {
                    estado = RETORNA_FECHA_PARENTESES;
                }
                else if (token.simbolo[tokenLen] == '+') {
                    estado = RETORNA_MAIS;
                }
                else if (token.simbolo[tokenLen] == '-') {
                    estado = RETORNA_MENOS;
                }
                else if (token.simbolo[tokenLen] == '*') {
                    estado = RETORNA_MULTIPLICACAO;
                }
                else if (token.simbolo[tokenLen] == '/') {
                    estado = RETORNA_DIVISAO;
                }
                else if (token.simbolo[tokenLen] == '.') {
                    estado = RETORNA_PONTO;
                }
                else if (token.simbolo[tokenLen] == EOF) {
                    estado = RETORNA_FIM_ARQUIVO;
                }
                else {
                    estado = RETORNA_ERRO;
                }
                break;
            case ESTADO_DIGITO:
                if (ehDigito(token.simbolo[tokenLen])) {
                    estado = ESTADO_DIGITO;
                }
                else if (token.simbolo[tokenLen] == '.') {
                    estado = PONTO_DECIMAL;
                }
                else {
                    estado = RETORNA_INTEIRO;
                }
                break;
            case RETORNA_INTEIRO:
                token.simbolo[tokenLen-1] = '\0';
                devolveCaractere(2);
                strcpy(token.tipo, "NUM_INTEIRO");
                return(token);
            case PONTO_DECIMAL:
                if (ehDigito(token.simbolo[tokenLen])) {
                    estado = ESTADO_REAL;
                }
                else {
                    estado = RETORNA_ERRO;
                }
                break;
            case ESTADO_REAL:
                if (ehDigito(token.simbolo[tokenLen])) {
                    estado = ESTADO_REAL;
                }
                else {
                    estado = RETORNA_REAL;
                }
                break;
            case RETORNA_REAL:
                token.simbolo[tokenLen-1] = '\0';
                devolveCaractere(2);
                strcpy(token.tipo, "NUM_REAL");
                return(token);
            case ESTADO_LETRA:
                if (ehLetra(token.simbolo[tokenLen]) || ehDigito(token.simbolo[tokenLen])) {
                    estado = ESTADO_LETRA;
                }
                else {
                    estado = RETORNA_IDENTIFICADOR;
                }
                break;
            case RETORNA_IDENTIFICADOR:
                strcpy(token.tipo, "IDENTIFICADOR");
                token.simbolo[tokenLen-1] = '\0';
                devolveCaractere(2);
                return(token);
            case ESTADO_MENOR:
                if (token.simbolo[tokenLen] == '=') {
                    estado = RETORNA_MENOR_IGUAL;
                }
                else if (token.simbolo[tokenLen] == '>') {
                    estado = RETORNA_NAO_IGUAL;
                }
                else estado = RETORNA_MENOR;
                break;
            case RETORNA_MENOR_IGUAL:
                token.simbolo[tokenLen] = '\0';
                strcpy(token.tipo, "LE");
                return(token);
            case RETORNA_NAO_IGUAL:
                token.simbolo[tokenLen] = '\0';
                strcpy(token.tipo, "NE");
                return(token);
            case RETORNA_MENOR:
                devolveCaractere(2);
                token.simbolo[tokenLen-1] = '\0';
                strcpy(token.tipo, "LT");
                return(token);
            case ESTADO_ATRIBUICAO:
                if (token.simbolo[tokenLen] == '=') {
                    estado = RETORNA_ATRIBUICAO;
                }
                else {
                    estado = RETORNA_TIPO_VAR;
                }
                break;
            case RETORNA_TIPO_VAR:
                devolveCaractere(2);
                token.simbolo[tokenLen-1] = '\0';
                strcpy(token.tipo, ":");
                return(token);
            case RETORNA_ATRIBUICAO:
                devolveCaractere(1);
                token.simbolo[tokenLen] = '\0';
                strcpy(token.tipo, "ASSIGN");
                return(token);
            case ESTADO_MAIOR:
                if (token.simbolo[tokenLen] == '=')
                    estado = RETORNA_MAIOR_IGUAL;
                else estado = RETORNA_MAIOR;
                break;
            case RETORNA_MAIOR_IGUAL:
                strcpy(token.tipo, "GE");
                return(token);
            case RETORNA_MAIOR:
                devolveCaractere(2);
                token.simbolo[tokenLen-1] = '\0';
                strcpy(token.tipo, "GT");
                return(token);
            case RETORNA_IGUAL:
                strcpy(token.tipo, "EQ");
                return(token);
            case RETORNA_VIRGULA:
                token.simbolo[tokenLen] = '\0';
                devolveCaractere(1);
                strcpy(token.tipo, ",");
                return(token);
            case RETORNA_MAIS:
                devolveCaractere(1);
                token.simbolo[tokenLen] = '\0';
                strcpy(token.tipo, "PLUS");
                return(token);
            case RETORNA_MENOS:
                devolveCaractere(1);
                token.simbolo[tokenLen] = '\0';
                strcpy(token.tipo, "MINUS");
                return(token);
            case RETORNA_MULTIPLICACAO:
                strcpy(token.tipo, "MULT");
                return(token);
            case RETORNA_DIVISAO:
                strcpy(token.tipo, "DIV");
                return(token);
            case RETORNA_PONTO_VIRGULA:
                strcpy(token.tipo, ";");
                token.simbolo[tokenLen] = '\0';
                return(token);
            case RETORNA_ABRE_PARENTESES:
                token.simbolo[tokenLen] = '\0';
                devolveCaractere(1);
                strcpy(token.tipo, "(");
                return(token);
            case RETORNA_FECHA_PARENTESES:
                token.simbolo[tokenLen] = '\0';
                devolveCaractere(1);
                strcpy(token.tipo, ")");
                return(token);
            case ESTADO_COMENTARIO:
                if (token.simbolo[tokenLen] == '}') {
                    tokenLen = -1;
                    estado = INICIAL;
                }
                break;
            case RETORNA_PONTO:
                token.simbolo[tokenLen] = '\0';
                strcpy(token.tipo, ".");
                return(token);
            case RETORNA_FIM_ARQUIVO:
                strcpy(token.tipo, "EOF");
                return(token);
            case RETORNA_ERRO:
                strcpy(token.tipo, "ERRO");
                devolveCaractere(1);
                token.simbolo[tokenLen] = '\0';
                return(token);
            default:
                break;
        }
    }
    return(token);
}

/**
 * Metodo para receber um novo caractere do arquivo.
 */
char AnalisadorLexico::proxCaractere()
{
    char c = fgetc(fonte);
    return(c);
}

/**
 * Verifica se o caractere eh um digito de um numero.
 */
int AnalisadorLexico::ehDigito(char c)
{
    return((c > 47) && (c < 58));
}

/**
 * Verifica se o caractere recebido eh uma letra maiuscula entre A e Z ou minuscula entre a e z.
 */
int AnalisadorLexico::ehLetra(char c)
{
    return(((c > 64) && (c < 91)) || ((c > 96) && (c < 123)));
}

/**
 * No caso de ter lido um caractere a mais que nao pertence ao token atual,
 * este metodo recua no arquivo para que o proximo token seja reconhecido corretamente.
 */
void AnalisadorLexico::devolveCaractere(int n)
{
    fseek(fonte, (-1)*n*sizeof(char), SEEK_CUR);
}

/**
 * A principal funcao deste metodo eh separar as palavras reservadas dos identificadores
 * e inserir os tokens na tabela hash de simbolos.
 */
void AnalisadorLexico::emitirToken(Token * token)
{
    //Analisa se algum identificador contem uma palavra reservada
    if (!strcmp(token->simbolo, "program")) {
        strcpy(token->tipo, "program");
    }
    else if (!strcmp(token->simbolo, "var")) {
        strcpy(token->tipo, "var");
    }
    else if (!strcmp(token->simbolo, "begin")) {
        strcpy(token->tipo, "begin");
    }
    else if (!strcmp(token->simbolo, "end")) {
        strcpy(token->tipo, "end");
    }
    else if (!strcmp(token->simbolo, "if")) {
        strcpy(token->tipo, "if");
    }
    else if (!strcmp(token->simbolo, "then")) {
        strcpy(token->tipo, "then");
    }
    else if (!strcmp(token->simbolo, "else")) {
        strcpy(token->tipo, "else");
    }
    else if (!strcmp(token->simbolo, "while")) {
        strcpy(token->tipo, "while");
    }
    else if (!strcmp(token->simbolo, "repeat")) {
        strcpy(token->tipo, "repeat");
    }
    else if (!strcmp(token->simbolo, "do")) {
        strcpy(token->tipo, "do");
    }
    else if (!strcmp(token->simbolo, "until")) {
        strcpy(token->tipo, "until");
    }
    else if (!strcmp(token->simbolo, "procedure")) {
        strcpy(token->tipo, "procedure");
    }
    else if (!strcmp(token->simbolo, "integer")) {
        strcpy(token->tipo, "integer");
    }
    else if (!strcmp(token->simbolo, "real")) {
        strcpy(token->tipo, "real");
    }
    else if (!strcmp(token->tipo, "EOF")) {
        return;
    }
    tabelaSimbolos->insert(pair<string, string> (token->simbolo, token->tipo));
    cout << token->simbolo << " - " << token->tipo << endl;
}

/**
 * Caso ocorra um erro no analisador lexico este metodo eh chamado para alertar o programador do erro.
 */
void AnalisadorLexico::emiteErroLexico(int codigo)
{
    fprintf(stderr, "Erro %d na linha %d", codigo, n_linha);
}
