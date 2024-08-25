// if you want to find the sum of any subarray in very efficient manner, calculate its prefix sum and with the help of this we can calculate sum of any subarray in O(1).

#include<iostream>
using namespace std;

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6};

    vector<int> prefix_sum(n + 1, 0); // create array with one larger space

    for(int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }

    // 0, 1, 3, 6, 10, 15, 16 -----> this will be prefix sum arr

    // finding subarray starting from index low = 1 to high = 3 which will be 2 + 3 + 4 -> 9
    prefix_sum[high + 1] - prefix_sum[low]; // this will give the subarray sum as 10 - 1 -> 9

}