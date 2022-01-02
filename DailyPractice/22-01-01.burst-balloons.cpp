#include "leetcode.h"

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        // dp[i][j] is the maximum coins that can be obtained by 
        // bursting balloons only in the range [i,j]
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));


        for (int len = 1; len <= n; len++) {
            for (int start = 1; start <= n-len+1; start++) {
                int end = start+len-1;
                int maxCoins = 0;
                for (int final = start; final <= end; final++) {
                    int coins = dp[start][final-1] + dp[final+1][end];
                    coins += nums[start-1] * nums[final] * nums[end+1];
                    if (coins > maxCoins) maxCoins = coins;
                }
                dp[start][end] = maxCoins;
            }
        }
        
        return dp[1][n];
    }
};
