#include "compilador.h"

Compilador::Compilador(char * nomearquivo)
{
    fonte = fopen(nomearquivo, "r");
    if (fonte == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    aLex = new AnalisadorLexico(fonte, &tabelaSimbolos);
    while (!feof(fonte)) {
        aLex->proxToken();
        //aLex->emitirToken();
    }
    fclose(fonte);
}
