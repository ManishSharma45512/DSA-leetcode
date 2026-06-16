class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // Look for p and q in the left and right subtrees
        TreeNode* leftResult = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightResult = lowestCommonAncestor(root->right, p, q);



        if (leftResult != nullptr && rightResult != nullptr) {
            return root;
        }

        // Otherwise, if only one side found something, return that side's result
        return (leftResult != nullptr) ? leftResult : rightResult;
    }
};
