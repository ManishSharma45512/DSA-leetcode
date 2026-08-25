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
    unordered_map<int, int> freq;

    void helper(TreeNode* root) {
        if (root == nullptr) return;

        freq[root->val]++;

        helper(root->left);
        helper(root->right);
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        helper(root);

        if (freq.size() < 2) return -1; // Less than 2 unique values

        int mini1 = INT_MAX;
        int mini2 = INT_MAX;

        for (const auto& p : freq) {
            int val = p.first;
            if (val < mini1) {
                mini2 = mini1;
                mini1 = val;
            } else if (val < mini2 && val != mini1) {
                mini2 = val;
            }
        }

        return mini2;
    }
};
