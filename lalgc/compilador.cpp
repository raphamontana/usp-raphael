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
    fonte = fopen(nomearquivo, "r");
    if (fonte == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    aLex = new AnalisadorLexico(fonte, &tabelaSimbolos);
    while (!feof(fonte)) {
        Token token = aLex->proxToken();
        aLex->emitirToken(&token);
    }
    fclose(fonte);
    tabelaSimbolos.clear();
}
