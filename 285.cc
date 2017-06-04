// https://leetcode.com/problems/inorder-successor-in-bst

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *res = NULL;
        while (root) {
            if (root->val > p->val) {
                res = root;
                root = root->left;
            } else root = root->right;
        }
        return res;
    }

    // Solution 2
    TreeNode* inorderSuccessor2(TreeNode* root, TreeNode* p) {
        if (!root) return NULL;
        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        } else {
            TreeNode *left = inorderSuccessor(root->left, p);
            return left ? left : root;
        }
    }
};
