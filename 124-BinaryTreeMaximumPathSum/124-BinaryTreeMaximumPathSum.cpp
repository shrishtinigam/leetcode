// Last updated: 8/30/2025, 8:20:04 PM
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
    int curMax = 0;
    int maxPathSumUtil(TreeNode * root){
        if(root == NULL)
            return 0;
        int rightMax = max( maxPathSumUtil(root->right) , 0);
        int leftMax = max( maxPathSumUtil(root->left) , 0);
        
        curMax = max(curMax, root->val + leftMax + rightMax);
        return root->val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode * root){
        if(root == NULL)
            return 0;
        curMax = root->val;
        maxPathSumUtil(root);
        return curMax;
    }
};