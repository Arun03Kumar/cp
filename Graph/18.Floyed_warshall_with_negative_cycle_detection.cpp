// Problem Link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

//O(n^3)

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> grid; // 2d matrix with weights
    int n = grid.size();

    for(int via = 0; via < n; via++) {

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                int via_dist = grid[i][via] + grid[via][j];
                grid[i][j] = min(grid[i][j], via_dist);

            }
        }

    }

    // now after this the grid will contains all the updated paths with minimum distance.
}