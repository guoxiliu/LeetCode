/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (46.59%)
 * Total Accepted:    192.6K
 * Total Submissions: 412.4K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& comb, int cur, int n, int k, vector<vector<int>> &res) {
        if (k == 0) {
            res.push_back(comb);
            return;
        }

        // if cur > n - k, there are not enough number left, we have to select the current number
        if (cur <= n - k)
            backtrack(comb, cur+1, n, k, res);
        comb.push_back(cur);
        backtrack(comb, cur+1, n, k-1, res);
        comb.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sol;
        backtrack(sol, 1, n, k, res);
        return res;
    }
};

