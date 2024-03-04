#ifndef HASH_T_HPP
#define HASH_T_HPP
#include <string>
using std::string;

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    struct Node {
        string data;
        Node* next;
        Node(string value) : data(value), next(nullptr) {}
    };
    Node* table[TABLE_SIZE];
    int hash(string value);

public:
    HashTable();
    int add(string value);
    void remove(string value);
    bool search(string value);
    string toString();
    int getCollisionCount();
};

#endif 
