// https://leetcode.com/problems/recover-binary-search-tree/#/description
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (!root) return;
        TreeNode* cur = root, *first = nullptr, *second = nullptr, *prev = nullptr, *p;
        while(cur) {
            if (!cur->left) {
                if (prev && prev->val > cur->val) {
                    if (!first) {
                        first = prev;
                        second = cur;
                    } else {
                        second = cur;
                    }
                }
                prev = cur;
                cur = cur->right;
            } else {
                p = cur->left;
                while (p->right && p->right != cur)
                    p = p->right;
                 
                if (!p->right) {
                    p->right = cur;
                    cur = cur->left;
                } else {
                    p->right = nullptr;
                    if (prev && prev->val > cur->val) {
                        if (!first) {
                            first = prev;
                            second = cur;
                        } else {
                            second = cur;
                        }
                    }
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        swapNode(first, second);
    }
    
    void swapNode(TreeNode* p, TreeNode* q) {
        int temp = p->val;
        p->val = q->val;
        q->val = temp;
    }
};
