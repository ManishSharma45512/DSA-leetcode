class Solution {
public:
    int sumNumbers(TreeNode* root, int sum = 0) {
        // Base case
        if (root == nullptr) return 0;

        // Calculate the value of the path from the root down to the current node
        sum = sum * 10 + root->val;

        // If we reach a leaf node, return the completed path value
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        }

        // Recursively find the sum of all paths in the left and right subtrees
        return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
    }
};
