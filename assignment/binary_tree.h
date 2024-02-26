struct BinaryNode
{
    int value;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
    BinaryNode *root;
    void in_order_traversal_helper(BinaryNode *current);
    

    public:
        BinarySearchTree();
        BinaryNode* insert_node(BinaryNode *node, int new_value);
        BinaryNode* delete_node(BinaryNode *node, int old_value);
        bool search(int proposed_value);
        void test_tree();
        void in_order_traversal();
};