#include "leetcode.h"

class Solution {
public: 
    void reorderList(ListNode *head) {
        if (head == nullptr) return;
        ListNode *iter = head;
        stack<ListNode *> st;
        // get the length of the list 
        int len = 0, cnt = 0;
        while (iter) {
            len++;
            st.push(iter);
            iter = iter->next;
        }
        if (len < 3) return;

        // the middle node
        iter = head;
        bool op = true;
        while (iter) {
            cnt++;
            if (cnt == len) {
                iter->next = nullptr;
                break;
            }
            if (op) {
                st.top()->next = iter->next;
                iter->next = st.top();
                st.pop();
            } 
            op = !op;
            iter = iter->next;
        }
    }
};
