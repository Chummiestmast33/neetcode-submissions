class PrefixTree {
    struct Node {
        Node* childs[26];
        bool isEnd = false;
        Node() {
            for (int i = 0; i < 26; i++) childs[i] = nullptr;
        }
    };

   public:
    Node* root;
    PrefixTree() { root = new Node(); }

    void insert(string word) {
        Node* current = root;
        for (char& c : word) {
            if (current->childs[c - 'a'] == nullptr) {
                Node* node = new Node;
                current->childs[c - 'a'] = node;
            }
            current = current->childs[c - 'a'];
        }
        current->isEnd = true;
    }

    bool search(string word) {
        Node* current = root;
        for (char& c : word) {
            if (current->childs[c - 'a'] == nullptr) return false;
            current = current->childs[c - 'a'];
        }
        return current->isEnd;
    }

    bool startsWith(string prefix) {
        Node* current = root;
        for (char& c : prefix) {
            if (current->childs[c - 'a'] == nullptr) return false;
            current = current->childs[c - 'a'];
        }
        return true;
    }
};
