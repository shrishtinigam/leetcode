// Last updated: 8/30/2025, 8:20:16 PM
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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        
        if(!p and !q)
            return true;

        if(!p or !q or p->val != q->val)
            return false;

        return (isSameTree(p->right, q->right) and isSameTree(p->left, q->left));
        
    }
};