class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    { 
        // 97 = int('a')
        int freq[26] = {0};
        for(int i = 0; i < magazine.size(); i++)
            freq[int(magazine[i]) - 97]++;
        
        for(int i = 0; i < ransomNote.size(); i++)
            freq[int(ransomNote[i]) - 97]--;
        
        for(int i = 0; i < 26; i++)
            if(freq[i] < 0)
                return false;
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