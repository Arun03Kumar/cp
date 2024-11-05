#include<bits/stdc++.h>
using namespace std;

int N = 1e7+10;
vector<int> is_prime(N, true);
is_prime[0] = is_prime[1] = false;
vector<int> lowset_prime(N, 0);
vector<int> highest_prime(N);

void sieve() {
    for(int i = 2; i < N; i++) {
        if(is_prime[i] == true) {
            for(int j = 2 * i; j < N; j += i) {
                is_prime[j] = false;

                // everything is same as sieve just add these two line for finding highest and lowest primes
                // since a prime factor is a number which can divide the number so in here we can only find them
                // lowest prime is the number which divides that number first time, so first time when i divides any number store that into lowest
                // highest will keep on updating becasue it will be the last number which can divide the number
                if(lowest_prime[j] == 0) lowest_prime[j] = i;
                highest_prime[j] = i;
            }
        }
    }


    // now that we have found the smallest and largest prime factors of the number we can find all the prime factors of given number.
    // we keep on dividing the number either by highest or lowest prime factor, and from the lowest_prime and highest_prime factor arrays keeps on getting the new factors for remaining number

    int num; // this is the number for which we wanted to find all the factors
    vector<int> all_prime_factors_of_num;

    // if we want to find the count of factors we can use the map to store the factors and their count in the map
    unordered_map<int, int> count_factors;

    while(num > 1) {
        int factor = highest_prime[num];
        while(num % factor == 0) {
            num /= factor;
            all_prime_factors_of_num.push_back(factor);

            count_factors[factor]++;
        }
    }

}

int main() {

}