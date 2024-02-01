#ifndef NODE_HEAD
#define NODE_HEAD
#include <iostream>

class Node {
    public:
        int id;
        Node *next;

        Node(int num);
};

#endif