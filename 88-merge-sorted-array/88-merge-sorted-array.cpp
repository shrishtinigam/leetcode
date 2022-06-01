class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = 0, k1 = 0, k2 = 0;
        vector <int> temp(m + n);
        while(k1 < m && k2 < n)
        {
            if(nums1[k1] <= nums2[k2])
                temp[k++] = nums1[k1++];
            else
                temp[k++] = nums2[k2++];
        }
        while(k1 < m)
            temp[k++] = nums1[k1++];
        while(k2 < n)
            temp[k++] = nums2[k2++];
        for(int i = 0; i < m + n; i++)
        {
            nums1[i] = temp[i];
        }
    }
};