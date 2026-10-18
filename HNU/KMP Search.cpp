//Find substring A int string B
#include <iostream>
#include <vector>
using namespace std;

vector<int> buildNext(const vector<int>& A) {
	int n = A.size();
	vector<int> next(n, 0);
	for (int i = 1, j = 0;i < n;i++) {
		while (j > 0 && A[i] != A[j]) j = next[j - 1];
		if (A[i] == A[j]) j++;
		next[i] = j;
	}
	return next;
}

bool kmpSearch(const vector<int>& A, const vector<int>& B) {
	int n = A.size(), m = B.size();
	if (n == 0) return true;
	if (n > m) return false;
	vector<int> next = buildNext(A);
	for (int i = 0, j = 0;i < m;i++) {
		while (j > 0 && B[i] != A[j]) j = next[j - 1];
		if (B[i] == A[j]) j++;
		if (j == n) return true;
	}
	return false;
}

int main() {
	int n, m;

	cin >> n;
	vector<int> A(n);
	for (int i = 0;i < n;i++) cin >> A[i];

	cin >> m;
	vector<int> B(m);
	for (int i = 0;i < m;i++) cin >> B[i];

	bool sea = kmpSearch(A, B);
	if (sea) cout << "Exist" << "\n";
	else cout << "No Existence" << "\n";
	return 0;
}