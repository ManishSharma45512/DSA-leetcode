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
    void levels(TreeNode* root, vector<vector<int>>& level, int idx) {
        if (root == nullptr) return; // Base Case

        if (idx == level.size()) {
            level.push_back({});
        }

        level[idx].push_back(root->val);

        levels(root->left, level, idx + 1);
        levels(root->right, level, idx + 1);
    }

public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> level;
        levels(root, level, 0);

        vector<double> average;
        for (int i = 0; i < level.size(); i++) {
            double temp = 0.0;
            for (int j = 0; j < level[i].size(); j++) {
                temp += level[i][j]; 
            }
            average.push_back(temp / level[i].size());
        }

        return average;
    }
};
