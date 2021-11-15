/*
 * @lc app=leetcode id=1735 lang=cpp
 *
 * [1735] Count Ways to Make Array With Product
 *
 * https://leetcode.com/problems/count-ways-to-make-array-with-product/description/
 *
 * algorithms
 * Hard (49.13%)
 * Likes:    124
 * Dislikes: 24
 * Total Accepted:    2.9K
 * Total Submissions: 5.8K
 * Testcase Example:  '[[2,6],[5,1],[73,660]]'
 *
 * You are given a 2D integer array, queries. For each queries[i], where
 * queries[i] = [ni, ki], find the number of different ways you can place
 * positive integers into an array of size ni such that the product of the
 * integers is ki. As the number of ways may be too large, the answer to the
 * i^th query is the number of ways modulo 10^9 + 7.
 * 
 * Return an integer array answer where answer.length == queries.length, and
 * answer[i] is the answer to the i^th query.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: queries = [[2,6],[5,1],[73,660]]
 * Output: [4,1,50734910]
 * Explanation: Each query is independent.
 * [2,6]: There are 4 ways to fill an array of size 2 that multiply to 6:
 * [1,6], [2,3], [3,2], [6,1].
 * [5,1]: There is 1 way to fill an array of size 5 that multiply to 1:
 * [1,1,1,1,1].
 * [73,660]: There are 1050734917 ways to fill an array of size 73 that
 * multiply to 660. 1050734917 modulo 10^9 + 7 = 50734910.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: queries = [[1,1],[2,2],[3,3],[4,4],[5,5]]
 * Output: [1,2,3,10,5]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= queries.length <= 10^4 
 * 1 <= ni, ki <= 10^4
 * 
 * 
 */

// @lc code=start

#define MOD 1000000007

/**
 * If prime factorizes ki to a1^x1 * a2^x2 * a3^x3, then result is C(ni+x1-1,ni-1) * 
 * C(ni+x2-1,ni-1) * C(ni+x3-1, ni-1).
 * Use H(ni,xi) = C(ni+xi-1,ni-1) to get the number of combinations.
 */ 
class Solution {
    /**
     * Use the prime factorization to get the number of prime numbers for decomposing
     * the given integer.
     */
    vector<int> getPrimeFactorization(int num) {
        vector<int> pf;
        int count = 0;
        for (int i = 2; i <= sqrt(num); i++) {
            while (num % i == 0) {
                count++;
                num /= i;
            }
            if (count) {
                pf.push_back(count);
                count = 0;
            }
        }
        if (num != 1) pf.push_back(1);
        return pf;
    }

    /**
     * The functions below use Euler's theorem of modular multiplicative inverse to 
     * compute the value of n choose r (nCr).
     * (1/a) % m = (a^(m-2)) % m
     */ 

    // Power function to compute (a ^ b) % mod
    // wee need it to compute (a ^ (m-2))
    long power(long a, long b) {
        long x = 1, y = a;
        while (b > 0) {
            if (b % 2) {
                x = (x * y) % MOD;
            }
            y = (y * y) % MOD;
            b /= 2;
        }
        return x % MOD;
    }

    // The function computes (1/a) % m.
    long modInverse(long n) {
        return power(n, MOD-2);
    }

    // The function computes the value of nCr.
    // factorial[n] stores the value of n!
    long nCr(long n, long k, std::vector<long> &factorial) {
        return (factorial[n]*((modInverse(factorial[k]) * modInverse(factorial[n-k])) % MOD)) % MOD; 
    }
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> ans;

        // precompute the factorials
        vector<long> factorials(20001);
        factorials[0] = 1;
        for (int i = 1; i <= 20000; i++) {
            factorials[i] = (factorials[i-1] * i) % MOD;
        }
        
        for (vector<int> query : queries) {
            int n = query[0], k = query[1];
            long res = 1, mod = 1e9+7;
            vector<int> freqs = getPrimeFactorization(k);
            for (int r : freqs) {
                res = (res * nCr(n+r-1, n-1, factorials)) % MOD;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
// @lc code=end
