/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (42.16%)
 * Likes:    282
 * Dislikes: 73
 * Total Accepted:    49.7K
 * Total Submissions: 117.9K
 * Testcase Example:  '26'
 *
 * 
 * Given an integer, write an algorithm to convert it to hexadecimal. For
 * negative integer, two’s complement method is used.
 * 
 * 
 * Note:
 * 
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is
 * zero, it is represented by a single zero character '0'; otherwise, the first
 * character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You must not use any method provided by the library which converts/formats
 * the number to hex directly.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 26
 * 
 * Output:
 * "1a"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * -1
 * 
 * Output:
 * "ffffffff"
 * 
 * 
 */
class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";
        
        string s = "";
        const int mask = 0x0000000f;
        for(int i = 0; i < 8; i++) {
            if(num == 0) break;
            int remainder = num & mask;
            if(remainder == 10) {
                s = "a" + s;
            } else if(remainder == 11) {
                s = "b" + s;
            } else if(remainder == 12) {
                s = "c" + s;
            } else if(remainder == 13) {
                s = "d" + s;
            } else if(remainder == 14) {
                s = "e" + s;
            } else if(remainder == 15) {
                s = "f" + s;
            } else {
                s = to_string(remainder) + s;
            }
            num >>= 4;

        }
        
        return s;
    }
};

