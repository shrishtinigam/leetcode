// Last updated: 8/30/2025, 8:19:07 PM
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> nums3;
        sort(nums1.begin(), nums1.end());        
        sort(nums2.begin(), nums2.end());  
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(nums3));
        return nums3;
    }
};