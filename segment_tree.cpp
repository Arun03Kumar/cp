#include<bits/stdc++.h>
using namespace std;

int arr[100005], segArr[4 * 100005];

void build(int idx, int low, int high) {
	if (low == high) {
		segArr[idx] = arr[low];
		return;
	}
	int mid = (low + high) / 2;
	build(2 * idx + 1, low, mid);
	build(2 * idx + 2, mid + 1, high);
	segArr[idx] = segArr[2 * idx + 1] + segArr[2 * idx + 2];
}

int query(int idx, int low, int high, int l, int r) {
	if (l <= low && r >= high) {
		return segArr[idx];
	}
	if (l > high || r < low) {
		return 0;
	}
	int mid = (low + high) / 2;
	int left = query(2 * idx + 1, low, mid, l, r);
	int right = query(2 * idx + 2, mid + 1, high, l, r);
	return left + right;
}

void update(int idx, int low, int high, int change_idx, int newVal) {
	if (low == high) {
		segArr[idx] = newVal;
		return;
	}
	int mid = (low + high) / 2;
	if (change_idx <= mid) {
		update(2 * idx + 1, low, mid, change_idx, newVal);
	}
	else {
		update(2 * idx + 2, mid + 1, high, change_idx, newVal);
	}
	segArr[idx] = segArr[2 * idx + 1] + segArr[2 * idx + 2];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	build(0, 0, n - 1);
	int q;
	cin >> q;
	while (q--) {
		int type, l, r;
		cin >> type >> l >> r;
		if (type == 1) {
			cout << query(0, 0, n - 1, l, r) << "\n";
		}
		else {
			update(0, 0, n - 1, l, r);
		}
	}
}
