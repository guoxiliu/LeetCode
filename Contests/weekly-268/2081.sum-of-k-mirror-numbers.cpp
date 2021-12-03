/*
 * @lc app=leetcode id=2081 lang=cpp
 *
 * [2081] Sum of k-Mirror Numbers
 *
 * https://leetcode.com/problems/sum-of-k-mirror-numbers/description/
 *
 * algorithms
 * Hard (33.99%)
 * Likes:    35
 * Dislikes: 67
 * Total Accepted:    2K
 * Total Submissions: 5.9K
 * Testcase Example:  '2\n5'
 *
 * A k-mirror number is a positive integer without leading zeros that reads the
 * same both forward and backward in base-10 as well as in base-k.
 * 
 * 
 * For example, 9 is a 2-mirror number. The representation of 9 in base-10 and
 * base-2 are 9 and 1001 respectively, which read the same both forward and
 * backward.
 * On the contrary, 4 is not a 2-mirror number. The representation of 4 in
 * base-2 is 100, which does not read the same both forward and backward.
 * 
 * 
 * Given the base k and the number n, return the sum of the n smallest k-mirror
 * numbers.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 2, n = 5
 * Output: 25
 * Explanation:
 * The 5 smallest 2-mirror numbers and their representations in base-2 are
 * listed as follows:
 * ⁠ base-10    base-2
 * ⁠   1          1
 * ⁠   3          11
 * ⁠   5          101
 * ⁠   7          111
 * ⁠   9          1001
 * Their sum = 1 + 3 + 5 + 7 + 9 = 25. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: 499
 * Explanation:
 * The 7 smallest 3-mirror numbers are and their representations in base-3 are
 * listed as follows:
 * ⁠ base-10    base-3
 * ⁠   1          1
 * ⁠   2          2
 * ⁠   4          11
 * ⁠   8          22
 * ⁠   121        11111
 * ⁠   151        12121
 * ⁠   212        21212
 * Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: k = 7, n = 17
 * Output: 20379000
 * Explanation: The 17 smallest 7-mirror numbers are:
 * 1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064,
 * 6597956, 6958596
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= k <= 9
 * 1 <= n <= 30
 * 
 * 
 */

// @lc code=start
class Solution {
    // convert a number to string with the given base
    string long2string(long long value, int radix) {
        const char base10[] = "0123456789";
        string result;
        while (value > 0) {
            long long remainder = value % radix;
            value /= radix;
            result.insert(result.begin(), base10[remainder]);
        }
        return result;
    }
    // check if a string is palindrome
    bool ispal(string str) {
        for (int i = 0, j = str.length()-1; i < j; i++, j--) {
            if (str[i] != str[j]) return false;
        }
        return true;
    }
public:
    long long kMirror(int k, int n) {
        long long ans = 0;
        for (int len = 1; ;len++) {
            int x = pow(10, (len-1)/2);
            int y = pow(10, (len+1)/2);
            
            for (int i = x; i < y; i++) {
                // get the mirror number in base 10
                long long b = i;
                for (int j = len % 2 == 1 ? i/10 : i; j > 0; j /= 10) {
                    b = b*10 + j % 10;
                }
                string h = long2string(b, k);
                if (ispal(h)) {
                    ans += b;
                    n--;
                    if (n <= 0)
                        return ans;
                }
            }
        }
        
        return ans;
    }
};
// @lc code=end

