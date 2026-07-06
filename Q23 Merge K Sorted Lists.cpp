class Solution {
    
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

private:
    unordered_map<TreeNode*, int> heightMap;

    int getHeight(TreeNode* node) {
        if (!node) return 0;
        return heightMap.count(node) ? heightMap[node] : 1;
    }

    int getBalanceFactor(TreeNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    void updateHeight(TreeNode* node) {
        if (node) {
            heightMap[node] = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x; 
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y; 
    }

    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }

public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }

    TreeNode* insertAVL(TreeNode* node, int val) {
        if (!node) {
            TreeNode* newNode = new TreeNode(val);
            heightMap[newNode] = 1;
            return newNode;
        }

        if (val < node->val) {
            node->left = insertAVL(node->left, val);
        } else if (val > node->val) {
            node->right = insertAVL(node->right, val);
        } else {
            // Note: AVL trees handle duplicates poorly without frequency counters.
            // For now, to keep your structure intact, we can insert duplicates to the left.
            node->left = insertAVL(node->left, val);
        }

        updateHeight(node);
        int balance = getBalanceFactor(node);

        if (balance > 1 && val <= node->left->val) {
            return rightRotate(node);
        }
        if (balance < -1 && val > node->right->val) {
            return leftRotate(node);
        }
        if (balance > 1 && val > node->left->val) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && val <= node->right->val) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }


//------------------------------------------------------------------XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX--------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//QUESTIONS START FROM HERE:
//                         APPROACH: ALL LIST->BST USING AVL METHOD->INORDER TRAVERSAL FOR SORTED ARRAY----(TRANSFORMATION ARRAY->LINKED LIST)
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr; 

        TreeNode* res = nullptr;

        
        for(ListNode* headNode : lists){
            ListNode* curr = headNode;
            while(curr != nullptr) {
                res = insertAVL(res, curr->val); 
                curr = curr->next;
            }
        }

        vector<int> vals = inorderTraversal(res); 

        
        ListNode* dummy = new ListNode(0); 
        ListNode* current_ptr = dummy;

        for(int i = 0; i < vals.size(); i++){
            current_ptr->next = new ListNode(vals[i]);
            current_ptr = current_ptr->next;
        }

        ListNode* actual_head = dummy->next;
        delete dummy; 
        return actual_head;
    }
};
