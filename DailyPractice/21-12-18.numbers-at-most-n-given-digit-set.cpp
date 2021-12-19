#include "leetcode.h"

class Solution {
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n) {
        string strN = std::to_string(n);
        int digit = strN.size(), dsize = digits.size(), ans = 0;

        for (int i = 1; i < digit; i++) {
            ans += pow(dsize, i);
        }

        for (int i = 0; i < digit; i++) {
            bool sameNum = false;
            for (string &d : digits) {
                if (d[0] < strN[i]) {
                    ans += pow(dsize, digit-i-1);
                }
                else if (d[0] == strN[i]) {
                    sameNum = true;
                }
            }
            if (!sameNum) return ans;
        }

        return ans+1;
    }
};
