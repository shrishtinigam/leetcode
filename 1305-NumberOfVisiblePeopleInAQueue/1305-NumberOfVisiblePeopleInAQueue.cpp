// Last updated: 8/30/2025, 8:18:19 PM
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) 
        {
            while (!st.empty() && heights[i] > st.top()) 
            {
                st.pop();
                ans[i]++;
            }
            
            if (!st.empty())
                ans[i]++;
            st.push(heights[i]);
        }
        return ans;
    }
};