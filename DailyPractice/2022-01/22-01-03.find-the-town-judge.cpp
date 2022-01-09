#include "../leetcode.h"

class Solution {
public: 
    int findJudge(int n, vector<vector<int>> &trust) {
        vector<int> from(n+1, 0), to(n+1, 0);
        for (vector<int> &t : trust) {
            from[t[1]]++;
            to[t[0]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (from[i] == n-1 && to[i] == 0) return i;
        }
        return -1;
    }
};
