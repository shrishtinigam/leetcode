// Last updated: 8/30/2025, 8:18:46 PM
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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        rec(root, diameter);
        return diameter;
    }
    int rec(TreeNode* root, int &d) 
    {
        if(!root) // If null, then diameter = 0.
            return 0;
        
        int lh = rec(root->left, d); // Find left height
        int rh = rec(root->right, d); // Find right height
        
        // Current Diameter = lh + rh
        int curr_d = lh + rh;
        // If Current Diameter > Current Maximum Diameter, update.
        d = max(d, curr_d); 

        // Diameter of the current node = max(left_diameter, right_diameter) + 1
        // i.e., longest path till now + 1 edge
        return max(lh, rh) + 1;
    }
};

  