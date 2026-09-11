#include <iostream>
using namespace std;
bool Prime(int k) {
	for (int i = 2;i <= k / 2;i++) {
		if (k % i == 0) return false;
	}
	return true;
}
int n;
int i;
int main() {
	cin >> n;
	if (n == 1) {
		cout << 1 << " is not a Prime Number or Composite Number." << endl;
	}
	i = n + 1;
	if (Prime(n)) cout << n << " is a Prime Number." << endl;
	else {
		while (1) {
			if (Prime(i)) {
				cout << "The next Prime Number is " << i;
				break;
			}
			i++;
		}
	}
	return 0;
}
