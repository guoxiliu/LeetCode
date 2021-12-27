#include "leetcode.h"

class Solution {
public: 
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        // there is only 1 set bit if the number is power of 2
        return ((n & (n-1)) == 0);
    }
};
