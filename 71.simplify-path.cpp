/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (28.38%)
 * Total Accepted:    145K
 * Total Submissions: 510.8K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it. Or in other
 * words, convert it to the canonical path.
 * 
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level. For more
 * information, see: Absolute path vs relative path in Linux/Unix
 * 
 * Note that the returned canonical path must always begin with a slash /, and
 * there must be only a single slash / between two directory names. The last
 * directory name (if it exists) must not end with a trailing /. Also, the
 * canonical path must be the shortest string representing the absolute
 * path.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 * 
 * 
 * Example 6:
 * 
 * 
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 * 
 * 
 */

#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    void stack_op(string str, vector<string>& stack) {
        if (str == ".") {}
        else if (str == "..") { 
            if (!stack.empty()) 
                stack.pop_back(); 
        }
        else { stack.push_back(str); }
    }

    string simplifyPath(string path) {
        if (path.size() < 1) return "";

        vector<string> path_stack;
        string res, cur;
        int pos = -1;

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (i - pos <= 1) {
                    pos = i;
                    continue;
                }
                cur = path.substr(pos+1, i-pos-1);
                stack_op(cur, path_stack);
                pos = i;
            }

            else if (i == path.size()-1) {
                cur = path.substr(pos+1, i-pos);
                stack_op(cur, path_stack);
                pos = i;
            }
        }

        if (path_stack.empty()) return "/";

        vector<string>::iterator iter;
        // for (iter = path_stack.begin(); iter != path_stack.end(); iter++) {
        //     cout << *iter << endl;
        // }
        res = "";
        for (iter = path_stack.begin(); iter != path_stack.end(); iter++) {
            res += ("/" + *iter);
        }
        
        return res;
    }
};

