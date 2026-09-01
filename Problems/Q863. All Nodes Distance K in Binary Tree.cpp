/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void addSubtreeNodes(TreeNode* root, int d, int k, vector<int>& res) {
        if (root == nullptr) return;

        if (d == k) {
            res.push_back(root->val);
            return;
        }

        addSubtreeNodes(root->left, d + 1, k, res);
        addSubtreeNodes(root->right, d + 1, k, res);
    }

    int findTarget(TreeNode* root, TreeNode* target, int k, vector<int>& res) {
        if (root == nullptr) return -1;

        if (root == target) {
            addSubtreeNodes(root, 0, k, res);
            return 0; // Distance to target is 0
        }

        int leftDist = findTarget(root->left, target, k, res);
        if (leftDist != -1) {
            if (leftDist + 1 == k) {
                res.push_back(root->val);
            } else {
                addSubtreeNodes(root->right, leftDist + 2, k, res);
            }
            return leftDist + 1;
        }

        int rightDist = findTarget(root->right, target, k, res);
        if (rightDist != -1) {
            if (rightDist + 1 == k) {
                res.push_back(root->val);
            } else {
                addSubtreeNodes(root->left, rightDist + 2, k, res);
            }
            return rightDist + 1;
        }

        return -1;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        findTarget(root, target, k, res);
        return res;
    }
};
