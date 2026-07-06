class Solution {
private:
    void traverse(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        
        traverse(node->left, result);  // 1. Left
        traverse(node->right, result); // 2. Right
        result.push_back(node->val);   // 3. Root
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};
