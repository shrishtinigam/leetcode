// Last updated: 8/30/2025, 8:21:09 PM
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        if (needle == "") return -1;
        int n = haystack.size();
        int m = needle.size();
        int i = 0;
        while(i < n){
            int j = 0;
            while(j < m){
                if(haystack[j+i] != needle[j]){
                    break;
                }
                if(j == m-1)
                    return i;
                j++;
            }
            i++;
        }
        return -1;
    }
};