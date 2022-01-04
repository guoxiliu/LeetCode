#include "../leetcode.h"

class Solution {
    static int dist(vector<int> &vec) {
        return (vec[0]*vec[0] + vec[1]*vec[1]);
    }

    static bool compare(vector<int> &a, vector<int> &b) {
        int dist1 = dist(a), dist2 = dist(b);
        return dist1 < dist2;
    }
public: 
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        sort(points.begin(), points.end(), compare);
        vector<vector<int>> ans;
        ans = vector<vector<int>>(points.begin(), points.begin()+k);
        return ans;
    }
};
