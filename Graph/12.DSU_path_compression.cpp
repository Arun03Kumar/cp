
// in the basic DSU we create a tree and search for the parent so in worst case it may possible that it became a skew tree and searching time is O(n).

// so what we can do is the path compression means when we recursively call the find for the parent of the node we could directly assign the roo parent to that node instead of just previous node.

// ex lets, tree is like 0 -> 6 -> 4-> 8-> in which 0 is parent of 6, 6 is parent of 4, 4 is parent of 8.
// now if we do find(8) so we fist go to 4 then parent[4] which is 6, then parent[6] which is 0.
// so now when recursive call returns back we assign the root parent as the direct parent of the nodes.

//  0 -> 6
//  0 -> 4
//  0 -> 8
// this will be the new tree, so now we can directly find the parent of each node in very less time.

#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

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

    parent[parent_node1] = parent_node2; 
}