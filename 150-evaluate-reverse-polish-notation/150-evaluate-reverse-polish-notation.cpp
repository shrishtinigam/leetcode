class Solution {
public:
    int calculate(int x, int y, string o)
    {
        if(o == "+")
            return x + y;
        else if(o == "-")
            return x - y;
        else if(o == "*")
            return x * y;
        return x / y;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(isdigit(tokens[i][0]) or tokens[i].size() > 1)
                s.push(stoi(tokens[i]));
            else
            {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(calculate(y,x,tokens[i]));
            }
        }
        return s.top();
    }
};