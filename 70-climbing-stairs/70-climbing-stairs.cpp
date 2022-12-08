class Solution {
public:

    int climbStairs(int n) {

     int steps[45] = {0};
     steps[0] = 1;
     steps[1] = 2;

     for(int i = 2; i < n; i++)
     {
         steps[i] = steps[i - 2]+steps[i - 1]; 
         // First step can be taken in 2 ways, 1, rem(n - 1) and 2, rem(n - 2). 
         // Now we have found the no. of distinct ways of n - 1 and n - 2
         // So we add them up to get distinct steps for n.  
     }
     return steps[n - 1];
    }
};

