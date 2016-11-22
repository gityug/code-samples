// https://leetcode.com/problems/copy-list-with-random-pointer/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<RandomListNode*, RandomListNode*>mp;

    RandomListNode *copyRandomList(RandomListNode *head) {
	    if (head == NULL)return head;
	    if (mp.find(head) == mp.end())
	    {
		    mp[head] = new RandomListNode(head->label);
		    mp[head]->next = copyRandomList(head->next);
		    mp[head]->random = copyRandomList(head->random);
	    }
	    return mp[head];
    }
};
