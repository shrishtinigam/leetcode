class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector <int> answer;
        int i = temperatures.size() - 1;
        stack <int> pos;
        pos.push(i);
        while(i >= 0)
        {
            while(!pos.empty() and temperatures[pos.top()] <= temperatures[i])
                pos.pop();
            if(!pos.empty())
                answer.push_back(pos.top() - i);
            else
                answer.push_back(0);
            pos.push(i);
            i--;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};