// problem link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// set is a little faster then the priority queue or min heap because in sets we can erase an element while in pq and min heaps we can not.
// but how is that helpful -> suppose we relaxed a node and its value is came to 6, means distance from source is 6, and then in the next iteration it came as 4, so now when we push 4 will come above, so we will realx every other node w.r.t 4, but if we won't remove 6 then eventually we will came at 6 and try to relax each node with this value offcourse no node is going to be relaxed because they would have been already relaxed by 4. hence we saved one iteration here.

// we are using ordered set which stores element is ascending order.

#include <bits/stdc++.h>
using namespace std;

vector<int> shortest_distance_from_source(unordered_map<int, vector<int>> adj, int source) {

    set<pair<int, int>> st;

    vector<int> distance(V, INT_MAX); // here V is the number of vertices

    distance[source] = 0; // distance from source to source itself will be 0
    st.insert({0, source});

    while(!st.empty()) {

        auto &it = *st.begin(); // st.begin() gives a iterator to the first element but if we derefrence it then it will give the first element in the set
        int current_node_dist_from_source = it.first;
        int current_node = it.second;
        st.erase(it);

        for(auto x: adj[current_node]) {

            int neighbour = x[0];
            int wt = x[1];

            if(current_node_dist_from_source + wt < distance[neighbour]) {

                if(distance[neighbour] != INT_MAX) {

                    st.erase({distance[neighbour], neighbour});

                }

                distance[neighbour] = current_node_dist_from_source + wt;
                st.insert({current_node_dist_from_source + wt, neighbour});

            }

        }

    }

    return distance;

}

int main() {
    unordered_map<int, vector<int>> adj;

    vector<int> result = shortest_distance_from_source(adj, 0);
}