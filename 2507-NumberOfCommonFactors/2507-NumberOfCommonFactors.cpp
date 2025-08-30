// Last updated: 8/30/2025, 8:17:51 PM
class Solution {
public:
    set <int> findFactors(int n){
        set <int> factors;
        for(int factor = 1; factor <= n; ++factor) {
            if(n % factor == 0)
                factors.insert(factor);
        }
        return factors;
    } 
    int commonFactors(int a, int b) {
        set <int> factorA = findFactors(a);
        set <int> factorB = findFactors(b);
        
        set <int> commonFactorsAB;
        
        set_intersection(factorA.begin(), factorA.end(), factorB.begin(), factorB.end(), inserter(commonFactorsAB, commonFactorsAB.begin()));
        
        return commonFactorsAB.size();

    }
};