// Last updated: 8/30/2025, 8:18:17 PM
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector <int> noOfSoldiers;
        vector <int> noOfSoldiersCopy;
        int rows = mat.size();
        int cols = mat[0].size();
        for(int i = 0; i < rows; i++)
        {
            int x = accumulate(mat[i].begin(), mat[i].end(), 0);
            noOfSoldiers.push_back(x);
            noOfSoldiersCopy.push_back(x);
        }
        sort(noOfSoldiers.begin(), noOfSoldiers.end());
        vector <int> result;
        for(int i = 0; i < k; i++)
        {
            int index;
            for(int j = 0; j < rows; j++)
            {
                if(noOfSoldiers[i] == noOfSoldiersCopy[j])
                {
                    noOfSoldiersCopy[j] = -1;
                    index = j;
                    break;
                }
            }
            result.push_back(index);
        }
        return result;
    }
};