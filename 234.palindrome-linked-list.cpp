/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (36.54%)
 * Likes:    1769
 * Dislikes: 260
 * Total Accepted:    277.3K
 * Total Submissions: 758.7K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    /*
    // Use a stack to store the nodes.
    bool isPalindrome(ListNode* head) {
        ListNode *iter = head;
        stack<int> values;
        while(iter) {
            values.push(iter->val);
            iter = iter->next;
        }
        iter = head;
        while(iter) {
            if(values.top() != iter->val) {
                return false;
            }
            values.pop();
            iter = iter->next;
        }
        return true;
    }
    */

   // Check palindrome by reversing the list.
   bool isPalindrome(ListNode* head) {
       // reverse the first half of the linked list
       ListNode *slow_ptr = head, *fast_ptr = head, *rev_ptr = NULL;
       while(fast_ptr && fast_ptr->next) {
           fast_ptr = fast_ptr->next->next;
           ListNode *tmp = slow_ptr->next;
           slow_ptr->next = rev_ptr;
           rev_ptr = slow_ptr;
           slow_ptr = tmp;
       }
       // if the size of the linked list is odd
       if(fast_ptr) slow_ptr = slow_ptr->next;
       while(slow_ptr && rev_ptr) {
           if(slow_ptr->val != rev_ptr->val) {
               return false;
           }
           slow_ptr = slow_ptr->next;
           rev_ptr = rev_ptr->next;
       }
       return true;
   }
};

