#ifndef COMPILADOR_H
#define COMPILADOR_H

#include "analisadorlexico.h"
#include "analisadorsintatico.h"
#include "analisadorsemantico.h"


class Compilador
{
public:
    Compilador(char * nomearquivo);

    ~Compilador();

private:
    void testarLexico();

    vector<Simbolo> * tabelaSimbolos;

    AnalisadorLexico * aLex;

    AnalisadorSintatico * aSin;

    AnalisadorSemantico * aSem;
};

#endif // COMPILADOR_H
