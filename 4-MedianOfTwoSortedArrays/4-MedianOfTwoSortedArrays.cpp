// Last updated: 8/30/2025, 8:21:28 PM
class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // CORNER CASES
        if(nums1.size() == 0){
            if(nums2.size() % 2 != 0)
                return double (nums2[nums2.size()/2]);
            return (double (nums2[nums2.size()/2]) + double (nums2[(nums2.size()/2) - 1]))/2;
        }
        if(nums2.size() == 0){
            if(nums1.size() % 2 != 0)
                return double (nums1[nums1.size()/2]);
            return (double (nums1[nums1.size()/2]) + double (nums1[(nums1.size()/2) - 1]))/2;
        }

        // O(N+M) SOLUTION
        int nm = (nums1.size() + nums2.size());
        bool even = nm % 2 == 0;
        int c = 0, i = 0, j = 0;
        vector<double> last;
        while(c < ((nm/2) + 1)){
            if(i < nums1.size() and j < nums2.size()){
                if(nums1[i] < nums2[j]){
                    last.push_back((double)nums1[i]);
                    i++;
                    c++;
                    if(last.size()>2)
                        last.erase(last.begin());
                }else{
                    last.push_back((double)nums2[j]);
                    j++;
                    c++;
                    if(last.size()>2)
                        last.erase(last.begin());
                }
            }else if(i < nums1.size()){
                last.push_back((double)nums1[i]);
                i++;
                c++;
                if(last.size()>2)
                    last.erase(last.begin());
            }else if(j < nums2.size()){
                last.push_back((double)nums2[j]);
                j++;
                c++;
                if(last.size()>2)
                    last.erase(last.begin());
            }else{
                break;
            }
        }

        if((nums1.size()+nums2.size())%2 == 0)
            return (last[0]+last[1])/2;
        return last[1];
    }
};

/**

class Solution {
public:
    vector<int> merge(vector<int> &nums1, vector<int> &nums2){
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        vector <int> res;
        while(i < m and j < n){
            if(nums1[i] < nums2[j]){
                res.push_back(nums1[i++]);
            } else if(nums1[i] > nums2[j]){
                res.push_back(nums2[j++]);
            }else{
                res.push_back(nums1[i++]);
                res.push_back(nums2[j++]);
            }
        }
        while(i < m)
            res.push_back(nums1[i++]);
        while(j < n)
            res.push_back(nums2[j++]);

        return res;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> res = merge(nums1, nums2);
        if(res.size() % 2 != 0)
            return double (res[res.size()/2]);
        return (double (res[res.size()/2]) + double (res[(res.size()/2) - 1]))/2;
    }
};

**/