/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (54.03%)
 * Total Accepted:    354.9K
 * Total Submissions: 656.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

class Solution {
public:
    void search(vector<int>& nums, int level, vector<vector<int>>& result) {
        if (level == nums.size()) {
            result.push_back(nums);
            return;
        } 

        for (int i = level; i < nums.size(); i++) {
            swap(nums[level], nums[i]);
            search(nums, level+1, result);
            swap(nums[level], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;
        
        search(nums, 0, res);
        return res;
    }
};

