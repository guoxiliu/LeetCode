#include "../leetcode.h"

class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        vector<int> remainder(60, 0);
        for (int duration : time) {
            remainder[duration%60]++;
        }

        int ans = 0;
        for (int i = 0; i <= 30; i++) {
            if (i == 0 || i == 30) {
                ans += (remainder[i] * (remainder[i]-1)) / 2;
            }
            else {
                ans += (remainder[i] * remainder[60-i]);
            }
        }

        return ans;
    }
};
