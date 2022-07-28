/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* cur = root;
        
        while (true)
            if (p->val < cur->val and q->val < cur->val) // if the values in p and q are less than value in cur 
                cur = cur -> left; // search the left subtree
            else if (p->val > cur->val and q->val > cur->val) // if the values in p and q are greater than value in cur 
                cur = cur -> right; // search the right subtree
            else 
                break;
        
        return cur;
    }
            
};

