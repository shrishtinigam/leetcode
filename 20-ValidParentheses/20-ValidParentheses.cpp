// Last updated: 8/30/2025, 8:21:17 PM
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' or s[i] == '{' or s[i] == '['){
                stk.push(s[i]);
            }else{
                if(stk.size() == 0)
                    return false;
                if(s[i] == ')'){
                    if(stk.top() != '('){
                        return false;
                    }else{
                        stk.pop();
                    }
                }

                if(s[i] == '}'){
                    if(stk.top() != '{'){
                        return false;
                    }else{
                        stk.pop();
                    }
                }

                if(s[i] == ']'){
                    if(stk.top() != '['){
                        return false;
                    }else{
                        stk.pop();
                    }
                }

            }
        }

        if(stk.size() > 0)
            return false;
        return true;
    }
};