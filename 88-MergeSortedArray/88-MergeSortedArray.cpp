// Last updated: 8/30/2025, 8:20:22 PM
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--; k--;
            }
            else{
                nums1[k] = nums2[j];
                j--; k--;
            }
        }
        while(j>=0){
            nums1[k] = nums2[j];
            j--; k--;
        }
    }
};
/*class Solution {
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
};*/