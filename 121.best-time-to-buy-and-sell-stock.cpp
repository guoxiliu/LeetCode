/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
#include <vector>
#include <cmath>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0, minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            minPrice = std::min(prices.at(i), minPrice);
            maxPro = std::max(maxPro, prices.at(i) - minPrice);
        }
        return maxPro;
    }
};

