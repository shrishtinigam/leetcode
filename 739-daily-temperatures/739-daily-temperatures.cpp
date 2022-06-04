class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector <int> answer(temperatures.size());
        int i = temperatures.size() - 1;
        stack <int> pos;
        pos.push(i);
        while(i--)
        {
            while(!pos.empty() and temperatures[pos.top()] <= temperatures[i])
                pos.pop();
            answer[i] = pos.empty() ? 0 : pos.top() - i;
            pos.push(i);
        }
        return answer;
    }
};