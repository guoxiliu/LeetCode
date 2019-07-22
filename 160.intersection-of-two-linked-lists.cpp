/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *iterA = headA;
        ListNode *iterB = headB;
        int numA = 0, numB = 0;
        while(iterA) {
            numA++;
            iterA = iterA->next;
        }
        while (iterB) {
            numB++;
            iterB = iterB->next;
        }
        iterA = headA; 
        iterB = headB;
        if(numA > numB) {
            for(int i = 0; i < numA-numB; i++){
                iterA = iterA->next;
            }
        } else {
            for(int i = 0; i < numB-numA; i++){
                iterB = iterB->next;
            }
        }
        while(iterA && iterB && iterA != iterB) {
            iterA = iterA->next;
            iterB = iterB->next;
        }
        return iterA;
    }
};

