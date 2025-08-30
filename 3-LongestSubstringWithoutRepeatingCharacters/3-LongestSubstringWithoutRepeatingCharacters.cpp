// Last updated: 8/30/2025, 8:21:29 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>chars(128,-1);
        int max_cnt = 0;
        int l = 0, r = 0;
        while(r < s.length()){
            if(chars[s[r]] != -1)
                l = max(l, chars[s[r]] + 1); 
            max_cnt = max(max_cnt, r - l + 1);
            chars[s[r]] = r;
            r++;
        }
        return max_cnt;
    }
};

/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // we will store a senitel value of -1 to simulate 'null'/'None' in C++
        vector<int> chars(128, -1);

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char r = s[right]; // current character

            int index = chars[r]; // last time the character appeared in the string
            
            // decrease window size from left if the new character is already present within the window
            if (index != -1 and index >= left) {
                left = index + 1;
            }
            
            // result is max of current window size and max window size up till now
            res = max(res, right - left + 1);
            
            // save the position at which the character appeared
            chars[r] = right;
            
            // increase window size from right
            right++;
        }
        return res;
    }
};
*/