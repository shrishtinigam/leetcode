class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int sa_sum = sum - x; // sub array sum
        int curr_sum = 0, left = 0;
        int maxwinlen = -1;
        
        for(int right = 0; right < nums.size(); right++)
        {
            curr_sum += nums[right];
            
            // remove elements from the left of the window if current sum exceeds the required subarray sum
            while(left <= right and curr_sum > sa_sum)
                curr_sum -= nums[left++]; 
            
            // if current subarray sum is equal to required subarray sum, check if the length of this subarray is greater than any previous subarray that also satisfied the requirement. If it is greater, then update the maximum window length.
            if(curr_sum == sa_sum)
                maxwinlen = max(maxwinlen, right - left + 1);
        }
        
        // We take the maximum window length as it returns the minimum operations required.
        return (maxwinlen == -1) ? -1 : nums.size() - maxwinlen;
    }
};