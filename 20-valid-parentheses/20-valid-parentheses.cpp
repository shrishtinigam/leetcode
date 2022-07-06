class Solution {
public:

    bool isValid(string s) {
        stack <char> parentheses;
        unordered_map <char,char> mp;
        mp['}'] = '{';
        mp[']'] = '[';
        mp[')'] = '(';
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '{' or s[i] == '[' or s[i] == '(')
                parentheses.push(s[i]);
            else
                if(parentheses.empty() or mp[s[i]] != parentheses.top())
                    return false;
                else
                    parentheses.pop();
        }
        if(parentheses.empty())
            return true;
        return false;
    }
};

/*
    bool match(char a, char b)
    {
        vector <char> arr1 = {'{', '[', '('};        
        vector <char> arr2 = {'}', ']', ')'};
        for(int i = 0; i < arr1.size(); i++)
        {
            if(a == arr1[i] and b == arr2[i])
                return true;
        }
        return false;
    }
*/