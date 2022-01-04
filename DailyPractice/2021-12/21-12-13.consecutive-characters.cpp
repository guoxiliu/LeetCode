#include "../leetcode.h"

class Solution {
public:
    int maxPower(string s) {
        int i = 0, n = s.length();
        int ans = 1;
        while (i < n) {
            char c = s[i];
            int cur = 0;
            while (i < n && s[i] == c) 
                cur++, i++;
            ans = max(ans, cur);
        }
        return ans;
    }
};
