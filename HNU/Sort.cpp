#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int a[100001];
void bubble(int a[], int n) {
	for (int i = 0;i < n - 1;i++) {
		bool flag = false;
		for (int j = 0;j < n - i - 1;j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				flag = true;
			}
		}
		if (!flag) break;
	}
}

void insertion(int a[], int n) {
	for (int i = 1;i < n;i++) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

void quick(int a[], int l, int r) {
	if (l >= r) return;
	int i = l;
	int j = r;
	int mid = a[(l + r) / 2];
	while (i <= j) {
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
		if (l < j) quick(a, l, j);
		if (i < r) quick(a, i, r);
	}
}

void bucket(int a[], int n) {
	int maxn = a[0];
	int minn = a[0];
	for (int i = 1;i < n;i++) {
		maxn = max(maxn, a[i]);
		minn = min(minn, a[i]);
	}
	vector<int> cnt(maxn - minn + 1, 0);
	for (int i = 0;i < n;i++) cnt[a[i] - minn]++;
	int k = 0;
	for (int i = 0;i <= maxn - minn;i++) {
		while (cnt[i] > 0) {
			a[k] = i + minn;
			k++;
			cnt[i]--;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];

	bubble(a, n);

	for (int i = 0;i < n;i++) cout << a[i] << " ";
	return 0;
}


//hello