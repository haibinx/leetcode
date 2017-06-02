// https://leetcode.com/problems/odd-even-linked-list/#/description
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode oddDummy(0);
        ListNode evenDummy(0);
        ListNode* oddPre = &oddDummy;
        ListNode* evenPre = &evenDummy;
        
        ListNode* curr = head;
        bool odd = true;
        while(curr) {
            if (odd) {
                oddPre->next = curr;
                oddPre = curr;
            } else {
                evenPre->next = curr;
                evenPre = curr;
            }
            odd = !odd;
            curr = curr->next;
        }
        oddPre->next = evenDummy.next;
        evenPre->next = nullptr;
        return oddDummy.next;
    }
};
