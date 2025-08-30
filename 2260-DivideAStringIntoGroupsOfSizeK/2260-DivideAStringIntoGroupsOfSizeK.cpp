// Last updated: 8/30/2025, 8:18:03 PM
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        int i = 0;
        int k1 = k;
        vector <string> result;
        while(i < n)
        {
            string temp = "";
            while(k1 != 0)
            {
                if(i >= n)
                    temp = temp + fill;
                else
                    temp = temp + s[i];
                i++;
                k1--;
            }
            result.push_back(temp);
            k1 = k;
        }
        return result;
    }
};