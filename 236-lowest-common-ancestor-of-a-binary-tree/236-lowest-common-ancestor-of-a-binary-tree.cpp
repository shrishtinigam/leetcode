/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* Method - 1 */
/* TC - O(n)*/
/* SC - O(h = worst case O(n) -> (not sure) */

/* Find root to P path and root to Q path. The last common node is LCA */
/*
class Solution {
public:
    
    // Finding the path from root to node and storing it in a vector (by dfs and backtracking)
    bool pathFinder(TreeNode* root, TreeNode* p, vector <TreeNode*> * result){
        if(!root)
            return false;
        result->push_back(root);
        if(root == p)
            return true;
        if (pathFinder(root->left, p, result) or pathFinder(root->right, p, result))
            return true;
        result->pop_back();
        return false; 
    }
    
    // Finding the Lowest Common Ancestor using the paths
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        vector <TreeNode*> pPath, qPath = {};
        pathFinder(root, p, &pPath);
        pathFinder(root, q, &qPath);
  
        int n = min(pPath.size(), qPath.size()), i = 1;
        while(i < n){
            if(pPath[i] != qPath[i])
                break;
            i++;
        }
        return pPath[i-1];
    }
};
*/

/* Method - 2 */
/* TC - O(n) */
/* SC - O(1) */
/* Recursion - The node receiving TRUE from both children is the LCA */
class Solution {
public:
   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==NULL) 
            return NULL;
        if(root == p or root == q)
           return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left and right)
            return root;
        
        return left == NULL? right : left;
    }
};