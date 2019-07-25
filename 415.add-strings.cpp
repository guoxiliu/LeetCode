/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (44.16%)
 * Likes:    457
 * Dislikes: 155
 * Total Accepted:    105.1K
 * Total Submissions: 238K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string s = "";
        int i = num1.size()-1, j = num2.size()-1;

        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0)
                sum += num1[i--]-'0';
            if(j >= 0)
                sum += num2[j--]-'0';
            
            carry = sum / 10;
            sum %= 10;
            s += char(sum+'0') ;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};

