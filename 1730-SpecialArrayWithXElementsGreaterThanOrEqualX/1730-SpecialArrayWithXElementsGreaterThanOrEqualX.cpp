// Last updated: 8/30/2025, 8:18:11 PM
class Solution {
public:
    int specialArray(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cur = 0;
        for(int x = 0; x <= n; ++x)
        {
            while(cur < n && nums[cur] < x)
                ++cur;
            cout << x << " : " << n-cur << endl;
            if(n-cur == x) return x;
        }
        return -1;
    }
};