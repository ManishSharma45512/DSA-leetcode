class Solution {
public:
    
    void traverse(TreeNode* root, stack<TreeNode*>& s) {
        if (root == nullptr) return;

        s.push(root);              // Root
        traverse(root->left, s);    // Left
        traverse(root->right, s);   // Right
    }

    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        
        stack<TreeNode*> s1;
        traverse(root, s1);

        // s2 flips s1 
        stack<TreeNode*> s2;
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        
        TreeNode* temp = root;
        
        // Pop the root out of s2 because 'temp' is already pointing to it
        if (!s2.empty()) {
            s2.pop();
        }

        // Stitch everything together into a right-only skewed chain
        while (!s2.empty()) {
            temp->left = nullptr;       
            temp->right = s2.top();     
            s2.pop();
            
            temp = temp->right;        
        }

        
        temp->left = nullptr;
        temp->right = nullptr;
    }
};
