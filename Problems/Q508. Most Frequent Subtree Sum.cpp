class Solution {
    void helper(TreeNode* root, int& currSum) {
        if (root == nullptr) return; // Base case

        currSum += root->val;
        helper(root->left, currSum);
        helper(root->right, currSum);
    }


    void traverse(TreeNode* root, vector<int>& sumi) {
        if (root == nullptr) return;

        int currSum = 0;
        helper(root, currSum);
        sumi.push_back(currSum);

        traverse(root->left, sumi);
        traverse(root->right, sumi);
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> sumi;
        traverse(root, sumi);

        
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for (int s : sumi) {
            freq[s]++;
            maxFreq = max(maxFreq, freq[s]);
        }

        // Filter the sums that have the maximum frequency
        vector<int> res;
        for (auto& pair : freq) {
            if (pair.second == maxFreq) {
                res.push_back(pair.first);
            }
        }

        return res;
    }
};
