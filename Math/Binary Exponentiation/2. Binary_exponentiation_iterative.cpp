#include<bits/stdc++.h>
using namespace std;

// if we want to calculate 3^13 then we need to use binary representation of 13 to find the power
// binary(13) => (1101) so 3^13 can be calculated as 3^8 * 3^4 * 3^0 * 3^1
// if we start from right we can see that after each iteration power of 3 is increased by factor of two means at each iteration a is multiplied by itself,
// iter 1 => 3 * 3 = a
// iter 2 = (3*3) * (3*3) => a * a
// if we store it into a itself then again we just have to multiply by itself
// and when we find a set bit then multiply current a in to the ans
// and right shift the b
int binary_expo_iterative(int a, int b) {
    int ans = 1;

    while(b > 0) {
        if(b & 1) ans *= a;

        a *= a;
        b >>= 1;
    }

    return ans;
}


// if we want to use Modulo

const int M = 1e9 + 7;
int binary_expo_iter_modulo(int a, int b) {
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