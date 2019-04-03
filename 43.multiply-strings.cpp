/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (30.19%)
 * Total Accepted:    190.2K
 * Total Submissions: 629.6K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int m = num1.size()-1, n = num2.size()-1, carry = 0;
        string product;

        for (int i = 0; i <= m+n || carry; i++) {
            for (int j = max(0, i-n); j<= min(i, m); j++) {
                carry += (num1[m-j] - '0') * (num2[n-i+j] - '0');
            }
            product += carry%10 + '0';
            carry /= 10;
        }
        reverse(product.begin(), product.end());
        return product;
    }
};

