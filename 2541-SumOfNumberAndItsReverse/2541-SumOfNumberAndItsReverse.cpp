// Last updated: 8/30/2025, 8:17:45 PM
class Solution {
public:
    int reverseSum(int n){
        int n1 = n;
        int rem, res = 0;
         while(n != 0) {
            rem = n % 10;
            res = res * 10 + rem;
            n /= 10;
        }
        return res+n1;
    }
    bool sumOfNumberAndReverse(int num) {
        if(num == 0)
            return true;
        for(int i = 0 ; i < num; i++){
            if(reverseSum(i) == num)
                return true;
        }
        return false;
    }
};