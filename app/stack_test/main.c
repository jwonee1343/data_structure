#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

#ifndef STACKLEN
#define STACKLEN 5
#endif /* STACKLEN */

int 
main(void)
{
    stack_t *s;
    int n = 0;

    printf("Stack length = %d\n", STACKLEN);

    s = stack_create(STACKLEN, sizeof(int));
    if (!s)
    {
        printf("Failed to create a stack\n");
        exit(EXIT_FAILURE);
    }

    printf("Stack = %p\n", s);

    printf("-- PUSH --\n");
    while (!stack_full(s))
    {
        *(int *)stack_push(s) = ++n;
        printf("%d -> top\n", n);
    }

    printf("-- POP --\n");
    while (!stack_empty(s))
    {
        printf("top -> %d\n", *(int *)stack_pop(s));
    }

    stack_destroy(s);
    exit(EXIT_SUCCESS);
}
