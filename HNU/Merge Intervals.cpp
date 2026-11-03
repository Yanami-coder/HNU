#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Time
{
	double l, r;
};

int main() {
	int n;
	cin >> n;

	vector<Time> times(n);
	for (int i = 0; i < n; i++) cin >> times[i].l >> times[i].r;

	sort(times.begin(), times.end(), [](const Time& a, const Time& b) {
		return a.l < b.l;
	});

	double minn = times[0].l, maxn = times[0].r;
	for (int i = 1;i <= n;i++) {
		if (i == n || times[i].l > maxn) {
			cout << "[" << minn << "," << maxn << "]" << endl;
			if (i < n) {
				minn = times[i].l;
				maxn = times[i].r;
			}
		}
		else {
			maxn = max(maxn, times[i].r);
		}
	}

	return 0;
}