#include<bits/stdc++.h>
using namespace std;

// if any number from 2 to n-1 divides the number it means it is not a prime number.
// but we do not need to search from 2 to n-1, we can search from 2 to sqrt(n), because if any number can not divide it before that then it can not divide after that as well
bool check_prime(int n) {

    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

int main() {

}