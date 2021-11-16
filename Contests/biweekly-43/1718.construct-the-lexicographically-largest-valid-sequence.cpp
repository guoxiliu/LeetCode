/*
 * @lc app=leetcode id=1718 lang=cpp
 *
 * [1718] Construct the Lexicographically Largest Valid Sequence
 *
 * https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/
 *
 * algorithms
 * Medium (50.37%)
 * Likes:    332
 * Dislikes: 26
 * Total Accepted:    7.6K
 * Total Submissions: 15K
 * Testcase Example:  '3'
 *
 * Given an integer n, find a sequence that satisfies all of the
 * following:
 * 
 * 
 * The integer 1 occurs once in the sequence.
 * Each integer between 2 and n occurs twice in the sequence.
 * For every integer i between 2 and n, the distance between the two
 * occurrences of i is exactly i.
 * 
 * 
 * The distance between two numbers on the sequence, a[i] and a[j], is the
 * absolute difference of their indices, |j - i|.
 * 
 * Return the lexicographically largest sequence. It is guaranteed that under
 * the given constraints, there is always a solution. 
 * 
 * A sequence a is lexicographically larger than a sequence b (of the same
 * length) if in the first position where a and b differ, sequence a has a
 * number greater than the corresponding number in b. For example, [0,1,9,0] is
 * lexicographically larger than [0,1,5,6] because the first position they
 * differ is at the third number, and 9 is greater than 5.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: [3,1,2,3,2]
 * Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the
 * lexicographically largest valid sequence.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 5
 * Output: [5,3,1,4,3,5,2,4,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 20
 * 
 * 
 */

// @lc code=start
/**
 * The solution is to use backtracking to construct the valid sequence.
 */ 
class Solution {
public:
    bool backtrack(vector<int> &ans, vector<bool> &visited, int n, int idx) {
        if (idx == ans.size()) return true;
        if (ans[idx]) return backtrack(ans, visited, n, idx+1);

        // add the number from largest to smallest
        for (int i = n; i > 0; i--) {
            if (visited[i]) continue;
            visited[i] = true;
            ans[idx] = i;

            if (i == 1) {
                if (backtrack(ans, visited, n, idx+1)) return true;
            }

            // check if we can put the same number at the index (i+idx)
            else if (i+idx < ans.size() && ans[i+idx] == 0) {
                ans[i+idx] = i;
                if (backtrack(ans, visited, n, idx+1)) return true;
                ans[i+idx] = 0;
            }

            // reset the values
            ans[idx] = 0;
            visited[i] = false;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        if (n == 1) return vector<int> {1};

        vector<int> ans(2 * n - 1);
        vector<bool> visited(n+1, false);
        backtrack(ans, visited, n, 0);

        return ans;
    }
};
// @lc code=end

