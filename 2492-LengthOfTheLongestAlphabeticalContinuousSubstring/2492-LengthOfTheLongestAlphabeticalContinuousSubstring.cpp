// Last updated: 8/30/2025, 8:17:53 PM
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int count = 1;
        int max_count = 1;
        for(int i = 0; i < s.length() -1; i++){
            if((int)s[i+1] - (int)s[i] == 1){
                count++;
                max_count = max(count, max_count);
            }else{
                count = 1;
            }
        }
        return max_count;
    }
};