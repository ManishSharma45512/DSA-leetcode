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
    void countFromNode(TreeNode* root, long long targetSum, int& found) {
        if (root == nullptr) return;

        if (targetSum == root->val) {
            found++;// Found a valid path!
        }

        // Keep exploring downwards on the SAME contiguous path
        countFromNode(root->left, targetSum - root->val, found);
        countFromNode(root->right, targetSum - root->val, found);
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;

        int found = 0;

        
        countFromNode(root, targetSum, found);

        found += pathSum(root->left, targetSum);
        found += pathSum(root->right, targetSum);

        return found;
    }
};
