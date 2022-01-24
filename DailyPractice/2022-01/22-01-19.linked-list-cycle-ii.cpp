#include "../leetcode.h"

class Solution {
public: 
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;
        ListNode *iter = head;
        while (iter) {
            if (nodes.find(iter) == nodes.end()) {
                nodes.insert(iter);
            }
            else {
                return iter;
            }
            iter = iter->next;
        }
        return nullptr;
    }
};

