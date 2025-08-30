// Last updated: 8/30/2025, 8:20:47 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int goal = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            if(i + nums[i] >= goal){
                goal = i;
            }
        }
        if(goal == 0)
            return true;
        return false;
        /*int res = 0;
        int l = 0, r = 0;

        while(r < nums.size() - 1){
            int farthest = 0;
            for(int i = l; i <= r; i++){
                farthest = max(farthest, i + nums[i]);
            }
            if(r >= farthest)
                return false;
            l = r + 1;
            r = farthest;
        }

        return true;*/
    }
};