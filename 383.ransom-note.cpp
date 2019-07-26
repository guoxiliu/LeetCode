/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (50.30%)
 * Likes:    335
 * Dislikes: 127
 * Total Accepted:    117.9K
 * Total Submissions: 234.4K
 * Testcase Example:  '"a"\n"b"'
 *
 * 
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the
 * ransom 
 * note can be constructed from the magazines ; otherwise, it will return
 * false. 
 * 
 * 
 * Each letter in the magazine string can only be used once in your ransom
 * note.
 * 
 * 
 * Note:
 * You may assume that both strings contain only lowercase letters.
 * 
 * 
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * 
 * 
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letters[26] = { 0 };
        for(int i = 0; i < magazine.size(); i++) {
            letters[magazine[i]-'a']++;
        }
        for(int i = 0; i < ransomNote.size(); i++) {
            if(--letters[ransomNote[i]-'a'] < 0)
                return false;
        }
        return true;
    }
};

