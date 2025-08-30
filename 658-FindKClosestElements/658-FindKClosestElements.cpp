// Last updated: 8/30/2025, 8:18:39 PM
class Solution {
public:

    vector<int> findClosestElements(vector<int>& A, int k, int x) {
        int left = 0, right = A.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - A[mid] > A[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(A.begin() + left, A.begin() + left + k);
    

    }

    /*vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> max_heap;
        int n = arr.size();
        for(int i = 0 ; i < n; i++){
            max_heap.push({abs(arr[i]-x), arr[i]});
            if(max_heap.size() > k){
                max_heap.pop();
            }
        }

        vector<int> res;
        for(int i = 0; i < k; i++){
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }*/
};