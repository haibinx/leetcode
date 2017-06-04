// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/#/description
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> row;
            for (int i = 0; i < n; i++) {
                TreeNode * p = q.front();
                q.pop();
                row.push_back(p->val);
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            if (level++ & 1) {
                reverse(row.begin(), row.end());
            }
            ans.push_back(row);
        }
        return ans;
    }
};
