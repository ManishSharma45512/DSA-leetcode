/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
    void helper(TreeNode* root, vector<int>& values, bool& isUni) {
        if (root == nullptr || !isUni) return; // Base case

        
        if (values.empty()) {//empty
            values.push_back(root->val);
        } else if (root->val != values[0]) {
            // Found a value that doesn't match!
            isUni = false;
            return;
        }

        // Check left and right subtrees
        helper(root->left, values, isUni);
        helper(root->right, values, isUni);
    }

public:
    bool isUnivalTree(TreeNode* root) {
        vector<int> values;
        bool isUni = true;
        helper(root, values, isUni);

        return isUni;
    }
};
