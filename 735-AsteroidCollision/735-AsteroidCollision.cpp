// Last updated: 8/30/2025, 8:18:35 PM
// 1 While stack is not empty and the filled with positive numbers, remove all the positive numbers from the top that are less than absolute value of the current number.
// 2 While stack is not empty and stack top is equal to absolute value of current number. 
// 3 If stack is empty or stack top is negative (in which case all the stack elements are negative), push the negative number to current stack.

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(ast[i] > 0 || s.empty())
                s.push(ast[i]);
            else{ 
                while(!s.empty() and s.top() > 0 and s.top() < abs(ast[i])) // 1
                    s.pop();
                if(!s.empty() and s.top() == abs(ast[i])) // 2
                    s.pop();
                else 
                    if(s.empty() || s.top() < 0) // 3
                        s.push(ast[i]);
            }
        }
        vector<int> res(s.size());
        for(int i = (int)s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};