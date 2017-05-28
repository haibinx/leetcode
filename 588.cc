// https://leetcode.com/problems/design-in-memory-file-system/#/description
class FileSystem {
struct TreeNode;
struct Cmp {
    bool operator() (TreeNode* a, TreeNode* b) {
        return a->name < b->name;
    }
};

struct TreeNode {
  string name;
  set<TreeNode*, Cmp> children;
  bool isFile;
  string fileContent;
  TreeNode(string n) : name(n), isFile(false), fileContent("") {}
};
public:
    FileSystem() {
        root = new TreeNode("");
    }
    
    vector<string> ls(string path) {
        vector<string> ans;
        if (path.empty() || path[0] != '/') return ans;
        istringstream iss(path.substr(1));
        string token;
        TreeNode* curr = root;
        while(getline(iss, token, '/')) {
            TreeNode tmp(token);
            if (curr->children.find(&tmp) == curr->children.end()) {
                return ans;
            }
            auto it = curr->children.find(&tmp);
            curr = *it;
        }
        if (curr->isFile) {
            ans.push_back(curr->name);
            return ans;
        } else {
            for ( auto & i : curr->children) {
                ans.push_back(i->name);
            }
            return ans;
        }
    }
    
    void mkdir(string path) {
        if (path.empty() || path[0] != '/') return;
        istringstream iss(path.substr(1));
        string token;
        TreeNode* curr = root;
        while(getline(iss, token, '/')) {
            TreeNode tmp(token);
            if (curr->children.find(&tmp) == curr->children.end()) {
                TreeNode * n = new TreeNode(token);
                curr->children.insert(n);
                curr = n; 
            } else {
                auto it = curr->children.find(&tmp);
                curr = *it;
            }
        }
    }
    
    void addContentToFile(string filePath, string content) {
       if (filePath.empty() || filePath[0] != '/') return;
        istringstream iss(filePath.substr(1));
        string token;
        TreeNode* curr = root;
        while(getline(iss, token, '/')) {
            TreeNode tmp(token);
            if (curr->children.find(&tmp) == curr->children.end()) {
                TreeNode * n = new TreeNode(token);
                curr->children.insert(n);
                curr = n; 
            } else {
                auto it = curr->children.find(&tmp);
                curr = *it;
            }
        }
        curr->isFile = true;
        curr->fileContent += content;
    }
    
    string readContentFromFile(string filePath) {
        if (filePath.empty() || filePath[0] != '/') return "";
        istringstream iss(filePath.substr(1));
        string token;
        TreeNode* curr = root;
        while(getline(iss, token, '/')) {
            TreeNode tmp(token);
            if (curr->children.find(&tmp) == curr->children.end()) {
                return "";
            }
            auto it = curr->children.find(&tmp);
            curr = *it;
        }
        if (!curr->isFile) {
            return "";
        }
        return curr->fileContent;
    }
private:
  TreeNode * root;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */
