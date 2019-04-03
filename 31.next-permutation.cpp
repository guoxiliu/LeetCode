/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.17%)
 * Total Accepted:    222K
 * Total Submissions: 735.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j;
        
        // find the first decreasing number
        for (i = nums.size()-2; i >= 0; i--) {
            if (nums[i] < nums[i+1]) break;
        }
        
        // if not found, reverse the permutation
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        j = i + 1;        
        while(j < nums.size() && nums[j] > nums[i]){
            j++;
        }
        j--;
        
        swap(nums[i], nums[j]);
        reverse(nums.begin()+i+1, nums.end());
    }
};

