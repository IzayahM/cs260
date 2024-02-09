#pragma once
#include "node.h"

class list {
    private:
        node *head;

    public:
        list();
        void insert(int data, int position);
        void remove(int position);
        void display();
};