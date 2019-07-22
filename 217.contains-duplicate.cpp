/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (52.56%)
 * Likes:    425
 * Dislikes: 538
 * Total Accepted:    358.8K
 * Total Submissions: 682.5K
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an array of integers, find if the array contains any duplicates.
 * 
 * Your function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4]
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 */
class Solution {
public:
    /* 
    // Use unordered set.
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for(int i = 0; i < nums.size(); i++) {
            if(numSet.find(nums[i]) != numSet.end())
                return true;
            numSet.insert(nums[i]);
        }
        return false;
    }
     */

    // Sort the vector.
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) 
                return true;
        }
        return false;
    }
};

