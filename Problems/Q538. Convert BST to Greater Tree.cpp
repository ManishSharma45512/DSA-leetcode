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
    void helper(TreeNode* root, TreeNode* great, int& sum) {
        if (root == nullptr) return;

        
        if (root->right != nullptr) {
            great->right = new TreeNode(0);
            helper(root->right, great->right, sum);
        }

        
        sum += root->val;
        great->val = sum;

        
        if (root->left != nullptr) {
            great->left = new TreeNode(0);
            helper(root->left, great->left, sum);
        }
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return nullptr;

        TreeNode* great = new TreeNode(0);
        int sum = 0;
        helper(root, great, sum);

        return great;
    }
};
