/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (27.72%)
 * Total Accepted:    302.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */

/* 
* 8 ms solution
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long nn = n;
        if (nn < 0) {
            nn *= -1;
            x = 1/x;
        }

        while (nn > 0) {
            if (nn & 1) res *= x;
            x *= x;
            nn >>= 1;
        }

        return res;
    }
}; 
*/

class Solution {
public:
    double helper(double x, int n) {
        if (n == 0) return 1.0;
        double y = helper(x, n/2);
        if (n % 2 == 0) {
            return y * y;
        }
        return x * y * y;
    }

    double myPow(double x, int n) {
        if (n >= 0) return helper(x, n);
        return helper(1/x, -1L * n);
    } 
};

