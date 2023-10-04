#include "global.h"

int erro(char *m) // Gera todas as mensagens de erro
{
    fprintf(stderr, "linha %d: %s\n", clinha, m);
    exit(1); // Término do programa sem sucesso
}