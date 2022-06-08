class Solution {
public:
    bool isAnagram(string s, string t) {
        // Frequency counting of characters will help to determine if two strings are anagrams.
        // This takes O(n) time and O(1) space.
        vector <int> counts (26, 0), countt (26, 0);
        
        for(int i = 0; i < s.length(); i++)
            counts[int(s[i]) - 97]++;

        for(int i = 0; i < t.length(); i++)
            countt[int(t[i]) - 97]++;
        
        if(counts == countt)
            return true;
        return false;
    }
};