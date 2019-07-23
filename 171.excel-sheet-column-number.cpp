/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            res = res*26 + (s[i]-'A'+1);
        }
        return res;
    }
};

