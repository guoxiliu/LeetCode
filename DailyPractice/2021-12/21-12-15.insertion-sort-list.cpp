class Solution {
public: 
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy, *iter = head;
        while (iter) {
            if (iter->next && iter->next->val < iter->val) {
                while (p->next->val < iter->next->val) {
                    p = p->next;
                }
                ListNode *tmp = iter->next;
                iter->next = iter->next->next;
                tmp->next = p->next;
                p->next = tmp;
                p = dummy;
            }
            else {
                iter = iter->next;
            }
        }
        return dummy->next;
    }
};
