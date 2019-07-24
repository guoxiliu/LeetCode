/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (52.82%)
 * Likes:    769
 * Dislikes: 114
 * Total Accepted:    364.1K
 * Total Submissions: 689.3K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        int n = s.length();
        char counts[30] = { 0 };
        char countt[30] = { 0 };
        for(int i = 0; i < n; i++) {
            counts[s[i]-'a']++;
            countt[t[i]-'a']++;
        }
        for(int i = 0; i < 30; i++) {
            if(counts[i] != countt[i]) 
                return false;
        }
        return true;
    }
};

