/*
 * @lc app=leetcode id=1717 lang=cpp
 *
 * [1717] Maximum Score From Removing Substrings
 *
 * https://leetcode.com/problems/maximum-score-from-removing-substrings/description/
 *
 * algorithms
 * Medium (43.17%)
 * Likes:    316
 * Dislikes: 18
 * Total Accepted:    7.9K
 * Total Submissions: 18.2K
 * Testcase Example:  '"cdbcbbaaabab"\n4\n5'
 *
 * You are given a string s and two integers x and y. You can perform two types
 * of operations any number of times.
 * 
 * 
 * Remove substring "ab" and gain x points.
 * 
 * 
 * For example, when removing "ab" from "cabxbae" it becomes
 * "cxbae".
 * 
 * 
 * Remove substring "ba" and gain y points.
 * 
 * For example, when removing "ba" from "cabxbae" it becomes
 * "cabxe".
 * 
 * 
 * 
 * 
 * Return the maximum points you can gain after applying the above operations
 * on s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "cdbcbbaaabab", x = 4, y = 5
 * Output: 19
 * Explanation:
 * - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5
 * points are added to the score.
 * - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4
 * points are added to the score.
 * - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points
 * are added to the score.
 * - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are
 * added to the score.
 * Total score = 5 + 4 + 5 + 5 = 19.
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aabbaaxybbaabb", x = 5, y = 4
 * Output: 20
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * 1 <= x, y <= 10^4
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
/**
 * The solution is to use stack to keep track of 'a' and 'b' in the string.
 * Comments in the code assume removing "ab" gains more points.
 */ 
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0, char1 = 'a', char2 = 'b';
        // if removing "ba" gains more points
        if (x < y) {
            swap(char1, char2);
            swap(x, y);
        }
        
        // use vector to function like stack 
        // since it is easier to clear the container
        vector<char> vec1, vec2;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == char1) {
                vec1.push_back(char1);
            }
            else if (s[i] == char2) {
                // the current character is "b"
                // if we find "ab" then add x points
                if (!vec1.empty()) {
                    ans += x;
                    vec1.pop_back();
                }
                else {
                    vec2.push_back(char2);
                }
            }
            else {
                // check if we can make 'ba' and add y points
                while (!vec1.empty() && !vec2.empty()) {
                    vec2.pop_back(); vec1.pop_back();
                    ans += y;
                }
                // clear the stack since 'a' and 'b' are not together
                vec1.clear();
                vec2.clear();
            }
        }
        
        // in case there are any characters left 
        while (!vec1.empty() && !vec2.empty()) {
            vec2.pop_back(); vec1.pop_back();
            ans += y;
        }
        
        return ans;
    }
};
// @lc code=end

