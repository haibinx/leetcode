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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
    void helper(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        helper(root->left, ans);
        helper(root->right, ans);
        ans.push_back(root->val);
    }

    // Solution 2
    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode*, bool>> s;
	    TreeNode* p = root;
	    while(p || !s.empty()) {
		  if (p) {
		      s.push(make_pair(p, false));
		      p = p->left;
		  } else {
		      pair<TreeNode *, bool> n = s.top();
		      s.pop();
		      if (n.second) {
		          ans.push_back(n.first->val);
		      } else {
		          n.second = true;
		          s.push(n);
		          p = n.first->right;
		      }
		  }
        }
        return ans;
    }
};
