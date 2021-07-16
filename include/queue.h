/**
 * @file    queue.h
 * @author  Jaewon Choi <jwonee1343@gmail.com>
 */
#ifndef _QUEUE_H
#define _QUEUE_H

/* Includes */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Structure */
typedef struct
{
    uint32_t front;     /* Index of front position */
    uint32_t rear;      /* Index of rear position */
    uint32_t len;       /* Count of queue elements */
    uint32_t nsize;     /* Size of a queue element */
    bool empty;
} queue_t;

/* Functions */

/**
 * @brief   Initialize a queue
 *
 * @param   q       Pointer of a queue
 * @param   len     Count of queue elements
 * @param   nsize   Size of a queue element
 */
void queue_init(queue_t *q, uint32_t len, uint32_t nsize);

/**
 * @brief   Check if a queue is empty
 *
 * @param   q       Pointer of a queue
 * @return  If a queue is empty, return true or not false
 */
bool queue_empty(queue_t *q);

/**
 * @brief   Check if a queue is full 
 *
 * @param   q       Pointer of a queue
 * @return  If a queue is full, return true or not false
 */
bool queue_full(queue_t *q);

/**
 * @brief   Enqueue a rear of queue and return the position
 *
 * @param   q       Pointer of a queue
 * @return  Address of queue elements on the rear
 */
void *queue_enqueue(queue_t *q);

/**
 * @brief   Dequeue a front of queue and return the position
 *
 * @param   q       Pointer of a queue
 * @return  Address of queue elements on the front
 */
void *queue_dequeue(queue_t *q);

/**
 * @brief   Pop a top of queue and return the position
 *
 * @param   q       Pointer of a queue
 * @return  Address of queue elements on the top
 */
queue_t *queue_create(uint32_t len, uint32_t nsize);

/**
 * @brief   Pop a top of queue and return the position
 *
 * @param   q       Pointer of a queue
 * @return  Address of queue elements on the top
 */
void queue_destroy(queue_t *q);

#endif /* _QUEUE_H */
