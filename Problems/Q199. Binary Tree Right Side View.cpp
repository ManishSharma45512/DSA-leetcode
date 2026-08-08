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
    void helper(TreeNode* root, vector<vector<int>>& level, int idx) {
        if (root == nullptr) return; // Base Case

        if (idx == level.size()) {//if visit first time then a level
            level.push_back({});
        }

        level[idx].push_back(root->val);

        helper(root->left, level, idx + 1);
        helper(root->right, level, idx + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> level;
        helper(root, level, 0);

        vector<int> res;
        for (int i = 0; i < level.size(); i++) {
            int n = level[i].size();
            res.push_back(level[i][n - 1]); //rightmost element is right view
        }

        return res;
    }
};
