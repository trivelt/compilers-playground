#include "global.h"

struct symb_table_elem keywords[] = {
    "div", DIV,
    "mod", MOD,
    0, 0
};

void init()
{
    struct symb_table_elem *p;
    for (p = keywords; p->symb_lex; p++)
    add(p->lexem, p->symb_lex);
}

