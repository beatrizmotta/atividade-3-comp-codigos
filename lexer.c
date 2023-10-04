#include "global.h"

char lexbuf[BSIZE];
int clinha = 1; 
int tokenval = NONE;

int lexan() {

    int t;
    while (1) {
        t = getchar(); 

        if (t == ' ' || t == '\t') {
            ; // Remover os espaços em branco
        } else if (t == '\n') {
            clinha = clinha + 1; 
        } else if (isdigit(t)) {
            ungetc(t, stdin);
            scanf("%d", &tokenval);
            return NUM;
        } else if (isalpha(t)) {
            int p, b = 0; 
            while (isalnum(t)) {
                lexbuf[b] = t;
                t = getchar();
                b = b + 1; 
                if (b >= BSIZE) {
                    erro("erro do compilador");
                }
            }
            
            lexbuf[b] = EOS; 

            if (t != EOF) {
                ungetc(t, stdin);
            }
            p = buscar(lexbuf);
            if (p == 0) {
                p = insert(lexbuf, ID);
            }
        
            tokenval = p; 

            return tab_simb[p].token; 
        
        } else if (t == EOF) {
            return DONE;
        } else {
            tokenval = NONE; 
            return t; 
        }
        }


    }


