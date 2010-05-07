#include "compilador.h"

/**
 * Programa principal soh inicia o compilador
 */
int main(int argc, char *argv[])
{
    if (argc != 2) {
        puts("Passe o codigo fonte como argumento!");
    }
    Compilador c(argv[1]);
    return(0);
}
