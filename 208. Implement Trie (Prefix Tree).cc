// https://leetcode.com/problems/implement-trie-prefix-tree/#/description
class Trie {
struct TrieNode {
    bool isWord;
    struct TrieNode* children[26];
    TrieNode() : isWord(false) {
        memset(children, 0, 26 * sizeof(struct TrieNode*));
    }
};

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children[c-'a']) cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children[c-'a']) return false;
            cur = cur->children[c-'a'];
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (!cur->children[c-'a']) return false;
            cur = cur->children[c-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
