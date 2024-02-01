#include "queue.hpp"
#include <iostream>

using std::cout;
using std::endl;

Queue::Queue(){
    front = nullptr;
    rear = nullptr;
}

void Queue::enqueue(int num){

    Node *new_node = new Node(new_node->id = num);
    //both f/r pointer will point to first item if empty
    if (front == nullptr){
        front = new_node;
        rear = front;
    }
    //only the rear pointer moves when adding item
    else{
        rear->next = new_node;
        rear = new_node;
    }

    cout << "The following has been added to the queue: " << num << endl;
    //tests to see f/r
    cout << "front " << front->id << endl;
    cout << "rear: " << rear->id << endl;
}

void Queue::dequeue(){
    if (front == nullptr){
        std::cout << "Queue is empty..." << endl;
    }
    else
    {
        Node *tmp = front;
        //moves the front pointer to next in queue
        front = front->next;
        cout << tmp->id << " has been dequeued!" << endl;
        //tests to see f/r
        cout << "front " << front->id << endl;
        cout << "rear: " << rear->id << endl;
        delete tmp;
    }

}

