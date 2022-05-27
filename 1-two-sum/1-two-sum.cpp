
class Solution {
public:
    #include <algorithm>
    int binarysearch(vector<int> nums, int l, int x)
    {
        int r = nums.size() - 1;
        while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == x)
            return m;
        if (nums[m] < x)
            l = m + 1;
        else
            r = m - 1;
        }
        return -1;
    }
    int linearsearch(vector<int> nums, int start, int x)
    {
        for(int i = start; i < nums.size(); i++)
            if(nums[i] == x)
                return i;
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> x = nums;        
        vector<int> y = nums;

        sort(x.begin(), x.end());
        int a, b;
        for(int i = 0; i < x.size(); i++)
        {
            if(binarysearch(x, i + 1, target - x[i]) != -1)
            {
                a = x[i];
                b = target - a;
                break;
            }
        }
        int a_i = linearsearch(nums, 0, a);
        int b_i = 0;
        if(a == b)
            b_i = linearsearch(nums, a_i + 1, b);
        else
            b_i = linearsearch(nums, 0, b);
        vector <int> ans = {a_i, b_i};
        return ans;
    }
};