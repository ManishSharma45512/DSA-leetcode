class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result; 

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true; //zigzag condition

        while (!q.empty()) {
            int size = q.size();     
            vector<int> row(size);   
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                
                int index = leftToRight ? i : (size - 1 - i);
                row[index] = curr->val;

                
                if (curr->left != nullptr) q.push(curr->left);
                if (curr->right != nullptr) q.push(curr->right);
            }

            
            leftToRight = !leftToRight;
            result.push_back(row);
        }

        return result;
    }
};
