//problem link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

// basice concept is that we are doing dfs and if we came up to a node which is already visited then we can say that graph contains cycle. but there is a problem assume two node 0 ---------- 1 these are undirected so 0 is marked visited and we move to 1 so now when we are at 1 we mark is visited then we search for its children so we will found that 0 is also visited so we can say that graph contains cycle but we can see its not, hence we need to do a trick we need to also define the parent of each node, so when we encounter a case where children is alredy visited so we compare the parent. if we are at a node and its parent came as visited then we will move on we won't do anything, but if we find a node is already visited and that is not the parent of current node it means there is cycle;

bool isCycleDFS(unordered_map<int, vector<int>> adj, int node, vector<int> &visited, int parent) {
    visited[node] = true;
    for(int x: adj[node]) {
        if(x == parent) continue; // if it is parent then move on because that wont make a cycle
        if(visited[x] == true) { // it means x is not its parent because we already habdle the parent case in above line, so it means if any children of the node is already visited there is a cycle
            return true;
        }
        bool x = isCycleDFS(adj, x, visited, node);//if children is not visited then check the condition on its children recursively
        if(x == true) return true; // we are not returning false if not true because if may be possible for that node it gives false but for other nodes it may give true hence we are only checking for true;
    }
    return false; // if no one return true it means there is no cycle in the graph
}

int main() {
    unordered_map<int, vector<int>> adj; // create the graph from given edges and vertices.
    vector<bool> visited(v, false); // here v is the number of vertices

    //now since graph can be disconnected so iterate over each vetices.
    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            bool x = isCycleDFS(adj, i, visited, -1); //when we start then there is no parent hence we gave it -1;
            if(x == true) return true;
        }
    }
    return false;
}