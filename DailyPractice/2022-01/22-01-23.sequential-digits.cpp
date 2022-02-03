#include "../leetcode.h"

class Solution {
public:
    void backtrack(vector<int> &ans, int &low, int &high, int num, int next) {
        if (num > high || num > INT_MAX / 10) return;
        if (num >= low && num <= high) ans.push_back(num);
        if (next <= 9)
            backtrack(ans, low, high, num*10+next, next+1);
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            backtrack(ans, low, high, i, i+1);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

