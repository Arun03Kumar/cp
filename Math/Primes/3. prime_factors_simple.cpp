#include<bits/stdc++.h>
using namespace std;

// we keep on dividing with the i till it is divisible, this way all factors of i will be included,
vector<int> prime_factors(int n) {

    vector<int> ans;
    for(int i = 2; i <= n; i++) {
        while(n % 2 == 0) {
            ans.push_back(i);
            n /= 2;
        }
    }

    return ans;
}


vector<int>

int main() {

}