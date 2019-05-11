/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (34.35%)
 * Total Accepted:    186.6K
 * Total Submissions: 541.1K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m >= n || head == NULL)
            return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev_m_node = dummy;
        for (int i = 1; i < m; i++) {
            prev_m_node = prev_m_node->next;
        }

        ListNode *m_node = prev_m_node->next;
        ListNode *n_node = m_node, *post_n_node = m_node->next;
        for (int i = m; i < n; i++) {
            ListNode *tmp = post_n_node->next;
            post_n_node->next = n_node;
            n_node = post_n_node;
            post_n_node = tmp;
        }
        m_node->next = post_n_node;
        prev_m_node->next = n_node;
        
        return dummy->next;
    }
};

