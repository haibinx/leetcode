// https://leetcode.com/problems/reverse-nodes-in-k-group/#/description
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* curr = head;
        int num = 0;
        while (curr) {
            num++;
            curr= curr->next;
        }
        curr = head;
        while (num >= k) {
            ListNode* p = pre;
            pre = p->next;
            for (int j = 0; j < k-1; ++j) {
                ListNode* r = pre->next;
                pre->next = r->next;
                r->next = p->next;
                p->next = r;
            }
            num -= k;
        }
        return dummy.next;
    }
};
