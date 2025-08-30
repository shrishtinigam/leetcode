// Last updated: 8/30/2025, 8:18:56 PM
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& I) {
        
        sort(I.begin(), I.end());
        int res = 0, pre = 0;
        for (int i = 1; i < I.size(); i++) 
        {
            if (I[i][0] < I[pre][1]) 
            {
                res++;
                if (I[i][1] < I[pre][1]) 
                    pre = i;
            }
            else 
                pre = i;
        }
        return res;
    }
};
