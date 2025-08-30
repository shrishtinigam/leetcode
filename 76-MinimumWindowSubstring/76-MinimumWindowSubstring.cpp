// Last updated: 8/30/2025, 8:20:30 PM
class Solution {
public:
    string minWindow(string s, string t) 
    {
        vector<int> m(128, 0);
        // Statistic for count of char in t
        for (auto c : t) m[c]++;
        // counter represents the number of chars of t to be found in s.
        int left = 0, right = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
        int size = s.size();

        // Move right to find a valid window.
        while (right < size) 
        {
            // If char in s exists in t, decrease counter
            if (m[s[right]] > 0)
                counter--;
            
            // Decrease m[s[right]]. If char does not exist in t, m[s[right]] will be negative.
            m[s[right]]--;
            right++;
            
            // When we found a valid window, move left to find smaller window.
            while (counter == 0) 
            {
                if (right - left < minLen) 
                {
                    minStart = left;
                    minLen = right - left;
                }
                m[s[left]]++;
                // When char exists in t, increase counter.
                if (m[s[left]] > 0)
                    counter++;
                
                left++;
            }
        }
        
        if (minLen != INT_MAX)
            return s.substr(minStart, minLen);
        return "";
    }
};