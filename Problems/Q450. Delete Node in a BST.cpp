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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base Case
        if (root == nullptr) {
            return nullptr;
        }

        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 


        //Deletion Phase :  Node is Found!!
        else {
            
            if (root->left == nullptr) {//have Right child
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) { //have Left child
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            //delete Node have two kids
            TreeNode* successor = root->right;
            while (successor->left != nullptr) {
                successor = successor->left;
            }

            
            root->val = successor->val;

            
            root->right = deleteNode(root->right, successor->val);
        }

        return root;
    }
};
