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
private:
    int maxSum = INT_MIN;

    int gainFromSubtree(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftGain = max(gainFromSubtree(root->left), 0);
        int rightGain = max(gainFromSubtree(root->right), 0);
        
        int currentPathSum = root->val + leftGain + rightGain;

        maxSum = max(maxSum, currentPathSum);

        
        return root->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        gainFromSubtree(root);
        return maxSum;
    }
};
