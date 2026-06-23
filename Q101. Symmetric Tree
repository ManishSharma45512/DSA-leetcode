class Solution {

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // Base case: if both are null, they are symmetric mirrors
        if (t1 == nullptr && t2 == nullptr) return true;
        
        // If only one is null, they cannot be mirrors
        if (t1 == nullptr || t2 == nullptr) return false;
        
        //if both values are same they are symmetric but we take AND to get total symmetric is present or not
        return (t1->val == t2->val) 
            && isMirror(t1->left, t2->right) 
            && isMirror(t1->right, t2->left);
    }


public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        
        
        return isMirror(root->left, root->right);
    }


};
