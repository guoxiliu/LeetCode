#include "../leetcode.h"

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 1) return true;
        // the first letter is capital
        if (word[0] >= 'A' && word[0] <= 'Z') {
            // all letters should be captials or lower case
            if (word[1] >= 'A' && word[1] <= 'Z') {
                for (int i = 2; i < n; i++) {
                    if (word[i] >= 'a' && word[i] <= 'z') return false;
                }
            }
            else {
                for (int i = 2; i < n; i++) {
                    if (word[i] >= 'A' && word[i] <= 'Z') return false;
                }
            }
            
        }
        else {
            for (int i = 1; i < n; i++) {
                if (word[i] >= 'A' && word[i] <= 'Z') return false;
            }
        }
        return true;
    }
};
