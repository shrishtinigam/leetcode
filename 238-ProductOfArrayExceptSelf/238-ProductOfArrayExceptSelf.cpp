// Last updated: 8/30/2025, 8:19:18 PM
class Solution {
public:
    
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int is_zero = -1;
        int is_two_zero = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                is_zero = i;
            }

            else if(is_zero != -1 and nums[i] == 0){
                vector <int> x (nums.size(), 0);
                return x;
            }
        }
        int m = accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
        if(is_zero != -1){
            int m1 = 1;
            for(int i = 0; i < nums.size(); i++){
                if(i != is_zero){
                    m1 *= nums[i];
                }
            }
            vector <int> x (nums.size(), 0);
            x[is_zero] = m1;
            return x;
        }
        for(int i = 0; i < nums.size(); i++){
            nums[i] = m/nums[i];
        }
        return nums;
    }
};