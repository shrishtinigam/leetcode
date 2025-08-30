// Last updated: 8/30/2025, 8:19:56 PM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int arr[60002] = {0};
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            x = x + 30000;
            arr[x]++;
        }

        for(int i = 0; i < 60002; i++){
            if(arr[i] == 1)
                return i-30000;
        }
        return -1;
    }

    int singleNumber2(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

        int ans = 0;
        for(int num : nums){
            ans = ans ^ num;
        }
        return ans;
    }
};