#include "MyQueue.h"

/*
    Implementation of Queue of Integers using a circular array.
    Supports enqueue and dequeue.

    Keeps track of front and back of the queue using two indices.
    Indicies are maintained/calculated using modulus operator.
*/

struct MyQueue
{
    int* data;
    size_t size_allocated;
    size_t size_used;
    int front;
    int back;
};

// gets the next available index handling looping around the array
static int getNextIndex(MyQueuePtr mq, int i)
{
    return ++i % mq->size_allocated;
}


MyQueuePtr mq_create_my_queue(size_t size_allocated)
{
    MyQueuePtr mq = malloc(sizeof(struct MyQueue));
    mq->data = malloc(sizeof(int)* size_allocated);

    mq->front = -1;
    mq->back = -1;

    mq->size_allocated = size_allocated;
    mq->size_used = 0;

    return mq;
}

EXIT_STATUS mq_destroy_my_queue(MyQueuePtr* mq)
{
    free((*mq)->data);
    free(*mq);

    *mq = NULL;

    return SUCCESS;
}

EXIT_STATUS mq_enqueue(MyQueuePtr mq, int data)
{
    if (!mq) return FAILURE;

    // queue full
    if (mq->size_allocated == mq->size_used)
    {
        printf("\nQueue is full! Size allocated: %d\tSize used: %d\n\n", mq->size_allocated, mq->size_used);
        return FAILURE;
    }

    // empty queue
    if (mq->size_used == 0)
    {
        mq->data[0] = data;
        mq->front = mq->back = 0;
    }
    else // there are 1 to n-1 elements in the queue
    {
        mq->back = getNextIndex(mq, mq->back);

        // collision should not occur in this case
        mq->data[mq->back] = data;
    }

    mq->size_used++;

    return SUCCESS;
}

EXIT_STATUS mq_dequeue(MyQueuePtr mq, int* dequeued)
{
    if (!mq) return FAILURE;

    // empty queue
    if (mq->size_used == 0)
    {
        printf("\nQueue is empty!\n");
        return FAILURE;
    }

    // return the front element
    *dequeued = mq->data[mq->front];

    mq->front = getNextIndex(mq, mq->front);
    mq->size_used--;

    return SUCCESS;
}

