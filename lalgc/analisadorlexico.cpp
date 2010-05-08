#include "analisadorlexico.h"

/**
 * @todo guardar o numero de linhas (para avisar de eventuais erros)
*/

/**
 * O construtor recebe os enderecos na memoria do arquivo fonte
 * e da tabela de simbolos para inserir os tokens que ele ler.
 */
AnalisadorLexico::AnalisadorLexico(char * nomearquivo)
{
    fonte = fopen(nomearquivo, "r");
    if (fonte == NULL) {
        char msg[1024];
        sprintf(msg, "Erro ao abrir arquivo %s", nomearquivo);
        perror(msg);
        exit(0);
    }
    constroiTabelaPalavrasReservadas();
}


AnalisadorLexico::~AnalisadorLexico()
{
    tabelaSimbolos->clear();
    fclose(fonte);
}


void AnalisadorLexico::constroiTabelaPalavrasReservadas()
{
    this->tabelaSimbolos = new multimap<string, string>();
}


/**
 * Este eh o metodo que varre o arquivo letra por letra,
 * e identifica os identificadoes, numeros, operadores, entre outros.
 */
Token AnalisadorLexico::obterToken()
{
    int estado = INICIAL;
    Token token;
    int tokenLen = -1;
    while (true) {
        token.cadeia[++tokenLen] = proxCaractere();
        switch (estado) {
            case INICIAL:
                if (isdigit(token.cadeia[tokenLen])) {
                    estado = ESTADO_DIGITO;
                }
                else if (isalpha(token.cadeia[tokenLen])) {
                    estado = ESTADO_LETRA;
                }
                else if (token.cadeia[tokenLen] == '=') {
                    estado = RETORNA_IGUAL;
                }
                else if (token.cadeia[tokenLen] == ':') {
                    estado = ESTADO_ATRIBUICAO;
                }
                else if (token.cadeia[tokenLen] == '<') {
                    estado = ESTADO_MENOR;
                }
                else if (token.cadeia[tokenLen] == '>') {
                    estado = ESTADO_MAIOR;
                }
                else if (token.cadeia[tokenLen] == ' ') {
                    tokenLen = -1;
                    estado = INICIAL;
                }
                else if (token.cadeia[tokenLen] == '{') {
                    estado = ESTADO_COMENTARIO;
                }
                else if (token.cadeia[tokenLen] == ';') {
                    estado = RETORNA_PONTO_VIRGULA;
                }
                else if ((token.cadeia[tokenLen] == '\n') || (token.cadeia[tokenLen] == '\r')) {
                    tokenLen = -1;
                    estado = INICIAL;
                }
                else if (token.cadeia[tokenLen] == ',') {
                    estado = RETORNA_VIRGULA;
                }
                else if (token.cadeia[tokenLen] == '(') {
                    estado = RETORNA_ABRE_PARENTESES;
                }
                else if (token.cadeia[tokenLen] == ')') {
                    estado = RETORNA_FECHA_PARENTESES;
                }
                else if (token.cadeia[tokenLen] == '+') {
                    estado = RETORNA_MAIS;
                }
                else if (token.cadeia[tokenLen] == '-') {
                    estado = RETORNA_MENOS;
                }
                else if (token.cadeia[tokenLen] == '*') {
                    estado = RETORNA_MULTIPLICACAO;
                }
                else if (token.cadeia[tokenLen] == '/') {
                    estado = RETORNA_DIVISAO;
                }
                else if (token.cadeia[tokenLen] == '.') {
                    estado = RETORNA_PONTO;
                }
                else if (token.cadeia[tokenLen] == EOF) {
                    estado = RETORNA_FIM_ARQUIVO;
                }
                else {
                    estado = RETORNA_ERRO;
                }
                break;
            case ESTADO_DIGITO:
                if (isdigit(token.cadeia[tokenLen])) {
                    estado = ESTADO_DIGITO;
                }
                else if (token.cadeia[tokenLen] == '.') {
                    estado = PONTO_DECIMAL;
                }
                else {
                    estado = RETORNA_INTEIRO;
                }
                break;
            case RETORNA_INTEIRO:
                token.cadeia[tokenLen-1] = '\0';
                devolveCaractere(2);
                strcpy(token.tipo, "NUM_INTEIRO");
                return(token);
            case PONTO_DECIMAL:
                if (isdigit(token.cadeia[tokenLen])) {
                    estado = ESTADO_REAL;
                }
                else {
                    estado = RETORNA_ERRO;
                }
                break;
            case ESTADO_REAL:
                if (isdigit(token.cadeia[tokenLen])) {
                    estado = ESTADO_REAL;
                }
                else {
                    estado = RETORNA_REAL;
                }
                break;
            case RETORNA_REAL:
                token.cadeia[tokenLen-1] = '\0';
                devolveCaractere(2);
                strcpy(token.tipo, "NUM_REAL");
                return(token);
            case ESTADO_LETRA:
                if (isalpha(token.cadeia[tokenLen]) || isdigit(token.cadeia[tokenLen])) {
                    estado = ESTADO_LETRA;
                }
                else {
                    estado = RETORNA_IDENTIFICADOR;
                }
                break;
            case RETORNA_IDENTIFICADOR:
                token.cadeia[tokenLen-1] = '\0';
                strcpy(token.tipo, "IDENTIFICADOR");
                emitirToken(&token);
                devolveCaractere(2);
                return(token);
            case ESTADO_MENOR:
                if (token.cadeia[tokenLen] == '=') {
                    estado = RETORNA_MENOR_IGUAL;
                }
                else if (token.cadeia[tokenLen] == '>') {
                    estado = RETORNA_NAO_IGUAL;
                }
                else estado = RETORNA_MENOR;
                break;
            case RETORNA_MENOR_IGUAL:
                token.cadeia[tokenLen] = '\0';
                strcpy(token.tipo, "LE");
                return(token);
            case RETORNA_NAO_IGUAL:
                token.cadeia[tokenLen] = '\0';
                strcpy(token.tipo, "NE");
                return(token);
            case RETORNA_MENOR:
                devolveCaractere(2);
                token.cadeia[tokenLen-1] = '\0';
                strcpy(token.tipo, "LT");
                return(token);
            case ESTADO_ATRIBUICAO:
                if (token.cadeia[tokenLen] == '=') {
                    estado = RETORNA_ATRIBUICAO;
                }
                else {
                    estado = RETORNA_TIPO_VAR;
                }
                break;
            case RETORNA_TIPO_VAR:
                devolveCaractere(2);
                token.cadeia[tokenLen-1] = '\0';
                strcpy(token.tipo, ":");
                return(token);
            case RETORNA_ATRIBUICAO:
                devolveCaractere(1);
                token.cadeia[tokenLen] = '\0';
                strcpy(token.tipo, "ASSIGN");
                return(token);
            case ESTADO_MAIOR:
                if (token.cadeia[tokenLen] == '=')
                    estado = RETORNA_MAIOR_IGUAL;
                else estado = RETORNA_MAIOR;
                break;
            case RETORNA_MAIOR_IGUAL:
                strcpy(token.tipo, "GE");
                return(token);
            case RETORNA_MAIOR:
                devolveCaractere(2);
                token.cadeia[tokenLen-1] = '\0';
                strcpy(token.tipo, "GT");
                return(token);
            case RETORNA_IGUAL:
                strcpy(token.tipo, "EQ");
                return(token);
            case RETORNA_VIRGULA:
                token.cadeia[tokenLen] = '\0';
                devolveCaractere(1);
                strcpy(token.tipo, ",");
                return(token);
            case RETORNA_MAIS:
                devolveCaractere(1);
                token.cadeia[tokenLen] = '\0';
                strcpy(token.tipo, "PLUS");
                return(token);
            case RETORNA_MENOS:
                devolveCaractere(1);
                token.cadeia[tokenLen] = '\0';
                strcpy(token.tipo, "MINUS");
                return(token);
            case RETORNA_MULTIPLICACAO:
                devolveCaractere(1);
                token.cadeia[tokenLen] = '\0';
                strcpy(token.tipo, "MULT");
                return(token);
            case RETORNA_DIVISAO:
                devolveCaractere(1);
                token.cadeia[tokenLen] = '\0';
                strcpy(token.tipo, "DIV");
                return(token);
            case RETORNA_PONTO_VIRGULA:
                strcpy(token.tipo, ";");
                token.cadeia[tokenLen] = '\0';
                return(token);
            case RETORNA_ABRE_PARENTESES:
                token.cadeia[tokenLen] = '\0';
                devolveCaractere(1);
                strcpy(token.tipo, "(");
                return(token);
            case RETORNA_FECHA_PARENTESES:
                token.cadeia[tokenLen] = '\0';
                devolveCaractere(1);
                strcpy(token.tipo, ")");
                return(token);
            case ESTADO_COMENTARIO:
                if (token.cadeia[tokenLen] == '}') {
                    tokenLen = -1;
                    estado = INICIAL;
                }
                break;
            case RETORNA_PONTO:
                token.cadeia[tokenLen] = '\0';
                strcpy(token.tipo, ".");
                return(token);
            case RETORNA_FIM_ARQUIVO:
                strcpy(token.tipo, "EOF");
                return(token);
            case RETORNA_ERRO:
                strcpy(token.tipo, "ERRO");
                devolveCaractere(1);
                token.cadeia[tokenLen] = '\0';
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
    if (!strcmp(token->cadeia, "program")) {
        strcpy(token->tipo, "program");
    }
    else if (!strcmp(token->cadeia, "var")) {
        strcpy(token->tipo, "var");
    }
    else if (!strcmp(token->cadeia, "begin")) {
        strcpy(token->tipo, "begin");
    }
    else if (!strcmp(token->cadeia, "end")) {
        strcpy(token->tipo, "end");
    }
    else if (!strcmp(token->cadeia, "if")) {
        strcpy(token->tipo, "if");
    }
    else if (!strcmp(token->cadeia, "then")) {
        strcpy(token->tipo, "then");
    }
    else if (!strcmp(token->cadeia, "else")) {
        strcpy(token->tipo, "else");
    }
    else if (!strcmp(token->cadeia, "while")) {
        strcpy(token->tipo, "while");
    }
    else if (!strcmp(token->cadeia, "repeat")) {
        strcpy(token->tipo, "repeat");
    }
    else if (!strcmp(token->cadeia, "do")) {
        strcpy(token->tipo, "do");
    }
    else if (!strcmp(token->cadeia, "until")) {
        strcpy(token->tipo, "until");
    }
    else if (!strcmp(token->cadeia, "procedure")) {
        strcpy(token->tipo, "procedure");
    }
    else if (!strcmp(token->cadeia, "integer")) {
        strcpy(token->tipo, "integer");
    }
    else if (!strcmp(token->cadeia, "real")) {
        strcpy(token->tipo, "real");
    }
    else if (!strcmp(token->tipo, "EOF")) {
        return;
    }
    //tabelaSimbolos->insert(pair<string, string> (token->cadeia, token->tipo));
    //cout << token->cadeia << " - " << token->tipo << endl;
}


/**
 * Caso ocorra um erro no analisador lexico este metodo eh chamado para alertar o programador do erro.
 */
void AnalisadorLexico::emiteErroLexico(int codigo)
{
    fprintf(stderr, "Erro %d na linha %d", codigo, n_linha);
}
