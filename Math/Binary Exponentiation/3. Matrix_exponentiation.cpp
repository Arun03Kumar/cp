#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void matrix_multiply(vector<vector<ll>> &A, vector<vector<ll>> &B, vector<vector<ll>> &result, ll mod) {
    // matrix A => (n*p), matrix B => (p*m)
    int n = A.size(); // number of rows in A
    int p = B.size(); // number of rows in B, or columns in A
    int m = B[0].size(); // number of columns in B

    // initialize result matrix with dimensions (n*m) and fill with 0
    result.assign(n, vector<ll>(m, 0));

    for(int i = 0; i < n; i++) { // loop over each row in A
        for(int j = 0; j < m; j++) { // loop over each column in B
            result[i][j] = 0;
            for(int k = 0; k < p; k++) { // loop over each element in row of A and column of B
                result[i][j] = (result[i][j] + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }
}

// this function initialize an Identity matrix of size n
void initialize_identity(vector<vector<ll>> &mat, int n) {
    mat.assign(n, vector<ll>(n, 0));
    for(int i = 0; i < n; i++) {
        mat[i][i] = 1;
    }
}

void matrix_power(vector<vector<ll>> &base, ll exponent, vector<vector<ll>> &result, ll mod) {
    int n = base.size();
    initialize_identity(result, n);

    while(exponent > 0) {
        if(exponent & 1) {
            vector<vector<ll>> temp; // Temporary matrix to store intermediate results
            matrix_multiply(result, base, temp, mod); // Multiply the result by base
            result = temp; // Update the result
        }

        vector<vector<ll>> temp; // Temporary matrix to square the base
        matrix_multiply(base, base, temp, mod); // Square the base matrix
        base = temp; // Update the base to its squared version

        exponent >>= 1;
    }
}

int main() {
    ll mod = 1e9 + 7;
    ll exponent = 5;
    vector<vector<ll>> base = {{1, 1}, {1, 0}};
    vector<vector<ll>> result;

    matrixPower(base, exponent, result, mod);
}