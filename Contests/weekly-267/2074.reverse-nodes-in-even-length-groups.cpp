/*
 * @lc app=leetcode id=2074 lang=cpp
 *
 * [2074] Reverse Nodes in Even Length Groups
 *
 * https://leetcode.com/problems/reverse-nodes-in-even-length-groups/description/
 *
 * algorithms
 * Medium (42.13%)
 * Likes:    35
 * Dislikes: 68
 * Total Accepted:    3.5K
 * Total Submissions: 8.4K
 * Testcase Example:  '[5,2,6,3,9,1,7,3,8,4]'
 *
 * You are given the head of a linked list.
 * 
 * The nodes in the linked list are sequentially assigned to non-empty groups
 * whose lengths form the sequence of the natural numbers (1, 2, 3, 4, ...).
 * The length of a group is the number of nodes assigned to it. In other
 * words,
 * 
 * 
 * The 1^st node is assigned to the first group.
 * The 2^nd and the 3^rd nodes are assigned to the second group.
 * The 4^th, 5^th, and 6^th nodes are assigned to the third group, and so on.
 * 
 * 
 * Note that the length of the last group may be less than or equal to 1 + the
 * length of the second to last group.
 * 
 * Reverse the nodes in each group with an even length, and return the head of
 * the modified linked list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [5,2,6,3,9,1,7,3,8,4]
 * Output: [5,6,2,3,9,1,4,8,3,7]
 * Explanation:
 * - The length of the first group is 1, which is odd, hence no reversal
 * occurrs.
 * - The length of the second group is 2, which is even, hence the nodes are
 * reversed.
 * - The length of the third group is 3, which is odd, hence no reversal
 * occurrs.
 * - The length of the last group is 4, which is even, hence the nodes are
 * reversed.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,1,0,6]
 * Output: [1,0,1,6]
 * Explanation:
 * - The length of the first group is 1. No reversal occurrs.
 * - The length of the second group is 2. The nodes are reversed.
 * - The length of the last group is 1. No reversal occurrs.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [2,1]
 * Output: [2,1]
 * Explanation:
 * - The length of the first group is 1. No reversal occurrs.
 * - The length of the last group is 1. No reversal occurrs.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: head = [8]
 * Output: [8]
 * Explanation: There is only one group whose length is 1. No reversal
 * occurrs.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [1, 10^5].
 * 0 <= Node.val <= 10^5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Get the actual length of a group 
    int getLength(ListNode *node, int limit) {
        int len = 0;
        while (node) {
            len++;
            node = node->next;
            if (len >= limit) 
                return limit;
        }
        
        return len;
    }
    
    // Reverse the sublist of a linked list with the given length
    ListNode *reverseList(ListNode *node, int len) {
        int idx = 0;
        ListNode *current = node;
        ListNode *previous = nullptr, *next = nullptr;
        while (idx < len) {
            previous = current;
            current = current->next;
            previous->next = next;
            next = previous;
            idx++;
        }
        node->next = current;
        return next;
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (head == nullptr) return head;
        
        ListNode *iter = head;
        int number = 2;
        while (iter) {
            // check the length
            int len = getLength(iter->next, number);
            if (len == 0) break;
            
            // reverse the list if the length is even
            if (len % 2 == 0) {
                ListNode *reverse_head = reverseList(iter->next, len);
                iter->next = reverse_head;
            }
            if (len < number) break;

            // go to the next group
            for (int i = 0; i < number; i++) {
                iter = iter->next;
            }
            number++;
        }
        
        return head;
    }
};
// @lc code=end

