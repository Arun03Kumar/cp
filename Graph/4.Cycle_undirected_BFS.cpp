#include <bits/stdc++.h>
using namespace std;

bool isCycleBFS_undirected(unordered_map<int, vector<int>> adj, int node, vector<int> &visited) {
   queue<pair<int, int> > que;
   que.psuh({node, -1});
   visited[node] = true;

   while(que.empty() == false) {
        pair<int, int> front = que.front();
        que.pop();
        int source = front.first;
        int parent = front.second;

        for(int x: adj[source]) {
            if(visited[x] == false) {
                que.push({x, source});
                visited[x] = true;
            }
            else if(x != parent) {
                return true;
            }
        }
        return false;
   }
}

int main() {
    unordered_map<int, vector<int>> adj; // create the graph from given edges and vertices.
    vector<bool> visited(v, false); // here v is the number of vertices

    //now since graph can be disconnected so iterate over each vetices.
    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            bool x = isCycleBFS_undirected(adj, i, visited); //when we start then there is no parent hence we gave it -1;
            if(x == true) return true;
        }
    }
    return false;
}