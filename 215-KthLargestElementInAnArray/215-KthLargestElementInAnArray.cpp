// Last updated: 8/30/2025, 8:19:30 PM
/*
class Solution {
public:

    int partition(vector<int> &nums, int left, int right){
        int pivot = nums[left], l = left + 1, r = right;
        while(l <= r){
            if(nums[l] < pivot and nums[r] > pivot){
                swap(nums[l++], nums[r--]);
            }
            if(nums[l] >= pivot){
                l++;
            }
            if(nums[r] <= pivot){
                r--;
            }
        }
        swap(nums[left], nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, kth;
        while (true) {
            int idx = partition(nums, left, right);
            if (idx == k - 1) {
                kth = nums[idx];
                break;
            }
            if (idx < k - 1) {
                left = idx + 1;
            } else {
                right = idx - 1;
            }
        }
        return kth;
    }
};

/*
int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return 0;
}();

//MERGESORT ALGORITHM

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + nums.size() - k,nums.end());
        return nums[nums.size() - k];
    }
};
*/
int speed_up = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    return 0;
}();

//MERGESORT ALGORITHM

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(),nums.begin()+k-1,nums.end(),std::greater<int>());
        return nums[k-1];
    }
};
