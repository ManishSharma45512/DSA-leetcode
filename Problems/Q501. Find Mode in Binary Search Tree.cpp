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

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


class Solution {
private:
    vector<int> nodeValues; 

    //Traversal function
    void traverse(TreeNode* root) {
        if (root == nullptr) return;

        traverse(root->left);
        nodeValues.push_back(root->val);
        traverse(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        
        nodeValues.clear();//clear traversal vector from previous Traversal
        traverse(root);

        
        unordered_map<int, int> freq;//O(1)
        int max_freq = 0;

        for (int val : nodeValues) {
            freq[val]++;
            
            max_freq = max(max_freq, freq[val]);
        }

        //Collect all elements that match the maximum frequency
        for (auto& pair : freq) {
            if (pair.second == max_freq) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};
