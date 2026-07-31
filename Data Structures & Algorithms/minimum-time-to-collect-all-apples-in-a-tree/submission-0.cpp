class Solution {
public:
    vector<vector<int>> graph;
    int f(int root,int parent,vector<bool>& hasApple){ // min time to collect apples of subtrees from root and return
        // base case
        // action
        int time = 0;
        for(auto nbr:graph[root]){
            if(nbr==parent) continue;
            int time_nbr = f(nbr,root,hasApple);
            if(time_nbr==0 && !hasApple[nbr]) continue;
            else if(time_nbr==0 && hasApple[nbr]) time+=2;
            else if(time_nbr!=0 && hasApple[nbr]) time+=2+time_nbr;
            else if(time_nbr!=0 && !hasApple[nbr]) time+=2+time_nbr;
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        graph = vector<vector<int>>(n);
        int e = edges.size();
        for(int i=0;i<e;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return f(0,-1,hasApple);
    }
};