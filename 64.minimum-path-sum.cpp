/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (46.03%)
 * Total Accepted:    218.2K
 * Total Submissions: 473.3K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m < 1) return 0;
        int n = grid[0].size();
        vector<int> prev(grid.at(0)), cur(n, 1);

        // Initialize the first row.
        for (int j = 1; j < n; j++) {
            prev[j] += prev[j-1];
        }
        cur = prev;

        // Dynamic programming.
        for (int i = 1; i < m; i++) {
            cur[0] = prev[0] + grid[i][0];
            for (int j = 1; j < n; j++) {
                cur[j] = min(prev[j], cur[j-1]) + grid[i][j];
            }
            prev = cur;
        }

        return cur[n-1];
    }
};

