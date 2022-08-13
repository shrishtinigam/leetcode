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
    
    int kthSmallest(TreeNode* root, int k) {
        vector <int> v;
        Inorder(root, v, k);
        return v[k-1];
    }
    
    void Inorder(TreeNode* root, vector<int> &v, int &k){
        if(!root)
            return;
        if(v.size() > k)
            return;
        Inorder(root->left, v, k);
        v.push_back(root->val);
        Inorder(root->right, v, k);
    }
    
};

/* ALSO WORKS
void Inorder(TreeNode* root, vector<int> &v, int &k){
        if(!root)
            return;
        Inorder(root->left, v, k);
        v.push_back(root->val);
        if(v.size() > k)
            return;
        Inorder(root->right, v, k);
    }
*/