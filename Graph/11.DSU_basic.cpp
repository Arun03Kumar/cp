// problem link: https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1

// DSU contains two main function find() and union.

//intitally each node is parent of themselves.

// find gives the parent of the input recursively, we basically maintain an array which contains the position of their parents, for each index from 0 to V-1(number of verices) the values at that position represents the parent of that node, so we recursively go to that node and check if parent of that node is that node itself, that is the basecase.

// we provide two inputs in the union function x and y, then we find the parent of both x and y if they are same then it means both are from same group or tree, when parents are different we assign one as a parent of other, in this way they now belong to the same group.

//initially the parent array contains the same number because initially node itself is their parents.


#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int node) {
    if(parent[node] == node) {
        return node;
    }

    return find(parent[node]);
}

void Union(int vertex1, int vertex2) {
    int parent_vertex1 = find(vertex1); 
    int parent_vertex2 = find(vertex2); 

    if(parent_vertex1 == parent_vertex2) {
        return;
    }
    
    parent[vertex1] = vertex2;    // here we assign vertex2 as parent of vertex1 
}

int main() {
    parent.resize(v);
    for(int i = 0; i < v; i++) {
        parent[i] = i;
    }
}