#include <iostream>
using namespace std;
int n;
int a[1001];
int i = 1;
int main() {
	cin >> n;
	while (1) {
		if (n == 1) {
			a[i] = 1;
			break;
		}
		a[i] = n % 2;
		i++;
		n /= 2;
	}
	for (int j = i;j >= 1;j--)
		cout << a[j];
	return 0;
}

