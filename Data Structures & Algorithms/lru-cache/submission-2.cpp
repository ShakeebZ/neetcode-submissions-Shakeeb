struct Node {
    Node* prev = NULL;
    Node* next = NULL;
    int value = -1;
    int key = -1;
};

class LRUCache {
    std::unordered_map<int, Node*> lru;
    Node* head = NULL;
    Node* tail = NULL;
    int size = -1;
public:
    LRUCache(int capacity) {
        size = capacity; // account for sentinels
        Node* n = new Node;
        Node* t = new Node;
        head = n;
        tail = t;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (lru.contains(key)) {
            Node* curr = lru[key];
            if (head->next != curr) {
                remove(curr);
                add(curr);
            }
            return curr->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* n = new Node();
        n->value = value;
        n->key = key;
        if (lru.contains(key)) {
            Node* temp = lru[key];
            n->prev = temp->prev;
            n->next = temp->next;
            remove(temp);
            add(n);
            lru.erase(key);
            lru[key] = n;
            return;
        }
        add(n);
        lru[n->key] = n;
        if (lru.size() > size) {
            lru.erase(tail->prev->key);
            remove(tail->prev);
        }
    }

    void remove(Node* curr) {
        Node* prev = curr->prev;
        Node* next = curr->next;
        prev->next = next;
        next->prev = prev;
    }

    void add(Node* curr) {
        Node* oldHead = head->next;
        oldHead->prev = curr;
        head->next = curr;
        curr->next = oldHead;
        curr->prev = head;
    }
};
