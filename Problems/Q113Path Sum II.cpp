class Solution {
private:
    vector<vector<int>> ans;

    void dfs(TreeNode* curr, int sum, vector<int>& path) {
        if (curr == nullptr) return;

        // 1. Add current node to path
        path.push_back(curr->val);

        // Check if we are at a leaf node
        bool isLeaf = (curr->left == nullptr && curr->right == nullptr);

        if (isLeaf) {
            // 2. If it's a leaf and the value matches what's left of the sum
            if (sum == curr->val) {
                ans.push_back(path);
            }
        } else {
            // 3. Keep searching left and right branches
            dfs(curr->left, sum - curr->val, path);
            dfs(curr->right, sum - curr->val, path);
        }

        // 4. Backtrack: Erase footprint before returning to parent
        path.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear();
        vector<int> path;
        
        dfs(root, targetSum, path);
        
        return ans;
    }
};
