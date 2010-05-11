#include "analisadorlexico.h"

/**
 * O construtor recebe os enderecos na memoria do arquivo fonte
 * e da tabela de simbolos para inserir os tokens que ele ler.
 */
AnalisadorLexico::AnalisadorLexico(string nomearquivo, vector<Simbolo> * simbolos)
{
    this->tabelaSimbolos = simbolos;
    //Abri o codigo fonte
    fonte = fopen(nomearquivo.data(), "r");
    if (fonte == NULL) {
        string msg = "Erro ao abrir arquivo " + nomearquivo;
        cerr << msg << endl;
        exit(0);
    }
    // Constroi tabela de palavras reservadas
    palavrasReservadas["program"] = "PROGRAM";
    palavrasReservadas["var"] = "VAR";
    palavrasReservadas["begin"] = "BEGIN";
    palavrasReservadas["end"] = "END";
    palavrasReservadas["if"] = "IF";
    palavrasReservadas["then"] = "THEN";
    palavrasReservadas["else"] = "ELSE";
    palavrasReservadas["while"] = "WHILE";
    palavrasReservadas["repeat"] = "REPEAT";
    palavrasReservadas["do"] = "DO";
    palavrasReservadas["until"] = "UNTIL";
    palavrasReservadas["procedure"] = "PROCEDURE";
    palavrasReservadas["integer"] = "INTEGER";
    palavrasReservadas["real"] = "REAL";
    palavrasReservadas["read"] = "READ";
    palavrasReservadas["write"] = "WRITE";
}


AnalisadorLexico::~AnalisadorLexico()
{
    palavrasReservadas.clear();
    fclose(fonte);
}


/**
 * Este eh o metodo que varre o arquivo letra por letra,
 * e identifica os identificadoes, numeros, operadores, entre outros.
 */
Simbolo AnalisadorLexico::obterSimbolo()
{
    Simbolo simbolo;
    int estado = INICIAL;
    int cadeiaLen = -1;
    map<string, string>::iterator it;
    bool achouSimbolo = false;
    while (!achouSimbolo) {
        simbolo.cadeia += proxCaractere();
        cadeiaLen++;
        switch (estado) {
            case INICIAL:
                if (isdigit(simbolo.cadeia.at(cadeiaLen))) {
                    estado = ESTADO_DIGITO;
                }
                else if (isalpha(simbolo.cadeia.at(cadeiaLen))) {
                    estado = ESTADO_LETRA;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == '=') {
                    estado = RETORNA_IGUAL;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == ':') {
                    estado = ESTADO_ATRIBUICAO;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == '<') {
                    estado = ESTADO_MENOR;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == '>') {
                    estado = ESTADO_MAIOR;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == ' ') {
                    simbolo.cadeia.clear();
                    cadeiaLen = -1;
                    estado = INICIAL;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == '\t') {
                    simbolo.cadeia.clear();
                    cadeiaLen = -1;
                    estado = INICIAL;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == '{') {
                    estado = ESTADO_COMENTARIO;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == ';') {
                    estado = RETORNA_PONTO_VIRGULA;
                }
                else if ((simbolo.cadeia.at(cadeiaLen) == '\n') || (simbolo.cadeia.at(cadeiaLen) == '\r')) {
                    simbolo.cadeia.clear();
                    cadeiaLen = -1;
                    estado = INICIAL;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == ',') {
                    estado = RETORNA_VIRGULA;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == '(') {
                    estado = RETORNA_ABRE_PARENTESES;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == ')') {
                    estado = RETORNA_FECHA_PARENTESES;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == '+') {
                    estado = RETORNA_MAIS;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == '-') {
                    estado = RETORNA_MENOS;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == '*') {
                    estado = RETORNA_MULTIPLICACAO;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == '/') {
                    estado = RETORNA_DIVISAO;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == '.') {
                    estado = RETORNA_PONTO;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == EOF) {
                    estado = RETORNA_FIM_ARQUIVO;
                }
                else {
                    estado = RETORNA_ERRO;
                }
                break;
            case ESTADO_DIGITO:
                if (isdigit(simbolo.cadeia.at(cadeiaLen))) {
                    estado = ESTADO_DIGITO;
                }
                else if (simbolo.cadeia.at(cadeiaLen) == '.') {
                    estado = PONTO_DECIMAL;
                }
                else if (simbolo.cadeia.find_first_of(" =<>+-*/;){,") != string::npos) {
                    estado = RETORNA_INTEIRO;
                }
                else {
                    estado = RETORNA_ERRO;
                }
                break;
            case RETORNA_INTEIRO:
                simbolo.cadeia.erase(cadeiaLen-1, 2);
                devolveCaractere(2);
                simbolo.token = "NUM_INTEIRO";
                return(simbolo);
            case PONTO_DECIMAL:
                if (isdigit(simbolo.cadeia[cadeiaLen])) {
                    estado = ESTADO_REAL;
                }
                else {
                    estado = RETORNA_ERRO;
                }
                break;
            case ESTADO_REAL:
                if (isdigit(simbolo.cadeia[cadeiaLen])) {
                    estado = ESTADO_REAL;
                }
                else if (simbolo.cadeia.find_first_of(" =<>+-*/;){,") != string::npos) {
                    estado = RETORNA_REAL;
                }
                else {
                    estado = RETORNA_ERRO;
                }
                break;
            case RETORNA_REAL:
                simbolo.cadeia.erase(cadeiaLen-1, 2);
                devolveCaractere(2);
                simbolo.token = "NUM_REAL";
                return(simbolo);
            case ESTADO_LETRA:
                if (isalpha(simbolo.cadeia[cadeiaLen]) || isdigit(simbolo.cadeia[cadeiaLen])) {
                    estado = ESTADO_LETRA;
                }
                else {
                    estado = RETORNA_IDENTIFICADOR;
                }
                break;
            case RETORNA_IDENTIFICADOR:
                simbolo.cadeia.erase(cadeiaLen-1, 2);
                //Consulta tabela de palavras reservadas e
                //analisa se o identificador contem uma palavra reservada
                it = palavrasReservadas.find(simbolo.cadeia);
                if (it != palavrasReservadas.end()) {
                    simbolo.token = it->second;
                }
                else {
                    simbolo.token = "IDENTIFICADOR";
                }
                devolveCaractere(2);
                return(simbolo);
            case ESTADO_MENOR:
                if (simbolo.cadeia[cadeiaLen] == '=') {
                    estado = RETORNA_MENOR_IGUAL;
                }
                else if (simbolo.cadeia[cadeiaLen] == '>') {
                    estado = RETORNA_NAO_IGUAL;
                }
                else estado = RETORNA_MENOR;
                break;
            case RETORNA_MENOR_IGUAL:
                simbolo.cadeia.erase(cadeiaLen, 1);
                simbolo.token = "LE";
                devolveCaractere(1);
                return(simbolo);
            case RETORNA_NAO_IGUAL:
                simbolo.cadeia.erase(cadeiaLen, 1);
                simbolo.token = "NE";
                devolveCaractere(1);
                return(simbolo);
            case RETORNA_MENOR:
                simbolo.cadeia.erase(cadeiaLen-1, 2);
                simbolo.token = "LT";
                devolveCaractere(2);
                return(simbolo);
            case ESTADO_ATRIBUICAO:
                if (simbolo.cadeia[cadeiaLen] == '=') {
                    estado = RETORNA_ATRIBUICAO;
                }
                else {
                    estado = RETORNA_TIPO_VAR;
                }
                break;
            case RETORNA_TIPO_VAR:
                simbolo.cadeia.erase(cadeiaLen-1, 2);
                simbolo.token = ":";
                devolveCaractere(2);
                return(simbolo);
            case RETORNA_ATRIBUICAO:
                simbolo.cadeia.erase(cadeiaLen, 1);
                simbolo.token = "ASSIGN";
                devolveCaractere(1);
                return(simbolo);
            case ESTADO_MAIOR:
                if (simbolo.cadeia[cadeiaLen] == '=')
                    estado = RETORNA_MAIOR_IGUAL;
                else estado = RETORNA_MAIOR;
                break;
            case RETORNA_MAIOR_IGUAL:
                simbolo.cadeia.erase(cadeiaLen, 3);
                simbolo.token = "GE";
                devolveCaractere(1);
                return(simbolo);
            case RETORNA_MAIOR:
                simbolo.cadeia.erase(cadeiaLen-1, 2);
                simbolo.token = "GT";
                devolveCaractere(2);
                return(simbolo);
            case RETORNA_IGUAL:
                simbolo.token = "EQ";
                return(simbolo);
            case RETORNA_VIRGULA:
                simbolo.cadeia.erase(cadeiaLen, 1);
                devolveCaractere(1);
                simbolo.token = ",";
                return(simbolo);
            case RETORNA_MAIS:
                simbolo.cadeia.erase(cadeiaLen, 1);
                simbolo.token = "PLUS";
                devolveCaractere(1);
                return(simbolo);
            case RETORNA_MENOS:
                simbolo.cadeia.erase(cadeiaLen, 1);
                simbolo.token = "MINUS";
                devolveCaractere(1);
                return(simbolo);
            case RETORNA_MULTIPLICACAO:
                simbolo.cadeia.erase(cadeiaLen, 1);
                simbolo.token = "MULT";
                devolveCaractere(1);
                return(simbolo);
            case RETORNA_DIVISAO:
                simbolo.cadeia.erase(cadeiaLen, 1);
                simbolo.token = "DIV";
                devolveCaractere(1);
                return(simbolo);
            case RETORNA_PONTO_VIRGULA:
                simbolo.cadeia = ";";
                simbolo.token = ";";
                return(simbolo);
            case RETORNA_ABRE_PARENTESES:
                simbolo.cadeia.erase(cadeiaLen, 1);
                simbolo.token = "(";
                devolveCaractere(1);
                return(simbolo);
            case RETORNA_FECHA_PARENTESES:
                simbolo.cadeia.erase(cadeiaLen, 1);
                simbolo.token = ")";
                devolveCaractere(1);
                return(simbolo);
            case ESTADO_COMENTARIO:
                if (simbolo.cadeia[cadeiaLen] == '}') {
                    simbolo.cadeia.clear();
                    cadeiaLen = -1;
                    estado = INICIAL;
                }
                break;
            case RETORNA_PONTO:
                simbolo.cadeia.erase(cadeiaLen, 1);
                simbolo.token = ".";
                return(simbolo);
            case RETORNA_FIM_ARQUIVO:
                simbolo.token = "EOF";
                return(simbolo);
            case RETORNA_ERRO:
                simbolo.cadeia.erase(cadeiaLen, 1);
                simbolo.token = "ERRO";
                devolveCaractere(1);
                return(simbolo);
            default:
                break;
        }
    }
    return(simbolo);
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
 * No caso de ter lido um caractere a mais que nao pertence ao simbolo atual,
 * este metodo recua no arquivo para que o proximo simbolo seja reconhecido corretamente.
 */
void AnalisadorLexico::devolveCaractere(int n)
{
    fseek(fonte, (-1)*n*sizeof(char), SEEK_CUR);
}


/**
 * Caso ocorra um erro no analisador lexico este metodo eh chamado para alertar o programador do erro.
 */
void AnalisadorLexico::emiteErroLexico(int codigo)
{
    fprintf(stderr, "Erro %d na linha %d", codigo, n_linha);
}
