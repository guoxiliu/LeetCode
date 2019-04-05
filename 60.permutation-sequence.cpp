/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (32.62%)
 * Total Accepted:    132.8K
 * Total Submissions: 406.9K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */
#include <string>
#include <vector>
using namespace std;

/**
 * The problem seems more like a math problem.
 * For example, n = 4, k = 9.
 * 1, 2, 3, 4
 * 1, 2, 4, 3
 * 1, 3, 2, 4
 * 1, 3, 4, 2
 * 1, 4, 2, 3
 * 1, 4, 3, 2  -- 3! = 6 combinations 
 * 2, 1, 3, 4 
 * 2, 1, 4, 3
 * 2, 3, 1, 4  -- answer
 * 2, 3, 4, 1
 * {1, 2, 3, 4}
 * k = 9 and 9 / 3! + 1 = 2, the first char is 2, then k is changed to 9 % 3! = 3
 * {1, 3, 4}
 * k = 3 and 3 / 2! + 1 = 2, the second char is 3, then k is changed to 3 % 2! = 1
 * {1, 4}
 * k = 1, the third char is 2
 * the left character will be 4
 */ 
class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        vector<int> factorial(n, 1);
        vector<char> num(n, 1);

        for (int i = 1; i < n; i++) {
            factorial[i] = i * factorial[i-1];
        }

        for (int i = 0; i < n; i++) {
            num[i] = i+1+'0';
        }

        k--;
        for (int i = n; i >= 1; i--) {
            int j = k/factorial[i-1];
            k = k%factorial[i-1];
            s.push_back(num[j]);
            num.erase(num.begin()+j);
        }

        return s;
    }
};

