// https://leetcode.com/problems/palindrome-linked-list
//
// Given a singly linked list, determine if it is a palindrome.
//

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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        for (int i = 0; i < v.size()/2; ++i) {
            if (v[i] != v[v.size() - 1 -i]) return false;
        }
        return true;
    }
};
