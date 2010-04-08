#include "compilador.h"

Compilador::Compilador(char * nomearquivo)
{
    fonte = fopen(nomearquivo, "r");
    if (fonte == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    aLex = new AnalisadorLexico(fonte, &tabelaSimbolos);
    Token token;
    while (!feof(fonte)) {
        token = aLex->proxToken();
        aLex->emitirToken(token);
        printf("%s - %s\n", token.simbolo, token.tipo);
    }

    fclose(fonte);
}
