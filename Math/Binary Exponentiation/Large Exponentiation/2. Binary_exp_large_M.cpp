// we are calculating (a^b)%M when M is very large, in the range of 10^18
// in this case when we multiply very large integer numbers then they will come into long long but in next iteration long long multiplies with large number will be overflowd and can't be stored even in long long
// so in that case we need to use binary multiplication
// this is similar to binary exponentiation
// eg. 3*(13), binary of 13 is 1101, now we can write 12 in powers of 2 as (2^3+2^2+0+2^1) => (8+4+0+1)
// so we are adding 3 one time then 4times then 8times totaly 13 times

#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

long long binary_multiply(long long a, long long b) {
    
    long long ans = 0;
    while(b > 0) {
        if(b & 1) ans = (ans + a) % M;
        a = (a + a) % M;
        b >>= 1;
    }

    return ans;

}

long long binary_exponentiation(long long a, long long b) {

    long long ans = 1;
    while(b > 0) {
        if(b & 1) ans = binary_multiply(ans, a);
        a = binary_multiply(a, a);
        b >>= 1;
    }

    return ans;

}

int main() {

}