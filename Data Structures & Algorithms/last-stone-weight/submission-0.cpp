class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> max_heap;
        int n = stones.size();
        for(int i=0;i<n;i++){
            max_heap.push(stones[i]);
        }
        while(max_heap.size()>1){
            int a = max_heap.top();
            max_heap.pop();
            int b = max_heap.top();
            max_heap.pop();
            if(a==b) continue;
            else if(a>b) max_heap.push(a-b);
        }
        return (max_heap.size()==1) ? max_heap.top() : 0;
    }
};
