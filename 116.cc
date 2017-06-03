// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/#/description
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            TreeLinkNode dummy(0);
            TreeLinkNode* pre =&dummy;
            for (int i = 0; i < n; i++) {
                TreeLinkNode* p = q.front();
                q.pop();
                pre->next = p;
                pre = p;
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            pre->next = nullptr;
        }
    }
    
    // Solution 2
    void connect2(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        root->next = nullptr;
        while(!q.empty()) {
            int n = q.size();
            TreeLinkNode dummy(0);
            TreeLinkNode* pre =&dummy;
            for (int i = 0; i < n; i++) {
                TreeLinkNode* p = q.front();
                q.pop();
                if (!p->left) break;
                else q.push(p->left);
                pre->next = p->left;
                p->left->next = p->right;
                pre = p->right;
                if (!p->right) break;
                else q.push(p->right);
            }
            if(pre) pre->next = nullptr;
        }
    }
    
    // Solution 3
    void connect(TreeLinkNode* root) {
        if (!root || !root->left) return;
        root->left->next = root->right;
        connect(root->left);
        connect(root->right);
        if(!root->next) return;
        auto* p = root->right, *q = root->next->left;
        while(p) {
            p->next = q; p = p->right; q = q->left;
        }   
    }
};
