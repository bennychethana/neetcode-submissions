class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> graph(n);
        vector<int> degree(n,0); // node -> edges
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1) q.push(i);
        }
        int remaining = n;
        while(remaining>2){
            int l = q.size();
            for(int i=0;i<l;i++){
                int node = q.front();
                q.pop();
                for(auto &nbr: graph[node]){
                    degree[nbr]--;
                    if(degree[nbr]==1) q.push(nbr);
                }
            }
            remaining-=l;
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
        }
        return ans;
    }
};