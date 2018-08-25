#include "global.h"

char lexbuf[BUFSIZE];
int line_number = 1;
int lex_value = EMPTY;

int lexer()
{
    int t;
    while(1) {
        t = getchar();
        if (t == ' ' || t == '\t')
            ; // ignore whitespaces
        else if (t == '\n')
            line_number++;
        else if (isdigit(t)) {
            ungetc(t, stdin);
            scanf("%d", &lex_value);
            return NUMBER;
        }
        else if (isalpha(t)) {
            int p, b = 0;
            while (isalnum(t)) {
                lexbuf[b] = t;
                t = getchar();
                b++;
                if (b >= BUFSIZE)
                    error("compiler error");
            }
            lexbuf[b] = EOS;
            if (t != EOF)
                ungetc(t, stdin);
            p = find(lexbuf);
            if (p == 0)
                p = add(lexbuf, ID);
            lex_value = p;
            return symbol_table[p].symb_lex;
        }
        else if (t == EOF)
            return END;
        else {
            lex_value = EMPTY;
            return t;
        }
    }
}

