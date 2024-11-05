#include<bits/stdc++.h>
using namespace std;

// if any number from 2 to n-1 divides the number it means it is not a prime number.
bool check_prime(int n) {

    for(int i = 2; i < n; i++) {
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

int main() {

}