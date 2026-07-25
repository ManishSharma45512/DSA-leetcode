class Solution {
    unordered_map<TreeNode*, int> memo;

public:
    int alternateRobbery(TreeNode* root) {
        if (root == nullptr) return 0; // Base case
        
        // we already computed max loot for this node, return it
        if (memo.count(root)) return memo[root];

        int robRoot = root->val;

        //left grandchildren
        if (root->left != nullptr) {
            robRoot += alternateRobbery(root->left->left);
            robRoot += alternateRobbery(root->left->right);
        }

        //right grandchildren
        if (root->right != nullptr) {
            robRoot += alternateRobbery(root->right->left);
            robRoot += alternateRobbery(root->right->right);
        }

        //Skip root and rob left & right subtrees
        int skipRoot = alternateRobbery(root->left) + alternateRobbery(root->right);

        return memo[root] = max(robRoot, skipRoot);
    }

    int rob(TreeNode* root) {
        return alternateRobbery(root);
    }
};
