/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (41.91%)
 * Total Accepted:    195.5K
 * Total Submissions: 466.6K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */
#include <vector>
using namespace std;

class Solution {
public:
    void backtracking(vector<int>& nums, int start, vector<int>& sol, vector<vector<int>>& res) {
        res.push_back(sol);
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[i-1]) {
                continue;
            }
            sol.push_back(nums[i]);
            backtracking(nums, i+1, sol, res);
            sol.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() < 1)
            return vector<vector<int>>();

        vector<vector<int>> res;
        vector<int> sol;
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, sol, res);
        return res;
    }
};

