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
    void helper(Node* root, vector<vector<int>>& res, int idx) {
        if (root == nullptr) return; // Base Case

        // If visiting this depth level for the first time, add a new row
        if (idx == res.size()) {
            res.push_back({});
        }

        res[idx].push_back(root->val);

        for (Node* child : root->children) {
            helper(child, res, idx + 1);
        }
    }

public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        helper(root, res, 0);
        return res;
    }
};
