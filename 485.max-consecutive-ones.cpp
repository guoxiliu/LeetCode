/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 *
 * https://leetcode.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (55.05%)
 * Likes:    653
 * Dislikes: 362
 * Total Accepted:    229K
 * Total Submissions: 415.9K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * Given a binary array, find the maximum number of consecutive 1s in this
 * array.
 * 
 * Example 1:
 * 
 * Input: [1,1,0,1,1,1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive
 * 1s.
 * ⁠   The maximum number of consecutive 1s is 3.
 * 
 * 
 * 
 * Note:
 * 
 * The input array will only contain 0 and 1.
 * The length of input array is a positive integer and will not exceed 10,000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int times = 0, res = 0;
    for(int i = 0; i < nums.size(); i++){
      times += nums[i];
      if(nums[i] == 0){
        if(times > res) res = times;
        times = 0;
      }
    }
    if(times > res) res = times;
    return res;
  }
};
// @lc code=end

