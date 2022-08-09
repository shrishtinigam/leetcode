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

// O(n)
class Solution {
public:
      bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
      }

    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) 
    {
        if(!root) 
            return true;
        if(minNode and root->val <= minNode->val or maxNode and root->val >= maxNode->val)
            return false;
        return isValidBST(root->left, minNode, root) and isValidBST(root->right, root, maxNode);
    }
};