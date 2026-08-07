/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void helper(Node* root,vector<int>& p){
        if(root==nullptr) return;//Base Case

        for(Node* child : root->children){
            helper(child,p);//first childs
        }

        p.push_back(root->val);//at last parent
    }


public:
    vector<int> postorder(Node* root) {
        vector<int> p;

        helper(root,p);
        return p;
    }
};
