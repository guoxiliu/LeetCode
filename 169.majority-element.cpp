/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_map<int, int> countMap;
        for(int i = 0; i < nums.size(); i++) {
            if(++countMap[nums[i]] > nums.size()/2) {
                return nums[i];
            }
        }
        return 0;
    }
};

