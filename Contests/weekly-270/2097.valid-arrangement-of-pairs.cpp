/*
 * @lc app=leetcode id=2097 lang=cpp
 *
 * [2097] Valid Arrangement of Pairs
 *
 * https://leetcode.com/problems/valid-arrangement-of-pairs/description/
 *
 * algorithms
 * Hard (27.00%)
 * Likes:    75
 * Dislikes: 8
 * Total Accepted:    1.1K
 * Total Submissions: 4K
 * Testcase Example:  '[[5,1],[4,5],[11,9],[9,4]]'
 *
 * You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti,
 * endi]. An arrangement of pairs is valid if for every index i where 1 <= i <
 * pairs.length, we have endi-1 == starti.
 * 
 * Return any valid arrangement of pairs.
 * 
 * Note: The inputs will be generated such that there exists a valid
 * arrangement of pairs.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
 * Output: [[11,9],[9,4],[4,5],[5,1]]
 * Explanation:
 * This is a valid arrangement since endi-1 always equals starti.
 * end0 = 9 == 9 = start1 
 * end1 = 4 == 4 = start2
 * end2 = 5 == 5 = start3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: pairs = [[1,3],[3,2],[2,1]]
 * Output: [[1,3],[3,2],[2,1]]
 * Explanation:
 * This is a valid arrangement since endi-1 always equals starti.
 * end0 = 3 == 3 = start1
 * end1 = 2 == 2 = start2
 * The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also
 * valid.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: pairs = [[1,2],[1,3],[2,1]]
 * Output: [[1,2],[2,1],[1,3]]
 * Explanation:
 * This is a valid arrangement since endi-1 always equals starti.
 * end0 = 2 == 2 = start1
 * end1 = 1 == 1 = start2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= pairs.length <= 10^5
 * pairs[i].length == 2
 * 0 <= starti, endi <= 10^9
 * starti != endi
 * No two pairs are exactly the same.
 * There exists a valid arrangement of pairs.
 * 
 * 
 */

// @lc code=start
class Solution {
    unordered_map<int, stack<int>> graph;
    
    // Use DFS to find the Euler path
    void dfs(vector<vector<int>> &ans, int curr) {
        stack<int> &stk = graph[curr];
        while (!stk.empty()) {
            int nei = stk.top();
            stk.pop();
            dfs(ans, nei);
            ans.push_back({curr, nei});
        }
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int sz = pairs.size();
        unordered_map<int, int> in;  // in degree
        unordered_map<int, int> out; // out degree
        graph.reserve(sz); in.reserve(sz); out.reserve(sz);
        
        for (vector<int> &p : pairs) {
            in[p[1]]++;
            out[p[0]]++;
            graph[p[0]].push(p[1]);
        }
        
        // find the starting node
        int start = -1;
        for (auto &p : graph) {
            int i = p.first;
            if (out[i] - in[i] == 1) start = i;
        }
        if (start == -1) {
            start = graph.begin()->first;
        }
        
        // use dfs to find the solution
        vector<vector<int>> ans;
        dfs(ans, start);
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
// @lc code=end

