// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
//
// Given a sorted linked list, delete all duplicates such that each element appear only once.
//
// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.
//

/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 **/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* retVal = head;
        ListNode* prev = 0;
        
        while (head) {
            if (prev && (prev->val == head->val)) {
                ListNode* tmp = head;
                prev->next = head->next;
                head = head->next;
                delete tmp;
            } else {
                prev = head;
                head = head->next;
            }
        }
        return retVal;
    }
};
