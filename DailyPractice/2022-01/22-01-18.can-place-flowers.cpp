#include "../leetcode.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int sz = fb.size();
        for (int i = 0; i < sz; i++) {
            if (fb[i] == 0) {
                if (i > 0 && i + 1 < sz) {
                    if (fb[i-1] == 0 && fb[i+1] == 0) {
                        fb[i] = 1;
                        n--;
                    }
                }
                else if (i == 0) {
                    if (i + 1 >= sz || (i+1 < sz && fb[i+1] == 0)) {
                        fb[i] = 1;
                        n--;
                    }
                }
                else if (i == sz-1 && fb[i-1] == 0) {
                    fb[i] = 1;
                    n--;
                }
            }
        }

        return n <= 0;
    }
};

