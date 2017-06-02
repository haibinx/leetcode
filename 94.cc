// https://leetcode.com/problems/binary-tree-inorder-traversal/#/description
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
    
    void helper(TreeNode* root, vector<int> & ans) {
        if (!root) return;
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }
    
    // Solution 2
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode * curr = root;
        while (!s.empty() || curr) {
            if (curr) {
                s.push(curr);
                curr = curr->left;
            } else {
                TreeNode * n = s.top();
                s.pop();
                ans.push_back(n->val);
                curr = n->right;
            }
        }
        return ans;
    }
    
    // Solution 3
    vector<int> inorderTraversal3(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr) {
            if (!curr->left) {
                ans.push_back(curr->val);
                curr= curr->right;
            } else {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr) prev = prev->right;
                
                if (!prev->right) {
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    prev->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
