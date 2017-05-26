#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;
class TreeNode {
public:
  int val;
  TreeNode *left, *right;
  TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

unordered_map<TreeNode*, unordered_set<TreeNode*>> mp;

unordered_set<TreeNode*> traverse(TreeNode* root) {
  if (!root) return unordered_set<TreeNode*>();
  unordered_set<TreeNode*> l = traverse(root->left);
  unordered_set<TreeNode*> r = traverse(root->right);
  l.insert(r.begin(), r.end());
  l.insert(root);
  mp[root] = l;
  return l;
}

TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
  TreeNode* curr = root;
  while(curr && mp[curr].find(p) != mp[curr].end() && mp[curr].find(q) != mp[curr].end()) {
    if (curr->left && mp[curr->left].find(p) != mp[curr->left].end() && mp[curr->left].find(q) != mp[curr->left].end()) {
      curr = curr->left;
    } else if (curr->right && mp[curr->right].find(p) != mp[curr->right].end() && mp[curr->right].find(q) != mp[curr->right].end()) {
      curr = curr->right;
    } else {
      return curr;
    }
  }
  return nullptr;
}

TreeNode* buildTree(const string& bfs) {
  if (bfs.empty() || bfs == "#") return nullptr;
  istringstream iss(bfs);
  string token;
  queue<TreeNode*> q;
  if (!getline(iss, token, ',')) {
    cout << "Input error." << endl;
    return nullptr;
  }
  TreeNode * root = new TreeNode(stoi(token));
  q.push(root);
  while(!iss.eof()) {
    TreeNode* pa = q.front();
    q.pop();
    if (!getline(iss, token, ',')) {
      cout << "Input error." << endl;
      return nullptr;
    }
    if (token != "#") {
      TreeNode* node = new TreeNode(stoi(token));
      pa->left = node;
      q.push(node);
    }
    if (!getline(iss, token, ',')) {
       cout << "Input error." << endl;
       return nullptr;
    }
    if (token != "#") {
      TreeNode* node = new TreeNode(stoi(token));
      pa->right = node;
      q.push(node);
    }
  }
  return root;
}

void printTree(const TreeNode* root) {
  if (!root) return;
  cout << root->val << ",";
  printTree(root->left);
  printTree(root->right);
}

void deleteTree(const TreeNode* root) {
  if (!root) return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

int main() {
  TreeNode* root = buildTree("1,2,3,4,#,6,7,#,5,#,#,8,#");
  printTree(root);
  cout << endl;
  traverse(root);
  cout << LCA(root, root->left->left, root->right->left)->val << endl;
  cout << LCA(root, root->left->left, root->left->left->right)->val << endl;
  cout << LCA(root, root->right->left, root->right->right)->val << endl;
  deleteTree(root);
  return 0;
}
