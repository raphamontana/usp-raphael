#include "compilador.h"

/**
 * Programa principal soh inicia o compilador
 */
int main(int argc, char *argv[])
{
    Compilador * c;
    if (argc != 2) {
        puts("Passe o codigo fonte como argumento!");
        return(0);
    }
    c = new Compilador(argv[1]);
    delete(c);
    return(0);
}
