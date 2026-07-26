class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        priority_queue<pair<int,char>> max_heap;
        if(a!=0) max_heap.push({a,'a'});
        if(b!=0) max_heap.push({b,'b'});
        if(c!=0) max_heap.push({c,'c'});
        while(!max_heap.empty()){
            auto [count,ch] = max_heap.top();
            max_heap.pop();
            int n = ans.size();
            if(n>=2 && ans[n-1]==ch && ans[n-2]==ch){// cur cannot be ch
                if(max_heap.empty()){
                    return ans;
                }
                auto [count2,ch2] = max_heap.top();
                max_heap.pop();
                ans+=ch2;
                count2--;
                if(count2>0){
                    max_heap.push({count2,ch2});
                }
                max_heap.push({count,ch});
            }
            else{// cur can be ch
                ans+=ch;
                count--;
                if(count>0){
                    max_heap.push({count,ch});
                }
            }
        }
        return ans;
    }
};


// aabaaaaa

// 4 4 4
