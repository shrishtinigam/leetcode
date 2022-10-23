
class Solution {
public:
    int convertTime(string s){
        int h = (int) s[0] * 10 + (int)s[1];
        int m = (int) s[3] * 10 + (int)s[4];
        return (h*60 + m);
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {

        int s1 = convertTime(event1[0]);
        int e1 = convertTime(event1[1]);
        int s2 = convertTime(event2[0]);
        int e2 = convertTime(event2[1]);
        
        if((s2 >= s1 and s2 <= e1) or(e2 >= s1 and e2 <= e1))
            return true;
        if((s1 >= s2 and s1 <= e2) or(e1 >= s2 and e1 <= e2))
            return true;
        return false;
    }
};