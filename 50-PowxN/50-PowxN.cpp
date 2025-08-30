// Last updated: 8/30/2025, 8:20:52 PM
class Solution {
public:
    double myPow(double x, int n) {
      // https://leetcode.com/problems/powx-n/solutions/1337794/java-c-simple-o-log-n-easy-faster-than-100-explained/  
        if(n < 0) {
            x = 1 / x;
        } 
        
        long num = labs(n);
        
        double pow = 1;
        
        while(num){ // equivalent to while(num != 0)
            if(num & 1) { // equivalent to if((num & 1) != 0)
                pow *= x;
            }
            
            x *= x;
            num >>= 1;
        }
        
        return pow;
    }

};