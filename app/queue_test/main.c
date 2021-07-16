#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#ifndef QUEUELEN
#define QUEUELEN 5
#endif /* QUEUELEN */

int 
main(void)
{
    queue_t *q;
    int n = 0;

    printf("Queue length = %d\n", QUEUELEN);

    q = queue_create(QUEUELEN, sizeof(int));
    if (!q)
    {
        printf("Failed to create a queue\n");
        exit(EXIT_FAILURE);
    }

    printf("Queue = %p\n", q);

    printf("-- ENQUEUE --\n");
    while (!queue_full(q))
    {
        *(int *)queue_enqueue(q) = ++n;
        printf("%d -> rear\n", n);
    }

    printf("-- DEQUEUE --\n");
    while (!queue_empty(q))
    {
        printf("front -> %d\n", *(int *)queue_dequeue(q));
    }

    queue_destroy(q);
    exit(EXIT_SUCCESS);
}
