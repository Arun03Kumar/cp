// Probelm link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

// no need to use priority queue because we have to process the edges in the same way every time, we can only process first time in any order then in every time we have to process in same order
// and in priority queue each time we get the minimum weight edge so every time ordering will be different hence we can not use.

#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, vector<int>> adj; // it also contains weights
    
    // let V is the number of vertices, and S is the source given
    vector<int> distance(V, INT_MAX);
    distance[S] = 0; // source to source distance is 0;

    for(int count = 1; count <= V - 1; count++) {

        for(auto edge: adj) {

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            // distance[u] != INT_MAX, this is to check if we can reach to the u from the source, if not then we can skip the relaxation in this iteration
            if(distance[u] != INT_MAX && wt + distance[u] < distance[v]) {

                distance[v] = wt + distance[u];

            }

        }

    }

    for(auto edge: adj) {

        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(distance[u] != INT_MAX && wt + distance[u] < distance[v]) {

            return -1; // it means negative edge cycle in present, because getting into this if condition tells that edges can be relaxed one more time after V-1 times, it means ther is negative edge cycle is present.

        }

    }

}