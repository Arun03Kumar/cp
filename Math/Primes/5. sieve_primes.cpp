#include<bits/stdc++.h>
using namespace std;

// initially mark all the numbers as true, then iterate over them and mark the multiple of them as False

int N = 1e7 + 10;
vector<int> is_prime(N, true);
is_prime[0] = is_prime[1] = false;

void prime_sieve(int n) {

    for(int i = 2; i < N; i++) {
        if(is_prime[i] == true) {

            for(int j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }

        }
    }

}


int main() {

}