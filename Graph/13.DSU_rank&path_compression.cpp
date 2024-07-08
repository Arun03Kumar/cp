
//intitally each node is parent of themselves, and no one in the children of any other node hence rank of each node will be 0 initially.

// so here we maintain two arrays, rank and parent.

// first find the parent of node1 and node2 in union then find the rank of those parents, 
// connect smaller rank to larger rank, always.
// make larger rank as the parent of smaller rank
// if rank of both is same then we can make anyone of as the parent to other and increase the rank of the parent.

#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> rank;

int find(int node) {
    if(parent[node] == node) {
        return node;
    }

    return parent[node] = find(parent[node]);
}

void Union(int node1, int node2) {
    int parent_node1 = find(node1);
    int parent_node2 = find(node2);

    if(parent_node1 == parent_node2) return;

    if(rank[parent_node1] < rank[parent_node2]) { // rank of parent1 is smaller so assign parent2 as a parent 1 

        parent[parent_node1] = parent_node2;

    }
    else if(rank[parent_node1] > rank[parent_node2]) {

        parent[parent_node2] = parent[parent_node1];

    }
    else {

        parent[parent_node1] = parent_node2; // we make parent of node2 as the parent of node1
        rank[parent_node2]++; // increase the rank of parent of node2

    }
}

int main() {
    parent.resize(v);
    rank.resize(v);

    for(int i = 0; i < v; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

