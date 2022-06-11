class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        unordered_map <char, string> buttons;
        buttons['2'] = "abc";
        buttons['3'] = "def";
        buttons['4'] = "ghi";
        buttons['5'] = "jkl";
        buttons['6'] = "mno";
        buttons['7'] = "pqrs";
        buttons['8'] = "tuv";
        buttons['9'] = "wxyz";
        vector <string> result = {""};
        for(int i = 0; i < digits.size(); i++)
        {
            vector <string> v2 = result;
            cout << buttons[digits[i]].size() << " ";
            for(int j = 0; j < buttons[digits[i]].size() - 1; j++)
                result.insert(result.end(), v2.begin(), v2.end());
            
            int x = result.size() / buttons[digits[i]].size();
            
            int y = 0;
            for(int j = 0; j < buttons[digits[i]].size(); j++)
            {
                for(int k = 0; k < x; k++)
                    result[k + y] += buttons[digits[i]][j];
                y += x;
            }
        }
        return result;

    }
};