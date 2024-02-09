/* I've adapted this code from session 14, some of the logic I was using in my design didn't
quite work out so I changed some of it. 
*/
#include <iostream>
#include "list.h"
#include "node.h"

using std::cout;
using std::endl;

list::list() {
    head = nullptr;
}

void list::insert(int data, int position) {
    node *new_node = new node;
    new_node->data = data;
    new_node->pos = position;

    //I used chat gpt to help me with the logic on the specific part: || new_node->pos == 0
    if (head == nullptr || new_node->pos == 0){
        new_node->next = head;
        head = new_node;
        return;
    }
    
    node *current = head;
    node *tmp = nullptr;

    for (int i = 1; new_node->pos > i && current != nullptr; ++i){
        tmp = current;
        current = current->next;
    }

    tmp->next = new_node;
    new_node->next = current;
    }


void list::remove(int position) {

    if (head == nullptr){
        cout << "List is empty!" << endl;
        return;
    }
    //with this I dont have to create two nodes
    if (position == 1){
        node *current = head;
        head = head->next;
        cout <<"["<< current->data <<","<< current->pos <<"]"<<"Has been removed!"<< endl;
        delete current;
        return;
    }

    node *current = head;
    node *tmp = nullptr;
    //iterates through until the current pointer == position
    while (current != nullptr && current->pos != position) {
        tmp = current;
        current = current->next;
    }

    tmp->next = current->next;
    cout <<"["<< current->data <<","<< current->pos <<"]"<<"Has been removed!"<< endl;
    delete current;
}

void list::display(){
    if (head == nullptr){
        cout << "List is empty, nothing to display!" << endl;
    }
    node *current = head;
    while (current != nullptr){
        cout <<"["<< current->data <<","<< current->pos <<"]"<< endl;
        current = current->next;
    }
}

int main(){
    list linked_list;
//some tests
    linked_list.remove(2);
    linked_list.display();
    linked_list.insert(1,1);
    linked_list.insert(2,3);
    linked_list.insert(2,2);
    linked_list.display();
    linked_list.remove(2);
    linked_list.display();

}
