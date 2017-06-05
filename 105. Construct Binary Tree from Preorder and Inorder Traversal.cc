// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/#/description
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
    unordered_map<int, int> mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size()) return nullptr;
        int n = preorder.size();
        for (int i = 0; i < n; i++ ) {
            mp[inorder[i]] = i;
        }
        return helper(preorder, 0, n-1, inorder, 0, n-1);
    }
    
    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) return root;
        int rootVal = preorder[preStart];
        int inPos = mp[rootVal];
        int leftLen = inPos - inStart;
        root->left = helper(preorder, preStart + 1, preStart + leftLen, inorder, inStart, inPos - 1);
        root->right = helper(preorder, preStart + leftLen + 1, preEnd, inorder, inPos + 1, inEnd);
        return root;
    }
};
