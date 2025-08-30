// Last updated: 8/30/2025, 8:19:01 PM
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    { 
        int hash[26] = {0};
        for(char ch : magazine) 
            hash[ch - 'a']++;
        
        for(char ch : ransomNote) 
        {
            if(hash[ch - 'a'] == 0) 
                return false;
            hash[ch - 'a']--;
        }
        return true;
    }
};

/*
unordered_map<char, int> u_map;

        for(int i = 0; i < magazine.size(); i++)
            u_map[magazine[i]]++;
        for(int i = 0; i < ransomNote.size(); i++)
            u_map[ransomNote[i]]--;
        for (auto i = u_map.begin(); i != u_map.end(); i++)
            if(i->second < 0)
                return false;
        return true;
*/