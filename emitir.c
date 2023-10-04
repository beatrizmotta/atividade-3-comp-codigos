#include "global.h"

int emitir(int t, int tval) // Gera a saída 
{
    switch (t)
    {
    case '+': case '-': case '*': case '/':
        printf("%c\n", t);
        break;
    case DIV:
        printf("DIV\n");
        break;
    case MOD:
        printf("MOD\n");
        break;
    case NUM:
        printf("%d\n", tval);
        break;
    case ID:
        printf("%d\n", tab_simb[tval].lexprt);
        break;
    default:
        printf("token %d, tokeval %d\n", t, tval);
    }
}