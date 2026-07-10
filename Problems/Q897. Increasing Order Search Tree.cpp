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
class Solution {
public:
    void helper(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        helper(root->left, result);       // 1. Traverse Left Subtree
        result.push_back(root->val);      // 2. Visit Root Node
        helper(root->right, result);      // 3. Traverse Right Subtree
    }

    TreeNode* increasingBST(TreeNode* root) {
        if(root==nullptr) return root;//Base Case

        vector<int> result;

        helper(root,result);

        TreeNode* answer=new TreeNode(0);
        

        TreeNode* temp=answer;

        for(int i=0;i<result.size();i++){
            temp->right=new TreeNode(result[i]);
            temp=temp->right;
        }

        TreeNode* mainHead=answer->right;
        delete answer;

        return mainHead;

    }
};
