#ifndef QUEUE_HEAD
#define QUEUE_HEAD
#include "node.hpp"

class Queue{
    public:
        Node *front;
        Node *rear;
        Queue();
        void enqueue(int num);
        void dequeue();

};

#endif