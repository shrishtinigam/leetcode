class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n % 2 == 0)
            return n;
        return n * 2;
    }
};

/* OTHER SOLUTIONS
int smallestEvenMultiple(int n) {
    return n % 2 == 0 ? n : n*2;
}

int smallestEvenMultiple(int n) {
    return n << (n & 1);
}

int smallestEvenMultiple(int n) {
    return n * (n % 2 + 1);
}

int smallestEvenMultiple(int n) {
    return n % 2 == 0 ? n : n << 1;
}

*/