/**
 * @file    queue.h
 * @author  Jaewon Choi <jwonee1343@gmail.com>
 */

#include "queue.h"

/* Includes */
#include <malloc.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Functions */

/**
 * @brief   Get start address of a queue elements
 *
 * @param   q       Pointer of a queue
 * @param   offset  Offset
 * @return  Start address of a queue + offset
 */
static inline void *
_queue_mem(queue_t *q, uint32_t offset)
{
    return (q + 1) + offset;
}

void
queue_init(queue_t *q, uint32_t len, uint32_t nsize)
{
    q->front = 0;
    q->rear = 0;
    q->len = len;
    q->nsize = nsize;
    q->empty = true;
}

bool
queue_empty(queue_t *q)
{
    return q->empty;
}

bool
queue_full(queue_t *q)
{
    return !q->empty && q->front == q->rear;
}

void *
queue_enqueue(queue_t *q)
{
    if (queue_full(q))
    {
        return NULL;
    }

    q->rear = (q->rear + 1) % q->len;

    if (q->empty)
    {
        q->empty = false;
    }

    return _queue_mem(q, q->nsize * q->rear);
}

void *
queue_dequeue(queue_t *q)
{
    if (queue_empty(q))
    {
        return NULL;
    }
    
    q->front = (q->front + 1) % q->len;
    if (q->front == q->rear)
    {
        q->empty = true;
    }

    return _queue_mem(q, q->nsize * q->front);
}

queue_t *
queue_create(uint32_t len, uint32_t nsize)
{
    queue_t *q;

    q = malloc(sizeof(*q));
    if (!q)
    {
        return NULL;
    }

    queue_init(q, len, nsize);
    return q;
}

void
queue_destroy(queue_t *q)
{
    free(q);
}
