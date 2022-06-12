class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> u_map;

        for(int i = 0; i < magazine.size(); i++)
            u_map[magazine[i]]++;
        for(int i = 0; i < ransomNote.size(); i++)
            u_map[ransomNote[i]]--;
        for (auto i = u_map.begin(); i != u_map.end(); i++)
            if(i->second < 0)
                return false;
        return true;
    }
};