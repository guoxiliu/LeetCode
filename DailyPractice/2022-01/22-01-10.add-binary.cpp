#include "../leetcode.h"

class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size(), len2 = b.size();
        int i = len1-1, j = len2-1;
        bool carry = 0;
        string result="";
        while (i >= 0 || j >= 0) {
            int res = carry;
            if (i >= 0) res += a[i]-'0';
            if (j >= 0) res += b[j]-'0';
            if (res > 1) {
                carry = 1;
                res %= 2;
            }
            else carry = 0;
            result = result.insert(0, to_string(res));
            i--; j--;
        }
        if (carry) result = result.insert(0, "1");
        return result;
    }
};

