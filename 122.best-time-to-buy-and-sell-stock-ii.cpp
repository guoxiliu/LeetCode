/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 1) return 0;

        int maxPro = 0;
        for (size_t i = 1; i < prices.size(); i++)
        {
            if(prices.at(i) - prices.at(i-1) > 0)
            {
                maxPro += prices.at(i)-prices.at(i-1);
            }
        }
        return maxPro;
    }
};

