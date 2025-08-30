// Last updated: 8/30/2025, 8:21:31 PM

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
        {
            unordered_map<int, int> indices;
            for (int i = 0; i < nums.size(); i++) {
                if (indices.find(target - nums[i]) != indices.end()) {
                    return {indices[target - nums[i]], i};
                }
                indices[nums[i]] = i;
            }
            return {};
        }
    
};

/*
        int linearsearch(vector<int> nums, int start, int x)
        {
            for(int i = start; i < nums.size(); i++)
                if(nums[i] == x)
                    return i;
            return -1;
        }
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            vector<int> x = nums;        
            sort(x.begin(), x.end());
            int a = 0, b = x.size() - 1;

            while(a < b)
            {
                if(x[a] + x[b] == target)
                    break;
                if(x[a] + x[b] > target)
                    b--;
                else
                    a++;
            }
            a = x[a];
            b = x[b];
            int a_i = linearsearch(nums, 0, a);
            int b_i = 0;
            if(a == b)
                b_i = linearsearch(nums, a_i + 1, b);
            else
                b_i = linearsearch(nums, 0, b);
            vector <int> ans = {a_i, b_i};
            return ans;
        }
*/