/*
题目描述

Anon 和 Soyorin 在玩一个数字游戏。Anon 给了 Soyorin 一个包含 $n$ 个正整数的数组 $a$，Soyorin 需要从中选出一个子集。

一个由正整数组成的元组 $\{x_1, x_2, \dots, x_k\}$ 被称为是简单的，当且仅当对于所有满足 $1 \le i < j \le k$ 的整数对 $(i,j)$，$x_i + x_j$ 都是素数。

Soyorin 想要从数组 $a$ 中找出一个大小最大的简单子集。

素数是指大于 1 的自然数，并且除了 1 和它本身之外没有其他正因数。

数组 $a$ 的子集是指从 $a$ 中删除若干个（也可以不删除或全部删除）元素后得到的元组。

输入格式

第一行包含一个整数 $n$ ($1 \le n \le 1000$)，表示数组 $a$ 中元素的数量。

第二行包含 $n$ 个整数 $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^6$)，表示数组 $a$ 中的元素。

输出格式

第一行输出一个整数 $m$，表示简单子集大小的最大值。

第二行输出 $m$ 个整数 $b_1, b_2, \dots, b_m$，表示一个大小最大的简单子集。

如果存在多组答案，输出任意一组即可。子集中的元素可以按任意顺序输出。
*/

#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 2000005;
bool is_prime[MAXN];

void sieve() {
	fill(is_prime, is_prime + MAXN, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2;i * i < MAXN;i++) {
		if (is_prime[i]) {
			for (int j = i * i;j < MAXN;j += i) {
				is_prime[j] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	sieve();

	int n;
	if (!(cin >> n)) return 0;

	vector<int> a(n);
	int cnt1 = 0;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		if (a[i] == 1) cnt1++;
	}

	//情况一： 包含数字1
	if (cnt1 > 0) {
		vector<int> ans;
		//先取所有的1
		for (int i = 0;i < n;i++) if (a[i] == 1) ans.push_back(1);

		//再尝试找一个非1的数，使得 1 + x 是素数
		for (int i = 0;i < n;i++) {
			if (a[i] != 1 && is_prime[1 + a[i]]) {
				ans.push_back(a[i]);
				break;
			}
		}

		cout << ans.size() << "\n";
		for (int i = 0;i < (int)ans.size();i++) cout << ans[i] << (i == (int)ans.size() - 1 ? "" : " ");
		cout << "\n";

		return 0;
	}

	//情况二： 不包含数字1
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			if (is_prime[a[i] + a[j]]) {
				cout << 2 << "\n";
				cout << a[i] << " " << a[j];

				return 0;
			}
		}
	}

	cout << 1 << "\n";
	cout << a[0] << "\n";

}