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
        if (strcmp(token.tipo, "EOF")) {
            printf("%s - %s\n", token.simbolo, token.tipo);
        }
        //aLex->emitirToken(token);
    }
    fclose(fonte);
}
