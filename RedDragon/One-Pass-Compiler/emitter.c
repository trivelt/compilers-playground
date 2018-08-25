#include "global.h"

void emit(int s, int symb_value)
{
    switch (s) {
        case '+': case '-': case '*': case '/':
            printf("%c\n", s); break;
        case DIV:
            printf("DIV\n");
        case MOD:
            printf("MOD\n");
        case NUMBER:
            printf("%d\n", symb_value); break;
        case ID:
            printf("%s\n", symbol_table[symb_value].lexem); break;
        default:
            printf("lexem %s, value %d\n", s, symb_value);
    }
}

