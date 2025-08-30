// Last updated: 8/30/2025, 8:18:33 PM
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char nextLargest = target;
        int found = 0;
        while(found != 27)
        {
            if(nextLargest == 'z')
                nextLargest = 'a';
            else
                nextLargest++;
            if(binary_search(letters.begin(), letters.end(), nextLargest))
                return nextLargest;
            
            found++;
        }
        return '\0';
    }
};