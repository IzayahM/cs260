#include <iostream>
#include "binary_tree.h"

using std::cout;
using std::endl;

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinaryNode *BinarySearchTree::insert_node(BinaryNode *node, int new_value){
    if (node == nullptr){
        return new BinaryNode(new_value);
    }
    //recursively goes through the tree to insert value
    if (node->value > new_value){
        node->left = insert_node(node->left, new_value);
    }
    else if(node->value < new_value){
        node->right = insert_node(node->right, new_value);
    }
    return node; // Return the modified node
}

BinaryNode *BinarySearchTree::delete_node(BinaryNode *node, int old_value){
    if (node == nullptr){
        cout << "The tree is empty!" << endl;
        return node;
    }
    //finds node
    if (node->value > old_value){
        node->right = delete_node(node->right, old_value);
    }
    else if(node->value < old_value){
        node->left = delete_node(node->left, old_value);
    }
    else{
        BinaryNode *tmp = nullptr;
        //no children case
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr; // Return null to indicate deletion
        }
        //if it has a child
        else if(node->right == nullptr)
        {
            tmp = node->left;
            delete node;
            return tmp;
        }
        else if(node->left == nullptr)
        {
            tmp = node->right;
            delete node;
            return tmp;
        }
        // if it has two children
        else{
            BinaryNode *parent = node;
            tmp = node->right;

            while (tmp->left != nullptr){
                parent = tmp;
                tmp = tmp->left;
            }
            if (parent != node){
                parent->left = tmp->right;
            }
            else{
                parent->right = tmp->right;
            }
            node->value = tmp->value;
            delete tmp;
        }
    }
    return node;
}

void BinarySearchTree::in_order_traversal() {
    in_order_traversal_helper(root);
    
}

void BinarySearchTree::in_order_traversal_helper(BinaryNode *current) {
    if(current != nullptr) {
        // go left
        in_order_traversal_helper(current->left);
        // visit
        cout << current->value << endl;
        // go right
        in_order_traversal_helper(current->right);
    }
}

void BinarySearchTree::test_tree(){
    BinaryNode *tree = nullptr;
    tree = insert_node(tree, 35);
    tree = insert_node(tree, 20);
    tree = insert_node(tree, 30);
    tree = insert_node(tree, 40);
    tree = insert_node(tree, 50);
    tree = insert_node(tree, 60);
    tree = insert_node(tree, 70);
    
    cout << "All inserted nodes:" << endl;
    in_order_traversal_helper(tree);
    cout << "Deletion of 35:" << endl;
    tree = delete_node(tree, 35);
    in_order_traversal_helper(tree);

}