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
    int maxEdges = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int leftArm = 0, rightArm = 0;

        if (root->left && root->left->val == root->val) {
            leftArm = left + 1;
        }

        if (root->right && root->right->val == root->val) {
            rightArm = right + 1;
        }

        maxEdges = max(maxEdges, leftArm + rightArm);

        return max(leftArm, rightArm);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        maxEdges = 0;
        dfs(root);
        return maxEdges;
    }
};
