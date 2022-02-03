#include "../leetcode.h"

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;
        int i = 0;
        for (; i < n-1; i++) {
            if (arr[i] >= arr[i+1]) break;
            if (i == n-2) return false;
        }
        if (i == 0) return false;
        for (int j = i+1; j < n; j++) {
            if (arr[j] >= arr[j-1]) return false;
        }
        
        return true;
    }
};
