/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (47.31%)
 * Total Accepted:    318K
 * Total Submissions: 672.1K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */

class Solution {
public:
    void search(vector<int>&num, int next, vector<int>& pSol, int target, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(pSol);
            return;
        }

        if (next == num.size() || target - num[next] < 0) 
            return;

        pSol.push_back(num[next]);
        search(num, next, pSol, target-num[next], result);
        pSol.pop_back();

        search(num, next+1, pSol, target, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> pSol;
        search(candidates, 0, pSol, target, result);
        return result;
    }
};

