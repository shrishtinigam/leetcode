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
/* Find root to P path and root to Q path. The last common node is LCA */
class Solution {
public:
    
    // Finding the path in an array by dfs and backtracking
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

/*
class Solution {
public:
   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
    }
};*/