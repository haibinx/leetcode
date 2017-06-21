// https://leetcode.com/problems/find-bottom-left-tree-value/#/description
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
    /*int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = root->val;
        while(!q.empty()) {
            int n = q.size();
            res = q.front()->val;
            for (int i = 0; i < n; i++) {
                TreeNode* p = q.front();
                q.pop();
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
        }
        return res;
    }*/
    
    int findBottomLeftValue(TreeNode* root) {
        pair<int,int> result(root->val,1); //root!=null
        dfs(root,1,result);
        return result.first;
    }
private:
    void dfs(TreeNode* root,int height,pair<int,int>& res)
    {
        if(!root->left && !root->right && height>res.second)
        {
            res = make_pair(root->val,height);
        }
        if(root->left) dfs(root->left,height+1,res);
        if(root->right) dfs(root->right,height+1,res);
    }
};
