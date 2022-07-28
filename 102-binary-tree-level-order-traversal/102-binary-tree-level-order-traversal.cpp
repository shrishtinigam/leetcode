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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector<int>> result;
        queue<TreeNode*> Q;
        Q.push(root);
        
        while (Q.empty() != true)
        {
            vector <int> level;
            int n = Q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* node = Q.front();
                Q.pop();
                if(node){ 
                    level.push_back(node->val);
                    Q.push(node->left);
                    Q.push(node->right);
                }
            }
            if(level.size() != 0)
                result.push_back(level);
        }
        return result;
    }
};

/*
        vector<vector<int>> x(0);
        if(root == NULL)
            return x;
        
        Q.push(root);
        int prevLevelCount = -2;
        vector <vector<int>> result(0);
        while(!Q.empty())   {
            
            TreeNode* current = Q.front();

            if(current->left != NULL){
                Q.push(current->left);
                prevLevelCount++;
            }
            if(current->right != NULL){
                Q.push(current->right);
                prevLevelCount++;
            }
            Q.pop();
            prevLevelCount--;
            if(prevLevelCount != 0){
                result[result.size()-1].push_back(current->val);
            }else{
                vector<int>r = {current->val};
                result.push_back(r);
            }
        }
        return result;
*/