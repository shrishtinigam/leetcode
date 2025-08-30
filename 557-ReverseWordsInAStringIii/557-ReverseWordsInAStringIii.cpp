// Last updated: 8/30/2025, 8:18:45 PM
class Solution {
public:
    void reverse(string &s, int low, int high)
    {
        while(low<high)
        {
            swap(s[low],s[high]);
            low++;
            high--;
        }
    }
    string reverseWords(string s) {
        int low(0), high(-1); 
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                reverse(s,low,high);
                low = i + 1;
            }
            high++;
        }
        reverse(s,low,high);
        return s;
    }
};