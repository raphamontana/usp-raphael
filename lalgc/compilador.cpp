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
    aLex = new AnalisadorLexico(nomearquivo);
    aSin = new AnalisadorSintatico(aLex);
    aSin->asd();
    delete(aSin);
    delete(aLex);
}

void Compilador::testarLexico()
{
    Token token = aLex->obterToken();
    aLex->emitirToken(&token);
    while (strcmp("EOF", token.tipo)) {
        token = aLex->obterToken();
        aLex->emitirToken(&token);
    }
}
