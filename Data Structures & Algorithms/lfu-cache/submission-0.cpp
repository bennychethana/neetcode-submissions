class LFUCache {
public:
    struct Node {
        int key;
        Node* prev;
        Node* next;

        Node(int k = 0) : key(k), prev(nullptr), next(nullptr) {}
    };

    struct LL {
        Node* head;
        Node* tail;
        int size;

        LL() {
            head = new Node();
            tail = new Node();

            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        void addAtTail(Node* node) {
            Node* last = tail->prev;

            last->next = node;
            node->prev = last;

            node->next = tail;
            tail->prev = node;

            size++;
        }

        void remove(Node* node) {
            Node* previous = node->prev;
            Node* next = node->next;

            previous->next = next;
            next->prev = previous;

            node->prev = nullptr;
            node->next = nullptr;

            size--;
        }

        Node* removeHead() {
            if (size == 0) {
                return nullptr;
            }

            Node* node = head->next;
            remove(node);
            return node;
        }

        bool empty() const {
            return size == 0;
        }
    };

    struct Entry {
        int value;
        int freq;
        Node* node;
    };

    unordered_map<int, Entry> keyMap;
    unordered_map<int, LL*> freqMap;

    int capacity;
    int currentSize;
    int minFreq;

    LFUCache(int capacity)
        : capacity(capacity), currentSize(0), minFreq(0) {}

    int get(int key) {
        if (!keyMap.count(key)) {
            return -1;
        }

        int value = keyMap[key].value;
        access(key);

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        if (keyMap.count(key)) {
            keyMap[key].value = value;
            access(key);
            return;
        }

        if (currentSize == capacity) {
            removeLFULRU();
        }

        addNewElement(key, value);
    }

private:
    void access(int key) {
        Entry& entry = keyMap[key];

        int oldFreq = entry.freq;
        Node* node = entry.node;

        LL* oldList = freqMap[oldFreq];
        oldList->remove(node);

        if (oldList->empty()) {
            delete oldList;
            freqMap.erase(oldFreq);

            if (minFreq == oldFreq) {
                minFreq = oldFreq + 1;
            }
        }

        int newFreq = oldFreq + 1;

        if (!freqMap.count(newFreq)) {
            freqMap[newFreq] = new LL();
        }

        freqMap[newFreq]->addAtTail(node);

        entry.freq = newFreq;
    }

    void addNewElement(int key, int value) {
        if (!freqMap.count(1)) {
            freqMap[1] = new LL();
        }

        Node* node = new Node(key);
        freqMap[1]->addAtTail(node);

        keyMap[key] = {
            value,
            1,
            node
        };

        minFreq = 1;
        currentSize++;
    }

    void removeLFULRU() {
        LL* list = freqMap[minFreq];

        Node* victim = list->removeHead();
        int victimKey = victim->key;

        keyMap.erase(victimKey);
        delete victim;

        if (list->empty()) {
            delete list;
            freqMap.erase(minFreq);
        }

        currentSize--;
    }
};

// Design 2

// map1: key -> value, freq, node
// map2: freq -> lru ll (with lru at head and mru at tail)
// int min_freq

// access()
//     - get value, freq & node from map1
//     - get ll from map2
//     - delete node from ll & if ll becomes empty delete it
//     - add node in map2[freq+1] at tail
//     - if(min_freq==freq && map2[freq] is empty) min_freq=freq+1
//     - update map1 with new freq

// get
//     - if map1 does not have
//         - return -1
//     - if map1 has
//         - access()
//         - return value

// add_new_element()
//     - add in map2[1] at tail
//     - min_freq = 1
//     - add in map1

// put
//     - if map1 has
//         - access()
//         - update map1 with new value
//     - if map1 does not have && size<cap
//         - add_new_element()
//         - size++
//     - if map1 does not have && size==cap
//         - get map2[min_freq] & remove lru from it at head & remove from map1
//             -  if map2[min_freq] becomes empty, delete it
//         - add_new_element()

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Design 1

// map : key -> value, ll1 node, ll2 node

// ll1 : increasing order of frequency, each node has all nodes with same freq in ll2 in lru order
// ll1 node : frequency, ll2

// ll2: ll with lru at head and mru at tail
// ll2 node: key

// get
// put update
// put new when cap not full
// put new at max capacity

// move_to_next(cur_ll1_node,cur_ll2_node)
//     - if next_ll1_node exists & next_ll1_node_freq == cur_ll1_node_freq+1
//         - remove cur_ll2_node from cur_ll1_node's ll2
//         - if cur_ll1_node's ll2 becomes empty, remove cur_ll1_node
//         - add cur_ll2_node in next_ll1_node's ll2's tail
//     - else
//         - create new next_ll1_node with frequency = cur_ll1_node_freq+1
//         - remove cur_ll2_node from cur_ll1_node's ll2
//         - if cur_ll1_node's ll2 becomes empty, remove cur_ll1_node
//         - add cur_ll2_node in next_ll1_node's ll2's tail
//     - update ll1 node, ll2 node in map
// get
//     - if map does not have 
//         - return -1
//     - if map has
//         - get cur_ll1_node & cur_ll2_node from map
//         - move_to_next(cur_ll1_node,cur_ll2_node)
//         - return value

// put_new_when_cap_not_full()
//     - if ll1 head freq==1
//         - add new node at ll2's tail
//     - else
//         - add new node at ll1 head with freq=1 & create first ll2 node 
//         - add entry in map with value ,ll1node & ll2 node
//     - capacity++
//     - update ll1 node, ll2 node in map
// put 
//     // put update
//     - if map has
//         - get cur_ll1_node & cur_ll2_node from map
//         - update value in map
//         - move_to_next(cur_ll1_node,cur_ll2_node)
//     // put new when cap not full
//     - if map doesnt have & size<cap
//         - put_new_when_cap_not_full()
//     // put new at max capacity
//     - if map doesnt have & size==cap
//         - remove head ll1's , head ll2 node
//         - capacity--
//         - put_new_when_cap_not_full()



        








