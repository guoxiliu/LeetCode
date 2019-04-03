/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (39.61%)
 * Total Accepted:    229.5K
 * Total Submissions: 578.9K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */

class Solution {
public:
    void search(vector<int> nums, int level, vector<vector<int>>& result) {
        if (level == nums.size()) {
            result.push_back(nums);
            return;
        }

        for (int i = level; i < nums.size(); i++) {
            if (i != level && nums[i] == nums[level])
                continue;
            swap(nums[level], nums[i]);
            search(nums, level+1, result);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        search(nums, 0, res);
        return res;
    }
};

