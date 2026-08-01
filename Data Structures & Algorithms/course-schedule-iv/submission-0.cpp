class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> graph;
    unordered_map<int,unordered_set<int>> map;
    void f(int node){
        if(visited[node]) return;
        visited[node] = true;
        for(auto nbr:graph[node]){
            f(nbr);
            map[node].insert(nbr);
            for(auto nbr_nbr:map[nbr]){
                map[node].insert(nbr_nbr);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        graph = vector<vector<int>>(numCourses);
        int p = prerequisites.size();
        for(int i=0;i<p;i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            graph[u].push_back(v);
        }
        visited = vector<bool>(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                f(i);
            }
        }
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            int u = queries[i][0];
            int v = queries[i][1];
            if(map[u].count(v)) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};