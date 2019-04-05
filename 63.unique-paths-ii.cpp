/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.28%)
 * Total Accepted:    190.5K
 * Total Submissions: 572.2K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m < 1) return 0;
        int n = obstacleGrid[0].size();

        // Initialize the first row.
        vector<long> prev(n, 1), cur(n, 1);
        prev[0] = 1 - obstacleGrid[0][0];
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[0][j] == 1 || prev[j-1] == 0) {
                prev[j] = 0;
            }
        }
        cur = prev;

        // Dynamic programming for the solution.
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 1 || prev[0] == 0) 
                cur[0] = 0;
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    cur[j] = 0;
                else
                    cur[j] = prev[j] + cur[j-1];
            }
            prev = cur;
        }

        return cur[n-1];
    }
};

