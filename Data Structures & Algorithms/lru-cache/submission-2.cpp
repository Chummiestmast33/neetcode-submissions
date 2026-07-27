class LRUCache {
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    unordered_map<int, Node*> memoryPosition;
    int maxCapacity;
    int current = 0;
    Node* dummyHead = new Node(0, 0);
    Node* dummyTail = new Node(0, 0);

   public:
    LRUCache(int capacity) {
        maxCapacity = capacity;
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }
    int get(int key) {
        if (memoryPosition.contains(key)) {
            Node* node = memoryPosition[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        Node* node;
        cout << "Inserted: " << key << ":" << value << endl;
        if (memoryPosition.contains(key)) {  // update the values and position
            node = memoryPosition[key];
            node->val = value;
            remove(node);
            insert(node);

        } else if (current < maxCapacity) {  // Insert a new node
            node = new Node(key, value);
            insert(node);
            memoryPosition.insert({key, node});
            ++current;
        } else {
            // Replace the least recently used node
            node = new Node(key, value);
            memoryPosition.insert({key, node});
            memoryPosition.erase(dummyTail->prev->key);
            cout << "removed: " << dummyTail->prev->key << endl;
            remove(dummyTail->prev);
            insert(node);
        }
    }

    void insert(Node* node) {
        node->prev = dummyHead;
        node->next = dummyHead->next;
        node->next->prev = node;
        dummyHead->next = node;
    }
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};
