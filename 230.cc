// https://leetcode.com/problems/kth-smallest-element-in-a-bst/#/description
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
    int kthSmallest(TreeNode* root, int k) {
        int vis = 0;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while (!s.empty() || curr) {
            if (curr) {
                s.push(curr);
                curr = curr->left;
            } else {
                TreeNode * n = s.top();
                if (++vis == k) return n->val;
                s.pop();
                curr = n->right;
            }
        }
        return 0;
    }
};
