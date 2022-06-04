class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> max_temps;
        vector <int> answer;
        int i = temperatures.size() - 1;
        stack <int> pos;
        max_temps.push(temperatures[i]);
        pos.push(i);
        while(i >= 0)
        {
            while(!max_temps.empty() and max_temps.top() <= temperatures[i])
            {
                max_temps.pop();
                pos.pop();
            }
            if(!max_temps.empty())
                answer.push_back(pos.top() - i);
            else
                answer.push_back(0);
            max_temps.push(temperatures[i]);
            pos.push(i);
            i--;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};