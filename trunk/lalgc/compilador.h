#ifndef COMPILADOR_H
#define COMPILADOR_H

#include "analisadorlexico.h"
#include "analisadorsintatico.h"
#include "analisadorsemantico.h"

class Compilador
{
public:
    Compilador(char * nomearquivo);

private:
    AnalisadorLexico * aLex;

    AnalisadorSintatico * aSin;

    AnalisadorSemantico * aSem;

    multimap<string, string> tabelaSimbolos;

    FILE * fonte;
};

#endif // COMPILADOR_H
