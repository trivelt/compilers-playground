#include "global.h"

int current;
void expr();

void load(int s)
{
    if (current == s)
        current = lexer();
    else
        error("syntax error");
}

void factor()
{
    switch (current) {
        case '(':
            load("("); expr(); load(")"); break;
        case NUMBER:
            emit(NUMBER, lex_value); load(NUMBER); break;
        case ID:
            emit(ID, lex_value); load(ID); break;
        default:
            error("syntax error");
    }
}

void comp()
{
    int s;
    factor();
    while(1) {
        switch (current) {
            case '*': case '/': case DIV: case MOD:
                s = current;
                load(current); factor(); emit(s, EMPTY);
                continue;
            default:
                return;
        }
    }
}

void expr()
{
    int s;
    comp();
    while(1) {
        switch (current) {
            case '+': case '-':
                s = current;
                load(current); comp(); emit(s, EMPTY);
                continue;
            default:
                return;
        }
    }
}

void parser()
{
    current = lexer();
    while (current != END) {
        expr(); load(';');
    }
}


