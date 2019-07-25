/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (55.60%)
 * Likes:    434
 * Dislikes: 846
 * Total Accepted:    234.5K
 * Total Submissions: 421.8K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * 
 * 
 * Note:
 * 
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            return intersection(nums2, nums1);
        }

        unordered_set<int> num1_set(nums1.begin(), nums1.end());
        vector<int> res;
        for(int i = 0; i < nums2.size(); i++) {
            if(num1_set.count(nums2[i])) {
                res.push_back(nums2[i]);
                num1_set.erase(nums2[i]);
            }
        }

        return res;
    }
};

