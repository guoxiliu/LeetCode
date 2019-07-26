/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (50.36%)
 * Likes:    1085
 * Dislikes: 82
 * Total Accepted:    291.2K
 * Total Submissions: 578.2K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int, int>> letters(26, {0, -1});
        int res = s.size();
        for(int i = 0; i < s.size(); i++) {
            letters[s[i]-'a'].first++;
            letters[s[i]-'a'].second = i;
        }

        for(auto p : letters) {
            if(p.first == 1)
                res = min(p.second, res);
        }

        if(res == s.size())
            return -1;
        return res;
    }
};

