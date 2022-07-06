class Solution {
public:
    
    int calculate(string s) 
    {
        int sum = 0;
        int sign = 1;
        int j = 0;
        stack<int> st;
        
        while(j < s.length())
        { 
            if(s[j] == '+')
                sign = 1;
            else if(s[j] == '-')
                sign = -1;
            else if(isdigit(s[j]))
            {
                int num = s[j] - '0';
                while(j + 1 < s.length() && isdigit(s[j + 1]))
                {
                    num = num * 10 + (s[j + 1] - '0');
                    j++;
                }
                sum += num * sign;
            }
            else if(s[j] == '(')
            {
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = 1;
            }
            else if(s[j]==')')
            {
                int xsign = st.top();
                st.pop();
                int xsum = st.top();
                st.pop();
                sum = sum * xsign + xsum;
            }
            j++;
        }
        
        return sum;
    }
};

