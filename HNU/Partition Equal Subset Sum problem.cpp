#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}

	if (sum % 2 != 0) {
		cout << "No partition scheme" << endl;
		return 0;
	}

	int target = sum / 2;
	vector<vector<char>> dp(n + 1, vector<char>(target + 1, 0));
	dp[0][0] = 1;
	//dp[i][j] represents whether we can form a sum j using the first i elements

	for (int i = 1;i <= n;i++) {
		for (int j = 0;j <= target;j++) {
			//Decide whether to choose the i-th number.
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i - 1] && dp[i - 1][j - a[i - 1]])
				dp[i][j] = 1;
		}
	}

	if (!dp[n][target]) {
		cout << "No partition scheme" << endl;
		return 0;
	}

	vector<int> A, B;
	int j = target;
	for (int i = n;i >= 1;i--) {
		if (j >= a[i - 1] && dp[i - 1][j - a[i - 1]]) {
			A.push_back(a[i - 1]);
			j -= a[i - 1];
		}
		else {
			B.push_back(a[i - 1]);
		}
	}

	cout << "Partition scheme found:" << endl;
	cout << "Subset A: ";
	for (int x : A) {
		cout << x << " ";
	}
	cout << endl;
	cout << "Subset B: ";
	for (int x : B) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}

/*
bitset Method:
	#include <iostream>
	#include <vector>
	#include <bitset>
	using namespace std;

	int main() {
		int n; cin >> n;
		vector<int> a(n);
		long long sum = 0;
		for (auto &x : a) { cin >> x; sum += x; }

		if (sum % 2) { cout << "No\n"; return 0; }

		int target = sum / 2;
		bitset<100005> dp;
		dp[0] = 1;
		for (int x : a) dp |= (dp << x);   // 0/1 背包：每件物品选/不选

		cout << (dp[target] ? "Yes\n" : "No\n");
}
*/