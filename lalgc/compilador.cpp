#include "compilador.h"

/**
 * Abre o arquivo fonte, e inicia a leitura do mesmo
 * usando o Analisador Lexico para obter os tokens.
 * Os tokens sao armazenados em uma tabela Hash para facilitar a busca dos elementos
 * A tabela Hash foi implementada usando a classe multimap,
 * assim é possivel fazer buscas em tempo logaritmo
 */
Compilador::Compilador(char * nomearquivo)
{
    tabelaSimbolos = new vector<Simbolo>();
    aLex = new AnalisadorLexico(nomearquivo, tabelaSimbolos);
    aSin = new AnalisadorSintatico(aLex);
    testarLexico();
    //aSin->asd();
    delete(aSin);
    delete(aLex);
}


Compilador::~Compilador()
{
    tabelaSimbolos->clear();
    delete(tabelaSimbolos);
}


void Compilador::testarLexico()
{
    Simbolo simbolo = aLex->obterSimbolo();
    cout << simbolo.cadeia << " # " << simbolo.token << endl;
    while (simbolo.token != "EOF") {
        simbolo = aLex->obterSimbolo();
        cout << simbolo.cadeia << " # " << simbolo.token<<endl;
    }
}
