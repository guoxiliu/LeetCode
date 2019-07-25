/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (48.36%)
 * Likes:    563
 * Dislikes: 58
 * Total Accepted:    102.3K
 * Total Submissions: 211.4K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> counts;
        for(int i = 0; i < s.length(); i++) {
            counts[s[i]]++;
        }
        int res = 0;
        bool odd = false;
        for(auto p : counts) {
            if(p.second % 2) {
                odd = true;
            }
            res += (p.second / 2) * 2;
        }

        return odd ? res+1 : res;
    }
};

