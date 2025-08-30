// Last updated: 8/30/2025, 8:18:25 PM
class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1;
        int res;
        if(n == 0)
            return 0;
        else if(n == 1 or n == 2)
            return 1;
        for(int i = 0; i < n-1; i++){
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};