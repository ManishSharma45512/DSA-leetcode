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
    void find(TreeNode* searchRoot, TreeNode* curr, int target, bool& isFind) {
        if (searchRoot == nullptr || isFind) return;

        if (searchRoot->val == target && searchRoot != curr) {
            isFind = true;
            return;
        }

        find(searchRoot->left, curr, target, isFind);
        find(searchRoot->right, curr, target, isFind);
    }

    bool helper(TreeNode* entireTreeRoot, TreeNode* curr, int k) {
        bool isFind = false;
        int target = k - curr->val;

        find(entireTreeRoot, curr, target, isFind);

        return isFind;
    }

    bool traverse(TreeNode* entireTreeRoot, TreeNode* curr, int k) {
        if (curr == nullptr) return false;

        if (helper(entireTreeRoot, curr, k)) return true;


        return traverse(entireTreeRoot, curr->left, k) || traverse(entireTreeRoot, curr->right, k);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        return traverse(root, root, k);
    }
};
