/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (36.65%)
 * Total Accepted:    158K
 * Total Submissions: 430K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *p1 = new ListNode(0);
        ListNode *p2 = new ListNode(0);
        ListNode *node1 = p1, *node2 = p2;

        while (head != NULL) {
            if (head->val < x) {
                node1->next = head;
                node1 = node1->next;
            } else {
                node2->next = head;
                node2 = node2->next;
            }
            head = head->next;
        }

        node2->next = NULL;
        node1->next = p2->next;

        return p1->next;
    }
};

