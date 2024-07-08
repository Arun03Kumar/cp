// problem link: https://leetcode.com/problems/is-graph-bipartite/description/

// when we push into queue update the colors array at the same time

#include <bits/stdc++.h>
using namespace std;

bool BFS(unordered_map<int, vector<int>> adj, vector<int> &colors, int node, int node_parent) {
    queue<int> q;
    q.push(node);
    colors[node] = node_parent;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(int x: adj[front]) {

            if(colors[x] == colors[front]) {
                return false;
            }

            if(colors[x] == -1) {
                q.push(x);
                colors[x] = 1 - colors[front];
            }
        }
    }

    return false;
}

int main() {
    unordred_map<int, vector<int>> adj;
    vector<int> colors(v, -1); // v is the number of vertices

    for(int i = 0; i < v; i++) {
        if(colors[i] == -1) {

            if(!BFS(adj, colors, i, 0)) {
                return false;
            }
        }
    }

    return true;

}