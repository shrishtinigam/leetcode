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
        if((p != NULL and q == NULL) or (p == NULL and q != NULL))
            return false;
        if(p == NULL and q == NULL)
            return true;
        if(p->val != q->val)
            return false;
        if(isSameTree(p->right, q->right) and isSameTree(p->left, q->left))
            return true;
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if((root != NULL and subRoot == NULL) or (root == NULL and subRoot != NULL))
            return false;

        if(root->val == subRoot->val and isSameTree(root, subRoot))
            return true;
        return ( isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot));
    }
};