// Last updated: 8/30/2025, 8:19:28 PM
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
       set<int> s;
       for (int i = 0; i < nums.size(); i++)
       {
           if (i > k) 
               s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) 
               return true;
           s.insert(nums[i]);
       }
       
       return false;
    }
};