#ifndef ANALISADORLEXICO_H
#define ANALISADORLEXICO_H

#include <stdio.h>
#include <map>

using namespace std;

typedef struct {
    char *buffer;
    char *inicio;
    char *final;
} Entrada;

class AnalisadorLexico
{
public:
    AnalisadorLexico(FILE * fonte, multimap<char *, char *> *tabelaSimbolos);

    int proxToken();

private:
    char proxCaractere();

    int ehDigito(char c);

    int ehLetra(char c);

    Entrada * retornaLexema();

    void devolveCaractere();

    void emitirToken(int, char);

    void emiteErroLexico(int codigo);

    FILE * fonte;

    multimap<char *, char *> *tabelaSimbolos;

    int n_linha;
};

#endif // ANALISADORLEXICO_H
