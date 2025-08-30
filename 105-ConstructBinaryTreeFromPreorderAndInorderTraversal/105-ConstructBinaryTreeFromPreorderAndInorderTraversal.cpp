// Last updated: 8/30/2025, 8:20:11 PM
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
 
 Watch https://youtu.be/ihj4IQGZ2zc
 */
class Solution {
public:

    void build(TreeNode* &root, int s, int e) {
        if (s > e) return;
        
        int v = pre[idx++]; // new Node
        int m = um[v]; // middle node's index

        root = new TreeNode(v);

        build(root->left, s, m-1);
        build(root->right, m+1, e);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        
        for (int i = 0 ; i < inorder.size(); i++) 
            um[inorder[i]] = i;
        
        pre = preorder;
        
        build(root, 0, inorder.size()-1);
        return root;
    }
private:
    unordered_map<int, int> um;
    vector<int> pre;
    int idx = 0;
};