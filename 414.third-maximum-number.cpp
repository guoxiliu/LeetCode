/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (29.25%)
 * Likes:    396
 * Dislikes: 730
 * Total Accepted:    98.3K
 * Total Submissions: 336.1K
 * Testcase Example:  '[3,2,1]'
 *
 * Given a non-empty array of integers, return the third maximum number in this
 * array. If it does not exist, return the maximum number. The time complexity
 * must be in O(n).
 * 
 * Example 1:
 * 
 * Input: [3, 2, 1]
 * 
 * Output: 1
 * 
 * Explanation: The third maximum is 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2]
 * 
 * Output: 2
 * 
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [2, 2, 3, 1]
 * 
 * Output: 1
 * 
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        int flag = 0; // see if INT_MIN is in the vector
        int count  = 0; // the number of unique elements

        for(int num : nums) {
            if(num == first || num == second || num == third) {
                if(num == INT_MIN)
                    flag = 1;
                continue;
            }
            if(num > first) {
                third = second;
                second = first;
                first = num;
                count++;
            } else if(num > second) {
                third = second;
                second = num;
                count++;
            } else if(num > third) {
                third = num;
                count++;
            }
        }

        return (count+flag) >= 3 ? third : first;
    }
};

