class FreqStack {
public:
    struct Node{
        Node* next = nullptr;
        Node* prev = nullptr;
        int val = 0;
        Node(int v){
            val = v;
        }
    };
    int max_freq = 0;
    unordered_map<int,Node*> map; // freq -> tail of ll
    unordered_map<int,int> freq_map;
    FreqStack() {
        
    }
    
    void push(int val) {
        int freq = freq_map[val];
        freq++;
        freq_map[val] = freq;
        Node* tail = map[freq];
        if(!tail){
            tail = new Node(val);
            map[freq] = tail;
        }
        else{
            Node* new_node = new Node(val);
            Node* prev = tail->prev;
            tail->next = new_node;
            new_node->prev = tail;
            map[freq] = new_node;
        }
        max_freq = max(max_freq,freq);
    }
    
    int pop() {
        Node* tail = map[max_freq];
        Node* prev = tail->prev;
        int val = tail->val;
        if(prev) { // more than 1 elemnent
            prev->next = nullptr; 
            map[max_freq] = prev;
        }
        else{ // only 1 element
            map.erase(max_freq);
            max_freq--;
        }
        int f = freq_map[val];
        freq_map[val] = f==0 ? 0 : f-1;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// maps:
//  freq -> linked list of numbers in order of pushing
//  number -> freq
// int max_freq