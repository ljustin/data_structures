#include <iostream>
#include "IntArray.h"
#include "MyQueue.h"

using namespace std;

// To Do..

// array
// vector (dynamic array)
// singly linked list
// doubly linked list
// Stack/Queue
// Priority Queue / Heap
// Hash map
// Binary Tree
// Binary Search Tree
// Balanced Binary Search Tree (Red-Black Tree)
// B-Tree
// Graph (directed/undirected/weighted as matrix and list)

// Above as templates


int main(int argc, char** argv)
{
    cout << "Hello World!" << endl;

    JDS::IntArray iArr(3);
    cout << iArr;

    iArr[0] = 1;
    iArr[1] = 2;

    cout << iArr;

    JDS::IntArray iArrCopy(iArr);
    cout << iArrCopy;

    MyQueuePtr mq = mq_create_my_queue(5);
    mq_enqueue(mq, 1);
    mq_enqueue(mq, 2);
    mq_enqueue(mq, 3);

    int dequeued = 0;
    mq_dequeue(mq, &dequeued);
    mq_dequeue(mq, &dequeued);
    mq_dequeue(mq, &dequeued);
    mq_dequeue(mq, &dequeued);

    system("pause");
    return 0;
}