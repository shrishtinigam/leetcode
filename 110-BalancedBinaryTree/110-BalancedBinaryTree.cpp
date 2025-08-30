// Last updated: 8/30/2025, 8:20:09 PM
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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(height(root) == -1)
            return false;
        return true;
    }

    int height(TreeNode *root){
        if(!root)
            return 0;
        int rd = height(root->right);
        int ld = height(root->left);
        if(ld == -1 or rd == -1)
            return -1;
        if(abs(rd - ld) > 1)
            return -1;
        return 1 + max(ld, rd);
    }
        
};

/*
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // depth of the right subtree
        if(!root)
            return true;
        int rd = depth(root->right);
        int ld = depth(root->left);
        if(abs(rd - ld) > 1)
            return false;
        return isBalanced(root->right) and isBalanced(root->left);
    }
        
    int depth(TreeNode* root){
        if(!root)
            return 0;
        return max(depth(root->right)+1, depth(root->left)+1);
    }
};
*/