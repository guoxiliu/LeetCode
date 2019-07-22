/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (45.82%)
 * Likes:    931
 * Dislikes: 240
 * Total Accepted:    246.8K
 * Total Submissions: 538.6K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 */
class Solution {
public:
    int tran(int n) {
        int res = 0;
        while(n) {
            res += (n%10) * (n%10);
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        unordered_set<int> visited;
        n = tran(n);
        while(!visited.count(n)) {
            visited.insert(n);
            if(n == 1) return true;
            n = tran(n);
        }
        return false;
    }
};

