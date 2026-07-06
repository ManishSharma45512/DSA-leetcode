/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

class Solution {
public:
    Node* connect(Node* root) {
        // Base case
        if (root == NULL || root->left == NULL) return root;

        // Connection 1: Link left child directly to right child
        root->left->next = root->right;

        // Connection 2: Link right child to the left child of the next subtree
        if (root->next != NULL) {
            root->right->next = root->next->left;
        }

       
        connect(root->left);
        connect(root->right);

        
        return root;
    }
};
