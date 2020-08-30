class Trie {
public:
    /** Initialize your data structure here. */
    Trie *children[26];
    bool isWord;
    Trie() {
        for(int i = 0; i < 26; i++) {
            this -> children[i] = NULL;
        }
        this -> isWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *root = this;
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(root -> children[index] == NULL) {
                root -> children[index] = new Trie();
            }
            root = root -> children[index];
        }
        root -> isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *root = this;
        if(root == NULL) {
            return false;
        }
        for(int i = 0; i < word.size(); i++) {
            int index  = word[i] - 'a';
            if(root -> children[index] == NULL) {
                return false;
            }
            root = root -> children[index];
        }
        if(root -> isWord) {
            return true;
        } return false;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *root = this;
        if(root == NULL) {
            return false;
        }
        for(int i = 0; i < prefix.size(); i++) {
            int index  = prefix[i] - 'a';
            if(root -> children[index] == NULL) {
                return false;
            }
            root = root -> children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
