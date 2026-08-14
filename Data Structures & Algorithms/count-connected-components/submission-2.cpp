class Solution {
public:
    struct DSU{
        vector<int> parent;
        vector<int> size;
        DSU(int n){
            parent = vector<int>(n,0);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
            size = vector<int>(n,1);
        }
        void unite(int u,int v){
            int pu = find(u);
            int pv = find(v);
            if(size[pu]>size[pv]){
                // attach pv to pu tree
                parent[pv] = pu;
                size[pu]+=size[pv];
            }
            else{
                parent[pu] = pv;
                size[pv]+=size[pu];
            }
        }
        int find(int u){
            if(parent[u]==u) return u;
            return parent[u] = find(parent[u]);
        }
    };
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(dsu.find(u)==dsu.find(v)) continue;
            dsu.unite(u,v);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(dsu.parent[i]==i) ans++;
        }
        return ans;
    }
};










