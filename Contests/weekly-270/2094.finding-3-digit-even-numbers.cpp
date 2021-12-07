/*
 * @lc app=leetcode id=2094 lang=cpp
 *
 * [2094] Finding 3-Digit Even Numbers
 *
 * https://leetcode.com/problems/finding-3-digit-even-numbers/description/
 *
 * algorithms
 * Easy (49.45%)
 * Likes:    55
 * Dislikes: 74
 * Total Accepted:    6.2K
 * Total Submissions: 12.6K
 * Testcase Example:  '[2,1,3,0]'
 *
 * You are given an integer array digits, where each element is a digit. The
 * array may contain duplicates.
 * 
 * You need to find all the unique integers that follow the given
 * requirements:
 * 
 * 
 * The integer consists of the concatenation of three elements from digits in
 * any arbitrary order.
 * The integer does not have leading zeros.
 * The integer is even.
 * 
 * 
 * For example, if the given digits were [1, 2, 3], integers 132 and 312 follow
 * the requirements.
 * 
 * Return a sorted array of the unique integers.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = [2,1,3,0]
 * Output: [102,120,130,132,210,230,302,310,312,320]
 * Explanation: 
 * All the possible integers that follow the requirements are in the output
 * array. 
 * Notice that there are no odd integers or integers with leading zeros.
 * 
 * Example 2:
 * 
 * 
 * Input: digits = [2,2,8,8,2]
 * Output: [222,228,282,288,822,828,882]
 * Explanation: 
 * The same digit can be used as many times as it appears in digits. 
 * In this example, the digit 8 is used twice each time in 288, 828, and
 * 882. 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = [3,7,5]
 * Output: []
 * Explanation: 
 * No even integers can be formed using the given digits.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: digits = [0,2,0,0]
 * Output: [200]
 * Explanation: 
 * The only valid integer that can be formed with three digits and no leading
 * zeros is 200.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: digits = [0,0,0]
 * Output: []
 * Explanation: 
 * All the integers that can be formed have leading zeros. Thus, there are no
 * valid integers.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> times(10, 0);
        for (int &digit : digits) {
            times[digit]++;
        }
        vector<int> ans;
        int n = digits.size();
        for (int i = 1; i < 10; i++) {
            if (times[i] == 0) continue;
            times[i]--;
            for (int j = 0; j < 10; j++) {
                if (times[j] == 0) continue;
                times[j]--;
                for (int k = 0; k < 10; k++) {
                    if (times[k] == 0) continue;
                    int num = i * 100 + j * 10 + k;
                    if (num % 2 == 0) ans.push_back(num);
                }
                times[j]++;
            }
            times[i]++;
        }
        return ans;
    }
};
// @lc code=end

