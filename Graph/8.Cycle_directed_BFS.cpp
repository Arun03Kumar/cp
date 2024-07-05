// its basically the same as toposort using BFS, because we know that toposort works only for DAG.
// so if there is cycle present then this wont work, and when there is cycle one element will always there whose indegree will never go 0.
// hence we take a count variable and increment it, now we can compare that if it is equal to the number of vertices or not;

#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, vector<int>> adj;
    vector<int> indegree(v, 0);

    for(int i = 0; i < v; i++) {
        for(int x: adj[i]) {
            indegree[x]++;
        }
    }

    int count = 0;
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            count++;
        }
    }
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();

        for(int x: adj[front]) {
            indegree[x]--;
            if(indegree[x] == 0) {
                q.push(x);
                count++;
            }
        }
    }

    if(count != v) return true;
    return false;
}