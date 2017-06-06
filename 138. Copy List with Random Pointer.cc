// https://leetcode.com/problems/copy-list-with-random-pointer/#/description
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
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        unordered_map<RandomListNode*, RandomListNode*> mp;
        RandomListNode* cur = head;
        while(cur) {
            RandomListNode* node = new RandomListNode(cur->label);
            mp[cur] = node;
            cur = cur->next;
        }
        
        cur = head;
        while(cur) {
            mp[cur]->next = cur->next ? mp[cur->next] : nullptr;
            mp[cur]->random = cur->random ? mp[cur->random] : nullptr;
            cur = cur->next;
        }
        return mp[head];
    }
};
