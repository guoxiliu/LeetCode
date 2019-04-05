/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 *
 * https://leetcode.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (39.31%)
 * Total Accepted:    198.1K
 * Total Submissions: 504K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * Given a m x n matrix, if an element is 0, set its entire row and column to
 * 0. Do it in-place.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * Output: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * Output: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 
 * Follow up:
 * 
 * 
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best
 * solution.
 * Could you devise a constant space solution?
 * 
 * 
 */
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int rows = matrix.size(), cols = matrix[0].size();
        bool firstRow = false, firstCol = false;

        // Check if first row and first column contain zero.
        for (int c = 0; c < cols; c++) 
            if (matrix[0][c] == 0) 
                firstRow = true;

        for (int r = 0; r < rows; r++) 
            if (matrix[r][0] == 0) 
                firstCol = true;

        // Use the first row and column as an indicator.
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = matrix[0][c] = 0;
                }
            }
        }

        // Set zeros according to the first row and column.
        for (int c = 1; c < cols; c++) {
            if (matrix[0][c] == 0) {
                for (int r = 1; r < rows; r++) 
                    matrix[r][c] = 0;
            }
        }
        for (int r = 1; r < rows; r++) {
            if (matrix[r][0] == 0) {
                for (int c = 1; c < cols; c++) 
                    matrix[r][c] = 0;
            }
        }
        
        // See if first row or first column is true.
        if (firstRow) {
            for (int c = 1; c < cols; c++) 
                matrix[0][c] = 0;
        }

        if (firstCol) {
            for (int r = 1; r < rows; r++) 
                    matrix[r][0] = 0;
        }

    }
};

