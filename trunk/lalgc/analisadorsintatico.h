#ifndef ANALISADORSINTATICO_H
#define ANALISADORSINTATICO_H

#include "analisadorlexico.h"


class AnalisadorSintatico
{
public:
    AnalisadorSintatico();

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

    AnalisadorLexico al;
};

#endif // ANALISADORSINTATICO_H
