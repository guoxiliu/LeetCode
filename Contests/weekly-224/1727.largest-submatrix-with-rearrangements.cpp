/*
 * @lc app=leetcode id=1727 lang=cpp
 *
 * [1727] Largest Submatrix With Rearrangements
 *
 * https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/
 *
 * algorithms
 * Medium (59.79%)
 * Likes:    540
 * Dislikes: 16
 * Total Accepted:    10.3K
 * Total Submissions: 17.2K
 * Testcase Example:  '[[0,0,1],[1,1,1],[1,0,1]]'
 *
 * You are given a binary matrix matrix of size m x n, and you are allowed to
 * rearrange the columns of the matrix in any order.
 * 
 * Return the area of the largest submatrix within matrix where every element
 * of the submatrix is 1 after reordering the columns optimally.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
 * Output: 4
 * Explanation: You can rearrange the columns as shown above.
 * The largest submatrix of 1s, in bold, has an area of 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: matrix = [[1,0,1,0,1]]
 * Output: 3
 * Explanation: You can rearrange the columns as shown above.
 * The largest submatrix of 1s, in bold, has an area of 3.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: matrix = [[1,1,0],[1,0,1]]
 * Output: 2
 * Explanation: Notice that you must rearrange entire columns, and there is no
 * way to make a submatrix of 1s larger than an area of 2.
 * 
 * Example 4:
 * 
 * 
 * Input: matrix = [[0,0],[0,0]]
 * Output: 0
 * Explanation: As there are no 1s, no submatrix of 1s can be formed and the
 * area is 0.
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m * n <= 10^5
 * matrix[i][j] is 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;

        // compute the cumulative ones for each column
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) matrix[i][j] = matrix[i-1][j] + 1;
                else matrix[i][j] = 0;
            }
        }

        // for each row, sort the columns in non-increasing order
        // compute the area of the submatrix and compare it with the maximum 
        for (int i = 0; i < m; i++) {
            int k = INT_MAX;
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            for (int j = 0; j < n; j++) {
                k = min(k, matrix[i][j]);
                ans = max(ans, (j+1) * k);
            }
        }

        return ans;
    }
};
// @lc code=end

