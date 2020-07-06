/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 *
 * https://leetcode.com/problems/hamming-distance/description/
 *
 * algorithms
 * Easy (71.47%)
 * Likes:    1792
 * Dislikes: 159
 * Total Accepted:    335.5K
 * Total Submissions: 463K
 * Testcase Example:  '1\n4'
 *
 * The Hamming distance between two integers is the number of positions at
 * which the corresponding bits are different.
 * 
 * Given two integers x and y, calculate the Hamming distance.
 * 
 * Note:
 * 0 ≤ x, y < 2^31.
 * 
 * 
 * Example:
 * 
 * Input: x = 1, y = 4
 * 
 * Output: 2
 * 
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 * ⁠      ↑   ↑
 * 
 * The above arrows point to positions where the corresponding bits are
 * different.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
  int hammingDistance(int x, int y) {
    /**
     * The input is two integers, so there are 32 bits at most.
     * For each bit check if x and y are equal or not.
     */ 
    int mask = 1, count = 0;
    for(int i = 0; i < 32; i++){
      mask = 1 << i;
      if((mask&x) ^ (mask&y)) count++;
    }
    return count;
  }
};
// @lc code=end

