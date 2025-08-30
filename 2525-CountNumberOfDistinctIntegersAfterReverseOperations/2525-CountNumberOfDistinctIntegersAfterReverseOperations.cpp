// Last updated: 8/30/2025, 8:17:44 PM
class Solution {
public:
    int reverseOperation(int n){
        int rem, res = 0;
         while(n != 0) {
            rem = n % 10;
            res = res * 10 + rem;
            n /= 10;
        }
        return res;
    }
    int countDistinctIntegers(vector<int>& nums) {
        set <int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
            s.insert(reverseOperation(nums[i]));
        }
        return s.size();
    }
};