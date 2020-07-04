/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (39.75%)
 * Likes:    1715
 * Dislikes: 105
 * Total Accepted:    153.9K
 * Total Submissions: 380.8K
 * Testcase Example:  '10'
 *
 * Write a program to find the n-th ugly number.
 * 
 * Ugly numbers are positive numbers whose prime factors only include 2, 3,
 * 5. 
 * 
 * Example:
 * 
 * 
 * Input: n = 10
 * Output: 12
 * Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
 * ugly numbers.
 * 
 * Note:  
 * 
 * 
 * 1 is typically treated as an ugly number.
 * n does not exceed 1690.
 * 
 */

// @lc code=start
class Solution {
public:
  int nthUglyNumber(int n) {
    /**
     * Use the dynamic programming.
     */ 
    static vector<int> uglyNums(1, 1);
    static int i = 0; 
    static int j = 0;
    static int k = 0;
    while(uglyNums.size() < n){
      uglyNums.push_back(min(uglyNums[i]*2, min(uglyNums[j]*3, uglyNums[k]*5)));
      if(uglyNums.back() == uglyNums[i]*2) i++;
      if(uglyNums.back() == uglyNums[j]*3) j++;
      if(uglyNums.back() == uglyNums[k]*5) k++;
    }
    return uglyNums[n-1];
  }
};
// @lc code=end

