#include "../leetcode.h"

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        
        while (low < high) {
            int middle = (low + high) / 2;
            int hours = 0;
            for (int &p : piles) {
                hours += p / middle + (p % middle != 0);
            }
            if (hours <= h) {
                high = middle;
            } else {
                low = middle + 1;
            }
        }
        
        return high;
    }
};

