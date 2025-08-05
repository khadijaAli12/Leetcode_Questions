// Problem: Binary Tree Right Side View
// Link: https://leetcode.com/problems/binary-tree-right-side-view/
// Tags: Tree, DFS, BFS, Binary Tree
// Approach: DFS (preorder) with level tracking – right subtree first.

class Solution {
    public:
        // DFS Helper: Traverse right first, then left, recording the first node seen at each level
        void preorder(vector<int>& res, int level, TreeNode* node) {
            if (node == nullptr) return;
            
            if (res.size() < level) {
                res.push_back(node->val); // first node seen at this level
            }
    
            preorder(res, level + 1, node->right);
            preorder(res, level + 1, node->left);
        }
    
        vector<int> rightSideView(TreeNode* root) {
            // ******** DFS ********
            vector<int> res;
            preorder(res, 1, root);
            return res;
    
            /*
            // ******** BFS Alternative ********
            vector<int> res;
            if (!root) return res;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty()) {
                int n = q.size();
                TreeNode* node = nullptr;
                for (int i = 0; i < n; i++) {
                    node = q.front(); q.pop();
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                res.push_back(node->val); // last node in level
            }
            return res;
            */
        }
    };
    