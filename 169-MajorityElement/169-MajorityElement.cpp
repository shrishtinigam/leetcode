// Last updated: 8/30/2025, 8:19:38 PM
// Boyer-Moore's Algorithm
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(count == 0)
                res = nums[i];
            count += (nums[i] == res) ? 1 : -1;
        }
        return res;
    }
};*/

// Bit manipulation method
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bits = 0;
            for (int num : nums) {
                if (num & mask) {
                    bits++;
                }
            }
            if (bits > nums.size() / 2) {
                majority |= mask;
            }
        }
        return majority;
    }
};
/*
int majorityElement(vector<int>& nums) {
        // Boyer-Moore's Algorithm
        int count = 1;
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == result)
                count++;
            else
                count--;

            if(count < 0){
                result = nums[i];
                count = 0;
            }
        }
        return result;
    }
*/