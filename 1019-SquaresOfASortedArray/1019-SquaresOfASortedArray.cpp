// Last updated: 8/30/2025, 8:18:24 PM
class Solution {
public:
    
    static int sqr(int x) {  return (x*x); }
    vector<int> sortedSquares(vector<int>& nums) {
         transform(nums.begin(), nums.end(), nums.begin(), sqr);
         sort(nums.begin(), nums.end());
         return nums;
    }
};