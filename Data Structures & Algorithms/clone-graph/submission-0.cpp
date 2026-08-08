/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> visited_map;
    void f(Node* node){
        if(visited_map.count(node)) return;
        Node* new_node = new Node(node->val);
        visited_map[node] = new_node;
        for(auto& nbr: node->neighbors){
            f(nbr);
            new_node->neighbors.push_back(visited_map[nbr]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        f(node);
        return visited_map[node];
    }
};

// method 1
// dfs once, create new nodes and store in map old->node to new node
// dfs again and add links

// method 2
// after dfs call for nbr in loop, 
//     if new node for nbr in created_nodes_set,
//     else create & add in set, add linkings










