// problem link: https://www.geeksforgeeks.org/problems/topological-sort/1

// first we create a indegree array for each vertices
// then as we do on bfs, we create a queue and push the current node but here we push the nodes which has indegree 0.
//then as we do in bfs, we iterate over the adjecency of front element and push it to the queue, but here we decrease the indegree of adjacency because we traversed the parent and now if we remove the parent then it means indegree of all its childrens will be decreased.
//now if indegree of any children is 0 we push it into the queue.

#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, vector<int> > adj;
    vector<int> indegree(v, 0);
    queue<int> q;
    for(int i = 0; i < v; i++) {
        for(int x: adj[i]) {
            indegree[x]++;
        }
    }

    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> res;

    while(!q.empty()) {
        int front = q.front();
        res.push_back(front);
        q.pop();

        for(int x: adj[front]) {
            indegree[x]--;
            if(indegree[x] == 0) {
                q.push(x);
            }
        }
    }

    return ans;
}