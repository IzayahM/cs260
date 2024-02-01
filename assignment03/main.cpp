/*
Izayah Marchand 
1/31/2024
cs260
This program is a queue linked list structure that can enqueue and dequeue. It does not take
user input as of right now. I am currently having an issue with the front pointer of the queue 
moving to the rear pointer after the first call of the enqueue function as well as only being
able to dequeue once without the program crashing.
*/
#include <iostream>
#include "node.hpp"
#include "queue.hpp"


int main() {
    Queue line;

    // tests empty queue
    line.dequeue();
    // enqueue tests

    line.enqueue(17);
    line.enqueue(23);
    line.enqueue(24);

    // dequeue tests
    line.dequeue();

    // I am currently expereiencing a problem where after the first dequeue any attempts
    // at another dequeue breaks the program and I am not sure why.
    // line.dequeue();
    // line.dequeue();


    return 0;
}