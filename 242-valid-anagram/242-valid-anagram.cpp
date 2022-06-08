class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> counts (26, 0);
        vector <int> countt (26, 0);
        for(int i = 0; i < s.length(); i++)
            counts[int(s[i]) - 97]++;

        for(int i = 0; i < t.length(); i++)
            countt[int(t[i]) - 97]++;
        
        if(counts == countt)
            return true;
        return false;
    }
};