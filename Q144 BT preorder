class Solution {
private:
    void traverse(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        
        result.push_back(node->val);   // 1. Root
        traverse(node->left, result);  // 2. Left
        traverse(node->right, result); // 3. Right
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
};
