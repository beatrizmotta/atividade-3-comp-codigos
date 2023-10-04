#include "global.h"

struct entry palavras_chave[] = {
        "div", DIV,
        "mod", MOD,
        0, 0
};

int init() {
    struct  entry *p;
    
    for (p = palavras_chave; p -> token; p++) {
        insert(p -> lexprt, p -> token);
    }
    
}