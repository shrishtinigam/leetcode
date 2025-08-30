// Last updated: 8/30/2025, 8:20:07 PM
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result(1);
        result[0] = {1};
        for(int i = 1; i < numRows; i++)
        {
            vector <int> cur(2,1); 
            for(int j = 1; j < i; j++)
                cur.insert(cur.begin() + j, result[i - 1][j - 1] + result[i - 1][j]);
            result.push_back(cur);
        }
        return result;
    }
};