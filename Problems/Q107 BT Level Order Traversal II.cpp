class Solution {
public:
    void travel(TreeNode* root, vector<vector<int>>& res, int i) {
        if (root == nullptr) return;

        
        if (res.size() <= i) {
            res.push_back({});
        }

        
        res[i].push_back(root->val);

        
        if (root->left != nullptr && root->right != nullptr) {
            travel(root->left, res, i + 1);
            travel(root->right, res, i + 1);
        }
        else if (root->left != nullptr && root->right == nullptr) {
            travel(root->left, res, i + 1);
        }
        else if (root->left == nullptr && root->right != nullptr) {
            travel(root->right, res, i + 1);
        }
        else {
            return; 
        }
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res; 

        
        travel(root, res, 0);

        //in-place reversal syntax
        std::reverse(res.begin(), res.end());

        return res;
    }
};
