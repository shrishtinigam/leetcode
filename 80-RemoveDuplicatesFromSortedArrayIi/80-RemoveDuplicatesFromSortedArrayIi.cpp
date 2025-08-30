// Last updated: 8/30/2025, 8:20:27 PM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) 
        return nums.size();

        int count = 1, j = 1;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] == nums[i]) 
                count++;
            else 
                count = 1;
            if(count <= 2) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }

    /* SENTINEL VALUES - WORKS FOR UNSORTED ARRAYS AS WELL */

    /*
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int count = 1;
            if(nums[i] == INT_MIN)
                continue;
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] == nums[j])
                    count++;
                if(count > 2){
                    nums[i] = INT_MIN;
                    count--;
                }
            }
        }
        int c = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == INT_MIN)
                c++;
            else{
                nums[i-c] = nums[i];
            }
        }

        return nums.size() - c;
    }
    */

};