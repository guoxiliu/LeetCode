#include "../leetcode.h"

class Solution {
    vector<int> vec;
    int length;
public:
    Solution(ListNode* head) {
        while (head) {
            vec.push_back(head->val);
            head = head->next;
        }
        length = vec.size();
    }
    
    int getRandom() {
        int idx = rand() % length;
        return vec[idx];
    }
};
