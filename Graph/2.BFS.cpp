#include <bits/stdc++.h>
using namespace std;

void BFS(unordered_map<int, vector<int> > &adj, vector<bool> &visited, int node, vector<int> &res) {
    queue<int> que;
    que.push(node); // pushing in queue means visiting it hence mark it visited to 1 also
    visited[node] = true; // if visited then push into result
    res.push_back(node);

    while(que.empty() == false) {//means till there is any element in queue loop over it
        int front = que.front();
        que.pop(); //this is first element visited so now its time to visit its direct connected nodes

        for(auto x: adj[front]) {
            if(visited[x] == false) {
                que.push(x);
                visited[x] = true;
                res.push_back(x);
            }
        }
    }
}

int main() {
    unordered_map<int, vector<int> > adj;
    // create the graph from given edges and vertices. then pass this adj in dfs function along with visited array.
    vector<bool> visited(v, false); // here v is the number of vertices
    vector<int> result; // this contains the nodes in DFS traversed manner.
    BFS(adj, visited, 0, result); // here we start with the node 0, but we can take any value
    //now return the result or print it.

    return 0;
}