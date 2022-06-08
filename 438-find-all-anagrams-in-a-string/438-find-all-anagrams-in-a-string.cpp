class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        if(s.size() < p.size()) return {};
        vector <int> count_s (26, 0), count_p(26, 0);
        for(int i = 0; i < p.size(); i++)
        {
            count_p[int(p[i])-97]++;            
            count_s[int(s[i])-97]++;
        }
        
        vector <int> res;
        
        if(count_p == count_s)
                res.push_back(0);
        for(int i = p.size(); i < s.size(); i++)
        {
            count_s[int(s[i-p.size()])-97]--;
            count_s[int(s[i])-97]++;
     
            if(count_p == count_s)
                res.push_back(i-p.size()+1);
        }
        return res;
    }
};