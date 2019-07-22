/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (29.42%)
 * Likes:    1144
 * Dislikes: 426
 * Total Accepted:    251.5K
 * Total Submissions: 854.8K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        bool prime[n];
        memset(prime, true, sizeof(prime));
        int counts = 1;
        int upper = sqrt(n);
        // scan only odd numbers
        for(int i = 3; i < n; i+=2) {
            if(prime[i]) {
                counts++;
                // avoid i*i overflow
                if(i > upper) continue;
                // increase j by 2*i to keep j as an odd number
                for(int j = i*i; j < n; j+=2*i) {
                    prime[j] = false;
                }
            }
        }
        return counts;
    }
};

