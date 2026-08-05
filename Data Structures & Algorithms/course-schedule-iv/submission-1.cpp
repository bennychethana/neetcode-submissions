class Solution {
public:
    unordered_map<int,unordered_set<int>> map;
    vector<vector<int>> graph;
    unordered_set<int> visited;
    void f(int node){
        if(visited.count(node)) return;
        visited.insert(node);
        for(auto &nbr: graph[node]){
            f(nbr);
            map[node].insert(nbr);
            for(auto &it:map[nbr]){
                map[node].insert(it);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // build grapg
        graph = vector<vector<int>>(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            graph[u].push_back(v);
        }
        // dfs
        for(int i=0;i<numCourses;i++){
            if(!visited.count(i)){
                f(i);
            }
        }
        // process queries
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            ans.push_back(map[u].count(v));
        }
        return ans;
    }
};

// 3->2->1->0