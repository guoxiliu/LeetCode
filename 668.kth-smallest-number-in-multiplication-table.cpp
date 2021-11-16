/*
 * @lc app=leetcode id=668 lang=cpp
 *
 * [668] Kth Smallest Number in Multiplication Table
 *
 * https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
 *
 * algorithms
 * Hard (48.98%)
 * Likes:    1044
 * Dislikes: 31
 * Total Accepted:    33.9K
 * Total Submissions: 68.5K
 * Testcase Example:  '3\n3\n5'
 *
 * Nearly everyone has used the Multiplication Table. The multiplication table
 * of size m x n is an integer matrix mat where mat[i][j] == i * j
 * (1-indexed).
 * 
 * Given three integers m, n, and k, return the k^th smallest element in the m
 * x n multiplication table.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: m = 3, n = 3, k = 5
 * Output: 3
 * Explanation: The 5^th smallest number is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: m = 2, n = 3, k = 6
 * Output: 6
 * Explanation: The 6^th smallest number is 6.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= m, n <= 3 * 10^4
 * 1 <= k <= m * n
 * 
 * 
 */

// @lc code=start
class Solution {
    // count the number of integers <= x in a multiplication table 
    // since each row is in the form [i*1, i*2, ..., i*n]
    // suppose N * i <= x, then N <= x / i, but each row has at most n integers
    int count(int m, int n, int x) {
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            ans += min(x / i, n);
        }
        return ans;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n, mid, ans;
        // apply the binary search  
        while (low <= high) {
            mid = low + (high-low) / 2;
            if (count(m, n, mid) < k) {
                low = mid + 1;
            } else {
                high = mid - 1; 
                ans = mid;
            }
        }
        return ans;
    }
};
// @lc code=end

