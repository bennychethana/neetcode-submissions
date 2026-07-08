class LRUCache {
public:
    struct Node{
        Node* prev;
        Node* next;
        int val;
        int key;
        Node(int val,int key){
            prev = nullptr;
            next = nullptr;
            this->val = val;
            this->key = key;
        }
    };

    unordered_map<int,Node*> map;
    int cap = 0;

    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.count(key)){
            Node* node = map[key];
            remove_and_add_at_end(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.count(key)){
            Node* old_node = map[key];
            old_node->val = value;
            remove_and_add_at_end(old_node);
        }
        else if(map.size()>=cap){
            evict_lru();
            Node* new_node = new Node(value,key);
            map[key] = new_node;
            add_at_end(new_node);
        }
        else{
            Node* new_node = new Node(value,key);
            map[key] = new_node;
            add_at_end(new_node);
        }
    }

    void remove_and_add_at_end(Node* node){
        Node* next = node->next;
        Node* prev = node->prev;
        Node* last = tail->prev;

        prev->next = next;
        next->prev = prev;

        add_at_end(node);
    }

    void add_at_end(Node* node){
        Node* prev = tail->prev;
        prev->next = node;
        node->next = tail;
        tail->prev = node;
        node->prev = prev;
    }

    void evict_lru(){
        Node* to_evict = head->next;
        Node* to_evict_next = head->next->next;
        head->next = to_evict_next;
        to_evict_next->prev = head;
        int to_evict_key = to_evict->key;
        map.erase(to_evict_key);
    }
};

// map , ll : map key to node in ll

// put
// - push into ll
// - store in map

// get
// - get index from map
// - get from vector
// - erase and push at vector back again
// - erase old index in map, add new index