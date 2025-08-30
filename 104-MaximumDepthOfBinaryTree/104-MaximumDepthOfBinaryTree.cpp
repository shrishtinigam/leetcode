// Last updated: 8/30/2025, 8:20:14 PM
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
    int maxDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};


/*
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(root == NULL){
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
*/