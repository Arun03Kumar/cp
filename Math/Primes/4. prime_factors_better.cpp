#include<bits/stdc++.h>
using namespace std;

// we keep on dividing with the i till it is divisible, this way all factors of i will be included,
// but instead of checking all numbers from 2 to n-1 we can only check from 2 to sqrt(n), because if a number smallest divisor then it will definitely come before sqrt(n) 

// but there is one problem in this approach is that if we have such a number, such that last prime factor came only 1 time then that will be skipped
// hence we have to manually handle that case
// e.g. 24 => after 2,2,2 then n becomes 3 and i will also become 3, but 3*3 <= 3 will be false and for loop will get terminated, hence we have to put that in the answer.
vector<int> prime_factors(int n) {

    vector<int> ans;
    for(int i = 2; i * i <= n; i++) {
        while(n % 2 == 0) {
            ans.push_back(i);
            n /= 2;
        }
    }

    if(n > 1) ans.push_back(n);

    return ans;
}


vector<int>

int main() {

}