/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (42.22%)
 * Likes:    1557
 * Dislikes: 2411
 * Total Accepted:    633.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer,
 * increment one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contains a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int i = digits.size()-1;
    for(; i >= 0; i--){
      if(digits[i] != 9){
        digits[i]++;
        break;
      }
      else{
        digits[i] = 0;
      }
    }

    if(i == -1){
      digits.insert(digits.begin(), 1);
    }

    return digits;
  }
};
// @lc code=end

