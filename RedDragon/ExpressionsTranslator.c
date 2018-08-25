/* 
Example 2.24 from book
Compilers: Principles, Techniques, and Tools
by A.V. Aho, R. Sethi, J.D. Ullman
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int current;

void error()
{
    printf("syntax error\n");
    exit(1); 
}

void load(int t)
{
    if (current == t)
        current = getchar();
    else 
        error();
}

void term()
{
    if (isdigit(current)) {
        putchar(current);
        load(current);
    }
    else error();
}

void expr()
{
    term();
    while (1)
        if (current =='+') {
            load('+'); term(); putchar('+');
        }
        else if (current == '-') {
            load('-'); term(); putchar('-');
        }
        else break;
}


int main()
{
    current = getchar();
    expr();
    putchar ('\n');
}

