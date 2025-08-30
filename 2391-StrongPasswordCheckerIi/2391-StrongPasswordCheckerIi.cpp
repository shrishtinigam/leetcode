// Last updated: 8/30/2025, 8:18:00 PM
#include <regex>

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        string pattern = "^(?!.*([0-9])\\1)(?!.*([a-z])\\2)(?!.*([A-Z])\\3)(?!.*([!@#$%^&*()+-])\\4)(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.*[!@#$%^&*()+-])[A-Za-z0-9!@#$%^&*()+-]{8,}$";
        return regex_match (password, regex(pattern));
    }
};


/*

? 
class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        return p.size() >= 8 && (accumulate(p.begin(), p.end(), 0, [](int x, char c) {return (x & 31) | (islower(c) ? 1 : isupper(c) ? 2 : isdigit(c) ? 4 : 8) | (c == (x >> 16) ? 16 : 0) | (c << 16);}) & 31) == 15;
    }
};



bool strongPasswordCheckerII(string p) {
    int cnt[4] = {}, sz = p.size();
    for (int i = 0; i < sz; ++i) {
        if (i > 0 && p[i - 1] == p[i])
            return false;
        ++cnt[islower(p[i]) ? 1 : isupper(p[i]) ? 2 : isdigit(p[i]) ? 3 : 0];
    }
    return sz > 7 && all_of(begin(cnt), end(cnt), bind(greater<int>(), placeholders::_1, 0));
}



class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        if(size(p) < 8) return false;
        bool low = false , upper = false ,digit = false ,special = false;
        for(auto c : p){
            if(c>='a' and c<='z') low = true;
            else if(c>='A' and c <='Z') upper = true;
            else if(isdigit(c)) digit = true;
            else special = true;
        }
        //Check the 6th condition
        for(int i=0;i+1<size(p);i++) if(p[i] == p[i+1]) return false;
        if(low and upper and digit and special) return true;
        return false;
    }
};

*/