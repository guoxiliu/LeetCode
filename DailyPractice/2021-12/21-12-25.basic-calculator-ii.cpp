#include "../leetcode.h"

class Solution {
public:
    int calculate(string s) {
        if (s.empty()) return 0;
        int len = s.length(), ans = 0;
        int cur = 0, prev = 0;
        char sign = '+';
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) {
                cur = cur * 10 + (s[i]-'0');
            }
            if ((!isdigit(s[i]) && !isspace(s[i])) || i == len-1) {
                if (sign == '+' || sign == '-') {
                    ans += prev;
                    prev = (sign == '+') ? cur : -cur;
                }
                else if (sign == '*') prev *= cur;
                else if (sign == '/') prev /= cur;
                sign = s[i];
                cur = 0;
            }
        }

        ans += prev;
        return ans;
    }
};
