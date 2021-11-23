/*
 * @lc app=leetcode id=952 lang=cpp
 *
 * [952] Largest Component Size by Common Factor
 *
 * https://leetcode.com/problems/largest-component-size-by-common-factor/description/
 *
 * algorithms
 * Hard (37.15%)
 * Likes:    816
 * Dislikes: 73
 * Total Accepted:    32.4K
 * Total Submissions: 84.5K
 * Testcase Example:  '[4,6,15,35]'
 *
 * You are given an integer array of unique positive integers nums. Consider
 * the following graph:
 * 
 * 
 * There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
 * There is an undirected edge between nums[i] and nums[j] if nums[i] and
 * nums[j] share a common factor greater than 1.
 * 
 * 
 * Return the size of the largest connected component in the graph.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,6,15,35]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [20,50,9,63]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,3,6,7,4,12,21,39]
 * Output: 8
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * 1 <= nums[i] <= 10^5
 * All the values of nums are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
    vector<int> par, sz;
    
    int Find(int x) {
        int y = par[x];
        while (y != par[y]) {
            y = par[y];
        }
        return par[x] = y;
    }
    
    bool Union(int x, int y) {
        int xp = Find(x), yp = Find(y);
        if (xp == yp) return false;
        if (sz[xp] > sz[yp]) par[yp] = par[xp], sz[xp] += sz[yp];
        else par[xp] = par[yp], sz[yp] += sz[xp];
        return true;
    }
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        for (int i = 0; i < n; i++) {
            par.push_back(i);
        }
        sz = vector<int>(n, 1);
        unordered_map<int, vector<int>> mp;
        
        // prime factorize 
        for (int i = 0; i < n; i++) {
            int cur = nums[i];
            // check if 2 is the prime factor 
            if (cur % 2 == 0) {
                mp[2].push_back(i);
                while (cur % 2 == 0) cur >>= 1;
            }
            // check all the odd numbers 
            for (int p = 3; p <= sqrt(cur); p += 2) {
                if (cur % p == 0) {
                    mp[p].push_back(i);
                    while (cur % p == 0) cur /= p;
                }
            }
            if (cur > 1) mp[cur].push_back(i);
        }
        
        for (auto ele : mp) {
            for (int i = 0; i < ele.second.size()-1; i++) {
                Union(ele.second[i], ele.second[i+1]);
            }
        }
        
        return *max_element(begin(sz), end(sz));
    }
};
// @lc code=end

