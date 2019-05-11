/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (51.82%)
 * Total Accepted:    346.2K
 * Total Submissions: 668.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtracking(vector<int>&nums, vector<int>& cur, int pos, vector<vector<int>> &res) {
        res.push_back(cur);
        for (int i = pos; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            backtracking(nums, cur, i+1, res);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        backtracking(nums, cur, 0, res);
        return res;
    }
};
