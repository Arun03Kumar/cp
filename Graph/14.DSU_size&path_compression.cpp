// it is similar to the rank, here we maintian a size array which tells the size of the set, like in rank we make parent which has larger rank here also we make parent which has larger size, but here when we merge two different groups or sets into one the size should be increase by the sum of those two groups.

// as initially rank of each node was 0, now size of each node will be 1;

#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> size;

int find(int node) {
    if(parent[node] = node) {
        return node;
    }

    return parent[node] = find(parent[node]);
}

int Union(int node1, int node2) {
    int parent_node1 = find(node1);
    int parent_node2 = find(node2);

    if(parent_node1 == parent_node2) {
        return;
    }

    if(size[parent_node1] > size[parent_node2]) { // size of set1 is greter than size of set2

        parent[parent_node2] = parent_node1; // merged the set 2 into set 1
        size[parent_node1] += size[parent_node2]; // increased the size of set1

    }
    else if(size[parent_node2] > size[parent_node1]) {

        parent[parent_node1] = parent_node2;
        size[parent_node2] += size[parent_node1];

    }
    else {

        parent[parent_node1] = parent_node2;
        size[parent_node2] += size[parent_node1];

    }
}

int main() {
    parent.resize(v);
    size.resize(v)

    for(int i = 0; i < v; i++) {
        parent[i] = i;
        size[i] = 1; // initially the size of each node will be 1;
    }
}