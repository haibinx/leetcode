// https://leetcode.com/problems/validate-binary-search-tree/#/description
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
    bool isValidBST(TreeNode* root) {
        TreeNode *pre = nullptr;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                TreeNode * n = s.top();
                s.pop();
                if (pre && pre->val >= n->val) return false;
                pre = n;
                p = n->right;
            }
        }
        return true;
    }

    // Solution 2
    TreeNode* pre = nullptr;
    bool isValidBST2(TreeNode* root) {
        if (!root) return true;
        if (!isValidBST(root->left)) return false;
        if (pre && pre->val >= root->val) return false;
        pre = root;
        return isValidBST(root->right);
    }
};
