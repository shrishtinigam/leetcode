class Solution {
public:
    int characterReplacement(string s, int k) {
        
        // res is the length of the largest window we can find. 
        // The largest window we can find has this property: res = maxf + k
        // maxf is the max frequency of any character we have seen so far.
        int res = 0, maxf = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < s.length(); i++) {
            maxf = max(maxf, ++count[s[i]]);
            if (res - maxf < k)
                res++;
            else
                count[s[i - res]]--; // decreasing the count of the characters that are now outside the window
        }
        return res;
    }
};