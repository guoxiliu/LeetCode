#include "../leetcode.h"

class Solution {
public: 
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0, cur = 0, startIndex = 0;
        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            cur += diff;
            if (cur < 0) {
                startIndex = i + 1;
                cur = 0;
            }
        }
        if (total < 0) 
            return -1;

        return startIndex;
    }
};
