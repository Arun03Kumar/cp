#include<bits/stdc++.h>
using namespace std;

// we are taking a number input then a position index where we want to check the set bit
// we then create a mask by left shifting 1 by the given position it will create a mask with all zeros and 1 at the given index
// then wo do the & operation of number with the mask.
// if result is greater than 0 then that index contains set bit else 0

int main() {

    int num;
    cin >> num;

    int position;
    cin >> position;

    int mask = (1 << position);
    if(num & mask) {
        cout << "given position has set bit";
    }
    else {
        cout << "given position is not set";
    }

}