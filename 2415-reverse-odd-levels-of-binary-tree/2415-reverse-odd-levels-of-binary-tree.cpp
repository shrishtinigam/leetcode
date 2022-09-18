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
        int level = 0; 
        queue<TreeNode*> q; 
        q.push(root); 
        while (q.size()) {
            vector<TreeNode*> vals; 
            for (int sz = q.size(); sz; --sz) {
                TreeNode* node = q.front(); q.pop(); 
                vals.push_back(node); 
                if (node->left) q.push(node->left); 
                if (node->right) q.push(node->right); 
            }
            if (level&1) {
                for (int i = 0, n = vals.size(); i < n/2; ++i) {
                    swap(vals[i]->val, vals[n-1-i]->val); 
                }
            }
            level ^= 1; 
        }
        return root; 
    }
};

/*
DFS
class Solution {
private:
    void reverse(TreeNode* rootL, TreeNode* rootR, int level) {
        if(rootL == NULL and rootR == NULL) return;
        if(level % 2 == 0) swap(rootL->val, rootR->val);
        reverse(rootL->left, rootR->right, level + 1);
        reverse(rootL->right, rootR->left, level + 1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse(root->left, root->right, 0);
        return root;
    }
};



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
*/