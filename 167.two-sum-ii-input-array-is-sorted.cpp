/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res{};
        int low = 0, high = numbers.size()-1;
        while(low < high) {
            if(numbers[low] + numbers[high] == target) {
                return vector<int>{low+1, high+1};
            } else if(numbers[low]+numbers[high] > target) {
                high--;
            } else {
                low++;
            }
        }
        return vector<int>{};
    }
};

