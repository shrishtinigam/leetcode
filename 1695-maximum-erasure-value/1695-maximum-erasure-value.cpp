class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
        
    {
        unordered_map <int, bool> umap;
        int max_res = 0;
        int curr = 0;
        int i = 0;
        int j = 0;
        while(j < nums.size())
        {
            while(umap.find(nums[j]) != umap.end())
            {
                curr -= nums[i];
                umap.erase(nums[i]);
                i++;
            }
            umap[nums[j]] = true;
            curr += nums[j];
            max_res = max (max_res, curr);
            j++;
        }
        return max_res;
    }
};