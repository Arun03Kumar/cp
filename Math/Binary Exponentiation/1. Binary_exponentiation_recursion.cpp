#include<bits/stdc++.h>
using namespace std;

// we are calculating a^b
// recursive calls are very large we can reduce it by storing into one var and use it instead.
int recursive(int a, int b) {
    if(b == 0) return 1;
    if(b & 1) return b * recursive(a, b / 2) * recursive(a, b / 2);
    else recursive(a, b / 2) * recursive(a, b / 2);
}

int recursive_opt(int a, int b) {
    if(b == 0) return 1;

    int ans = recursive_opt(a, b / 2);

    if(b & 1) return b * res * res;
    else return res * res;
}

// if we need to use modulo so we can use the modulo in the code as:
const int M = 1e9 + 7;
int recursive_modulo(int a, int b) {
    if(b == 0) return 1;

    int ans = recursive_modulo(a, b / 2);

    // since res*res can be overflown to int datatype hence we can use 1LL to typecast it into long long
    if(b & 1) return (b * (res * 1LL * res) % M) % M;
    else return (res * 1LL * res) % M;
}

int main() {

}