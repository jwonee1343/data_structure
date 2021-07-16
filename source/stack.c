/**
 * @file    stack.h
 * @author  Jaewon Choi <jwonee1343@gmail.com>
 */

#include "stack.h"

/* Includes */
#include <malloc.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Functions */

/**
 * @brief   Get start address of a stack elements
 *
 * @param   s       Pointer of a stack
 * @param   offset  Offset
 * @return  Start address of a stack + offset
 */
static inline void *
_stack_mem(stack_t *s, uint32_t offset)
{
    return (s + 1) + offset;
}

void
stack_init(stack_t *s, uint32_t len, uint32_t nsize)
{
    s->top = 0;
    s->len = len;
    s->nsize = nsize;
}

bool
stack_empty(stack_t *s)
{
    return s->top == 0;
}

bool
stack_full(stack_t *s)
{
    return s->top == s->len;
}

void *
stack_push(stack_t *s)
{
    if (stack_full(s))
    {
        return NULL;
    }

    return _stack_mem(s, s->nsize * s->top++);
}

void *
stack_pop(stack_t *s)
{
    if (stack_empty(s))
    {
        return NULL;
    }

    return _stack_mem(s, s->nsize * --s->top);
}

stack_t *
stack_create(uint32_t len, uint32_t nsize)
{
    stack_t *s;

    s = malloc(sizeof(*s));
    if (!s)
    {
        return NULL;
    }

    stack_init(s, len, nsize);
    return s;
}

void
stack_destroy(stack_t *s)
{
    free(s);
}
