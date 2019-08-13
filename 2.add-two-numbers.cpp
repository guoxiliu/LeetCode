/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.55%)
 * Likes:    5687
 * Dislikes: 1461
 * Total Accepted:    964.8K
 * Total Submissions: 3.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = new ListNode(0);
        ListNode *iter = head;

        while(l1 || l2) {
            int x, y, sum = 0;
            x = (l1 != NULL) ? l1->val : 0;
            y = (l2 != NULL) ? l2->val : 0;
            sum = x + y + carry;
            iter->next = new ListNode(sum % 10);
            carry = sum / 10;
            if(l1) l1 = l1->next; 
            if(l2) l2 = l2->next; 
            iter = iter->next;
        }
        if(carry) iter->next = new ListNode(1);
        
        return head->next;
    }
};

