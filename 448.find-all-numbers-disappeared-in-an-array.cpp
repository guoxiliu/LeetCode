/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 *
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (53.82%)
 * Likes:    1774
 * Dislikes: 168
 * Total Accepted:    168.4K
 * Total Submissions: 312.3K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
 * elements appear twice and others appear once.
 * 
 * Find all the elements of [1, n] inclusive that do not appear in this array.
 * 
 * Could you do it without extra space and in O(n) runtime? You may assume the
 * returned list does not count as extra space.
 * 
 * Example:
 * 
 * Input:
 * [4,3,2,7,8,2,3,1]
 * 
 * Output:
 * [5,6]
 * 
 * 
 */
/**
 * 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            int val = abs(nums[i])-1;
            if(nums[val] > 0)
                nums[val] = -nums[val];
        }

        for(int i = 0; i < len; i++) {
            if(nums[i] > 0) 
                res.push_back(i+1);
        }

        return res;
    }
};
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            while (nums[cur-1] != cur) {
                swap(cur, nums[cur-1]);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i+1) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};

