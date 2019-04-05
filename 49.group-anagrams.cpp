/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (45.54%)
 * Total Accepted:    311.9K
 * Total Submissions: 684.9K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings, group anagrams together.
 * 
 * Example:
 * 
 * 
 * Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * Output:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * Note:
 * 
 * 
 * All inputs will be in lowercase.
 * The order of your output does not matter.
 * 
 * 
 */

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> dict;
        int count = 0;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs.at(i);
            sort(s.begin(), s.end());
            // if found in the map
            if (dict.count(s)) {
                res[dict[s]].push_back(strs.at(i));
                continue;
            }
            // if not, we need add it into our map
            dict[s] = count;
            res.push_back(vector<string>{});
            res[count].push_back(strs.at(i));
            count++;
        }
        return res;
    }
};

