/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (40.63%)
 * Total Accepted:    207.7K
 * Total Submissions: 511.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */

#include <vector>
using namespace std;

class Solution {
public:
    void search(vector<int>& nums, int start, vector<int> pSol, int target, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(pSol);
            return;
        } 

        int i = start;
        while (i < nums.size() && target-nums[i] >= 0) {
            if (i == start || nums[i] != nums[i-1]) {
                pSol.push_back(nums[i]);
                search(nums, i+1, pSol, target-nums[i], result);
                pSol.pop_back();
            }
            i++;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> pSol;
        search(candidates, 0, pSol, target, result);
        return result;
    }
};
