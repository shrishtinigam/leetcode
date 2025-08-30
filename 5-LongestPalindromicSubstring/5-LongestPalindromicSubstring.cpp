// Last updated: 8/30/2025, 8:21:27 PM
class Solution {
public:
    string longestPalindrome(string s) {
        
        // edge cases
        if(s.length() == 0 || s.length() == 1) return s;
        
        // to hold max len and its starting index
        int maxLenBeginIndex = 0;
        int maxLen = 1;
        
        int mid = 0;
        while(mid < s.length()){
            
            // calculating middle window
            
            int midBegin = mid;
            int midEnd = mid;
            
            // handling even length palindromes; the middlemost chars will trivially match in even length case
            // so expand the middle window as long as possible
            while( midEnd + 1 < s.length() && s[midEnd] == s[midEnd + 1]){ midEnd++ ; }
            
            // for next iteration
            mid = midEnd + 1;
            
            // starting comparison in left and right windows
            
            // in case of odd len palindrome; both start from mid;
            // in case of even; midBegin and midEnd handles it all
            int leftWindow = midBegin;
            int rightWindow = midEnd;
            
            // expand the windows left and right simultaneously
            while(leftWindow - 1 >= 0 && rightWindow + 1 < s.length() && s[leftWindow - 1] == s[rightWindow + 1]){
                    leftWindow--;
                    rightWindow++;
            }
            
            // update maxLen is currLen > maxLen
            int currLen = rightWindow - leftWindow + 1;
            if( currLen  > maxLen ){
                maxLenBeginIndex = leftWindow;
                maxLen = currLen;
            }
        }
        
        return s.substr(maxLenBeginIndex, maxLen);
    }
        
};

/* DYNAMIC PROGRAMMING METHOD

class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        if (n == 0)
            return "";

        // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
        bool dp[n][n];

        //Initialize with false

        memset(dp, 0, sizeof(dp));

        //Every Single character is palindrome
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        string ans = "";
        ans += s[0];

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    //If it is of two character OR if its susbtring is palindrome.
                    if (j - i == 1 || dp[i + 1][j - 1])
                    {
                        //Then it will also a palindrome substring
                        dp[i][j] = true;

                        //Check for Longest Palindrome substring
                        if (ans.size() < j - i + 1)
                            ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return ans;
    }
        
};
*/