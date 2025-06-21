class TrieNode {
public:
    TrieNode** pointers;
    bool isEnd;
    TrieNode() {
        pointers = new TrieNode*[26];
        for (int i = 0; i < 26; i++) {
            pointers[i] = NULL;
        }
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* trie;
public:
    Trie() {
        trie = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* t = trie;
        for (int i = 0; i < word.length(); i++) {
            int j = word[i] - 'a';
            if (!t->pointers[j]) {
                t->pointers[j] = new TrieNode();                
            }
            t = t->pointers[j];
        }
        t->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* t = trie;
        for (int i = 0; i < word.length(); i++) {
            int j = word[i] - 'a';
            if (!t->pointers[j]) {
                return false;
            }
            t = t->pointers[j];
        }
        return t->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* t = trie;
        for (int i = 0; i < prefix.length(); i++) {
            int j = prefix[i] - 'a';
            if (!t->pointers[j]) {
                return false;
            }
            t = t->pointers[j];
        }
        return t;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
