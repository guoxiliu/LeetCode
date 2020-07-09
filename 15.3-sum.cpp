/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (26.37%)
 * Likes:    7086
 * Dislikes: 822
 * Total Accepted:    938.2K
 * Total Submissions: 3.5M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int>> ans;
    if(len < 3) return ans;
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < len-2; i++){
      if(i > 0 && nums[i] == nums[i-1]) 
        continue;
      int j = i+1, k = len-1;
      int target = -nums[i];
      while(j < k){
        if(nums[j] + nums[k] < target) j++;
        else if(nums[j] + nums[k] > target) k--;
        else{
          ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
          do {j++;} while(j < k && nums[j-1] == nums[j]);
          do {k--;} while(j < k && nums[k+1] == nums[k]);
        }
      }
    }
    return ans;
  }
};
// @lc code=end

