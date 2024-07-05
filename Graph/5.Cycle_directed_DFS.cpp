//problem link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

// undirected DFS concept will fail here because in the same connected component it is possible that we get a node from which we can not go anywhere ex.(0 ---> 1 <--- 2) so in this case when we start from 0 we mark it visited and mark its children 1 as visited with parent value as 0, now from 1 we can not go anywhere hence that DFS recursion will stop and new recursion will start from 2, so when we go to 1 from 2 we found that 1 is already visited and its parent is 1 not equal to 2 hence we think that there is a cycle but we can see there is no cycle.

// so problem arises with the recursion hence we take another array which tells us that if we are at already visited node then we are coming on it from the same recursion call or previously calls.
// if it is same recursion call then there is cycle.

//for doing this when we visit a node we mark is visited and is_same_recursion array true but when we return from that node we unmark the is_same_recursion to false, this way in the new recursion call we can find that if it is already visited in other calls then also its is_same_recursion will be false in the new call.

bool isCycleDFS_directed(unordered_map<int, vector<int>> adj, int node, vector<int> &visited, vector<int> &is_same_recursion) {
    visited[node] = true;
    is_same_recursion[node] = true;
    for(int x: adj[node]) {
        if(visited[x] == false) { // it means not visited yet so we can call the dfs on it
            int ans = isCycleDFS_directed(adj, x, visited, is_same_recursion);
            if(ans) return true;
        }
        else if(visited[x] == true && is_same_recursion[x] == true) { //if current node is visited and in the same recursion then it means there is cycle, since we checked in the first if it visited so if it is false then it means it is already visited hence we no need to check again in the else if condition that visited[x] == true we can directly check got is_same_recursion[x] == true
            return false;
        }
    }
    is_same_recursion[node] = false;
    return false; // if no one return true it means there is no cycle in the graph
}

int main() {
    unordered_map<int, vector<int>> adj; // create the directed graph from given edges and vertices.
    vector<bool> visited(v, false); // here v is the number of vertices
    vector<bool> is_same_recursion(v, false);

    //now since graph can be disconnected so iterate over each vetices.
    for(int i = 0; i < v; i++) {
        if(visited[i] == false) {
            bool x = isCycleDFS_directed(adj, i, visited, is_same_recursion); //when we start then there is no parent hence we gave it -1;
            if(x == true) return true;
        }
    }
    return false;
}