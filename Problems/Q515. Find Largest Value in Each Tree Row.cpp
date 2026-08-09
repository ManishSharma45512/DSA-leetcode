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
    void level(TreeNode* root, vector<vector<int>>& levels, int idx) {
        if (root == nullptr) return; // Base Case

        if (levels.size() == idx) levels.push_back({}); // First time visiting level

        levels[idx].push_back(root->val);
        
        level(root->left, levels, idx + 1);
        level(root->right, levels, idx + 1);

        return;
    }

public:
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> levels;
        level(root, levels, 0);

        vector<int> res;

        for (const vector<int>& p : levels) {
            res.push_back(*max_element(p.begin(), p.end()));
        }

        return res;
    }
};
