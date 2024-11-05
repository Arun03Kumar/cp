// problem link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// we maintain a min heap which stores the pair of distance and node
// when any node is relaxed means we get some smaller distance then push that node into the min heap.
// iterate like BFS.

// distance array stores the distance of each node from the source, means at index 0 it will store the minimum distance from source to node 0, at index 1 means it will store the minimim distance from source to node 1...
// hence distance[source] = 0, it will always be 0 because source to source distance is always 0.

// in the min heap we store pair of element, in which first number tells the distance from source and second number tells the vertex, means <0, 2> is telling that from source to node 2 the distance is 0. <1, 5> is telling that from source to node 5 the distance is 1.

#include <bits/stdc++.h>
using namespace std;

vector<int> shortest_distance_from_source(unordered_map<int, vector<int>> adj, int source) {
    // 1. max heap which stores integer, to store other datatypes just replace the int.
    // priority_queue<int, vector<int>> pq;

    // 2. min heap which stores integer, to store other data types just replace the int.
    // priority_queue<int, vector<int>, greater<int>>

    priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>>> pq;

    vector<int> distance(V, INT_MAX); // here V is the number of vertices

    distance[source] = 0; // because source to source distance is 0.
    pq.push({0, source});

    while(!pq.empty()) {

        int current_node_dist_from_source = pq.top().first // top will always give smallest distance because of min heap
        int current_node = pq.top().second;
        pq.pop();

        for(int neighbour: adj[current_node]) {
            //in this adjacency list we store weights along with the neighbouring vertices.

            int node = neighbour[0];
            int wt = neighbour[1];

            if(wt + current_node_dist_from_source < distance[node]) {

                distance[node] = wt + current_node_dist_from_source;
                pq.push({wt + current_node_dist_from_source, node});

            }
        }
    }

    return distance;

}

int main() {
    // in this we store weights along with neighbouring nodes.
    unordered_map<int, vector<int>> adj;

    vector<int> res = shortest_distance_from_source(adj, 0);

}