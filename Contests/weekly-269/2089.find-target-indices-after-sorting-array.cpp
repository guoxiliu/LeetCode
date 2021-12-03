/*
 * @lc app=leetcode id=2089 lang=cpp
 *
 * [2089] Find Target Indices After Sorting Array
 *
 * https://leetcode.com/problems/find-target-indices-after-sorting-array/description/
 *
 * algorithms
 * Easy (86.36%)
 * Likes:    117
 * Dislikes: 5
 * Total Accepted:    12.3K
 * Total Submissions: 14.3K
 * Testcase Example:  '[1,2,5,2,3]\n2'
 *
 * You are given a 0-indexed integer array nums and a target element target.
 * 
 * A target index is an index i such that nums[i] == target.
 * 
 * Return a list of the target indices of nums after sorting nums in
 * non-decreasing order. If there are no target indices, return an empty list.
 * The returned list must be sorted in increasing order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,5,2,3], target = 2
 * Output: [1,2]
 * Explanation: After sorting, nums is [1,2,2,3,5].
 * The indices where nums[i] == 2 are 1 and 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,5,2,3], target = 3
 * Output: [3]
 * Explanation: After sorting, nums is [1,2,2,3,5].
 * The index where nums[i] == 3 is 3.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,5,2,3], target = 5
 * Output: [4]
 * Explanation: After sorting, nums is [1,2,2,3,5].
 * The index where nums[i] == 5 is 4.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [1,2,5,2,3], target = 4
 * Output: []
 * Explanation: There are no elements in nums with value 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 1 <= nums[i], target <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

