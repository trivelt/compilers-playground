#include "global.h"

void error(char* m)
{
    fprintf(stderr, "line %d: %s\n", line_number, m);
    exit(1);
}

