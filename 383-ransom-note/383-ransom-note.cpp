class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> u_map1, u_map2;

        for(int i = 0; i < magazine.size(); i++)
            u_map1[magazine[i]]++;
        for(int i = 0; i < ransomNote.size(); i++)
            u_map2[ransomNote[i]]++;
        for (auto i = u_map2.begin(); i != u_map2.end(); i++)
            if(u_map1[i->first] < i->second)
                return false;
        return true;
    }
};