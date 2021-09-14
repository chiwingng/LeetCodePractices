class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node *prev, *next;
        Node(int key, int value) : key(key), val(value) {}
    };
    
    // add node to the front of doubly linked list
    void addNode(Node* node) {
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }
    
    // remove node from doubly linked list
    void delNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    // link head and tail in initialization
    LRUCache(int capacity) : cap(capacity) {
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        // if key is registered, move its node to the front and return value
        Node* node = cache[key];
        delNode(node);
        addNode(node);
        cache[key] = node;
        return node->val;
    }
    
    void put(int key, int value) {
        // key is registered before, remove the previous node
        if (cache.find(key) != cache.end()) delNode(cache[key]);
        // need to insert new key but capacity reached limit, remove the last node
        else if (cache.size() == cap) {
            cache.erase(tail->prev->key);
            delNode(tail->prev);
        }
        // insert new node
        Node* node = new Node(key, value);
        addNode(node);
        // assign new node to cache
        cache[key] = node;
    }
    
private:
    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);
    unordered_map<int, Node*> cache;
    int cap;
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
