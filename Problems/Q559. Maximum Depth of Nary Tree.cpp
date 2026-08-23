/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    int helper(Node* root, int depth) {
        if (root == nullptr) {
            return depth;
        }
        int curr = depth;

        for (Node* child : root->children) {
            curr = max(curr, helper(child, depth + 1));
        }

        return curr;
    }

public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;// Handled empty tree edge case
        return helper(root, 1);
    }
};
