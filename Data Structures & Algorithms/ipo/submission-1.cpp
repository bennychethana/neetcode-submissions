class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> max_heap; // profit,capital
        vector<vector<int>> pairs; // capital,profit
        int n = profits.size();
        for(int i=0;i<n;i++){
            pairs.push_back({capital[i],profits[i]});
        }
        sort(pairs.begin(),pairs.end());
        int ind = 0;
        int cur_capital = w;
        for(int i=0;i<k;i++){
            while(ind<n && cur_capital>=pairs[ind][0]){
                max_heap.push(pairs[ind][1]);
                ind++;
            }
            if(max_heap.empty()) return cur_capital;
            cur_capital+=max_heap.top();
            max_heap.pop();
        }
        return cur_capital;
    }
};


// 1 4 2 3
// 0 3 1 1


// w
// 0 -> can_pick(1) -> 1
// 1 -> 2,3         -> 3
// 4 -> 4,3         -> 4
// 8

// maintain sorted {capital,profit} pairs
// add to heap affordable ones
// at every step until k
//     - pop from heap & add to ans
//     - add to heap from remaining pairs if more became affordable
//     - f none affordable return ans


