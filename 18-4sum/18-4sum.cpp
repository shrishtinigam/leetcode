// Last updated: 8/30/2025, 8:21:19 PM
class Solution {
public:

    void kSum(vector <int> & nums, vector<vector<long long>> & res, vector <long long> curr, long long k, long long start, long long target){
        if(k != 2){
            for(long long i = start; i < nums.size() - k + 1; i++){
                if(i > start and nums[i] == nums[i-1])
                    continue;
                curr.push_back(nums[i]);
                kSum(nums, res, curr, k-1, i+1, target-nums[i]);
                curr.pop_back();
            }
        }else{
            long long l = start, r = nums.size()-1;
            while(l < r){
                if(nums[l] + nums[r] < target)
                    l++;
                else if(nums[l] + nums[r] > target)
                    r--;
                else{
                    curr.push_back(nums[l]);
                    curr.push_back(nums[r]);
                    res.push_back(curr);
                    curr.pop_back();
                    curr.pop_back();
                    l++;
                    while(l < r and nums[l] == nums[l-1])
                        l++;
                }
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<long long>> res;
        vector<vector<int>> ac_res;
        if(nums.size() < 4)
            return ac_res;
        vector<long long>temp;
        kSum(nums, res, temp, 4, 0, target);
        
        for(int i = 0; i < res.size(); i++){
            vector <int> temp2;
            for(int j = 0; j < res[i].size(); j++){
                
                temp2.push_back((int) res[i][j]);

            }
            ac_res.push_back(temp2);
        }
        return ac_res;
    }
};