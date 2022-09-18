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

    TreeNode* reverseOddLevels(TreeNode* root) {
        list<TreeNode*> Q;
        Q.push_back(root);
        int odd = 0;
        while (Q.size() > 0)
        {
            if(odd == 1){
                auto i = Q.begin();
                auto j = Q.rbegin();
                int x = Q.size()/2;
                while(x--){
                    if(*i and *j){
                        int temp = (*i)->val;
                        (*i)->val = (*j)->val;
                        (*j)->val = temp;
                    }
                    i++;
                    j++;
                }
            }
            int n = Q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = Q.front();
                Q.pop_front();
                if(node){ 
                    if(node->left)
                        Q.push_back(node->left);
                    if(node->right)
                        Q.push_back(node->right);
                }
            }
            odd = (odd == 0) ? 1 : 0;
        }
        return root;
    }
};