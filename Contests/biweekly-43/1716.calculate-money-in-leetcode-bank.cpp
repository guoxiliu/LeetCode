/*
 * @lc app=leetcode id=1716 lang=cpp
 *
 * [1716] Calculate Money in Leetcode Bank
 *
 * https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/
 *
 * algorithms
 * Easy (64.32%)
 * Likes:    364
 * Dislikes: 12
 * Total Accepted:    25K
 * Total Submissions: 38.9K
 * Testcase Example:  '4'
 *
 * Hercy wants to save money for his first car. He puts money in the Leetcode
 * bank every day.
 * 
 * He starts by putting in $1 on Monday, the first day. Every day from Tuesday
 * to Sunday, he will put in $1 more than the day before. On every subsequent
 * Monday, he will put in $1 more than the previous Monday. 
 * 
 * Given n, return the total amount of money he will have in the Leetcode bank
 * at the end of the n^th day.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: 10
 * Explanation: After the 4^th day, the total is 1 + 2 + 3 + 4 = 10.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 10
 * Output: 37
 * Explanation: After the 10^th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) +
 * (2 + 3 + 4) = 37. Notice that on the 2^nd Monday, Hercy only puts in $2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 20
 * Output: 96
 * Explanation: After the 20^th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) +
 * (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int totalMoney(int n) {
        if (n == 1) return 1;
        int weeks = n/7, days = n%7;
        
        int ans = 0;
        // each week he saves $7 more
        // 1+2+3+4+5+6+7 = 28
        for (int i = 0; i < weeks; i++) {
            ans += (28 + 7*i);
        }
        
        // add the remaining days
        for (int i = 0; i < days; i++) {
            ans += (1+weeks+i);
        }
        
        return ans;
  }
};
// @lc code=end

