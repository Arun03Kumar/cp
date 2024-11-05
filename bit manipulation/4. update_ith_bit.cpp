#include<bits/stdc++.h>
using namespace std;

// we are taking a number input then a position index where we want to check the set bit

// we first clear the ith bit
// then we update the bit

void clear_ith_bit(int &num, int idx) {
    int mask = ~(1 << idx);
    num = num & mask;
}

void update_ith_bit(int &num, int idx, int val) {
    int mask = val << idx;
    num |= mask; 
}

int main() {
    int num;
    cin >> num;

    int idx_from_right;
    cin >> idx_from_right;

    clear_ith_bit(num, idx_from_right);
    update_ith_bit(num, idx_from_right, 1); // 3rd argument is 0 or 1, what you want to set at given idx

    cout << num;
}