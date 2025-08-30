// Last updated: 8/30/2025, 8:19:10 PM
class Solution {
public:
    // dp[index] = dp[index - offset] + 1;
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        int offset = 1;
        for (int index = 1; index < num + 1; ++index)
        {
            if (offset * 2 == index)
            {
                offset *= 2;
            }
            result[index] = result[index - offset] + 1;
        }
        return result;
    }
};