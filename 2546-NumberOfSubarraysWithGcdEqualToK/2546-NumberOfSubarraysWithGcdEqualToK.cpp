// Last updated: 8/30/2025, 8:17:47 PM
class Solution {
public:
 

    int iter(vector<int>& nums, int& k){
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            int hcf = nums[i];
            for(int j = i; j < nums.size(); j++){
                hcf = __gcd(hcf, nums[j]);
                if(hcf == k)
                    res++;
            }
        }
        return res;
    }

    int subarrayGCD(vector<int>& nums, int k) {
        if(nums.size() == 1){
            if(k == nums[0]){
                return 1;
            }
            return 0;
        }
        
        int res = 0;
        res = iter(nums, k);
        return res;
    }
};