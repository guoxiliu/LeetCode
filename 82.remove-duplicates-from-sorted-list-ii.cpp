/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (32.52%)
 * Total Accepted:    174.5K
 * Total Submissions: 536.2K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        // If the first value has duplicates
        while (head != NULL && head->next != NULL && head->next->val == head->val) {
            while (head->next != NULL && head->next->val == head->val) 
                head = head->next;
            head = head->next;
        }

        // Just go through the whole list and remove duplicates
        ListNode *p1 = head, *p2;
        while (p1 != NULL && p1->next != NULL) {
            p2 = p1->next;
            bool flag = false;
            while (p2->next != NULL && p2->next->val == p2->val)  {
                flag = true;
                p2 = p2->next;
            }
            if (flag)
                p1->next = p2->next;
            else 
                p1 = p1->next;
        }

        return head;
    }
};

