/*
 * @lc app=leetcode id=2121 lang=cpp
 *
 * [2121] Intervals Between Identical Elements
 *
 * https://leetcode.com/problems/intervals-between-identical-elements/description/
 *
 * algorithms
 * Medium (39.46%)
 * Likes:    318
 * Dislikes: 12
 * Total Accepted:    7.2K
 * Total Submissions: 18.3K
 * Testcase Example:  '[2,1,3,1,2,3,3]'
 *
 * You are given a 0-indexed array of n integers arr.
 * 
 * The interval between two elements in arr is defined as the absolute
 * difference between their indices. More formally, the interval between arr[i]
 * and arr[j] is |i - j|.
 * 
 * Return an array intervals of length n where intervals[i] is the sum of
 * intervals between arr[i] and each element in arr with the same value as
 * arr[i].
 * 
 * Note: |x| is the absolute value of x.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [2,1,3,1,2,3,3]
 * Output: [4,2,7,2,4,4,5]
 * Explanation:
 * - Index 0: Another 2 is found at index 4. |0 - 4| = 4
 * - Index 1: Another 1 is found at index 3. |1 - 3| = 2
 * - Index 2: Two more 3s are found at indices 5 and 6. |2 - 5| + |2 - 6| = 7
 * - Index 3: Another 1 is found at index 1. |3 - 1| = 2
 * - Index 4: Another 2 is found at index 0. |4 - 0| = 4
 * - Index 5: Two more 3s are found at indices 2 and 6. |5 - 2| + |5 - 6| = 4
 * - Index 6: Two more 3s are found at indices 2 and 5. |6 - 2| + |6 - 5| = 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [10,5,10,10]
 * Output: [5,0,3,4]
 * Explanation:
 * - Index 0: Two more 10s are found at indices 2 and 3. |0 - 2| + |0 - 3| = 5
 * - Index 1: There is only one 5 in the array, so its sum of intervals to
 * identical elements is 0.
 * - Index 2: Two more 10s are found at indices 0 and 3. |2 - 0| + |2 - 3| = 3
 * - Index 3: Two more 10s are found at indices 0 and 2. |3 - 0| + |3 - 2| =
 * 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == arr.length
 * 1 <= n <= 10^5
 * 1 <= arr[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> pos;
        int len = arr.size();
        for (int i = 0; i < len; i++) 
            pos[arr[i]].emplace_back(i);

        vector<long long> ans(len, 0);
        for (auto &iter : pos) {
            long long n = iter.second.size();
            // preSum stores the sum before the current index 
            // postSum stores the sum from the current index
            long long preSum = 0, postSum = accumulate(iter.second.begin(), iter.second.end(), 0LL);
            for (long long i = 0; i < n; i++) {
                long long idx = iter.second[i];
                long long tmp1 = i * idx, tmp2 = (n-i) * idx;
                // since previous indices are less than the current one
                // the absolute difference would be the reverse 
                long long pre = -(preSum - tmp1);
                // opposite for the indices larger than the current one 
                long long post = postSum - tmp2;
                ans[iter.second[i]] = (pre + post);
                // update the preSum and postSum
                preSum += idx;
                postSum -= idx;
            }
        }
        return ans;
    }
};
// @lc code=end

