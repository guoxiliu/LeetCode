/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (50.20%)
 * Likes:    310
 * Dislikes: 477
 * Total Accepted:    57.2K
 * Total Submissions: 113.7K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is
 * a tuple of points (i, j, k) such that the distance between i and j equals
 * the distance between i and k (the order of the tuple matters).
 * 
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 * 
 * Example:
 * 
 * 
 * Input:
 * [[0,0],[1,0],[2,0]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); i++) {
            unordered_map<int, int> group(points.size());
            for(int j = 0; j < points.size(); j++) {
                if(j == i) continue;

                int dy = points[i][1] - points[j][1];
                int dx = points[i][0] - points[j][0];

                int key = dx*dx + dy*dy;

                ++group[key];
            }

            for(auto& p : group) {
                res += p.second * (p.second-1);
            }
        }

        return res;
    }
};

