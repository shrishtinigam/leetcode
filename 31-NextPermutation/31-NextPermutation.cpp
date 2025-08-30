// Last updated: 8/30/2025, 8:21:08 PM
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k = -1, l;
        for(k = n - 2; k >= 0; k--)
        {
            if(nums[k] < nums[k + 1])
                break;
        }
        if(k >= 0)
        {
            for(l = n - 1; l > k; l--)
                if(nums[l] > nums[k])
                    break;
            swap(nums[k], nums[l]);
        }
        reverse(nums.begin() + k + 1, nums.end());
    }
};

/*
    next_permutation(nums.begin(), nums.end());
*/