#include <iostream>
#include <sstream>
#include "hash_t.hpp"

using namespace std;
using std::stringstream;

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table[i] = nullptr;
    }
}

int HashTable::hash(string value) {
    int hash = 0;
    for (char c : value) {
        hash += (int)c;
    }
    return hash % TABLE_SIZE;
}

int HashTable::add(string value) {
    int bucket = hash(value);

    Node* newNode = new Node(value);
    //puts str into bucket if bucket is empty
    if (table[bucket] == nullptr) {
        table[bucket] = newNode;
    } else {
        //collision
        Node* current = table[bucket];
        current->next = newNode;
    }
    return bucket;
}

void HashTable::remove(string value) {
    int bucket = hash(value);
    Node* current = table[bucket];
    Node* tmp = nullptr;

    while (current != nullptr) {
        if (current->data == value) {
            if (tmp == nullptr) {
                //points to null or collision case
                table[bucket] = current->next;
            } else {
                tmp->next = current->next;
            }
            cout << current->data << " has been deleted!" << endl;
            return;
        }
        //traversal
        tmp = current;
        current = current->next;
    }

    return;
}

bool HashTable::search(string value) {
    int bucket = hash(value);
    Node* current = table[bucket];

    while (current != nullptr) {
        if (current->data == value) {
                cout << value << " found!"<< endl; 
            return true;
        }
        current = current->next;
    }
    cout << value << " does not exist!"<< endl; 
    return false;
}

string HashTable::toString() {
    stringstream result;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        result << "Bucket " << i << ": ";
        Node* current = table[i];
        while (current != nullptr) {
            result << current->data << ", ";
            current = current->next;
        }
        result << "\n";
    }
    return result.str();
}

int HashTable::getCollisionCount() {
    int collisions = 0;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node* current = table[i];
        //if there are two in same bucket
        if (current != nullptr && current->next != nullptr) {
            cout << "Collision found in Bucket "<< i << endl;
            ++collisions;
        }
        delete current;
    }
    
    return collisions;
}

int main() {
    HashTable table;
    table.add("clementine");
    table.add("chim");
    table.add("howly");
    table.add("chunk");
    table.add("lucy");
    table.add("lasagana");
    table.add("moo");
    table.search("chim");
    cout << table.getCollisionCount() << endl; 
    cout << table.toString() << endl; 
    table.remove("chim");
    cout << table.toString() << endl;
    return 0;
}