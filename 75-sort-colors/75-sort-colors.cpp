class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1, mid = 0; 
        while (mid <= hi) { 
            switch (nums[mid]) {
            case 0: 
                swap(nums[lo++], nums[mid++]); 
                break; 
            case 1: 
                mid++; 
                break; 
            case 2: 
                swap(nums[mid], nums[hi--]); 
                break; 
            }
        }
    }
};

/*
    void sortColors(vector<int>& nums) {
        int twos = 0, ones = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 2)
                twos++;
            else if(nums[i] == 1)
                ones++; 
            else
                nums[i - twos - ones] = 0;
        }
        for(int i = nums.size() - twos - ones; i < nums.size() - twos; i++)
           nums[i] = 1; 
        for(int i = nums.size() - twos; i < nums.size(); i++)
           nums[i] = 2; 
    }
*/