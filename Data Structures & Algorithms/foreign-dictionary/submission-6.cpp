class Solution {
public:
    string ans;
    unordered_map<char,unordered_set<char>> graph;
    // unordered_set<char> visited;
    unordered_map<char,int> visited; // 0,1,2
    unordered_set<char> words_set;
    bool is_cycle = false;
    void f(char node){
        if(visited[node]==2 || is_cycle) return;
        if(visited[node]==1) {
            is_cycle = true;
            return;
        }
        // visited.insert(node);
        visited[node] = 1;
        for(auto &nbr: graph[node]){
            f(nbr);
        }
        visited[node] = 2;
        ans+=node;
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                words_set.insert(words[i][j]);
            }
        }
        for(int i=0;i<n-1;i++){
            string w1 = words[i];
            string w2 = words[i+1];
            int l = 0;
            int r = 0;
            bool edge_added = false;
            while(l<w1.size() && r<w2.size()){
                if(w1[l]==w2[r]){
                    l++;
                    r++;
                    continue;
                }
                char u = w1[l];
                char v = w2[r];
                // edge detected from u to v
                    // cycle if already edge from v to u
                if(graph[v].count(u)) return "";
                // add edge from u to v
                graph[u].insert(v);
                edge_added = true;
                break;
            }
            // ["abc","ab"]
            if(!edge_added && w1.size()>w2.size()) return "";
        }
        // graph creation done
        // start dfs from first char - not enough, there can be unconnected components
        for(auto &c:words_set){
            if(visited[c]==0){
                f(c);
            }
        }
        if(is_cycle) return "";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// z->o

// h->e->r

// compare i to i+1 to get one edge
//     if at any point, cycle detected OR i.length < (i+1).length -> invalid
//     keep addign to graph

// Once u have graph, start dfs at first letter from words and form answer string
// is toposort(reversing) required? 
//     yes because multiple nodes might point to the same node
//     so we need to collect child first

// h->e->r->n->f

// a->r


