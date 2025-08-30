// Last updated: 8/30/2025, 8:20:44 PM
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1;
        while(s[n] == ' '){
            n--;
        }

        int lastWord = 0;

        while(n >= 0 and s[n] != ' '){
            lastWord++;
            n--;
        }
        return lastWord;
    }
};