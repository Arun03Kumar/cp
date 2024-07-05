// problem link: https://www.geeksforgeeks.org/problems/topological-sort/1

//so basically do the DFS call while maintaining the stack, and push the node into stack in the last because before that all the nodes which are children means which came after will be pushed into stack first and the current node will be pushed at the last so when we pop back the stack, parent will came first.

#include <bits/stdc++.h>
using namespace std;

void DFS_toposort(unordered_map<int, vector<int> > &adj, vector<bool> &visited, stack<int> &st, int node) {
    visited[node] = true;

    for(int x: adj[node]) {
        if(visited[x] == false) {
            DFS_toposort(adj, visited, st, x);
        }
    }
    st.push(node);
}

int main() {
    unordered_map<int, vector<int> > adj;
    vector<bool> visited(v, false);
    stack<int> st;

    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            DFS_toposort(adj, visited, st, i);
        }
    }

    vector<int> res;
    while(!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
}