// problem link: https://www.geeksforgeeks.org/problems/bipartite-graph/1

// bipartite means if we can color all the verices of the graph with only two colors in such a way that no two adjecent vertices gets the same color.

// lets represents two colors as 0 and 1, initially no vertex will have any color so initialzes with -1;
// we can send the colors array in dfs call which will also work as if vertex is visited or not, if vertex dosen't have -1 then it means its visited.

// we can send the color of the current node in the call so that we can check if its childrens have the same color or not.

#include <bits/stdc++.h>
using namespace std;

bool is_bipartite_DFS(unordered_map<int, vector<int>> adj, vector<int> &color_of_vertex, int node, int node_color) {
    color_of_vertex[node] = node_color;

    for(int x: adj[node]) {
        if(color_of_vertex[x] == node_color) return false;

        if(color_of_vertex[x] == -1) {
            bool res = is_bipartite_DFS(adj, color_of_vertex, x, 1 - node_color); // if a variable can take only two values 0 and 1 then we can flip the value by (1 - var)
            if(res == false) return false;
        }
    }
}

int main() {
    unordered_map<int, vector<int>> adj;
    vector<int> color_of_vertex(v, -1);

    for(int i = 0; i < v; i++) {
        if(color_of_vertex[i] == -1) {
            bool x = is_bipartite_DFS(adj, color_of_vertex, i, 0);
            if(x == false) return false;
        }
    }
    return true;
}