// Last updated: 8/30/2025, 8:19:09 PM
class Solution {
public:
    void reverseString(vector<char>& s) {
        int low(0), high(s.size()-1); 
        while(low<high)
            swap(s[low++],s[high--]);
        // reverse(s.begin(), s.end());
    }
};