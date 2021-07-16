/**
 * @file    stack.h
 * @author  Jaewon Choi <jwonee1343@gmail.com>
 */
#ifndef _STACK_H
#define _STACK_H

/* Includes */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Structure */
typedef struct
{
    uint32_t top;       /* Index of top position */
    uint32_t len;       /* Count of stack elements */
    uint32_t nsize;     /* Size of a stack element */
} stack_t;

/* Functions */

/**
 * @brief   Initialize a stack
 *
 * @param   s       Pointer of a stack
 * @param   len     Count of stack elements
 * @param   nsize   Size of a stack element
 */
void stack_init(stack_t *s, uint32_t len, uint32_t nsize);

/**
 * @brief   Check if a stack is empty
 *
 * @param   s       Pointer of a stack
 * @return  If a stack is empty, return true or not false
 */
bool stack_empty(stack_t *s);

/**
 * @brief   Check if a stack is full 
 *
 * @param   s       Pointer of a stack
 * @return  If a stack is full, return true or not false
 */
bool stack_full(stack_t *s);

/**
 * @brief   Push a top of stack and return the position
 *
 * @param   s       Pointer of a stack
 * @return  Address of stack elements on the top
 */
void *stack_push(stack_t *s);

/**
 * @brief   Pop a top of stack and return the position
 *
 * @param   s       Pointer of a stack
 * @return  Address of stack elements on the top
 */
void *stack_pop(stack_t *s);

/**
 * @brief   Pop a top of stack and return the position
 *
 * @param   s       Pointer of a stack
 * @return  Address of stack elements on the top
 */
stack_t *stack_create(uint32_t len, uint32_t nsize);

/**
 * @brief   Pop a top of stack and return the position
 *
 * @param   s       Pointer of a stack
 * @return  Address of stack elements on the top
 */
void stack_destroy(stack_t *s);

#endif /* _STACK_H */
