// Last updated: 8/30/2025, 8:19:57 PM
class Solution {
public:
    
    bool isPali(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i++; j--;
        }
        return true;
    }

    void dfs(int i, string &s, vector <string> &part, vector<vector<string>> &res){
        if(i == s.length()){
            res.push_back(part);
        }else{
            for(int j = i; j < s.length(); j++){
                if(isPali(s, i, j)){
                    part.push_back(s.substr(i, j - i + 1));
                    dfs(j + 1, s, part, res);
                    part.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        dfs(0, s, part, res);
        return res;
    }
};