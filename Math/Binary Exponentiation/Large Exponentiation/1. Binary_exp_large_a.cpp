// we are finding (a^b)%M but here a can be very large, in the range of 2^18 or 2^1024

#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

// when a is in range of 2^18, just take modulus of a at the start
// because we are multiplying so if we take modulus at the start then it won't affect the ans
int binary_exp(long long a, int b) {
    
    a %= M;
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        b >>= 1;
    }

    return ans;
}


// when a in range of 2^1024
int binary_exp(long long a, int b) {
    a = binary_exp(2, 1024);
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        b >>= 1;
    }

    return ans;
}


int main() {

}