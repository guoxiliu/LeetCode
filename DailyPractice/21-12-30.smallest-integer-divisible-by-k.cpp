#include "leetcode.h"

class Solution {
public: 
    int smallestRepunitDivByK(int k) {
        vector<bool> seen(k, false);
        int r = 0;
        for (int i = 1; i <= k; i++) {
            r = (r * 10 + 1) % k;
            if (r == 0) return i;
            if (seen[r]) return -1;
            seen[r] = true;
        }
        return -1;
    }
};
