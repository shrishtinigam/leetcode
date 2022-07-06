class Solution {
public:

    bool isValid(string s) {
        stack<char> st; 
        for(auto i:s)  
            if(i=='(' or i=='{' or i=='[') 
                st.push(i);  
            else  
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']'))                    return false;
                else
                    st.pop();  
        return st.empty();  
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
    bool isValid(string s) {
        stack <char> parentheses;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '{' or s[i] == '[' or s[i] == '(')
                parentheses.push(s[i]);
            else
                if(parentheses.empty() or !match(parentheses.top(), s[i]))
                    return false;
                else
                    parentheses.pop();
        }
        if(parentheses.empty())
            return true;
        return false;
    }
*/