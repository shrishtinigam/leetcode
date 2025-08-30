// Last updated: 8/30/2025, 8:21:26 PM
class Solution {
public:

    vector<int> stringify(int x){
        vector<int> s;
        while(x > 0){
            int curr = (x % 10);
            x = x / 10;
            s.push_back(curr);
        }
        return s;
    }
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        vector<int> s = stringify(x);
        int l = 0;
        int h = s.size() - 1;
        while(h > l){
            if(s[l] != s[h])
                return false;
            l++;
            h--;
        }
        return true;
    }

    // Best Solution
    bool isPalindrome2(int x) {
        if (x < 0) {
            return false;
        }

        long long reversed = 0;
        long long temp = x;

        while (temp != 0) {
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }

        return (reversed == x);
    }
};