/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (48.83%)
 * Likes:    990
 * Dislikes: 1391
 * Total Accepted:    296K
 * Total Submissions: 606.1K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */
class Solution {
public:
    /* 
    // Calculate the sum from 1 to n.
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int res = size*(size+1) / 2;
        for(int i = 0; i < size; i++) {
            res -= nums[i];
        }
        return res;
    }
     */

    // XOR
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int res = size;
        for(int i = 0; i < size; i++) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};

