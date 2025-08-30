// Last updated: 8/30/2025, 8:20:13 PM
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int n = q.size();
        vector<int> row(n);

        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();
            // find position to fill node's value
            int index = (leftToRight) ? i : (n - 1 - i);
            row[index] = node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}
};