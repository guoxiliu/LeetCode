/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (53.77%)
 * Total Accepted:    315.1K
 * Total Submissions: 585.4K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void generate(vector<string> &res, int nleft, int nright, string cur) {
        if (nleft == 0 && nright == 0) {
            res.push_back(cur);
            return;
        }

        if (nleft > 0)
            generate(res, nleft-1, nright, cur+"(");
        if (nleft < nright)
            generate(res, nleft, nright-1, cur+")");

    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, n, n, "");
        return res;
    }
};

