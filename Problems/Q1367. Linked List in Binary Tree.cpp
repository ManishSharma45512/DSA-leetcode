/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
private:
    bool checkPath(TreeNode* treeNode, ListNode* listNode) {
        if (listNode == nullptr) return true;
        if (treeNode == nullptr) return false;
        
        if (treeNode->val == listNode->val) {
            return checkPath(treeNode->left, listNode->next) || 
                   checkPath(treeNode->right, listNode->next);
        }
        
        return false;
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false; // Tree is empty but list is not
        
        //root=head
        if (checkPath(root, head)) return true;
        
        // check left and right subtree
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
