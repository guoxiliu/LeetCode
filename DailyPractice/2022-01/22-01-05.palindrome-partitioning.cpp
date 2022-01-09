/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (56.72%)
 * Likes:    5513
 * Dislikes: 162
 * Total Accepted:    396.8K
 * Total Submissions: 691.3K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome. Return all possible palindrome partitioning of s.
 * 
 * A palindrome string is a string that reads the same backward as forward.
 * 
 * 
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
    vector<vector<bool>> dp;
public:
    vector<vector<string>> partition(string s) {
       int len = s.length();
       dp = vector<vector<bool>>(len, vector<bool>(len, false)); 
       vector<vector<string>> ans;
       vector<string> cur;
       dfs(ans, s, 0, cur);
       return ans;
    }

    void dfs(vector<vector<string>> &ans, string &s, int start, vector<string> &cur) {
        if (start >= s.length()) 
            ans.emplace_back(cur);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end-start <= 2 || dp[start+1][end-1])) {
                dp[start][end] = true;
                cur.push_back(s.substr(start, end-start+1));
                dfs(ans, s, end+1, cur);
                cur.pop_back();
            }
        }
    }
};
// @lc code=end

