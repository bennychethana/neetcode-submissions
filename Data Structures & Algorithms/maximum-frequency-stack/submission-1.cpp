class FreqStack {
public:
    unordered_map<int,int> map;
    priority_queue<tuple<int,int,int>> max_heap; // {freq,time,num}
    int time = 0;

    FreqStack() {
        
    }
    
    void push(int val) {
        int freq = 0;
        if(map.count(val)){
            map[val]++;
            freq = map[val];
        }
        else{
            freq = 1;
            map[val] = 1;
        }
        time++;
        max_heap.push({freq,time,val});
    }
    
    int pop() {
        auto [freq,time,val] = max_heap.top();
        max_heap.pop();
        map[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

//     {freq,num}
// 5   1,5
// 7   1,7
// 5   2,5
// 7   2,7
// 4   4,1
// 5   3,5





