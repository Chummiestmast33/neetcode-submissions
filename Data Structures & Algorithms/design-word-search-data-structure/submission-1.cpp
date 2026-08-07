class WordDictionary {
    struct TrieNode {
        TrieNode* childs[26];
        bool isEnd = false;
        TrieNode() {
            for (int i = 0; i < 26; i++) childs[i] = nullptr;
        }
    };

    TrieNode* root;

   public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* current = root;
        for (char& c : word) {
            if (current->childs[c - 'a'] == nullptr) current->childs[c - 'a'] = new TrieNode();
            current = current->childs[c - 'a'];
        }
        current->isEnd = true;
    }

    bool searchWord(string& word, int index, TrieNode* root) {
        if (index == word.size()) {  // Whe complete already the word
            return root->isEnd;
        }

        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (root->childs[i] != nullptr) {
                    if (searchWord(word, index + 1, root->childs[i])) return true;
                }
            }
            return false;
        } else {
            if (root->childs[word[index] - 'a'] != nullptr) {
                bool isChildAvalible = searchWord(word, index + 1, root->childs[word[index] - 'a']);
                return isChildAvalible;
            }
            return false;
        }
    }

    bool search(string word) { return searchWord(word, 0, root); }
};
