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
    int maxDepth = -1;

    void helper(TreeNode* root, vector<int>& left, int depth) {
        if (root == nullptr) return; // Base Case

        // If we reach a deeper level for the first time, record the leftmost node
        if (depth > maxDepth) {
            maxDepth = depth;
            left.push_back(root->val);
        }

        helper(root->left, left, depth + 1);// Traverse left
        helper(root->right, left, depth + 1);// Traverse right
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        vector<int> left;
        helper(root, left, 0);

        int n = left.size() - 1;
        return left[n];
    }
};
