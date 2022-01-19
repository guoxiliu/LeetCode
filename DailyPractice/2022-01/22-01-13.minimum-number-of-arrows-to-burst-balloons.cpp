#include "../leetcode.h"

bool compare(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), compare);
        int ans = 0, end = 0;
        for (int i = 0; i < points.size(); i++) {
            if (ans == 0 || points[i][0] > end) {
                ans++;
                end = points[i][1];
            }
        }

        return ans;
    }
};

