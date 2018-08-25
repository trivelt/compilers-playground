#include "global.h"

#define LEXMAX 999
#define SYMMAX 100

char lexems[LEXMAX];
int last_character = -1; // last position in lexems table
struct symb_table_elem symbol_table[SYMMAX];
int last_element = 0; // last position in symbols table

int find(char s[])
{
    int p;
    for (p = last_element; p > 0; p--)
        if (strcmp(symbol_table[p].lexem, s) == 0)
            return p;
    return 0;
}

int add(char s[], int symb_lex)
{
    int length = strlen(s);
    if (last_element + 1 >= SYMMAX)
        error("symbol table is full");
    if (last_character + length +1 >= LEXMAX)
        error("symbol table is full");
    last_element++;
    symbol_table[last_element].symb_lex = symb_lex;
    symbol_table[last_element].lexem = &lexems[last_character + 1];
    last_character++;
    strcpy(symbol_table[last_element].lexem, s);
    return last_element;
}

