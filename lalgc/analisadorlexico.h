#ifndef ANALISADORLEXICO_H
#define ANALISADORLEXICO_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;


/**
 * Esta enumeracao serve para organizar os estados,
 * eh mais facil referenciar o estado RETORNA_IDENTIFICADOR do que o estado 8. ;)
 */
enum estados {
    INICIAL,
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


/**
 * Estrutura interna para armazenar um simbolo
 * corresponde de duas palavras, uma identifica o simbolo e a outra o significado do simbolo.
 */
typedef struct {
    string cadeia;
    string token;
    string categoria;
    string tipo;
    string valor;
    int nro_param;
    int nro_var_locais;
    int escopo;
} Simbolo;


/**
 * Classe Analisador Lexico
 */
class AnalisadorLexico
{
public:
    AnalisadorLexico(string nomearquivo, vector<Simbolo> * simbolos);

    ~AnalisadorLexico();

    Simbolo obterSimbolo();

private:
    char proxCaractere();

    void devolveCaractere(int n);

    void emiteErroLexico(string msg);

    FILE * fonte;

    vector<Simbolo> * tabelaSimbolos;

    map<string, string> palavrasReservadas;

    int n_linha;
};

#endif // ANALISADORLEXICO_H
