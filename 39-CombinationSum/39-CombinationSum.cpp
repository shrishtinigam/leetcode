// Last updated: 8/30/2025, 8:21:00 PM
class Solution {
public:

    void dfs(int i, vector <int> cur, int total, vector<vector<int>> &res, int &target, vector <int> &candidates){
        if(total == target){
            res.push_back(cur);
            return;
        }

        if(i >= candidates.size() or total > target)
            return;
        
        cur.push_back(candidates[i]);
        dfs(i, cur, total + candidates[i], res, target, candidates);
        cur.pop_back();
        dfs(i + 1, cur, total, res, target, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        dfs(0, {}, 0, res, target, candidates);
        return res;
    }
};
    
    