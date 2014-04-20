#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdlib.h>
#include <stdio.h>

typedef enum
{
    FAILURE = 0,
    SUCCESS = 1
} EXIT_STATUS;

typedef struct MyQueue* MyQueuePtr;

MyQueuePtr  mq_create_my_queue(size_t size_allocated);
EXIT_STATUS mq_destroy_my_queue(MyQueuePtr* mq);
EXIT_STATUS mq_enqueue(MyQueuePtr mq, int data);
EXIT_STATUS mq_dequeue(MyQueuePtr mq, int* dequeued);

#ifdef __cplusplus
}
#endif

#endif;