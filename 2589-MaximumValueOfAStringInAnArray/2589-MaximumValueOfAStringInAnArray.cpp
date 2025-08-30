// Last updated: 8/30/2025, 8:17:43 PM
class Solution {
public:
    
    bool is_num(const string &str)
    {
        return find_if(str.begin(), str.end(), [](char c) { return !(isdigit(c) || (c == ' ')); }) == str.end();
    }
    int maximumValue(vector<string>& strs) {
        int max = 0;
        int curr_len = 0;
        for(int i = 0; i < strs.size(); i++){
            if(is_num(strs[i]))
                curr_len = stoi(strs[i]);
            else
                curr_len = strs[i].size();
            if(curr_len > max)
                max = curr_len;

        }
        return max;
        
        // return find_if(strs.begin(), str.end(), )
    }
};