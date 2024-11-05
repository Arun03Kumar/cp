// we are calculating (a^b)%M, but here b can be very larger number that can not be stored in to long long
// to do this we have to use Euler's theorem
// which tells that (a^b)%M = (a^(b%ETF(M)))%M, where ETF is Euler's Totient Function


// leetcode problem: https://leetcode.com/problems/super-pow/description/

#include<bits/stdc++.h>
using namespace std;

const int M = 1e18+7;

long long bin_exp(int a, long long b, long long m) {
    
    long long ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }

    return ans;
}

int main() {
    // calculate 50^(64^32)%M
    // so using euler's theorem we can first calculate (64^32)%(M-1) because M is prime and we know that ETF of prime is just (prime - 1)
    // so it is similar to calculate bin_exp(64, 32, M-1)

    long long temp = bin_exp(64, 32, M - 1);
    long long ans = bin_exp(50, temp, M);
    // or ans = bin_exp(50, bin_exp(64, 32, M - 1), M);
}