/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (22.03%)
 * Total Accepted:    249.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() < 1) 
            return 0;

        if (s[0] < '1' || s[0] > '9')
            return 0;

        int n = s.size();
        int ways[n] = {0};
        ways[0] = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] >= '1' && s[i] <= '9') 
                ways[i] = ways[i-1];
            int tmp = (s[i-1]-'0')*10+(s[i]-'0');
            if (tmp >= 10 && tmp <= 26) {
                if (i - 2 < 0) ways[i] += 1;
                else ways[i] += ways[i-2];
            }
        }
        
        return ways[n-1];
    }
};

