/*
 * @lc app=leetcode id=1734 lang=cpp
 *
 * [1734] Decode XORed Permutation
 *
 * https://leetcode.com/problems/decode-xored-permutation/description/
 *
 * algorithms
 * Medium (58.84%)
 * Likes:    398
 * Dislikes: 15
 * Total Accepted:    7.8K
 * Total Submissions: 13.2K
 * Testcase Example:  '[3,1]'
 *
 * There is an integer array perm that is a permutation of the first n positive
 * integers, where n is always odd.
 * 
 * It was encoded into another integer array encoded of length n - 1, such that
 * encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then
 * encoded = [2,1].
 * 
 * Given the encoded array, return the original array perm. It is guaranteed
 * that the answer exists and is unique.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: encoded = [3,1]
 * Output: [1,2,3]
 * Explanation: If perm = [1,2,3], then encoded = [1 XOR 2,2 XOR 3] = [3,1]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: encoded = [6,5,4,6]
 * Output: [2,4,1,5,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= n < 10^5
 * n is odd.
 * encoded.length == n - 1
 * 
 * 
 */

// @lc code=start
/**
 * Basic XOR rules: (1) a ^ a = 0; (2) a ^ b = b ^ a; (3) a ^ 0 = 0.
 * The solution is to get the XOR result of the entire permutation, get the XOR result 
 * of the adjacent elements from encoded array, and then XOR the above two results to 
 * get the last element of the original array. Thus, we can reverse the encoding 
 * process to get the original array.
 */ 
class Solution {
public:
    // Calculate XOR from 1 to n
    // The XOR results repeat with a cycle of 4
    int xor_all (int n) {
        switch(n & 3) {
            case 0:
                return n;
            case 1:
                return 1;
            case 2:
                return n+1;
            case 3: 
                return 0;
        }
        return 0;
    }
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        vector<int> ans(n+1);
        int all = xor_all(n+1);
        int adj = 0;
        for (int i = 0; i < n; i+=2) {
            adj = adj ^ encoded[i];
        }
        int last = all ^ adj;
        ans[n] = last;
        for (int i = n-1; i >= 0; i--) {
            last = encoded[i] ^ last;
            ans[i] = last;
        }
        return ans;
    }
};
// @lc code=end
