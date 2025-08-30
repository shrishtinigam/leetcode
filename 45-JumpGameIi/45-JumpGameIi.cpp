// Last updated: 8/30/2025, 8:20:56 PM
class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, l = 0, r = 0;

        while(r < nums.size()-1){
            int farthest = 0;
            for(int i = l; i <= r; i++){
                farthest = max(farthest, nums[i]+i);
            }
            l = r+1;
            r = farthest;
            res +=1;   
        }
        return res;
    }
};

















/**
int jump(vector<int>& nums) {
        int res = 0;
        int l = 0, r = 0;

        while(r < nums.size() - 1){
            int farthest = 0;
            for(int i = l; i <= r; i++)
                farthest = max(farthest, i + nums[i]);
            l = r + 1;
            r = farthest;
            res += 1;
        }

        return res;
    }
**/