#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 128 
#define EMPTY -1
#define EOS '\0'
#define NUMBER 256
#define DIV 257
#define MOD 258
#define ID 259
#define END 260

int lex_value;
int line_number;

struct symb_table_elem {
    char *lexem;
    int symb_lex;
};
struct symb_table_elem symbol_table[];

