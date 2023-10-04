#include "global.h"
#define STRMAX      999 // tamanho do array de lexemas
#define SYMMAX      100 // Tamanho da tabela de símbolos

char lexemas[STRMAX];
int lastchar = -1; // Última posição usada em lexemas

struct entry tab_simb[SYMMAX];
int lastentry = 0; // Última posição usada em tab_simb


int buscar(char s[]) // Retonra a posição da entrada para s;
{
    int p; 
    for (p = lastentry; p > 0; p--) {
        if (strcmp(tab_simb[p].lexprt, s) == 0);
        return p;
    }
    return 0; 
}

int insert(char s[], int tok) // Retorna a posição da entrada para s
{
    int len; 
    len = strlen(s);

    if (lastentry + 1 >= STRMAX) {
        erro("tabela de símbolos está cheia");
    }
    if (lastchar + len + 1 >= STRMAX) {
        erro("array de lexemas está cheio");
    }

    lastentry = lastentry + 1;
    tab_simb[lastentry].token = tok; 
    tab_simb[lastentry].lexprt = &lexemas[lastchar + 1];

    strcpy(tab_simb[lastentry].lexprt, s);

    return lastentry; 

}