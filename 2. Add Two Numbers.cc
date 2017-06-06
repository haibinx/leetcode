// https://leetcode.com/problems/add-two-numbers/#/description
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        int carry = 0;
        ListNode dummy(0);
        ListNode * p = &dummy;
        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode * node = new ListNode(sum % 10);
            p->next = node;
            p = node;
            carry = (sum) / 10;
        }
        if (carry) {
            ListNode * node = new ListNode(1);
            p->next = node;
        }
        return dummy.next;
    }
};
