#include<bits/stdc++.h>
using namespace std;

// we are taking a number input then a position index where we want to check the set bit
// we then create a mask by left shifting 1 by the given position it will create a mask with all zeros and 1 at the given index
// then wo do the | operation of number with the mask.

int main() {

    int num;
    cin >> num;

    int position;
    cin >> position;

    int mask = (1 << position);
    int set_bit_num = num | mask;
    cout << set_bit_num;

}