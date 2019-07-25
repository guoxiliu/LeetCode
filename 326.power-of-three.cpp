/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (41.77%)
 * Likes:    295
 * Dislikes: 1088
 * Total Accepted:    193.5K
 * Total Submissions: 463.3K
 * Testcase Example:  '27'
 *
 * Given an integer, write a function to determine if it is a power of three.
 * 
 * Example 1:
 * 
 * 
 * Input: 27
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: 9
 * Output: true
 * 
 * Example 4:
 * 
 * 
 * Input: 45
 * Output: false
 * 
 * Follow up:
 * Could you do it without using any loop / recursion?
 */
class Solution {
public:
    /* 
    // Loop version.
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
     */

    // Logarithm base change formula.
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1) == 0;
    }
};

