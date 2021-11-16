/*
 * @lc app=leetcode id=1726 lang=cpp
 *
 * [1726] Tuple with Same Product
 *
 * https://leetcode.com/problems/tuple-with-same-product/description/
 *
 * algorithms
 * Medium (59.83%)
 * Likes:    339
 * Dislikes: 15
 * Total Accepted:    16.3K
 * Total Submissions: 27.2K
 * Testcase Example:  '[2,3,4,6]'
 *
 * Given an array nums of distinct positive integers, return the number of
 * tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are
 * elements of nums, and a != b != c != d.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,4,6]
 * Output: 8
 * Explanation: There are 8 valid tuples:
 * (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
 * (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,4,5,10]
 * Output: 16
 * Explanation: There are 16 valids tuples:
 * (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
 * (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
 * (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
 * (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,3,4,6,8,12]
 * Output: 40
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums = [2,3,5,7]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 10^4
 * All elements in nums are distinct.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        if (nums.size() < 4) return 0;
        unordered_map<int, int> products;
        int ans = 0;

        // count the times of each product can be made from every two numbers
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            for (int j = i+1; j < n; j++) {
                int tmp = nums[i] * nums[j];
                products[tmp]++;
            }
        }

        for (pair<int, int> prod : products) {
            // there needs to be at least 2 same products to make a valid tuple
            // choose 2 from the number and each 2 pairs have 8 valid tuples
            if (prod.second >= 2) {
                ans += prod.second * (prod.second-1) / 2 * 8;
            }
        }

        return ans;
    }
};
// @lc code=end

