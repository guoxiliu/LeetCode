/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (30.77%)
 * Likes:    1451
 * Dislikes: 621
 * Total Accepted:    319K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    /*
    Typcial solution needs O(n) extra space. 
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> res(size);
        k = k % size;
        for(int i = 0; i < size; i++) {
            res[i] = nums[(i+size-k)%size];
        }
        for(int i = 0; i < size; i++) {
            nums[i] = res[i];
        }
    } 
    */
   
   // Use reversal algorithm to rotate the array with O(1) extra space.
   void reverseArray(vector<int>& nums, int start, int end) {
       while(start < end) {
           swap(nums[start], nums[end]);
           start++;
           end--;
       }
   }
   void rotate(vector<int>& nums, int k) {
       int size = nums.size();
       k = k % size;
       if(k == 0) return;
       reverseArray(nums, 0, size-1);
       reverseArray(nums, 0, k-1);
       reverseArray(nums, k, size-1);
   }
};

