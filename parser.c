#include "global.h"

int lookahead;

int parse()
{ // Analisa gramaticalmente e traduz uma lista de expressões
    lookahead = lexan();
    while (lookahead != DONE)
    {
        expr();
        reconhecer(';');
    }
}

int expr()
{
    int t;
    termo();
    while (1)
    {
        switch (lookahead)
        {
        case '+':
        case '-':
            t = lookahead;
            reconhecer(lookahead);
            termo();
            emitir(t, NONE);
            continue;
        default:
            return;
        }
    }
}

int termo()
{
    int t;
    fator();
    while (1)
    {
        switch (lookahead)
        {
        case '*':
        case '/':
        case DIV:
        case MOD:
            t = lookahead;
            reconhecer(lookahead);
            fator();
            emitir(t, NONE);
            continue;
        default:
            return;
        }
    }
}

int fator()
{
    switch (lookahead)
    {
    case '(':
        reconhecer('(');
        expr();
        reconhecer(')');
        break; 
    case NUM:
        emitir(NUM, tokenval);
        reconhecer(NUM);
        break;
    case ID:
        emitir(ID, tokenval);
        reconhecer(ID); 
        break;
    default:
        erro("erro de sintaxe");
    }
}

int reconhecer(int t) {
    if (lookahead == t) {
        lookahead = lexan();
    } else {
        erro("erro de sintaxe");
    }

}