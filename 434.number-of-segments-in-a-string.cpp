/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (37.10%)
 * Likes:    148
 * Dislikes: 576
 * Total Accepted:    58.5K
 * Total Submissions: 157.8K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 * 
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * 
 * Input: "Hello, my name is John"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int countSegments(string s) {
        bool prevSpace = true;
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                if(!prevSpace) {
                    prevSpace = true;
                }
            } else {
                if(prevSpace) count++;
                prevSpace = false;
            }
        }

        return count;
    }
};

