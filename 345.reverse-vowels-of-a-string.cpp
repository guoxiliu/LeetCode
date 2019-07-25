/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (41.88%)
 * Likes:    408
 * Dislikes: 763
 * Total Accepted:    164K
 * Total Submissions: 391.5K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */
class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        while(i < j) {
            while(!isVowel(s[i]) && i < j) i++;
            while(!isVowel(s[j]) && i < j) j--;
            swap(s[i++], s[j--]);
        }
        return s;
    }
};

