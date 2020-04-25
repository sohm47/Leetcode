class LRUCache {
public:
    struct Node {
        Node *prev, *next;
        int key, value;
        Node(int k, int v): prev(nullptr), next(nullptr), key(k), value(v) {}
    };
    Node *head, *tail;
    
    int size;
    unordered_map<int, Node*> cache;
    bool firstValue;
    
    LRUCache(int capacity) {
        head = nullptr;
        tail = nullptr;
        size = capacity;
        firstValue = true;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        
        if(cache[key]->prev != nullptr) {
            if(tail->key == cache[key]->key)
                tail = tail->prev;
            cache[key]->prev->next = cache[key]->next;
        }
        
        if(head->key != key) {
            if(cache[key]->next != nullptr)
                cache[key]->next->prev = cache[key]->prev;
            
            cache[key]->prev = nullptr;
            head->prev = cache[key];
            cache[key]->next = head;
            head = cache[key];
        }
        
        return head->value;
    }
    
    void put(int key, int value) {
        if(get(key) == -1) {
            Node *tempNode = new Node(key, value);
            if(firstValue) {
                head = tempNode;
                tail = tempNode;
                firstValue = false;
            }
            else {
                head->prev = tempNode;
                tempNode->next = head;
                head = tempNode;
            }
            
            cache[key] = tempNode;
            if(cache.size() > size) {
                cache.erase(tail->key);
                tail = tail->prev;
                tail->next = nullptr;
            }
        }
        else
            head->value = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
