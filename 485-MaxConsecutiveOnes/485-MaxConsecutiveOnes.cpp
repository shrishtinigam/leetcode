// Last updated: 8/30/2025, 8:18:54 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_cnt = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                cnt++;
            else
                cnt = 0;
            max_cnt = max(cnt, max_cnt);
        }
        return max_cnt;
    }
};