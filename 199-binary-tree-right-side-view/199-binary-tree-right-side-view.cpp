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
    vector<int> rightSideView(TreeNode* root) {
        vector <int> result;
        queue<TreeNode*> Q;
        Q.push(root);
        
        while (Q.empty() != true)
        {
            int level = -101;
            int n = Q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = Q.front();
                Q.pop();
                if(node){ 
                    level = node->val;
                    Q.push(node->left);
                    Q.push(node->right);
                }
            }
            if(level != -101)
                result.push_back(level);
        }
        return result;
    }
};