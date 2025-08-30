// Last updated: 8/30/2025, 8:18:05 PM
class Solution {
public:
    int minimumDeletions(vector<int>& A) {
        int a = max_element(A.begin(), A.end()) - A.begin();
        int b = min_element(A.begin(), A.end()) - A.begin();
        int N = A.size();

        if (a > b) 
            swap(a, b);

        return min({ a + 1 + N - b, b + 1, N - a });
    }
};