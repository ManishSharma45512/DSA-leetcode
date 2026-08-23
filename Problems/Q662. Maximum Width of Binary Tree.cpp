class Solution {
    void buildLevel(TreeNode* root, vector<vector<unsigned long long>>& level, int i, unsigned long long idx) {
        if (root == nullptr) return;

        if (i == level.size()) {
            level.push_back({idx, idx}); //{first_idx, last_idx}
        } else {
            level[i][1] = idx; //Update rightmost index at this depth
        }

        // Normalize relative to level's first index to prevent 64-bit overflow
        unsigned long long normalized = idx - level[i][0];

        buildLevel(root->left, level, i + 1, 2 * normalized + 1);
        buildLevel(root->right, level, i + 1, 2 * normalized + 2);
    }

    int processLevel(vector<vector<unsigned long long>>& level, int i) {
        return level[i][1] - level[i][0] + 1;
    }

public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        vector<vector<unsigned long long>> level;
        buildLevel(root, level, 0, 0);

        int max_width = 0;
        for (int i = 0; i < level.size(); i++) {
            max_width = max(max_width, processLevel(level, i));
        }

        return max_width;
    }
};
