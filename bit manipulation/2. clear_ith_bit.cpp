#include<bits/stdc++.h>
using namespace std;

// we are taking a number input then a position index where we want to check the set bit

// we then create a mask by left shifting 1 by the given position it will create a mask with all zeros and 1 at the given index
// but for clearing the bit we need 0 at the given index and 1 at all other positions so we negate the mask
// also given index should be in 0 index form from the right to get the desired result

int main() {
    int num;
    cin >> num;

    int idx_from_right;
    cin >> idx_from_right;

    int mask_with_one_at_idx = (1 << (idx_from_right - 1));
    int mask_with_zero_at_idx = ~mask_with_one_at_idx;

    int cleared_bit_num = num & mask_with_zero_at_idx;
    cout << cleared_bit_num;
}