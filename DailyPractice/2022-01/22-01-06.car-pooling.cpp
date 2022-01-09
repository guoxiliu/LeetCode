#include "../leetcode.h"

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> a(1005, 0);
        for (int i = 0; i < trips.size(); i++) {
            a[trips[i][1]] += trips[i][0];
            a[trips[i][2]] -= trips[i][0];
        }
        
        int res = 0;
        for (int i = 0; i <= 1000; i++) {
            res += a[i];
            if (res > capacity) return false;
        }
        
        return true;
    }
};
