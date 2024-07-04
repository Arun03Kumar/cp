#include <bits/stdc++.h>
using namespace std;

void DFS(unordered_map<int, vector<int> > &adj, vector<bool> &visited, int node, vector<int> &res) {
    if(visited[node] == true) // it means node is already visited so return from it else if there will be any loop then it will go on forever, it works as a base case
        return 
    
    visited[node] = true; // mark the node as visited; and add it to the result;
    res.push_back(node);

    //now traverse over the adjecency of node and call the DFS on them if they are not visited;
    for(auto x: adj[node]) {
        if(visited[x] == false) {
            DFS(adj, visited, x, res);
        }
    }
}

int main() {
    unordered_map<int, vector<int> > adj;
    // create the graph from given edges and vertices. then pass this adj in dfs function along with visited array.
    vector<bool> visited(v, false); // here v is the number of vertices
    vector<int> result; // this contains the nodes in DFS traversed manner.
    DFS(adj, visited, 0, result); // here we start with the node 0, but we can take any value
    //now return the result or print it.
}