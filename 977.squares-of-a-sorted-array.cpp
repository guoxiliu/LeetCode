/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (72.26%)
 * Likes:    1136
 * Dislikes: 86
 * Total Accepted:    235.8K
 * Total Submissions: 326.4K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an array of integers A sorted in non-decreasing order, return an array
 * of the squares of each number, also in sorted non-decreasing order.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A is sorted in non-decreasing order.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
  vector<int> sortedSquares(vector<int>& A) {
    /*
      the idea is to initialize two pointers and unfold them from the center
      since the smallest numbers are living in the middle. 

      step 1:
      find out the starting point for the positive part and the negative part.
      Denote them as P (positive) and N (Negative).

      step 2:
      * compare P[i] and N[j]
      * Add the smaller one to the list, and advance the corresponding index.
      * rinse and repeat until one list has been exhausted. 

      step 3:
      if there is one list that has not been finished, finish it.
    */
    vector<int> ans(A.size());
    int l = 0, r = A.size()-1, i = A.size()-1;
    while(l <= r){
      int lsq = A[l]*A[l];
      int rsq = A[r]*A[r];
      if(lsq >= rsq){
        ans[i--] = lsq;
        l++;
      }
      else{
        ans[i--] = rsq;
        r--;
      }
    }
    return ans;
  }
};
// @lc code=end

