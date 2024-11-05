#include<bits/stdc++.h>
using namespace std;

int pow(int x, int y) {
    if(y == 0) return 1;

    if(y & 1) return x * pow(x, y - 1);
    
    int temp = pow(x, y / 2);
    return temp * temp;

}


int main() {
    // recursive solution
    // cout << pow(3, 2);

    // iterative solution
    int a = 2, b = 10;
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans *= a;
        // a <<= 2;
        // b >>= 1;
        a *= a; // a <<= 2;
        b /= 2; // b >>= 1;
    }

    cout << ans;
}

