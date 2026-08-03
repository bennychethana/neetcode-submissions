class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>> q; // {pattern, dist from 0000}
        unordered_set<string> deadends_set;
        for(int i=0;i<deadends.size();i++){
            deadends_set.insert(deadends[i]);
        }
        unordered_set<string> visited;
        int ans = INT_MAX;
        q.push({"0000",0});
        visited.insert("0000");
        while(!q.empty()){
            auto [cur_string,cur_dist] = q.front();
            q.pop();
            if(cur_string==target){
                ans = min(ans,cur_dist);
                continue;
            }
            if(deadends_set.count(cur_string)) continue;
            for(int i=0;i<4;i++){
                string s = cur_string;
                // up
                if(s[i]=='0') s[i] = '9';
                else s[i] = ((s[i]-'0')-1)+'0';
                if(!visited.count(s)){
                    visited.insert(s);
                    q.push({s,cur_dist+1});
                }
                // down
                s = cur_string;
                if(s[i]=='9') s[i] = '0';
                else s[i] = ((s[i]-'0')+1) + '0';
                if(!visited.count(s)){
                    visited.insert(s);
                    q.push({s,cur_dist+1});
                }
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};

// 0000 -> tttt
// dfs 
// if tttt, add to ans min
// if deadend, return

// bfs with dist
