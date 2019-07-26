/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (45.53%)
 * Likes:    385
 * Dislikes: 646
 * Total Accepted:    66.2K
 * Total Submissions: 145.3K
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 * 
 * For example, the above binary watch reads "3:25".
 * 
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 * 
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 * 
 * 
 * Note:
 * 
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 * 
 * 
 */
class Solution {
public:
    const int LEDs[6] = {1, 2, 4, 8, 16, 32};
    void backtracking(vector<string> &res, int hour, int min, int pos, int left) {
        if(left == 0) {
            if(hour < 12 && min < 60) {
                stringstream ss;
                ss << setw(1) << hour << ":" << setw(2) << setfill('0') << min;
                res.push_back(ss.str());
            }
            return;
        }

        if(pos > 5 || left < 0 || hour > 11 || min > 59) {
            return;
        }
        
        backtracking(res, hour, min+LEDs[pos], pos+1, left-1);
        backtracking(res, hour, min, pos+1, left);
        if(pos < 4) {
            backtracking(res, hour+LEDs[pos], min, pos+1, left-1);
            backtracking(res, hour+LEDs[pos], min+LEDs[pos], pos+1, left-2);
        }
    }

    vector<string> readBinaryWatch(int num) {
        vector<string> times;
        backtracking(times, 0, 0, 0, num);
        return times;
    }
};

