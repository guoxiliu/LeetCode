/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (59.82%)
 * Likes:    552
 * Dislikes: 824
 * Total Accepted:    218.8K
 * Total Submissions: 365.7K
 * Testcase Example:  '1'
 *
 * Write a program that outputs the string representation of numbers from 1 to
 * n.
 * 
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 * 
 * Example:
 * 
 * n = 15,
 * 
 * Return:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        string three = "Fizz";
        string five = "Buzz";
        for(int i = 1; i <= n; i++) {
            if(i % 3 == 0 && i % 5 == 0) {
                res.push_back(three + five);
            } else if(i % 3 == 0) {
                res.push_back(three);
            } else if(i % 5 == 0) {
                res.push_back(five);
            } else {
                res.push_back(to_string(i));
            }
        }
        return res;
    }
};

