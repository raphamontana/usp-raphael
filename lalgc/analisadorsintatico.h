#ifndef ANALISADORSINTATICO_H
#define ANALISADORSINTATICO_H

/**
 * Define-se o 'saidaLexico' para imprimir os tokens lidos do analisador lexico
 */
#define saidaLexico

#include "analisadorlexico.h"


class AnalisadorSintatico
{
public:
    AnalisadorSintatico(AnalisadorLexico * aLex);
    ~AnalisadorSintatico();
    void asd();

private:
    void programa();
    void corpo();
    void dc();
    void dc_v();
    void tipo_var();
    void variaveis();
    void mais_var();
    void dc_p();
    void parametros();
    void lista_par();
    void mais_par();
    void corpo_p();
    void dc_loc();
    void lista_arg();
    void argumentos();
    void mais_ident();
    void pfalsa();
    void comandos();
    void cmd();
    void ident();
    void condicao();
    void relacao();
    void expressao();
    void op_un();
    void outros_termos();
    void op_ad();
    void termo();
    void mais_fatores();
    void op_mul();
    void fator();
    void erro();
    void imprimirMensagem(string msg);
    void imprimirErro(string msg);

    AnalisadorLexico * aLex;
    Token token;
};

#endif // ANALISADORSINTATICO_H
