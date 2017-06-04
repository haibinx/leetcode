// https://leetcode.com/problems/remove-nth-node-from-end-of-list/#/description
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* fast = head;
        for (int i = 0; i < n; i++)  fast = fast->next;
        if (!fast) {
            return head->next;
        }
        ListNode* slow = head;
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};
